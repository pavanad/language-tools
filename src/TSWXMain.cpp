//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TSWXMain.h"
#include "TSWXLanguageThread.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Number = 1;
	projectname = "Project" + IntToStr(Number);
	settings = new TSettings(Application);
	analysis = new TAnalysis(Application);

	this->Caption = "Lang Tools - " + projectname;
	settings->Parent = project;
	settings->Align = alClient;
	settings->Visible = true;

	analysis->Parent = pAnalysis;
	analysis->Align = alClient;
	analysis->Visible = true;

	m_lang = new TSWXLanguageTexts(analysis,settings);

	//idioma default
	SetLanguage("pt");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::addDfmExecute(TObject *Sender)
{
	TOpenDialog * open = new TOpenDialog(NULL);

	open->Filter = "Files *.dfm (*.dfm)|*.dfm";
	open->FilterIndex = 0;
	open->DefaultExt = "dfm";
	open->Options << ofAllowMultiSelect;

	if(open->Execute())
	{
		for(int i = 0; i < open->Files->Count; i++)
		{
			UnicodeString fname = open->Files->Strings[i];
			settings->m_ls->AddItem(fname,NULL);
		}

	}

	delete open;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::m_toobarRunClick(TObject *Sender)
{
	//coleta os dados do form
	m_destName = settings->m_dest->Text;

	m_list.resize(settings->m_ls->GetCount());
	for(int i = 0; i < settings->m_ls->GetCount(); i++)
	{
		m_list[i]=settings->m_ls->Items->Item[i]->Caption;
	}


	//verifica se os campos foram preenchidos
	if(!isReady())
	{
		MessageBox(NULL,m_lang->msg.Fill.t_str(),"Lang Tools", MB_OK | MB_ICONSTOP);
	}else
	{
		//alimenta o data transfer
		m_data = new TSWXMainDT();
		m_data->SetData(m_list);

		//executa o thread
		//myThread = new TSWXLanguageThread(&m_data);

		//executa classe apenas para teste
		myKernel = new TSWXKernel(m_data, analysis);

	}
}
//---------------------------------------------------------------------------
bool TForm1::isReady()
{
	if(m_list.empty()) return false;
	if (m_destName.IsEmpty()) return false;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actionExportExecute(TObject *Sender)
{
	int row = analysis->m_grid->RowCount;
	int col = analysis->m_grid->ColCount;
	UnicodeString filename = settings->m_dest->Text;
	UnicodeString nodeObject;

	if(filename.IsEmpty()) return;
	if(analysis->m_quantNodes->Caption.IsEmpty()) return;

	if(DirectoryExists(GetDirectory())==false)
	{
		MessageBox(NULL,m_lang->msg.Directory.t_str(),"Lang Tools",MB_OK | MB_ICONINFORMATION);
		return;
    }

	_di_IXMLDocument doc;
	doc = NewXMLDocument("1.0");
	doc->Active = true;

	_di_IXMLNode nodeLang = doc->AddChild("Language");

	for(int i = 1; i < row; i++)
	{
		nodeObject = analysis->m_grid->Cells[1][i];
		_di_IXMLNode node = nodeLang->AddChild(nodeObject);
		node->Text = analysis->m_grid->Cells[2][i];
    }

	doc->SaveToFile(filename);

	MessageBox(NULL,m_lang->msg.Generate.t_str(),"Lang Tools",MB_OK | MB_ICONINFORMATION);

	if(settings->m_ckOpen->Checked)
	{
		ShellExecute( NULL, "open", "iexplore",filename.t_str(), NULL, SW_SHOWNORMAL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actionNewExecute(TObject *Sender)
{
	if(this->WasSaved()==false)
	{
		UnicodeString message = m_lang->msg.Saved1.t_str() + this->GetFileName() +
							    m_lang->msg.Saved2.t_str();

		int res = MessageDlg(message,mtConfirmation,mbYesNoCancel,0);

		if(res == mrYes)
		{
			this->actionSaveExecute(Sender);
		}

		if(res == mrCancel)
		{
			return;
		}
	}

	Number++;
	projectname = "Project" + IntToStr(Number);
	this->Caption = "Lang Tools - " + projectname;
	analysis->ResetForm();
	settings->ResetForm();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actionSaveExecute(TObject *Sender)
{

	if (!FileExists(projectname))
	{

		actionSaveasExecute(Sender);

	}else{

		_di_IXMLDocument doc;
		doc = NewXMLDocument("1.0");
		doc->Active = true;

		_di_IXMLNode node = doc->AddChild("Project");

		settings->WriteMe(node);
		analysis->WriteMe(node);

		doc->SaveToFile(projectname);

		settings->SetWasSaved(true);
		analysis->SetWasSaved(true);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actionSaveasExecute(TObject *Sender)
{
	TSaveDialog * save = new TSaveDialog(NULL);
	save->Filter = "Project files Lang tools (*.lgt)|*.lgt";
	save->FilterIndex = 0;
	save->DefaultExt = "lgt";
	save->Options << ofOverwritePrompt;

	if(save->Execute())
	{
		projectname = save->FileName;
		FileNameTitle(projectname);

		_di_IXMLDocument doc;
		doc = NewXMLDocument("1.0");
		doc->Active = true;

		_di_IXMLNode node = doc->AddChild("Project");

		settings->WriteMe(node);
		analysis->WriteMe(node);

		doc->SaveToFile(projectname);

		settings->SetWasSaved(true);
		analysis->SetWasSaved(true);

	}

	delete save;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actionOpenExecute(TObject *Sender)
{

	if(this->WasSaved()==false)
	{
    	UnicodeString message = m_lang->msg.Saved1.t_str() + this->GetFileName() +
							    m_lang->msg.Saved2.t_str();

		int res = MessageDlg(message,mtConfirmation,mbYesNoCancel,0);

		if(res == mrYes)
		{
			this->actionSaveExecute(Sender);
		}

		if(res == mrCancel)
		{
			return;
		}
	}

	TOpenDialog * open = new TOpenDialog(NULL);
	open->Filter = "Project files Lang tools (*.lgt)|*.lgt";
	open->FilterIndex = 0;
	open->DefaultExt = "lgt";

	if(open->Execute())
	{
		analysis->ResetForm();
		settings->ResetForm();
		projectname = open->FileName;
		FileNameTitle(projectname);

		try{

		_di_IXMLDocument doc;
		doc = LoadXMLDocument(projectname);

		doc->Active = true;

		_di_IXMLNode node = doc->ChildNodes->Nodes["Project"];

		settings->ReadMe(node);
		analysis->ReadMe(node);

		settings->SetWasSaved(true);
		analysis->SetWasSaved(true);

		}catch(...){
			MessageBox(NULL, m_lang->msg.Error.t_str(),"Lang Tools", MB_OK | MB_ICONERROR);
			return;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actionPtExecute(TObject *Sender)
{
	SetLanguage("pt");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actionEnExecute(TObject *Sender)
{
	SetLanguage("en");
}
//---------------------------------------------------------------------------
void TForm1::SetLanguage(UnicodeString lang)
{

   	char CurrentPath[_MAX_PATH];

	getcwd(CurrentPath, _MAX_PATH);

	UnicodeString filename = CurrentPath;

	if(lang=="pt")	{

		filename = filename + "\\Languages\\Portuguese.lang";
		Portugs1->Checked = true;
		English1->Checked = false;

	}else if(lang=="en")
	{
		filename = filename + "\\Languages\\English.lang";
		Portugs1->Checked = false;
		English1->Checked = true;
	}

	if(FileExists(filename))
	{
		_di_IXMLDocument doc;
		doc = LoadXMLDocument(filename);
		doc->Active = true;

		_di_IXMLNode node = doc->ChildNodes->Nodes["Language"];

		//altera o idioma dos forms
		m_lang->SetLanguage(node);

		//altera o idioma do main
		_di_IXMLNode myNode = node->ChildNodes->Nodes[File1->Name];
		File1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Newproject1->Name];
		Newproject1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Openproject1->Name];
		Openproject1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[SaveProject1->Name];
		SaveProject1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[SaveProjectas1->Name];
		SaveProjectas1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Import1->Name];
		Import1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Export1->Name];
		Export1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Edit1->Name];
		Edit1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Tools1->Name];
		Tools1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[L1->Name];
		L1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[English1->Name];
		English1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Portugs1->Name];
		Portugs1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Help1->Name];
		Help1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[Aboutlanguagetools1->Name];
		Aboutlanguagetools1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[EditCut1->Name];
		EditCut1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[EditCopy1->Name];
		EditCopy1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[EditPaste1->Name];
		EditPaste1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[FileExit1->Name];
		FileExit1->Caption = myNode->Text;

		myNode = node->ChildNodes->Nodes[addDfm->Name];
		addDfm->Caption = myNode->Text;
	}
}
//----------------------------------------------------------------------------
void TForm1::FileNameTitle(UnicodeString fname)
{
	UnicodeString title;
	int count = fname.Length();

	for(int i = count; i > 0; i--)
	{
		if(fname.SubString(i,1)=="\\")
		{
			title = fname.SubString(i+1,count - i);
			this->Caption = "Lang Tools - " + title;
			return;
		}
	}
}
//----------------------------------------------------------------------------
void __fastcall TForm1::actionImportExecute(TObject *Sender)
{
	TOpenDialog * open = new TOpenDialog(NULL);
	open->Filter = "Lang files(*.lang)|*.lang|XML files(*.xml)|*.xml";
	open->FilterIndex = 0;
	open->DefaultExt = "lang";

	if(open->Execute())
	{
		UnicodeString fname = open->FileName;

		if(FileExists(fname))
		{
			try{
				_di_IXMLDocument doc;
				doc = LoadXMLDocument(fname);
				doc->Active = true;

				_di_IXMLNode node = doc->ChildNodes->Nodes["Language"];
				analysis->SetImport(node);
			}catch(...)
			{
				MessageBox(NULL,m_lang->msg.Error.t_str(),"Lang Tools", MB_OK | MB_ICONERROR);
				return;
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::actionAboutExecute(TObject *Sender)
{
	About->ShowModal();
}
//---------------------------------------------------------------------------
bool TForm1::WasSaved()
{
	if(settings->GetWasSaved()==false) return false;
	if(analysis->GetWasSaved()==false) return false;
	return true;
}
//---------------------------------------------------------------------------
UnicodeString TForm1::GetFileName()
{
	if(FileExists(projectname))
	{
		UnicodeString filename;
		int count = projectname.Length();

		for(int i = count; i > 0; i--)
		{
			if(projectname.SubString(i,1)=="\\")
			{
				filename = projectname.SubString(i+1,count - i);
				return filename;
			}
		}
	}

	return projectname;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if(this->WasSaved() == true)
	{
		CanClose = true;
		return;
	}

	UnicodeString message = m_lang->msg.Saved1.t_str() + this->GetFileName() +
							m_lang->msg.Saved2.t_str();

	int res = MessageDlg(message,mtConfirmation,mbYesNoCancel,0);

	if(res == mrYes)
	{
		this->actionSaveExecute(Sender);
		CanClose = true;
		return;
	}

	if(res == mrCancel)
	{
		CanClose = false;
		return;
	}

	if(res == mrNo)
	{
		CanClose = true;
		return;
	}

	CanClose = true;
}
//---------------------------------------------------------------------------
UnicodeString TForm1::GetDirectory()
{
	UnicodeString directory;
	UnicodeString filename = settings->m_dest->Text;

	for(int i = filename.Length(); i > 0; i--)
	{
		if(filename.SubString(i,1)=="\\")
		{
			directory = filename.SubString(1,i-1);
			return directory;
		}
	}
}
