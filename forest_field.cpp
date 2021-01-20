// forest_field.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

const int ITN = 25;

double time_to_point(double forest_edge, double x, int vp, int vf)
{
	double distance_forest_to_point = sqrt(pow(1.0 - x, 2) + pow(forest_edge, 2));
	double distance_to_forest = sqrt(pow(x, 2) + pow(1.0 - forest_edge, 2));
	return (distance_to_forest / vp + distance_forest_to_point / vf);
}

double ternary_search(double left, double right, double forest_edge, int vp, int vf)
{
	double mid1, mid2;
	for (int i = 0; i < ITN; i++)
	{
		mid1 = (2 * left + right) / 3;
		mid2 = (left + 2 * right) / 3;
		if (time_to_point(forest_edge, mid1, vp, vf) < time_to_point(forest_edge, mid2, vp, vf))
		{
			right = mid2;
		}
		else
		{
			left = mid1;
		}
	}
	return right;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int vp, vf;
	std::cin >> vp >> vf;
	double a;
	std::cin >> a;
	double result = ternary_search(0.0, 1.0, a, vp, vf);
	std::cout.setf(std::ios::fixed);  // вывод в фиксированном формате 
	std::cout.precision(4);
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
