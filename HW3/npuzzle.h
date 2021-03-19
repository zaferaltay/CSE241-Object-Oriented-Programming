#ifndef NPUZZLE_H_
#define NPUZZLE_H_
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class NPuzzle{
	const int max=9;
	string arrayy[9],a;
	int game[9][9],row2,column2,count=0,final_board[9][9],random,emmpty_x,emmpty_y;
	private:
	class Board
	{
	private:
		int board[9][9],row,column,final_game_board[9][9],empty_x,empty_y,random;
		int total_move=0,count=1;
		public:
		void print();
		void init_final_board();
		void initBoard(string s_array[9]);
		void readFromFile(string arrayy[9]);
		void readFromFile2(string arrayy[9],string dosya_adi);
		void writeToFile();
		void move(char movee);
		void reset();
		void setSize(int row2,int column2);
		bool isSolved();
		int getTotal_move();
		void getArray(int game[9][9]);
		void setArray(int game[9][9]);
		int getRow();
		int getColumn();
		int getEmptyX();
		int getEmptyY();
		void setEmpty_X(int emmpty_x);
		void setEmpty_Y(int emmpty_y);
		void getFinalBoard(int final_board[9][9]);
		void setTotalMove(int t_move);
		int getTotalMove();

		};
private:
	Board game_board;
public:
	void print();
	void printReport();
	void readFromFile();
	void readFromFile2(string dosya_adi);
	void writeToFile();
	void moveRandom(int N);
	void shuffle(int N);
	void reset();
	void setSize();
	void move(char moove);
	void moveIntelligent();
	void solvePuzzle();
	inline bool control(){
		bool control;
		control=game_board.isSolved();
		return control;

		}

	inline int getRow2(){
		return game_board.getRow();
		}
	inline int getColumn2(){
		return game_board.getColumn();
	}
	NPuzzle(string a);
	NPuzzle();
};

#endif
