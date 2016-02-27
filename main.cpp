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

	bigint bi1(10), bi2(0);
	std::deque<int> d1 = { 1, 0 };
	std::string s = "-123";
	
	cout << (bi1 >= bi2)<< endl;
	
	return 0;
}
