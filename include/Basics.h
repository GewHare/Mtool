#pragma once
#ifndef BASICS_H_
#define BASICS_H_
int pow(int tn, int ex);	//һ������ƽ����
struct Letter
{
	//��ĸ��
	char letter;			//��ĸ
	int exponent;			//��ĸ��ָ��
};							
struct LUnit
{
	//����ʽ�����ÿ����Ԫ
	Letter data;			//��Ԫ����
	LUnit* next;			//ָ����һ����Ԫ��ָ��;
};
class Monomial
{
	//����ʽ�࣬��ĸ��ʵ��Ϊһ������
	//�ɳ������ĸ����������
public:
	Monomial();
	~Monomial();
	int size;								//��ĸ�������������ȣ�
	Letter argument;						//������
	int constnum;							//������
	void append(Letter data);				//������β�����
	void remove(int index);					//ɾ��
	void replace(int index, Letter data);	//�滻
	Letter read(int index);					//��ȡ
	bool operator==(Monomial M);
	Monomial operator+(Monomial M);
	Monomial operator-(Monomial M);
	Monomial operator*(Monomial M);
	Monomial operator/(Monomial M);
private:
	LUnit* head;							//ָ��ʼ��Ԫ��ָ��
	LUnit* tail;							//ָ�������Ԫ��ָ��
};

struct MUnit
{

	Monomial* data;
	MUnit* next;
};
class Polynomial
{
	//����ʽ�࣬�ɶ������ʽ���
	//����ʽ��ʵ�ʻ���������*^____^*
public:
	Polynomial();
	~Polynomial();
	int size;								//����ʽ�����������ȣ�
	void append(Monomial data);				//�ڵ���ʽĩβ���
	void remove(int index);					//ɾ��
	void replace(int index, Monomial data);	//�滻
	Monomial read(int index);				//��ȡ
	Polynomial operator+(Polynomial P);
	Polynomial operator-(Polynomial P);
	Polynomial operator*(Polynomial P);
	Polynomial operator/(Polynomial P);
private:
	MUnit* head;							//ָ���һ����Ԫ��ָ��
	MUnit* tail;							//ָ�����Ԫ��ָ��
};

class Arguments
{
	//�����г����ַ��������ַ��Ķ��ձ�
	//ʵ��Ϊһ����ϣ��
public:
	Arguments();
	~Arguments();
	int* arrary;						//�洢��ϣ�����ݵ�����
	int index(char name);				//����ת��Ϊ����
	void insert(char name, int data);	//�����Ϊname������data
	int read(char name);				//��ѯname������
private:
};
class Function
{
	//������
public:
	Function(Polynomial E);
	~Function();
	char id;					//���������ƣ�Ψһ��ʶ����
	Letter value;				//�������Ա���
	Arguments* args;			//�����������������ձ��ַ
	Polynomial expression;		//��������ʽ������ʽ��
	int solve_y(int x);			//��Y
	int solve_x(int y);			//��X
private:
};
#endif // !BASICS_H_