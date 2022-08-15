#include "Basics.h"
#include "Tool.h"
#include <iostream>
using namespace std;
int main()
{
	Letter L = CreatLetter('a',2);		//a^2
	Letter Lb = CreatLetter('b', 2);	//b^2
	Letter Lc = CreatLetter('c', 2);	//b^2
	Monomial M;
	M.append(L);
	M.constnum = 2;
	Monomial M2;
	M2.append(Lb);
	M2.constnum = 3;
	Polynomial P;
	P.append(M);
	Polynomial P2;
	P2.append(M2);
	Polynomial P3 = P + P2;
	cout << P3.size;
	Print(P3.read(1));
	cout << endl;
	cout << P3.read(1).read(0).exponent;
	cout << endl;
	system("pause");
	return 0;
}