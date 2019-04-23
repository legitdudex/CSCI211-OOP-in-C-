
#include <iostream>
#include <cmath>

int main(){
	int i, perfectSquare, lastDigit, secondLastDigit;
	for(i = 1; i > 0; i++){
		perfectSquare = i * i;
		lastDigit = perfectSquare % 10;
		secondLastDigit = (((perfectSquare % 100) / 10) - (lastDigit / 10));
		if((lastDigit % 2) != 0){
			if((secondLastDigit % 2) != 0){
				std::cout << perfectSquare;
				std::cout << "\n";
				return perfectSquare;
			}
		}
	}
	

}


