#include <stdlib.h>
#include "cl_application.h"

int main()
{
	//создание корневого объекта
	cl_application  ob_cl_application(nullptr);
	//конструирование системы, построение дерева объектов
	ob_cl_application.build_tree_objects();
	//запуск системы
	return ob_cl_application.exec_app();
}
