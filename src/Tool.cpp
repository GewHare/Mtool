#include "Tool.h"

ostream& operator<<(ostream& O, const Letter& L)
{
	O << L.letter;
	O << '^';
	O << L.exponent;
	return O;
}
ostream& operator<<(ostream& O, const Monomial& M)
{
	O << M.constnum;
	for (int i = 0; i < M.size; i++)
	{
		O << M.read(i);
	}
	O << M.value;
	return O;
}
ostream& operator<<(ostream& O, const Polynomial& P)
{
	for (int i = 0; i < P.size; i++)
	{
		O << P.read(i);
		if (i == P.size - 2)
			O << '+';
	}
	return O;
}
ostream& operator<<(ostream& O, const Function& F)
{
	O << F.id;
	O << '(';
	O << F.value.letter;
	O << ')';
	O << '=';
	O << F.expression;
	return O;
}