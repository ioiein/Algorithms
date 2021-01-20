
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>

const int OPERATIONS_MAX_COUNT = 1e5;
const int PRIME = 200003;
const int SHIFT = (int)('a');

class Set
{
private:
	struct element
	{
		std::string value;
		bool is_added;
	};
	std::vector<element> body;
	int size;
	int a;
	int count;

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

	void rehash()
	{
		int old_size = size;
		size *= 2;
		a = rand();
		std::vector<element> buff = body;
		body.clear();
		body.reserve(size);
		element el;
		el.value = "";
		el.is_added = false;
		for (size_t _ = 0; _ < size; ++_)
		{
			body.push_back(el);
		}
		for (size_t i = 0; i < old_size; ++i)
		{
			if (buff[i].value != "")
			{
				insert(buff[i].value);
			}
		}
	}

public:
	Set()
	{
		count = 0;
		size = 32;
		body.reserve(size);
		element el;
		el.value = "";
		el.is_added = false;
		for (size_t _ = 0; _ < size; ++_)
		{
			body.push_back(el);
		}
		a = rand();
	}

	void insert(const std::string& value)
	{
		if (exists(value))
		{
			return;
		}
		else
		{
			if (count >= size / 4)
			{
				rehash();
			}
			int i = hash(value);
			while (body[i].value != "")
			{
				++i;
				i %= size;
			}
			body[i].value = value;
			body[i].is_added = true;
			++count;
		}
	}

	bool exists(const std::string& value)
	{
		int i = hash(value);
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

	void remove(const std::string& value)
	{
		int i = hash(value);
		while (body[i].is_added != false)
		{
			if (body[i].value == value)
			{
				body[i].value = "";
				--count;
				return;
			}
			++i;
			i %= size;
		}
	}

	std::vector<std::string> getall()
	{
		std::vector<std::string> result;
		for (int i = 0; i < size; i++)
		{
			if (body[i].value != "")
			{
				result.push_back(body[i].value);
			}
		}
		return result;
	}

	~Set() {};

};

class Map
{
private:
	struct element
	{
		std::string key;
		Set value;
		element(const std::string& value1)
		{
			key = value1;
		}
	};
	std::list<element>* body;
	int size;
	int a;

	int hash(const std::string& key)
	{
		int current_a = 1;
		int result = 0;
		for (size_t i = 0; i < key.length(); i++)
		{
			result = abs(result + (current_a * ((int)key[key.length() - 1 - i] - (int)('a')))) % PRIME;
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
	}

	void put(const std::string& value1, const std::string& value2)
	{

		int i = hash(value1);
		auto it = std::find_if(std::begin(body[i]), std::end(body[i]),
			[&](const element el) { return el.key == value1; });
		if (body[i].end() == it)
		{
			element new_element(value1);
			new_element.value.insert(value2);
			body[i].push_back(new_element);
		}
		else
		{
			it->value.insert(value2);
		}
	}

	void remove(const std::string& value1, const std::string& value2)
	{
		int i = hash(value1);
		auto it = std::find_if(std::begin(body[i]), std::end(body[i]),
			[&](const element el) { return el.key == value1; });
		if (body[i].end() == it)
		{
			return;
		}
		else
		{
			it->value.remove(value2);
		}
	}

	void removeall(const std::string& value)
	{
		int i = hash(value);
		body[i].remove_if([&](const element el) { return el.key == value; });
	}

	std::vector<std::string> get(const std::string& value)
	{
		std::vector<std::string> result;
		int i = hash(value);
		auto it = std::find_if(std::begin(body[i]), std::end(body[i]),
			[&](const element el) { return el.key == value; });
		if (body[i].end() != it)
		{
			result = it->value.getall();
		}
		return result;
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
			std::vector<std::string> result = map.get(x);
			std::cout << result.size();
			for (int i = 0; i < result.size(); i++)
			{
				std::cout << ' ' << result[i];
			}
			std::cout << '\n';
		}
		else if (command == "delete")
		{
			std::cin >> y;
			map.remove(x, y);
		}
		else
		{
			map.removeall(x);
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