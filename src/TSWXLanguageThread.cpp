//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TSWXLanguageThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TSWXLanguageThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TSWXLanguageThread::TSWXLanguageThread(TSWXMainDT * data,
								  TAnalysis * child, bool CreateSuspended)
	: TThread(CreateSuspended)
{

	m_data = data;
	m_analysis = child;

}
//---------------------------------------------------------------------------
void __fastcall TSWXLanguageThread::Execute()
{

}
//---------------------------------------------------------------------------
