//---------------------------------------------------------------------------

#ifndef TSWXAboutH
#define TSWXAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TAbout : public TForm
{
__published:	// IDE-managed Components
	TImage *m_image;
	TLabel *m_label1;
	void __fastcall m_imageClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAbout *About;
//---------------------------------------------------------------------------
#endif
