#pragma once

#include <Windows.h>
#include<string>   
using namespace std; 

#ifndef tstring
#ifdef _UNICODE
#define tstring wstring
#else
#define tstring string
#endif
#endif


/*
*	�ļ���:	character.h
*	��	��:	wchar_t * �� char * ֮���ת����string ��wstring֮���ת��
*	˵	��:	wchar_t * �� char * ֮���ת�� ֮��ת�� ��ʽ���ö�̬�����ڴ淽ʽ
*			��TEXT_ANTI_TO_TCHAR�ȶ���������һ��������ʱ���󣬲��ҵ��������ʱ����
*			�ķ�������wchar_t * ��char * ָ��
*			ʹ��ʱӦ��ע��: ��ʱ�����ڳ���������֮�󣬻������ڲ�������ڴ棬
*			�������·�ʽ�ĵ����Ǵ����:
*			
*		1. ************************************************
*			char charbuf[500]="���"
*			wchar_t * pss = TEXT_ANTI_TO_TCHAR(charbuf);  //����ķ�ʽ�����ص�ָ���Ѿ�������
			�ڸ�pss ��ֵ֮ǰ�����������Ѿ���������������
*			************************************************
*			
		2.	wcout << TEXT_ANTI_TO_TCHAR(charbuf)<< endl; �������õĵ��÷�ʽ����ȷ��
*			
*			���Ҫ���棬��ʹ�����漸�ַ�ʽ��
*		3.	*************************************************
*			Ascii_To_Wide as(charbuf) ;// �����������󣬵���ת������
*			wchar_t * tst = as.wchar_rep();	
*			*************************************************
*		4.	**************************************************
*			TCHAR ss[1024];// ����buf,�����ݸ��Ƶ�buf�У�(Ҫ�㹻�Ŀռ�)
*			_tcscpy(ss, TEXT_ANTI_TO_TCHAR(charbuf)); 
*			**************************************************
*			
*			inline void InitLocal() ������Ϊ�����wchar_t * �е����Ķ����ã��ڵ���
*			wcout wprintf ���������ʱ�������������������ַ��������ȵ��øú���
*			���Խ�������������
*
*/


//inline char *WideCharToChar(const wchar_t *pwstr,char *pcstr);
//inline wchar_t * CharToWideChar(const char *str,wchar_t *pwstr);
inline void InitLocal();  
inline string WString2String(const wstring wstr);
inline wstring String2WString(const string str);



//������std::string ��std::wstring ֱ��ת��
#ifdef _UNICODE 
#define SWITCH_STRING String2WString 
#define TO_ALWAYS_STRING WString2String	//��wstring ת���� string �����������֪ת��Ŀ����wstring
#define TO_ALWAYS_WSTRING String2WString	//��string ת����wstring �����������֪ת��Ŀ����string
#else 
#define SWITCH_STRING WString2String 
#define TO_ALWAYS_STRING
#define TO_ALWAYS_WSTRING 
#endif
//end




//������char* ��wchar_t *ֱ��ת��
#ifdef _UNICODE
# define TEXT_ALWAYS_CHAR(STRING) (Wide_To_Ascii (STRING).char_rep ())
# define TEXT_ALWAYS_WCHAR(STRING) STRING
# define TEXT_CHAR_TO_TCHAR(STRING) (Ascii_To_Wide (STRING).wchar_rep ())
# define TEXT_WCHAR_TO_TCHAR(STRING) STRING
# define TEXT_ANTI_TO_TCHAR(STRING) (Ascii_To_Wide (STRING).wchar_rep ())
#else
# define TEXT_ALWAYS_CHAR(STRING) STRING
# define TEXT_ALWAYS_WCHAR(STRING) (Ascii_To_Wide (STRING).wchar_rep ())
# define TEXT_CHAR_TO_TCHAR(STRING) STRING
# define TEXT_WCHAR_TO_TCHAR(STRING) (Wide_To_Ascii (STRING).char_rep ())
# define TEXT_ANTI_TO_TCHAR(STRING) (Wide_To_Ascii (STRING).char_rep ())
#endif
//end

class Wide_To_Ascii
{
public:
	/// Ctor must take a wchar string.
	Wide_To_Ascii (const wchar_t *s);

	/// Dtor will free up the memory.
	~Wide_To_Ascii (void);

	/// Return the internal char* representation.
	char *char_rep (void);

	/// Converts an wchar_t string to ascii and returns a new string.
	static char *convert (const wchar_t *wstr);

private:
	/// Internal pointer to the converted string.
	char *s_;

	/// Disallow these operation.
	Wide_To_Ascii (void);
	Wide_To_Ascii (Wide_To_Ascii &);
	Wide_To_Ascii& operator= (Wide_To_Ascii &);
};

class Ascii_To_Wide
{
public:
	/// Ctor must take a wchar string.
	Ascii_To_Wide (const char *s);

	/// Dtor will free up the memory.
	~Ascii_To_Wide (void);

	/// Return the internal wchar* representation.
	wchar_t *wchar_rep (void);

	/// Converts an char string to unicode/wide and returns a new string.
	static wchar_t *convert (const char *str);

private:
	/// Internal pointer to the converted string.
	wchar_t *s_;

	/// Disallow these operation.
	Ascii_To_Wide (void);
	Ascii_To_Wide (Ascii_To_Wide &);
	Ascii_To_Wide operator= (Ascii_To_Wide &);
};

inline Wide_To_Ascii::~Wide_To_Ascii (void)
{
	delete [] this->s_;
}

inline char * Wide_To_Ascii::char_rep (void)
{
	//setlocale(LC_ALL, "chs");
	return this->s_;
}

inline char *Wide_To_Ascii::convert (const wchar_t *wstr)
{
	// Short circuit null pointer case
	if (wstr == 0)
		return 0;

	UINT cp = GetACP ();
	int len = ::WideCharToMultiByte (cp,
		0,
		wstr,
		-1,
		0,
		0,
		0,
		0);


	char *str = new char[len];

	::WideCharToMultiByte (cp, 0, wstr, -1, str, len, 0, 0);

	return str;
}

inline Wide_To_Ascii::Wide_To_Ascii (const wchar_t *s)
: s_ (Wide_To_Ascii::convert (s))
{
}

inline
Ascii_To_Wide::~Ascii_To_Wide (void)
{
	delete [] this->s_;
}

inline wchar_t * Ascii_To_Wide::wchar_rep (void)
{
	return this->s_;
}

inline wchar_t * Ascii_To_Wide::convert (const char *str)
{
	// Short circuit null pointer case
	if (str == 0)
		return 0;
	
	UINT cp = GetACP ();
	int len = ::MultiByteToWideChar (cp, 0, str, -1, 0, 0);


	wchar_t *wstr = new wchar_t[len];
	::MultiByteToWideChar (cp, 0, str, -1, wstr, len);
	return wstr;
}

inline Ascii_To_Wide::Ascii_To_Wide (const char *s)
: s_ (Ascii_To_Wide::convert (s))
{
}


inline void InitLocal()
{
	char   scp[16]; 
	UINT   cp   =   GetACP(); 
	sprintf_s(scp, ".%d ",cp); 
	setlocale(LC_ALL,   scp   );
}


//
//char *WideCharToChar(const wchar_t *pwstr,char *pcstr)
//{
//	setlocale(LC_ALL, "chs");
//	int nlength=(int)wcslen(pwstr);
//	//��ȡת����ĳ���
//	
//	int nbytes = WideCharToMultiByte(CP_ACP,	// specify the code page used to perform the conversion
//									 0,      // no special flags to handle unmapped characters
//									 pwstr,  // wide character string to convert
//									 nlength+1, // the number of wide characters in that string
//									 NULL,     // no output buffer given, we just want to know how long it needs to be
//									 0,
//									 NULL,      // no replacement character given
//									 NULL );    // we don't want to know if a character didn't make it through the translation
//	
//	
//	//// make sure the buffer is big enough for this, making it larger if necessary
//	//if(nbytes>=cstrlen)
//	//	nbytes=cstrlen-1;
//
//	// ͨ�����ϵõ��Ľ����ת��unicode �ַ�Ϊascii �ַ�
//
//	WideCharToMultiByte( CP_ACP,			// specify the code page used to perform the conversion
//						 0,         // no special flags to handle unmapped characters
//						 pwstr,     // wide character string to convert
//						 nlength+1,   // the number of wide characters in that string
//						 pcstr,		// put the output ascii characters at the end of the buffer
//						 nbytes,    // there is at least this much space there
//						 NULL,      // no replacement character given
//						 NULL );
//
//	//pcstr[nbytes] = '\0'; // ���û���㹻�ռ䣬��ô���ܳ���Υ�����!!
//	//nlength = strlen(pcstr);
//	return pcstr ;
//
//}
//
//
//
//
//wchar_t * CharToWideChar(const char *str,wchar_t *pwstr)
//{
//	
//	setlocale(LC_ALL, "chs");
//	int nlength =(int)strlen(str);
//	int nbytes =MultiByteToWideChar(CP_ACP,
//											0,
//											str,
//											nlength,
//											NULL,
//											0
//											);
//	//if(nbytes>=wstrlen)
//	//	nbytes=wstrlen-1;
//	MultiByteToWideChar(CP_ACP,
//						0,
//						str,
//						nlength,
//						pwstr,
//						nbytes
//						);
//	pwstr[nbytes]=0;	// ���û���㹻�ռ䣬��ô���ܳ���Υ�����!!
//	return pwstr;
//
//}
//
//

//��stringת����wstring   
wstring String2WString(const string str)   
{   
	wstring result;  
	setlocale(LC_ALL, "chs");
	//��ȡ��������С��������ռ䣬��������С���ַ�����   
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(),(int)str.size(), NULL, 0);   
	wchar_t* buffer = new wchar_t[len + 1];   
	//���ֽڱ���ת���ɿ��ֽڱ���   
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), (int)str.size(), buffer, len);   
	 buffer[len] ='\0';             //����ַ�����β   
	//ɾ��������������ֵ   
	result.append(buffer);   
	delete[] buffer;   

	 return result;   
}

//��wstringת����string   
string WString2String(const wstring wstr)   
{   
	string result;  
	setlocale(LC_ALL, "chs");
	 //��ȡ��������С��������ռ䣬��������С�°��ֽڼ����   
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), (int)wstr.size(), NULL, 0, NULL, NULL);   
	char* buffer = new char[len + 1];   
	//���ֽڱ���ת���ɶ��ֽڱ���   
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), (int)wstr.size(), buffer, len, NULL, NULL);   
	buffer[len] = '\0';   
	//ɾ��������������ֵ   
	result.append(buffer);   
	delete[] buffer;  

	return result;   
}
