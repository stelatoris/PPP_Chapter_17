//	PPP Chapter 17 Ex 06
//6. This chapter does not say what happens when you run out of memory
//using new.That’s called memory exhaustion.Find out what happens.You have
//two obvious alternatives : look for documentation, or write a program with
//an infinite loop that allocates but never deallocates.Try both.Approximately
//how much memory did you manage to allocate before failing ? .

#include "std_lib_facilities.h"

int main()
try {	
	int count{};

	while (true) {
		double* d = new double[99999];
		count += sizeof(*d);
		std::cout << count << '\n';
	}

	return 0;
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}