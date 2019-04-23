/*
 * Kang-hee Cho
 * CS211
 * 8 Queens Lab: Recursive approach 
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>

int globl_size;
/*
 * This board checks the queen's territory for any other queens.
 * Have to check:
 * 	1) Row -1 Col -1 for 1's iteratively until col# or row# < 0
 * 	2) Row -1 Col +1 for 1's iteratively until col# == 8 or row# < 0 
 * 	3) Row +1 Col -1 for 1's iteratively until col# < 0 or row# == 8
 * 	4) Row +1 Col +1 for 1's iteratively until col# or row# == 8
 * 	5) All spaces in that row for a 1
 * 	6) All spaces in that col for a 1
 */
bool checkValid(int board[8][8], int row, int col){
	int r, c; //need to save the queen's coordinates
	r = row;
	c = col;
	while(r >= 0 && c >= 0){ //row-- col-- until row or col < 0 (upper left diagonal check)
		if(board[r][c] == 1){
			return false;
		}
		r--;
		c--;
	}
	r = row;
	c = col;
	while(r < 8 && c >= 0){ //row++ col-- until row == 8 or col < 0 (lower left diagonal check)
		if(board[r][c] == 1){
			return false;
		}
		r++;
		c--;
	}
	for(r = 0; r < 8; r++){ //check the row for any queens (row check)
		if(board[r][col] == 1){
			return false;
		}
	}
	for(c = 0; c < 8; c++){ //check the column for any queens (col check)
		if(board[row][c] == 1){
			return false;
		}
	}

	//we are now finished checking. If the program made it this far, it means that 
	//the queen in question can indeed be placed on the spot marked row, col 
	return true;
}

/*
 * This function fills the space (row, col) on the board with a queen if it is a valid location.
 */
bool fillQueen(int (&board)[8][8], int row, int col){
	bool valid = checkValid(board, row, col);
	if(valid){
		board[row][col] = 1;
		return true;
	}
	return false;
}

/*
 * This function removes the queen at the loaction (row, col) on the board.
 */
void removeQueen(int (&board)[8][8], int row, int col){
	board[row][col] = 0;
}


/*
 * This function prints the current contents of the board.
 * It takes an 8 by 8 integer array and prints them per row.
 */ 
void printBoard(int* board, size){
	int r, c;
	for(r = 0; r < size; r++){
		for(c = 0; c < size; c++){
			std::cout << (board[r][c]);
		}
		std::cout << ("\n");
	}
	std::cout << ("\n");
	std::cout << ("\n");
}

/*
 * This is the backtrack function.
 * Basically, all it does is decrement the col, remove the queen in the col, and set the row to the next row to continue the algorithm
 *
 * In a case where the queen in the column behind us where we want to backtrack is in row 7, then r++ would be detrimental to the program since
 * 	that would basically break it by going out of bounds. We can counter this flaw by calling backTrack on itself when the queen found in the
 * 	column we want to backtrack to exists in row 7.
 */
void backTrack(int (&board)[8][8], int &row, int &col, int &numberQueensFilled){
	col--; //move to the previous column
	if(col != -1){ //after moving back a column, if we are off the board, then the program has ended and there is no need to do the following
		for(int r = 0; r < 8; r++){
			if(board[r][col] == 1){ //we found the queen in the previous col
				removeQueen(board, r, col); //remove the queen from the space on the board
				numberQueensFilled--; //decrement the number of queens on the board
				row = r; //set the row number to that of which we found the queen in
				break; //end the loop
			}
		}
		if(row == 7){ //if we have exhausted all our possible configurations for this column, backtrack again
			backTrack(board, row, col, numberQueensFilled);
		}
		else{ //we did not find the previous queen in the last row of the column, so we are good to move onto the next row
			row++;
		}	
	}
	//at this point, we should have backtracked to the previous column, removed the queen in the previous column, and set our row coordinate to that of 
	//	the last queen's position + 1 to move on with the algorithm.	
}

void getUserInput(int* inputArr){
	std::cout << "Please enter the board size (nXn) n =";
	std::cin >> inputArr[0];
	std::cout << "\nPlease enter the number of bishops to fill the board with where k <= n. k =";
	std::cin >> inputArr[1];
	std::cout << "\n";
	if(inputArr[0] < inputArr[1]){
		std::cout << "Invalid input: k, the number of bishops was greater than n, the size of the board\n";
		std::cout << "Please enter new and valid values for k and n where k <= n.\n";
		getUserInput(inputArr);
	}
}

/*
 * This is the main function of the program. This is where all of the program's
 * variables are declared and where all the functions are called.
 *
 * This particular implementation of 8 queens does not use goto statements.
 */
int main(){
	int n[2];
	getUserInput(n);
	globl_size = n[0];	

	int board[n[0]][n[0]] = {0}; //initialize the board
	int row, col, numberBshopsFilled;
	bool isFilledCol;
	numberBishopsFilled = 0; //to keep track of the number of queens placed on the board
	row = 0;
	col = 0;
	int solutionCounter = 0;
	while(col != -1){ //if the column number is -1, this means the program backtracked completely and we have tried all the possible variations
		isFilledCol = fillQueen(board, row, col); //isFilledCol will hold true if the fill was successful
		if(isFilledCol){ //we were able to successfully place a queen in a row in this col
			numberBishopsFilled++; //increment the queens counter
			if(col == (n[0] - 1)){ //if a solution was found
				printBoard(board, n[0]); //print the board
				solutionCounter++;
				removeQueen(board, row, col); //remove the last queen we put in to get the solution to backtrack
				numberBishopsFilled--;
				if((n[0] - 1) == 7){ //if we are on the last row in the last column, we need to backtrack
					backTrack(board, row, col, numberBishopsFilled);
				}
				else{
					row++; //move on with the algorithm
				}
					
			}
			else{ //if a solution was not found after placing a queen down in this column
				col++; //move on to the next column
				row = 0; //start at the top of the row of the next column
			}
		} //end of the first if statement
		else{//the column was not filled yet
			if(row == (n[0] - 1)){ //if we are on the last row and the last space was not valid, we need to backtrack
				backTrack(board, row, col, numberBishopsFilled);		
			}
			else{ //we are not on the last row so just move on to the next row and continue our algorithm
				row++; //move on to the next row
			}
		} //end of the first else statement
	}
	std::cout << "There were " << solutionCounter << " distinct solutions to this problem.\n";
return 0;
}
