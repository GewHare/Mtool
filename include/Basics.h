#pragma once
#include <cmath>
#ifndef _BASICS_H_
#define _BASICS_H_
struct Letter
{
	//��ĸ�ṹ
	char letter;
	int exponent;
};

struct LNode
{
	//�ڵ�
	Letter data;
	LNode* next;
};
class Monomial
{
public:
	//����ʽ�࣬ʵ��Ϊһ������
	Monomial();
	~Monomial();
	int size;
	int constnum;
	Letter value;
	void append(const Letter &data);				//����ʽ����������data
	void remove(int index);							//�Ƴ��±�Ϊindex�Ľڵ�
	void replace(int index, const Letter& data);	//��index���������滻Ϊdata
	Letter read(int index) const;					//��ȡindex��������
	bool operator==(const Monomial M) const;		//�ж���������ʽ�Ƿ�Ϊͬ����
	Monomial operator+(const Monomial M) const;		//������ͬ�������
	Monomial operator-(const Monomial M) const;		//������ͬ�������
	Monomial operator*(const Monomial M) const;		//����������ʽ���
	Monomial operator/(const Monomial M) const;		//����������ʽ���
private:
	LNode* head;			//ָ��ʼ�ڵ��ָ��
	LNode* tail;			//ָ�����ڵ��ָ��
};

struct MNode
{
	//�ڵ�
	Monomial data;
	MNode* next;
};
class Polynomial
{
	//����ʽ�࣬ʵ��Ϊ����
public:
	Polynomial();
	~Polynomial();
	int size;								//����ʽ����(������)
	void append(const Monomial& data);		//�ڶ���ʽ������data����ʽ
	void remove(int index);					//ɾ��indexλ�õĽڵ�
	void replace(int index, const Monomial& data);		//��indexλ�õĽڵ�ɾ��
	Monomial& read(int index) const;			//��ȡindex��������
	Polynomial operator+(const Polynomial& P) const;	//����������ʽ���
	Polynomial operator-(const Polynomial& P) const;	//����������ʽ���
	Polynomial operator*(const Polynomial& P) const;	//����������ʽ���
	Polynomial operator/(const Polynomial& P) const;	//����������ʽ���
private:
	MNode* head;			//ָ��ʼ�ڵ��ָ��
	MNode* tail;			//ָ������ڵ��ָ��
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
	char value;				//�������Ա���
	ArgumentMap* args;			//�����������������ձ��ַ
	Polynomial expression;		//����ģ�����ʽ������ʽ��
	Polynomial real_expression;//����ʵ�ʽ���ʽ
	void set_value(char terget);//�����Ա���
	void set_RE();
	int solve_y(int x);			//��Y
	int solve_x(int y);			//��X
private:
};
#endif // !_BASICS_H_