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
	//单项式类，字母项实质为一个链表
	//由常数项，字母项，变量项组成
public:
	Monomial();
	~Monomial();
	int size;								//字母项项数（链表长度）
	Letter argument;						//变量项
	int constnum;							//常数项
	void append(Letter data);				//在链表尾部添加
	void remove(int index);					//删除
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
	int size;
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