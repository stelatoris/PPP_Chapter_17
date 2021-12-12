//	PPP Chapter 17 Ex 08
//	8. Do exercise 7 again, but this time read into a std::string rather than to
//	memory you put on the free store(string knows how to use the free store
//	for you).

#include "std_lib_facilities.h"


int main()
try {	
	
	std::cout << "Please enter a series of characters ending with '!'\n";
	
	std::string my_string;
	char ch;

	while (cin>>ch && ch!='!') {
		my_string.push_back(ch);
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