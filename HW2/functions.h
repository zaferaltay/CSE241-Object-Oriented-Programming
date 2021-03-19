#include<iostream>
#include<fstream>
#include <string>
using namespace std;

void print_menu();
void init_txt(int game_board[9][9],int row,int column);
void row_column(int array[2],string arrayy[9],string dosya_adi);
void init_board(int board[9][9],string s_array[9],int row,int column);
void init_final_board(int game_board[9][9],int final_board[9][9],int row,int column);
void show_board2(int board[9][9],int row,int column);
void move_right2(int game_board[9][9],int empty_x,int empty_y);
void move_left2(int game_board[9][9],int empty_x,int empty_y);
void move_down2(int game_board[9][9],int empty_x,int empty_y);
void move_up2(int game_board[9][9],int empty_x,int empty_y);
void shuffle(int game_board[9][9],int final_board[9][9],int row,int column);
inline char control_game2(int game_board[9][9],int final_game_board[9][9],int row,int column){
		int count=0;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					if (game_board[i][j]==final_game_board[i][j])
					{
						count++;
					}
				}
			}

			if(count==(row*column)){
				cout<<"the game was end"<<endl;
				return 'Q';
			}
			else{
				return 'a';
			}

	}
void move_right(int game_board[9][9],int size,int empty_x,int empty_y);
void move_left(int game_board[9][9],int size,int empty_x,int empty_y);
void move_down(int game_board[9][9],int size,int empty_x,int empty_y);
void move_up(int game_board[9][9],int size,int empty_x,int empty_y);
void suffle(int game_board[9][9],int size);
void init_game_board(int game[9][9],int size);
void show_board(int board[9][9],int size);
char intelligent(int game_board[9][9],int size,int x,int y,char prev_move);
char control_game(int game_board[9][9],int final_game_board[9][9],int size);
void intelligent2(int board[9][9],int final_board[9][9],int row,int column,int first_step[4],int empty_x,int empty_y);
void menu2(int game_board[9][9],int final_board[9][9],int row,int column);
void menu(int game_board[9][9],int size);

