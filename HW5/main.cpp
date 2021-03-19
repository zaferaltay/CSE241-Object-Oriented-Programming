#include "board1d.h" 					
#include "board2d.h"
#include "boardvect.h"


using namespace zaff;

int main(){
	srand(time(0));
	int choice;
	AbstractBoard *abj;

	cout<<"which one do you want to test"<<endl;
	cout<<"1-)BoardArray1D"<<endl;
	cout<<"2-)BoardArray2D"<<endl;
	cout<<"3-)BoardVector"<<endl;
	cin>>choice;
//---------------------------------------------------	TEST1D ARRAY------------------------------------------------------------------------------------------------
	if (choice==1)
	{
		BoardArray1D obj(3,3);
		BoardArray1D obj2(3,3);
		cout<<"We have created 3*3 objects but it is one dmensional array have 9 element"<<endl;
		obj.print();
		cout<<"now we test the movements"<<endl;
		obj.move('l');
		cout<<"moved left if moving"<<endl;
		obj.print();
		obj.move('r');
		cout<<"moved right if moving"<<endl;
		obj.print();
		obj.move('u');
		cout<<"moved up if moving"<<endl;
		obj.print();
		obj.move('d');
		cout<<"moved down if moving"<<endl;
		obj.print();
		cout<<"Your total move="<<obj.numberOfMoves()<<endl;
		cout<<"Now we are testing the writeToFile function.(We write to file that its name abcd.)"<<endl;cout<<endl;
		obj.writeToFile();
		obj.print();
		cout<<"You can control abcd"<<endl;cout<<endl;cout<<endl;
		cout<<"Now we are testing the readFromFile function.(We created the file that its name abc)"<<endl;
		cout<<"By the way we set the file to check the isSolved function"<<endl;cout<<endl;
		obj.readFromFile();
		obj.print();
		cout<<"We also read the file for the other object(obj2) because to test the == operator"<<endl;
		obj2.readFromFile();
		cout<<"We controlling == operator"<<endl;
		if (obj==obj2)
		{
			cout<<"== operator successful"<<endl;
		}
		else{
			cout<<"== operator failed"<<endl;
		}

		cout<<endl;
		cout<<endl;
		cout<<"Now we are testing the () operator.We controlled 3rd row and 2nd column.It must be 8(bcs of abc)"<<endl;cout<<endl;
		cout<< "3. row 2.column element is"<<obj(2,1)<<endl;
		cout<<endl;cout<<endl;

		cout<<"Now we are testing the isSolved function."<<endl;
		cout<<"For this we must first move down then down"<<endl;
		cout<<"Because of abc file"<<endl;cout<<endl;
		obj.move('d');
		cout<<"Last move="<<obj.lastMove()<<endl;
		obj.move('d');
		cout<<"Last move="<<obj.lastMove()<<endl;cout<<endl;cout<<endl;
		cout<<"We did movements.Now we're printing the final version of the screen to the board."<<endl;cout<<endl;
		obj.print();
		cout<<"Now we check the isSolved function"<<endl;cout<<endl;
		if (obj.isSolved())
		{
			cout<<"isSolved function successful.Program will terminated."<<endl;
			cout<<"And your total move="<<obj.numberOfMoves()<<endl;
		}
		else{
			cout<<"isSolved function failed."<<endl;
		}
	}




//----------------------------------------------------TEST 2D ARRAY----------------------------------------------------------------------------------------------------------

	else if(choice==2){
		BoardArray2D obj(3,3);
		BoardArray2D obj2(3,3);
		cout<<"We have created 3*3 objects"<<endl;
		obj.print();
		cout<<"now we test the movements"<<endl;
		obj.move('l');
		cout<<"moved left if moving"<<endl;
		obj.print();
		obj.move('r');
		cout<<"moved right if moving"<<endl;
		obj.print();
		obj.move('u');
		cout<<"moved up if moving"<<endl;
		obj.print();
		obj.move('d');
		cout<<"moved down if moving"<<endl;
		obj.print();
		cout<<"Your total move="<<obj.numberOfMoves()<<endl;
		cout<<"Now we are testing the writeToFile function.(We write to file that its name abcd.)"<<endl;cout<<endl;
		obj.writeToFile();
		obj.print();
		cout<<"You can control abcd"<<endl;cout<<endl;cout<<endl;
		cout<<"Now we are testing the readFromFile function.(We created the file that its name abc)"<<endl;
		cout<<"By the way we set the file to check the isSolved function"<<endl;cout<<endl;
		obj.readFromFile();
		obj.print();
		cout<<"We also read the file for the other object(obj2) because to test the == operator"<<endl;
		obj2.readFromFile();
		cout<<"We controlling == operator"<<endl;
		if (obj==obj2)
		{
			cout<<"== operator successful"<<endl;
		}
		else{
			cout<<"== operator failed"<<endl;
		}

		cout<<endl;
		cout<<endl;
		cout<<"Now we are testing the () operator.We controlled 3rd row and 2nd column.It must be 8(bcs of abc)"<<endl;cout<<endl;
		cout<< "3. row 2.column element is"<<obj(2,1)<<endl;
		cout<<endl;cout<<endl;

		cout<<"Now we are testing the isSolved function."<<endl;
		cout<<"For this we must first move down then down"<<endl;
		cout<<"Because of abc file"<<endl;cout<<endl;cout<<endl;
		obj.move('d');
		cout<<"Last move="<<obj.lastMove()<<endl;
		obj.move('d');
		cout<<"Last move="<<obj.lastMove()<<endl;cout<<endl;cout<<endl;
		cout<<"We did movements.Now we're printing the final version of the screen to the board."<<endl;cout<<endl;
		obj.print();
		cout<<"Now we check the isSolved function"<<endl;cout<<endl;
		if (obj.isSolved())
		{
			cout<<"isSolved function successful.Program will terminated."<<endl;
			cout<<"And your total move="<<obj.numberOfMoves()<<endl;
		}
		else{
			cout<<"isSolved function failed."<<endl;
		}
	}


//------------------------------------------------TEST 3D ARRAY----------------------------------------------------------------------------------------------------------------------------

	else if(choice==3){
		BoardVector obj(3,3);
		BoardVector obj2(3,3);
		cout<<"We have created 3*3 objects"<<endl;
		obj.print();
		cout<<"now we test the movements"<<endl;
		obj.move('l');
		cout<<"moved left if moving"<<endl;
		obj.print();
		obj.move('r');
		cout<<"moved right if moving"<<endl;
		obj.print();
		obj.move('u');
		cout<<"moved up if moving"<<endl;
		obj.print();
		obj.move('d');
		cout<<"moved down if moving"<<endl;
		obj.print();
		cout<<"Your total move="<<obj.numberOfMoves()<<endl;
		cout<<"Now we are testing the writeToFile function.(We write to file that its name abcd.)"<<endl;cout<<endl;
		obj.writeToFile();
		obj.print();
		cout<<"You can control abcd"<<endl;cout<<endl;cout<<endl;
		cout<<"Now we are testing the readFromFile function.(We created the file that its name abc)"<<endl;
		cout<<"By the way we set the file to check the isSolved function"<<endl;cout<<endl;
		obj.readFromFile();
		obj.print();
		cout<<"We also read the file for the other object(obj2) because to test the == operator"<<endl;
		obj2.readFromFile();
		cout<<"We controlling == operator"<<endl;
		if (obj==obj2)
		{
			cout<<"== operator successful"<<endl;
		}
		else{
			cout<<"== operator failed"<<endl;
		}

		cout<<endl;
		cout<<endl;
		cout<<"Now we are testing the () operator.We controlled 3rd row and 2nd column.It must be 8(bcs of abc)"<<endl;cout<<endl;
		cout<< "3. row 2.column element is"<<obj(2,1)<<endl;
		cout<<endl;cout<<endl;

		cout<<"Now we are testing the isSolved function."<<endl;
		cout<<"For this we must first move down then down"<<endl;
		cout<<"Because of abc file"<<endl;cout<<endl;cout<<endl;
		obj.move('d');
		cout<<"Last move="<<obj.lastMove()<<endl;
		obj.move('d');
		cout<<"Last move="<<obj.lastMove()<<endl;cout<<endl;cout<<endl;
		cout<<"We did movements.Now we're printing the final version of the screen to the board."<<endl;cout<<endl;
		obj.print();
		cout<<"Now we check the isSolved function"<<endl;cout<<endl;
		if (obj.isSolved())
		{
			cout<<"isSolved function successful.Program will terminated."<<endl;
			cout<<"And your total move="<<obj.numberOfMoves()<<endl;
		}
		else{
			cout<<"isSolved function failed."<<endl;
		}
	}





}
