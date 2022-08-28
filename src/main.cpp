#include <iostream>
#include <map>
#include "Basics.h"
#include "Tool.h"

using namespace std;
int main()
{
	Letter Lc{ 'c',1 };
	Monomial Mc;
	Mc.append(Lc);
	Letter Laf{ 'a',-1 };
	Monomial Maf;
	Maf.append(Laf);

	Letter La{ 'a',1 };
	Letter Lb{ 'b',1 };
	Monomial Ma;
	Ma.append(La);
	Monomial Mb;
	Mb.append(Lb);
	Polynomial P = (Polynomial)Ma;
	P.append(Mb);

	Letter La2{ 'a',1 };
	Letter Lb2{ 'b',1 };
	Monomial Ma2;
	Ma2.append(La2);
	Monomial Mb2;
	Mb2.append(Lb2);
	Polynomial P2 = (Polynomial)Ma2;
	P2.append(Mb2);
	Polynomial P3 = (P ^ 2) * Ma;
	Polynomial P4 = (P ^ 2) * Mb;
	cout << P3.read(1);
	cout << endl;
	cout << P4.read(0);
	cout << endl;
	cout << (P^4);
	system("pause");
	return 0;
}