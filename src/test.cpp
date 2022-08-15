#include "Basics.h"
#include "Tool.h"
#include <iostream>
using namespace std;
int main()
{
	Letter L = CreatLetter('a',2);
	Letter Lb = CreatLetter('a', 2);
	Monomial M;
	M.append(L);
	M.append(Lb);
	Print(M);
	cout << endl;
	system("pause");
	return 0;
}