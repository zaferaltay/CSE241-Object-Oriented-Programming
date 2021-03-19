#include "npuzzle.h"

int main(int argc, char const *argv[])
{
	srand(time(0));
	char choice;



	if (argc==1)
	{
	NPuzzle nPuzzle;
	cout<<nPuzzle;
	

	bool control=false;
	while(control!=true){
	cout<<"V-) Solves the problem"<<endl;
	cout<<"T-) Prints a report"<<endl;
	cout<<"O-) Asks a file name and loads the current board"<<endl;
	cout<<"E-) Asks a file name and saves the current board"<<endl;
	cout<<"R-L-U-D Moves empty cell"<<endl;
	cout<<"S-) Shuffle the board"<<endl;
		cin>>choice;
		switch(choice){

			case 'L':
			case 'l':
					nPuzzle.move('l');
					cout<<nPuzzle;
					break;
			case 'R':
			case 'r':
					nPuzzle.move('r');
					cout<<nPuzzle;
					break;						
			case 'U':
			case 'u':
					nPuzzle.move('u');
					cout<<nPuzzle;
					break;
			case 'D':
			case 'd':
					nPuzzle.move('d');
					cout<<nPuzzle;
					break;																				
					//----------------------------------------------------------------------------------------
			case 'S':
			case 's':

					nPuzzle.shuffle(nPuzzle.getRow2()*nPuzzle.getColumn2());
					cout<<nPuzzle;
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
					cin>>nPuzzle;
					nPuzzle.print();
					break;		
			case 'E':
			case 'e':
					nPuzzle.writeToFile();
					cout<<nPuzzle;
					break;		

		}
		control=nPuzzle.control();
	}
}



else{
		NPuzzle nPuzzle(argv[1]);		//Constructor with string
		nPuzzle.print();

	bool control=false;
	while(control!=true){
	cout<<"V-) Solves the problem"<<endl;
	cout<<"T-) Prints a report"<<endl;
	cout<<"O-) Asks a file name and loads the current board"<<endl;
	cout<<"E-) Asks a file name and saves the current board"<<endl;
	cout<<"R-L-U-D Moves empty cell"<<endl;
	cout<<"S-) Shuffle the board"<<endl;
		cin>>choice;
		switch(choice){

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
					cin>>nPuzzle;
					nPuzzle.print();
					break;		
			case 'E':
			case 'e':
					nPuzzle.writeToFile();
					cout<<nPuzzle;
					break;		

		}
		control=nPuzzle.control();
	}


}


	return 0;
}