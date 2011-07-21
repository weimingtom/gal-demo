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
#include "hgeTTFontManager.h"
#include "hgeTTFont.h"


TTFontManager::TTFontManager( )
{
	hge = hgeCreate(HGE_VERSION);
}

TTFontManager::~TTFontManager()
{
	unsigned int i ;
	
	for (i=0; i<TTFonts.size(); ++i)
	{
		delete TTFonts[i].Font;
	}

	for (i=0; i<Faces.size(); ++i)
	{
		delete Faces[i].Face;
	}
	hge->Release();
}

hgeTTFont* TTFontManager::getFont(const char* filename,unsigned int fontsize)
{

	STTFace f;
	STTFont tf;

	if (!filename)
		filename = "";

	f.Filename = filename;

	int index = find( Faces, f );

	if (index == -1){
		f.Face = new hgeTTFace();
		if (f.Face->load(f.Filename.c_str())){
			Faces.push_back(f);
			index = (int)Faces.size() - 1;
		} else {
			delete f.Face;
			return	0;
		}
	}
	STTFace *face = &Faces[index];

	tf.Filename = face->Filename;
	tf.size = fontsize;
	index = find( TTFonts, tf );
	if (index != -1){
		return TTFonts[index].Font;
	}

	// not existing yet. try to load font.

	hgeTTFont* font = new hgeTTFont(hge);
	if (!font->attach(face->Face,fontsize))
	{
		delete font;
		return 0;
	}

	// add to fonts.

	tf.Font = font;
	TTFonts.push_back(tf);

	return font;
}

template <typename T1, typename T2>
int TTFontManager::find( T1 &con, T2 &f )
{
	int size = (int)con.size();
	for( int i = 0; i < size; ++ i )
	{
		if( !( con.at( i ) < f ) && !( f < con.at( i ) ) )
		{
			return i;
		}
	}

	return -1;
}

TTFontManager* TTFontManager::GetInstance()
{
	static TTFontManager instance;
	return &instance;
}
