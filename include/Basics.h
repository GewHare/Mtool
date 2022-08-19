#pragma once
#ifndef _BASICS_H_
#define _BASICS_H_
struct Letter
{
	char letter;
	int exponent;
};

struct LNode
{
	Letter data;
	LNode* next;
};
class Monomial
{
public:
	Monomial();
	~Monomial();
	int size;
	int constnum;
	Letter value;
	void append(const Letter &data);
	void remove(int index);
	void replace(int index, const Letter& data);
	Letter read(int index) const;
	bool operator==(const Monomial M) const;
	Monomial operator+(const Monomial M) const;
	Monomial operator-(const Monomial M) const;
	Monomial operator*(const Monomial M) const;
	Monomial operator/(const Monomial M) const;
private:
	LNode* head;
	LNode* tail;
};

struct MNode
{
	Monomial data;
	MNode* next;
};
class Polynomial
{
public:
	Polynomial();
	~Polynomial();
	int size;
	void append(const Monomial& data);
	void remove(int index);
	void replace(int index, const Monomial& data);
	Monomial read(int index) const;
	Polynomial operator+(const Polynomial& P) const;
	Polynomial operator-(const Polynomial& P) const;
	Polynomial operator*(const Polynomial& P) const;
	Polynomial operator/(const Polynomial& P) const;
private:
	MNode* head;
	MNode* tail;
};

class ArgumentMap
{
public:
	ArgumentMap();
	~ArgumentMap();
	int index(char name) const;				//将键转换为数字
	void insert(char name, int data);	//插入键为name的数据data
	int read(char name) const;				//查询name的数据
private:
	int* arrary;						//存储哈希表数据的数组
};

class Function
{
	//函数类
public:
	Function(const Polynomial& E);
	~Function();
	char id;					//函数的名称（唯一标识符）
	Letter value;				//函数的自变量
	ArgumentMap* args;			//常量，变量参数对照表地址
	Polynomial expression;		//函数解析式（多项式）
	int solve_y(int x);			//求Y
	int solve_x(int y);			//求X
private:
};
#endif // !_BASICS_H_