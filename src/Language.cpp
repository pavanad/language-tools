//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include "TSWXSplash.h"
#include <vector>
//---------------------------------------------------------------------------
USEFORM("Form\TSWXSettings.cpp", Settings);
USEFORM("Form\TSWXSplash.cpp", Splash);
USEFORM("Form\TSWXAnalysis.cpp", Analysis);
USEFORM("TSWXMain.cpp", Form1);
USEFORM("Form\TSWXAbout.cpp", About);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		TSplash * splash = new TSplash(NULL);

		splash->Show();
		splash->Update();

		Application->Initialize();

		std::vector<UnicodeString> Messages;
		Messages.resize(5);
		Messages.push_back("Initializing Lang Tools");
		Messages.push_back("Load application");
		Messages.push_back("Load components");
		Messages.push_back("Load files languages");
		Messages.push_back("Load files interface");

        splash->ShowTime(Messages);
		splash->Close();
		delete splash;

		Application->MainFormOnTaskBar = true;
		Application->Title = "Lang Tools";
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TSettings), &Settings);
		Application->CreateForm(__classid(TAnalysis), &Analysis);
		Application->CreateForm(__classid(TSplash), &Splash);
		Application->CreateForm(__classid(TAbout), &About);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
