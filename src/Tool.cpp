#include "Tool.h"

ostream& operator<<(ostream& O, const Letter& L)
{
	O << L.letter;
	O << '^';
	O << L.exponent;
	return O;
}
ostream& operator<<(ostream& O, const Point& P)
{
	O << '(';
	O << P.x;
	O << P.y;
	O << ')';
	return O;
}
ostream& operator<<(ostream& O, const Monomial& M)
{
	O << M.constnum;
	for (int i = 0; i < M.size; i++)
	{
		O << M.read(i);
	}
	if(M.value.letter!=0)
		O << M.value;
	return O;
}
ostream& operator<<(ostream& O, const Polynomial& P)
{
	for (int i = 0; i < P.size; i++)
	{
		O << P.read(i);
		if (i != P.size - 1)
			O << '+';
	}
	return O;
}

ostream& operator<<(ostream& O, const Function& F)
{
	O << F.id;
	O << '(';
	O << F.value;
	O << ')';
	O << '=';
	O << F.expression;
	return O;
}