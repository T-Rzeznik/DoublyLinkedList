#include "dnode.h"
#include <iostream>
using namespace std;

dnode::value_type dnode::get_data()
{
	return data_field;
}

dnode* dnode::get_prev_link()
{
	return prev_link_field;
}

dnode* dnode::get_next_link()
{
	return next_link_field;
}

void dnode::set_data(value_type entry)
{
	data_field = entry;
}

void dnode::set_prev_link(dnode* prev_link_ptr)
{
	prev_link_field = prev_link_ptr;
}

void dnode::set_next_link(dnode* next_link_ptr)
{
	next_link_field = next_link_ptr;
}

dnode::dnode(value_type entry, dnode* prev_link_ptr, dnode* next_link_ptr)
{
	data_field = entry;
	prev_link_field = prev_link_ptr;
	next_link_field = next_link_ptr;
}

void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry)
{
	head_ptr = new dnode(entry, nullptr, head_ptr);
	if (head_ptr->get_next_link() != nullptr)
		head_ptr->get_next_link()->set_prev_link(head_ptr);
}

void list_head_remove(dnode*& head_ptr)
{
	dnode* remove_ptr;
	remove_ptr = head_ptr;
	head_ptr = head_ptr->get_next_link(); // head_ptr = (*head_ptr).get_link();
	head_ptr->set_prev_link(nullptr);
	delete remove_ptr;
}

void list_insert(dnode*& previous_ptr, const dnode::value_type& entry)
{
	dnode* insert_ptr;
	insert_ptr = new dnode(entry, previous_ptr, previous_ptr->get_next_link());
	previous_ptr->set_next_link(insert_ptr);
	if (insert_ptr->get_next_link() != nullptr)
		insert_ptr->get_next_link()->set_prev_link(insert_ptr);
}

void list_remove(dnode*& previous_ptr)
{
	dnode* remove_ptr;
	remove_ptr = previous_ptr->get_next_link();
	previous_ptr->set_next_link(remove_ptr->get_next_link());
	remove_ptr->get_next_link()->set_prev_link(previous_ptr);
	delete remove_ptr;
}

void list_display(dnode*& head_ptr)
{
	dnode* cursor;
	cursor = head_ptr;
	while (cursor != nullptr)
	{
		cout << cursor->get_data() << endl;
		cursor = cursor->get_next_link();
	}
}

int list_length(dnode*& head_ptr)
{
	dnode* cursor;
	cursor = head_ptr;
	int length = 0;
	while (cursor != nullptr)
	{
		length++;
		cursor = cursor->get_next_link();
	}
	return length;
}

dnode* list_search(dnode* head_ptr, const dnode::value_type& target)
{
	dnode* cursor;
	cursor = head_ptr;
	while (cursor != nullptr)
	{
		if (cursor->get_data() == target)
		{
			return cursor;
		}
		else
			cursor = cursor->get_next_link();
	}
	return nullptr;
}

dnode* list_locate(dnode* head_ptr, int position)
{
	dnode* cursor = head_ptr;
	int i = 1;
	while ((i < position) && (cursor != nullptr))
	{
		i++;
		cursor = cursor->get_next_link();
	}
	return cursor;
}

void list_clear(dnode*& head_ptr)
{
	while (head_ptr != nullptr)
	{
		list_head_remove(head_ptr);
	}
}

void list_copy(dnode* source_ptr, dnode*& head_ptr)
{
	dnode* cursor;
	head_ptr = nullptr;
	if (source_ptr == nullptr)
	{
		return;
	}
	list_head_insert(head_ptr, source_ptr->get_data());
	cursor = head_ptr;
	source_ptr = source_ptr->get_next_link();
	while (source_ptr != nullptr)
	{
		list_insert(cursor, source_ptr->get_data());
		cursor = cursor->get_next_link();
		source_ptr = source_ptr->get_next_link();
	}
}

dnode* list_reverse(dnode*& head_ptr)
{
	dnode* cursor;
	cursor = head_ptr;

	dnode* temp = nullptr;

	
		while (cursor != nullptr)
		{
			temp = cursor->get_prev_link();
			cursor->set_prev_link(cursor->get_next_link());
			cursor->set_next_link(temp);
			cursor = cursor->get_prev_link();
		}
		head_ptr = temp->get_prev_link();
	
	return head_ptr;
}