#include "Tool.h"

Letter CreatLetter(char letter, int exponent)
{
	return Letter{letter,exponent};
}

Monomial CreatMonomial(int constnum, Letter* letters,int l_size)
{
	Monomial* re_m = new Monomial;
	re_m->constnum = constnum;
	for (int i = 0; i < l_size ; i++)
	{
		re_m->append(letters[i]);
	}
	return *(re_m);
}

Polynomial CreatPolynomial(Monomial** ms, int m_size)
{
	Polynomial* re_p = new Polynomial;
	for (int i = 0; i < m_size; i++)
	{
		re_p->append(*(ms[i]));
	}
	return *(re_p);
}

Function CreatLinearFunction(int k, int b, char argument)
{
	Polynomial re_p = Polynomial();
	Function re_f = Function(re_p);
	return re_f;
}

void Print(Letter L)
{
	cout << L.letter;
	cout << '^';
	cout << L.exponent;
}

void Print(Monomial M)
{
	cout << M.constnum;
	for (int i = 0; i < M.size; i++)
	{
		Print(M.read(i));
	}
	Print(M.argument);
}

void Print(Polynomial P)
{
	for (int i = 0; i < P.size; i++)
	{
		Print(P.read(i));
		if (i != P.size - 1)
			cout << '+';
	}
}

void Print(Function F)
{
	cout << F.id;
	cout << '(' << F.value.letter << ')';
	cout << '=';
	Print(F.expression);
}
