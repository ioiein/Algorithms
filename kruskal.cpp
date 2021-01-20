// kruskal.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

class System_unjoined_sets {
private:
    std::vector<int> p;
    std::vector<int> rank;

public:
    System_unjoined_sets(int size) {
        p.resize(size);
        rank.resize(size);
        for (int i = 0; i < size; ++i) {
            p[i] = i;
            rank[i] = 0;
        }
    }

    int get(int x) {
        if (p[x] != x) {
            p[x] = get(p[x]);
        }
        return p[x];
    }

    void join(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return;
        }
        else {
            if (rank[x] > rank[y]) {
                std::swap(x, y);
            }
            if (rank[x] == rank[y]) {
                ++rank[y];
            }
            p[x] = y;
        }
    }
};

struct Edge {
    int begin;
    int end;
    int weight;

    Edge(int b, int e, int w) {
        begin = b;
        end = e;
        weight = w;
    }
};

inline bool operator< (const Edge& lhs, const Edge& rhs) { return lhs.weight < rhs.weight; }
inline bool operator> (const Edge& lhs, const Edge& rhs) { return rhs < lhs; }
inline bool operator<=(const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); }
inline bool operator>=(const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); }

class Graph {
private:
    std::vector<Edge> edges;

public:
    Graph(int m) {
        edges.reserve(m);
    }

    void add_edge(int b, int e, int w) {
        Edge new_edge(b, e, w);
        edges.push_back(new_edge);
    }

    int kruskal(int vertice_count) {
        System_unjoined_sets sus(vertice_count);
        std::sort(edges.begin(), edges.end());
        int result = 0;
        for (Edge edge : edges) {
            if (sus.get(edge.begin) != sus.get(edge.end)) {
                result += edge.weight;
                sus.join(edge.begin, edge.end);
            }
        }
        return result;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    Graph graph(m);
    int b, e, w;
    for (int i = 0; i < m; ++i) {
        std::cin >> b >> e >> w;
        graph.add_edge(b - 1, e - 1, w);
    }
    std::cout << graph.kruskal(n);
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
