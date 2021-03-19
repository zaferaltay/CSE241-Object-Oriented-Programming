#include "board1d.h"


namespace zaff{

BoardArray1D::BoardArray1D(){
	setSize(3,3);

}
BoardArray1D::BoardArray1D(int num1,int num2){
	setSize(num1,num2);
}
BoardArray1D::BoardArray1D(const BoardArray1D& obj){
	board1d = new int [obj.getRow()*obj.getColumn()];
	finalGameBoard1d=new int [obj.getRow()*obj.getColumn()];
	for (int i = 0; i <obj.getRow()*obj.getColumn() ; i++)
	 {
	 	board1d[i]=obj.board1d[i];
	 	finalGameBoard1d[i]=obj.board1d[i];
	 } 
}

bool BoardArray1D::operator ==(const AbstractBoard& other){
	int counter=0;

	BoardArray1D *brd=(BoardArray1D *)&other;


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (board1d[i+j]==brd->board1d[i+j])
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
BoardArray1D& BoardArray1D::operator=(const BoardArray1D& obj){
	if (this==&obj)
	{
		return *this;
	}
	if (row!=obj.getRow() || column!=obj.getColumn())
	{
		delete [] board1d;
		delete [] finalGameBoard1d;
		setSize(obj.getRow(),obj.getColumn());
	}
	for (int i = 0; i < obj.getColumn()*obj.getRow(); i++)
	{
		board1d[i]=obj.board1d[i];
		finalGameBoard1d[i]=obj.finalGameBoard1d[i];
	}

	lastmove='s';
	empty_x=obj.getEmptyX();
	empty_y=obj.getEmptyY();

	return *this;

}

BoardArray1D:: ~BoardArray1D(){
	delete [] board1d;
	delete [] finalGameBoard1d;
}
int BoardArray1D::operator()(int a,int b){
		return board1d[a*column+b];
}
void BoardArray1D::setSize(int num1,int num2){
	row=num1;
	column=num2;
	numBoard++;
	int a;
	int count=1;
	int random;

	board1d=new int [row*column];
	finalGameBoard1d=new int [row*column];

		for (int z = 0; z < row; z++)
		{
			for (int k = 0; k < column; k++)
			{
				finalGameBoard1d[(column*z)+k]=count;
				count++;
			}
		}
		finalGameBoard1d[(row*column)-1]=99;
		empty_x=row-1;
		empty_y=column-1;
		for (int l = 0; l < row; l++)
		{
			for (int m = 0; m < column; m++)
			{
				a=finalGameBoard1d[(column*l)+m];
				board1d[(column*l)+m]=a;
			}
		}
		count=0;
					while(count<(row*column)){
						random=rand()%4;
							switch(random){
								case 0:
									if (empty_x>0 &&board1d[(column*empty_x+empty_y)-column]!=00)
									{
										move('u');
										count++;	
									}
									break;
								case 1:
									if (empty_x<row-1&& board1d[(column*empty_x+empty_y)+column]!=00)
										{
											move('d');
											count++;
										}	
									break;
								case 2:
									if (empty_y>0 && board1d[(column*empty_x+empty_y)-1]!=00)
										{
											move('l');
											count++;
										}		
									break;
								case 3:
									if (empty_y<column-1 && board1d[(column*empty_x+empty_y)+1]!=00)
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
void BoardArray1D::print()const{
	for ( int i=0; i <row; i++)
			{
				for ( int j=0; j <column; j++)
				{	if (board1d[(row*i)+j]!=99)
				 {
				 	if (board1d[(row*i)+j]/10!=0)
				 	{
					cout<<" "<<board1d[(row*i)+j];						
				 	
				 	}
				 	else{
				 		cout<<" 0"<<board1d[(row*i)+j];
				 	}
				  }
				  else{
				  	cout<<" bb";
				  }
				}
				cout<<endl;
					
				}
}
void BoardArray1D::readFromFile(){
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
void BoardArray1D::writeToFile()const{
		string output_txt;
		//cout<<"Please enter a file name"<<endl;
		//cin>>output_txt;
		output_txt="abcd";
		ofstream printerr;
		printerr.open(output_txt);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{	if (board1d[(row*i)+j]>=10 && board1d[(row*i)+j]!=99)
			    {
					printerr<<board1d[(row*i)+j];
			    }
				else if (board1d[(row*i)+j]==99)
			    {
					printerr<<"bb";
				}
				else{
					printerr<<"0";
					printerr<<board1d[(row*i)+j];
				}
			
				if(j<column-1)
					printerr<<" ";

			}
			if(i<row-1)
			printerr<<endl;
		}	
	}
void BoardArray1D::init_final_board(){
	
		int counter=1,last_i,last_j;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)							// 1 den başlyayan counter tuttuk ,00 görünce 00 yazdı,bb görünce bb yazdı 
			{
				if (board1d[i+j]==0)							//normal sayı görünce tuttuğumuz sayıyı yazdı
				{
					finalGameBoard1d[(row*i)+j]=board1d[(row*i)+j];
				}
				else{
					finalGameBoard1d[(row*i)+j]=counter;
					counter++;
					last_i=i;
					last_j=j;
				}
			}
		}
		finalGameBoard1d[row*column-1]=99;
	}	
void BoardArray1D::initBoard(string s_array[9]){
				int count_string_column=0,counter=0;
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

					board1d[counter]=total;
					counter++;
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
				if (board1d[(row*i)+j]==99)
				{
					empty_x=i;
					empty_y=j;
				}
			}
		}
		init_final_board(); 
		}

	bool BoardArray1D::isSolved()const{
		int count=0;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					if (board1d[(row*i)+j]==finalGameBoard1d[(row*i)+j])
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
	void BoardArray1D::reset(){
		int a;
		for (int l = 0; l < row; l++)
		{
			for (int m = 0; m < column; m++)
			{
				a=finalGameBoard1d[(row*l)+m];
				board1d[(row*l)+m]=a;
			}
		}		

	}	
	void BoardArray1D::move(char movee){

		switch(movee){
			case 'l' :
			case 'L' :
	 			if (empty_y>0 && board1d[(column*empty_x+empty_y)-1]!=0){
	 			board1d[(column*empty_x+empty_y)]=board1d[(column*empty_x+empty_y)-1];
				board1d[(column*empty_x+empty_y)-1]=99;
				empty_y=empty_y-1;
				total_move++;
				lastmove='l';
	 			}

				break;

			case 'r' :
			case 'R' :
				if (empty_y<column-1 && board1d[(column*empty_x+empty_y)+1]!=0){
		 		board1d[(column*empty_x+empty_y)]=board1d[(column*empty_x+empty_y)+1];
				board1d[(column*empty_x+empty_y)+1]=99;
				empty_y=empty_y+1;	
				total_move++;lastmove='r';
				}
				break;

			case 'u':
			case 'U':
				if (empty_x>0 &&board1d[(column*empty_x+empty_y)-column]!=0){
				board1d[(column*empty_x+empty_y)]=board1d[(column*empty_x+empty_y)-column];
				board1d[(column*empty_x+empty_y)-column]=99;
				empty_x=empty_x-1;
				total_move++;lastmove='u';
				}
				break;

			case 'd':
			case 'D':
				if (empty_x<row-1&& board1d[(column*empty_x+empty_y)+3]!=0){
				board1d[(column*empty_x+empty_y)]=board1d[(column*empty_x+empty_y)+3];
				board1d[(column*empty_x+empty_y)+column]=99;
				empty_x=empty_x+1;
				total_move++;lastmove='d';
				}
				break;
		} //switxh case kapama parantezi
			

}
}