#pragma once
#ifndef _BIGINT_H
#define _BIGINT_H

#include<iostream>
#include<deque>
#include<string>
#include<stdlib.h>

class bigint
{
public:
	bigint();
	bigint(int);
	bigint(const std::string &);
	bigint(const bigint &);
	~bigint();
	
	bigint & operator=(const std::deque<int> &);
	bigint & operator=(int);
	bigint & operator=(const std::string &);
	bigint & operator=(const bigint &);

	bigint & operator+(const std::deque<int> &);
	bigint & operator+(int);
	bigint & operator+(const std::string &);
	bigint & operator+(const bigint &);

	bigint & operator+=(const std::deque<int> &);
	bigint & operator+=(int);
	bigint & operator+=(const std::string &);
	bigint & operator+=(const bigint &);

	bigint & operator++();
	bigint & operator++(int);

	bigint & operator-(const std::deque<int> &);
	bigint & operator-(int);
	bigint & operator-(const std::string &);
	bigint & operator-(const bigint &);

	bigint & operator-=(const std::deque<int> &);
	bigint & operator-=(int);
	bigint & operator-=(const std::string &);
	bigint & operator-=(const bigint &);

	bigint & operator--();
	bigint & operator--(int);

	bigint & operator*(const std::deque<int> &);
	bigint & operator*(int);
	bigint & operator*(const std::string &);
	bigint & operator*(const bigint &);

	bigint & operator*=(const std::deque<int> &);
	bigint & operator*=(int);
	bigint & operator*=(const std::string &);
	bigint & operator*=(const bigint &);

	bigint & operator/(const std::deque<int> &);
	bigint & operator/(int);
	bigint & operator/(const std::string &);
	bigint & operator/(const bigint &);

	bigint & operator/=(const std::deque<int> &);
	bigint & operator/=(int);
	bigint & operator/=(const std::string &);
	bigint & operator/=(const bigint &);

	inline int operator[](int)const;
	inline std::size_t size()const;
	std::string & dtos()const;// deque to string

private:
	std::deque<int> deq;

	void itod(std::deque<int> &, int);// int to deque
	void stod(std::deque<int> &, const std::string &);// string to deque
	void align(std::deque<int> &, std::deque<int> &);
	
};

bool operator==(const bigint &, const std::deque<int> &);
bool operator==(const bigint &, int);
bool operator==(const bigint &, const std::string &);
bool operator==(const bigint &, const bigint &);

bool operator!=(const bigint &, const std::deque<int> &);
bool operator!=(const bigint &, int);
bool operator!=(const bigint &, const std::string &);
bool operator!=(const bigint &, const bigint &);

bool operator<(const bigint &, const std::deque<int> &);
bool operator<(const bigint &, int);
bool operator<(const bigint &, const std::string &);
bool operator<(const bigint &, const bigint &);

bool operator<=(const bigint &, const std::deque<int> &);
bool operator<=(const bigint &, int);
bool operator<=(const bigint &, const std::string &);
bool operator<=(const bigint &, const bigint &);

bool operator>(const bigint &, const std::deque<int> &);
bool operator>(const bigint &, int);
bool operator>(const bigint &, const std::string &);
bool operator>(const bigint &, const bigint &);

bool operator>=(const bigint &, const std::deque<int> &);
bool operator>=(const bigint &, int);
bool operator>=(const bigint &, const std::string &);
bool operator>=(const bigint &, const bigint &);

std::istream & operator>>(std::istream &, bigint &);
std::ostream & operator<<(std::ostream &, const bigint &);

#endif // !_BIGINT_H