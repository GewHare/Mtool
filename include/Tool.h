#pragma once
#include "Basics.h"
#include <iostream>
using namespace std;
#ifndef TOOL_H_
#define TOOL_H_
Letter CreatLetter(char letter, int exponent);						//创建字母项
Monomial CreatMonomial(int constnum, Letter* letters,int l_size);	//创建单项式
Polynomial CreatPolynomial(Monomial** ms,int m_size);										//创建多项式
Function CreatFunction(Polynomial expression);						//创建函数
Function CreatLinearFunction(int k, int b, char argument);			//创建线性函数
void Print(Letter L);			//输出字母
void Print(Monomial M);			//输出单项式
void Print(Polynomial P);		//输出多项式
void Print(Function F);			//输出函数
#endif // !TOOL_H_