#include "Basics.h"

Monomial::Monomial():LinkList()
{
	constnum = 1;
	value = { 0,0 };
}

Monomial::~Monomial()
{

}

void Monomial::sort(char mode)
{
	for (int i = 1; i < size; i++)
	{
		if(mode=='L')
		{
			int index = i;
			for (int j = index-1;read(j).letter > read(index).letter&&j>-1; j--)
			{
				Letter key;
				key = read(index);
				replace(index, read(j));
				replace(j, key);
				index = j;
			}
		}
		else if (mode == 'E')
		{
			int index = i;
			for (int j = i - 1; read(j).exponent < read(index).exponent && j > -1; j--)
			{
				Letter key;
				key = read(index);
				replace(index, read(j));
				replace(j, key);
				index = j;
			}
		}
		else
		{}
	}
}

Monomial Monomial::copy() const
{
	Monomial re_m;
	for (int i = 0; i < this->size; i++)
	{
		re_m.append(this->read(i));
	}
	re_m.constnum = this->constnum;
	re_m.value = this->value;
	return re_m;
}

bool Monomial::operator==(const Monomial& M) const
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

Monomial Monomial::operator+(const Monomial& M) const
{
	Monomial re_m = *this;
	re_m.constnum+=M.constnum;
	return re_m;
}

Monomial Monomial::operator-(const Monomial& M) const
{
	Monomial re_m = *this;
	re_m.constnum -= M.constnum;
	return re_m;
}

Monomial Monomial::operator*(const Monomial& M) const
{
	Monomial re_m= *this;
	int size = re_m.size;
	for (int i = 0; i < M.size; i++)
	{
		int bools = 0;
		for (int j = 0; j < size; j++, bools++)
		{
			if (re_m.read(j).letter == M.read(i).letter)
			{
				Letter re_l = { re_m.read(j).letter,re_m.read(j).exponent + M.read(i).exponent };
				if (re_l.exponent == 0)
					re_m.remove(j);
				else
					re_m.replace(j, re_l);
				break;
			}
		}
		if (bools == size)
			re_m.append(M.read(i));
	}
	re_m.constnum *= M.constnum;
	return re_m;
}

Monomial Monomial::operator*(double D) const
{
	Monomial re_m = *this;
	re_m.constnum *= D;
	return re_m;
}

Monomial Monomial::operator/(const Monomial& M) const
{
	Monomial re_m = *this;
	int size = re_m.size;
	for (int i = 0; i < M.size; i++)
	{
		int bools = 0;
		for (int j = 0; j < size; j++, bools++)
		{
			if (re_m.read(j).letter == M.read(i).letter)
			{
				Letter re_l = { re_m.read(j).letter,re_m.read(j).exponent - M.read(i).exponent };
				if (re_l.exponent == 0)
					re_m.remove(j);
				else
					re_m.replace(j, re_l);
				break;
			}
		}
		if (bools == size)
		{
			Letter ad = M.read(i);
			ad.exponent *= -1;
			re_m.append(ad);
		}
	}
	re_m.constnum /= M.constnum;
	return re_m;
}

Monomial Monomial::operator/(double D) const
{
	Monomial re_m = *this;
	re_m.constnum /= D;
	return re_m;
}

Polynomial::Polynomial():LinkList()
{
}

Polynomial::Polynomial(double D):LinkList()
{
	Monomial M;
	M.constnum = D;
	append(M);
}

Polynomial::Polynomial(Monomial M) :LinkList()
{
	append(M);
}

Polynomial::~Polynomial()
{
}

void Polynomial::sort(char mode)
{
}

Polynomial Polynomial::operator+(const Monomial& M) const
{
	Polynomial re_p = *this;
	int i = 0;
	int size = re_p.size;
	for (; i < size; i++)
	{
		if (re_p.read(i) == M)
		{
			Monomial re_m = re_p.read(i) + M;
			if (re_m.constnum == 0)
				re_p.remove(i);
			else
				re_p.replace(i, re_m);
			break;
		}
	}
	if (i == size)
		re_p.append(M);
	return re_p;
}

Polynomial Polynomial::operator+(const Polynomial& P) const
{
	Polynomial re_p= *this;
	for (int i = 0; i < P.size; i++)
	{
		re_p += P.read(i);
	}
	return re_p;
}

void Polynomial::operator+=(const Polynomial& P)
{
	for (int i = 0; i < P.size; i++)
	{
		*this += P.read(i);
	}
}

void Polynomial::operator+=(const Monomial& M)
{
	int i = 0;
	int size = this->size;
	for (; i < size; i++)
	{
		if (this->read(i) == M)
		{
			Monomial re_m = this->read(i) + M;
			if (re_m.constnum == 0)
				this->remove(i);
			else
				this->replace(i, re_m);
			break;
		}
	}
	if (i == size)
		this->append(M);
}

Polynomial Polynomial::operator-(const Polynomial& P) const
{
	Polynomial re_p = *this;
	for (int i = 0; i < P.size; i++)
	{
		re_p -= P.read(i);
	}
	return re_p;
}

Polynomial Polynomial::operator-(const Monomial& M) const
{
	Polynomial re_p = *this;
	int i = 0;
	int size = re_p.size;
	for (; i < size; i++)
	{
		if (re_p.read(i) == M)
		{
			Monomial re_m = re_p.read(i) - M;
			if (re_m.constnum == 0)
				re_p.remove(i);
			else
				re_p.replace(i, re_m);
			break;
		}
	}
	if (i == size)
		re_p.append(M*-1);
	return re_p;
}

void Polynomial::operator-=(const Polynomial& P)
{
	for (int i = 0; i < P.size; i++)
	{
		*this -= P.read(i);
	}
}

void Polynomial::operator-=(const Monomial& M)
{
	int i = 0;
	int size = this->size;
	for (; i < size; i++)
	{
		if (this->read(i) == M)
		{
			Monomial re_m = this->read(i) - M;
			if (re_m.constnum == 0)
				this->remove(i);
			else
				this->replace(i, re_m);
			break;
		}
	}
	if (i == size)
		this->append(M*-1);
}

Polynomial Polynomial::operator*(const Polynomial& P) const
{
	Polynomial re_p;
	for (int i = 0; i < P.size; i++)
		re_p += (*this * P.read(i));
	return re_p;
}

Polynomial Polynomial::operator*(const Monomial& M) const
{
	Polynomial re_p;
	for (int i = 0; i < this->size; i++)
		re_p.append( M * this->read(i));
	return re_p;
}

void Polynomial::operator*=(const Polynomial& P)
{
	Polynomial re_p;
	for (int i = 0; i < P.size; i++)
		re_p += (*this * P.read(i));
	*this = re_p;
}

void Polynomial::operator*=(const Monomial& M)
{
	for (int i = 0; i < this->size; i++)
		this->replace(i,this->read(i) * M);
}

Polynomial Polynomial::operator/(const Polynomial& P) const
{
	Polynomial re_p;
	for (int i = 0; i < P.size; i++)
		re_p += (*this / P.read(i));
	return re_p;
}

Polynomial Polynomial::operator/(const Monomial& M) const
{
	Polynomial re_p;
	for (int i = 0; i < this->size; i++)
		re_p.append(this->read(i) / M);
	return re_p;
}

void Polynomial::operator/=(const Polynomial& P)
{
	Polynomial re_p;
	for (int i = 0; i < P.size; i++)
		re_p += (*this / P.read(i));
	*this = re_p;
}

void Polynomial::operator/=(const Monomial& M)
{
	for (int i = 0; i < this->size; i++)
		this->replace(i, this->read(i) / M);
}

Polynomial Polynomial::operator^(int ex) const
{
	Polynomial re_p=*this;
	for (int i = 1; i < ex; i++)
	{
		re_p *= *this;
	}
	return re_p;
}

Equation::Equation() :LinkList()
{
}

Equation::~Equation()
{
}

void Equation::operator+(const Polynomial& P)
{
}

void Equation::operator-(const Polynomial& P)
{
}

void Equation::operator*(const Polynomial& P)
{
}

void Equation::operator/(const Polynomial& P)
{
}

Inequation::Inequation() :LinkList()
{
}

Inequation::~Inequation()
{
}

Inequation Inequation::operator+(const Polynomial& P)
{
	return Inequation();
}

Inequation Inequation::operator-(const Polynomial& P)
{
	return Inequation();
}

Inequation Inequation::operator*(const Polynomial& P)
{
	return Inequation();
}

Inequation Inequation::operator/(const Polynomial& P)
{
	return Inequation();
}

ArgumentMap::ArgumentMap()
{
	arrary = new double[124];
}

ArgumentMap::~ArgumentMap()
{
	delete[] arrary;
}

void ArgumentMap::insert(char name, int data)
{
	arrary[(int)name] = data;
}

double ArgumentMap::read(char name) const
{
	if (name == 0)
		return 0;
	else
		return arrary[int(name)];
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
		double coefficient = expression.read(i).constnum;
		for (int j = 0; j < expression.read(i).size; j++)
			coefficient *= pow(arg.read(expression.read(i).read(j).letter), expression.read(i).read(j).exponent);
		Monomial M;
		M.constnum = coefficient;
		M.value = expression.read(i).value;
		re_p.append(M);
	}
	return Function(re_p,this->value);
}

double Function::solve_y(int x)
{
	double sum = 0;
	for (int i = 0; i < expression.size; i++)
	{
		sum += expression.read(i).constnum * (pow(x, expression.read(i).value.exponent));
	}
	return sum;
}

double Function::solve_x(int y)
{
	return 0;
}

Vector operator+(Vector S, Vector E)
{
	return Vector();
}

Vector operator-(Vector S, Vector E)
{
	return Vector();
}

Vector operator*(Vector S, Vector E)
{
	return Vector();
}

Vector operator/(Vector S, Vector E)
{
	return Vector();
}
