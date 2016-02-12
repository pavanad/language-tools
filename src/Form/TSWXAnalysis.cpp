//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TSWXAnalysis.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAnalysis *Analysis;
//---------------------------------------------------------------------------
__fastcall TAnalysis::TAnalysis(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAnalysis::FormCreate(TObject *Sender)
{
	m_grid->Cols[0]->Add("Item");
	m_grid->Cols[1]->Add("Object");
	m_grid->Cols[2]->Add("Value");

	m_grid->Cells[0][1] = "1";
}
//---------------------------------------------------------------------------
void TAnalysis::SetData(TSWXResultsDT * m_ResultsData)
{
	m_FileAnalysis->Visible = true;
	m_SearchNodes->Visible = true;

	int row = m_ResultsData->m_results[0].size();
	int col = m_ResultsData->m_results.size();

	m_countFiles->Visible = true;
	m_countFiles->Caption = IntToStr(m_ResultsData->m_files);

	m_quantNodes->Visible = true;
	m_quantNodes->Caption = IntToStr(m_ResultsData->m_nodes);

	m_grid->RowCount = row+1;

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			m_grid->Cells[j][i+1] = m_ResultsData->m_results[j][i];
		}
    }
}
//---------------------------------------------------------------------------
void __fastcall TAnalysis::actionClearExecute(TObject *Sender)
{
	int row = m_grid->RowCount;

	for(int i = 1; i < row; i++)
	{
		m_grid->Rows[i]->Clear();
	}

	m_grid->RowCount = 2;

	m_grid->Cells[0][1] = "1";
	m_countFiles->Caption = "";
	m_quantNodes->Caption = "";
	m_FileAnalysis->Visible = false;
	m_SearchNodes->Visible = false;
	m_saved = false;

}
//---------------------------------------------------------------------------
void __fastcall TAnalysis::actionRemoveExecute(TObject *Sender)
{
	int row = m_grid->Row, total;

	if(row==0) return;
	if(m_grid->RowCount==2) return;

	for(int i = row; i < m_grid->RowCount; i++)
	{
		for(int j = 1; j < m_grid->ColCount; j++)
		{
			m_grid->Cells[0][i] = IntToStr(i);
			m_grid->Cells[j][i] = m_grid->Cells[j][i+1];
		}
	}

	m_grid->RowCount--;

	if(m_SearchNodes->Visible)
	{
		total = m_grid->RowCount-1;
		m_quantNodes->Caption = IntToStr(total);
	}

	m_saved = false;
}
//---------------------------------------------------------------------------
void __fastcall TAnalysis::actionInsertExecute(TObject *Sender)
{
	int row = m_grid->Row, total;

	if(row==0) return;

	m_grid->RowCount++;
	for(int i = m_grid->RowCount; i > row; i--)
	{
		for(int j = 1; j < m_grid->ColCount; j++)
		{
			m_grid->Cells[0][i] = IntToStr(i);
			m_grid->Cells[j][i] = m_grid->Cells[j][i-1];
		}
	}

	m_grid->Rows[row]->Clear();
	m_grid->Cells[0][row] = IntToStr(row);

	if(m_SearchNodes->Visible)
	{
		total = m_grid->RowCount-1;
		m_quantNodes->Caption = IntToStr(total);
	}

	m_saved = false;
}
//---------------------------------------------------------------------------
void TAnalysis::ResetForm()
{
	m_FileAnalysis->Visible = false;
	m_SearchNodes->Visible = false;
	m_countFiles->Caption = "";
	m_quantNodes->Caption = "";
	actionClearExecute(this);
}
//--------------------------------------------------------------------------
void TAnalysis::WriteMe(_di_IXMLNode & node)
{
	int row = m_grid->RowCount;

	_di_IXMLNode myNode = node->AddChild("Analysis");

	if( m_FileAnalysis->Visible){
		_di_IXMLNode fileNode = myNode->AddChild("Files");
		fileNode->Text = "true";

		_di_IXMLNode countFiles = myNode->AddChild("Count_Files");
		countFiles->Text = m_countFiles->Caption;
	}

	if( m_SearchNodes->Visible){
		_di_IXMLNode SearchNode = myNode->AddChild("Search");
		SearchNode->Text = "true";

		_di_IXMLNode countNodes = myNode->AddChild("Count_Nodes");
		countNodes->Text = m_quantNodes->Caption;
	}

		_di_IXMLNode gridNode = myNode->AddChild(m_grid->ClassName());

		_di_IXMLNode rowNode = gridNode->AddChild("Rows");
		rowNode->Text = IntToStr(row-1);

		for(int i = 1; i < row; i++)
		{
			_di_IXMLNode objectNode = gridNode->AddChild("Object_" + IntToStr(i));
			objectNode->Text = m_grid->Cells[1][i];

			_di_IXMLNode valueNode = gridNode->AddChild("Value_" + IntToStr(i));
			valueNode->Text = m_grid->Cells[2][i];
		}
}
//--------------------------------------------------------------------------
void TAnalysis::ReadMe(_di_IXMLNode & node)
{
	int row;
	UnicodeString objectText,valueText, rowsText;

	_di_IXMLNode myNode = node->ChildNodes->Nodes["Analysis"];

	_di_IXMLNode filesNode = myNode->ChildNodes->Nodes["Files"];
	if(filesNode->Text == "true")
	{
		m_FileAnalysis->Visible = true;
	}

	_di_IXMLNode countFiles = myNode->ChildNodes->Nodes["Count_Files"];
	m_countFiles->Caption = countFiles->Text;

	_di_IXMLNode searchNode = myNode->ChildNodes->Nodes["Search"];
	if(searchNode->Text == "true")
	{
		m_SearchNodes->Visible = true;
	}

	_di_IXMLNode countNode = myNode->ChildNodes->Nodes["Count_Nodes"];
	m_quantNodes->Caption = countNode->Text;

	_di_IXMLNode gridNode = myNode->ChildNodes->Nodes[m_grid->ClassName()];
	_di_IXMLNode rowsNode = gridNode->ChildNodes->Nodes["Rows"];

	rowsText = rowsNode->Text;

	if (!rowsText.IsEmpty())
	{

		row = StrToInt(rowsText);
		m_grid->RowCount = row+1;

		for(int i = 1; i <= row; i++)
		{
			m_grid->Cells[0][i] = i;

			objectText = "Object_" + IntToStr(i);
			_di_IXMLNode objectNode = gridNode->ChildNodes->Nodes[objectText];
			m_grid->Cells[1][i] = objectNode->Text;

			valueText = "Value_" + IntToStr(i);
			_di_IXMLNode valueNode = gridNode->ChildNodes->Nodes[valueText];
			m_grid->Cells[2][i] = valueNode->Text;

		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TAnalysis::m_gridKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	int row,col;

	row = m_grid->Row;
	col = m_grid->Col;

	if (Key == VK_DELETE) {
		m_grid->Cells[col][row] = "";
	}
}
//---------------------------------------------------------------------------
void __fastcall TAnalysis::actionCopyExecute(TObject *Sender)
{
	int row,col;
	HGLOBAL hText;
	char *pText;

	row = m_grid->Row;
	col = m_grid->Col;

	hText = GlobalAlloc(GMEM_DDESHARE|GMEM_MOVEABLE, 100);
	pText = (char*) GlobalLock(hText);
	strcpy(pText,m_grid->Cells[col][row].t_str());
	GlobalUnlock(hText);


	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hText);
	CloseClipboard();

}
//---------------------------------------------------------------------------
void __fastcall TAnalysis::actionPasteExecute(TObject *Sender)
{
	int row,col;

	row = m_grid->Row;
	col = m_grid->Col;

	OpenClipboard(NULL);
	HANDLE foo = GetClipboardData(CF_TEXT);
	CloseClipboard();
	LPVOID lptstr = GlobalLock(foo);

	m_grid->Cells[col][row] = (char*) lptstr;

}
//---------------------------------------------------------------------------
void __fastcall TAnalysis::actionCutExecute(TObject *Sender)
{
	int row, col;

	row = m_grid->Row;
	col = m_grid->Col;

	actionCopyExecute(Sender);
	m_grid->Cells[col][row] = "";
	m_saved = false;
}
//---------------------------------------------------------------------------
void TAnalysis::SetImport(_di_IXMLNode & node)
{
	int count = node->ChildNodes->GetCount();

	_di_IXMLNode myNode = node->ChildNodes->First();

	m_grid->RowCount = count+1;

	for(int i = 1; i <= count; i++)
	{
		m_grid->Cells[0][i] = IntToStr(i);
		m_grid->Cells[1][i] = myNode->GetLocalName();
		m_grid->Cells[2][i] = myNode->Text;

		myNode = myNode->NextSibling();
	}

	m_SearchNodes->Visible = true;
	m_quantNodes->Caption = IntToStr(count);
}
//---------------------------------------------------------------------------
void TAnalysis::SetWasSaved(bool saved)
{
	m_saved = saved;
}
//---------------------------------------------------------------------------
void __fastcall TAnalysis::m_gridSetEditText(TObject *Sender, int ACol, int ARow,
		  const UnicodeString Value)
{
	m_saved = false;
}
//---------------------------------------------------------------------------
bool TAnalysis::GetWasSaved()
{
	return m_saved;
}
