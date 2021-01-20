// ford_bellman.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

const int64_t INF = 5000000000000000000;

struct edge {
    int begin;
    int end;
    int64_t wieght;

    edge(int b, int e, int64_t w) {
        begin = b - 1;
        end = e - 1;
        wieght = w;
    }
};

class Graph {
private:
    std::vector<edge> edges;
    int vertice_count;
    int edges_count;

public:
    Graph(int n, int m) {
        vertice_count = n;
        edges_count = m;
        edges.reserve(m);
    }
    void add_edge(int b, int e, int64_t w) {
        edge new_edge(b, e, w);
        edges.push_back(new_edge);
    }
    std::vector<int64_t> ford_bellman(int start) {
        std::vector<int64_t> d(vertice_count, INF);
        d[start - 1] = 0;
        for (int i = 0; i < vertice_count - 1; ++i) {
            for (int j = 0; j < edges_count; ++j) {
                if (d[edges[j].begin] < INF) {
                    d[edges[j].end] = std::min(d[edges[j].end], d[edges[j].begin] + edges[j].wieght);
                }
            }
        }
        return d;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, s;
    std::cin >> n >> m >> s;
    Graph graph(n, m);
    int b, e;
    int64_t w;
    for (int i = 0; i < m; ++i) {
        std::cin >> b >> e >> w;
        graph.add_edge(b, e, w);
    }
    graph.ford_bellman(s);
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
