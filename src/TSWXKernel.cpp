//---------------------------------------------------------------------------


#pragma hdrstop

#include "TSWXKernel.h"

#pragma package(smart_init)

//---------------------------------------------------------------------------
TSWXKernel::TSWXKernel(TSWXMainDT * data, TAnalysis * analysis)
{
	m_data = data;
	m_analysis = analysis;
	this->Compute();
}
//---------------------------------------------------------------------------
void TSWXKernel::Compute()
{
	int nodes=0, files;
	const int max = 200;
	char buff[max];
	char arq[max];
	UnicodeString value,temp1, temp2, object;
	std::vector<UnicodeString> list;
	std::vector< std::vector<UnicodeString> > result (3);

	//recebe os dados do data tranfer
	list = m_data->GetData();

	//habilita o progress bar
	m_analysis->m_progress->Visible = true;

	//conta os arquivos selecionados
	files = list.size();

	//percorre o vector e abre os arquivos
	for(int i = 0; i < files; i++)
	{
		ifstream arquivo;
		arquivo.open(list[i].c_str());

		while(arquivo)
		{
			arquivo.getline(buff,max);
			line = buff;

			object = this->GetObject();
			value = this->GetValue();

			if (!object.IsEmpty()) {
				temp1 = object;
			}
			if (!value.IsEmpty()) {
				temp2 = value;
			}

			if (!temp1.IsEmpty() && !temp2.IsEmpty()){
				nodes++;
				result[0].push_back(nodes);
				result[1].push_back(temp1);
				result[2].push_back(temp2);
				temp1 = "";
				temp2 = "";
			}

			object = NULL;
			value = NULL;
		}

		arquivo.close();
		delete arquivo;

		m_analysis->m_progress->Position = (i+1)*(100/files);
		m_analysis->Update();
	}

	m_ResultsData = new TSWXResultsDT();
	m_ResultsData->SetData(files,nodes,result);
	m_analysis->SetData(m_ResultsData);

	m_analysis->m_progress->Position = 0;
	m_analysis->m_progress->Visible = false;

}
//------------------------------------------------------------------------------
UnicodeString TSWXKernel::GetObject()
{
	int start, qtd;
	for(int j = 0; j < line.Length(); j++)
	{
		if (line.SubString(j,6)=="object")
		{
			start = (j+6)+1;
		}

		if (line.SubString(j,1)==":")
		{
			qtd = j - start;
			return line.SubString(start,qtd);
		}
	}
}
//------------------------------------------------------------------------------
UnicodeString TSWXKernel::GetValue()
{
	int start, qtd;
	for(int j = 0; j < line.Length(); j++)
	{
		if (line.SubString(j,7)=="Caption")
		{
			start = (j+7)+4;
		}
	}

	qtd = line.Length() - start;
	return line.SubString(start,qtd);
}
//------------------------------------------------------------------------------
