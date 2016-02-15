#include "bigint.h"

bigint::bigint()
	//: str("0")
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
	//str.~basic_string();
}

bigint & bigint::operator=(int rhs)
{
	itod(deq, rhs);
}

bigint & bigint::operator=(const std::string &rhs)
{
	stod(rhs);
}

bigint & bigint::operator=(const bigint &rhs)
{
	 
}

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


bigint & bigint::operator+(int rhs)
{
	std::deque<int> tmp, res;
	std::size_t tsz = tmp.size();
	std::size_t dsz = deq.size();
	
	itod(tmp, rhs);
	
	if (tsz != dsz)
	{
		std::deque<int> *min = (tsz < dsz) ? &tmp : &deq;
		std::deque<int> *max = (tsz > dsz) ? &tmp : &deq;

		min->insert(min->begin(), max->size() - min->size(), 0);// filling shortest deque by zeroes
	}

	for (int i = 0; i < deq.size(); i++)
	{
		short resid = 0;
		int sum = deq.back() + tmp.back();
		deq.pop_back(); tmp.pop_back();

		if (sum >= 10) resid = 1;

	}

}

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

void bigint::itod(std::deque<int> &_deq, int _val)
{
	int dig;
	while (_val != 0)
	{
		dig = _val % 10;
		_val = _val / 10;
		_deq.push_front(_val);
	}
}

void bigint::stod(const std::string &_str)
{
	int tmp = std::stoi(_str);
	//dtov(tmp);
}

void bigint::dtos(const std::deque<int> &_vec)
{

}
