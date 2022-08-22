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
	E.append(M1);
	E.append(M2);
	ArgumentMap arg;
	arg.insert('k', 1);
	arg.insert('b', 1);
	Function Fx(E, 'x');
	Function F= Fx.set_RE(arg);
	cout << F.solve_y(2);
	system("pause");
	return 0;
}