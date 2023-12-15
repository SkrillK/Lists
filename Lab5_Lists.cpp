#include <iostream>
#include "stack.h"
#include "listFunc.h"

void algorithmChoise()
{
	char answer = ' ';

	cout << "----------------------------------------------------------\n\n";

	cout << "Choose Algorithm.\n 1. Merge two ordered lists.\n";
	cout << " 2. Swap max and min elements of list\n";
	cout << " 3. Sort singly linked list\n";
	cout << " 4. Convert list to stack\n";
	cout << "Or type any other symbol to stop program.\n";
	cout << "Your choice : ";
	cin >> answer;

    switch (answer) {
    default:
        return;
        break;
    case '1': 
    {
        int size1, size2;
        SLList<int> list1, list2, list3;

        cout << "\n  Size of list1: ";
        cin >> size1;

        cout << "  Size of list2: ";
        cin >> size2;

        listRndFill(list1, size1);
        listRndFill(list2, size2);
        listSort(list1);
        listSort(list2);

        cout << "\n  List 1\n";
        printList(list1);
        cout << "\n  List 2\n";
        printList(list2);

        mergeLists(list1, list2, list3);

        cout << "\n  Result of merging\n";
        printList(list3);
        cout << "\n";

        break;
    }
    case '2': 
    {
        SLList<int> list;
        int size;

        cout << "\n  Size of list: ";
        cin >> size;

        listRndFill(list, size);
        cout << "\n  List\n";
        printList(list);

        pair<int, int> max = findMax(list);
        cout << "\n  Max: " << max.second << " | Ind: " << max.first << endl;
        pair<int, int> min = findMin(list);
        cout << "  Min: " << min.second << " | Ind: " << min.first << endl;

        swapMinMax(list, max.first, min.first);
        cout << "\n  Result\n";
        printList(list);
        cout << "\n";

        break;
    }
    case '3': 
    {
        char newUserInput;
        int size;
        SLList<int> list;
        Stack<int> stack;

        cout << "\n  Size of list: ";
        cin >> size;

        listRndFill(list, size);
        cout << "\n  List\n";
        printList(list);

        cout << "\n  Result\n";
        listToStack(list, stack);
        cout << "  Top element in stack: " << stack.getTop() << "\n\n";

        break;
    }
	case '4':
        int size;
        SLList<int> list;

        cout << "\n  Size of list: ";
        cin >> size;

        listRndFill(list, size);

        cout << "\n  Before sorting\n";
        printList(list);

        cout << "\n  List after sort\n";
        listSort(list);
        printList(list);

        cout << "\n";
		break;
	}

	algorithmChoise();
}

int main()
{
	algorithmChoise();
}