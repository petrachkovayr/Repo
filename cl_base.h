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
	
	//Работа 2
	void print_tree_rec(string s_tab);
	cl_base* find_object_from_current(string s_name);
	cl_base* find_object_from_root(string s_name);
	void set_state(int state);
	void print_state_tree_rec(string s_tab);
};

#endif
/*Свойства:
1Наименование объекта (строкового типа);
2Указатель на головной объект для текущего объекта
(для корневого объекта значение указателя равно nullptr);
3Динамический массив указателей на объекты,
подчиненные к текущему объекту в дереве иерархии.
Функционал:
1Параметризированный конструктор с параметрами:
указатель на объект базового класса, содержащий адрес головного объекта в дереве иерархии;
строкового типа, содержащий наименование создаваемого объекта (имеет значение по умолчанию);
2Метод редактирования имени объекта.
Один параметр строкового типа, содержит новое наименование объекта.
Если нет дубляжа имени подчиненных объектов у головного,
то редактирует имя и возвращает «истину», иначе возвращает «ложь»;
3Метод получения имени объекта;
4Метод получения указателя на головной объект текущего объекта;
5Метод вывода наименований объектов в дереве иерархии слева направо и сверху вниз;
6Метод получения указателя на непосредственно подчиненный объект по его имени.
Если объект не найден, то возвращает nullptr.
Один параметр строкового типа, содержит наименование искомого подчиненного объекта.*/