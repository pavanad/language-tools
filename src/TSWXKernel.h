//---------------------------------------------------------------------------

#ifndef TSWXKernelH
#define TSWXKernelH

#include "TSWXMainDT.h"
#include "TSWXAnalysis.h"
#include "TSWXResultsDT.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
//---------------------------------------------------------------------------

class TSWXKernel
{
	private:

		TSWXMainDT * m_data;
		TAnalysis * m_analysis;
		TSWXResultsDT * m_ResultsData;

		UnicodeString line;

	public:

		TSWXKernel(TSWXMainDT * data, TAnalysis * analysis);

		void Compute();

		UnicodeString GetObject();
		UnicodeString GetValue();

};
#endif
