// priority_queue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

template <typename T>
class Heap
{
private:
	struct Leaf
	{
		T value;
		int command_number;

		Leaf()
		{
			value = 0;
			command_number = 0;
		}
		Leaf(const T& value, const int& number) : value(value) { command_number = number; }
	};
	std::vector<Leaf> heap;
	std::vector<int> position_from_command;
public:
	Heap() 
	{
		std::vector<T> heap;
		std::vector<int> position_from_command;
	}

	void insert(const T& value, const int& number)
	{
		int i = heap.size();
		Leaf leaf(value, number);
		position_from_command.push_back(i);
		heap.push_back(leaf);
		
		while (i > 0 && heap[i].value < heap[(i - 1) / 2].value)
		{
			std::swap(position_from_command[heap[i].command_number - 1],
				position_from_command[heap[(i - 1) / 2].command_number - 1]);
			std::swap(heap[i], heap[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	void extract_min()
	{
		position_from_command.push_back(-1);
		if (heap.size() == 0)
		{
			std::cout << '*' << '\n';
			return;
		}
		std::cout << heap[0].value << ' ' << heap[0].command_number << '\n';
		std::swap(position_from_command[heap[0].command_number - 1], 
			position_from_command[heap[heap.size() - 1].command_number - 1]);
		std::swap(heap[0], heap[heap.size() - 1]);
		position_from_command[heap[heap.size() - 1].command_number - 1] = -1;
		heap.pop_back();
		int i = 0;
		Leaf current, left, right;
		while (2 * i + 1 < heap.size())
		{
			current = heap[i];
			left = heap[2 * i + 1];
			if (2 * i + 2 == heap.size())
			{
				right.value = INT_MAX;
				right.command_number = 0;
			}
			else
			{
				right = heap[2 * i + 2];
			}
			if (left.value < current.value && left.value <= right.value)
			{
				std::swap(position_from_command[heap[i].command_number - 1],
					position_from_command[heap[2 * i + 1].command_number - 1]);
				std::swap(heap[i], heap[2 * i + 1]);
				i = 2 * i + 1;
			}
			else if (right.value < current.value && right.value < left.value)
			{
				std::swap(position_from_command[heap[i].command_number - 1],
					position_from_command[heap[2 * i + 2].command_number - 1]);
				std::swap(heap[i], heap[2 * i + 2]);
				i = 2 * i + 2;
			}
			else
			{
				break;
			}
		}
	}

	void decrease_key(const T& value, const int& number)
	{
		position_from_command.push_back(-1);
		int i = position_from_command[number - 1];
		if (i == -1)
			return;
		heap[i].value = value;
		while (i > 0 && heap[i].value < heap[(i - 1) / 2].value)
		{
			std::swap(position_from_command[heap[i].command_number - 1],
				position_from_command[heap[(i - 1) / 2].command_number - 1]);
			std::swap(heap[i], heap[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	~Heap() {}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	Heap<int> heap;
	int count = 0;
	std::string command;
	while (std::cin >> command)
	{
		++count;
		if (command == "push")
		{
			int value;
			std::cin >> value;
			heap.insert(value, count);
		}
		else if (command == "extract-min")
		{
			heap.extract_min();
		}
		else if (command == "decrease-key")
		{
			int number, value;
			std::cin >> number >> value;
			heap.decrease_key(value, number);
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
