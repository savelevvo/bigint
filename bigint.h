#pragma once
#ifndef _BIGINT_H
#define _BIGINT_H

#include<iostream>
#include<vector>
#include<string>

class bigint
{
public:
	bigint();
	bigint(int);
	bigint(const std::string &);
	bigint(const bigint &);
	~bigint();
	
	bigint & operator=(int);
	bigint & operator=(const std::string &);
	bigint & operator=(const bigint &);

	bigint & operator+=(int);
	bigint & operator+=(const std::string &);
	bigint & operator+=(const bigint &);

	bigint & operator-=(int);
	bigint & operator-=(const std::string &);
	bigint & operator-=(const bigint &);

	bigint & operator*=(int);
	bigint & operator*=(const std::string &);
	bigint & operator*=(const bigint &);

	bigint & operator/=(int);
	bigint & operator/=(const std::string &);
	bigint & operator/=(const bigint &);

	bigint & operator+(int);
	bigint & operator+(const std::string &);
	bigint & operator+(const bigint &);

	bigint & operator-(int);
	bigint & operator-(const std::string &);
	bigint & operator-(const bigint &);
	
	bigint & operator*(int);
	bigint & operator*(const std::string &);
	bigint & operator*(const bigint &);

	bigint & operator/(int);
	bigint & operator/(const std::string &);
	bigint & operator/(const bigint &);

	bigint & operator++();
	bigint & operator++(int);
	bigint & operator--();
	bigint & operator--(int);

	void itov(int);// int to vector
	void stov(std::string);// string to vector

private:
	std::vector<int> v;
};

bool operator== (const bigint &, int);
bool operator== (const bigint &, const std::string &);
bool operator== (const bigint &, const bigint &);

bool operator!= (const bigint &, int);
bool operator!= (const bigint &, const std::string &);
bool operator!= (const bigint &, const bigint &);

std::istream & operator>>(std::istream &, bigint &);
std::ostream & operator<<(std::ostream &, const bigint &);

#endif // !_BIGINT_H