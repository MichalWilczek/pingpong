//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormPingpong *FormPingpong;
int xBall = -8;
int yBall = 8;

//---------------------------------------------------------------------------
__fastcall TFormPingpong::TFormPingpong(TComponent* Owner)
        : TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TFormPingpong::TimerPaddleLeftUpTimer(TObject *Sender)
{
    if (ImagePaddleLeft->Top - 10 > 0)
        ImagePaddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TFormPingpong::TimerPaddleLeftDownTimer(TObject *Sender)
{
    if (ImagePaddleLeft->Top + ImagePaddleLeft->Height + 10 < ShapeBackground->Height)
        ImagePaddleLeft->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TFormPingpong::TimerPaddleRightUpTimer(TObject *Sender)
{
    if (ImagePaddleRight->Top - 10 > 0)
        ImagePaddleRight->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TFormPingpong::TimerPaddleRightDownTimer(TObject *Sender)
{
    if (ImagePaddleRight->Top + ImagePaddleRight->Height + 10 < ShapeBackground->Height)
        ImagePaddleRight->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TFormPingpong::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_UP)
        TimerPaddleRightUp->Enabled = false;
    if (Key == VK_DOWN)
        TimerPaddleRightDown->Enabled = false;
    if (Key == 0x57)
        TimerPaddleLeftUp->Enabled = false;
    if (Key == 0x53)
        TimerPaddleLeftDown->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormPingpong::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_UP)
        TimerPaddleRightUp->Enabled = true;
    if (Key == VK_DOWN)
        TimerPaddleRightDown->Enabled = true;
    if (Key == 0x57)
        TimerPaddleLeftUp->Enabled = true;
    if (Key == 0x53)
        TimerPaddleLeftDown->Enabled = true;
}
//---------------------------------------------------------------------------



void __fastcall TFormPingpong::TimerBallTimer(TObject *Sender)
{
    // Move the ball on the screen.
    ImageBall->Left += xBall;
    ImageBall->Top += yBall;

    // Catch the ball on the upper wall.
    if (ImageBall->Top <= ShapeBackground->Top){
        yBall = -yBall;
    }
    // Catch the ball on the lower wall.
    if (ImageBall->Top + ImageBall->Height >= ShapeBackground->Height){
        yBall = -yBall;
    }
    // Hit the ball with the left paddle.
    if (ImagePaddleLeft->Left + ImagePaddleLeft->Width > ImageBall->Left &&
        ImagePaddleLeft->Left < ImageBall->Left + ImageBall->Width &&
        ImagePaddleLeft->Top < ImageBall->Top + ImageBall->Height/2 &&
        ImagePaddleLeft->Top + ImagePaddleLeft->Height > ImageBall->Top + ImageBall->Height/2){
        if (xBall < 0)
            xBall = -xBall;
    }
    // Hit the ball with the right paddle.
    if (ImagePaddleRight->Left + ImagePaddleRight->Width > ImageBall->Left &&
        ImagePaddleRight->Left < ImageBall->Left + ImageBall->Width &&
        ImagePaddleRight->Top < ImageBall->Top + ImageBall->Height/2 &&
        ImagePaddleRight->Top + ImagePaddleRight->Height > ImageBall->Top + ImageBall->Height/2){
        if (xBall > 0)
            xBall = -xBall;
    }
    // Game over.
    if (ImageBall->Left + ImageBall->Width < ShapeBackground->Left ||
        ImageBall->Left > ShapeBackground->Left + ShapeBackground->Width){
        TimerBall->Enabled = false;
        ImageBall->Enabled = false;
    }

}
//---------------------------------------------------------------------------

