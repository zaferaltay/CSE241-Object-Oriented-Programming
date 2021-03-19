#include "boardvect.h"

namespace zaff{
BoardVector::BoardVector(){
	int num1,num2;
	cout<<"Please enter the size"<<endl;
	cin>>num1>>num2;
	setSize(num1,num2);
}
BoardVector::BoardVector(int num1,int num2){
	setSize(num1,num2);
}

BoardVector::BoardVector(const BoardVector& obj){
	vector<int> v;
	for (int i = 0; i < obj.getRow(); i++)
	{
		for (int j = 0; j < obj.getColumn(); j++)
		{
			v.push_back(obj.boardvector[i][j]);
		}
		boardvector.push_back(v);
		v.clear();
	}

	for (int k = 0; k < obj.getRow(); k++)
	{
		for (int l = 0; l < obj.getColumn(); l++)
		{
			v.push_back(obj.finalvector[k][l]);
		}
		finalvector.push_back(v);
		v.clear();
	}
}


void BoardVector::reset(){
		for (int l = 0; l < row; l++)
		{
			for (int m = 0; m < column; m++)
			{
				boardvector[l][m]=finalvector[l][m];
			}
		}
}
bool BoardVector::operator ==(const AbstractBoard& other){
	int counter=0;

	BoardVector *brd=(BoardVector *)&other;


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (boardvector[i][j]==brd->boardvector[i][j])
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
BoardVector:: ~BoardVector(){
	boardvector.clear();
	finalvector.clear();

}
int BoardVector::operator()(int a,int b){
		return boardvector[a][b];
}
void BoardVector::setSize(int num1,int num2){
	row=num1;
	column=num2;
	numBoard++;
	vector<int> v;
	int random;

		for (int z = 0; z < row; z++)
		{
			for (int k = 0; k < column; k++)
			{
				v.push_back(count);
				count++;
			}
			boardvector.push_back(v);
			finalvector.push_back(v);
			v.clear();
		}
		finalvector[row-1][column-1]=99;
		boardvector[row-1][column-1]=99;
		empty_x=row-1;
		empty_y=column-1;

		count=0;
					while(count<(row*column)){
						random=rand()%4;
							switch(random){
								case 0:
									if (empty_x>0 &&boardvector[empty_x-1][empty_y]!=00)
									{
										move('u');
										count++;	
									}
									break;
								case 1:
									if (empty_x<row-1&& boardvector[empty_x+1][empty_y]!=00)
										{
											move('d');
											count++;
										}	
									break;
								case 2:
									if (empty_y>0 && boardvector[empty_x][empty_y-1]!=00)
										{
											move('l');
											count++;
										}		
									break;
								case 3:
									if (empty_y<column-1 &&boardvector[empty_x][empty_y+1]!=00)
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
void BoardVector::move(char movee){

		switch(movee){
			case 'l' :
			case 'L' :
	 			if (empty_y>0 && boardvector[empty_x][empty_y-1]!=0){
	 			boardvector[empty_x][empty_y]=boardvector[empty_x][empty_y-1];
				boardvector[empty_x][empty_y-1]=99;
				empty_y=empty_y-1;
				total_move++;
				lastmove='l';
	 			}

				break;

			case 'r' :
			case 'R' :
				if (empty_y<column-1 &&boardvector[empty_x][empty_y+1]!=0){
		 		boardvector[empty_x][empty_y]=boardvector[empty_x][empty_y+1];
				boardvector[empty_x][empty_y+1]=99;
				empty_y=empty_y+1;	
				total_move++;lastmove='r';
				}
				break;

			case 'u':
			case 'U':
				if (empty_x>0 &&boardvector[empty_x-1][empty_y]!=0){
				boardvector[empty_x][empty_y]=boardvector[empty_x-1][empty_y];
				boardvector[empty_x-1][empty_y]=99;
				empty_x=empty_x-1;
				total_move++;lastmove='u';
				}
				break;

			case 'd':
			case 'D':
				if (empty_x<row-1&& boardvector[empty_x+1][empty_y]!=0){
				boardvector[empty_x][empty_y]=boardvector[empty_x+1][empty_y];
				boardvector[empty_x+1][empty_y]=99;
				empty_x=empty_x+1;
				total_move++;lastmove='d';
				}
				break;
		} //switxh case kapama parantezi
			

}
void BoardVector::print()const{
	for ( int i=0; i <row; i++)
			{
				for ( int j=0; j <column; j++)
				{	if (boardvector[i][j]!=99)
				 {
				 	if (boardvector[i][j]/10!=0)
				 	{
					cout<<" "<<boardvector[i][j];						
				 	
				 	}
				 	else{
				 		cout<<" 0"<<boardvector[i][j];
				 	}
				  }
				  else{
				  	cout<<" bb";
				  }
				}
				cout<<endl;
					
				}
}
void BoardVector::readFromFile(){
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
void BoardVector::writeToFile()const{
		string output_txt;
		//cout<<"Please enter a file name"<<endl;
		//cin>>output_txt;
		output_txt="abcd";
		ofstream printerr;
		printerr.open(output_txt);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{	if (boardvector[i][j]>=10 && boardvector[i][j]!=99)
			    {
					printerr<<boardvector[i][j];
			    }
				else if (boardvector[i][j]==99)
			    {
					printerr<<"bb";
				}
				else{
					printerr<<"0";
					printerr<<boardvector[i][j];
				}
			
				if(j<column-1)
					printerr<<" ";

			}
			if(i<row-1)
			printerr<<endl;
		}	
	}
	void BoardVector::init_final_board(){
	
		int counter=1,last_i,last_j;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)							// 1 den başlyayan counter tuttuk ,00 görünce 00 yazdı,bb görünce bb yazdı 
			{
				if (boardvector[i][j]==0)							//normal sayı görünce tuttuğumuz sayıyı yazdı
				{
					finalvector[i][j]=boardvector[i][j];
				}
				else{
					finalvector[i][j]=counter;
					counter++;
					last_i=i;
					last_j=j;
				}
			}
		}
		finalvector[last_i][last_j]=99;
	}	
	void BoardVector::initBoard(string s_array[9]){
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

					boardvector[string_row][(count_string_column/3)]=total;
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
				if (boardvector[i][j]==99)
				{
					empty_x=i;
					empty_y=j;
				}
			}
		}
		init_final_board(); 
		}
		bool BoardVector::isSolved()const{
		int count=0;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					if (boardvector[i][j]==finalvector[i][j])
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