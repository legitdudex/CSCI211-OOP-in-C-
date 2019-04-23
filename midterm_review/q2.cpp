
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

bool leapyear(int y){
	if((y % 100) == 0){
		if((y % 400) == 0){
			return true;
		}
	}
	else{
		if((y % 4) == 0){
			return true;
		}
	}
	return false;
}

int main(){
	int y;
	
	while(true){
		cout << "Enter the year (Enter 0 to quit): ";
		cin >> y;
		cout << "\n";
		if(y == 0){
			break;
		}
		bool isLeapYear = leapyear(y);
		if(isLeapYear){
			cout << "The year " << y << " is indeed a leap year.\n";
		}
		else{
			cout << "The year " << y << " is not a leap year.\n";
		}
		
	}
	return 0;
}
