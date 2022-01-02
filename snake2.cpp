#include <iostream>
#include <windows.h>
#include <conio.h>
#define MAX 100
using namespace std;

struct Point{
int x;
int y;
int x0;
int y0;
};

Point snake[MAX];
int length = 4;


void gotoxy(int x, int y){
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}};

void fence(){
for (int i=5; i<=115; i++){
    gotoxy(i,1);
    cout<<"_";
    gotoxy (i,25);
    cout<<"_";
for (int j=2; j<=25; j++){
    gotoxy (5,j);
    cout<<"|";
    gotoxy (115, j);
    cout<<"|";
}
}
}

void bornsnake(){
snake[0].x0 = 15;
snake[0].y0 = 5;
for (int i=0; i<length; i++){
    snake[i].x = snake[0].x0--;
    snake[i].y = snake[0].y0;
   }
}

void drawsnake(){
for(int i=0; i<length; i++){
    gotoxy(snake[i].x, snake[i].y);
    if(i==0){
        cout<<"D";
    }
    else{
    cout<<"O";
    }
}}

void snakemove(){
    for (int i=0; i<length; i++){
        snake[i].x=snake[i-1].x;
        snake[i].y=snake[i-1].y;
    }
    snake[0].x
}

int main (){
fence();
bornsnake();
drawsnake();
while(true){
snakemove();
}
return 0;
}
