//---------------------------------------------------------------------------


#pragma hdrstop

#include "TSWXResultsDT.h"
#pragma package(smart_init)

//---------------------------------------------------------------------------
void TSWXResultsDT::SetData(int files, int nodes,
							std::vector< std::vector<UnicodeString> > results)
{
	m_files = files;
	m_nodes = nodes;
	m_results = results;
}
