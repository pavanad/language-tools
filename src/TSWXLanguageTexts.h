//---------------------------------------------------------------------------

#ifndef TSWXLanguageTextsH
#define TSWXLanguageTextsH
#include "TSWXSettings.h"
#include "TSWXAnalysis.h"
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <direct.h>

//---------------------------------------------------------------------------

class TSWXLanguageTexts
{

	public:

    	struct TMessages
		{
			UnicodeString Fill;
			UnicodeString Generate;
			UnicodeString Error;
			UnicodeString Saved1;
			UnicodeString Saved2;
			UnicodeString Directory;
		};

		TMessages msg;

	private:

		TAnalysis * m_analysis;
		TSettings * m_settings;

	public:

		TSWXLanguageTexts(TAnalysis * analysis, TSettings * settings)
		{
			m_analysis = analysis;
			m_settings = settings;
		}

		void SetLanguage(_di_IXMLNode & node);
};
#endif
