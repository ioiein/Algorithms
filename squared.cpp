﻿// squared.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

const int ITN = 55;

double f(double x)
{
	return x * x + sqrt(x);
}

double bin_search(double c)
{
	double left = 0.0;
	double mid;
	double right(10e10);
	for (int i = 0; i < ITN; i++)
	{
		mid = (left + right) / 2.0;
		if (f(mid) < c)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return right;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	double c;
	std::cin >> c;
	double result = bin_search(c);
	std::cout.setf(std::ios::fixed);  // вывод в фиксированном формате 
	std::cout.precision(6);
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