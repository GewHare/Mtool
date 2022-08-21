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
	Function Fx(E);
	Fx.set_value('x');
	Fx.args->insert('k', 1);
	Fx.args->insert('d', 1);
	cout << Fx.args->read('k');
	Fx.set_RE();
	system("pause");
	return 0;
}