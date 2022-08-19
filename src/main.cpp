#include <iostream>
#include "Basics.h"
#include "Tool.h"

using namespace std;
int main()
{
	Letter La{ 'a',2 };
	Letter Lb{ 'b',3 };
	Letter Lc{ 'c',5 };
	cout << La;
	cout << endl;
	cout << Lb;
	cout << endl;
	cout << Lc;
	cout << endl;
	Monomial M;
	M.constnum = 6;
	M.append(La);
	M.append(Lb);
	M.append(Lc);
	Monomial M2 = M;
	cout << M;
	cout << M2;
	cout << endl;
	Polynomial P;
	P.append(M);
	P.append(M2);
	Function F(P);
	cout << F;
	system("pause");
	return 0;
}