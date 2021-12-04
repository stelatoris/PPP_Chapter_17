// PPP Chapter 17 Drill Ex 02
#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i) {
		os << a[i];
		if (i == n-1) { cout << '\n'; break; }
		else cout << ',';
	}
}

int main()
try {
	//01
	int n1{ 7 };
	int* p1 = &n1;

	//02
	cout << "Value of p1 is:" << p1 << '\n';

	//03
	int* p2 = new int[7];

	for (int i = 0; i < 7; ++i) {
		p2[i] = pow(2, i);
	}

	//04
	cout << "Value of p2 is:" << p2 << '\n';
	cout << "Value of p2 pointed array is:";
	print_array(cout, p2, 7);

	//05
	int* p3 = p2;
	cout << "Value of p3 is:" << p3 << '\n';

	//06
	p2 = p1;
	cout << "Value of p2 is:" << p2 << '\n';

	//07
	p2 = p3;

	//08
	cout << "Value of p1 is:" << p1 << '\n';
	cout << "Value of p2 is:" << p2 << '\n';

	//09
	delete[]p2;
	
	cout << "Value of p2 is:" << p2 << '\n';
	//10
	p1 = new int[10];
	for (int i = 0; i < 10; ++i) {
		p1[i] = pow(2, i);
	}

	cout << "Value of p1 is:" << p1 << '\n';
	cout << "Value of p1 pointed array is:";
	print_array(cout, p1, 10);

	//11
	p2 = new int[10];
	cout << "Value of p2 is:" << p2 << '\n';

	//12
	for (int i = 0; i < 10; ++i) {
		p2[i] = p1[i];
	}
	cout << "Value of p2 pointed array is:";
	print_array(cout, p2, 10);

	//13
	vector<int> v1;
	for (int i = 0; i < 10; ++i) {
		v1.push_back(pow(2, i));
	}	

	vector<int>* p = new vector<int>;
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}