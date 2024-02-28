//Коммит 3. Заголовочный файл базового класса.
#ifndef __CL_BASE__H
#define __CL_BASE__H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class cl_base
{
	string s_name;
	cl_base* p_head_object;
	vector<cl_base*> p_sub_objects;
	int i_state = 0;
public:
	cl_base(cl_base* p_new_head_object, string s_new_name = "Base object");
	~cl_base();
	bool set_name(string s_new_name);
	string get_name();
	cl_base* get_head();
	void print_tree();
	cl_base* get_object_by_name(string s_name);
	
	//������ 2
	void print_tree_rec(string s_tab);
	cl_base* find_object_from_current(string s_name);
	cl_base* find_object_from_root(string s_name);
	void set_state(int state);
	void print_state_tree_rec(string s_tab);
};

#endif
