// postfix_record.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <typename T>
class Vector
{
private:
	size_t capacity;
	T* elements;

	void change_capacity(size_t new_capacity)
	{
		T* new_elements = new T[new_capacity];
		for (size_t i = 0; i < size; ++i)
		{
			new_elements[i] = elements[i];
		}
		delete[] elements;
		elements = new_elements;
	}

	void ensure_capacity()
	{
		capacity *= 2;
		change_capacity(capacity);
	}

	void decrease_capacity()
	{
		capacity /= 2;
		change_capacity(capacity);
	}
public:
	size_t size;

	Vector()
	{
		size = 0;
		capacity = 2;
		elements = new T[2];
	}

	T get(int i)
	{
		if (i < 0 || i >= size)
		{
			return NULL;
		}
		else
		{
			return elements[i];
		}
	}	

	void add(const T& value)
	{
		if (size >= capacity)
		{
			ensure_capacity();
		}
		elements[size] = value;
		++size;
	}

	void erase()
	{
		if (size <= capacity / 4)
		{
			decrease_capacity();
		}
		--size;
	}

	~Vector() {}
};

template <typename T>
class Stack
{
private:
	Vector<T> vector;
public:
	Stack()
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
		return vector.get(vector.size - 1);
	}

	~Stack()
	{
		vector.~Vector();
	}
};

int postfix(Stack<char>& stack)
{
	char chr = stack.front();
	stack.pop();
	if (chr == '+')
	{
		return postfix(stack) + postfix(stack);
	}
	else if (chr == '-')
	{
		int a = postfix(stack);
		int b = postfix(stack);
		return b - a;
	}
	else if (chr == '*')
	{
		return postfix(stack) * postfix(stack);
	}
	else
	{
		return (int)chr - (int)('0');
	}
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	Stack<char> stack;
	char input;
	while (std::cin >> input)
	{
		stack.push(input);
	}
	int result = postfix(stack);
	std::cout << result;
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
