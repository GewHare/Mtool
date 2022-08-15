#include "Basics.h"
#include "Tool.h"
#include <iostream>
using namespace std;
int main()
{
	Letter L = CreatLetter('a',3);
	Letter Lb = CreatLetter('b', 2);
	Monomial M;
	M.constnum = 2;
	M.append(L);
	M.append(Lb);
	Monomial M2;
	M2.constnum = 3;
	M2.append(Lb);
	M2.append(L);
	Print(M);
	cout << endl;
	Print(M2);
	cout << endl;
	Print(M/M2);
	cout << endl;
	system("pause");
	return 0;
}