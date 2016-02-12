//---------------------------------------------------------------------------

#ifndef TSWXMainDTH
#define TSWXMainDTH
#include <vector>
#include <Classes.hpp>
//---------------------------------------------------------------------------

class TSWXMainDT
{
	public:

		std::vector<UnicodeString> m_list;

		void SetData(std::vector<UnicodeString> list);
		std::vector<UnicodeString> GetData();
};
#endif
