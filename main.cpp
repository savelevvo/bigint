#include<iostream>
#include"bigint.h"
#include"Test\test.h"

int main(int argc, char** argv)
{
	//todo:
	//	namespace
	//	check() is number correct
	//std::stoi("74");
	
	if (argc > 1) START_TEST(argv);

	bigint b1(13), b2(1);
	std::deque<int> d1 = { 2, 1 };
	bigint b3 = b1 * d1;
	
	std::cout << b3[0] << std::endl;
	
	
	
	
	return 0;
}
