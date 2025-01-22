//********************************************************************************************************************
// Tools
// 24.IV.2010 Сливен
// <cTools.h>
//********************************************************************************************************************

#if     _MSC_VER > 1000
#pragma once
#endif
#define _AFXDLL

#ifndef __cTools_PGP2508GFK__
#define __cTools_PGP2508GFK__

#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdexcept>
//#include <cctype>
#include <locale>         // std::locale, std::tolower
//#include <codecvt>

#include "pch.h" 

using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
template<class T>
string ToString(T val)
{
	std::stringstream strm;		// to_string();
	strm << val;
	return strm.str();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
template<class T>
wstring ToWString(T val)
{
std::wstringstream strm;
strm << val;
return strm.str();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Number of digits after the decimal point!
template<class T>
string ToString(T val, unsigned short precision)
{
	std::stringstream strm;
	if (precision != NULL)
		strm.precision(precision);
	strm << fixed;
	strm << val;
	return strm.str();
}
// Number of digits after the decimal point!
template<class T>
wstring ToWString(T val, unsigned short precision)
{
	std::wstringstream strm;
	if (precision != NULL)
		strm.precision(precision);
	strm << fixed;
	strm << val;
	return strm.str();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Number of digits after the decimal point and number of reserved widths
template<class T>
string ToString(T val, unsigned short width, unsigned short precision)
{
	std::stringstream strm;
	if (precision != NULL)
		strm.precision(precision);
	if (width != NULL)
		strm.width(width);
	strm << fixed;
	strm << val;
	return strm.str();
}
//
template<class T>
wstring ToWString(T val, unsigned short width, unsigned short precision)
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace NFuncConverter						// Defining a workspace
{
	string WToString(wstring wstr);				// Convert wstring to string
	wstring SToWString(string str);				// Convert string to wstring
	string ToLower(string str);					// Convert string to Lower case
	string ToUpper(string str);					// Convert string to upper case
	wstring ToLower(wstring str);				// Convert wstring to Lower case
	wstring ToUpper(wstring str);				// Convert wstring to upper case

	string TrimLeftZero(string str);			// Trim zero from left of string
	string TrimLeft(string str);				// Trim Left String
	string Trim(string str);					// Trim String
	string TrimRight(string str);				// Trim Right String
	wstring Trim(wstring str);					// Trim WString
	bool Tokenize(const string str, vector<string> &tokens, const string delimiters);
	bool TokenizeNull(const string str, vector<string> &tokens, const string delimiters);

	string ToString(double val, unsigned short width, unsigned short precision);
	string ToString(float val, unsigned short width, unsigned short precision);
	string ToString(long val, unsigned short width);
	string ToString(int val, unsigned short width);
	wstring ToWString(double val, unsigned short width, unsigned short precision);
	wstring ToWString(float val, unsigned short width, unsigned short precision);
	wstring ToWString(long val, unsigned short width);
	wstring ToWString(int val, unsigned short width);

	char isUTF8(const char* data, size_t size);			// 
	string UTF8ToANSI(string s);						// 

	char eoln(fstream &stream);							// C++ code Return End of Line
	// wstring OemToUnicode(UINT codePage, const char* sz);

};

bool FileExist(LPCTSTR szFileName );					// Проверка дали файла съществува!

// Real-world Use Case: CSV Parser that handles quoted fields:
// https://medium.com/@ryan_forrester_/splitting-strings-in-c-a-complete-guide-cf162837f4ba
class CSVParser {
private:
	static bool isQuoted(const std::string& field) {
		return field.size() >= 2 &&
			field.front() == '"' &&
			field.back() == '"';
	}

	static std::string unquote(const std::string& field) {
		if (!isQuoted(field)) return field;
		return field.substr(1, field.size() - 2);
	}

public:
	static std::vector<std::string> parseCSVLine(const std::string& line) {
		std::vector<std::string> fields;
		std::string field;
		bool inQuotes = false;

		for (char c : line) {
			if (c == '"') {
				inQuotes = !inQuotes;
				field += c;
			}
			else if (c == ',' && !inQuotes) {
				fields.push_back(unquote(field));
				field.clear();
			}
			else {
				field += c;
			}
		}

		fields.push_back(unquote(field));  // Add the last field
		return fields;
	}
};

#endif	/* __cTools_PGP2508GFK__ */