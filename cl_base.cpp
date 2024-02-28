#include "cl_base.h"
#include <queue>

cl_base::cl_base(cl_base* p_new_head_object, string s_new_name)
{
	p_head_object = p_new_head_object;
	s_name = s_new_name;
	if (p_head_object)
		p_head_object->p_sub_objects.push_back(this);
}

cl_base::~cl_base()
{
	for (auto obj: p_sub_objects)
		delete obj;
}

bool cl_base::set_name(string s_new_name)
{
	if (s_new_name.empty())
		return false;
	cl_base* p_search = this;
	//проверим ветки
	while (p_search)
	{
		if (p_search->find_object_from_current(s_new_name))//≈сли нашли такой элемент в верхней ветке, то не добавл€ем
			return false;
		p_search = p_search -> p_head_object;
	}
	this->s_name = s_new_name;
	return true;
}

string cl_base::get_name()
{
	return s_name;
}

cl_base* cl_base::get_head()
{
	return p_head_object;
}

//поиск в 1 дереве в 1 ветке
cl_base* cl_base::get_object_by_name(string s_name)
{
	for (auto obj : p_sub_objects)
	{
		if (obj->get_name() == s_name)
			return obj;
	}
	return nullptr;
}

void cl_base::print_tree()
{
	if (!p_sub_objects.empty())
	{
		cout << endl << get_name();
		for (auto obj: p_sub_objects)
		{
			cout << "  " << obj->get_name();
			obj->print_tree();
		}
	}
}

//--------------------------------------------------------------
cl_base* cl_base::find_object_from_current(string s_name)
{
	//—оздаем очередь дл€ хранени€ всех узлов дерева
	queue <cl_base*> p_nodes;
	//ƒобавл€ем в очередь текущий узел
	p_nodes.push(this);
	//Ќайденый узел или nullptr
	cl_base* p_search = nullptr;
	while(p_nodes.empty() == false)
	{
		//берем по одному элементу из начала очереди
		cl_base* p_node = p_nodes.front();
		//удал€ем вз€тый элемент из очереди
		p_nodes.pop();
		//≈сли нашли элемент
		if (p_node->s_name == s_name) 
		{
			if(p_search  == nullptr)
			{
				p_search = p_node;
			}
			else//такой элемент уже есть в дереве
			{
				p_search = nullptr;
			}
		}
		//добавл€ем в очередь все подчиненные элементы узла
		if(p_node!= nullptr)
			for (auto obj : p_node->p_sub_objects)
				p_nodes.push(obj);
	}	
	return p_search;
}

//--------------------------------------------------------------
cl_base* cl_base::find_object_from_root(string s_name)
{
	if (s_name.empty())
		return nullptr;
	if (p_head_object != nullptr)
		return p_head_object->find_object_from_root(s_name);
	else
		return find_object_from_current(s_name);
}

//метод установки готовности объекта, в качестве параметра
//передаетс€ переменна€ целого типа, содержит номер состо€ни€.
void cl_base::set_state(int state)
{
	if (state == 0)//установим элементу и вем его потомкам not ready состо€ние
	{
		this->i_state = state;
		for (auto obj : p_sub_objects)
		{
			obj->set_state(state);
		}
	}
	else//проверим, что родители ready и тогда установим состо€ние ready
	{
		if (this->p_head_object)
		{
			if (this->p_head_object->i_state)
			{
				this->i_state = state;
			}
			else
			{
				this->i_state = 0;
			}
		}
		else
		{
			this->i_state = state;
		}
	}
}

void cl_base::print_tree_rec(string s_tab)
{
	cout << endl << s_tab << this->s_name;
	if (!p_sub_objects.empty())
	{
		s_tab = s_tab + "    ";
		for (auto obj : p_sub_objects)
		{
			obj->print_tree_rec(s_tab);
		}
	}
}

void cl_base::print_state_tree_rec(string s_tab)
{
	//cout << "The tree objects and their readiness" << endl;
	cout << endl << s_tab << this->s_name;
	if (this->i_state == 0)
		cout << " is not ready";
	else
		cout << " is ready";	
	if (!p_sub_objects.empty())
	{
		s_tab = s_tab + "    ";
		for (auto obj : p_sub_objects)
		{
			obj->print_state_tree_rec(s_tab);
		}
	}	
}