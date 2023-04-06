#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int months[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };

struct Date
{
	int day;
	int month;
	int year;

	int getAllDays()
	{
		int days = day;

		for (int i = month - 2; i >= 0; i--) {
			days += months[i];
		}
		days += 365 * (year - 1);

		if (year % 4 == 0)
			days += year / 4 - 1;
		else
			days += year / 4;

		return days;
	}

	string info()
	{
		string str;
		if (day < 10)
			str.append("0");
		str.append(std::to_string(day));

		str.append(".");

		if (month < 10)
			str.append("0");
		str.append(std::to_string(month));

		str.append(".");

		str.append(std::to_string(year));

		return str;
	}
};

struct Time
{
	int hour;
	int minute;

	int getAllTime()
	{
		int minutes = minute;

		minutes += (hour - 1) * 60;

		return minutes;
	}

	string info()
	{
		string str;
		if (hour < 10)
			str.append("0");
		str.append(std::to_string(hour));

		str.append(":");

		if (minute < 10)
			str.append("0");
		str.append(std::to_string(minute));

		return str;
	}
};

struct Task
{
	string name;
	int priority;
	string description;
	Date create_date;
	Time compl_time;

	string info() {
		string str = "";
		str.append("Название: ");
		str.append(name);
		str.append("\n");
		str.append("Приоритет: ");
		str.append(std::to_string(priority));
		str.append("\n");
		str.append("Описание: ");
		str.append(description);
		str.append("\n");
		str.append("Дата: ");
		str.append(create_date.info());
		str.append("\n");
		str.append("Время выполнения: ");
		str.append((compl_time.info()));
		str.append("\n");
		return str;
	}
};

void createTask(Task& x)
{
	cout << "Введите название дела: ";
	cin >> x.name;
	cout << "Введите приоритет дела: ";
	cin >> x.priority;
	cout << "Введите описание дела: ";
	cin >> x.description;
	cout << "Введите дату появления дела (день, месяц, год): ";
	cin >> x.create_date.day >> x.create_date.month >> x.create_date.year;
	cout << "Введите время исполнения дела (час, минуты): ";
	cin >> x.compl_time.hour >> x.compl_time.minute;
	cout << endl;
}

void addTask(Task*& array, int& size, Task new_task)
{
	Task* temp = new Task[size + 1];

	for (int i = 0; i < size; i++)
		temp[i] = array[i];

	temp[size] = new_task;

	delete[] array;
	array = temp;
	size++;
}

string reverseString(string s)
{
	string res;

	for (int i = s.length() - 1; i >= 0; i--)
		res += s[i];

	return res;
}

void bubbleSort(Task* arr, int size)
{
	int i, j;

	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (arr[j].create_date.getAllDays() > arr[j + 1].create_date.getAllDays())
				swap(arr[j], arr[j + 1]);
}

int findTask(Task* array, int size, string del_name)
{
	for (int i = 0; i < size; i++)
		if (array[i].name.compare(del_name) == 0)
			return i;

	return -1;
}

void deleteTask(Task*& array, int& size, int chosen_task)
{
	Task* temp = new Task[size - 1];

	for (int i = 0; i < chosen_task; i++)
		temp[i] = array[i];

	for (int i = chosen_task + 1; i < size; i++)
		temp[i - 1] = array[i];

	delete[] array;
	array = temp;
	size--;
}

void printArray(Task* arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		cout << arr[i].info() << "\n\n";

	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);

	Task* array = new Task[0];
	int size = 0;
	Task new_task;
	int amount;

	cout << "Введите, сколько дел хотите добавить в список: ";
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		createTask(new_task);
		addTask(array, size, new_task);
	}

	printArray(array, size);

	string del_name;
	int del_index;

	cout << "Введите название дела для удаления\n";
	cin >> del_name;

	del_index = findTask(array, size, del_name);
	if (del_index != -1)
		deleteTask(array, size, del_index);
	else
		cout << "Дело не найдено\n";

	printArray(array, size);
}

/*

Создайте приложение «Список дел».

Приложение должно позволять:

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

