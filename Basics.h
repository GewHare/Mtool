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
	Letter letter;
	LUnit* nextpoint;
};
class Monomial
{
public:
	Monomial();
	~Monomial();
private:
	LUnit* head;
};

#endif // !BASICS_H_
