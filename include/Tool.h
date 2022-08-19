#pragma once
#include<iostream>
#include"Basics.h"
using namespace std;
#ifndef _TOOL_H_
#define _TOOL_H_
ostream& operator<<(ostream& O, const Letter& L);
ostream& operator<<(ostream& O, const Monomial& M);
ostream& operator<<(ostream& O, const Polynomial& P);
ostream& operator<<(ostream& O, const Function& F);
#endif // !_TOOL_H_
