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
	bool operator==(Monomial M);
	Monomial operator+(Monomial M);
	Monomial operator-(Monomial M);
	Monomial operator*(Monomial M);
	Monomial operator/(Monomial M);
private:
	LUnit* head;
	LUnit* tail;
};
struct MUnit
{
	Monomial* data;
	MUnit* next;
};
class Polynomial
{
public:
	Polynomial();
	~Polynomial();
	void append(Monomial data);
	void remove(int index);
	void replace(int index, Monomial data);
	Monomial read(int index);
	Polynomial operator+(Polynomial P);
	Polynomial operator-(Polynomial P);
	Polynomial operator*(Polynomial P);
	Polynomial operator/(Polynomial P);
private:
	MUnit* head;
	MUnit* tail;
};
#endif // !BASICS_H_