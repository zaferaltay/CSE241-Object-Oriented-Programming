#include "board.h"
 
namespace zaff{



void AbstractBoard::setRow(int num){
		row=num;
}	
void AbstractBoard::setColumn(int num){
		column=num;
}		
int AbstractBoard::getRow()const{
			return row;
		}
int AbstractBoard::getColumn()const{
			return column;
		}
int AbstractBoard::getEmptyX()const{
			return empty_x;
		}
int AbstractBoard::getEmptyY()const{
			return empty_y;
		}
void AbstractBoard::setEmptyX(int emmpty_x){
			empty_x=emmpty_x;
		}
void AbstractBoard::setEmptyY(int emmpty_y){
			empty_y=emmpty_y;
		}	
char AbstractBoard::lastMove()const{
		return lastmove;
}		
int AbstractBoard::numberOfMoves()const{
	return total_move;
}
int AbstractBoard::NumberOfBoard()const{
	return numBoard;
}

}