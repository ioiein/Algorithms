// cycle_queue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <typename T>
class Vector
{
private:
	int capacity;
	int begin;
	int size;
	T* elements;

	void change_capacity(int new_capacity)
	{
		T* new_elements = new T[new_capacity];
		for (size_t i = 0; i < size; ++i)
		{
			new_elements[i] = elements[(begin + i) % capacity];
		}
		delete[] elements;
		elements = new_elements;
		begin = 0;
	}

	void ensure_capacity()
	{
		change_capacity(capacity * 2);
		capacity *= 2;
	}

	void decrease_capacity()
	{
		change_capacity(capacity / 2);
		capacity /= 2;
	}
public:

	Vector()
	{
		begin = 0;
		size = 0;
		capacity = 2;
		elements = new T[2];
	}

	T get(int i)
	{
		if (i < begin && i > ((begin + size) % capacity))
		{
			return NULL;
		}
		else
		{
			return elements[(begin + i) % capacity];
		}
	}

	void add(const T& value)
	{
		if (size >= capacity)
		{
			ensure_capacity();
		}
		elements[(begin + size) % capacity] = value;
		size++;
	}

	void erase()
	{
		if (size <= capacity / 4)
		{
			decrease_capacity();
		}
		--size;
		++begin;
		begin %= capacity;
	}

	~Vector() {}
};

template <typename T>
class Queue
{
private:
	Vector<T> vector;
public:
	Queue()
	{
		Vector<T> vector;
	}

	void push(const T& value)
	{
		vector.add(value);
	}

	void pop()
	{
		vector.erase();
	}

	T front()
	{
		return vector.get(0);
	}

	~Queue()
	{
		vector.~Vector();
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	Queue<int> queue;
	int m;
	std::cin >> m;
	for (size_t _ = 0; _ < m; _++)
	{
		char command;
		std::cin >> command;
		if (command == '+')
		{
			int value;
			std::cin >> value;
			queue.push(value);
		}
		else if (command == '-')
		{
			std::cout << queue.front() << '\n';
			queue.pop();
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
