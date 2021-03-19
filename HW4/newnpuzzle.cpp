#include "npuzzle.h"
																						//	Hocam,
																						//	Command line dan direkt dosya alınca segment alıyorum,düzeltmeyi denesem de pek başarılı olamadım.
void NPuzzle::Board::print(){															//
	for ( int i=0; i <row; i++)
			{
				for ( int j=0; j <column; j++)
				{	if (board[i][j]!=99)
				 {
				 	if (board[i][j]/10!=0)
				 	{
					cout<<" "<<board[i][j];						
				 	
				 	}
				 	else{
				 		cout<<" 0"<<board[i][j];
				 	}
				  }
				  else{
				  	cout<<" bb";
				  }
				}
				cout<<endl;
					
				}
			}

void NPuzzle::Board::init_final_board(){
		
		int counter=1,k=0;
		final_game_board.clear();
		vector<int> v;


		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)							// 1 den başlyayan counter tuttuk ,00 görünce 00 yazdı,bb görünce bb yazdı 
			{
				if (board[i][j]==0)							//normal sayı görünce tuttuğumuz sayıyı yazdı
				{
					v.push_back(0);
				}
				else{
					v.push_back(counter);
					counter++;
				}

			}
			final_game_board.push_back(v);
			v.clear();
		}
		final_game_board[row-1][column-1]=99;
	}	

	void NPuzzle::Board::initBoard(string s_array[9]){
				int count_string_column=0;
				decltype(count_string_column) string_row=0,total=0,k=0;
				board2.clear();
				board.clear();
			

			while(string_row<row){
				while(count_string_column<((column*3)-2)){ 
					if (s_array[string_row][count_string_column]=='0')
					{
						total=s_array[string_row][count_string_column+1]-48;  // ilk karakter 0 ise ikinicye bakıyoruz ascii de bulup totale yazıyoruz
						
					}
					else if (s_array[string_row][count_string_column]=='b')  //ilk karakter b ise boşluk olduğunu anlıyoruz 
					{
						total=99;
					}
					else{
						total=(s_array[string_row][count_string_column]-48)*10;    // ilk karakter sayı ise 10 la çarpıp ikini değeri ekleyip yerine yerleştiriyoruz
						total+=s_array[string_row][count_string_column+1]-48;

					}

					board2.push_back(total);
					k++;
					count_string_column+=3;
					total=0;
				}
				board.push_back(board2);
				board2.clear();
				count_string_column=0;
				string_row++;
			}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (board[i][j]==99)
				{
					empty_x=i;
					empty_y=j;
				}
			}
		}
		init_final_board();
		}
	void NPuzzle::Board::readFromFile(string arrayy[9],string dosya_adi){
			string satir;
			int i=0;
			int satir_sayisi=0,sutun_sayisi=0;
			//cout<<"Please enter the text name"<<endl;
			//cin>>dosya_adi;

			ifstream read_board;

			read_board.open(dosya_adi);
			getline(read_board,satir);
		do{
			arrayy[i]=satir;
			i++;
			sutun_sayisi=0;
			satir_sayisi++;						//boardın kaç satır olduğunu bulduk
		  while(satir[sutun_sayisi]!='\0'){
			sutun_sayisi++;							// boardın kaç sütun olduğunu bulduk sütun+1 /3 yaparak 
				}
		}
		while(getline(read_board,satir));

		row=satir_sayisi;
		sutun_sayisi=(sutun_sayisi+1)/3;
		column=sutun_sayisi;
		read_board.close();
		initBoard(arrayy);
	}	
	void NPuzzle::Board::readFromFile2(string arrayy[9],string dosya_adi){
			string satir;			
			int i=0;
			int satir_sayisi=0,sutun_sayisi=0;
			ifstream read_board;
			read_board.open(dosya_adi);
			getline(read_board,satir);
		do{
			arrayy[i]=satir;
			i++;
			sutun_sayisi=0;
			satir_sayisi++;						//boardın kaç satır olduğunu bulduk
		  while(satir[sutun_sayisi]!='\0'){
			sutun_sayisi++;							// boardın kaç sütun olduğunu bulduk sütun+1 /3 yaparak 
				}
		}
		while(getline(read_board,satir));

		row=satir_sayisi;
		sutun_sayisi=(sutun_sayisi+1)/3;
		column=sutun_sayisi;
		read_board.close();
		initBoard(arrayy);
	}	
	void NPuzzle::Board::writeToFile(){

		string output_txt;
		cout<<"Please enter a file name"<<endl;
		cin>>output_txt;
		ofstream printerr;
		printerr.open(output_txt);
		int k=0;
	for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{	if (board[i][j]>=10 && board[i][j]!=99)
			    {
					printerr<<board[i][j];
			    }
				else if (board[i][j]==99)
			    {
					printerr<<"bb";
				}
				else{
					printerr<<"0";
					printerr<<board[i][j];
				}
			
				if(j<column-1)
					printerr<<" ";
				k++;
			}
			if(i<row-1)
			printerr<<endl;
		}	
	}		
void NPuzzle::Board::move(char movee){

		switch(movee){
			case 'l' :
			case 'L' :
	 			if (empty_y>0 && board[empty_x][empty_y-1]!=0){
	 			board[empty_x][empty_y]=board[empty_x][empty_y-1];
				board[empty_x][empty_y-1]=99;
				empty_y=empty_y-1;
				total_move++;
	 			}

				break;

			case 'r' :
			case 'R' :
				if (empty_y<column-1 &&board[empty_x][empty_y+1]!=0){
		 		board[empty_x][empty_y]=board[empty_x][empty_y+1];
				board[empty_x][empty_y+1]=99;
				empty_y=empty_y+1;	
				total_move++;
				}
				break;

			case 'u':
			case 'U':
				if (empty_x>0 &&board[empty_x-1][empty_y]!=0){
				board[empty_x][empty_y]=board[empty_x-1][empty_y];
				board[empty_x-1][empty_y]=99;
				empty_x=empty_x-1;
				total_move++;
				}
				break;

			case 'd':
			case 'D':
				if (empty_x<row-1&& board[empty_x+1][empty_y]!=0){
				board[empty_x][empty_y]=board[empty_x+1][empty_y];
				board[empty_x+1][empty_y]=99;
				empty_x=empty_x+1;
				total_move++;
				}
				break;
		} //switxh case kapama parantezi
	}		
void NPuzzle::Board::reset(){
		int count=0;
		total_move=0;
					while(count<(row*column)){
						random=rand()%4;
							switch(random){
								case 0:
									if (empty_x>0 &&board[empty_x-1][empty_y]!=00)
									{
										move('u');
										count++;	
									}
									break;
								case 1:
									if (empty_x<row-1&& board[empty_x+1][empty_y]!=00)
										{
											move('d');
											count++;
										}	
									break;
								case 2:
									if (empty_y>0 && board[empty_x][empty_y-1]!=00)
										{
											move('l');
											count++;
										}		
									break;
								case 3:
									if (empty_y<column-1 &&board[empty_x][empty_y+1]!=00)
										{
											move('r');
											count++;
										}
									break;							
									}   // switch-case kapanış
								} //while kapanış
	}	

void NPuzzle::Board::setSize(int row2,int column2){
		board2.clear();
		int k=1;
		for (int z = 0; z < row2; z++)
		{	
			for (int i = 0; i < column2; ++i)
			{
				board2.push_back(k);
				k++;
			}
				final_game_board.push_back(board2);
				board.push_back(board2);
				board2.clear();
		}
		final_game_board[row2-1][column2-1]=99;
		empty_x=row2-1;
		empty_y=column2-1;
		row=row2;
		column=column2;
		reset();
	}

void NPuzzle::Board::setArray(vector<vector<int>> game2,int row2,int column2){

			board.clear();
			board2.clear();
			row=row2;
			column=column2;
			for (int i = 0; i < row2; i++)
			{
				for (int k = 0; k < column2; k++)
				{		
					
					board2.push_back(game2[i][k]);
				}
				board.push_back(board2);
				board2.clear();
			}
		}		
vector<vector<int>> NPuzzle::Board::getArray(){
		return board;

		}
int NPuzzle::Board::getRow(){
			return row;
		}	
int NPuzzle::Board::getColumn(){
			return column;
		}
int NPuzzle::Board::getEmptyX(){
			return empty_x;
		}
int NPuzzle::Board::getEmptyY(){
			return empty_y;
		}
void NPuzzle::Board::setEmpty_X(int emmpty_x){
			empty_x=emmpty_x;
		}
void NPuzzle::Board::setEmpty_Y(int emmpty_y){
			empty_y=emmpty_y;
		}
vector<vector<int>> NPuzzle::Board::getFinalBoard(){	
		return final_game_board;
		}	
int NPuzzle::Board::getTotalMove(){
			return total_move;
		}	
void NPuzzle::Board::setTotalMove(int t_move){
			total_move=t_move;
		}
void NPuzzle::Board::setRow(int a){
			row=a;
		}
void NPuzzle::Board::setColumn(int a){
			column=a;
		}				
vector<vector<int>> NPuzzle::Board::getBoard3(){
		return board3;
		}	
void NPuzzle::Board::setBoard3(vector<vector<int>> game3,int row2,int column2){
	board2.clear();
	board3.clear();
			for (int i = 0; i < row2; i++)
			{
			for (int k = 0; k < column2; k++)
			{		
					
					board2.push_back(game3[i][k]);
			}
			board3.push_back(board2);
			board2.clear();
			}

}		
void NPuzzle::Board::setLastMove(char x){
	lastmove=x;
}	
void NPuzzle::Board::setNumberOfMoves(int a){
	numberOfMoves=a;
}
int NPuzzle::Board::getNumberOfMoves(){
	return numberOfMoves;
}	
char NPuzzle::Board::getLastMove(){
	return lastmove;
}
bool NPuzzle::Board::isSolved(){
		int count=0;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					if (board[i][j]==final_game_board[i][j])
					{
						count++;
					}
				
				}
			}
			if(count==(row*column)){
				return true;
			}
			else{
				return false;
			}
	}
//-------------------------------------------------------------------------NPUZZLE FONKSİYONLAR--------------------------------------------------------------------

void NPuzzle::print(){
		game_vector[0].print();
	}
	void NPuzzle::printReport(){
		cout<<"Your total move = "<<game_vector[0].getTotalMove()<<endl;
		if (game_vector[0].isSolved()==true)
		{
			cout<<"The game was end"<<endl;
		}
		else{
			cout<<"The game is not finish yet"<<endl;
		}
	}
void NPuzzle::move(char a){
	game_vector.resize(1);
	game_vector[0].move(a);
}	
void NPuzzle::writeToFile(){
		game_vector[0].writeToFile();
	}
void NPuzzle::readFromFile(string dosya_adi){
		game_vector[0].readFromFile(arrayy,dosya_adi);
		game2.clear();
		game2=game_vector[0].getArray();
		emmpty_x=game_vector[0].getEmptyX();
		emmpty_y=game_vector[0].getEmptyY();		
	}	
void NPuzzle::readFromFile2(string dosya_adi){
		game_vector[0].readFromFile2(arrayy,dosya_adi);
		game2.clear();
		game2=game_vector[0].getArray();
		emmpty_x=game_vector[0].getEmptyX();
		emmpty_y=game_vector[0].getEmptyY();	
	}
void NPuzzle::reset(){
	game_vector.resize(0);
}	
void NPuzzle::moveRandom(int N){
	game_vector.resize(1);
	row2=game_vector[0].getRow();
	column2=game_vector[0].getColumn();
	game_vector[0].setEmpty_X(emmpty_x);
	game_vector[0].setEmpty_Y(emmpty_y);
		int count=0,t_move;
				while(count<N){
						random=rand()%4;
							switch(random){
								case 0:
									if (emmpty_x>0 && game2[emmpty_x-1][emmpty_y]!=0)
									{	
										game_vector[0].move('u');
										//emmpty_x-=1;
										count++;

									}
									break;
								case 1:
									if (emmpty_x<row2-1&& game2[emmpty_x+1][emmpty_y]!=0)
										{	
											game_vector[0].move('d');
										//	emmpty_x+=1;
											count++;
										}	
									break;
								case 2:
									if (emmpty_y>0 && game2[emmpty_x][emmpty_y-1]!=0)
										{	
											game_vector[0].move('l');
										//	emmpty_y-=1;
											count++;
										}		
									break;
								case 3:
									if (emmpty_y<column2-1 && game2[emmpty_x][emmpty_y+1]!=0)
										{	
											game_vector[0].move('r');
										//	emmpty_y+=1;
											count++;

										}
									break;							
									}   // switch-case kapanış
									t_move=game_vector[0].getTotalMove();
									t_move++;
									game_vector[0].setTotalMove(t_move);
									game2.clear();
									game2=game_vector[0].getArray();
									emmpty_x=game_vector[0].getEmptyX();
									emmpty_y=game_vector[0].getEmptyY();
								} //while kapanış
	}	
void NPuzzle::shuffle(int N){
		game_vector.resize(1);
		game2=game_vector[0].getArray();
		row2=game_vector[0].getRow();
		column2=game_vector[0].getColumn();
		emmpty_x=game_vector[0].getEmptyX();
		emmpty_y=game_vector[0].getEmptyY();
		game_vector[0].setEmpty_X(emmpty_x);
		game_vector[0].setEmpty_Y(emmpty_y);
		final_board.clear();
		final_board=game_vector[0].getFinalBoard();
		game2.clear();
		game2=game_vector[0].getFinalBoard();
		moveRandom(N);
	}
void NPuzzle::setSize(){
		int a,b;
		cout<<"Enter the size"<<endl;
		cin>>row2;
		column2=row2;
		game_board.setSize(row2,column2);
		game_vector.push_back(game_board);

	}
	bool operator == (vector<vector<int>> board2,vector<vector<int>> board){										
		int count=0;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if(board2[i][j]==board[i][j]){
					count++;
				}
			}
		}
		if (count==(board.size()*board[0].size()))
				{
					return true;
				}
		
		return false;

	}
	int NPuzzle::Board::operator () (int a,int b){		// =,() gibi (nonstatic işaretlerde)friend kullanılmaz.Scopeler kullanılır
		return board[a][b];
	}	

ostream& operator<<(ostream& out , NPuzzle &obj1){
		obj1.game2=obj1.game_vector[0].getArray();
		obj1.row2=obj1.game_vector[0].getRow();
		obj1.column2=obj1.game_vector[0].getColumn();
	for ( int i=0; i <obj1.row2; i++)
			{
				for ( int j=0; j <obj1.column2; j++)
				{	if (obj1.game2[i][j]!=99)
				 {
				 	if (obj1.game2[i][j]/10!=0)
				 	{
					out<<" "<<obj1.game2[i][j];						
				 	
				 	}
				 	else{
				 		out<<" 0"<<obj1.game2[i][j];
				 	}
				  }
				  else{
				  	out<<" bb";
				  }
				}
				out<<endl;
					
				}
				return out;
	}
	istream& operator>>(istream& in ,NPuzzle &obj1){		// friend kullandığımız için scopeye gerek yok
		string a;
		cout<<"enter the txt  name"<<endl;
		in>>a;
		obj1.readFromFile2(a);


		return in;

	}
	void NPuzzle::solvePuzzle(){
		vector<vector<int>> temp_board_vector;
		vector<vector<int>> final_vector;
		vector<char> temp_move_vector;
		vector<int> moves_num;
		int equal_all_option=0,numofmvs=0,control_counter=0,board_now=0,total_vector=1,flag,temp_empty_x=0,total_move=0,temp_empty_y=0,counter=0,i=0;
		char move;
		game_vector[0].setNumberOfMoves(numofmvs);
		game_vector[0].setLastMove('s');
		final_vector=game_vector[0].getFinalBoard();

		numofmvs++;

int fflag=0;
			while(equal_all_option<4){
					if (fflag==1)
				{
					break;
				}
					equal_all_option=0;
					temp_empty_x=game_vector[board_now].getEmptyX();
					temp_empty_y=game_vector[board_now].getEmptyY();
					temp_board_vector=game_vector[board_now].getArray();
				if (temp_empty_y<column2-1 &&temp_board_vector[temp_empty_x][temp_empty_y+1]!=00)
				{
				//------------önce sağa doğru kaydetme-----------------------------
					game_vector[board_now].move('r');
					temp_board_vector=game_vector[board_now].getArray();
					temp_empty_x=game_vector[board_now].getEmptyX();
					temp_empty_y=game_vector[board_now].getEmptyY();
					game_vector[board_now].move('l');
					while(control_counter<total_vector){
						if (game_vector[control_counter].getArray()==temp_board_vector)
						{
							control_counter=0;
							flag=1;
							break;
						}
						control_counter++;
						flag=0;   //vektörleri karşılaştırdık
					}control_counter=0;
					if (flag==0)
					{
						game_board.setArray(temp_board_vector,row2,column2);
						game_board.setEmpty_X(temp_empty_x);
						game_board.setEmpty_Y(temp_empty_y);
						game_board.setNumberOfMoves(numofmvs);
						game_board.setLastMove('r');
						game_board.setRow(row2);
						game_board.setColumn(column2);
						game_vector.push_back(game_board);
						total_vector++;
					}
					else{
						equal_all_option++;
					}
					if (game_vector[total_vector-1].getArray()==final_vector)
					{
						break;
						fflag=1;
					}
					cout<<endl;
				
				}
				//------------sağa doğru kaydetme bitiş----------------------------				
				//------------sola doğru kaydetme başlangıç------------------------
				if (fflag==1)
				{
					break;
				}
					temp_empty_x=game_vector[board_now].getEmptyX();
					temp_empty_y=game_vector[board_now].getEmptyY();
					temp_board_vector=game_vector[board_now].getArray();
				if (temp_empty_y>0 && temp_board_vector[temp_empty_x][temp_empty_y-1]!=0)
				{
					game_vector[board_now].move('l');
					temp_board_vector.clear();
					temp_board_vector=game_vector[board_now].getArray();
					temp_empty_x=game_vector[board_now].getEmptyX();
					temp_empty_y=game_vector[board_now].getEmptyY();
					game_vector[board_now].move('r');
					while(control_counter<total_vector){
						if (game_vector[control_counter].getArray()==temp_board_vector)
						{
							control_counter=0;
							flag=1;
							break;
						}
						control_counter++;
						flag=0;   //vektörleri karşılaştırdık
					}control_counter=0;
					if (flag==0)
					{
						//cout<<"girdi"<<endl;
						game_board.setArray(temp_board_vector,row2,column2);//cout<<"girdi"<<endl;
						game_board.setEmpty_X(temp_empty_x);//cout<<"girdi"<<endl;
						game_board.setEmpty_Y(temp_empty_y);//cout<<"girdi"<<endl;
						game_board.setNumberOfMoves(numofmvs);//cout<<"girdi"<<endl;
						game_board.setLastMove('l');//cout<<"girdi"<<endl;
						game_board.setRow(row2);//cout<<"girdi"<<endl;
						game_board.setColumn(column2);//cout<<"girdi"<<endl;
						//game_board.print();
						game_vector.push_back(game_board);
						total_vector++;
					}
					else{
						equal_all_option++;
					}
					if (game_vector[total_vector-1].getArray()==final_vector)
					{
						break;
						fflag=1;
					}										
				}				

//---------------sola doğru kaydetme bitiş------------------------------------			
//---------------aşağı doğru kaydetme balangıç--------------------------------
					if (fflag==1)
				{
					break;
				}
					temp_empty_x=game_vector[board_now].getEmptyX();
					temp_empty_y=game_vector[board_now].getEmptyY();
					temp_board_vector=game_vector[board_now].getArray();
				if (temp_empty_x<row2-1&& temp_board_vector[temp_empty_x+1][temp_empty_y]!=0)
					{
					game_vector[board_now].move('d');
					temp_board_vector.clear();
					temp_board_vector=game_vector[board_now].getArray();
					temp_empty_x=game_vector[board_now].getEmptyX();
					temp_empty_y=game_vector[board_now].getEmptyY();
					game_vector[board_now].move('u');

					while(control_counter<total_vector){
						if (game_vector[control_counter].getArray()==temp_board_vector)
						{
							control_counter=0;
							flag=1;
							break;
						}
						control_counter++;
						flag=0;   //vektörleri karşılaştırdık
					}control_counter=0;

					if (flag==0)
					{
						game_board.setArray(temp_board_vector,row2,column2);
						game_board.setEmpty_X(temp_empty_x);//cout<<"girdi"<<endl;
						game_board.setEmpty_Y(temp_empty_y);//cout<<"girdi"<<endl;
						game_board.setNumberOfMoves(numofmvs);//cout<<"girdi"<<endl;
						game_board.setLastMove('d');//cout<<"girdi"<<endl;
						game_board.setRow(row2);//cout<<"girdi"<<endl;
						game_board.setColumn(column2);//cout<<"girdi"<<endl;
						cout<<endl;
						game_vector.push_back(game_board);
						total_vector++;						
					}
					else{
						equal_all_option++;
					}
					if (game_vector[total_vector-1].getArray()==final_vector)
					{
						break;
						fflag=1;
					}

					}
//---------------aşağı doğru kaydetme bitiş-----------------------------------	
//---------------yukarı doğru kaydetme başlangıç---------------------------------
						if (fflag==1)
				{
					break;
				}
					temp_empty_x=game_vector[board_now].getEmptyX();
					temp_empty_y=game_vector[board_now].getEmptyY();
					temp_board_vector=game_vector[board_now].getArray();
				if (temp_empty_x>0 && temp_board_vector[temp_empty_x-1][temp_empty_y]!=0)
					{
					game_vector[board_now].move('u');
					temp_board_vector.clear();
					temp_board_vector=game_vector[board_now].getArray();
					temp_empty_x=game_vector[board_now].getEmptyX();
					temp_empty_y=game_vector[board_now].getEmptyY();
					game_vector[board_now].move('d');
					while(control_counter<total_vector){
						if (game_vector[total_vector-1].getArray()==final_vector)
						{
							control_counter=0;
							flag=1;
							break;
						}
						control_counter++;
						flag=0;   //vektörleri karşılaştırdık
					}control_counter=0;
					if (flag==0)
					{
						//cout<<"girdi"<<endl;
						game_board.setArray(temp_board_vector,row2,column2);//cout<<"girdi"<<endl;

						game_board.setEmpty_X(temp_empty_x);//cout<<"girdi"<<endl;
						game_board.setEmpty_Y(temp_empty_y);//cout<<"girdi"<<endl;
						game_board.setNumberOfMoves(numofmvs);//cout<<"girdi"<<endl;
						game_board.setLastMove('u');//cout<<"girdi"<<endl;
						game_board.setRow(row2);//cout<<"girdi"<<endl;
						game_board.setColumn(column2);//cout<<"girdi"<<endl;
					//	game_board.print();
						game_vector.push_back(game_board);
						total_vector++;
					}
					else{
						equal_all_option++;
					}
					if (game_vector[total_vector-1].getArray()==final_vector)
					{
						break;
					}					
					}	

//--------------------yukarı bitiş--------------------------------------						
					numofmvs++;
					board_now++;
					i++;


			//while bitiş
			}
control_counter=0;
			while(control_counter<total_vector){
				game_vector[control_counter].print();
				//cout<<endl;
				cout<<"last move="<<game_vector[control_counter].getLastMove()<<endl;
				control_counter++;
			}

		//-------------------------Kaydetme bölümleri bitiş-----------------------
			control_counter=0;
	
			while(control_counter<total_vector){
				temp_move_vector.push_back(game_vector[control_counter].getLastMove());
		
				control_counter++;
			}
			control_counter=0;
			total_vector--;


			counter=0;
			while(total_vector>0 && total_move<1000){
				move=temp_move_vector[total_vector];
		
				i=0;
				if (move=='r')
				{
					game_vector[total_vector].move('l');
					temp_board_vector=game_vector[total_vector].getArray();
					game_vector[total_vector].move('r');
					while(i<total_vector){
							if (temp_board_vector==game_vector[i].getArray())
							{
								break;
							}
							else{
								i++;
							}
					}
					game_vector[i].print();
					cout<<endl;
					moves_num.push_back(i);
					total_vector=i;
					counter++;
				}
				else if(move=='l'){
					game_vector[total_vector].move('r');
					temp_board_vector=game_vector[total_vector].getArray();
					game_vector[total_vector].move('l');
					while(i<total_vector){
							if (temp_board_vector==game_vector[i].getArray())
							{
								break;
							}
							else{
								i++;
							}
					}
					game_vector[i].print();
					cout<<endl;
		
					moves_num.push_back(i);
					counter++;
					total_vector=i;

				}
				else if (move=='u')
				{	cout<<"u"<<endl;
					game_vector[total_vector].move('d');
					temp_board_vector=game_vector[total_vector].getArray();
					game_vector[total_vector].move('u');
					while(i<total_vector){
							if (temp_board_vector==game_vector[i].getArray())
							{
								break;
							}
							else{
								i++;
							}
					game_vector[i].print();
					cout<<endl;
				
					moves_num.push_back(i);
					counter++;
					total_vector=i;
					}					
				}
				else if (move=='d')
				{	
					game_vector[total_vector].move('u');
					temp_board_vector=game_vector[total_vector].getArray();
					game_vector[total_vector].move('d');
					while(i<total_vector){
							if (temp_board_vector==game_vector[i].getArray())
							{
								break;
							}
							else{
								i++;
							}
						game_vector[i].print();
						cout<<endl;
				
					moves_num.push_back(i);
					counter++;
					total_vector=i;
					}										
				}
				else if(move=='s'){
					
					game_vector[0].print();
				}

				total_move++;
									total_move=game_vector[0].getTotalMove();
									
									game_vector[0].setTotalMove(total_move);
			}			
	}


//----------------------------CONSTRUCTOR-------------------------------------------
	NPuzzle::NPuzzle(){
		setSize();
	}
	NPuzzle::NPuzzle(string a){
		readFromFile2(a);
	}

//----------------------------------------------------------------------------------S