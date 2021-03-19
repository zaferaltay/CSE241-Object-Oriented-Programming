#include<iostream>
#include<fstream>
#include<string>
#include "functions.h"

using namespace std;

int main(int argc,char* argv[]){
		srand(time(0));

		const int max=9;


if (argc==1)
{
	int game_board[max][max];
	int size;
	auto control=0;
	do{
		cout<<"Please enter the size (3-9)"<<endl;
		cin>>size;
		control=0;
		if (size<3 || size>max)
		{
			control=1;
		}
}while(control);
	
		init_game_board(game_board,size);
		show_board(game_board,size);
		menu(game_board,size);
}
else{ 
 	int r_c[2];
 	int i=0;
 	string s_array[9];
 	string dosya_adi;
 	dosya_adi=argv[1];
 	row_column(r_c,s_array,dosya_adi);
 	int board[9][9],final_board[9][9];
    init_board(board,s_array,r_c[0],r_c[1]);
    init_final_board(board,final_board,r_c[0],r_c[1]);
    show_board2(board,r_c[0],r_c[1]);
    menu2(board,final_board,r_c[0],r_c[1]);

}

}
