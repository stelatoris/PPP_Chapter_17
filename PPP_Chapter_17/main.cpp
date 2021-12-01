// PPP Chapter 17 Drill Ex 02
#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int n)
{
	for(int i=0;i<n;++i){
		os<<a[i]<<'\n';
	}
}

int main()
try {
	int n1{7};
	
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}