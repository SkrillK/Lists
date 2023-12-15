#pragma once
#include "SLList.h"

using namespace std;

template <typename T>
class Stack {
public:
	void push(T value) 
	{
		stack_data.appendEl(value);
		len++;
	}

	void pop() {
		if (isEmpty()) 
		{
			cout << "  Error: can’t pop from empty stack.\n\n";
			return;
		}
		stack_data.deleteEl(len - 1);
		len--;
	}

	bool isEmpty()
	{
		return (len < 1);
	}

	size_t getLength() 
	{
		return len;
	}

	T getTop()
	{
		if (isEmpty())
		{
			cout << "  Error: stack is empty.\n\n";
			return -1;
		}
		else
			return stack_data.operator[](len - 1);
	}

	void print()
	{
		if (isEmpty())
		{
			cout << "  Error: stack is empty.\n\n";
			return;
		}
		else
		{
			cout << "Stack:\n  ";
			for (int i = 0; i < len; i++)
				cout << stack_data.operator[](i) << " ";
			cout << "\n\n";
		}
	}

	void clear()
	{
		for (int i = len - 1; i >= 0; i--)
			stack_data.deleteEl(i);
		len = 0;
	}

private:
	SLList<T> stack_data;
	int len;
};
