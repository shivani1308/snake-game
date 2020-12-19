#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int width=20 , height=20 , GameOver;
int x,y,fruitX,fruitY,score,flag;
int tailX[100],tailY[100];
int counttail = 0;
void setup(){
  GameOver = 0;
  x=width/2;
  y=height/2;
label1:
  fruitX = rand()%20;
if(fruitX==0)
goto label1;
label2:
  fruitY = rand()%20;
if(fruitY==0)
goto label2;
score = 0;

  
}
void draw()
{
int i, j , k ;
system("cls");
for(i=0;i<width;i++)
{
for(j=0;j<height;j++)
{
if(i==0||i==height-1||j==0||j==width-1)
{
printf("*");
}
else{
  if(i==x && j==y)
   printf("O");
else if (i==fruitX && j==fruitY)
printf("F");
else{ int ch = 0;
for(k=0;  k< counttail;k++)
{
if( i == tailX[k] && j==tailY[k]){
printf("o");
ch = 1;}

}
//this ch variable is used so that boundary does not move
if(ch==0) 
printf(" ");
}
}
printf("\n");
}
printf("SCORE=%d",score);

}
void input()
{
if(kbhit())
{ switch(getch())
{
case 'a': //  a s w z these 4 buttons are used
flag = 1;
break;
case 's':
flag = 2;
break;
case 'w':
flag =3 ;
break;
case 'z':
flag = 4 ;
case 'x' : //if user wants to quit the game 
 GameOver = 1;
 break;
}
}
}
void makelogic()
{ 
//to increase snake size we will make an array to store the value
int i;
int prevX = tailX[0];
int prevY = tailY[0];
int prev2x , prev2y;   
tailX[0] =x;
tailY[0] = y; 
for(i=1;i<counttail;i++)
{ 
prev2x = tailX[i];
prev2y = tailY[i];
tailX[i]= prevX;
tailY[i]= prevY;
prevX = prev2x;
prevY = prev2y;

}


switch(flag)
{
case 1:
y--;
break;
case 2:
y++;
break;
case 3:
x--;
break;
case 4:
x++;
break;
 default:
 break;}
if(x<0 || x>width || y<0 ||y>height)
GameOver = 1;
//this loop is used if snake collapse with its head then game will be over
for(i = 0 ; i<counttail;i++)
{
if(x==tailX[i] && y==tailY[i])
GameOver = 1;
}
if(x==fruitX && y==fruitY){
//to generate new food
label3:
  fruitX = rand()%20;
if(fruitX==0)
goto label3;
label4:
  fruitY = rand()%20;
if(fruitY==0)
goto label4;
score+=1;
counttail++;

}
}

int main()
{
int m,n;
char c; 
label5:

setup();
while(!GameOver){
draw();
input();
makelogic();
//these are used to make snake slow but you can use sleep() or delay () function also.
for(m=0;m<100000;m++){
for(n=0;n<100000;n++){
}}
for(m=0;m<1000;m++){
for(n=0;n<1000;n++){
}}
}

printf("\n PRESS Y TO CONTINUE......");
scanf("%c",&c);
do
 { 
  printf("press y to continue...... ");
  scanf("%c",&c);
if(c=='y')
   goto label5; }while(c=='y');

}
}
