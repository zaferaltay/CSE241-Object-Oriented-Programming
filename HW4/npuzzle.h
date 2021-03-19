#ifndef NPUZZLE_H_
#define NPUZZLE_H_
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class NPuzzle{
	const int max=9;
	string arrayy[9],a,b;
	vector<vector<int>> game2;
	vector<vector<int>> final_board;
	int row2=0,column2=0,count=0,random,emmpty_x,emmpty_y;
	private:
	class Board
	{
	private:
		vector<vector<int>> board;
		vector<int> board2;
		vector<vector<int>> board3;
		vector<vector<int>> final_game_board;
		int row,column,empty_x,empty_y,random;
		char lastmove;
		int total_move=0,count=1,numberOfMoves;
		string dosya_adi;
		public:
		void print();
		void init_final_board();
		void initBoard(string s_array[9]);
		void readFromFile(string arrayy[9],string dosya_adi);
		void readFromFile2(string arrayy[9],string dosya_adi);
		void writeToFile();
		void move(char movee);
		void reset();
		void setSize(int row2,int column2);
		bool isSolved();
		void setLastMove(char x);
		char getLastMove();
		int getTotalMove();
		vector<vector<int>> getArray();
		vector<int> getBoard2();
		void setArray(vector<vector<int>> game2,int row2,int column2);
		void setBoard3(vector<vector<int>> game3,int row2,int column2);
		int getRow();
		void setRow(int a);
		void setColumn(int a);
		int getColumn();
		int getEmptyX();
		int getEmptyY();
		void setEmpty_X(int emmpty_x);
		void setEmpty_Y(int emmpty_y);
		vector<vector<int>> getFinalBoard();
		void setTotalMove(int t_move);
		vector<vector<int>> getBoard3();
		void setNumberOfMoves(int a);
		int getNumberOfMoves();
		friend bool operator ==(vector<vector<int>> board2,vector<vector<int>> board);
		int operator ()(int a,int b);
		};
private:
	Board game_board;
	Board newBoard;
	vector<Board> game_vector;
public:
	void print();
	void printReport();
	void readFromFile(string dosya_adi);
	void readFromFile2(string dosya_adi);
	void writeToFile();
	void moveRandom(int N);
	void shuffle(int N);
	void reset();
	void setSize();
	void move(char moove);
	void deneme();
	void moveIntelligent();
        friend ostream& operator<<(ostream& out ,NPuzzle &obj1);
	friend istream& operator>>(istream& in ,NPuzzle &obj1);
	void solvePuzzle();
	inline bool control(){
		bool control;
		control=game_vector[0].isSolved();
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
