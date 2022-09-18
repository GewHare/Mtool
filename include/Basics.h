#pragma once
#include <cmath>
#ifndef _BASICS_H_
#define _BASICS_H_
typedef unsigned char charex;
class ArgumentMap;
struct Letter
{
	//字母结构
	charex letter;
	double exponent;
};

struct Point
{
	double x;
	double y;
};

struct Vector
{
	Point start;
	Point end;
};

template<typename T>
class LinkList
{
public:
	LinkList();
	LinkList(const LinkList& L);
	~LinkList();
	int size;
	void append(const T& data);					//链表尾部添加data;
	void remove(int index);						//删除链表index处的数据（和node节点）
	void replace(int index, const T& data);     //将链表index处的数据替换为data
	T& read(int index) const;					//返回链表index处的数据
private:
	struct Node									//节点
	{
		T data;	    //数据
		Node* next;//指向下一个节点的指针，如果此节点为最后，则为空指针
	};
	Node* head;//指向开始节点的指针
	Node* tail;//指向最后节点的指针
};

template<typename T>
LinkList<T>::LinkList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
LinkList<T>::LinkList(const LinkList& L)
{
	size = 0;
	head = nullptr;
	tail = nullptr;
	for (int i = 0; i < L.size; i++)
	{
		append(L.read(i));
	}
}


template<typename T>
LinkList<T>::~LinkList()
{
}

template<typename T>
void LinkList<T>::append(const T& data)
{
	if (tail == 0)
	{
		head = new Node{ data,0 };
		tail = head;
		size++;
	}
	else
	{
		tail->next = new Node{ data,0 };
		tail = tail->next;
		size++;
	}
}

template<typename T>
void LinkList<T>::remove(int index)
{
	Node* del_unit = head;
	Node* b_unit = head;
	if (index >= size)
	{
	}
	else
	{
		if (index == 0)
		{
			head = del_unit->next;
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				b_unit = del_unit;
				del_unit = del_unit->next;
			}
			b_unit->next = del_unit->next;
		}
	}
	if (del_unit->next == 0)
		tail = b_unit;
	delete del_unit;
	size--;
}

template<typename T>
void LinkList<T>::replace(int index, const T& data)
{
	Node* re_u = head;
	for (int i = 0; i < index; i++)
		re_u = re_u->next;
	re_u->data = data;
}

template<typename T>
T& LinkList<T>::read(int index) const
{
	if (index >= size)
	{
	}
	else
	{
		Node* re_u = head;
		for (int i = 0; i < index; i++)
			re_u = re_u->next;
		return (re_u->data);
	}
}

class Monomial:public LinkList<Letter>
{
public:
	//单项式类，实质为一个链表
	Monomial();
	~Monomial();
	double constnum;
	Letter value;
	void sort(char mode = 'L');						//排序,'L'为按字母的ASCII码表排序，'E'为按字母的指数排序
	Monomial copy() const;							//复制构造函数的暂时替代品
	bool operator==(const Monomial& M) const;		//判断两个单项式是否为同类项
	Monomial operator+(const Monomial& M) const;	//将两个同类项相加
	Monomial operator-(const Monomial& M) const;	//将两个同类项相减
	Monomial operator*(const Monomial& M) const;	//将两个单项式相乘
	Monomial operator*(double D) const;				//将两个单项式相乘
	Monomial operator/(const Monomial& M) const;	//将两个单项式相除
	Monomial operator/(double D) const;				//将两个单项式相除
private:
};

class Polynomial:public LinkList<Monomial>
{
	//多项式类，实质为链表
public:
	Polynomial();
	Polynomial(double D);
	explicit Polynomial(Monomial M);
	~Polynomial();
	void sort(char mode = 'L');
	static ArgumentMap PMap;
	double value_max;
	double value_min;
	Polynomial operator+(const Monomial& M) const;		//将一个多项式与一个单项式相加
	Polynomial operator+(const Polynomial& P) const;	//将两个多项式相加

	void operator+=(const Polynomial& P);				//一个多项式加等于一个多项式
	void operator+=(const Monomial& M);					//一个多项式加等于一个单项式

	Polynomial operator-(const Polynomial& P) const;	//将两个多项式相减
	Polynomial operator-(const Monomial& M) const;		//多项式减去一个单项式

	void operator-=(const Polynomial& P);				//一个多项式减等于一个多项式
	void operator-=(const Monomial& M);					//一个多项式减等于一个单项式

	Polynomial operator*(const Polynomial& P) const;	//将两个多项式相乘
	Polynomial operator*(const Monomial& M) const;		//将一个多项式与一个单项式相乘

	void operator*=(const Polynomial& P);				//一个多项式乘等于一个多项式
	void operator*=(const Monomial& M);					//一个多项式乘等于一个单项式

	Polynomial operator/(const Polynomial& P) const;	//将两个多项式相除
	Polynomial operator/(const Monomial& M) const;		//将一个多项式除以一个单项式

	void operator/=(const Polynomial& P);				//将一个多项式除以等于一个多项式
	void operator/=(const Monomial& M);					//将一个多项式除以等于一个单项式

	Polynomial operator^(int ex) const;					//多项式的ex次方
private:
};

class Equation:public LinkList<Polynomial>
{
	//等式
public:
	Equation();
	~Equation();
	void operator+(const Polynomial& P);				//同加，将等式所有项同加P；
	void operator-(const Polynomial& P);				//同减，将等式所有项同减P；
	void operator*(const Polynomial& P);				//同乘，将等式所有项同乘P；
	void operator/(const Polynomial& P);				//同除，将等式所有项同除P；
private:
};

class Inequation:public LinkList<Polynomial>
{
	//等式
public:
	Inequation();
	~Inequation();
	Inequation operator+(const Polynomial& P);			//同加，将不等式所有项同加P；
	Inequation operator-(const Polynomial& P);			//同减，将不等式所有项同减P；
	Inequation operator*(const Polynomial& P);			//同乘，将不等式所有项同乘P(constnum)常数为负应变号；
	Inequation operator/(const Polynomial& P);			//同除，将不等式所有项同除P(constnum)常数为负应变号；
private:
};

class ArgumentMap
{
	//常量对照表类，实质为哈希表
public:
	ArgumentMap();
	~ArgumentMap();
	void insert(char name, int data);	//插入键为name的数据data
	double read(char name) const;				//查询name的数据
private:
	double* arrary;						//存储哈希表数据的数组
};

class Function
{
	//函数类
public:
	Function(const Polynomial& E, char value, char id = 'f');
	Function();
	~Function();
	char id;					//函数的名称（唯一标识符）
	char value;					//函数的自变量
	Polynomial expression;		//函数解析式（多项式）
	void set_value(char terget);//设置自变量
	Function set_RE(const ArgumentMap& arg);	//输出被设置好常量值的函数解析式
	double solve_derived(double x);	//求在X的导数
	Function solve_Dfunction();		//求其导函数
	double solve_y(int x);			//求Y
	double solve_y(double* x,int size);
	double solve_y(double min, double max, double step);
	double solve_x(int y);			//求X
private:
};
Vector operator+(Vector S, Vector E);					//向量相加
Vector operator-(Vector S, Vector E);					//向量相减
Vector operator*(Vector S, Vector E);					//向量相乘
Vector operator/(Vector S, Vector E);					//向量相除
#endif // !_BASICS_H_