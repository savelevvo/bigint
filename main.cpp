#include<iostream>
#include"bigint.h"

using std::cout;
using std::endl;

int main()
{
	//todo: operator <, <=, >, >=
	//		namespace
	//		+(-x), negative numbers
	//		check() is number correct
	//std::stoi("74");

	bigint bi1(-500), bi2(100);
	std::deque<int> d1 = { -2, 0 };
	//std::deque<int> d2 = { 4, 9, 9 };
	std::string s = "-123";
	
	bi1 = s;
	
	cout << bi1 << endl;
	
	

	return 0;
}
