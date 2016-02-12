//---------------------------------------------------------------------------

#ifndef TSWXLanguageThreadH
#define TSWXLanguageThreadH

class TSWXMainDT;

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <vector>
#include "TSWXAnalysis.h"

//---------------------------------------------------------------------------
class TSWXLanguageThread : public TThread
{
private:

	TSWXMainDT * m_data;
	TAnalysis * m_analysis;

protected:
	void __fastcall Execute();
public:
	__fastcall TSWXLanguageThread(TSWXMainDT * data,
								   TAnalysis * child, bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
