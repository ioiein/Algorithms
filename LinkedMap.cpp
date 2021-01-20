// LinkedMap.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>

const int OPERATIONS_MAX_COUNT = 1e5;
const int PRIME = 200003;
const int SHIFT = (int)('a');

class Map
{
private:
	struct element
	{
		std::string key;
		std::string value;
		element* previous;
		element* next;

		element(const std::string& value1, const std::string& value2)
		{
			key = value1;
			value = value2;
			previous = NULL;
			next = NULL;
		}
	};
	std::list<element>* body;
	int size;
	int a;
	element* last;

	int hash(const std::string& key)
	{
		int current_a = 1;
		int result = 0;
		for (size_t i = 0; i < key.length(); i++)
		{
			result = abs(result + (current_a * ((int)key[key.length() - 1 - i] - SHIFT + 1))) % PRIME;
			current_a *= a;
		}
		return result % size;
	}

public:
	Map()
	{
		size = OPERATIONS_MAX_COUNT * 2;
		body = new std::list<element>[size];
		a = rand();
		last = NULL;
	}

	void put(const std::string& value1, const std::string& value2)
	{
		element new_element(value1, value2);
		int i = hash(value1);
		auto it = std::find_if(std::begin(body[i]), std::end(body[i]),
			[&](const element el) { return el.key == value1; });
		if (body[i].end() == it)
		{
			new_element.previous = last;
			body[i].push_back(new_element);
			if (last != NULL)
			{
				last->next = &body[i].back();
			}
			last = &body[i].back();
		}
		else
		{
			(*it).value = value2;
		}
	}

	void remove(const std::string& value)
	{
		int i = hash(value);
		auto it = std::find_if(std::begin(body[i]), std::end(body[i]),
			[&](const element el) { return el.key == value; });
		if (body[i].end() == it)
		{
			return;
		}
		else
		{
			if ((*it).previous != NULL)
			{
				(*it).previous->next = (*it).next;
			}
			if ((*it).next != NULL)
			{
				(*it).next->previous = (*it).previous;
			}
			else
			{
				last = (*it).previous;
			}
			body[i].erase(it);
		}
	}

	std::string get(const std::string& value)
	{
		int i = hash(value);
		auto it = std::find_if(std::begin(body[i]), std::end(body[i]),
			[&](const element el) { return el.key == value; });
		if (body[i].end() == it)
		{
			return "none";
		}
		else
		{
			return (*it).value;
		}
	}

	std::string next(const std::string& value)
	{
		int i = hash(value);
		auto it = std::find_if(std::begin(body[i]), std::end(body[i]),
			[&](const element el) { return el.key == value; });
		if (body[i].end() == it || (*it).next == NULL)
		{
			return "none";
		}
		else
		{
			return (*it).next->value;
		}
	}

	std::string prev(const std::string& value)
	{
		int i = hash(value);
		auto it = std::find_if(std::begin(body[i]), std::end(body[i]),
			[&](const element el) { return el.key == value; });
		if (body[i].end() == it || (*it).previous == NULL)
		{
			return "none";
		}
		else
		{
			return (*it).previous->value;
		}
	}

	~Map() {};

};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string command, x, y;
	Map map;
	while (std::cin >> command)
	{
		std::cin >> x;
		if (command == "put")
		{
			std::cin >> y;
			map.put(x, y);
		}
		else if (command == "get")
		{
			std::cout << map.get(x) << '\n';
		}
		else if (command == "delete")
		{
			map.remove(x);
		}
		else if (command == "prev")
		{
			std::cout << map.prev(x) << '\n';
		}
		else
		{
			std::cout << map.next(x) << '\n';
		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
