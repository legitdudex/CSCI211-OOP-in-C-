
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;


bool isValid(int configuration[]){
	for(int c = 0; c < 8; c++){ //check every column
		for(int c1 = c+1; c1 < 8; c1++){ //check every other column for that column
			if(configuration[c] == configuration[c1] || (c1 - c) == abs(configuration[c1] - configuration[c])){
				return false;
			}
		}
	}
	return true;
} 


int main(){
	string input;
	cout << "Enter a valid input for the 8 queens configuration (8 integers): ";
	cin >> input;
	cout << "\n";
	
	int size = input.size();
	int configuration[8];
	for(int i = 0; i < size; i++){
		configuration[i] = input[i];
	}
	
	bool valid;
	valid = isValid(configuration);
	if(valid){
		cout << "This is indeed a valid configurations for the 8 queens problem\n";
	}
	else{
		cout << "This is not a valid configuration for the 8 queens problem\n";
	}

	return 0;
}
