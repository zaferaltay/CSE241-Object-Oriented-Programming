#ifndef BOARD_H_
#define BOARD_H_
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

 	
namespace zaff{

class AbstractBoard
	{
	protected:
		int row,column,empty_x,empty_y;
		char lastmove;
		int total_move=0,count=1;
		string dosya_adi;
		string arrayy[9];
		int numBoard=0;
	public:
		virtual void print()const=0;
		virtual void init_final_board()=0;
		virtual void initBoard(string s_array[9])=0;
		virtual void readFromFile()=0;
		virtual void writeToFile()const=0;
		virtual void move(char movee)=0;
		virtual void reset()=0;
		virtual void setSize(int num1,int num2)=0;
		virtual bool isSolved()const=0;
		char lastMove()const;
		int getRow()const;
		void setRow(int a);
		void setColumn(int a);
		int getColumn()const;
		int getEmptyX()const;
		int getEmptyY()const;
		void setEmptyX(int emmpty_x);
		void setEmptyY(int emmpty_y);
		virtual bool operator == (const AbstractBoard& other)=0;
		virtual int operator()(int a,int b)=0;
		int numberOfMoves()const;
		int NumberOfBoard()const;
};

}

#endif
