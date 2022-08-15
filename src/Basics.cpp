#include "Basics.h"

Monomial::Monomial()
{
	head = 0;
	tail = 0;
	size = 0;
	constnum = 0;
	argument = { 0,0 };
}

Monomial::~Monomial()
{
}

void Monomial::append(Letter data)
{
	if (tail == 0)
	{
		head = new LUnit;
		head->data = data;
		head->next = 0;
		tail = head;
		size++;
	}
	else
	{
		tail->next = new LUnit;
		tail = tail->next;
		tail->data = data;
		tail->next = 0;
		size++;
	}
}

void Monomial::remove(int index)
{
	if (index >= size)
	{}
	else
	{
		LUnit* del_unit=head;
		LUnit* b_unit=head;
		if (index == 0)
		{
			head = del_unit->next;
			delete del_unit;
			size--;
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				b_unit = del_unit;
				del_unit = del_unit->next;
			}
			b_unit->next = del_unit->next;
			delete del_unit;
			size--;
		}
	}
}

void Monomial::replace(int index, Letter data)
{
	LUnit* re_u = head;
	for (int i = 0; i < index; i++)
		re_u = re_u->next;
	re_u->data = data;
}

Letter Monomial::read(int index)
{
	if (index >= size)
	{
		return Letter{ 0,0 };
	}
	else
	{
		LUnit* re_u = head;
		for (int i = 0; i < index; i++)
			re_u = re_u->next;
		return (re_u->data);
	}
}
