#include "Basics.h"
#include "Tool.h"
#include <iostream>
using namespace std;
int pow(int tn, int ex)
{
	int start = tn;
	if (ex < 0)
		return 0;
	else if(ex == 0)
		return 1;
	else if(ex > 0)
	{
		for (int i = 1; i < ex; i++,tn*=start)
		{}
		return tn;
	}
}
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
		head = new LUnit{data,0};
		tail = head;
		size++;
	}
	else
	{
		tail->next = new LUnit{data,0};
		tail = tail->next;
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

Polynomial::Polynomial()
{
	head = 0;
	tail = 0;
	size = 0;
}

Polynomial::~Polynomial()
{
}

void Polynomial::append(Monomial data)
{
	if (tail == 0)
	{
		head = new MUnit{ &data,0};
		tail = head;
		size++;
	}
	else
	{
		tail->next = new MUnit{ &data,0 };
		tail = tail->next;
		size++;
	}
}

void Polynomial::remove(int index)
{
	if (index >= size)
	{
	}
	else
	{
		MUnit* del_unit = head;
		MUnit* b_unit = head;
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

void Polynomial::replace(int index, Monomial data)
{
	MUnit* re_u = head;
	for (int i = 0; i < index; i++)
		re_u = re_u->next;
	re_u->data = &data;
}

Monomial Polynomial::read(int index)
{
 	MUnit* re_m = head;
	if (index >= size)
	{
		return Monomial();
	}
	else
	{
		for (int i = 0; i < index; i++)
			re_m = re_m->next;
		return *(re_m->data);
	}
}

Polynomial Polynomial::operator+(Polynomial P)
{
	return Polynomial();
}

Polynomial Polynomial::operator-(Polynomial P)
{
	return Polynomial();
}

Polynomial Polynomial::operator*(Polynomial P)
{
	return Polynomial();
}

Polynomial Polynomial::operator/(Polynomial P)
{
	return Polynomial();
}

Arguments::Arguments()
{
	arrary = new int[80];
}

Arguments::~Arguments()
{
	delete [] arrary;
}

int Arguments::index(char name)
{
	return ((int)name - 60);
}

void Arguments::insert(char name, int data)
{
	arrary[index(name)] = data;
}

int Arguments::read(char name)
{
	if (name == 0)
		return 0;
	else
		return arrary[index(name)];
}

Function::Function(Polynomial E)
{
	id = 'f';
	expression = E;
	args = new Arguments;
}

Function::~Function()
{
	delete args;
}

int Function::solve_y(int x)
{
	int re_num = 0;
	for (int i = 0; i < expression.size; i++)
	{
		int m_num = expression.read(i).constnum;
		for (int j = 0; j < expression.read(i).size; j++)
		{
			int l_num = pow(args->read(expression.read(i).read(j).letter), expression.read(i).read(j).exponent);
			m_num *= l_num;
		}
		int v_num=pow(args->read(expression.read(i).argument.letter), expression.read(i).argument.exponent);
		m_num *= v_num;
		re_num += m_num;
	}
	return re_num;
}

int Function::solve_x(int y)
{
	return 0;
}
