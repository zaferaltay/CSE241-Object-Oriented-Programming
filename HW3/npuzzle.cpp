#include "npuzzle.h"


void NPuzzle::Board::print(){
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
		
		int counter=1,last_i,last_j;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)							// 1 den başlyayan counter tuttuk ,00 görünce 00 yazdı,bb görünce bb yazdı 
			{
				if (board[i][j]==0)							//normal sayı görünce tuttuğumuz sayıyı yazdı
				{
					final_game_board[i][j]=board[i][j];
				}
				else{
					final_game_board[i][j]=counter;
					counter++;
					last_i=i;
					last_j=j;
				}
			}
		}
		final_game_board[last_i][last_j]=99;
	}				
void NPuzzle::Board::initBoard(string s_array[9]){
				int count_string_column=0;
				decltype(count_string_column) string_row=0,total=0;

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

					board[string_row][(count_string_column/3)]=total;
					count_string_column+=3;
					total=0;
				}
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
void NPuzzle::Board::readFromFile(string arrayy[9]){
			string satir;
			string dosya_adi;
			int i=0;
			int satir_sayisi=0,sutun_sayisi=0;
			cout<<"Please enter the text name"<<endl;
			cin>>dosya_adi;

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
		for (int z = 0; z < row2; z++)
		{
			for (int k = 0; k < column2; k++)
			{
				final_game_board[z][k]=count;
				count++;
			}
		}
		final_game_board[row2-1][column2-1]=99;
		empty_x=row2-1;
		empty_y=column2-1;
		row=row2;
		column=column2;
		for (int l = 0; l < row2; l++)
		{
			for (int m = 0; m < column2; m++)
			{
				board[l][m]=final_game_board[l][m];
			}
		}

		reset();

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

int NPuzzle::Board::getTotal_move(){
			return total_move;
		}		

void NPuzzle::Board::getArray(int game[9][9]){
		
	const int max2=9;

			for (int i = 0; i < max2; i++)
			{
				for (int j = 0; j < max2; j++)
				{
					game[i][j]=board[i][j];
				}
			 }

		}

void NPuzzle::Board::setArray(int game[9][9]){
			const int max=9;
			for (int i = 0; i < max; i++)
			{
				for (int j = 0; j < max; j++)
				{
					board[i][j]=game[i][j];
				}
			 }
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
void NPuzzle::Board::getFinalBoard(int final_board[9][9]){		
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					final_board[i][j]=final_game_board[i][j];
				}
			 }

		}
void NPuzzle::Board::setTotalMove(int t_move){
			total_move=t_move;
		}
int NPuzzle::Board::getTotalMove(){
			return total_move;
		}

void NPuzzle::print(){
		game_board.print();
	}
void NPuzzle::printReport(){
		cout<<"Your total move = "<<game_board.getTotal_move()<<endl;
		if (game_board.isSolved()==true)
		{
			cout<<"The game was end"<<endl;
		}
		else{
			cout<<"The game is not finish yet"<<endl;
		}
	}
void NPuzzle::readFromFile(){
		game_board.readFromFile(arrayy);
		game_board.getArray(game);
		emmpty_x=game_board.getEmptyX();
		emmpty_y=game_board.getEmptyY();		
	}
void NPuzzle::readFromFile2(string dosya_adi){
		game_board.readFromFile2(arrayy,dosya_adi);
		game_board.getArray(game);
		emmpty_x=game_board.getEmptyX();
		emmpty_y=game_board.getEmptyY();
	}
void NPuzzle::writeToFile(){
		game_board.writeToFile();
	}
void NPuzzle::moveRandom(int N){
		int count=0,t_move;
				while(count<N){
						random=rand()%4;
							switch(random){
								case 0:
									if (emmpty_x>0 && game[emmpty_x-1][emmpty_y]!=0)
									{	
										game_board.move('u');
										//emmpty_x-=1;
										count++;

									}
									break;
								case 1:
									if (emmpty_x<row2-1&& game[emmpty_x+1][emmpty_y]!=0)
										{	
											game_board.move('d');
										//	emmpty_x+=1;
											count++;
										}	
									break;
								case 2:
									if (emmpty_y>0 && game[emmpty_x][emmpty_y-1]!=0)
										{	
											game_board.move('l');
										//	emmpty_y-=1;
											count++;
										}		
									break;
								case 3:
									if (emmpty_y<column2-1 && game[emmpty_x][emmpty_y+1]!=0)
										{	
											game_board.move('r');
										//	emmpty_y+=1;
											count++;

										}
									break;							
									}   // switch-case kapanış
									t_move=game_board.getTotalMove();
									t_move++;
									game_board.setTotalMove(t_move);
									game_board.getArray(game);
									emmpty_x=game_board.getEmptyX();
									emmpty_y=game_board.getEmptyY();
								} //while kapanış



	}
void NPuzzle::shuffle(int N){
		game_board.getArray(game);
		row2=game_board.getRow();
		column2=game_board.getColumn();
		emmpty_x=row2-1;
		emmpty_y=column2-1;
		game_board.setEmpty_X(emmpty_x);
		game_board.setEmpty_Y(emmpty_y);
		game_board.getFinalBoard(final_board);

		for (int i = 0; i < row2; i++)
		{
			for (int j = 0; j < column2; j++)
			{
				game[i][j]=final_board[i][j];		
			}
		}
		game_board.setArray(game);

		moveRandom(N);
	}	// shuffle fonksiyonu kapanış
	
void NPuzzle::reset(){
		game_board.reset();
		game_board.getArray(game);
	}
void NPuzzle::setSize(){
		cout<<"Enter the size"<<endl;
		cin>>row2;
		column2=row2;
		game_board.setSize(row2,column2);
		game_board.getArray(game);
	}
void NPuzzle::move(char moove){
		game_board.move(moove);
		game_board.getArray(game);
	}
void NPuzzle::moveIntelligent(){
			int goal_x,goal_y,num,first_step[4];
			auto total_distance=0,min=9999,min_count=0,random_move=0;
			int i,j,k,l,m,n;
			game_board.getArray(game);
			row2=game_board.getRow();			
			column2=game_board.getColumn();			
			emmpty_x=game_board.getEmptyX();			
			emmpty_y=game_board.getEmptyY();
			game_board.getFinalBoard(final_board);

				//--------------------------------------right için bak

				if (game[emmpty_x][emmpty_y+1]==0 || emmpty_y+1>=column2)
				{
					first_step[0]=9999;
				}
				else {
					
				num=game[emmpty_x][emmpty_y+1];

				for (k = 0; k < row2; k++)
				{
					for (l = 0; l < column2; l++)
					{
						if (num==final_board[k][l])
						{
							goal_x=k;
							goal_y=l;
						}
					}
				}

				if (goal_x<emmpty_x)
				{
					total_distance+=(emmpty_x-goal_x);
				}
				else{
					total_distance+=(goal_x-emmpty_x);
				}

				if (goal_y<emmpty_y)
				{
					total_distance+=(emmpty_y-goal_y);
				}
				else{
					total_distance+=(goal_y-emmpty_y);
				}

				first_step[0]=total_distance;
				total_distance=0;
				}
				//--------------------------------------------left için 

				if (game[emmpty_x][emmpty_y-1]==0 || emmpty_y-1<0 ){
					first_step[1]=9999;
				}
				else{


				num=game[emmpty_x][emmpty_y-1];

				for ( k = 0; k < row2; k++)
				{
					for (l = 0; l < column2; l++)
					{
						if (num==final_board[k][l])
						{
							goal_x=k;
							goal_y=l;
						}
					}
				}

				if (goal_x<emmpty_x)
				{
					total_distance+=(emmpty_x-goal_x);
				}
				else{
					total_distance+=(goal_x-emmpty_x);
				}

				if (goal_y<emmpty_y)
				{
					total_distance+=(emmpty_y-goal_y);
				}
				else{
					total_distance+=(goal_y-emmpty_y);
				}

				first_step[1]=total_distance;
				total_distance=0;
				}
				//---------------------------------------------up için
				if (game[emmpty_x-1][emmpty_y]==0 || emmpty_x-1<0 )
				{
					first_step[2]=9999;
				}
				else{

				num=game[emmpty_x-1][emmpty_y];

				for (k = 0; k < row2; k++)
				{
					for (l = 0; l < column2; l++)
					{
						if (num==final_board[k][l])
						{
							goal_x=k;
							goal_y=l;
						}
					}
				}

				if (goal_x<emmpty_x)
				{
					total_distance+=(emmpty_x-goal_x);
				}
				else{
					total_distance+=(goal_x-emmpty_x);
				}

				if (goal_y<emmpty_y)
				{
					total_distance+=(emmpty_y-goal_y);
				}
				else{
					total_distance+=(goal_y-emmpty_y);
				}

				first_step[2]=total_distance;
				total_distance=0;
				}

				//--------------------------------------------down için

				if (game[emmpty_x+1][emmpty_y]==0 || emmpty_x+1>=row2)
				{
					first_step[3]=9999;
				}
				else{

				num=game[emmpty_x+1][emmpty_y];

				for (k = 0; k < row2; k++)
				{
					for (l = 0; l < column2; l++)
					{
						if (num==final_board[k][l])
						{
							goal_x=k;
							goal_y=l;
						}
					}
				}

				if (goal_x<emmpty_x)
				{
					total_distance+=(emmpty_x-goal_x);
				}
				else{
					total_distance+=(goal_x-emmpty_x);
				}

				if (goal_y<emmpty_y)
				{
					total_distance+=(emmpty_y-goal_y);
				}
				else{
					total_distance+=(goal_y-emmpty_y);
				}

				first_step[3]=total_distance;
				total_distance=0;

				}
				min_count=0;
//--------------------------------------------------------------------------------------------
				for ( m = 0; m < 4; m++)
				{
					if (first_step[m]<min)
					{
						min=first_step[m];
					}
				}
				
				for (n = 0; n < 4; n++)
				{
					if (first_step[n]==min)
					{
						min_count=n;
					}
				}
					switch(min_count){
						case 0:
							game_board.move('r');
							break;
						case 1:
							game_board.move('l');
							break;
						case 2:
							game_board.move('u');
							break;
						case 3:
							game_board.move('d');
							break;			

					}
							emmpty_x=game_board.getEmptyX();
							emmpty_y=game_board.getEmptyY();

	}

void NPuzzle::solvePuzzle(){
		game_board.getArray(game);
		bool control;
		int move_i=0,move_r,move;
		const int maxx=500000;


		control=game_board.isSolved();
		while(control!=true && move<maxx){
			while(move_i<25){
				moveIntelligent();
				game_board.getArray(game);
				print();
				cout<<endl;
				move_i++;
				move++;
				control=game_board.isSolved();
				cout<<"Your total move="<<move<<endl;
				if (control==true)
				{
					break;
				}
			}
			move_r=0;
			while(control!=true && move_r<5){
				moveRandom(1);
				game_board.getArray(game);
				print();
				cout<<endl;
				move++;
				move_r++;
				control=game_board.isSolved();
				cout<<"Your total move="<<move<<endl;
				if (control==true)
				{
					break;
				}

			}


		}
		if (control==true)
				{
					cout<<"The game was end"<<endl;
				}

				

}
	NPuzzle::NPuzzle(){
		setSize();
	}

	NPuzzle::NPuzzle(string a){
		readFromFile2(a);
	}
