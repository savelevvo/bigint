#ifndef _BIGINT_H
#define _BIGINT_H

#if defined(_MSC_VER)
# pragma once
#endif

#include<iostream>
#include<deque>
#include<string>
#include<stdlib.h>

class bigint
{
	friend bool operator==(const bigint &, const std::deque<int> &);
	friend bool operator==(const bigint &, int);
	friend bool operator==(const bigint &, const std::string &);
	friend bool operator==(const bigint &, const bigint &);
	friend bool operator<(const bigint &, int);
	friend bool operator<(const bigint &, const std::string &);
	friend bool operator<(const bigint &, const bigint &);
	friend std::ostream & operator<<(std::ostream &, const bigint &);

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

	std::deque<int> naive_mul(const std::deque<int>&, const std::deque<int>&);
	std::deque<int> karatsuba_mul(const std::deque<int> &, const std::deque<int> &);

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

private:
	std::deque<int> deq;

	std::deque<int> to_deque(int)const;
	std::deque<int> to_deque(const std::string &)const;
	std::string dtos(const std::deque<int> &)const;// deque to string

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