#pragma once
#include<iostream>
#include"Basics.h"
using namespace std;
#ifndef _TOOL_H_
#define _TOOL_H_
ostream& operator<<(ostream& O, const Letter& L);			//输出Letter对象(字母)
ostream& operator<<(ostream& O, const Monomial& M);			//输出Monomial对象(单项式)
ostream& operator<<(ostream& O, const Polynomial& P);		//输出Polynomial对象(多项式)
ostream& operator<<(ostream& O, const Function& F);			//输出Function对象(函数)
#endif // !_TOOL_H_
