#ifndef BOARD2D_H_
#define BOARD2D_H_
#include "board.h"

namespace zaff{
class BoardArray2D : public AbstractBoard {
	
	protected:
		int **board2d;
		int **finalGameBoard2d;
	public:
		virtual void setSize(int num1,int num2);
		virtual bool isSolved()const;
		virtual void initBoard(string s_array[9]);
		virtual void init_final_board();
		virtual void writeToFile()const;
		virtual void readFromFile();
		virtual void print()const;
		BoardArray2D();
		BoardArray2D(int num1,int num2);
		BoardArray2D(const BoardArray2D& obj);
		BoardArray2D& operator=(const BoardArray2D &obj);
		virtual void reset();
		virtual void move(char movee);
		virtual bool operator ==(const AbstractBoard& other);
		virtual int operator()(int a,int b);
		~BoardArray2D();
};
}

#endif
