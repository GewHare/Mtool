#pragma once
#include "Basics.h"
#include <iostream>
using namespace std;
#ifndef TOOL_H_
#define TOOL_H_
Letter CreatLetter(char letter, int exponent);
Monomial CreatMonomial(int constnum, Letter* letters);
void Print(Letter L);
void Print(Monomial M);
void Print(Polynomial P);
#endif // !TOOL_H_