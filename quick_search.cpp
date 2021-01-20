// quick_search.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdio.h>

int lower_bound(const std::vector<int>& array, int x)
{
	int left = -1;
	int right = array.size();
	int mid;
	while (left < right - 1)
	{
		mid = (left + right) / 2;
		if (x <= array[mid])
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	return right;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, k;
	std::cin >> n;
	std::vector<int> input_array;
	input_array.reserve(n);
	copy_n(std::istream_iterator<int>(std::cin), n, back_inserter(input_array));
	std::sort(input_array.begin(), input_array.end());
	std::cin >> k;
	for (int _ = 0; _ < k; ++_)
	{
		int l, r;
		std::cin >> l >> r;
		int result = lower_bound(input_array, r + 1) - lower_bound(input_array, l);
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
