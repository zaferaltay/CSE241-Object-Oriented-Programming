#ifndef BOARD1D_H_
#define BOARD1D_H_
#include "board.h"

namespace zaff{
class BoardArray1D : public AbstractBoard {
	
	protected:
		int *board1d;
		int *finalGameBoard1d;
	public:
		virtual void setSize(int num1,int num2);
		virtual bool isSolved()const;
		virtual void initBoard(string s_array[9]);
		virtual void init_final_board();
		virtual void readFromFile();
		virtual void writeToFile()const;
		virtual void print()const;
		BoardArray1D();
		BoardArray1D(int num1,int num2);
		BoardArray1D(const BoardArray1D& obj);
		BoardArray1D& operator=(const BoardArray1D& obj);
		virtual void reset();
		virtual void move(char movee);
		virtual bool operator ==(const AbstractBoard& other);
		virtual int operator()(int a,int b);
		~BoardArray1D();
};

}
#endif
