#include <iostream>
#include"Queue.h"

#ifndef SNAKE_H_
#define SNAKE_H_

using namespace std;

struct position
{
	int x;
	int y;
};

template <class T>
class Snake
{
  private: 	
	char GameField[20][20];
	position head_position;
	Queue<T> SnakeBody;
	int SnakeSize;
	int next_size_up_value;
	int count;
	bool ResetFlag;/*a flag to set tha cursor at (5,5) when knowing that display() is called for the first time*/
	void display();
  public:
  	Snake();
  	void gameLoop();
  	void func();
};

#endif
