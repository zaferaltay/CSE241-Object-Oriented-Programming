#include <iostream>
#include <ctime>


using namespace std;
void init_game_board(int game[9][9],int size){
	int line,column,controller=0,iter=0,flag=0,count=0;
	int i=0,j=0;
	int control_array_size=size*size;
	int control_array[control_array_size];
	while(i<control_array_size){
		control_array[i]=100;
		i++;
	}


	for (i = 0; i <9; i++)   // oyun tahtasını işaret sayısıyla doldurduk
	{
		for (j = 0; j < 9; j++)
		{
			game[i][j]=99;
		}
	}

	line=column=size; //sınırları belirledik 

	for (i = 0; i <line ; i++) //işaretçi olan yerleri doldururuyoruz
	{
		for (j = 0; j < column; j++)
		{	
			
			do{ 
			iter=rand()%control_array_size;
			flag=0;
			while(controller<control_array_size){
				if (iter==control_array[controller])
				{
					
					controller=0;
					break;
				}
				else{
					controller++;
				}
			}


			}while( controller<control_array_size);
			
			control_array[count]=iter;
			count++;
			game[i][j]=iter;
			controller=0;
				
			
		}
	}
}
	int solvable_control(int game_board[9][9],int size){
		int control_array[(size*size)-1];             // boşluk hariç lineer bir arraye sıraladık
		int count=0,count2=0,count3=0,count4=0,count5=0,sum=0,total=0; // countlar sırasıyla toplam size,bulunduğum size,bulunduğun yerdeki sayı,baştan bulunduğun yere olan kısmı ve olan sayıları saymkatadır
		

		for (int i = 0; i < size; i++)    // arrayi doldurduk
		{
			for (int j = 0; j < size; j++)
			{
				if(game_board[i][j]!=0){

				control_array[count]=game_board[i][j];
				count++;
				}
			}
		}

			while(count2<count){						
					count3=control_array[count2];
					while(count4<count2){
						if (control_array[count4]<count3)
						{
							count5++;					//bkatığımız yerden küçük olan ve bulunan sayıalrı saydık ve asıl sayıdan çıkardık olmayanlar inverse olanlar
						}
						count4++;
					}
					total=count3-count5-1;
					count5=0;
					count4=0;
					sum+=total;
					count2++;
			}

			if (sum%2==0){
				return 0;		//eğer çiftse total çözülebilir
			}
			else{
				return 1;		//tekse çözülemez
			}


	}


	void show_board(int board[9][9],int size){
		
			for (int i = 0; i < size; i++)  /// sayuları board a yerleştirdk çift haneli ve tek haneli olanları boşluklarını ayarladık
			{
				for (int j = 0; j < size; j++)
				{	if (board[i][j]!=0)
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
				  	cout<<"   ";
				  }
				}
				cout<<endl;
			}
	}

	 void move_right(int game_board[9][9],int size,int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x][empty_y+1];
		game_board[empty_x][empty_y+1]=0;

	 }
	 void move_left(int game_board[9][9],int size,int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x][empty_y-1];
		game_board[empty_x][empty_y-1]=0;
	 }
	 void move_down(int game_board[9][9],int size,int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x+1][empty_y];
		game_board[empty_x+1][empty_y]=0;

	 }
	 void move_up(int game_board[9][9],int size,int empty_x,int empty_y){
	 	game_board[empty_x][empty_y]=game_board[empty_x-1][empty_y];
		game_board[empty_x-1][empty_y]=0;
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


	void suffle(int game_board[9][9],int size){
		int num=1,random,count=0,x=size-1,y=size-1,prev_move=0;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				game_board[i][j]=num;
				num++;
			}
		}
		game_board[size-1][size-1]=0;


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

	char control_game(int game_board[9][9],int final_game_board[9][9],int size){
		int count=0;
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






	void menu(int game_board[9][9],int size){
		char choice,choice2,ret,prev_ret,prev_move;
		int empty_x,empty_y,total_move=0,count=1,final_game_board[9][9];

		for (int z = 0; z < size; z++)
		{
			for (int k = 0; k < size; k++)
			{
				final_game_board[z][k]=count;
				count++;
			}
		}
		final_game_board[size-1][size-1]=0;

	do{  

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{	if (game_board[i][j]==0)
			  {
				empty_x=i;
				empty_y=j;
			   }
			}
		}

		cin>>choice;


		switch(choice){
			case 'R':
				if(empty_y<size-1){

				move_right(game_board,size,empty_x,empty_y);
				empty_y+=1;
				total_move++;
				prev_move='r';
				}
				
			break;
			case 'r':
				if(empty_y<size-1){

				move_right(game_board,size,empty_x,empty_y);
				empty_y+=1;
				total_move++;
				prev_move='r';
				}
				
			break;

			case 'L':
				if (empty_y>0)
				{
				move_left(game_board,size,empty_x,empty_y);
				empty_y-=1;total_move++;
				prev_move='l';
				}
	
			break;

			case 'l':
				if (empty_y>0)
				{
				move_left(game_board,size,empty_x,empty_y);
				empty_y-=1;total_move++;
				prev_move='l';
				}
	
			break;	

			case 'U':
				if (empty_x>0)
				{
					
				move_up(game_board,size,empty_x,empty_y);
				empty_x-=1;			total_move++;
				prev_move='u';
				}

			break;
			case 'u':
				if (empty_x>0)
				{
					
				move_up(game_board,size,empty_x,empty_y);
				empty_x-=1;			total_move++;
				prev_move='u';
				}
	
			break;

			case 'D':
				if (empty_x<size-1)
				{
				move_down(game_board,size,empty_x,empty_y);	
				empty_x+=1;total_move++;
				prev_move='d';
				}

			break;
			case 'd':
				if (empty_x<size-1)
				{
				move_down(game_board,size,empty_x,empty_y);	
				empty_x+=1;total_move++;
				prev_move='d';
				}	
			
			break;	
			case 'S':
				suffle(game_board,size);
				total_move=0;

			break;
			case 's':
				suffle(game_board,size);
				total_move=0;

			break;
			case 'I':
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
			case 'Q':
				break;
			case 'q':
				break;			
		}

		cout<<"Your total move: "<<total_move<<endl;
		show_board(game_board,size);
		choice2=control_game(game_board,final_game_board,size);

	}while(choice != 'Q' && choice !='q' && choice2!='Q' )	;

	}

int main(){
	srand(time(0));
	int game_board[9][9];
	int size;
	int control=0;
	do{
		cout<<"Please enter the size (3-9)"<<endl;
		cin>>size;
		control=0;
		if (size<3 || size>9)
		{
			control=1;
		}
}while(control);
	do{
		init_game_board(game_board,size);
		control=solvable_control(game_board,size);
		}while(control);
	show_board(game_board,size);
	menu(game_board,size);
}
