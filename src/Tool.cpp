#include "Tool.h"

Letter CreatLetter(char letter, int exponent)
{
	return Letter{letter,exponent};
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
