// graph_condensate.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Graph {
private:
    std::vector<std::vector<int>> adjacency;
    std::vector<int> color;

    void dfs_for_top_sort(int vertice, std::vector<int>& ans) {
        color[vertice] = 1;
        for (int i : adjacency[vertice]) {
            if (color[i] == 0) {
                dfs_for_top_sort(i, ans);
            }
        }
        ans.push_back(vertice);
    }

    void dfs_for_linked_comp(int vertice, int current_colour) {
        color[vertice] = current_colour;
        for (int i : adjacency[vertice]) {
            if (color[i] == 0) {
                dfs_for_linked_comp(i, current_colour);
            }
        }
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
                dfs_for_top_sort(i, ans);
            }
        }
        for (int i = 0; i < color.size(); ++i) {
            color[i] = 0;
        }
        std::reverse(std::begin(ans), std::end(ans));
        return ans;
    }

    Graph get_added_graph() {
        Graph added_graph(adjacency.size());
        for (int i = 0; i < adjacency.size(); ++i) {
            for (int j : adjacency[i]) {
                added_graph.add_edge(j + 1, i + 1);
            }
        }
        return added_graph;
    }

    int linked_comps_count(const std::vector<int>& order) {
        int count = 0;
        for (int i : order) {
            if (color[i] == 0) {
                ++count;
                dfs_for_linked_comp(i, count);
            }
        }
        return count;
    }

    int condensate_count_edges() {
        std::vector<int> order = topology_sort();
        Graph added_graph = get_added_graph();
        added_graph.linked_comps_count(order);
        color = added_graph.get_color();
        std::set<std::pair<int, int>> edges;
        for (int i = 0; i < adjacency.size(); ++i) {
            for (int j : adjacency[i]) {
                if (color[i] != color[j]) {
                    edges.insert(std::make_pair(color[i], color[j]));
                }
            }
        }
        return edges.size();
    }

    std::vector<int> get_color() {
        return color;
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
    std::cout << graph.condensate_count_edges();
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
