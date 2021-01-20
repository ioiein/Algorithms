// min_on_stack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node() : next(NULL) {}
		Node(const T& value) : data(value), next(NULL) {}
	};
	Node* head;
	Node* tail;
public:
	size_t size;

	List() : head(NULL), tail(NULL), size(0) {}
	
	void insert(const T& value)
	{
		Node* new_node = new Node(value);
		if (size == 0)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next = head;
			head = new_node;
		}
		++size;
	}

	void erase(int i)
	{
		if (i == 0)
		{
			if (size == 1)
			{
				delete head;
				head = tail = NULL;
			}
			else
			{
				Node* current_head = head;
				head = head->next;
				delete current_head;
			}
		}
		else
		{
			Node* previous = head;
			Node* current = head->next;
			int j = 1;
			while (j < i)
			{
				previous = current;
				current = current->next;
				++j;
			}
			previous->next = current->next;
			if (current = tail)
			{
				tail = previous;
			}
			delete current;
		}
		--size;
	}

	T head_value()
	{
		return head->data;
	}

	~List()
	{
		while (head)
		{
			erase(0);
		}
	}
};

template <typename T>
class Stack
{
private:
	List<T> list;
	List<T> current_min;
public:
	Stack()
	{
		List<T> list;
		List<T> current_min;
	}

	void push(const T& value)
	{
		if (list.size == 0)
		{
			current_min.insert(value);
		}
		else
		{
			if (value < current_min.head_value())
			{
				current_min.insert(value);
			}
			else
			{
				current_min.insert(current_min.head_value());
			}
		}
		list.insert(value);
	}

	void pop()
	{
		list.erase(0);
		current_min.erase(0);
	}

	size_t size()
	{
		return list.size;
	}

	T min_on_stack()
	{
		return current_min.head_value();
	}

	~Stack()
	{
		list.~List();
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	Stack<int> stack;
	for (int _ = 0; _ < n; ++_)
	{
		int command;
		std::cin >> command;
		if (command == 1)
		{
			int value;
			std::cin >> value;
			stack.push(value);
		}
		else if (command == 2)
		{
			stack.pop();
		}
		else
		{
			std::cout << stack.min_on_stack() << '\n';
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
