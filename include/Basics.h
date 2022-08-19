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
	int index(char name) const;				//����ת��Ϊ����
	void insert(char name, int data);	//�����Ϊname������data
	int read(char name) const;				//��ѯname������
private:
	int* arrary;						//�洢��ϣ�����ݵ�����
};

class Function
{
	//������
public:
	Function(const Polynomial& E);
	~Function();
	char id;					//���������ƣ�Ψһ��ʶ����
	Letter value;				//�������Ա���
	ArgumentMap* args;			//�����������������ձ��ַ
	Polynomial expression;		//��������ʽ������ʽ��
	int solve_y(int x);			//��Y
	int solve_x(int y);			//��X
private:
};
#endif // !_BASICS_H_