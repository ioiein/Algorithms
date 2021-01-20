// kuznechik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

void best_way(const std::vector<int>& pillars_cost, const int jump) {
	struct Step {
		int from;
		int max_money;
		Step() {
			from = 0;
			max_money = 0;
		}
	};
	std::vector<Step> steps;
	steps.reserve(pillars_cost.size());
	Step current;
	steps.push_back(current);
	for (size_t i = 1; i < pillars_cost.size(); i++) {
		int start = i - jump;
		if (start < 0) {
			start = 0;
		}
		current.max_money = INT32_MIN;
		for (int j = start; j < i; j++) {
			if (steps[j].max_money > current.max_money) {
				current.max_money = steps[j].max_money;
				current.from = j;
			}
		}
		current.max_money += pillars_cost[i];
		steps.push_back(current);
	}
	std::vector<int> way;
	int s = pillars_cost.size() - 1;
	while (s != 0) {
		way.push_back(s + 1);
		s = steps[s].from;
	}
	way.push_back(1);
	std::cout << steps[pillars_cost.size() - 1].max_money << '\n';
	std::cout << way.size() - 1 << '\n';
	for (int i = 0; i < way.size(); i++) {
		std::cout << way[way.size() - 1 - i] << ' ';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> pillars_cost(n);
	for (size_t i = 1; i < n - 1; i++) {
		std::cin >> pillars_cost[i];
	}
	best_way(pillars_cost, k);
	return 0;
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
