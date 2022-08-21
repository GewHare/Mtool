#pragma once
#ifndef _BASICS_H_
#define _BASICS_H_
struct Letter
{
	//字母结构
	char letter;
	int exponent;
};

struct LNode
{
	//节点
	Letter data;
	LNode* next;
};
class Monomial
{
public:
	//单项式类，实质为一个链表
	Monomial();
	~Monomial();
	int size;
	int constnum;
	Letter value;
	void append(const Letter &data);				//向单项式最后添加数据data
	void remove(int index);							//移除下标为index的节点
	void replace(int index, const Letter& data);	//将index处的数据替换为data
	Letter read(int index) const;					//读取index处的数据
	bool operator==(const Monomial M) const;		//判断两个单项式是否为同类项
	Monomial operator+(const Monomial M) const;		//将两个同类项相加
	Monomial operator-(const Monomial M) const;		//将两个同类项相减
	Monomial operator*(const Monomial M) const;		//将两个单项式相乘
	Monomial operator/(const Monomial M) const;		//将两个单项式相除
private:
	LNode* head;			//指向开始节点的指针
	LNode* tail;			//指向最后节点的指针
};

struct MNode
{
	//节点
	Monomial data;
	MNode* next;
};
class Polynomial
{
	//多项式类，实质为链表
public:
	Polynomial();
	~Polynomial();
	int size;								//多项式项数(链表长度)
	void append(const Monomial& data);		//在多项式最后添加data单项式
	void remove(int index);					//删除index位置的节点
	void replace(int index, const Monomial& data);		//将index位置的节点删除
	Monomial read(int index) const;			//读取index处的数据
	Polynomial operator+(const Polynomial& P) const;	//将两个多项式相加
	Polynomial operator-(const Polynomial& P) const;	//将两个多项式相减
	Polynomial operator*(const Polynomial& P) const;	//将两个多项式相乘
	Polynomial operator/(const Polynomial& P) const;	//将两个多项式相除
private:
	MNode* head;			//指向开始节点的指针
	MNode* tail;			//指向结束节点的指针
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
	void set_value(char terget);//设置自变量
	int solve_y(int x);			//求Y
	int solve_x(int y);			//求X
private:
};
#endif // !_BASICS_H_