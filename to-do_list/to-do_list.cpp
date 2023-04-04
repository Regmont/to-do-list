#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct doing
{
	string name;
	int priority;
	string description;
	string creat_date;
	float compl_time;
};

void create_a_doing(doing& x)
{
	cout << "Введите название дела: ";
	cin >> x.name;
	cout << "Введите приоритет дела: ";
	cin >> x.priority;
	cout << "Введите описание дела: ";
	cin >> x.description;
	cout << "Введите дату появления дела: ";
	cin >> x.creat_date;
	cout << "Введите время на исполнение дела (в часах): ";
	cin >> x.compl_time;
}

void print_a_doing(doing x)
{
	cout << "Название дела: " << x.name << endl;
	cout << "Приоритет дела: " << x.priority << endl;
	cout << "Описание дела: " << x.description << endl;
	cout << "Дата появления дела: " << x.creat_date << endl;
	cout << "Время на исполнение дела: " << x.compl_time << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);

	doing eat;
	create_a_doing(eat);
	print_a_doing(eat);
}

/*

Создайте приложение «Список дел».

Приложение должно позволять:

■ Добавление дел. У дела есть:
• название;
• приоритет;
• описание;
• дата, время исполнения.

■ Удаление дел.

■ Редактирование дел.

■ Поиск дел по:
• названию;
• приоритету;
• описанию;
• дате и времени исполнения.

■ Отображение списка дел:
• на день;
• на неделю;
• на месяц.

■ При отображении должна быть возможность сортировки:
• по приоритету;
• по дате и времени исполнения.

*/