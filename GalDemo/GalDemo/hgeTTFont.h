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
#ifndef _HGE_TT_FONT_H_
#define _HGE_TT_FONT_H_

#include <ft2build.h>
#include <freetype/freetype.h>
#include <hge.h>
#include <vector>
#include <hgerect.h>


class hgeSprite;

using std::vector;

/**
 * hgeTTFace
 *
 */
class hgeTTFace
{
public:
	hgeTTFace();
	virtual ~hgeTTFace();
	bool loaded;
	FT_Library	library;
	FT_Face		face;

	bool load(const char* filename);
};

/**
 * hgeTTGlyph
 *
 */
class hgeTTGlyph
{
public:
	bool cached;
	HGE  *hge;

	hgeTTGlyph();
	virtual ~hgeTTGlyph();

	void init();
	HTEXTURE createTexture( unsigned int *data, int w, int h );

	void cache(unsigned int idx);
	FT_Face *face;
	unsigned int size;
	unsigned int top;
	unsigned int left;
	unsigned int texw;
	unsigned int texh;
	unsigned int imgw;
	unsigned int imgh;
	HTEXTURE tex;
	int offset;
	unsigned char *image;
};

/**
 * hgeTTFont
 *
 * You can use this class to render some multibyte language texts.
 * And this is the first class you should pay attention to .
 * I mean , donot care hgeTTFace and hgeGlyph. 
 *
 * And you cannot new a hgeTTFont by yourself, it recommended that 
 * using hgeTTFontManager to get a hgeTTFont object. It's safe and easy 
 * if you do that.
 *
 * I'll keep the interface as same as hgeFont class. 
 */
class hgeTTFont
{
public:
	/**
	 * a tiny class that describe a Size.
	 *
	 */
	struct Size
	{
		int width, height;

		Size( int w = 0, int h = 0 ) : width( w ), height( h )
		{
		}
	};
public:
	/**
	 * Constructor
	 *
	 * Donot care it because you'll never new a hgeTTFont by yourself
	 */
	hgeTTFont(HGE *hge);
	
	/**
	 * Destructor
	 *
	 */
	virtual ~hgeTTFont();
	
	/**
	 * Render
	 *
	 * renders the text string to the screen
	 * @param x Screen-x coordinate
	 * @param y Screen-y coordinate
	 * @param align Alignment specificator. May be one of these: HGETEXT_LEFT, HGETEXT_RIGHT, HGETEXT_CENTER. 
	 * @param string the string to be rendered
	 */
	virtual void Render( float x, float y, int align, const wchar_t *string );
	virtual void printf( float x, float y, int align, const wchar_t *format, ... );
	virtual void Render( float x, float y, const wchar_t* text, bool hcenter = false, bool vcenter = false );

	/**
	 * GetColor
	 *
	 */
	DWORD GetColor();
	
	/**
	 * SetColor
	 *
	 */
	void SetColor( DWORD color );

	/** 
	 * SetSpacing
	 *
	 */
	void SetSpacing( float spacing );

	/** 
	 * GetSpacing
	 *
	 */
	float GetSpacing();

	/**
	 * GetStringWidth
	 *
	 */
	float GetStringWidth( const wchar_t *str );

	/**
	 * GetHeight
	 *
	 */
	float GetHeight();

	///////////////////////////////////////////////////////////////////////////////////////
	/**
	 * Donot care these functions below, i recommend you donot use them.
	 *
	 *
	 */
	bool         attach( hgeTTFace *Face, unsigned int size );
	virtual Size getDimension( const wchar_t* text );
	unsigned int getGlyphByChar( wchar_t c );
	virtual int  getCharacterFromPos( const wchar_t* text, int pixel_x );
	int          getWidthFromCharacter( wchar_t c );
	virtual void setKerningWidth( int kerning );
	virtual void setKerningHeight( int kerning );

	virtual int  getKerningWidth( const wchar_t* thisLetter=0, const wchar_t* previousLetter=0 );
	virtual int  getKerningHeight();

	//bool         TransParency;
	bool         attached;
	unsigned int size;

private:
	HGE                  *hge;
	vector< hgeTTGlyph > Glyphs;
	hgeTTFace            *tt_face;

	int   GlobalKerningWidth;
	int   GlobalKerningHeight;

	hgeSprite *spr;
	DWORD mColor;
};

#endif //end _HGE_TT_FONT_H_
