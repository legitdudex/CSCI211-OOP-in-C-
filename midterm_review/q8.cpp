
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;


int exp(int x, int n){
	if(n == 0){
		return 1;
	}
	return x * exp(x, n - 1);
}

void print(char* s){
	if(*s == 0){
		return;
	}
	cout << *s;
	print(s + 1);

}

void rev_print(char* s){
	if(*s == 0){
		return;
	}
	print(s + 1);
	cout << *s;
}

int  main(){
	char a[100];
	cin >> a;
	rev_print(a);
	return 0;
}


