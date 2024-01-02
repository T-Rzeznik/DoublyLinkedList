#include <iostream>
#include "dnode.h"
using namespace std;



int main()
{
	dnode* list1 = nullptr;
	
	
	list_head_insert(list1, 1001);
	list_insert(list1, 12);
	list_insert(list1, 11);
	list_insert(list1, 10);

	list_display(list1);
	
	
	cout << "After reversing the list: " << endl;
	list_reverse(list1);
	list_display(list1);

}