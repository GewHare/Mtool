#include "Basics.h"
#include "Tool.h"
#include <iostream>
using namespace std;
int main()
{
	Letter L = CreatLetter('a',2);		//a^2
	Letter Lb = CreatLetter('b', 2);	//b^2
	Letter Lc = CreatLetter('c', 2);	//b^2
	Letter* letters = new Letter[3]{L,Lb,Lc};
	Letter* letters2 = new Letter[3]{ L,Lb,Lc };
	Monomial M = CreatMonomial(5, letters, 3);
	Monomial M2 = CreatMonomial(5, letters2, 3);
	Monomial** ms = new Monomial * [2]{ &M,&M2 };
	Polynomial P = CreatPolynomial(ms, 2);
	Print(P);
	cout << endl;
	system("pause");
	return 0;
}