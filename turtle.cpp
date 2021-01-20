// turtle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

void best_way(int** field, int n, int m) {
	struct Step {
		int max_money;
		char forward;
		std::pair<int, int> from;

		Step() {
			max_money = INT32_MIN;
		}

		void Set(int money, char direct, int i_from, int j_from) {
			max_money = money;
			forward = direct;
			from = std::make_pair(i_from, j_from);
		}
	};
	Step** steps = new Step* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		steps[i] = new Step[m + 1];
	}
	steps[1][1].max_money = field[0][0];
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (i == 1 && j == 1) {
				continue;
			}
			if (steps[i - 1][j].max_money >= steps[i][j - 1].max_money) {
				steps[i][j].Set(steps[i - 1][j].max_money + field[i - 1][j - 1], 'D', i - 1, j);
			}
			else {
				steps[i][j].Set(steps[i][j - 1].max_money + field[i - 1][j - 1], 'R', i, j - 1);
			}
		}
	}
	int i = n;
	int j = m;
	std::string way = "";
	std::cout << steps[i][j].max_money << '\n';
	while (i != 1 || j != 1) {
		way = steps[i][j].forward + way;
		int k = steps[i][j].from.first;
		int s = steps[i][j].from.second;
		i = k;
		j = s;
	}
	std::cout << way;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	int** field = new int* [n];
	for (int i = 0; i < n; i++) {
		field[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> field[i][j];
		}
	}
	best_way(field, n, m);
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
