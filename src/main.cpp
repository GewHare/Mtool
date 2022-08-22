#include <iostream>
#include "Basics.h"
#include "Tool.h"

using namespace std;
int main()
{
	Letter Lk{ 'k',1 };
	Letter Lb{ 'b',1 };
	Letter Lx{ 'x',1 };
	Monomial M1;
	M1.append(Lk);
	M1.append(Lx);
	Monomial M2;
	M2.append(Lb);
	Polynomial E;
	Polynomial E2;
	E.append(M1);
	E2.append(M2);
	cout << E * E;
	system("pause");
	return 0;
}