#include "board2d.h"

namespace zaff{

BoardArray2D::BoardArray2D(){
	setSize(3,3);
}
BoardArray2D::BoardArray2D(int num1,int num2){
	setSize(num1,num2);
}
BoardArray2D::BoardArray2D(const BoardArray2D& obj){


	board2d=new int*[obj.getRow()];
	finalGameBoard2d=new int*[obj.getRow()];
	for (int i = 0; i < row; ++i)
	{
		board2d[i]=new int[obj.getColumn()];
		finalGameBoard2d[i]=new int[obj.getColumn()];
	}

	for (int j = 0; j < obj.getRow(); j++)
	{
		for (int k = 0; k < obj.getColumn(); k++)
		{
			board2d[j][k]=obj.board2d[j][k];
			finalGameBoard2d[j][k]=obj.board2d[j][k];
		}
	}
}
void BoardArray2D::reset(){								//final board u normal board a kopyaladık
		for (int l = 0; l < row; l++)
		{
			for (int m = 0; m < column; m++)
			{
				board2d[l][m]=finalGameBoard2d[l][m];
			}
		}
}
bool BoardArray2D::operator ==(const AbstractBoard& other){
	int counter=0;

	BoardArray2D *brd=(BoardArray2D *)&other;										//type cast yapıp compieler hatası almayı engelledik

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (board2d[i][j]==brd->board2d[i][j])								//her eleman tek tek eşit mi diye kontrol ettik
			{
				counter++;
			}
		}
	}

	if (counter==(row*column))
	{
		return true;
	}
	else{
		return false;
	}

}
BoardArray2D& BoardArray2D::operator=(const BoardArray2D &obj){
	if (this == &obj)
	{
		return *this;
	}
	if (row!=obj.getRow() || column!=obj.getColumn())							//eğer aynı eleman değilse öncekini hafızadan silip new ile yenisini oluşturduk
	{																			//yeni oluşanın içini doldurup return ettik
		delete [] board2d;
		delete [] finalGameBoard2d;
		setSize(obj.getRow(),obj.getColumn());
	}
	for (int i = 0; i < obj.getRow(); i++)
	{
		for (int j = 0; j < obj.getColumn(); j++)
		{
			board2d[i][j]=obj.board2d[i][j];
			finalGameBoard2d[i][j]=obj.finalGameBoard2d[i][j];
		}
	}
	lastmove='s';
	empty_x=obj.getEmptyX();
	empty_y=obj.getEmptyY();

	return *this;

}
BoardArray2D:: ~BoardArray2D(){
	delete [] board2d;
	delete [] finalGameBoard2d;
}

int BoardArray2D::operator()(int a,int b){
		return board2d[a][b];
}


void BoardArray2D::setSize(int num1,int num2){								//new ile row ve column a göre yer ayırdık
	row=num1;
	column=num2;
	numBoard++;
	board2d=new int* [row];
	finalGameBoard2d=new int* [row];
		int random;

	for (int i = 0; i < row; ++i)
	{
		board2d[i] =new int[column];
		finalGameBoard2d[i] =new int[column];
	}

		for (int z = 0; z < row; z++)
		{
			for (int k = 0; k < column; k++)
			{
				finalGameBoard2d[z][k]=count;
				count++;
			}
		}
		finalGameBoard2d[row-1][column-1]=99;				//final board u sırayla artırarak gittik doldurduk 
		empty_x=row-1;
		empty_y=column-1;
		for (int l = 0; l < row; l++)
		{
			for (int m = 0; m < column; m++)
			{
				board2d[l][m]=finalGameBoard2d[l][m];		//boarda attık ve sonra karıştırdık
			}
		}
		count=0;
	
					while(count<(row*column)){
						random=rand()%4;
							switch(random){
								case 0:
									if (empty_x>0 &&board2d[empty_x-1][empty_y]!=00)
									{
										move('u');
										count++;	
									}
									break;
								case 1:
									if (empty_x<row-1&& board2d[empty_x+1][empty_y]!=00)
										{
											move('d');
											count++;
										}	
									break;
								case 2:
									if (empty_y>0 && board2d[empty_x][empty_y-1]!=00)
										{
											move('l');
											count++;
										}		
									break;
								case 3:
									if (empty_y<column-1 &&board2d[empty_x][empty_y+1]!=00)
										{
											move('r');
											count++;
										}
									break;							
									}   // switch-case kapanış
								} //while kapanış
							total_move=0;
							count=1;	
}
void BoardArray2D::move(char movee){

		switch(movee){
			case 'l' :
			case 'L' :
	 			if (empty_y>0 && board2d[empty_x][empty_y-1]!=0){
	 			board2d[empty_x][empty_y]=board2d[empty_x][empty_y-1];
				board2d[empty_x][empty_y-1]=99;
				empty_y=empty_y-1;
				total_move++;
				lastmove='l';
	 			}

				break;

			case 'r' :
			case 'R' :
				if (empty_y<column-1 &&board2d[empty_x][empty_y+1]!=0){
		 		board2d[empty_x][empty_y]=board2d[empty_x][empty_y+1];
				board2d[empty_x][empty_y+1]=99;
				empty_y=empty_y+1;	
				total_move++;lastmove='r';
				}
				break;

			case 'u':
			case 'U':
				if (empty_x>0 &&board2d[empty_x-1][empty_y]!=0){
				board2d[empty_x][empty_y]=board2d[empty_x-1][empty_y];
				board2d[empty_x-1][empty_y]=99;
				empty_x=empty_x-1;
				total_move++;lastmove='u';
				}
				break;

			case 'd':
			case 'D':
				if (empty_x<row-1&& board2d[empty_x+1][empty_y]!=0){
				board2d[empty_x][empty_y]=board2d[empty_x+1][empty_y];
				board2d[empty_x+1][empty_y]=99;
				empty_x=empty_x+1;
				total_move++;lastmove='d';
				}
				break;
		} //switxh case kapama parantezi
				

}

void BoardArray2D::print()const{
	for ( int i=0; i <row; i++)
			{
				for ( int j=0; j <column; j++)
				{	if (board2d[i][j]!=99)
				 {
				 	if (board2d[i][j]/10!=0)
				 	{
					cout<<" "<<board2d[i][j];						
				 	
				 	}
				 	else{
				 		cout<<" 0"<<board2d[i][j];
				 	}
				  }
				  else{
				  	cout<<" bb";
				  }
				}
				cout<<endl;
					
				}
}
void BoardArray2D::readFromFile(){
			string satir;
			string dosya_adi;
			int i=0;
			int satir_sayisi=0,sutun_sayisi=0;
			total_move=0;
			//cout<<"Please enter the text name"<<endl;
			//cin>>dosya_adi;
			dosya_adi="abc";
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
void BoardArray2D::writeToFile()const{
		string output_txt;
		//cout<<"Please enter a file name"<<endl;
		//cin>>output_txt;
		output_txt="abcd";
		ofstream printerr;
		printerr.open(output_txt);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{	if (board2d[i][j]>=10 && board2d[i][j]!=99)
			    {
					printerr<<board2d[i][j];
			    }
				else if (board2d[i][j]==99)
			    {
					printerr<<"bb";
				}
				else{
					printerr<<"0";
					printerr<<board2d[i][j];
				}
			
				if(j<column-1)
					printerr<<" ";

			}
			if(i<row-1)
			printerr<<endl;
		}	
	}


void BoardArray2D::init_final_board(){
	
		int counter=1,last_i,last_j;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)							// 1 den başlyayan counter tuttuk ,00 görünce 00 yazdı,bb görünce bb yazdı 
			{
				if (board2d[i][j]==0)							//normal sayı görünce tuttuğumuz sayıyı yazdı
				{
					finalGameBoard2d[i][j]=board2d[i][j];
				}
				else{
					finalGameBoard2d[i][j]=counter;
					counter++;
					last_i=i;
					last_j=j;
				}
			}
		}
		finalGameBoard2d[last_i][last_j]=99;
	}	


void BoardArray2D::initBoard(string s_array[9]){
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

					board2d[string_row][(count_string_column/3)]=total;
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
				if (board2d[i][j]==99)
				{
					empty_x=i;
					empty_y=j;
				}
			}
		}
		init_final_board(); 
		}	

bool BoardArray2D::isSolved()const{
		int count=0;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					if (board2d[i][j]==finalGameBoard2d[i][j])
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

}