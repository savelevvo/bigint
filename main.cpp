#include<iostream>
#include"bigint.h"

int main()
{
	using std::cout;
	using std::endl;

	//todo:
	//	namespace
	//	check() is number correct
	//std::stoi("74");

	bigint bi1, bi2(150);
	std::deque<int> d1 = { 12 };
	std::deque<int> d2 = { 81 }, d3;
	//std::string s = "-123";

	//cout << (bi1 * d2) << endl;

	d3 = bi1.karatsuba_mul(d1, d2);
	cout << d3.front() << endl;

	return 0;
}
