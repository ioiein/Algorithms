// linked_component.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> adjacency;
    std::vector<int> color;

    void dfs(int vertice, int current_colour) {
        color[vertice] = current_colour;
        for (int i : adjacency[vertice]) {
            if (color[i] == 0) {
                dfs(i, current_colour);
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
        adjacency[end - 1].push_back(begin - 1);
    }

    int linked_comps_count() {
        int count = 0;
        for (int i = 0; i < adjacency.size(); ++i) {
            if (color[i] == 0) {
                ++count;
                dfs(i, count);
            }
        }
        return count;
    }

    void print_colors(int count) {
        for (int i : color) {
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
    int b, e;
    for (int i = 0; i < m; ++i) {
        std::cin >> b >> e;
        graph.add_edge(b, e);
    }
    int result = graph.linked_comps_count();
    std::cout << result << '\n';
    graph.print_colors(result);
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
