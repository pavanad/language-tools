//---------------------------------------------------------------------------


#pragma hdrstop

#include "TSWXMainDT.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------
void TSWXMainDT::SetData(std::vector<UnicodeString> list)
{
    m_list = list;
}

std::vector<UnicodeString> TSWXMainDT::GetData()
{
	return m_list;
}
