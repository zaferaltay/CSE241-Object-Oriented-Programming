#include "npuzzle.h"

int main(int argc, char const *argv[])
{
	srand(time(0));
	char choice;

	//----------------------------------------------------------------------Dosyasız başlayan oyun ------------------------------------------------------------
	if (argc==1)
	{
	NPuzzle nPuzzle; //Noparameter constructor
	
	nPuzzle.print();
	bool control=false;
	while(control!=true){
	cout<<"V-) Solves the problem"<<endl;
	cout<<"T-) Prints a report"<<endl;
	cout<<"O-) Asks a file name and loads the current board"<<endl;
	cout<<"E-) Asks a file name and saves the current board"<<endl;
	cout<<"L-) Moves left"<<endl;
	cout<<"R-) Moves right"<<endl;
	cout<<"U-) Moves up"<<endl;
	cout<<"D-) Moves down"<<endl;
	cout<<"I-) Makes an intelligent move"<<endl;
	cout<<"S-) Shuffle the board"<<endl;

		cin>>choice;
		switch(choice){
			case 'I':
			case 'i':

					nPuzzle.moveIntelligent();
					nPuzzle.print();
					break;
					//-----------------------------------------------------------------------------------------
			case 'L':
			case 'l':
					nPuzzle.move('l');
					nPuzzle.print();
					break;
			case 'R':
			case 'r':
					nPuzzle.move('r');
					nPuzzle.print();
					break;						
			case 'U':
			case 'u':
					nPuzzle.move('u');
					nPuzzle.print();
					break;
			case 'D':
			case 'd':
					nPuzzle.move('d');
					nPuzzle.print();
					break;																				
					//----------------------------------------------------------------------------------------
			case 'S':
			case 's':

					nPuzzle.shuffle(nPuzzle.getRow2()*nPuzzle.getColumn2());
					nPuzzle.print();
					break;

					//-------------------------------------------------------------------------------------------	
			case 'V':
			case 'v':

					nPuzzle.solvePuzzle();
					break;

					//-----------------------------------------------------------------------------------------
			case 'T':
			case 't':
					nPuzzle.printReport();
					nPuzzle.print();
					break;
			case 'O':
			case 'o':
					nPuzzle.readFromFile();
					nPuzzle.print();
					break;		
			case 'E':
			case 'e':
					nPuzzle.writeToFile();
					nPuzzle.print();
					break;		

		}
		control=nPuzzle.control();
	}
}
//-------------------------------------------------------------------------file alarak başlayan---------------------------------------------------------------------
	else{
		NPuzzle nPuzzle(argv[1]);		//Constructor with string
		nPuzzle.print();
	bool control=false;
	while(control!=true){
	cout<<"V-) Solves the problem"<<endl;
	cout<<"T-) Prints a report"<<endl;
	cout<<"O-) Asks a file name and loads the current board"<<endl;
	cout<<"E-) Asks a file name and saves the current board"<<endl;
	cout<<"L-) Moves left"<<endl;
	cout<<"R-) Moves right"<<endl;
	cout<<"U-) Moves up"<<endl;
	cout<<"D-) Moves down"<<endl;
	cout<<"I-) Makes an intelligent move"<<endl;
	cout<<"S-) Shuffle the board"<<endl;

		cin>>choice;
		switch(choice){
			case 'I':
			case 'i':

					nPuzzle.moveIntelligent();
					nPuzzle.print();
					break;
					//-----------------------------------------------------------------------------------------
			case 'L':
			case 'l':
					nPuzzle.move('l');
					nPuzzle.print();
					break;
			case 'R':
			case 'r':
					nPuzzle.move('r');
					nPuzzle.print();
					break;						
			case 'U':
			case 'u':
					nPuzzle.move('u');
					nPuzzle.print();
					break;
			case 'D':
			case 'd':
					nPuzzle.move('d');
					nPuzzle.print();
					break;																				
					//----------------------------------------------------------------------------------------
			case 'S':
			case 's':

					nPuzzle.shuffle(nPuzzle.getRow2()*nPuzzle.getColumn2());
					nPuzzle.print();
					break;

					//-------------------------------------------------------------------------------------------	
			case 'V':
			case 'v':

					nPuzzle.solvePuzzle();
					break;

					//-----------------------------------------------------------------------------------------
			case 'T':
			case 't':
					nPuzzle.printReport();
					nPuzzle.print();
					break;
			case 'O':
			case 'o':
					nPuzzle.readFromFile();
					nPuzzle.print();
					break;		
			case 'E':
			case 'e':
					nPuzzle.writeToFile();
					nPuzzle.print();
					break;		

		}
		control=nPuzzle.control();
	}
	}
	return 0;
}