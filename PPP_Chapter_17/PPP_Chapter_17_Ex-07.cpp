//	PPP Chapter 17 Ex 07
//7. Write a program that reads characters from cin into an array that you
//allocate on the free store.Read individual characters until an exclamation
//mark(!) is entered.Do not use a std::string.Do not worry about memory
//exhaustion.

#include "std_lib_facilities.h"

char* expand_array(const char* s)
{
	if (!s) return nullptr;
	if (s == 0) return 0;

	// get number of chars
	int n{ 0 };
	while (s[n] != 0) {
		++n;
	}
	char* temp = new char[n + 2];

	for (int i = 0; s[i]; ++i) {
		temp[i] = s[i];
	}
	temp[n] = 0;

	delete[] s;

	return temp;
}

int main()
try {	
	
	std::cout << "Please enter a series of characters ending with !\n";
	
	char* my_string = new char[1];
	*my_string = 0;

	char ch;
	int array_size{};
	while (cin>>ch && ch!='!') {
		my_string = expand_array(my_string);		
		int n = 0;
		for (int i = 0; my_string[n]; ++i) {
			n = i;
		}
		my_string[n] = ch;
		my_string[n + 1] = 0;
	}

	cout << my_string << '\n';
	
	return 0;
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}