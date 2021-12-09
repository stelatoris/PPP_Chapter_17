// PPP Chapter 17 Ex 04
//4. Write a function, char* strdup(const char*), that copies a C - style string
//into memory it allocates on the free store.Do not use any standard library
//functions.

#include "std_lib_facilities.h"

char* my_strdup(const char* c)
{
	if (!c) return nullptr;

	int n{ 0 };;
	while (c[n]) {
		++n;
	}

	char* ch = new char[n];
	for (int i = 0; i < n + 1; ++i) {
		ch[i] = c[i];
	}
	ch[n] = 0;
	return ch;
}

int main()
try {
	const char* s{ "Hello, world!" };
	char* cstring = my_strdup(s);

	cout << "cstring: " << cstring << '\n';;
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}