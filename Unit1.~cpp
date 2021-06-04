//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPingpong *FormPingpong;
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



