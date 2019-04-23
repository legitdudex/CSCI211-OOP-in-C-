
#include <iostream>
#include <list>
/*
 * This function takes:
 * a[]: A list of integers containing n elements
 * b[]: A second list of integers containing n elements
 * n: The number of elements
 *
 * And returns:
 * True: If the two lists are shift-equivalent 
 * False: If the two lists are not shift-equivalent
 * */
bool equivalent(int a[], int b[], int n){
	list<int> aShifted;
	int iterations;
	if(a != b){
		for(iterations = 0; iterations < n; iterations++){
			aShfited = rightShift(a, n);
			a = aShifted;
			if(a == b){
				return true;
			}
		}
	} 
	return false;
}

list<int> rightShift(int a[], n){
	int index, indexReturn;
	int returnLst[n];
	indexReturn = 1;
	for(index = 0; index < (n - 1); index++){
		returnLst[indexReturn] = a[index];
		indexReturn ++;
	}
	n--;
	returnLst[0] = a[n];
	return returnLst;
}


int main(){
        bool isEquivalent;
        isEquivalent = equivalent((1, 2, 3, 4, 5), (1, 2, 3, 4, 5), 5);
        if(isEquivalent == true){
                std::cout << ("The arrays are shift equivalent\n");
        }
        else{
                std::cout << ("The arrays are not shift equivalent\n");
        }
        return 0;
}

