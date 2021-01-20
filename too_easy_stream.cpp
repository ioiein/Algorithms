// too_easy_stream.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

struct Edge {
    int begin;
    int end;
    int capacity;
    int flow;
    int link;

    Edge(int b, int e, int c, int f, int l) {
        begin = b;
        end = e;
        capacity = c;
        flow = f;
        link = l;
    }
};

class Graph {
private:
    std::vector<std::vector<Edge>> g;

    int push_flow(int v, int t, int curr_flow, std::vector<int> used) {
        used[v] = 1;
        if (v == t) {
            return curr_flow;
        }
        for (Edge& i : g[v]) {
            if (!used[i.end] && i.flow < i.capacity) {
                int next_flow = std::min(curr_flow, i.capacity - i.flow);
                int delta = push_flow(i.end, t, next_flow, used);
                if (delta > 0) {
                    i.flow += delta;
                    g[i.end][i.link].flow -= delta;
                    return delta;
                }
            }
        }
        return 0;
    }
public:
    Graph(int n) {
        g.resize(n);
    }

    void add_edge(int a, int b, int c) {
        g[a].push_back(Edge(a, b, c, 0, g[b].size()));
        g[b].push_back(Edge(b, a, 0, 0, g[a].size() - 1));
    }

    int ford_falkerson(int start, int end) {
        int ans = 0;
        while (true) {
            std::vector<int> used(g.size(), 0);
            int delta = push_flow(start, end, INT32_MAX, used);
            if (delta > 0) {
                ans += delta;
            }
            else {
                break;
            }
        }
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
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> c;
        graph.add_edge(a - 1, b - 1, c);
    }
    std::cout << graph.ford_falkerson(0, n - 1);
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
