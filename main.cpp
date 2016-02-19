#include<iostream>
#include"bigint.h"

using std::cout;
using std::endl;

int main()
{
	//std::stoi("s");



	bigint bi1(102), bi2(506);
	

	//+900, +(-10)
	cout << bi1.pop_back() << endl;
	cout << bi1.pop_back() << endl;
	cout << bi1.pop_back() << endl;

	//cout << bi1 << endl;

	return 0;
}
