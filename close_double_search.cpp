// close_double_search.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int close_bin_search(const std::vector<int>& array, int left, int right, int x)
{
	while (left < right - 1)
	{
		int mid = (left + right) / 2;
		if (x == array[mid])
		{
			return array[mid];
		}
		else if (x < array[mid])
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	if (x - array[left] <= array[right] - x)
	{
		return array[left];
	}
	else
	{
		return array[right];
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> input_array;
	input_array.reserve(n);
	copy_n(std::istream_iterator<int>(std::cin), n, back_inserter(input_array));
	std::vector<int> requests;
	requests.reserve(k);
	copy_n(std::istream_iterator<int>(std::cin), k, back_inserter(requests));
	int result;
	for (int i = 0; i < k; ++i)
	{
		if (requests[i] <= input_array[0])
		{
			result = input_array[0];
		}
		else if (requests[i] >= input_array[n - 1])
		{
			result = input_array[n - 1];
		}
		else
		{
			result = close_bin_search(input_array, 0, n, requests[i]);
		}
		std::cout << result << '\n';
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
