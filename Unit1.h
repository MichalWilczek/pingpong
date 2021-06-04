//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormPingpong : public TForm
{
__published:	// IDE-managed Components
        TShape *ShapeBackground;
        TImage *ImagePaddleLeft;
        TImage *ImagePaddleRight;
        TImage *ImageBall;
        TTimer *TimerPaddleLeftUp;
        TTimer *TimerPaddleLeftDown;
        TTimer *TimerPaddleRightUp;
        TTimer *TimerPaddleRightDown;
        void __fastcall TimerPaddleLeftUpTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall TimerPaddleLeftDownTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall TimerPaddleRightUpTimer(TObject *Sender);
        void __fastcall TimerPaddleRightDownTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormPingpong(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPingpong *FormPingpong;
//---------------------------------------------------------------------------
#endif