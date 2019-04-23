

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	int i = 4;
	while(true){
		int perfSquare = i * i;
		int firstDigit = perfSquare % 10;
		int secondDigit = (((perfSquare % 100) / 10) - (firstDigit / 10));
		if(firstDigit % 2 != 0 && secondDigit % 2 != 0){
			cout << perfSquare;
			break;
		}
		else{
			i++;
		}
	}	


return 0;
}
