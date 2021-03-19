#include "functions.h"


void print_menu(){
	cout<<"L-) moves the empty cell left if there is room"<<endl;
	cout<<"R-) moves the empty cell right if there is room"<<endl;
	cout<<"U-) moves the empty cell up if there is room"<<endl;
	cout<<"D-) moves the empty cell down if there is room"<<endl;
	cout<<"I-) makes an intelligent move for you"<<endl;
	cout<<"S-) shuffle the board"<<endl;
	cout<<"V-) Solves the problem"<<endl;
	cout<<"T-) Prints a report"<<endl;
	cout<<"E-) Saves the board"<<endl;
	cout<<"Y-) Load the board"<<endl;
	cout<<"Q-) Quit game"<<endl;
}

void init_txt(int game_board[9][9],int row,int column){

	string output_txt;
	cout<<"Please enter a file name"<<endl;
	cin>>output_txt;
	ofstream printerr;
	printerr.open(output_txt);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{	if (game_board[i][j]>=10 && game_board[i][j]!=99)
		{
			
			printerr<<game_board[i][j];
		}
		else if (game_board[i][j]==99)
		{
			printerr<<"bb";
		}
		else{
			printerr<<"0";
			printerr<<game_board[i][j];
		}
			
			if(j<column-1)
				printerr<<" ";

		}
		if(i<row-1)
		printerr<<endl;
	}
}

void row_column(int array[2],string arrayy[9],string dosya_adi){
	//string dosya_adi;
	string satir;
	int i=0;
	//cin>>dosya_adi;
	int satir_sayisi=0,sutun_sayisi=0;

	ifstream read_board;

	read_board.open(dosya_adi);
	getline(read_board,satir);
	do{
		arrayy[i]=satir;
		i++;
		sutun_sayisi=0;
		//cout<<satir<<endl;
		satir_sayisi++;						//boardın kaç satır olduğunu bulduk
		while(satir[sutun_sayisi]!='\0'){
		sutun_sayisi++;							// boardın kaç sütun olduğunu bulduk sütun+1 /3 yaparak 
	}
	}
	while(getline(read_board,satir));

	array[0]=satir_sayisi;
	sutun_sayisi=(sutun_sayisi+1)/3;
	array[1]=sutun_sayisi;sutun_sayisi=(sutun_sayisi+1)/3;
	read_board.close();
}
																					//			yerleştirme			board[string_row][(count_string_column/3)]=total;
void init_board(int board[9][9],string s_array[9],int row,int column){
	int count_string_column=0,string_row=0,total=0;

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

}
	void init_final_board(int game_board[9][9],int final_board[9][9],int row,int column){
		
		int counter=1,last_i,last_j;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)							// 1 den başlyayan counter tuttuk ,00 görünce 00 yazdı,bb görünce bb yazdı 
			{
				if (game_board[i][j]==0)							//normal sayı görünce tuttuğumuz sayıyı yazdı
				{
					final_board[i][j]=game_board[i][j];
				}
				else{
					final_board[i][j]=counter;
					counter++;
					last_i=i;
					last_j=j;
				}
			}
		}
		final_board[last_i][last_j]=99;
	}
void show_board2(int board[9][9],int row,int column){
		
			for (int i = 0; i < row; i++)  /// sayuları board a yerleştirdk çift haneli ve tek haneli olanları boşluklarını ayarladık
			{
				for (int j = 0; j < column; j++)
				{	if (board[i][j]!=0)
				 {	
				 	if (board[i][j]==99)
				 	{
				 		cout<<" bb";
				 	}

				 	else if (board[i][j]/10!=0)
				 	{
					cout<<" "<<board[i][j];
				 	
				 	}
				 	else{
				 		cout<<" "<<"0"<<board[i][j];
				 	}
				  }
				  else{
				  	cout<<" 00";
				  }
				}
				cout<<endl;
			}
	}
	 void move_right2(int game_board[9][9],int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x][empty_y+1];
		game_board[empty_x][empty_y+1]=99;

	 }
	 void move_left2(int game_board[9][9],int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x][empty_y-1];
		game_board[empty_x][empty_y-1]=99;
	 }
	 void move_down2(int game_board[9][9],int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x+1][empty_y];
		game_board[empty_x+1][empty_y]=99;

	 }
	 void move_up2(int game_board[9][9],int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x-1][empty_y];
		game_board[empty_x-1][empty_y]=99;
	 }



	 void shuffle(int game_board[9][9],int final_board[9][9],int row,int column){
		int num=1,random,x,y,count=0,temp;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (final_board[i][j]==99)
								{
									x=i;
									y=j;
								}	
								game_board[i][j]=final_board[i][j];			
			}
		}



		while(count<(row*column)){

			random=rand()%4;
				switch(random){
					case 0:
						if (x>0 && game_board[x-1][y]!=00)
						{
							move_up2(game_board,x,y);
							x-=1;
							count++;
							
						}
						break;
					case 1:
						if (x<row-1&& game_board[x+1][y]!=00)
							{
								move_down2(game_board,x,y);
								x+=1;
								count++;
							
							}	
						break;
					case 2:
						if (y>0 && game_board[x][y-1]!=00)
								{
									move_left2(game_board,x,y);
									y-=1;
									count++;
								
								}		
						break;
					case 3:
						if (y<column-1 && game_board[x][y+1]!=00)
									{
										move_right2(game_board,x,y);
										y+=1;
										count++;
									
									}
						break;							
						}
		}

	}



//------------------------------------------------------------1.ödevv---------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------
	 void move_right(int game_board[9][9],int size,int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x][empty_y+1];
		game_board[empty_x][empty_y+1]=99;

	 }
	 void move_left(int game_board[9][9],int size,int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x][empty_y-1];
		game_board[empty_x][empty_y-1]=99;
	 }
	 void move_down(int game_board[9][9],int size,int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x+1][empty_y];
		game_board[empty_x+1][empty_y]=99;

	 }
	 void move_up(int game_board[9][9],int size,int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x-1][empty_y];
		game_board[empty_x-1][empty_y]=99;
	 }
void suffle(int game_board[9][9],int size){
		auto num=1,random=0,count=0,x=size-1,y=size-1,prev_move=0;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				game_board[i][j]=num;
				num++;
			}
		}
		game_board[size-1][size-1]=99;


		while(count<(size*size)){

			random=rand()%4;
				switch(random){
					case 0:
						if (x>0 && prev_move!=1)
						{
							move_up(game_board,size,x,y);
							x-=1;
							count++;
							prev_move=0;
						}
						break;
					case 1:
						if (x<size-1 && prev_move!=0)
							{
								move_down(game_board,size,x,y);
								x+=1;
								count++;
								prev_move=1;
							}	
						break;
					case 2:
						if (y>0 && prev_move!=3)
								{
									move_left(game_board,size,x,y);
									y-=1;
									count++;
									prev_move=2;
								}		
						break;
					case 3:
						if (y<size-1 && prev_move!= 2)
									{
										move_right(game_board,size,x,y);
										y+=1;
										count++;
										prev_move=3;
									}
						break;							
						}
		}
	}	

void init_game_board(int game[9][9],int size){
		suffle(game,size);
}

	void show_board(int board[9][9],int size){
		
			for (int i = 0; i < size; i++)  /// sayuları board a yerleştirdk çift haneli ve tek haneli olanları boşluklarını ayarladık
			{
				for (int j = 0; j < size; j++)
				{	if (board[i][j]!=99)
				 {
				 	if (board[i][j]/10!=0)
				 	{
					cout<<" "<<board[i][j];
				 	
				 	}
				 	else{
				 		cout<<"  "<<board[i][j];
				 	}
				  }
				  else{
				  	cout<<" bb";
				  }
				}
				cout<<endl;
			}
	}


	 char intelligent(int game_board[9][9],int size,int x,int y,char prev_move){

		int l_remaining=100,r_remaining=100,u_remaining=100,d_remaining=100;
		int rem_x,rem_y,cont_x,cont_y,temp,goal_x,goal_y;
		char move;

		if (y<size-1)// sağı kontrol
		{
			temp=game_board[x][y+1];
			cont_x=x;
			cont_y=y;								// manhitten uzaklığını bulduk
			temp-=1;
			goal_x=temp/size;
			goal_y=temp%size;

			if (goal_x<cont_x)						//karşılaştırma yaptık
			{
				rem_x=cont_x-goal_x;
			}
			else{
				rem_x=goal_x-cont_x;
			}

			if (goal_y<cont_y)
			{
				rem_y=cont_y-goal_y;
			}
			else{
				rem_y=goal_y-cont_y;
			}

			r_remaining=rem_x+rem_y;
		}

		if(y>0){ //sol kontrol
				temp=game_board[x][y-1];
				cont_x=x;
				cont_y=y;
				temp-=1;
				goal_x=temp/size;
				goal_y=temp%size;

			if (goal_x<cont_x)
			{
				rem_x=cont_x-goal_x;
			}
			else{
				rem_x=goal_x-cont_x;
			}

			if (goal_y<cont_y)
			{
				rem_y=cont_y-goal_y;
			}
			else{
				rem_y=goal_y-cont_y;
			}

			l_remaining=rem_x+rem_y;
		}

		if (x>0) //yukarı kontrol
		{
			temp=game_board[x-1][y];
			temp-=1;
			cont_x=x;
			cont_y=y;
			goal_x=temp/size;
			goal_y=temp%size;

			if (goal_x<cont_x)
			{
				rem_x=cont_x-goal_x;
			}
			else{
				rem_x=goal_x-cont_x;
			}

			if (goal_y<cont_y)
			{
				rem_y=cont_y-goal_y;
			}
			else{
				rem_y=goal_y-cont_y;
			}

			u_remaining=rem_x+rem_y;


		}
		if(x<size-1){ // aşağı kontrol
			temp=game_board[x+1][y];
			temp-=1;
			cont_x=x;
			cont_y=y;
			goal_x=temp/size;
			goal_y=temp%size;

			if (goal_x<cont_x)
			{
				rem_x=cont_x-goal_x;
			}
			else{
				rem_x=goal_x-cont_x;
			}

			if (goal_y<cont_y)
			{
				rem_y=cont_y-goal_y;
			}
			else{
				rem_y=goal_y-cont_y;
			}

			d_remaining=rem_x+rem_y;
		}

			if (r_remaining<=l_remaining) /// move kontrol
			{
				if (u_remaining<d_remaining)
				{
					if (r_remaining<u_remaining)
					{
						if(prev_move=='l'){
							move='u';
						}
						else{
							move='r';
						}
					}
					else{
							if(prev_move=='d'){
									move='r';
							}
							else{

							move='u';
							}
					}
				}
				else{
						if (r_remaining<d_remaining)
					{
						if(prev_move=='l'){
									move='d';
							}
							else{

							move='r';
							}
					}
						

					else{
						if(prev_move=='u'){
									move='d';
							}
							else{

							move='r';
							}
					}			
					}
				}
			else{
				if (u_remaining<d_remaining)
				{
					if (l_remaining<u_remaining)
					{	
						if(prev_move=='r'){
									move='u';
							}
							else{

							move='l';
							}
					}			
						
					
					else{
						if(prev_move=='d'){
									move='l';
							}
							else{

							move='u';
							}
				
					}
				}
				else{
						if (l_remaining<d_remaining)
					{
						move='l';
						if(prev_move=='r'){
									move='d';
							}
							else{

							move='l';
							}
								
					}
					else{
							if(prev_move=='u'){
									move='l';
							}
							else{

							move='d';
							}

			
					}
				}
			
			}
			cout<<endl;
			cout<<"Your intelligent move "<<move<<endl;
		return move;
	}


	char control_game(int game_board[9][9],int final_game_board[9][9],int size){
		auto count=0;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (game_board[i][j]==final_game_board[i][j])
					{
						count++;
					}
				}
			}

			if(count==(size*size)){
				cout<<"the game was end"<<endl;
				return 'Q';
			}
			else{
				return 'a';
			}

	}
	void intelligent2(int board[9][9],int final_board[9][9],int row,int column,int first_step[4],int empty_x,int empty_y){


			int goal_x,goal_y,num;
			auto total_distance=0,min=9999,min_count=0,random_move=0;
			int i,j,k,l,m,n;

				//--------------------------------------right için bak

				if (board[empty_x][empty_y+1]==0 || empty_y+1>=column)
				{
					first_step[0]=9999;
				}
				else {
					
				num=board[empty_x][empty_y+1];

				for (k = 0; k < row; k++)
				{
					for (l = 0; l < column; l++)
					{
						if (num==final_board[k][l])
						{
							goal_x=k;
							goal_y=l;
						}
					}
				}

				if (goal_x<empty_x)
				{
					total_distance+=(empty_x-goal_x);
				}
				else{
					total_distance+=(goal_x-empty_x);
				}

				if (goal_y<empty_y)
				{
					total_distance+=(empty_y-goal_y);
				}
				else{
					total_distance+=(goal_y-empty_y);
				}

				first_step[0]=total_distance;
				total_distance=0;
				}
				//--------------------------------------------left için 

				if (board[empty_x][empty_y-1]==0 || empty_y-1<0 ){
					first_step[1]=9999;
				}
				else{


				num=board[empty_x][empty_y-1];

				for ( k = 0; k < row; k++)
				{
					for (l = 0; l < column; l++)
					{
						if (num==final_board[k][l])
						{
							goal_x=k;
							goal_y=l;
						}
					}
				}

				if (goal_x<empty_x)
				{
					total_distance+=(empty_x-goal_x);
				}
				else{
					total_distance+=(goal_x-empty_x);
				}

				if (goal_y<empty_y)
				{
					total_distance+=(empty_y-goal_y);
				}
				else{
					total_distance+=(goal_y-empty_y);
				}

				first_step[1]=total_distance;
				total_distance=0;
				}
				//---------------------------------------------up için
				if (board[empty_x-1][empty_y]==0 || empty_x-1<0 )
				{
					first_step[2]=9999;
				}
				else{

				num=board[empty_x-1][empty_y];

				for (k = 0; k < row; k++)
				{
					for (l = 0; l < column; l++)
					{
						if (num==final_board[k][l])
						{
							goal_x=k;
							goal_y=l;
						}
					}
				}

				if (goal_x<empty_x)
				{
					total_distance+=(empty_x-goal_x);
				}
				else{
					total_distance+=(goal_x-empty_x);
				}

				if (goal_y<empty_y)
				{
					total_distance+=(empty_y-goal_y);
				}
				else{
					total_distance+=(goal_y-empty_y);
				}

				first_step[2]=total_distance;
				total_distance=0;
				}

				//--------------------------------------------down için

				if (board[empty_x+1][empty_y]==0 || empty_x+1>=row)
				{
					first_step[3]=9999;
				}
				else{

				num=board[empty_x+1][empty_y];

				for (k = 0; k < row; k++)
				{
					for (l = 0; l < column; l++)
					{
						if (num==final_board[k][l])
						{
							goal_x=k;
							goal_y=l;
						}
					}
				}

				if (goal_x<empty_x)
				{
					total_distance+=(empty_x-goal_x);
				}
				else{
					total_distance+=(goal_x-empty_x);
				}

				if (goal_y<empty_y)
				{
					total_distance+=(empty_y-goal_y);
				}
				else{
					total_distance+=(goal_y-empty_y);
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
							move_right2(board,empty_x,empty_y);
							empty_y++;
							break;
						case 1:
							move_left2(board,empty_x,empty_y);
							empty_y--;
							break;
						case 2:
							move_up2(board,empty_x,empty_y);
							empty_x--;
							break;
						case 3:
							move_down2(board,empty_x,empty_y);
							empty_x++;
							break;			

					}


				

	}

	//---------------------------------------menü-------------------------
	void menu2(int game_board[9][9],int final_board[9][9],int row,int column){
		char choice,choice2,ret,prev_ret,prev_move;
		int empty_x,empty_y;
		auto total_move=0,count=1,k=0,z=0,i_step=0,random_move=0,all_step=0,r_step=0;
		int r_c[2];
		int first_step[4];
		string s_array[9];
		string dosya_adi;


		//------------------------------------------------------------------------------
		for (int z = 0; z < row; z++)							
		{
			for (int k = 0; k < column; k++)		//Boşluğun yerini bulup empty x and empty y ye attık
			{
				if(game_board[z][k]==99)
					{
						empty_x=z;
						empty_y=k;
					}
			}
		}
		//--------------------------------------------------------------------
	do{  
		print_menu();
		cin>>choice;

		switch(choice){
			//--------------------------------------------------------------------------------------------------------------
			case 'R':
			case 'r':

				if(empty_y<column-1 && game_board[empty_x][empty_y+1]!=00){

				move_right2(game_board,empty_x,empty_y);
				empty_y+=1;
				total_move++;
				prev_move='r';
				}
				
			break;
			//-------------------------------------------------------------------------------------------------------
			case 'L':
			case 'l':

				if (empty_y>0 &&game_board[empty_x][empty_y-1]!=00)
				{
				move_left2(game_board,empty_x,empty_y);
				empty_y-=1;total_move++;
				prev_move='l';
				}
	
			break;	
			//----------------------------------------------------------------------------------------------------------------
			case 'U':													//boşluğun yukarı doğru hareketini yaptık
			case 'u':

				if (empty_x>0 && game_board[empty_x-1][empty_y]!=00)
				{
					
				move_up2(game_board,empty_x,empty_y);
				empty_x-=1;			total_move++;
				prev_move='u';
				}
	
			break;
			//-----------------------------------------------------------------------------------------------------------------------
			case 'D':
			case 'd':

				if (empty_x<row-1 && game_board[empty_x+1][empty_y]!=00)
				{
				move_down2(game_board,empty_x,empty_y);	
				empty_x+=1;total_move++;
				prev_move='d';
				}	
			
			break;
			//-------------------------------------------------------------------------------------------------------------------------	
			case 'S':													//Shuffle yaptık
			case 's':

				shuffle(game_board,final_board,row,column);
				total_move=0;
				for (z = 0; z < row; z++)							
						{
						for ( k = 0; k < column; k++)		//Boşluğun yerini bulup empty x and empty y ye attık
							{
									if(game_board[z][k]==99)
										{
											empty_x=z;
											empty_y=k;
										}
							}
						}

			break;
			//------------------------------------------------------------------------------------------------------------
	
			case 'T':				//toplam hareketi yazdırdık
			case 't':

				cout<<"Your total move :"<< total_move<<endl;
				cout<<"Your game not finish yet"<<endl;	
				break;
			//-------------------------------------------------------------------------------------------------
			case 'Y':
 			case 'y':

 				cout<<"Enter txt name"<<endl;
				cin>>dosya_adi;
 				row_column(r_c,s_array,dosya_adi);
 				init_board(game_board,s_array,r_c[0],r_c[1]);
    			init_final_board(game_board,final_board,r_c[0],r_c[1]);
 				break;
 				//--------------------------------------------------------------------------------------------------------
 			case 'E':										//dosyaya yazdırdık
 			case 'e':

 				init_txt(game_board,row,column);
 				break;	
 				//-------------------------------------------------------------------------------------------------------
 			case 'i':
 			case 'I':

 					intelligent2(game_board,final_board,row,column,first_step,empty_x,empty_y);
 					for (z = 0; z < row; z++)							
						{
						for ( k = 0; k < column; k++)		//Boşluğun yerini bulup empty x and empty y ye attık
							{
									if(game_board[z][k]==99)
										{
											empty_x=z;
											empty_y=k;
										}
							}
						}	
 					break;
			case 'V':
			case 'v':

				all_step=0;
					while(choice2!='Q' && all_step<=500000){ 
						while(choice2!='Q' && i_step!=25){

							intelligent2(game_board,final_board,row,column,first_step,empty_x,empty_y);
								for (z = 0; z < row; z++)							
								{
								for ( k = 0; k < column; k++)		//Boşluğun yerini bulup empty x and empty y ye attık
									{
										if(game_board[z][k]==99)
											{
												empty_x=z;
												empty_y=k;
											}
									}
								}	
							cout<<endl;
							show_board2(game_board,row,column);
							cout<<endl;
							choice2=control_game2(game_board,final_board,row,column);
							i_step++;cout<<"toplam adim"<<all_step+1<<endl;
							all_step++;
							r_step=0;
						}
						while(choice2!='Q' && r_step!=3){
							
							
								random_move=rand()%4;
								if (random_move==0 && game_board[empty_x][empty_y+1]!=0 && empty_y+1<=column)
									{
									move_right2(game_board,empty_x,empty_y);
									empty_y++;
									r_step++;all_step++;
									cout<<endl;
									show_board2(game_board,row,column);
									cout<<endl;cout<<"toplam adim"<<all_step+1<<endl;
									choice2=control_game2(game_board,final_board,row,column);
									}			

									else if (random_move==1 && game_board[empty_x][empty_y-1]!=0 && empty_y-1>=0 )
									{
									move_left2(game_board,empty_x,empty_y);
									empty_y--;
									r_step++;all_step++;
									cout<<endl;
									show_board2(game_board,row,column);
									cout<<endl;cout<<"toplam adim"<<all_step+1<<endl;
									choice2=control_game2(game_board,final_board,row,column);
									}
								else if (random_move==2 && game_board[empty_x-1][empty_y]!=0 && empty_x-1>=0 )
								{
									move_up2(game_board,empty_x,empty_y);
									empty_x--;
									r_step++;all_step++;
									cout<<endl;
									show_board2(game_board,row,column);
									cout<<endl;cout<<"toplam adim"<<all_step+1<<endl;
									choice2=control_game2(game_board,final_board,row,column);
								}
								else if (random_move==3 && game_board[empty_x+1][empty_y]!=0 && empty_x+1<=row)
								{
									move_down2(game_board,empty_x,empty_y);
									empty_x++;
									r_step++;
									all_step++;
									cout<<endl;
									show_board2(game_board,row,column);
									cout<<endl;
									cout<<"toplam adim"<<all_step+1<<endl;
									choice2=control_game2(game_board,final_board,row,column);
								}							
					
							i_step=0;


						}
						
					}
					break;

			case 'Q':
				break;
			case 'q':
				break;			
		}

		show_board2(game_board,row,column);
		choice2=control_game2(game_board,final_board,row,column);

	}while(choice != 'Q' && choice !='q' && choice2!='Q' )	;

	}




	void menu(int game_board[9][9],int size){
		char choice,choice2,ret,prev_ret,prev_move;
		int empty_x,empty_y,final_game_board[9][9],final_board[9][9];
		int r_c[2];
		auto total_move=0,count=1,r_step=0,all_step=0,i_step=0,random_move=0,flag=0;
		string s_array[9];
		string dosya_adi;

		for (int z = 0; z < size; z++)
		{
			for (int k = 0; k < size; k++)
			{
				final_game_board[z][k]=count;
				count++;
			}
		}
		final_game_board[size-1][size-1]=99;

	do{  

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{	if (game_board[i][j]==99)
			  {
				empty_x=i;
				empty_y=j;
			   }
			}
		}
		print_menu();

		cin>>choice;


		switch(choice){
			case 'R':
			case 'r':

				if(empty_y<size-1){

				move_right(game_board,size,empty_x,empty_y);
				empty_y+=1;
				total_move++;
				prev_move='r';
				}
				
			break;

			case 'L':
			case 'l':

				if (empty_y>0)
				{
				move_left(game_board,size,empty_x,empty_y);
				empty_y-=1;total_move++;
				prev_move='l';
				}
	
			break;	

			case 'U':
			case 'u':

				if (empty_x>0)
				{
					
				move_up(game_board,size,empty_x,empty_y);
				empty_x-=1;			total_move++;
				prev_move='u';
				}
	
			break;

			case 'D':
			case 'd':

				if (empty_x<size-1)
				{
				move_down(game_board,size,empty_x,empty_y);	
				empty_x+=1;total_move++;
				prev_move='d';
				}	
			
			break;	
			case 'S':
			case 's':

				suffle(game_board,size);
				total_move=0;

			break;
			case 'Y':
 			case 'y':

 				cout<<"Enter txt name"<<endl;
				cin>>dosya_adi;
 				row_column(r_c,s_array,dosya_adi);
 				init_board(game_board,s_array,r_c[0],r_c[1]);
    			init_final_board(game_board,final_board,r_c[0],r_c[1]);
    			show_board2(game_board,r_c[0],r_c[1]);
 				break;
 			case 'E':
 			case 'e':
 				init_txt(game_board,size,size);
			case 'I':
			case 'i':

				ret=intelligent(game_board,size,empty_x,empty_y,prev_move);
				if(ret=='r'){
					move_right(game_board,size,empty_x,empty_y);
					empty_y+=1;total_move++;
					prev_move='r';
				}
				else if(ret=='l'){
					move_left(game_board,size,empty_x,empty_y);
					empty_y-=1;total_move++;
					prev_move='l';
				}
				else if (ret=='u')
				{
					move_up(game_board,size,empty_x,empty_y);
					empty_x-=1;	total_move++;
					prev_move='u';
				}
				else{
					move_down(game_board,size,empty_x,empty_y);	
					empty_x+=1;		total_move++;
					prev_move='d';
				}
				break;

			case 'v':
			case 'V':

				all_step=0;
				flag=1;
					while(choice2!='Q' && all_step<=500000){ 
						while(choice2!='Q' && i_step!=25){
								ret=intelligent(game_board,size,empty_x,empty_y,prev_move);
								if(ret=='r'){
									move_right(game_board,size,empty_x,empty_y);
									empty_y+=1;total_move++;
									prev_move='r';i_step++;
											}
								else if(ret=='l'){
									move_left(game_board,size,empty_x,empty_y);
									empty_y-=1;total_move++;
									prev_move='l';i_step++;
													}
								else if (ret=='u')
												{
									move_up(game_board,size,empty_x,empty_y);
									empty_x-=1;	total_move++;
									prev_move='u';i_step++;
												}
								else{
									move_down(game_board,size,empty_x,empty_y);	
									empty_x+=1;		total_move++;
									prev_move='d';i_step++;
									}
									random_move=0;

									cout<<"Your total move: "<<total_move<<endl;
									show_board(game_board,size);
									choice2=control_game(game_board,final_game_board,size);
									all_step++;

									r_step=0;
								}

						while(choice2!='Q' && r_step!=3){
							
							
								random_move=rand()%4;
								if (random_move==0 && empty_y+1<size)
									{
									move_right(game_board,size,empty_x,empty_y);
									empty_y++;
									r_step++;all_step++;
									cout<<endl;
									show_board(game_board,size);
									cout<<endl;cout<<"toplam adim"<<all_step<<endl;
									choice2=control_game(game_board,final_game_board,size);
									}			

									else if (random_move==1 && empty_y-1>=0 )
									{
									move_left(game_board,size,empty_x,empty_y);
									empty_y--;
									r_step++;all_step++;
									cout<<endl;
									show_board(game_board,size);
									cout<<endl;cout<<"toplam adim"<<all_step<<endl;
									choice2=control_game(game_board,final_game_board,size);
									}
								else if (random_move==2 && empty_x-1>=0 )
								{
									move_up(game_board,size,empty_x,empty_y);
									empty_x--;
									r_step++;all_step++;
									cout<<endl;
									show_board(game_board,size);
									cout<<endl;cout<<"toplam adim"<<all_step<<endl;
									choice2=control_game(game_board,final_game_board,size);
								}
								else if (random_move==3 && empty_x+1<size)
								{
									move_down(game_board,size,empty_x,empty_y);
									empty_x++;
									r_step++;all_step++;
									cout<<endl;
									show_board(game_board,size);
									cout<<endl;cout<<"toplam adim"<<all_step<<endl;
									choice2=control_game(game_board,final_game_board,size);
								}							
					
							i_step=0;


						}


							}

			break;


			case 'Q':
				break;
			case 'q':
				break;			
		}

		cout<<"Your total move: "<<total_move<<endl;
		if (flag!=1)
		{
			/* code */
		show_board(game_board,size);
		choice2=control_game(game_board,final_game_board,size);
		}

	}while(choice != 'Q' && choice !='q' && choice2!='Q' )	;

	}