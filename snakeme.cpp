 #include <iostream>
#include <windows.h>
#include <conio.h>
#define MAX 100
using namespace std;

int toa_dox[MAX];
int toa_doy[MAX];
int length = 4;
//------------------------
void gotoxy(int x, int y){
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}};

void fence (){
    for (int x=5; x<=115; x++){
        gotoxy(x, 1);
        cout<<"_";
        gotoxy(x, 25);
        cout<<"_";
    }
    for (int y=2; y<=25; y++){
        gotoxy (5, y);
        cout<<"|";
        gotoxy(115, y);
        cout<<"|";
    }
}

//--------------------------
void toadoran(){
int x0 = 60;
int y0 = 15;
for (int i=0; i < length; i++){
    toa_dox[i] = x0--;
    toa_doy[i] = y0;
}
 }

void drawsnake (){
for (int i=0; i<length ; i++){
   gotoxy(toa_dox[i], toa_doy[i]);
  if (i == 0){
    cout<<"D";
  }
  else {
    cout<<"O";
  }
}
}
//---------------------------
void snakemove(int X, int Y){
for (int i = length; i>0; i--){
    toa_dox[i] = toa_dox[i-1];
    toa_doy[i] = toa_doy[i-1];
}
toa_dox [0] = X;
toa_doy[0] = Y;}

//---------------------------



int main (){
    int check = 2;
    int X = toa_dox[0];
    int Y = toa_doy[0];
    fence();
    toadoran();
    drawsnake();
    while(true){
        //xoa dot cu --------
        gotoxy(toa_dox[length], toa_doy[length]);
        cout<<" ";
        //ve-------------
        drawsnake();
        //move
        if(check == 0){
            Y++;
        }
        else if (check == 1){
            Y--;
        }
        else if (check == 2){
            X++;
        }
        else if (check == 3){
            X--;
        }
        snakemove(X, Y);
    //speed--------------
        Sleep(200);
    //control----------------
    if (_kbhit()){
        char c = _getch();
        if (c == -32){
            c == _getch();
            if (c == 72){
                check = 1;
            }
            else if (c == 80){
                check = 0;
            }
            else if (c == 75){
                check = 3;
            }
            else if (c == 77){
                check = 2;
            }
        }
    }
    }
return 0;
}

