////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tools
// 24.IV.2010 —ÎË‚ÂÌ
// <cTools.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "cTools.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Trim Left String - deletes spaces from the left
string NFuncConverter::TrimLeft(string str)
{
	::setlocale(LC_ALL, "");							// Includes locale settings for UNICODE conversion
	bool isZero = false;
	unsigned i;
	string newStr("");
	for (i=0; i<str.size(); i++)
		if ( (!isZero) && (str.substr(i,1).compare(" ") == 0) )
			isZero = false;
		else
		{
			isZero = true;
			newStr+= str.substr(i,1);
		}
	if (!isZero)
		newStr.empty();
	return newStr;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Trim Right String - deletes spaces on the right
string NFuncConverter::TrimRight(string str)
{
	::setlocale(LC_ALL, "");							// Includes locale settings for UNICODE conversion
	bool isZero = false;
	unsigned i;
	string newStr("");
	for (i=str.size(); i>0; i--)
		if ( (!isZero) && (str.substr(i-1,1).compare(" ") == 0) )
		{
			isZero = false;
			newStr = str.erase(i-1,1);
		}
		else
			isZero = true;
//	if (!isZero)
//		newStr.empty();

	return newStr;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Trim String - deletes spaces from both ends
string NFuncConverter::Trim(string str)
{
	::setlocale(LC_ALL, "");							// Includes locale settings for UNICODE conversion
	bool isZero = false;
	unsigned i;
	string newStr("");
	for (i=0; i<str.size(); i++)
		if ( (!isZero) && (str.substr(i,1).compare(" ") == 0) )
			isZero = false;
		else
		{
			isZero = true;
			newStr+= str.substr(i,1);
		}
	if (!isZero)
		return "";
	isZero = false;
	str = newStr;
	for (i=str.size(); i>0; i--)
		if ( (!isZero) && (str.substr(i-1,1).compare(" ") == 0) )
		{
			isZero = false;
			newStr = str.erase(i-1,1);
		}
		else
			isZero = true;

	return newStr;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Trim WString - deletes spaces from both ends
wstring NFuncConverter::Trim(wstring str)
{
	bool isZero = false;
	unsigned i;
	wstring newStr(L"");
	for (i=0; i<str.size(); i++)
		if ( (!isZero) && (str.substr(i,1).compare(L" ") == 0) )
			isZero = false;
		else
		{
			isZero = true;
			newStr+= str.substr(i,1);
		}
	if (!isZero)
		return L"";
	isZero = false;
	str = newStr;
	for (i=str.size(); i>0; i--)
		if ( (!isZero) && (str.substr(i-1,1).compare(L" ") == 0) )
		{
			isZero = false;
			newStr = str.erase(i-1,1);
		}
		else
			isZero = true;

	return newStr;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Trim Left zero - deletes leading zeros
string NFuncConverter::TrimLeftZero(string str)			// Trim zero from left of string 000123456
{
	::setlocale(LC_ALL, "");							// Includes locale settings for UNICODE conversion
	bool isZero = false;
	unsigned i;
	string newStr("");
	for (i=0; i<str.size(); i++)
		if ( (!isZero) && (str.substr(i,1).compare("0") == 0) )
			isZero = false;
		else
		{
			isZero = true;
			newStr+= str.substr(i,1);
		}
	if (!isZero)
		newStr = "";
	return newStr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tokenize string - ",,aa,bb,,,cc,," -> "aa","bb","cc"
bool NFuncConverter::Tokenize(const string str, vector<string> &tokens, const string delimiters)
{
	// Skip delimiters at beginning.
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// Find first "non-delimiter".
	string::size_type pos     = str.find_first_of(delimiters, lastPos);
	
	tokens.clear();

	while (string::npos != pos || string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
	return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tokenize string - ",,aa,bb,,,cc,," -> "","","aa","","","cc",""
bool NFuncConverter::TokenizeNull(const string str, vector<string> &tokens, const string delimiters)
{
	// Skip delimiters at beginning. 
	size_t lastPos = str.find_first_not_of(delimiters, 0); 
	// Find first "non-delimiter". 
	size_t pos = str.find_first_of(delimiters, 0); 
	tokens.clear();
	while (std::string::npos != pos || std::string::npos != lastPos) 
	{
		if(pos<lastPos)
		{
			tokens.push_back("");
		}
		else
		{
			tokens.push_back(str.substr(lastPos, pos - lastPos));
			lastPos = str.find_first_not_of(delimiters, pos);
		}
		if(std::string::npos != pos)
			pos = str.find_first_of(delimiters, pos+1); 
	}
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Double precision real number to string
string NFuncConverter::ToString(double val, unsigned short width, unsigned short precision)
{
	std::stringstream strm;
	if (width != NULL)
		strm.width(width);
	if (precision != NULL)
		strm.precision(precision);
	strm<<fixed;
	strm<<val;
	return strm.str();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Real number to string
string NFuncConverter::ToString(float val, unsigned short width, unsigned short precision)
{
	std::stringstream strm;
	if (precision != NULL)
		strm.precision(precision);
	if (width != NULL)
		strm.width(width);
	strm<<fixed;
	strm<<val;
	return strm.str();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Integer to fixed-length string
string NFuncConverter::ToString(long val, unsigned short width)
{
	std::stringstream strm;
	if (width != NULL)
		strm.width(width);
	strm << fixed;
	strm << val;
	return strm.str();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Integer to fixed-length string
string NFuncConverter::ToString(int val, unsigned short width)
{
	std::stringstream strm;
	if (width != NULL)
		strm.width(width);
	strm << fixed;
	strm << val;
	return strm.str();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Double precision real number to wide string
wstring NFuncConverter::ToWString(double val, unsigned short width, unsigned short precision)
{
	std::wstringstream strm;
	if (width != NULL)
		strm.width(width);
	if (precision != NULL)
		strm.precision(precision);
	strm << fixed;
	strm << val;
	return strm.str();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Real number to wide string
wstring NFuncConverter::ToWString(float val, unsigned short width, unsigned short precision)
{
	std::wstringstream strm;
	if (precision != NULL)
		strm.precision(precision);
	if (width != NULL)
		strm.width(width);
	strm << fixed;
	strm << val;
	return strm.str();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Integer to fixed-length string
wstring NFuncConverter::ToWString(long val, unsigned short width)
{
	std::wstringstream strm;
	if (width != NULL)
		strm.width(width);
	strm << fixed;
	strm << val;
	return strm.str();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Integer to fixed-length string
wstring NFuncConverter::ToWString(int val, unsigned short width)
{
	std::wstringstream strm;
	if (width != NULL)
		strm.width(width);
	strm << fixed;
	strm << val;
	return strm.str();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Checks whether a file with the specified name and path exists.
bool FileExist(LPCTSTR szFileName )			//Checking if the file exists
{
	ifstream ifile(szFileName);
	return ((ifile)?true:false);
/*	CFileStatus status;		// GetStatus returns 0 if the specified file does not exist
	if (CFile::GetStatus( szFileName, status ) == 0)
		return false;
	return true;	*/
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ASSISTANT Procedure & Function
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Convert string to wstring
wstring NFuncConverter::SToWString(string str)			// Convert string to wstring
{
//	std::string -> std::wstring
	std::wstring wstr;
	wstr.assign(str.begin(), str.end());
	return wstr;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Convert WString To String
string NFuncConverter::WToString(wstring wstr)			// Convert wstring to string
{
//	std::string -> std::wstring
	std::string str;
	str.assign(wstr.begin(), wstr.end());
	return str;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// End Of Line
char NFuncConverter::eoln(fstream &stream)			// C++ code Return End of Line
{
	if (stream.eof()) return 1;		// True end of file
	long curpos;	char ch;
	curpos = stream.tellp();		// Get current position
	while (!stream.eof())
	{
		stream.get(ch);				// Get next char
		if ((int)ch != 32 )			// Skips spaces (ASCII code 32) or ASCII code 255?
			break;
		curpos = stream.tellp();	// Get current position
	}
	stream.clear();					// Fix bug in VC 6.0
	stream.seekp(curpos);			// Return to prev position
	if ((int)ch != 10)				// if (ch) eq 10
		return 0;					// False not end of row (line)
	else							// (if have spaces?)
		stream.get(ch);				// Go to next row
	return 1;						// True end of row (line)
}									// End function

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// UTF-8 encoding adds markers to each bytes
// and so itís possible to write a reliable algorithm
// to check if a byte string is encoded to UTF-8.
char NFuncConverter::isUTF8(const char* data, size_t size)
{
	const unsigned char* str = (unsigned char*)data;
	const unsigned char* end = str + size;
	unsigned char byte;
	unsigned int code_length, i;
	uint32_t ch;
	while (str != end) {
		byte = *str;
		if (byte <= 0x7F) {
			/* 1 byte sequence: U+0000..U+007F */
			str += 1;
			continue;
		}

		if (0xC2 <= byte && byte <= 0xDF)
			/* 0b110xxxxx: 2 bytes sequence */
			code_length = 2;
		else if (0xE0 <= byte && byte <= 0xEF)
			/* 0b1110xxxx: 3 bytes sequence */
			code_length = 3;
		else if (0xF0 <= byte && byte <= 0xF4)
			/* 0b11110xxx: 4 bytes sequence */
			code_length = 4;
		else {
			/* invalid first byte of a multibyte character */
			return 0;
		}

		if (str + (code_length - 1) >= end) {
			/* truncated string or invalid byte sequence */
			return 0;
		}

		/* Check continuation bytes: bit 7 should be set, bit 6 should be
		 * unset (b10xxxxxx). */
		for (i = 1; i < code_length; i++) {
			if ((str[i] & 0xC0) != 0x80)
				return 0;
		}

		if (code_length == 2) {
			/* 2 bytes sequence: U+0080..U+07FF */
			ch = ((str[0] & 0x1f) << 6) + (str[1] & 0x3f);
			/* str[0] >= 0xC2, so ch >= 0x0080.
			   str[0] <= 0xDF, (str[1] & 0x3f) <= 0x3f, so ch <= 0x07ff */
		}
		else if (code_length == 3) {
			/* 3 bytes sequence: U+0800..U+FFFF */
			ch = ((str[0] & 0x0f) << 12) + ((str[1] & 0x3f) << 6) +
				(str[2] & 0x3f);
			/* (0xff & 0x0f) << 12 | (0xff & 0x3f) << 6 | (0xff & 0x3f) = 0xffff,
			   so ch <= 0xffff */
			if (ch < 0x0800)
				return 0;

			/* surrogates (U+D800-U+DFFF) are invalid in UTF-8:
			   test if (0xD800 <= ch && ch <= 0xDFFF) */
			if ((ch >> 11) == 0x1b)
				return 0;
		}
		else if (code_length == 4) {
			/* 4 bytes sequence: U+10000..U+10FFFF */
			ch = ((str[0] & 0x07) << 18) + ((str[1] & 0x3f) << 12) +
				((str[2] & 0x3f) << 6) + (str[3] & 0x3f);
			if ((ch < 0x10000) || (0x10FFFF < ch))
				return 0;
		}
		str += code_length;
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// UTF to ANSI
string NFuncConverter::UTF8ToANSI(string s)	// UTF to ANSI
{
	BSTR	bstrWide;
	char* 	pszAnsi;
	int 	nLength;
	const char* pszCode = s.c_str();

	nLength = MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, NULL, NULL);
	bstrWide = SysAllocStringLen(NULL, nLength);

	MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, bstrWide, nLength);

	nLength = WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, NULL, 0, NULL, NULL);
	pszAnsi = new char[nLength];

	WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, pszAnsi, nLength, NULL, NULL);
	SysFreeString(bstrWide);

	string r(pszAnsi);
//	delete pszAnsi;
//	delete pszCode;
	//AfxMessageBox(L"delete bull");
	return r;
}
