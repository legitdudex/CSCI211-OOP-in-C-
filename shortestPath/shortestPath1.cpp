
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;
const int rows = 5;
const int cols = 6;
static int pathLog[30] = {0};

/*
 * Parameters:
 * 	i: The row number
 * 	j: The col number
 *
 */
int cost(int i, int j){
	int weight[rows][cols] = {
		{3, 4, 1, 2, 8, 6},
		{6, 1, 8, 2, 7, 4},
		{5, 9, 3, 9, 9, 5},
		{8, 4, 1, 3, 2, 6},
		{3, 7, 2, 8, 6, 4}};
	//base case
	if(j == 0){
		pathLog[(i * 6)] = weight[i][0];
		return weight[i][0];
	}
	if(pathLog[((i * 6) + j)] != 0){
		return pathLog[((i * 6) + j)];
	}
	
	//recursive call
	int left = weight[i][j] + cost(i, j - 1); //the weight of the box to the left is the cost of the current box + the cost of the box to it's left
	int up = weight[i][j] + cost(((i - 1 + rows) % rows), j - 1); //the weight of the box to the upper left is the cost of the current box + the cost of the box to it's upper left
	int down = weight[i][j] + cost(((i + 1) % rows), j - 1); //the weight of the box to the lower left is the cost of the current box + the cost of the box to it's lower left

	//find the value of the shortest path through cell (i, j)
	int min;
	if((left < up) && (left < down)){
		min = left;
	}
	else if((up < left) && (up < down)){
		min = up;
	}
	else{
		min = down;
	}
	int newI = i;
	if(i == 0 && j != 0){
		pathLog[j] = min;
	}
	else{
		pathLog[((newI * 6) + j)] = min;
	}	
	return min;
}

int main(){
	int ex[rows];
	int shortestRow = 0; //to store the starting row to the shortest path so we can print the path later

	//get the shortest path out of rach cell on the right
	for(int i = 0; i < rows; i++){
		ex[i] = cost(i, cols - 1);
	}
	//now find the smallest of them
	int min = ex[0];
	for(int i = 1; i < rows; i++){
		if(ex[i] < min){
			min = ex[i];
			shortestRow = i;
		}
	}
	
	for(int i = 0; i < 30; i++){
		cout << pathLog[i] << ", ";
		if(((i + 1) % 6) == 0){
			cout << "\n";
		}

	}
	cout << "\n";
	cout << "The shortest path is of length: " << min << "\n";
	system("PAUSE");
	return EXIT_SUCCESS;
} 
