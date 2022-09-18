#include <iostream>
#include <map>
#include "Basics.h"
#include "Tool.h"

using namespace std;
void PolynomialExponentSample();		//示例，输出(a+b)的x次方；
void LinearFunctionSample();				//示例，用户自定义线性函数并求解；
int main()
{
	PolynomialExponentSample();
	system("pause");
	return 0;
}

void PolynomialExponentSample()
{
	int x=0;
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
	cout << "计算(a+b)的X次方" << endl;
	cout << "X:";
	cin >> x;
	cout << (P ^ x);
}

void LinearFunctionSample()
{
	int k; int b; int x;
	Letter Lk{ 'k',1 };
	Letter Lx{ 'x',1 };
	Monomial M1;
	M1.append(Lk);
	M1.append(Lx);

	Letter Lb{ 'b',1 };
	Monomial M2;
	M2.append(Lb);

	Polynomial E;
	E.append(M1);
	E.append(M2);

	Function F(E,'x');
	cout << "函数模板:";
	cout << F << endl;
	cout << "k:";
	cin >> k;
	cout << endl;
	cout << "b:";
	cin >> b;
	cout << endl;
	ArgumentMap arg;
	arg.insert('k', k);
	arg.insert('b', b); 
	Function Fx = F.set_RE(arg);
	cout << "实际函数解析式：" << Fx<< endl;
	cout << "x:";
	cin >> x;
	cout << endl;
	cout<<Fx.solve_y(x);
	cout << endl;
}
