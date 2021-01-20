// shortest_way.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <set>

class Graph {
private:
    std::vector<std::vector<std::pair<int, int>>> adjacency;
    std::vector<int> color;
	int size;

    std::vector<int> dijkstra(int start) {
		std::vector<int> d(size, INT32_MAX);
		d[start] = 0;
		std::set <std::pair<int, int>> q;
		q.insert(std::make_pair(start, d[start]));
		while (!q.empty()) {
			int v = q.begin()->first;
			q.erase(q.begin());

			for (std::pair<int, int> j : adjacency[v]) {
				int to = j.first;
				int	len = j.second;
				if (d[v] + len < d[to]) {
					q.erase(std::make_pair(to, d[to]));
					d[to] = d[v] + len;
					q.insert(std::make_pair(to, d[to]));
				}
			}
		}
		return d;
    }
public:
    Graph(int vertice_count) {
		size = vertice_count;
        adjacency.resize(vertice_count);
        color.resize(vertice_count);
    }

    void add_edge(int begin, int end, int weight) {
        adjacency[begin - 1].push_back(std::make_pair(end - 1, weight));
        adjacency[end - 1].push_back(std::make_pair(begin - 1, weight));
    }

	void print_distance() {
		std::vector<int> distance = dijkstra(0);
		for (int i : distance) {
			std::cout << i << ' ';
		}
	}
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	Graph graph(n);
	int b, e, w;
	for (int i = 0; i < m; ++i) {
		std::cin >> b >> e >> w;
		graph.add_edge(b, e, w);
	}
	graph.print_distance();
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
