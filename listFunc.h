#pragma once
#include "SLList.h"
#include "stack.h"
#include <time.h>

template<typename T>
void listSort(SLList<T>& list)
{
    int temp, j;
    for (int i = 1; i < list.getLength(); i++)
    {
        j = i;
        temp = list[i];
        while (j > 0 && temp < list[j - 1])
        {
            list.insertEl(list[j - 1], j);
            list.deleteEl(j + 1);
            j--;
        }
        list.insertEl(temp, j);
        list.deleteEl(j + 1);
    }
}

void listRndFill(SLList<int>& list, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        list.appendEl(rand() % 50);
}

template<typename T>
void printList(SLList<T>& list) 
{
    cout << "  ";
    for (int i = 0; i < list.getLength(); i++)
        cout << list[i] << " ";
    cout << endl;
}

//--------------------------------------------

template<typename T>
void mergeLists(SLList<T>& list1, SLList<T>& list2, SLList<T>& list_result) 
{
    int len1 = list1.getLength(), len2 = list2.getLength();
    int i = 0, j = 0;

    while (i < len1 && j < len2)
        if (list1[i] <= list2[j])
            list_result.appendEl(list1[i++]);
        else
            list_result.appendEl(list2[j++]);

    if (i < len1)
        for (int k = i; k < len1; k++)
            list_result.appendEl(list1[k]);
    else if (j < len2)
        for (int k = j; k < len2; k++)
            list_result.appendEl(list2[k]);
}

//--------------------------------------------

template<typename T>
pair<int, T> findMax(SLList<T>& list)
{
    int max = list[0];
    int index = 0;

    for (int i = 0; i < list.getLength(); i++)
        if (list[i] >= max)
        {
            max = list[i];
            index = i;
        }

    return make_pair(index, max);
}

template<typename T>
pair<int, T> findMin(SLList<T>& list)
{
    int min = list[0];
    int index = 0;

    for (int i = 0; i < list.getLength(); i++)
        if (list[i] <= min)
        {
            min = list[i];
            index = i;
        }

    return make_pair(index, min);
}

template<typename T>
void swapMinMax(SLList<T>& list, int maxIndex, int minIndex)
{
    T elem1 = list[maxIndex];
    T elem2 = list[minIndex];

    list.insertEl(elem2, maxIndex);
    list.deleteEl(maxIndex + 1);

    list.insertEl(elem1, minIndex);
    list.deleteEl(minIndex + 1);
}

//--------------------------------------------

template<typename T>
void listToStack(SLList<T>& list, Stack<T>& stack)
{
    for (int i = 0; i < list.getLength(); i++)
        stack.push(list[i]);
    cout << "  List -> ";
    stack.print();
}