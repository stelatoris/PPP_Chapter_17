//	PPP Chapter 17 Ex 05
//	5. Write a function, char* findx(const char* s, const char* x), that finds the
//	first occurrence of the C - style string x in s.
// Thank you Yabe for the help!

#include "std_lib_facilities.h"

const char* findx(const char* s, const char* x)
{
	//find x in s
	if (!s||!x) return nullptr;

	for (int i{}; s[i]; ++i) {
		if (s[i] == x[0]) {
			int j{};
			while (x[j]) {
				if (s[i] != x[j]) break;
				++i;
				++j;
			}

			if (x[j] == '\0')
				return &s[i - j];
		}		
	}

	return nullptr;
}

int main()
try {
	const char* s = "Pointers are difficult to understand!";
	const char* x = " are";

	const char* sub = findx(s, x);

	if (!sub) std::cout << "Not found!\n";
	
	else std::cout << sub << '\n';	

	return 0;
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}