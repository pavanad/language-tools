//---------------------------------------------------------------------------

#ifndef TSWXMainH
#define TSWXMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <StdActns.hpp>
#include <ExtCtrls.hpp>
#include "TSWXSettings.h"
#include "TSWXAnalysis.h"
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <vector>
#include "TSWXMainDT.h"
#include "TSWXLanguageThread.h"
#include "TSWXKernel.h"
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include "TSWXLanguageTexts.h"
#include "TSWXAbout.h"

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Newproject1;
	TMenuItem *Openproject1;
	TToolBar *ToolBar1;
	TStatusBar *StatusBar1;
	TMenuItem *N1;
	TMenuItem *SaveProject1;
	TMenuItem *SaveProjectas1;
	TMenuItem *N2;
	TMenuItem *Exit1;
	TMenuItem *Edit1;
	TMenuItem *Help1;
	TMenuItem *Aboutlanguagetools1;
	TMenuItem *Cut1;
	TMenuItem *Copy1;
	TMenuItem *Paste1;
	TActionList *ActionList1;
	TEditCut *EditCut1;
	TEditCopy *EditCopy1;
	TEditPaste *EditPaste1;
	TMenuItem *Tools1;
	TMenuItem *L1;
	TMenuItem *Portugs1;
	TMenuItem *English1;
	TFileExit *FileExit1;
	TPanel *project;
	TPanel *pAnalysis;
	TMenuItem *N3;
	TMenuItem *Add1;
	TAction *addDfm;
	TImageList *ImageList1;
	TToolButton *m_toobarNew;
	TToolButton *m_toobarOpen;
	TToolButton *ToolButton3;
	TToolButton *m_toobarAdd;
	TToolButton *m_toobarSave;
	TToolButton *ToolButton6;
	TToolButton *m_toobarRun;
	TMenuItem *Export1;
	TMenuItem *N4;
	TAction *actionExport;
	TAction *actionNew;
	TAction *actionSave;
	TAction *actionSaveas;
	TAction *actionOpen;
	TAction *actionPt;
	TAction *actionEn;
	TMenuItem *Import1;
	TAction *actionImport;
	TAction *actionAbout;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall addDfmExecute(TObject *Sender);
	void __fastcall m_toobarRunClick(TObject *Sender);
	void __fastcall actionExportExecute(TObject *Sender);
	void __fastcall actionNewExecute(TObject *Sender);
	void __fastcall actionSaveExecute(TObject *Sender);
	void __fastcall actionSaveasExecute(TObject *Sender);
	void __fastcall actionOpenExecute(TObject *Sender);
	void __fastcall actionPtExecute(TObject *Sender);
	void __fastcall actionEnExecute(TObject *Sender);
	void __fastcall actionImportExecute(TObject *Sender);
	void __fastcall actionAboutExecute(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	TSettings * settings;
	TAnalysis * analysis;
	TSWXLanguageTexts * m_lang;

	UnicodeString projectname;
	int Number;

	void SetLanguage(UnicodeString lang);
	void FileNameTitle(UnicodeString fname);
	UnicodeString GetFileName();

	bool isReady();
	bool WasSaved();
	UnicodeString GetDirectory();

	UnicodeString m_destName;
	std::vector<UnicodeString> m_list;

	TSWXMainDT * m_data;

	TSWXLanguageThread * myThread;
	TSWXKernel * myKernel;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
