#include<iostream>
#include"bigint.h"

void TEST(char**);

int main(int argc, char** argv)
{
	//todo:
	//	namespace
	//	check() is number correct
	//std::stoi("74");
	
	if (argc > 1) TEST(argv);

	//bigint b1(-6), b2(-7);
	//bigint b3 = b1 - b2;
	//std::cout << b3 << std::endl;
	return 0;
}

void TEST(char** args)
{
	bigint bi1 = args[1], bi2 = args[2];
	bigint sum_result1, diff_result1;

	int i1 = std::stoi(args[1]), i2 = std::stoi(args[2]);;
	int sum_result2, diff_result2;

	sum_result1 = bi1 + bi2;
	sum_result2 = i1 + i2;
	diff_result1 = bi1 - bi2;
	diff_result2 = i1 - i2;

	if ((sum_result1) != (sum_result2) &&
		(diff_result1) != (diff_result2))
		std::cout << "Error. Arguments: ["
		<< bi1 << ", " << bi2
		<< "] [" << i1 << ", " << i2 << "]"
		<< "\nSum results = " << sum_result1 << ", " << sum_result2
		<< "\nDiff results = " << diff_result1 << ", " << diff_result2 << std::endl;
}