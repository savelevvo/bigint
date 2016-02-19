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
	stod(_str);
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
	stod(rhs);
	return *this;
}

bigint & bigint::operator=(const bigint &rhs)
{
	deq = rhs.deq;
	return *this;
}
/*
bigint & bigint::operator+=(int rhs)
{

}

bigint & bigint::operator+=(const std::string &rhs)
{

}

bigint & bigint::operator+=(const bigint &rhs)
{

}

bigint & bigint::operator-=(int rhs)
{

}

bigint & bigint::operator-=(const std::string &rhs)
{

}

bigint & bigint::operator-=(const bigint &rhs)
{

}

bigint & bigint::operator*=(int rhs)
{

}

bigint & bigint::operator*=(const std::string &rhs)
{

}

bigint & bigint::operator*=(const bigint &rhs)
{

}


bigint & bigint::operator/=(int rhs)
{

}

bigint & bigint::operator/=(const std::string &rhs)
{

}

bigint & bigint::operator/=(const bigint &rhs)
{

}
*/
bigint & bigint::operator+(int rhs)
{
	std::deque<int> tmp, res;
	itod(tmp, rhs);
	align(deq, tmp);

	short resid = 0;
	short sum;

	for (std::deque<int>::reverse_iterator rit = deq.rbegin(); rit != deq.rend(); ++rit)
	{
		sum = *rit + tmp.back();
		tmp.pop_back();
		if (resid)
		{
			++sum;
			resid = 0;
		}
	
		if (sum >= 10)
		{
			resid = 1;
			res.push_front(sum % 10);
			sum = 0;
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


bigint & bigint::operator++()
{

}

bigint & bigint::operator++(int)
{

}

bigint & bigint::operator--()
{

}

bigint & bigint::operator--(int)
{

}
*/

int bigint::pop_back()const
{
	
	std::deque<int>::reverse_iterator rit = deq.rbegin();
	return *rit;
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

void bigint::stod(const std::string &_str)
{
	int tmp = std::stoi(_str);
	itod(deq, tmp);
}

void bigint::dtos(const std::deque<int> &_deq)
{

}

void bigint::align(std::deque<int>&lhs, std::deque<int>&rhs)
{
	std::size_t lsz = lhs.size();
	std::size_t rsz = rhs.size();

	if (lsz != rsz)
	{
		std::deque<int> *min = (lsz < rsz) ? &lhs : &rhs;
		std::deque<int> *max = (lsz > rsz) ? &lhs : &rhs;

		min->insert(min->begin(), (max->size() - min->size()), 0);// filling shortest deque with zeros
	}
}
/*
bool operator==(const bigint &lhs, int rhs)
{
	
	return false;
}

bool operator==(const bigint &lhs, const std::string &rhs)
{
	return false;
}

bool operator== (const bigint &lhs, const bigint &rhs)
{

}

bool operator!= (const bigint &lhs, int rhs)
{

}

bool operator!= (const bigint &lhs, const std::string &rhs)
{

}

bool operator!= (const bigint &lhs, const bigint &rhs)
{

}

std::istream & operator>>(std::istream &is, bigint &_val)
{

}
*/
std::ostream & operator<<(std::ostream &os, const bigint &_val)
{
	/*std::deque<int>::iterator it;
	for (it = deq.begin(); it != deq.end(); ++it)
		os << *it << ",";
	os << std::endl;*/
	return os;
}
