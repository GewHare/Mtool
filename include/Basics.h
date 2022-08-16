#pragma once
#ifndef BASICS_H_
#define BASICS_H_
int pow(int tn, int ex);	//一个数的平方；
struct Letter
{
	//字母项
	char letter;			//字母
	int exponent;			//字母的指数
};							
struct LUnit
{
	//单项式链表的每个单元
	Letter data;			//单元数据
	LUnit* next;			//指向下一个单元的指针;
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
	void replace(int index, Letter data);	//替换
	Letter read(int index);					//读取
	bool operator==(Monomial M);
	Monomial operator+(Monomial M);
	Monomial operator-(Monomial M);
	Monomial operator*(Monomial M);
	Monomial operator/(Monomial M);
private:
	LUnit* head;							//指向开始单元的指针
	LUnit* tail;							//指向结束单元的指针
};

struct MUnit
{

	Monomial* data;
	MUnit* next;
};
class Polynomial
{
	//多项式类，由多个单项式组成
	//多项式的实质还是链表是*^____^*
public:
	Polynomial();
	~Polynomial();
	int size;								//多项式项数（链表长度）
	void append(Monomial data);				//在单项式末尾添加
	void remove(int index);					//删除
	void replace(int index, Monomial data);	//替换
	Monomial read(int index);				//读取
	Polynomial operator+(Polynomial P);
	Polynomial operator-(Polynomial P);
	Polynomial operator*(Polynomial P);
	Polynomial operator/(Polynomial P);
private:
	MUnit* head;							//指向第一个单元的指针
	MUnit* tail;							//指向最后单元的指针
};

class Arguments
{
	//函数中常量字符、变量字符的对照表
	//实质为一个哈希表
public:
	Arguments();
	~Arguments();
	int* arrary;						//存储哈希表数据的数组
	int index(char name);				//将键转换为数字
	void insert(char name, int data);	//插入键为name的数据data
	int read(char name);				//查询name的数据
private:
};
class Function
{
	//函数类
public:
	Function(Polynomial E);
	~Function();
	char id;					//函数的名称（唯一标识符）
	Letter value;				//函数的自变量
	Arguments* args;			//常量，变量参数对照表地址
	Polynomial expression;		//函数解析式（多项式）
	int solve_y(int x);			//求Y
	int solve_x(int y);			//求X
private:
};
#endif // !BASICS_H_