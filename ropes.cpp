// ropes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

bool what_about_ropes(std::vector<int> ropes, int home_count, int length)
{
	for (int i = 0; i < ropes.size(); i++)
	{
		while (ropes[i] >= length)
		{
			if (home_count == 0)
			{
				return true;
			}
			ropes[i] -= length;
			home_count--;
		}
	}
	if (home_count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int max_rope(const std::vector<int> ropes, int home_count)
{
	int left = 1;
	int right = 10000001;
	if (what_about_ropes(ropes, home_count, left) == false)
	{
		return 0;
	}
	int mid;
	while (left < right - 1)
	{
		mid = (left + right) / 2;
		if (what_about_ropes(ropes, home_count, mid) == true)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> ropes;
	ropes.reserve(n);
	copy_n(std::istream_iterator<int>(std::cin), n, back_inserter(ropes));
	int result = max_rope(ropes, k);
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
