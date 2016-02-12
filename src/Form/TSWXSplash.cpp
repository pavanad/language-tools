//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TSWXSplash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSplash *Splash;
//---------------------------------------------------------------------------
__fastcall TSplash::TSplash(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TSplash::ShowTime(std::vector<UnicodeString> & Messages)
{
	for(int i = 0; i < Messages.size(); i++)
	{
		m_Load->Caption = Messages[i];
		m_Load->Refresh();
        m_Progress->Position = (i+1) * (100/Messages.size());
		#ifndef _DEBUG
		Sleep(300);
		#endif
		Update();
	}
}
