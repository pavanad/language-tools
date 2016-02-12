//---------------------------------------------------------------------------

#ifndef TSWXAnalysisH
#define TSWXAnalysisH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include "TSWXResultsDT.h"
#include <ActnList.hpp>
#include <Menus.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
//---------------------------------------------------------------------------
class TAnalysis : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupAnalysis;
	TLabel *m_analyze;
	TProgressBar *m_progress;
	TLabel *m_status;
	TStringGrid *m_grid;
	TLabel *m_SearchNodes;
	TLabel *m_FileAnalysis;
	TLabel *m_countFiles;
	TLabel *m_quantNodes;
	TPopupMenu *PopupMenu1;
	TActionList *ActionList1;
	TAction *actionClear;
	TMenuItem *Clearitens1;
	TMenuItem *Insertline1;
	TMenuItem *Removeline1;
	TMenuItem *N1;
	TAction *actionRemove;
	TAction *actionInsert;
	TMenuItem *N2;
	TMenuItem *Cut1;
	TMenuItem *Copy1;
	TMenuItem *Paste1;
	TAction *actionCopy;
	TAction *actionPaste;
	TAction *actionCut;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall actionClearExecute(TObject *Sender);
	void __fastcall actionRemoveExecute(TObject *Sender);
	void __fastcall actionInsertExecute(TObject *Sender);
	void __fastcall m_gridKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall actionCopyExecute(TObject *Sender);
	void __fastcall actionPasteExecute(TObject *Sender);
	void __fastcall actionCutExecute(TObject *Sender);
	void __fastcall m_gridSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value);


private:	// User declarations
	bool m_saved;
public:		// User declarations
	__fastcall TAnalysis(TComponent* Owner);
	void SetData(TSWXResultsDT * m_ResultsData);
	void SetImport(_di_IXMLNode & node);
	void SetWasSaved(bool saved);

	void ResetForm();
	void WriteMe(_di_IXMLNode & node);
	void ReadMe(_di_IXMLNode & node);
    bool GetWasSaved();


};
//---------------------------------------------------------------------------
extern PACKAGE TAnalysis *Analysis;
//---------------------------------------------------------------------------
#endif
