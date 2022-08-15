#include "Basics.h"
#include "Tool.h"
#include <iostream>
using namespace std;
Monomial::Monomial()
{
	head = 0;
	tail = 0;
	size = 0;
	constnum = 0;
	argument = { 0,0 };
}

Monomial::~Monomial()
{
}

void Monomial::append(Letter data)
{
	if (tail == 0)
	{
		head = new LUnit;
		head->data = data;
		head->next = 0;
		tail = head;
		size++;
	}
	else
	{
		tail->next = new LUnit;
		tail = tail->next;
		tail->data = data;
		tail->next = 0;
		size++;
	}
}

void Monomial::remove(int index)
{
	if (index >= size)
	{}
	else
	{
		LUnit* del_unit=head;
		LUnit* b_unit=head;
		if (index == 0)
		{
			head = del_unit->next;
			delete del_unit;
			size--;
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				b_unit = del_unit;
				del_unit = del_unit->next;
			}
			b_unit->next = del_unit->next;
			delete del_unit;
			size--;
		}
	}
}

void Monomial::replace(int index, Letter data)
{
	LUnit* re_u = head;
	for (int i = 0; i < index; i++)
		re_u = re_u->next;
	re_u->data = data;
}

Letter Monomial::read(int index)
{
	if (index >= size)
	{
		return Letter{ 0,0 };
	}
	else
	{
		LUnit* re_u = head;
		for (int i = 0; i < index; i++)
			re_u = re_u->next;
		return (re_u->data);
	}
}

bool Monomial::operator==(Monomial M)
{
	if (this->size == M.size)
	{
		int bools = 0;
		for (int i = 0; i < M.size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				if ((this->read(j).letter == M.read(i).letter) && (this->read(j).exponent == M.read(i).exponent))
				{
					bools++;
					break;
				}
			}
		}
		if (bools == M.size)
			return true;
		else
			return false;
	}
	else
		return false;
}

Monomial Monomial::operator+(Monomial M)
{
	Monomial re_m = *this;
	re_m.constnum += M.constnum;
	return re_m;
}

Monomial Monomial::operator-(Monomial M)
{
	Monomial re_m = *this;
	re_m.constnum -= M.constnum;
	return re_m;
}

Monomial Monomial::operator*(Monomial M)
{
	Monomial re_m = *this;
	for (int i = 0; i < M.size; i++)
	{
		int bools = 0;
		for (int j = 0; j < re_m.size; j++,bools++)
		{
			if (re_m.read(j).letter == M.read(i).letter)
			{
				re_m.replace(j, Letter{ re_m.read(j).letter,re_m.read(j).exponent + M.read(i).exponent });
				break;
			}
		}
		if (bools == re_m.size)
			re_m.append(M.read(i));
	}
	re_m.constnum *= M.constnum;
	return re_m;
}

Monomial Monomial::operator/(Monomial M)
{
	Monomial re_m = *this;
	for (int i = 0; i < M.size; i++)
	{
		Letter L = M.read(i);
		L.exponent *= -1;
		M.replace(i, L);
	}
	for (int i = 0; i < M.size; i++)
	{
		int bools = 0;
		for (int j = 0; j < re_m.size; j++, bools++)
		{
			if (re_m.read(j).letter == M.read(i).letter)
			{
				re_m.replace(j, Letter{ re_m.read(j).letter,re_m.read(j).exponent + M.read(i).exponent });
				break;
			}
		}
		if (bools == re_m.size)
			re_m.append(M.read(i));
	}
	re_m.constnum *= M.constnum;
	return re_m;
}
