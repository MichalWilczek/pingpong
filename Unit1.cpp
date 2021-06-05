//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormPingpong *FormPingpong;
int X_BALL_INIT = -3;
int Y_BALL_INIT = 3;

int xBall = X_BALL_INIT;
int yBall = Y_BALL_INIT;
int moves = 0;
int numberWinsLeft = 0;
int numberWinsRight = 0;

void increaseBallSpeed(int displacementIncrement=1){
    // Speed up the ball after a given number of moves
    if (moves%4 == 0 & moves != 0) {

        // Increase the ball displacement in x-direction.
        if (xBall < 0) xBall -= displacementIncrement;
        else xBall += displacementIncrement;

        // Increase the ball displacement in y-direction.
        if (yBall < 0) xBall -= displacementIncrement;
        else yBall += displacementIncrement;
    }
}

//---------------------------------------------------------------------------
__fastcall TFormPingpong::TFormPingpong(TComponent* Owner)
        : TForm(Owner)
{
    ImageBall->Left = ShapeBackground->Left + ShapeBackground->Width/2 - ImageBall->Width/2;
    ImageBall->Top = ShapeBackground->Top + ShapeBackground->Height/2 - ImageBall->Height/2;
}

//---------------------------------------------------------------------------

void __fastcall TFormPingpong::TimerPaddleLeftUpTimer(TObject *Sender)
{
    if (ImagePaddleLeft->Top - 50 > 0)
        ImagePaddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TFormPingpong::TimerPaddleLeftDownTimer(TObject *Sender)
{
    if (ImagePaddleLeft->Top + ImagePaddleLeft->Height - 20 < ShapeBackground->Height)
        ImagePaddleLeft->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TFormPingpong::TimerPaddleRightUpTimer(TObject *Sender)
{
    if (ImagePaddleRight->Top - 50 > 0)
        ImagePaddleRight->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TFormPingpong::TimerPaddleRightDownTimer(TObject *Sender)
{
    if (ImagePaddleRight->Top + ImagePaddleRight->Height - 20 < ShapeBackground->Height)
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
        if (xBall < 0){
            xBall = -xBall;
            moves++;
            increaseBallSpeed();
        }
    }
    // Hit the ball with the right paddle.
    if (ImagePaddleRight->Left + ImagePaddleRight->Width > ImageBall->Left &&
        ImagePaddleRight->Left < ImageBall->Left + ImageBall->Width &&
        ImagePaddleRight->Top < ImageBall->Top + ImageBall->Height/2 &&
        ImagePaddleRight->Top + ImagePaddleRight->Height > ImageBall->Top + ImageBall->Height/2){
        if (xBall > 0){
            xBall = -xBall;
            moves++;
            increaseBallSpeed();
        }
    }
    // Game over.
    if (ImageBall->Left + ImageBall->Width < ShapeBackground->Left ||
        ImageBall->Left > ShapeBackground->Left + ShapeBackground->Width){

        if (ImageBall->Left + ImageBall->Width < ShapeBackground->Left)
            numberWinsRight++;
        if (ImageBall->Left > ShapeBackground->Left + ShapeBackground->Width)
            numberWinsLeft++;

        TimerBall->Enabled = false;
        ImageBall->Enabled = false;
        ButtonNewRound->Visible = true;

        LabelPoints->Caption = IntToStr(numberWinsLeft) + " : " + IntToStr(numberWinsRight);
        LabelMoves->Caption = "Number of moves: " + IntToStr(moves);
        LabelMoves->Visible = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFormPingpong::ButtonNewRoundClick(TObject *Sender)
{
    ImageBall->Left = ShapeBackground->Left + ShapeBackground->Width/2 - ImageBall->Width/2;
    ImageBall->Top = ShapeBackground->Top + ShapeBackground->Height/2 - ImageBall->Height/2;
    ImageBall->Visible = true;
    ImageBall->Enabled = true;

    TimerBall->Enabled = true;
    ButtonNewRound->Visible = false;
    LabelMoves->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormPingpong::New1Click(TObject *Sender)
{
    FormPingpong->ButtonNewRoundClick(ButtonNewRound);
    numberWinsLeft = 0;
    numberWinsRight = 0;
    LabelPoints->Caption = IntToStr(numberWinsLeft) + " : " + IntToStr(numberWinsRight);
}
//---------------------------------------------------------------------------

void __fastcall TFormPingpong::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    TimerBall->Enabled = false;

    if (Application->MessageBox("Do you want to exit?",
    "Confirm", MB_YESNO | MB_ICONQUESTION) == IDNO) {
        Action=0;
    }
    TimerBall->Enabled = true;
}
//---------------------------------------------------------------------------

