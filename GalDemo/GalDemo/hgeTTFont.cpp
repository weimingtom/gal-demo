/**
 * HGE FreeType2 font system support. This system makes HGE
 * support multibyte language. 
 *
 * Special thanks to uirou, he wrote some codes to make Irrlicht
 * engine support multibyte language. And now i use some of his codes
 * here to make HGE do the same fever to HGE-users. 
 * 
 * Original author in Irrlicht : uirou
 * Modified version in HGE :     Kevin Lynx
 * mail : zmhn320@163.com
 * Date : 8/18/2007
 *
 * this class depends on HGE 1.6 (maybe later version is avaiable too )and
 * FreeType 2.2.1
 */
#include "stdafx.h"
#include "hgeTTFont.h"
#include <hgefont.h>

hgeTTFace::hgeTTFace()
{
	loaded = false;
}

hgeTTFace::~hgeTTFace()
{
	if (loaded){
		FT_Done_Face(face);
		FT_Done_FreeType(library);
	}
}

bool hgeTTFace::load(const char* filename)
{
	if (FT_Init_FreeType( &library )){
		return	false;
	}
	if (FT_New_Face( library,filename,0,&face )){
		return	false;
	}

	loaded = true;
	return true;
}


hgeTTGlyph::hgeTTGlyph() 
{
	tex = NULL;
	//tex16 = NULL;
	image = NULL;
}

hgeTTGlyph::~hgeTTGlyph()
{
	if (image) delete image;
	if (tex){
		hge->Texture_Free( tex );
	}
/*	if (tex16){
		hge->Texture_Free( tex16 );
	}
*/
}

void hgeTTGlyph::init()
{
   tex = NULL;
   //tex16 = NULL;
   image = NULL;
}

void hgeTTGlyph::cache(unsigned int idx)
{
	FT_Set_Pixel_Sizes(*face,0,size);
	if (!FT_Load_Glyph(*face,idx,FT_LOAD_NO_HINTING|FT_LOAD_NO_BITMAP)){
		FT_GlyphSlot glyph = (*face)->glyph;
		FT_Bitmap  bits;
		if (glyph->format == ft_glyph_format_outline ){
			if (!FT_Render_Glyph( glyph, FT_RENDER_MODE_NORMAL)){
				bits = glyph->bitmap;
				unsigned char *pt = bits.buffer;
				image = new unsigned char[bits.width * bits.rows];
				memcpy(image,pt,bits.width * bits.rows);
				top = glyph->bitmap_top;
				left = glyph->bitmap_left;
				imgw = 1;
				imgh = 1;
				texw = bits.width;
				texh = bits.rows;
				for(;;){
					if (imgw > texw){
						break;
					} else {
						imgw <<= 1;
					}
				}
				for(;;){
					if (imgh > texh){
						break;
					} else {
						imgh <<= 1;
					}
				}
				if (imgw > imgh){
					imgh = imgw;
				} else {
					imgw = imgh;
				}
				unsigned int *texd = new unsigned int[imgw*imgh];
				memset(texd,0,imgw*imgh*sizeof(unsigned int));
				unsigned int *texp = texd;
				offset = size - bits.rows;
				bool cflag = true;//(Driver->getDriverType() == video::EDT_DIRECT3D8);
				for (int i = 0;i < bits.rows;i++){
					unsigned int *rowp = texp;
					for (int j = 0;j < bits.width;j++){
						if (*pt){
							if (cflag){
								*rowp = *pt;
								*rowp *= 0x01010101;
							} else {
								*rowp = *pt << 24;
								*rowp |= 0xffffff;
							}
						} else {
							*rowp = 0;
						}
						pt++;
						rowp++;
					}
					texp += imgw;
				}
				char name[128];
				sprintf(name,"TTFontGlyph%d",idx);
				//video::IImage *img = Driver->createImageFromData(video::ECF_A8R8G8B8,core::dimension2d<int>(imgw,imgh),texd);
				
				if (tex){
					hge->Texture_Free( tex );
				}
				tex = createTexture( texd, imgw, imgh );
				delete texd;
				cached = true;
			}
		}
	}
	
}

HTEXTURE hgeTTGlyph::createTexture( unsigned int *data, int w, int h )
{
	HTEXTURE tex = hge->Texture_Create( w, h );
	DWORD *color = hge->Texture_Lock( tex, false );
	
	memcpy( color, data, sizeof( unsigned int ) * w * h );

	hge->Texture_Unlock( tex );
	
	return tex;
}


////////////////////////////////////////////////////////
hgeTTFont::hgeTTFont(HGE *_hge)
{
	hge = _hge;
	//TransParency = false;
	attached = false;
	GlobalKerningWidth = 0;
	GlobalKerningHeight = 0;
	mColor = ARGB( 255, 255, 255, 255 );
	spr = new hgeSprite( 0, 0, 0, 0, 0 );
}

hgeTTFont::~hgeTTFont()
{
	if (attached)	
	{
		//delete tt_face;
	}
	attached = false;

	delete spr;
}


bool hgeTTFont::attach(hgeTTFace *Face,unsigned int size)
{
	if (!hge)
		return false;

	if (attached){
		//delete tt_face;
		tt_face = 0;
	}
	tt_face = Face;

	this->size = size;

	hgeTTGlyph tmp;  
	int*tmp2;

	Glyphs.resize( tt_face->face->num_glyphs );
	//Glyphs.reallocate(tt_face->face->num_glyphs);
	//Glyphs.set_used(tt_face->face->num_glyphs);
	for (int i = 0;i < tt_face->face->num_glyphs;i++){
		Glyphs[i].hge = hge;
		Glyphs[i].size = size;
		Glyphs[i].face = &(tt_face->face);
		Glyphs[i].cached = false;

		tmp2 = (int*)&(Glyphs[i]);
		*tmp2 = *(int*)(&tmp);
		Glyphs[i].init(); 
	}
	attached = true;
	return	true;
}

unsigned int hgeTTFont::getGlyphByChar(wchar_t c){

	unsigned int idx = FT_Get_Char_Index( tt_face->face, c );
	if (idx && !Glyphs[idx - 1].cached)	Glyphs[idx - 1].cache(idx);
	return	idx;
}

hgeTTFont::Size  hgeTTFont::getDimension(const wchar_t* text)
{
	Size dim(0, Glyphs[0].size);

	for(const wchar_t* p = text; *p; ++p)
	{
		dim.width += getWidthFromCharacter(*p) + GlobalKerningWidth;
	}
	return dim;
}


inline int hgeTTFont::getWidthFromCharacter(wchar_t c)
{
	unsigned int n = getGlyphByChar(c);
	if ( n > 0){
		int w = Glyphs[n - 1].texw;
		int left = Glyphs[n - 1].left;
		if (w + left > 0) return w + left;
	}
	if (c >= 0x2000){
		return	Glyphs[0].size;
	} else {
		return	Glyphs[0].size / 2;
	}
}

DWORD hgeTTFont::GetColor()
{
	return mColor;
}

void hgeTTFont::SetColor( DWORD color )
{
	mColor = color;
}

void hgeTTFont::SetSpacing( float spacing )
{
	this->setKerningWidth( static_cast<int>( spacing ) );
}

float hgeTTFont::GetSpacing()
{
	return static_cast<float>( getKerningWidth() );
}

float hgeTTFont::GetStringWidth( const wchar_t *str )
{
	Size textDimension = getDimension( str );
	return static_cast<float>( textDimension.width );
}

float hgeTTFont::GetHeight()
{
	Size textDimension = getDimension( L"A" );
	return static_cast<float>( textDimension.height );
}

void hgeTTFont::Render( float offsetX, float offsetY, int align, const wchar_t *text )
{

	if( align != HGETEXT_LEFT )
	{
		Size textDimension;
		textDimension = getDimension(text);

		if( align == HGETEXT_CENTER )
			offsetX = offsetX - ( textDimension.width >>1 );
		
		if( align == HGETEXT_RIGHT )
			offsetX = offsetX - textDimension.width;
	}

	unsigned int n;
	
	while(*text)
	{
		n = getGlyphByChar(*text);
		if ( n > 0)
		{
			int imgw = Glyphs[n-1].imgw;
			int imgh = Glyphs[n-1].imgh;
			int texw = Glyphs[n-1].texw;
			int texh = Glyphs[n-1].texh;
			int offx = Glyphs[n-1].left;
			int offy = Glyphs[n-1].size - Glyphs[n-1].top;

			spr->SetTexture( Glyphs[n-1].tex );
			spr->SetTextureRect( 0, 0, imgw-1.0f, imgh-1.0f );
			spr->SetColor( mColor );
			spr->Render( offsetX + offx, offsetY + offy );
 
			offsetX += getWidthFromCharacter(*text) + GlobalKerningWidth;
		} 
		else 
		{
			offsetX += getWidthFromCharacter(*text) + GlobalKerningWidth;
		}
		++text;
	}
}

void hgeTTFont::printf( float x, float y, int align, const wchar_t *format, ... )
{
	va_list l;
	va_start( l, format );

	wchar_t text[1024];
	wvsprintfW( text, format, l );

	Render( x, y, align, text );
}


void hgeTTFont::Render( float offsetX, float offsetY, const wchar_t* text, bool hcenter, bool vcenter )
{
	
    if( hcenter || vcenter )
	{
		Size textDimension;
		textDimension = getDimension(text);

		if (hcenter)
			offsetX = offsetX - ( textDimension.width >> 1 );

		if (vcenter)
			offsetY = offsetY - ( textDimension.height >> 1 );
	}

	unsigned int n;
	
	while(*text)
	{
		n = getGlyphByChar(*text);
		if ( n > 0)
		{
			int imgw = Glyphs[n-1].imgw;
			int imgh = Glyphs[n-1].imgh;
			int texw = Glyphs[n-1].texw;
			int texh = Glyphs[n-1].texh;
			int offx = Glyphs[n-1].left;
			int offy = Glyphs[n-1].size - Glyphs[n-1].top;

			spr->SetTexture( Glyphs[n-1].tex );
			spr->SetTextureRect( 0, 0, imgw-1.0f, imgh-1.0f );
			spr->SetColor( mColor );
			spr->Render( offsetX + offx, offsetY + offy );
 
			offsetX += getWidthFromCharacter(*text) + GlobalKerningWidth;
		} 
		else 
		{
			offsetX += getWidthFromCharacter(*text) + GlobalKerningWidth;
		}
		++text;
	}
}


//! Calculates the index of the character in the text which is on a specific position.
int hgeTTFont::getCharacterFromPos(const wchar_t* text, int pixel_x)
{
	int x = 0;
	int idx = 0;

	while (text[idx])
	{
		x += getWidthFromCharacter(text[idx]);

		if (x >= pixel_x)
			return idx;

		++idx;
	}

	return -1;
}

void hgeTTFont::setKerningWidth ( int kerning )
{
	GlobalKerningWidth = kerning;
}

int hgeTTFont::getKerningWidth(const wchar_t* thisLetter, const wchar_t* previousLetter)
{
	return GlobalKerningWidth;
}

void hgeTTFont::setKerningHeight ( int kerning )
{
	GlobalKerningHeight = kerning;
}

int hgeTTFont::getKerningHeight ()
{
	return GlobalKerningHeight;
}

