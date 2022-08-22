#include "Basics.h"

Monomial::Monomial()
{
	size = 0;
	head = 0;
	tail = 0;
	constnum = 1;
	value = { 0,0 };
}

Monomial::~Monomial()
{
}

void Monomial::append(const Letter& data)
{
	if (tail == 0)
	{
		head = new LNode{ data,0 };
		tail = head;
		size++;
	}
	else
	{
		tail->next = new LNode{ data,0 };
		tail = tail->next;
		size++;
	}
}

void Monomial::remove(int index)
{

	LNode* del_unit = head;
	LNode* b_unit = head;
	if (index >= size)
	{
	}
	else
	{
		if (index == 0)
		{
			head = del_unit->next;
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				b_unit = del_unit;
				del_unit = del_unit->next;
			}
			b_unit->next = del_unit->next;
		}
	}
	if (del_unit->next == 0)
		tail = b_unit;
	delete del_unit;
	size--;
}

void Monomial::replace(int index, const Letter& data)
{
	LNode* re_u = head;
	for (int i = 0; i < index; i++)
		re_u = re_u->next;
	re_u->data = data;
}

Letter Monomial::read(int index) const
{
	if (index >= size)
	{
		return Letter{ 0,0 };
	}
	else
	{
		LNode* re_u = head;
		for (int i = 0; i < index; i++)
			re_u = re_u->next;
		return (re_u->data);
	}
}

bool Monomial::operator==(const Monomial M) const
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

Monomial Monomial::operator+(const Monomial M) const
{
	Monomial re_m = *this;
	re_m.constnum += M.constnum;
	return re_m;
}

Monomial Monomial::operator-(const Monomial M) const
{
	Monomial re_m = *this;
	re_m.constnum -= M.constnum;
	return re_m;
}

Monomial Monomial::operator*(const Monomial M) const
{
	Monomial re_m = *this;
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

Monomial Monomial::operator/(const Monomial M) const
{
	Monomial re_m = *this;
	for (int i = 0; i < M.size; i++)
	{
		int bools = 0;
		for (int j = 0; j < re_m.size; j++, bools++)
		{
			if (re_m.read(j).letter == M.read(i).letter)
			{
				re_m.replace(j, Letter{ re_m.read(j).letter,re_m.read(j).exponent - M.read(i).exponent });
				break;
			}
		}
		if (bools == re_m.size)
		{
			Letter ad = M.read(i);
			ad.exponent *= -1;
			re_m.append(ad);
		}
	}
	re_m.constnum /= M.constnum;
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

void Polynomial::append(const Monomial& data)
{
	if (tail == 0)
	{
		head = new MNode{ data,0 };
		tail = head;
		size++;
	}
	else
	{
		tail->next = new MNode{ data,0 };
		tail = tail->next;
		size++;
	}
}

void Polynomial::remove(int index)
{
	MNode* del_unit = head;
	MNode* b_unit = head;
	if (index >= size)
	{
	}
	else
	{
		if (index == 0)
		{
			head = del_unit->next;
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				b_unit = del_unit;
				del_unit = del_unit->next;
			}
			b_unit->next = del_unit->next;
		}
	}
	if (del_unit->next == 0)
		tail = b_unit;
	delete del_unit;
	size--;
}

void Polynomial::replace(int index, const Monomial& data)
{
	MNode* re_u = head;
	for (int i = 0; i < index; i++)
		re_u = re_u->next;
	re_u->data = data;
}

Monomial& Polynomial::read(int index) const
{
	MNode* re_m = head;
	if (index >= size)
	{
	}
	else
	{
		for (int i = 0; i < index; i++)
			re_m = re_m->next;
		return re_m->data;
	}
}

Polynomial Polynomial::operator+(const Polynomial& P) const
{
	return Polynomial();
}

Polynomial Polynomial::operator-(const Polynomial& P) const
{
	return Polynomial();
}

Polynomial Polynomial::operator*(const Polynomial& P) const
{
	return Polynomial();
}

Polynomial Polynomial::operator/(const Polynomial& P) const
{
	return Polynomial();
}

ArgumentMap::ArgumentMap()
{
	arrary = new int[80];
}

ArgumentMap::~ArgumentMap()
{
	delete[] arrary;
}

int ArgumentMap::index(char name) const
{
	return ((int)name - 60);
}

void ArgumentMap::insert(char name, int data)
{
	arrary[index(name)] = data;
}

int ArgumentMap::read(char name) const
{
	if (name == 0)
		return 0;
	else
		return arrary[index(name)];
}

Function::Function(const Polynomial& E, char valuex, char id)
{
	expression = E;
	this->id = id;
	this->value = valuex;
	for (int i = 0; i < expression.size; i++)
	{
		int size = expression.read(i).size;
		for (int j = 0; j < size; j++)
		{
			if (expression.read(i).read(j).letter == valuex)
			{
				expression.read(i).value = expression.read(i).read(j);
				expression.read(i).remove(j);
			}
		}
	}
}

Function::Function()
{
}

Function::~Function()
{
}

void Function::set_value(char terget)
{
}

Function Function::set_RE(const ArgumentMap& arg)
{
	Polynomial re_p;
	for (int i = 0; i < expression.size; i++)
	{
		int coefficient = expression.read(i).constnum;
		for (int j = 0; j < expression.read(i).size; j++)
			coefficient *= pow(arg.read(expression.read(i).read(j).letter), expression.read(i).read(j).exponent);
		Monomial M;
		M.constnum = coefficient;
		M.value = expression.read(i).value;
		re_p.append(M);
	}
	return Function(re_p,this->value);
}

int Function::solve_y(int x)
{
	int sum = 0;
	for (int i = 0; i < expression.size; i++)
	{
		sum += expression.read(i).constnum * (pow(x, expression.read(i).value.exponent));
	}
	return sum;
}

int Function::solve_x(int y)
{
	return 0;
}
