#pragma once
#include<iostream>
#include"Basics.h"
using namespace std;
#ifndef _TOOL_H_
#define _TOOL_H_
ostream& operator<<(ostream& O, const Letter& L);			//���Letter����(��ĸ)
ostream& operator<<(ostream& O, const Point& P);			//���Point����(ֱ������ϵ)
ostream& operator<<(ostream& O, const Monomial& M);			//���Monomial����(����ʽ)
ostream& operator<<(ostream& O, const Polynomial& P);		//���Polynomial����(����ʽ)
ostream& operator<<(ostream& O, const Function& F);			//���Function����(����)
#endif // !_TOOL_H_
