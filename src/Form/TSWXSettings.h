//---------------------------------------------------------------------------

#ifndef TSWXSettingsH
#define TSWXSettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include "TeCanvas.hpp"
#include "TeeEdiGrad.hpp"
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include "TSWXSplash.h"
//---------------------------------------------------------------------------
class TSettings : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupSettings;
	TLabel *m_target;
	TEdit *m_dest;
	TButton *m_save;
	TCheckBox *m_ckOpen;
	TListView *m_ls;
	TButton *m_top;
	TButton *m_bottom;
	TButton *m_del;
	TImageList *ImageList1;
	TImageList *ImageList2;
	TPopupMenu *PopupMenu1;
	TMenuItem *Movetoup1;
	TMenuItem *Movetobottom1;
	TMenuItem *Remove1;
	TMenuItem *N1;
	TMenuItem *Clearitens1;
	TActionList *ActionList1;
	TAction *actionUp;
	TAction *actionBottom;
	TAction *actionRemove;
	TAction *actionClear;
	void __fastcall m_saveClick(TObject *Sender);
	void __fastcall actionUpExecute(TObject *Sender);
	void __fastcall actionBottomExecute(TObject *Sender);
	void __fastcall actionRemoveExecute(TObject *Sender);
	void __fastcall actionClearExecute(TObject *Sender);
	void __fastcall m_ckOpenClick(TObject *Sender);
	void __fastcall m_lsEdited(TObject *Sender, TListItem *Item, UnicodeString &S);
	void __fastcall m_lsInsert(TObject *Sender, TListItem *Item);
	void __fastcall m_lsDeletion(TObject *Sender, TListItem *Item);



private:	// User declarations
	bool m_saved;
public:		// User declarations
	__fastcall TSettings(TComponent* Owner);

	void SetWasSaved(bool saved);

	void ResetForm();
	void WriteMe(_di_IXMLNode & node);
	void ReadMe(_di_IXMLNode & node);
	bool GetWasSaved();

};
//---------------------------------------------------------------------------
extern PACKAGE TSettings *Settings;
//---------------------------------------------------------------------------
#endif
