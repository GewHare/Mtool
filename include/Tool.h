#pragma once
#include "Basics.h"
#include <iostream>
using namespace std;
#ifndef TOOL_H_
#define TOOL_H_
Letter CreatLetter(char letter, int exponent);						//������ĸ��
Monomial CreatMonomial(int constnum, Letter* letters,int l_size);	//��������ʽ
Polynomial CreatPolynomial();										//��������ʽ
Function CreatFunction(Polynomial expression);						//��������
Function CreatLinearFunction(int k, int b, char argument);			//�������Ժ���
void Print(Letter L);			//�����ĸ
void Print(Monomial M);			//�������ʽ
void Print(Polynomial P);		//�������ʽ
void Print(Function F);			//�������
#endif // !TOOL_H_