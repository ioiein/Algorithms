// chess_horse.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <list>

class Graph {
private:
    std::vector<std::vector<int>> adjacency;
    std::vector<int> color;
    int size;

    std::list<int> bfs(int start, int end) {
        std::vector<int> from(size * size);
        std::list<int> queue;
        queue.push_back(start);
        color[start] = 1;
        while (!queue.empty()) {
            int vertice = queue.front();
            queue.pop_front();
            for (int i : adjacency[vertice]) {
                if (color[i] == 0) {
                    color[i] = 1;
                    queue.push_back(i);
                    from[i] = vertice;
                }
            }
        }
        std::list<int> way;
        int current = end;
        while (current != start) {
            way.push_front(current);
            current = from[current];
        }
        way.push_front(current);
        return way;
    }
public:
    Graph(int _size) {
        size = _size;
        adjacency.resize(size * size);
        color.resize(size * size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i + 1 < size && j - 2 >= 0) {
                    add_edge(i * size + j, (i + 1) * size + j - 2);
                }
                if (i + 2 < size && j - 1 >= 0) {
                    add_edge(i * size + j, (i + 2) * size + j - 1);
                }
                if (i + 2 < size && j + 1 < size) {
                    add_edge(i * size + j, (i + 2) * size + j + 1);
                }
                if (i + 1 < size && j + 2 < size) {
                    add_edge(i * size + j, (i + 1) * size + j + 2);
                }
            }
        }
    }

    void add_edge(int begin, int end) {
        adjacency[begin].push_back(end);
        adjacency[end].push_back(begin);
    }

    void print_way(int x1, int y1, int x2, int y2) {
        int start = (y1 - 1) * size + x1 - 1;
        int end = (y2 - 1) * size + x2 - 1;
        std::list<int> way = bfs(start, end);
        std::cout << way.size() << '\n';
        while (!way.empty()) {
            std::cout << (way.front() % size) + 1 << ' ' << (way.front() / size) + 1 << '\n';
            way.pop_front();
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    Graph graph(n);
    graph.print_way(x1, y1, x2, y2);
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
