// PPP Chapter 17 Ex 02
//2. How many bytes are there in an int ? In a double ? In a bool ? Do not use
//sizeof except to verify your answer.

#include "std_lib_facilities.h"


int main()
try {

	int* pi = new int(0);

	pi = new int[2];
	pi[0] = 1;
	pi[1] = 2;

	cout << "pi[0]: " <<(int)&pi[0] << '\n';
	cout << "pi[1]: " <<(int)&pi[1] << '\n';
	cout << "size of pi :" << (int)&pi[1] - (int)&pi[0] << '\n';
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}