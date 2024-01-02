#pragma once

class dnode
{
public:
	typedef int value_type;
	value_type get_data();
	dnode* get_prev_link();
	dnode* get_next_link();
	void set_data(value_type entry);
	void set_prev_link(dnode* prev_link_ptr);
	void set_next_link(dnode* next_link_ptr);

	dnode(value_type entry, dnode* prev_link_ptr, dnode* next_link_ptr);

private:
	value_type data_field;
	dnode* prev_link_field;
	dnode* next_link_field;
};

void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry);
void list_head_remove(dnode*& head_ptr);
void list_insert(dnode*& previous_ptr, const dnode::value_type& entry);
void list_remove(dnode*& previous_ptr);
void list_display(dnode*& head_ptr);
int list_length(dnode*& head_ptr);
dnode* list_search(dnode* head_ptr, const dnode::value_type& target);
dnode* list_locate(dnode* head_ptr, int position);
void list_clear(dnode*& head_ptr);
void list_copy(dnode* source_ptr, dnode*& head_ptr);

dnode* list_reverse(dnode*& head_ptr);
