// Prim.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>

const int INF = 1000000000;

class Graph {
private:
    int size;
    std::vector<std::pair<double, double>> vertices;
    std::vector<bool> color;
    
public:
    Graph(int n) {
        size = n;
        color.resize(size);
        vertices.reserve(size);
    }

    void add_vertice(double x, double y) {
        vertices.push_back(std::make_pair(x, y));
    }

    double get_weight(int b, int e) {
        return std::sqrt(std::pow(vertices[b].first - vertices[e].first, 2) + std::pow(vertices[b].second - vertices[e].second, 2));
    }

    std::vector<double> prim() {
        std::vector<double> min_e(size, INF); 
        std::vector<int>sel_e(size, -1);
        std::vector<double> weights;
        min_e[0] = 0;
        for (int i = 0; i < size; ++i) {
            int v = -1;
            for (int j = 0; j < size; ++j)
                if (!color[j] && (v == -1 || min_e[j] < min_e[v]))
                    v = j;

            color[v] = true;
            if (sel_e[v] != -1)
                weights.push_back(get_weight(v, sel_e[v]));

            for (int to = 0; to < size; ++to)
                if (get_weight(v, to) < min_e[to]) {
                    min_e[to] = get_weight(v, to);
                    sel_e[to] = v;
                }
        }
        return weights;
    }

    double get_weight_mst() {
        std::vector<double> weights = prim();
        double result = 0;
        for (double i : weights) {
            result += i;
        }
        return result;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    Graph graph(n);
    double x, y;
    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        graph.add_vertice(x, y);
    }
    std::cout << graph.get_weight_mst();
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
