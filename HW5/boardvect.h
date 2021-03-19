#ifndef BOARDVECT_H_
#define BOARDVECT_H_
#include "board.h"

namespace zaff{
class BoardVector : public AbstractBoard {
	
	protected:
		vector<vector<int>> boardvector;
		vector<vector<int>> finalvector;
	public:
		virtual void setSize(int num1,int num2);
		virtual bool isSolved()const;
		virtual void initBoard(string s_array[9]);
		virtual void init_final_board();
		virtual void readFromFile();
		virtual void writeToFile()const;
		virtual void print()const;
		BoardVector();
		BoardVector(int num1,int num2);
		BoardVector(const BoardVector& obj);
		~BoardVector();
		virtual void reset();
		virtual void move(char movee);
		virtual bool operator ==(const AbstractBoard& other);
		virtual int operator()(int a,int b);
};
}
#endif
