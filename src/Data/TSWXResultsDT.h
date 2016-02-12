//---------------------------------------------------------------------------

#ifndef TSWXResultsDTH
#define TSWXResultsDTH

#include <vector>
#include <Classes.hpp>

//---------------------------------------------------------------------------

class TSWXResultsDT
{
	public:
		int m_files;
		int m_nodes;
		std::vector< std::vector<UnicodeString> > m_results;

		void SetData(int files, int nodes,
					 std::vector< std::vector<UnicodeString> > results);
};
#endif
