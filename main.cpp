#include<iostream>
#include"bigint.h"

int main(int argc, char** argv)
{
	using std::cout;
	using std::endl;

	//todo:
	//	namespace
	//	check() is number correct
	//std::stoi("74");

	bigint bi1 = argv[1];
	bigint bi2 = argv[2];
	
	int i1 = std::stoi(argv[1]);
	int i2 = std::stoi(argv[2]);
	
	if ((bi1 + bi2) != (i1 + i2))
	{
		cout << "Error!" << endl;
		cout << "Arguments: " << bi1 << ", " << bi2 << endl;
	}

	return 0;
}
