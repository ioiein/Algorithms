// point.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include<set>

class Graph {
private:
    std::vector<std::vector<int>> adjacency;
    std::vector<int> color;
    std::set<int> points;
    std::vector<int> tin;
    std::vector<int> up;
    int time;

    void dfs(int vertice, int p) {
        color[vertice] = 1;
        tin[vertice] = up[vertice] = time++;
        int children = 0;
        for (int i : adjacency[vertice]) {
            if (i == p) {
                continue;
            }
            if (color[i] == 1) {
                up[vertice] = std::min(up[vertice], tin[i]);
            }
            else {
                dfs(i, vertice);
                up[vertice] = std::min(up[vertice], up[i]);
                if (up[i] >= tin[vertice] && p != -1) {
                    points.insert(vertice);
                }
                ++children;
            }
        }
        if (p == -1 && children > 1) {
            points.insert(vertice);
        }
    }
public:
    Graph(int vertice_count) {
        adjacency.resize(vertice_count);
        color.resize(vertice_count);
        tin.resize(vertice_count);
        up.resize(vertice_count);
        time = 0;
    }

    void add_edge(int begin, int end) {
        adjacency[begin - 1].push_back(end - 1);
        adjacency[end - 1].push_back(begin - 1);
    }

    std::set<int> get_points() {
        for (int i = 0; i < color.size(); ++i) {
            if (color[i] == 0) {
                dfs(i, -1);
            }
        }
        return points;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    Graph graph(n);
    int b, e;
    for (int i = 0; i < m; ++i) {
        std::cin >> b >> e;
        graph.add_edge(b, e);
    }
    std::set<int> result = graph.get_points();
    std::cout << result.size() << '\n';
    for (int i : result) {
        std::cout << i + 1 << ' ';
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
