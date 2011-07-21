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
#ifndef HGE_TT_FONT_MANAGER_H_
#define HGE_TT_FONT_MANAGER_H_

#include <hge.h>
#include <vector>

using std::vector ;

class hgeTTFace;
class hgeTTFont;

struct STTFace
{
	std::string Filename;
	hgeTTFace* Face;

	bool operator < (const STTFace& other) const
	{
		return strcmp( Filename.c_str(), other.Filename.c_str() ) < 0;
	}
};

struct STTFont
{
	std::string Filename;
	unsigned int size;
	hgeTTFont* Font;

	bool operator < (const STTFont& other) const
	{
		if (strcmp( Filename.c_str(), other.Filename.c_str() ) != 0 ){
			return strcmp( Filename.c_str(), other.Filename.c_str() ) < 0;
		} else {
			return (size < other.size);
		}
	}
};

/**
* TTFontManager
*
* Manage ttf font to support multibyte language
* Although this class is not a real singleton ,
* but to use it safely, make sure you donot create more than 
* one instance.
* 
*/
class TTFontManager
{
public:
	TTFontManager();
	~TTFontManager();

	hgeTTFont* getFont(const char* filename,unsigned int fontsize);
	
	static TTFontManager* GetInstance();
private:
	template <typename T1, typename T2>
	int find( T1 &con, T2 &f );
private:
	vector<STTFace> Faces;
	vector<STTFont> TTFonts;

	HGE *hge;
};

#endif //end HGE_TT_FONT_MANAGER_H_