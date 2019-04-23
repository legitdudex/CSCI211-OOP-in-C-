
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;


void rightShift(int arr[]){
	int i, temp, temp1, size;
	size = 5;
	temp = arr[size - 1];
	for(i = 0; i < size; i++){
		temp1 = arr[i];
		arr[i] = temp;
		temp = temp1;
	}
}

bool equivalent(int arr1[], int arr2[]){
	int i;
	for(i = 0; i < 5; i++){
		if(arr1[i] != arr2[i]){
			return false;
		}
	}
	return true;
}


int main(){
	int arr1[5] = {1, 2, 3, 4, 5};
	int arr2[5] = {2, 4, 4, 5, 1};
	bool isEq = false;
	for(int i = 0; i < 5; i++){
		if(equivalent(arr1, arr2)){
			isEq = true;
		}
		else{
			rightShift(arr2);
		}
	}
	if(isEq){
		cout << "The arrays are equivalent\n";
	}
	else{
		cout << "The arrays are not equivalent\n";
	}
	return 0;

}


