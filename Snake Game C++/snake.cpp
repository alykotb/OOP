#include <iostream>
#include "conio.h"
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "snake.h"
#include  "stdlib.h"
using namespace std;



template <class T>
Snake<T>::Snake()
{	
srand(time(0));
	int i,j;
	/*initializing the game field*/
	for(i=0;i<20;i++)
	{
	  for(j=0;j<20;j++)
	  {
          GameField[i][j]=-80;
      }
	}	
	ResetFlag=true;
	head_position.x=5;
	head_position.y=5;	
	SnakeSize=1;
	count=0;
	next_size_up_value=(rand() % 5) + 1;
}

template <class T>
void Snake<T>::display()
{
	
	position edited_position;
	char c;
	int i,j;
	if(SnakeBody.size()==SnakeSize)
	{
		edited_position=SnakeBody.remove();	
        GameField[edited_position.x] [edited_position.y]=-80;
	}

   for(i=0;i<20;i++)
	{
	  for(j=0;j<20;j++)
	  {
          cout<<GameField[i][j];
      }
       cout<<endl;
	}  
	if(ResetFlag==true)
	{
		ResetFlag=false;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{5,5});
		
	}
	count++;
	if(count==next_size_up_value)
	{
		count=0;
		SnakeSize=SnakeSize+next_size_up_value;
		next_size_up_value=(rand() % 5) + 1;
	}
}

template <class T>
void Snake<T>::gameLoop()
{
	

	display();
	
	SnakeBody.add(head_position);
	
	switch(getch())
	{
		case 'w': head_position.x-=1;
		          break;
		case 'a': head_position.y-=1;
		          break;
		case 'd': head_position.y+=1;
		          break;
		case 's': head_position.x+=1;
		          break;
	}
	if(GameField[head_position.x][head_position.y]==-78)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{5,0});
		cout<<"GAME OVER"<<endl;		
	}
	else if((head_position.x<1)||(head_position.x>18))
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{5,0});
		cout<<"GAME OVER"<<endl;	
	}
	else if ((head_position.y<1)||(head_position.y>18))
	{
	    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{5,0});
		cout<<"GAME OVER"<<endl;	
	}
	else
	{
			GameField[head_position.x][head_position.y]=-78;
			system("cls");
	        gameLoop();
	}
}


