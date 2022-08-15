#pragma once
#ifndef BASICS_H_
#define BASICS_H_
struct Letter
{
	char letter;
	int exponent;
};
struct LUnit
{
	Letter data;
	LUnit* next;
};
class Monomial
{
public:
	Monomial();
	~Monomial();
	int size;
	Letter argument;
	int constnum;
	void append(Letter data);
	void remove(int index);
	void replace(int index, Letter data);
	Letter read(int index);
	Monomial operator+(Monomial M);
	Monomial operator-(Monomial M);
	Monomial operator*(Monomial M);
	Monomial operator/(Monomial M);
private:
	LUnit* head;
	LUnit* tail;
};
#endif // !BASICS_H_