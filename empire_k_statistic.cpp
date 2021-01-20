// empire_k_statistic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int split(vector<uint32_t>& array, int l, int r, uint32_t divider)
{
	int median = l;
	for (int i = l; i < r; i++)
	{
		if (array[i] < divider)
		{
			swap(array[i], array[median]);
			median++;
		}
	}
	return median;
}

int find(vector<uint32_t>& array, int k, int l, int r)
{
	if (r - l == 1)
		return array[k];
	uint32_t divider = array[(rand() % (r - l)) + l];
	int median = split(array, l, r, divider);
	if (k < median)
		return find(array, k, l, median);
	else
		return find(array, k, median, r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<uint32_t> input_array;
	input_array.reserve(n);
	copy_n(istream_iterator<uint32_t>(cin), n, back_inserter(input_array));
	int count_request;
	int i, j, k;
	cin >> count_request;
	vector<uint32_t> buff_array;
	for (int _ = 0; _ < count_request; _++)
	{
		buff_array = input_array;
		cin >> i >> j >> k;
		int result = find(buff_array, k - 1 + i - 1, i - 1, j);
		cout << result << '\n';
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
