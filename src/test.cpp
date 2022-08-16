#include "Basics.h"
#include "Tool.h"
#include <iostream>
using namespace std;
int main()
{
	Letter L = CreatLetter('a',2);		//a^2
	Letter Lb = CreatLetter('b', 2);	//b^2
	Letter Lc = CreatLetter('c', 2);	//b^2
	Letter letters[] = { L,Lb,Lc };
	Monomial M = CreatMonomial(5, letters, 3);
	Print(M);
	system("pause");
	return 0;
}