#include "bigint.h"

bigint::bigint()
	: deq()
{
	
}

bigint::bigint(int _val)
{
	itod(deq, _val);
}

bigint::bigint(const std::string &_str)
{
	stod(deq, _str);
}

bigint::bigint(const bigint &rhs)
{
	*this = rhs;
}

bigint::~bigint()
{
	deq.~deque();
}

bigint & bigint::operator=(const std::deque<int> &rhs)
{
	deq = rhs;
	return *this;
}

bigint & bigint::operator=(int rhs)
{
	deq.clear();
	itod(deq, rhs);
	return *this;
}

bigint & bigint::operator=(const std::string &rhs)
{
	deq.clear();
	stod(deq, rhs);
	return *this;
}

bigint & bigint::operator=(const bigint &rhs)
{
	if (this == &rhs) return *this;
	deq = rhs.deq;
	return *this;
}

bigint & bigint::operator+(const std::deque<int> &rhs)
{
	std::deque<int> tmp(rhs), res;
	if (deq.size() != rhs.size()) align(deq, tmp);

	bool resid = false;
	int sum;

	for (std::deque<int>::const_reverse_iterator crit = deq.rbegin(); crit != deq.rend(); ++crit)
	{
		sum = *crit + tmp.back();
		tmp.pop_back();
		if (resid)
		{
			++sum;
			resid = false;
		}

		if (sum >= 10)
		{
			resid = true;
			res.push_front(sum % 10);
			sum = 0;
			if (crit == (deq.rend() - 1)) res.push_front(1);
		}
		else
			res.push_front(sum);
	}
	deq = res;
	return *this;
}

bigint & bigint::operator+(int rhs)
{
	std::deque<int> tmp;
	itod(tmp, rhs);

	return *this + tmp;
}

bigint & bigint::operator+(const std::string &rhs)
{
	std::deque<int> tmp;
	stod(tmp, rhs);

	return *this + tmp;
}

bigint & bigint::operator+(const bigint &rhs)
{
	std::deque<int> tmp;
	std::size_t rsz = rhs.size();
	for (std::size_t i = 0; i < rsz; ++i)
		tmp.push_back(rhs[i]);

	return *this + tmp;
}

bigint & bigint::operator+=(const std::deque<int> &rhs)
{
	return *this + rhs;
}

bigint & bigint::operator+=(int rhs)
{
	return *this + rhs;
}

bigint & bigint::operator+=(const std::string &rhs)
{
	return *this + rhs;
}

bigint & bigint::operator+=(const bigint &rhs)
{
	return *this + rhs;
}

bigint & bigint::operator++()
{
	return *this += 1;
}

bigint & bigint::operator++(int)
{
	bigint *tmp = new bigint(*this);
	++(*this);

	return *tmp;
}

bigint & bigint::operator-(const std::deque<int> &rhs)
{

}

bigint & bigint::operator-(int rhs)
{

}

bigint & bigint::operator-(const std::string &rhs)
{

}

bigint & bigint::operator-(const bigint &rhs)
{

}

bigint & bigint::operator-=(const std::deque<int> &rhs)
{
	return *this - rhs;
}

bigint & bigint::operator-=(int rhs)
{
	return *this - rhs;
}

bigint & bigint::operator-=(const std::string &rhs)
{
	return *this - rhs;
}

bigint & bigint::operator-=(const bigint &rhs)
{
	return *this - rhs;
}

bigint & bigint::operator--()
{
	return *this -= 1;
}

bigint & bigint::operator--(int)
{
	bigint *tmp = new bigint(*this);
	--(*this);
	return *tmp;
}
/*
bigint & bigint::operator*(const std::deque<int> &rhs);
{

}

bigint & bigint::operator*(int rhs)
{

}

bigint & bigint::operator*(const std::string &rhs)
{

}

bigint & bigint::operator*(const bigint &rhs)
{

}

bigint & bigint::operator*=(const std::deque<int> &rhs);
{
	return *this * rhs;
}

bigint & bigint::operator*=(int rhs)
{
	return *this * rhs;
}

bigint & bigint::operator*=(const std::string &rhs)
{
	return *this * rhs;
}

bigint & bigint::operator*=(const bigint &rhs)
{
	return *this * rhs;
}

bigint & bigint::operator/(const std::deque<int> &)
{

}

bigint & bigint::operator/(int rhs)
{

}

bigint & bigint::operator/(const std::string &rhs)
{

}

bigint & bigint::operator/(const bigint &rhs)
{

}

bigint & bigint::operator/=(const std::deque<int> &)
{

}

bigint & bigint::operator/=(int rhs)
{
	return *this / rhs;
}

bigint & bigint::operator/=(const std::string &rhs)
{
	return *this / rhs;
}

bigint & bigint::operator/=(const bigint &rhs)
{
	return *this / rhs;
}
*/
inline int bigint::operator[](int _val)const
{
	return deq[_val];
}

inline std::size_t bigint::size()const
{
	return deq.size();
}

std::string & bigint::dtos()const
{
	std::string* tmp = new std::string;
	for (std::deque<int>::const_iterator cit = deq.begin(); cit != deq.end(); ++cit)
		tmp->push_back(*cit + '0');

	return *tmp;
}


/**** Private functions ****/

void bigint::itod(std::deque<int> &_deq, int _val)
{
	int dig;
	while (_val != 0)
	{
		dig = _val % 10;
		_val = _val / 10;
		_deq.push_front(dig);
	}
}

void bigint::stod(std::deque<int> &_deq, const std::string &_str)
{
	for (std::string::const_reverse_iterator crit = _str.rbegin(); crit != _str.rend(); ++crit)
		_deq.push_front(*crit - '0');
}

void bigint::align(std::deque<int> &lhs, std::deque<int> &rhs)
{
	std::size_t lsz = lhs.size();
	std::size_t rsz = rhs.size();

	std::deque<int> *min = (lsz < rsz) ? &lhs : &rhs;
	std::deque<int> *max = (lsz > rsz) ? &lhs : &rhs;

	// filling shortest deque with zeros
	min->insert(min->begin(), (max->size() - min->size()), 0);
}


/**** Non-member functions ****/

bool operator==(const bigint &lhs, int rhs)
{
	std::string slhs = lhs.dtos();
	std::string srhs = std::to_string(rhs);
	return (slhs == srhs);
}

bool operator==(const bigint &lhs, const std::string &rhs)
{
	std::string slhs = lhs.dtos();
	return (slhs == rhs);
}

bool operator== (const bigint &lhs, const bigint &rhs)
{
	if (&lhs == &rhs) return true;
	std::string slhs = lhs.dtos();
	std::string srhs = rhs.dtos();
	return (slhs == srhs);
}

bool operator!= (const bigint &lhs, int rhs)
{
	return !(lhs == rhs);
}

bool operator!= (const bigint &lhs, const std::string &rhs)
{
	return !(lhs == rhs);
}

bool operator!= (const bigint &lhs, const bigint &rhs)
{
	return !(lhs == rhs);
}
/*
std::istream & operator>>(std::istream &is, bigint &_val)
{

	return is;
}
*/
std::ostream & operator<<(std::ostream &os, const bigint &_val)
{
	return os << _val.dtos();
}
