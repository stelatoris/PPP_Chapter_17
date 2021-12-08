// PPP Chapter 17 Ex 04
//4. Write a function, char* strdup(const char*), that copies a C - style string
//into memory it allocates on the free store.Do not use any standard library
//functions.

#include "std_lib_facilities.h"

void to_lower(char* s)
{
	char ch=' ';
	int i{ 0 };
	while (ch != 0) {
		if ('A'<= s[i]&& s[i]<='Z') {
			s[i] = s[i] + 32;
		}
		ch = s[i];
		cout << s[i];
		++i;
	}
}

int main()
try {	
	char s[]{ "Hello, world!" };
	to_lower(s);	
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}