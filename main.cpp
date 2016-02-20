#include<iostream>
#include"bigint.h"

using std::cout;
using std::endl;

int main()
{
	//std::stoi("s");
	bigint bi1(102), bi2(506);
	
	//+900, +(-10)
	
	std::string s1;
	s1 = bi1.dtos();
	cout << s1 << endl;


	return 0;
}
