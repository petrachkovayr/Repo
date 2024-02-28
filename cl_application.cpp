#include "cl_application.h"

cl_application::cl_application(cl_base* p_head_object) :cl_base(p_head_object)
{
}

void cl_application::build_tree_objects()
{
	string s_sub_name, s_head_name;
	cl_base* p_head = this;
	cl_base* p_sub = nullptr;
	int class_num;
	int class_ready;
	cin >> s_head_name;
	set_name(s_head_name);
	//Ввод иерархии объектов	
	while (true)
	{
		cin >> s_head_name;
		if (s_head_name == "endtree")
			break;
		cin >> s_sub_name;
		cin >> class_num;
		cl_base* p_child = nullptr;
		p_head = find_object_from_root(s_head_name);
		//если такого элемента и подчиненного с такими именами нет в дереве то создадим объекты
		if (p_head && p_head->find_object_from_root(s_sub_name) == nullptr)
		{
			switch (class_num)
			{
			case 2:
				p_child = new cl_2(p_head, s_sub_name);
				break;
			case 3:
				p_child = new cl_3(p_head, s_sub_name);
				break;
			case 4:
				p_child = new cl_4(p_head, s_sub_name);
				break;
			case 5:
				p_child = new cl_5(p_head, s_sub_name);
				break;
			case 6:
				p_child = new cl_6(p_head, s_sub_name);
				break;
			default:
				break;
			}
		}
	}
	//Установка состояний готовности для объектов	
	while (cin >> s_head_name)
	{
		cin >> class_ready;
		//вызов метода установки готовности объекта
		cl_base* p_find = this->find_object_from_root(s_head_name);
		if (p_find != nullptr)
			p_find->set_state(class_ready);
		else 
			break;
	}
}

int cl_application::exec_app()
{
	cout << endl << "Object tree";
	print_tree_rec("");
	cout << endl << "The tree objects and their readiness";
	print_state_tree_rec("");
	return 0;
}