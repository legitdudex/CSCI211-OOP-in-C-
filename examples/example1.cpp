
#include <iostream>
using namespace std;
int main(){
	int b[5][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
	cout << sizeof(b) << endl;
	cout << sizeof(b + 0) << endl;
	cout << sizeof(*(b + 0)) << endl;
	cout << "The address of b is: " << b << endl;
	cout << "The address of b + 0 is " << b + 0 << endl;
	cout << "The address of b + 1 is " << b + 1 << endl;
	cout << "The address of &b is " << &b << endl;
	cout << "The address of &b + 1 is " << &b + 1 << endl;
	cout << **b << endl;
	cout << *(*b + 1) << endl;
	cout << *(*(b + 1) + 1) << endl;
	return 0;
}

