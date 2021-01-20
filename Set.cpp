// Set.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const uint64_t OPERETIONS_MAX_COUNT = (uint64_t)1e6;
const uint64_t PRIME = 2015179;

template <typename T>
class Set
{
private:
	struct element
	{
		T value;
		bool is_added;
	};
	std::vector<element> body;
	uint64_t size;
	uint64_t a;

	uint64_t hash(const T& value)
	{
		return ((a * abs(value)) % PRIME) % size;
	}

public:
	Set()
	{
		size = 2 * OPERETIONS_MAX_COUNT;
		body.reserve(size);
		element el;
		el.value = INT32_MIN;
		el.is_added = false;
		for (size_t _ = 0; _ < size; ++_)
		{
			body.push_back(el);
		}
		a = rand();
	}

	void insert(const T& value)
	{
		if (exists(value))
		{
			return;
		}
		else
		{
			uint64_t i = hash(value);
			while (body[i].value != INT32_MIN)
			{
				++i;
				i %= size;
			}
			body[i].value = value;
			body[i].is_added = true;
		}
	}

	bool exists(const T& value)
	{
		uint64_t i = hash(value);
		while (body[i].is_added != false)
		{
			if (body[i].value == value)
			{
				return true;
			}
			++i;
			i %= size;
		}
		return false;
	}

	void remove(const T& value)
	{
		uint64_t i = hash(value);
		while (body[i].is_added != false)
		{
			if (body[i].value == value)
			{
				body[i].value = INT32_MIN;
				return;
			}
			++i;
			i %= size;
		}
	}

	~Set() {};

};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	Set<int> set;
	std::string command;
	int x;
	while (std::cin >> command)
	{
		std::cin >> x;
		if (command == "insert")
		{
			set.insert(x);
		}
		else if (command == "exists")
		{
			bool x_exist = set.exists(x);
			if (x_exist)
			{
				std::cout << "true\n";
			}
			else
			{
				std::cout << "false\n";
			}
		}
		else
		{
			set.remove(x);
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
