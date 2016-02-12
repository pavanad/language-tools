//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TSWXAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAbout *About;
//---------------------------------------------------------------------------
__fastcall TAbout::TAbout(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAbout::m_imageClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------
