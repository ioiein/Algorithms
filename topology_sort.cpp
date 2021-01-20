// topology_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Graph {
private:
    std::vector<std::vector<int>> adjacency;
    std::vector<int> color;

    void dfs(int vertice, std::vector<int>& ans) {
        color[vertice] = 1;
        for (int i : adjacency[vertice]) {
            if (color[i] == 0) {
                dfs(i, ans);
            }
            else if (color[i] == 1) {
                std::cout << -1;
                exit(0);
            }
        }
        color[vertice] = 2;
        ans.push_back(vertice);
    }
public:
    Graph(int vertice_count) {
        adjacency.resize(vertice_count);
        color.resize(vertice_count);
    }

    void add_edge(int begin, int end) {
        adjacency[begin - 1].push_back(end - 1);
    }

    std::vector<int> topology_sort() {
        std::vector<int> ans;
        for (int i = 0; i < adjacency.size(); ++i) {
            if (color[i] == 0) {
                dfs(i, ans);
            }
        }
        std::reverse(std::begin(ans), std::end(ans));
        return ans;
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
    std::vector<int> ans = graph.topology_sort();
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] + 1 << ' ';
    }
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
