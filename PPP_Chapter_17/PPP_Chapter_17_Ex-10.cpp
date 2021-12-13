//	PPP Chapter 17 Ex 10
//10. Look at your solution of exercise 7. Is there any way that input could
//get the array to overflow; that is, is there any way you could enter more
//characters than you allocated space for (a serious error) ? Does anything
//reasonable happen if you try to enter more characters than you allocated ?

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

	char c1[]{ "string" };
	std::cin >> c1;
	std::cout << '\n';
	std::cout << c1 << '\n';
	std::cout << '\n';
	
	//char* my_string = new char[1];
	//*my_string = 0;

	//char ch;
	//int array_size{};
	//while (cin >> ch && ch != '!') {
	//	my_string = expand_array(my_string);
	//	int n = 0;
	//	for (int i = 0; my_string[n]; ++i) {
	//		n = i;
	//	}
	//	my_string[n] = ch;
	//	my_string[n+1] = '-';	// added extra char to overflow
	//	my_string[n + 2] = 0;	//
	//}

	//cout << my_string << '\n';

	return 0;
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}