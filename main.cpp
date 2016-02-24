#include<iostream>
#include"bigint.h"

using std::cout;
using std::endl;

int main()
{
	//todo: operator <, <=, >, >=
	//		namespace
	//		+(-x)
	//std::stoi("74");

	bigint bi1(200), bi2(803);
	std::deque<int> d = {4,0,0};

	bi1 = d;
	cout << bi1+d << endl;
	
	

	return 0;
}
