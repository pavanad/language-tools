//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TSWXSettings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSettings *Settings;
//---------------------------------------------------------------------------
__fastcall TSettings::TSettings(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSettings::m_saveClick(TObject *Sender)
{
	TSaveDialog * save = new TSaveDialog(NULL);
	save->Filter = "Lang files (*.lang)|*.lang|XML files (*.xml)|*.xml";
	save->FilterIndex = 0;
	save->DefaultExt = "lang";
	save->Options << ofOverwritePrompt;


	if(save->Execute())
	{
		m_dest->Text = save->FileName;
		m_saved = false;
 	}

	delete save;
}
//---------------------------------------------------------------------------
void __fastcall TSettings::actionUpExecute(TObject *Sender)
{
	UnicodeString temp;
	int count = m_ls->Items->Count;
	int sel = m_ls->ItemIndex;

	if (sel <= 0) return;

	for(int i = 0; i < count; i++)
	{
		if(i == m_ls->ItemIndex)
		{
			temp = m_ls->Items->Item[i-1]->Caption;
			m_ls->Items->Item[i-1]->Caption = m_ls->Items->Item[i]->Caption;
			m_ls->Items->Item[i]->Caption = temp;
			sel = i-1;
		}
	}
	m_saved = false;
	m_ls->Items->Item[sel]->Selected = true;

}
//---------------------------------------------------------------------------
void __fastcall TSettings::actionBottomExecute(TObject *Sender)
{
	UnicodeString temp;
	int count = m_ls->Items->Count;
	int sel = m_ls->ItemIndex;

	if ( (sel < 0) || (sel >= (count-1)) ) return;

	for(int i = 0; i < count; i++)
	{
		if(i == m_ls->ItemIndex)
		{
			temp = m_ls->Items->Item[i+1]->Caption;
			m_ls->Items->Item[i+1]->Caption = m_ls->Items->Item[i]->Caption;
			m_ls->Items->Item[i]->Caption = temp;
			sel = i+1;
		}
	}

	m_saved = false;
	m_ls->Items->Item[sel]->Selected = true;
}
//---------------------------------------------------------------------------
void __fastcall TSettings::actionRemoveExecute(TObject *Sender)
{
	int sel = m_ls->ItemIndex;

	if(sel<0) return;
	m_ls->Items->Delete(sel);

	if(sel < m_ls->GetCount())
	{
    	m_ls->Items->Item[sel]->Selected = true;
	}

}
//---------------------------------------------------------------------------
void __fastcall TSettings::actionClearExecute(TObject *Sender)
{
	m_ls->Clear();
	m_saved = false;
}
//---------------------------------------------------------------------------
void TSettings::ResetForm()
{
	m_dest->Text = "";
	m_ckOpen->Checked = false;
	m_ls->Clear();

}
//---------------------------------------------------------------------------
void TSettings::WriteMe(_di_IXMLNode & node)
{
	int count = m_ls->GetCount();

	_di_IXMLNode myNode = node->AddChild("Settings");

	_di_IXMLNode targetNode = myNode->AddChild(m_dest->ClassName());
	targetNode->Text = m_dest->Text;

	if(m_ckOpen->Checked){
		_di_IXMLNode openNode = myNode->AddChild(m_ckOpen->ClassName());
		openNode->Text = "true";
	}

	_di_IXMLNode rowNode = myNode->AddChild("Rows");
	rowNode->Text = IntToStr(count);

	for(int i = 0; i < count; i++)
	{
		_di_IXMLNode listNode = myNode->AddChild(m_ls->ClassName() + "_" + (i+1));
		listNode->Text = m_ls->Items->Item[i]->Caption;
	}
}
//---------------------------------------------------------------------------
void TSettings::ReadMe(_di_IXMLNode & node)
{
	int rows;

	_di_IXMLNode myNode = node->ChildNodes->Nodes["Settings"];

	_di_IXMLNode targetNode = myNode->ChildNodes->Nodes[m_dest->ClassName()];
	m_dest->Text = targetNode->Text;

	_di_IXMLNode openNode = myNode->ChildNodes->Nodes[m_ckOpen->ClassName()];

	if(openNode->Text == "true")
	{
		m_ckOpen->Checked = true;
	}

	_di_IXMLNode rowsNode = myNode->ChildNodes->Nodes["Rows"];
	rows = StrToInt(rowsNode->Text);

	m_ls->Clear();

	for(int i = 0; i < rows; i++)
	{
		_di_IXMLNode listNode = myNode->ChildNodes->Nodes[m_ls->ClassName() + "_" + (i+1)];
		m_ls->AddItem(listNode->Text, NULL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TSettings::m_ckOpenClick(TObject *Sender)
{
	m_saved = false;
}
//---------------------------------------------------------------------------
void __fastcall TSettings::m_lsEdited(TObject *Sender, TListItem *Item, UnicodeString &S)
{
	m_saved = false;
}
//---------------------------------------------------------------------------
void __fastcall TSettings::m_lsInsert(TObject *Sender, TListItem *Item)
{
	m_saved = false;
}
//---------------------------------------------------------------------------
void __fastcall TSettings::m_lsDeletion(TObject *Sender, TListItem *Item)
{
	m_saved = false;
}
//---------------------------------------------------------------------------
void TSettings::SetWasSaved(bool saved)
{
	m_saved = saved;
}
//---------------------------------------------------------------------------
bool TSettings::GetWasSaved()
{
	if(m_dest->Modified) m_saved = false;
	return m_saved;
}
