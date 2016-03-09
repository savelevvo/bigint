#ifndef _TEST_H
#define _TEST_H

#if defined(_MSC_VER)
# pragma once
#endif

#include<string>
void START_TEST(char** args)
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
		<< "\nSum results = " << sum_result1
		<< ", " << sum_result2
		<< "\nDiff results = " << diff_result1 
		<< ", " << diff_result2 << std::endl;
}

#endif // !_TEST_H