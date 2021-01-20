// negative_cycle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

const int INF = 100000;

void floid(int** d, int size) {
	int8_t** next = new int8_t * [size];
	for (int i = 0; i < size; ++i) {
		next[i] = new int8_t[size];
		for (int j = 0; j < size; ++j) {
			next[i][j] = j;
		}
	}

	for (int k = 0; k < size; ++k) {
		for (int u = 0; u < size; ++u) {
			for (int v = 0; v < size; ++v) {
				if (d[u][k] < INF && d[k][v] < INF && d[u][v] > d[u][k] + d[k][v]) {
					d[u][v] = d[u][k] + d[k][v];
					next[u][v] = next[u][k];
				}
			}
		}
	}

	int where_cycle = -1;
	std::vector<int> way;
	for (int i = size - 1; i >= 0; --i) {
		if (d[i][i] < 0) {
			way.clear();
			where_cycle = i;
			bool correct = false;
			way.push_back(where_cycle + 1);
			int c = next[where_cycle][where_cycle];
			while (c != where_cycle) {
				way.push_back(c + 1);
				c = next[c][where_cycle];
				if (way.size() > size) {
					correct = true;
					break;
				}
			}
			if (correct == true) {
				continue;
			}
			std::cout << "YES\n" << way.size() << '\n';
			for (int i = 0; i < way.size(); ++i) {
				std::cout << way[i] << ' ';
			}
			break;
		}
	}
	if (where_cycle == -1) {
		std::cout << "NO";
	}
	for (int i = 0; i < size; ++i) {
		delete[] next[i];
	}
	delete[] next;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int** d = new int* [n];
	for (int i = 0; i < n; ++i) {
		d[i] = new int[n];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> d[i][j];
		}
	}
	floid(d, n);
	for (int i = 0; i < n; ++i) {
		delete[] d[i];
	}
	delete[] d;
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
