#pragma once
#include <iostream>

using namespace std;

template<typename T>
class SLList { //singly linked list
private:

	class Node {
	public:
		T el;
		Node* nextEl;

		Node(T el) 
		{
			this->el = el;
			nextEl = nullptr;
		}
	};

	Node* headEl;
	int listLength;

public:
	SLList() 
	{
		headEl = nullptr;
		listLength = 0;
	}

	void insertEl(T element, int index) 
	{
		if (index <= listLength && index >= 0)
		{
			if (index == 0)
			{
				Node* temp = headEl;
				headEl = new Node(element);
				headEl->nextEl = temp;
				listLength++;
			}
			else
			{
				Node* currEl = headEl;

				for (int i = 0; i < index - 1; i++)
					currEl = currEl->nextEl;

				Node* temp = currEl->nextEl;
				currEl->nextEl = new Node(element);
				currEl->nextEl->nextEl = temp;
				listLength++;
			}
		}
		else
		{
			cout << "  Err: index out of range.\n\n";
			return;
		}
	}

	void appendEl(T element) 
	{
		if (headEl == nullptr) 
		{
			headEl = new Node(element);
			listLength = 1;
		}
		else
		{
			Node* currEl = headEl;

			while (currEl->nextEl != nullptr)
			{
				currEl = currEl->nextEl;
			}

			currEl->nextEl = new Node(element);
			listLength++;
		}
	}

	void deleteEl(int index) 
	{
		if (index < listLength && index >= 0)
		{
			Node* el = headEl;

			for (int i = 0; i < index - 1; i++)
				el = el->nextEl;
			
			if (index != 0) {
				Node* temp = el->nextEl;
				el->nextEl = temp->nextEl;
				delete temp;
			}
			else
				el->nextEl = nullptr;

			listLength--;
		}
		else
		{
			cout << "  Err: index out of range.\n\n";
			return;
		}
	}

	int getLength() {
		return listLength;
	}

	void clear() 
	{
		for (int i = 0; i < listLength; i++)
		{
			Node* temp = headEl;
			headEl = headEl->nextEl;
			delete temp;
		}

		headEl = nullptr;
		listLength = 0;
	}

	T operator[](int index) 
	{
		Node* currEl = headEl;

		if (index < listLength && index >= 0)
		{
			for (int i = 0; i < index; i++)
			{
				currEl = currEl->nextEl;
			}
			return currEl->el;
		}
		else
		{
			cout << "  Err: index out of range.\n\n";
			return -1;
		}
	}

	~SLList()
	{
		clear();
	}
};