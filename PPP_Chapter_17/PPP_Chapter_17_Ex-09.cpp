//	PPP Chapter 17 Ex 09
//  9. Which way does the stack grow : up(toward higher addresses) or down(toward
//  lower addresses) ? Which way does the free store initially grow(that
//  is, before you use delete) ? Write a program to determine the answers.

#include "std_lib_facilities.h"

std::string growth_direction(int* i1, int* i2, int* i3)
{
	int up_count{ 0 };
	int down_count{ 0 };
	if (i2 - i1 > 0) ++up_count;
	if (i3 - i2) ++up_count;

	if (i2 - i1 < 0) ++down_count;
	if (i3 - i2 < 0) ++down_count;

	if(up_count==2) return " grows up\n";
	if(down_count==2) return " grows down\n";
	return " grows both up and down\n";		
}

int main()
try {
	
	//Direction of stack growth
	int i1{ 1 }, i2{ 2 }, i3{ 3 };
	std::cout << "Stack memory adresses:\n"
		<< &i1 << '\n'
		<< &i2 << '\n'
		<< &i3 << '\n';
	std::cout <<"Stack memory"<< growth_direction(&i1, &i2, &i3) << '\n';

	//Direction of heap growth

	int* p1 = new int{ 1 };
	int* p2 = new int{ 2 };
	int* p3 = new int{ 3 };
	std::cout << "Free store memory adresses:\n"
		<< p1 << '\n'
		<< p2 << '\n'
		<< p3 << '\n';
	std::cout <<"Heap memory"<< growth_direction(p1, p2, p3) << '\n';
	delete p1;
	delete p2;
	delete p3;
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}