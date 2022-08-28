#pragma once
#include <cmath>
#ifndef _BASICS_H_
#define _BASICS_H_
struct Letter
{
	//��ĸ�ṹ
	char letter;
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
	~LinkList();
	int size;
	void append(const T& data);
	void remove(int index);
	void replace(int index, const T& data);
	T& read(int index) const;
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
};

template<typename T>
LinkList<T>::LinkList()
{
	size = 0;
	head = 0;
	tail = 0;
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
	//����ʽ�࣬ʵ��Ϊһ������
	Monomial();
	~Monomial();
	double constnum;
	Letter value;
	void sort(char mode = 'L');						//����,'L'Ϊ����ĸ��ASCII�������'E'Ϊ����ĸ��ָ������
	Monomial copy() const;								//���ƹ��캯������ʱ���Ʒ
	bool operator==(const Monomial& M) const;		//�ж���������ʽ�Ƿ�Ϊͬ����
	Monomial operator+(const Monomial& M) const;		//������ͬ�������
	Monomial operator-(const Monomial& M) const;		//������ͬ�������
	Monomial operator*(const Monomial& M) const;		//����������ʽ���
	Monomial operator*(double D) const;				//����������ʽ���
	Monomial operator/(const Monomial& M) const;		//����������ʽ���
	Monomial operator/(double D) const;				//����������ʽ���
private:
};

class Polynomial:public LinkList<Monomial>
{
	//����ʽ�࣬ʵ��Ϊ����
public:
	Polynomial();
	Polynomial(double D);
	explicit Polynomial(Monomial M);
	~Polynomial();
	void sort(char mode = 'L');
	Polynomial copy() const;									//��ʱ�������ƹ��캯�������Ʒ
	Polynomial operator+(const Monomial& M) const;
	Polynomial operator+(const Polynomial& P) const;	//����������ʽ���

	void operator+=(const Polynomial& P);
	void operator+=(const Monomial& M);

	Polynomial operator-(const Polynomial& P) const;	//����������ʽ���
	Polynomial operator-(const Monomial& M) const;

	void operator-=(const Polynomial& P);
	void operator-=(const Monomial& M);

	Polynomial operator*(const Polynomial& P) const;	//����������ʽ���
	Polynomial operator*(const Monomial& M) const;

	void operator*=(const Polynomial& P);
	void operator*=(const Monomial& M);

	Polynomial operator/(const Polynomial& P) const;	//����������ʽ���
	Polynomial operator/(const Monomial& M) const;

	void operator/=(const Polynomial& P);
	void operator/=(const Monomial& M);

	Polynomial operator^(int ex) const;					//����ʽ��ex�η�
private:
};

class Equation:public LinkList<Polynomial>
{
public:
	Equation();
	~Equation();
	void operator+(const Polynomial& P);
	void operator-(const Polynomial& P);
	void operator*(const Polynomial& P);
	void operator/(const Polynomial& P);
	void operator=(const Polynomial& P);
private:
};

class Inequation:public LinkList<Polynomial>
{
public:
	Inequation();
	~Inequation();
	Inequation operator+(const Polynomial& P);
	Inequation operator-(const Polynomial& P);
	Inequation operator*(const Polynomial& P);
	Inequation operator/(const Polynomial& P);
private:
};

class ArgumentMap
{
	//�������ձ��࣬ʵ��Ϊ��ϣ��
public:
	ArgumentMap();
	~ArgumentMap();
	void insert(char name, int data);	//�����Ϊname������data
	double read(char name) const;				//��ѯname������
private:
	double* arrary;						//�洢��ϣ�����ݵ�����
};

class Function
{
	//������
public:
	Function(const Polynomial& E, char value, char id = 'f');
	Function();
	~Function();
	char id;					//���������ƣ�Ψһ��ʶ����
	char value;					//�������Ա���
	Polynomial expression;		//��������ʽ������ʽ��
	void set_value(char terget);//�����Ա���
	Function set_RE(const ArgumentMap& arg);	//��������úó���ֵ�ĺ�������ʽ
	double solve_y(int x);			//��Y
	double solve_x(int y);			//��X
private:
};
Vector operator+(Vector S, Vector E);
Vector operator-(Vector S, Vector E);
Vector operator*(Vector S, Vector E);
Vector operator/(Vector S, Vector E);
#endif // !_BASICS_H_