//---------------------------------------------------------------------------


#pragma hdrstop

#include "TSWXLanguageTexts.h"
#pragma package(smart_init)

//---------------------------------------------------------------------------
void TSWXLanguageTexts::SetLanguage(_di_IXMLNode & node)
{

	//altera o idioma do form settings
	_di_IXMLNode myNode = node->ChildNodes->Nodes[m_settings->GroupSettings->Name];
	m_settings->GroupSettings->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_settings->m_target->Name];
	m_settings->m_target->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_settings->m_save->Name];
	m_settings->m_save->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_settings->m_ckOpen->Name];
	m_settings->m_ckOpen->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_settings->m_ls->Name];
	m_settings->m_ls->Columns->Items[0]->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_settings->Movetoup1->Name];
	m_settings->Movetoup1->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_settings->Movetobottom1->Name];
	m_settings->Movetobottom1->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_settings->Remove1->Name];
	m_settings->Remove1->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_settings->Clearitens1->Name];
	m_settings->Clearitens1->Caption = myNode->Text;

	//altera o idioma do form analysis
	myNode = node->ChildNodes->Nodes[m_analysis->GroupAnalysis->Name];
	m_analysis->GroupAnalysis->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_analysis->m_analyze->Name];
	m_analysis->m_analyze->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_analysis->m_status->Name];
	m_analysis->m_status->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_analysis->m_SearchNodes->Name];
	m_analysis->m_SearchNodes->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_analysis->m_FileAnalysis->Name];
	m_analysis->m_FileAnalysis->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_analysis->Insertline1->Name];
	m_analysis->Insertline1->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_analysis->Removeline1->Name];
	m_analysis->Removeline1->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_analysis->Clearitens1->Name];
	m_analysis->Clearitens1->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_analysis->Cut1->Name];
	m_analysis->Cut1->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_analysis->Copy1->Name];
	m_analysis->Copy1->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes[m_analysis->Paste1->Name];
	m_analysis->Paste1->Caption = myNode->Text;

	myNode = node->ChildNodes->Nodes["Fill"];
	msg.Fill = myNode->Text;

	myNode = node->ChildNodes->Nodes["Generate"];
	msg.Generate = myNode->Text;

	myNode = node->ChildNodes->Nodes["Error"];
	msg.Error = myNode->Text;

	myNode = node->ChildNodes->Nodes["Saved1"];
	msg.Saved1 = myNode->Text;

	myNode = node->ChildNodes->Nodes["Saved2"];
	msg.Saved2 = myNode->Text;

	myNode = node->ChildNodes->Nodes["Directory"];
	msg.Directory = myNode->Text;
}

