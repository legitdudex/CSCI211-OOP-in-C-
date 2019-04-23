
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;
int main(){
	int i, j ,k;
	for(i = 0; i <= 5; i++){
		for(j = 0; j <= 5; j++){
			for(k = 0; k <= 5; k++){
				if(( i + j + k) == 15){
					if((i < j) && (j < k)){
						cout << i << j << k << "\n";
					}
					else if(i == j == k){
						cout << i << j << k << endl;
					}
				}
			}
		}
	}
	return 0;
}
						
