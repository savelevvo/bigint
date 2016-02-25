#include<iostream>
#include"bigint.h"

using std::cout;
using std::endl;

int main()
{
	//todo: operator <, <=, >, >=
	//		namespace
	//		+(-x), negative numbers
	//std::stoi("74");

	bigint bi1(200), bi2(4);
	std::deque<int> d = {5,0,0};
	std::string s = "100";
	
	
	cout << bi1 - s << endl;
	
	

	return 0;
}
