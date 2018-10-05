// SAPI.cpp : Text to speech app.
//
//#pragma warning(suppress : C4996)
//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <sapi.h>
#include <cstring>
#include <Windows.h>
#include <tchar.h>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	ISpVoice * pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;
	
	do {
		wchar_t msg[1024];
		printf("Enter text to Speak:\n");
		fgetws(msg, sizeof(msg), stdin);
		HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
		if (SUCCEEDED(hr))
		{
			//Change pitch
			//hr = pVoice->Speak(L"This sounds normal <pitch middle = '-10'/> but the pitch drops half way through", SPF_IS_XML, NULL);

			hr = pVoice->Speak(msg, 0, NULL);
			pVoice->Release();
			pVoice = NULL;
		}
	} while (true);

	::CoUninitialize();
	return TRUE;
}


