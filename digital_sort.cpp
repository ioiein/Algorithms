// digital_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

const int Range = 26;
const int Shift = 97;

int asciitocnt(char a)
{
	return (int)a - Shift;
}

void digital_sort(const vector<string>& array, int length, int iterations)
{
	vector<int> order;
	order.reserve(array.size());
	vector<int> buff_order(array.size());
	for (int i = 0; i < array.size(); i++)
	{
		order.push_back(i);
	}
	for (int digit = length - 1; digit > length - 1 - iterations; digit--)
	{
		vector<int> cnt(Range);
		for (int i = 0; i < array.size(); i++)
		{
			cnt[asciitocnt(array[i][digit])]++;
		}
		vector<int> offset(Range);
		for (int i = 1; i < Range; i++)
		{
			offset[i] = offset[i - 1] + cnt[i - 1];
		}
		for (int i = 0; i < array.size(); i++)
		{
			buff_order[offset[asciitocnt(array[order[i]][digit])]] = order[i];
			offset[asciitocnt(array[order[i]][digit])]++;
		}
		order = buff_order;
	}
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[order[i]] << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> input_array;
	input_array.reserve(n);
	copy_n(istream_iterator<string>(cin), n, back_inserter(input_array));
	digital_sort(input_array, m, k);
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
