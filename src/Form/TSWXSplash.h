//---------------------------------------------------------------------------

#ifndef TSWXSplashH
#define TSWXSplashH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TSplash : public TForm
{
__published:	// IDE-managed Components
	TImage *m_background;
	TLabel *m_Load;
	TProgressBar *m_Progress;
private:	// User declarations
public:		// User declarations
	__fastcall TSplash(TComponent* Owner);

	void ShowTime(std::vector<UnicodeString> & Messages);
};
//---------------------------------------------------------------------------
extern PACKAGE TSplash *Splash;
//---------------------------------------------------------------------------
#endif
