// PPP Chapter 17 Ex 03
//3. Write a function, void to_lower(char* s), that replaces all uppercase characters
//in the C - style string s with their lowercase equivalents.For example,
//Hello, World!becomes hello, world!.Do not use any standard
//library functions.A C - style string is a zero - terminated array of characters,
//so if you find a char with the value 0 you are at the end.

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