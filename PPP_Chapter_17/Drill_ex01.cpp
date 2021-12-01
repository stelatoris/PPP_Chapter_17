// PPP Chapter 17 Drill Ex 01
#include "std_lib_facilities.h"

//04
void print_array10(ostream& os, int* a)
{
	for(int i=0;i<10;++i){
		os<<a[i]<<'\n';
	}
}

//07
void print_array(ostream& os, int* a, int n)
{
	for(int i=0;i<n;++i){
		os<<a[i]<<'\n';
	}
}

//10
void print_vector(ostream& os, const vector<int>& v)
{
	for(int i=0;i<v.size();++i){
		os<<v[i]<<'\n';
	}
}

int main()
try {
	
	//01
	int ar1_size=10;
	int* ar1=new int[ar1_size]{0,1,2,3,4,5,6,7,8,9};
	//02
	cout<<"Drill Part1 - 02"<<'\n';
	for(int i=0;i<ar1_size;++i){
		cout<<ar1[i]<<'\n';
	}
	//03
	delete[] ar1;

	//05
	int* ar2=new int[10];
	for(int i=0;i<10;++i){
		ar2[i]=100+i;
	}
	cout<<"Drill Part1 - 05"<<'\n';
	print_array10(cout, ar2);
	delete[] ar2;

	//06
	int* ar3=new int[11];
	for(int i=0;i<11;++i){
		ar3[i]=100+i;
	}
	cout<<"Drill Part1 - 06"<<'\n';
	for(int i=0;i<11;++i){
		cout<<ar3[i]<<'\n';
	}
	delete[] ar3;

	//08
	int* ar4=new int[20];
	for(int i=0;i<20;++i){
		ar4[i]=100+i;
	}
	cout<<"Drill Part1 - 07"<<'\n';
	print_array(cout,ar4,20);
	delete[] ar4;

	//10

	vector<int>v1;
	for(int i=0;i<10;++i){
		v1.push_back(100+i);
	}
	cout<<"Drill Part1 - 10"<<'\n';
	print_vector(cout,v1);

	
	vector<int>v2;
	for(int i=0;i<11;++i){
		v2.push_back(100+i);
	}
	cout<<'\n';
	print_vector(cout,v2);

	vector<int>v3;
	for(int i=0;i<20;++i){
		v3.push_back(100+i);
	}
	cout<<'\n';
	print_vector(cout,v3);
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}