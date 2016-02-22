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

bigint & bigint::operator+=(int rhs)
{
	return *this + rhs;
}
/*
bigint & bigint::operator+=(const std::string &rhs)
{
	return *this + rhs;
}

bigint & bigint::operator+=(const bigint &rhs)
{
	return *this + rhs;
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
bigint & bigint::operator+(int rhs)
{
	//if(rhs < 0) return operator-(rhs);
	std::deque<int> tmp, res;
	itod(tmp, rhs);
	if(deq.size() != tmp.size()) align(deq, tmp);

	bool resid = false;
	int sum;

	for (std::deque<int>::const_reverse_iterator rit = deq.rbegin(); rit != deq.rend(); ++rit)
	{
		sum = *rit + tmp.back();
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
			if (rit == (deq.rend() - 1)) res.push_front(1);
		} else
			res.push_front(sum);

	}
	deq = res;
	return *this;
}
/*
bigint & bigint::operator+(const std::string &rhs)
{

}

bigint & bigint::operator+(const bigint &rhs)
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


bigint & bigint::operator*(int rhs)
{

}

bigint & bigint::operator*(const std::string &rhs)
{

}

bigint & bigint::operator*(const bigint &rhs)
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
*/
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
/*
bigint & bigint::operator--()
{

}

bigint & bigint::operator--(int)
{

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
	std::size_t dsz = _val.size();
	for (std::size_t i = 0; i < dsz; ++i)
		os << _val[i];

	return os;
}
