// count_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

const int Range = 101;

void countsort(vector<int>& array)
{
	vector<int> cnt(Range);
	for (int i = 0; i < array.size(); i++)
		cnt[array[i]]++;
	array.clear();
	for (int i = 0; i < Range; i++)
	{
		while (cnt[i] > 0)
		{
			array.push_back(i);
			cnt[i]--;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> input_array(istream_iterator<int>(cin), {});
	countsort(input_array);
	for (int& el : input_array)
	{
		cout << el << ' ';
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
