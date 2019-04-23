/*
 * Kang-hee Cho
 * CS211
 * 8 Queens Lab: With goto (*****IMPLEMENTED WITH TREMENDOUS AND HEAVY AMOUNT OF INFLUENCE FROM THE LAB SECTION OF THE CLASS (POWERPOINTS)*****)
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
 
int main(){
	//***Board Setup Section***
	int board[8][8] = {0}; //initialize the board
        int row, col, row1, col1; //define all variables
        col = 0;
	board[0][0] = 1; //set the first value to 1 to start the algorithm
        int solutionCounter = 0; //to count the number of solutions to make sure our program is running the way it should (should output 92 distinct solutions)
	//***Board Setup Section***
	next_col:
	//***Column Section***
		col++; //move onto the next column 
		if(col == 8){ //if we have found a solution
			solutionCounter++; //increment the number of solutions we have found
			goto print; //print the solution
		}
		row = -1; //start at the top of the column
	//***column Section***
	next_row:
	//***Row Section***
		row++; //move down a row 
		if(row == 8){ //if we have checked all the spaces in this column, we need to backtrack
			goto backtrack;
		}
		else{ //if we have not checked all the available spaces in this column
			for(int c = 0; c < col; c++){ //check the horizontal for any queens
				if(board[row][c] == 1){
					goto next_row;
				}
			}
			for(int r = 0; r < row; r++){ //check the vertical for any queens
				if(board[r][col] == 1){
					goto next_row;
				}
			}
			row1 = row;
        		col1 = col;
        		while(row1 >= 0 && col1 >= 0){ //row-- col-- until row or col < 0 (upper left diagonal check)
                		if(board[row1][col1] == 1){
                        		goto next_row;
                		}
                		row1--;
                		col1--;
        		}
        		row1 = row;
        		col1 = col;
        		while(row1 < 8 && col1 >= 0){ //row++ col-- until row == 8 or col < 0 (lower left diagonal check)
                		if(board[row1][col1] == 1){
                        		goto next_row;
                		}
                		row1++;
                		col1--;
        		}
			board[row][col] = 1; //if we have managed to make it this far, put a queen down on the space
			goto next_col; //move on to the next column
		}
			
		
	//***Row Section***
	backtrack:
	//***Backtrack Section***
		col--; //go back a column
		if(col == -1){ //if we have backtracked off the grid, the program is done
			std::cout << "There were " << solutionCounter << " distinct solutions to the problem.\n"; //just to make sure
			return 0; //exit the program gracefully
		}
		row = 0; //if the program did not end, start at the top of the column
		while(board[row][col] != 1){ //find the space on the column that the queen resides in 
			row++; 
		}
		board[row][col] = 0; //remove that queen from the board
		goto next_row; //continue on with the algorithm
	//***Backtrack Section***
	print:
	//***Print Section
		for(int r = 0; r < 8; r++){
                	for(int c = 0; c < 8; c++){
                        	std::cout << (board[r][c]);
                	}
                	std::cout << ("\n");
        	}
        	std::cout << ("\n");
        	std::cout << ("\n");
		goto backtrack;
	//***Print Section 

return 0;
}
