// too_eazy_taks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>

bool what_about_copy(int copy_count, int printer_one, int printer_two, long long seconds)
{
	int faster_printer = std::min(printer_one, printer_two);
	long long first_can = floor((double)(seconds - faster_printer) / printer_one);
	long long second_can = floor((double)(seconds - faster_printer) / printer_two);
	if (1 + first_can + second_can >= copy_count)
	{
		return true;
	}
	else
	{
		return false;
	}
}

long long min_time(int copy_count, int printer_one, int printer_two)
{
	long long left = 1;
	long long right = (long long)copy_count * (printer_one + printer_two);
	long long mid;
	while (left < right - 1)
	{
		mid = (left + right) / 2;
		if (what_about_copy(copy_count, printer_one, printer_two, mid) == true)
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
	int n, x, y;
	std::cin >> n >> x >> y;
	long long result = min_time(n, x, y);
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
