// Reposts.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <map>
#include<string>
#include<algorithm>

class Graph {
private:
    std::map<std::string, int> dict_of_names;
    std::vector<std::vector<int>> adjacency;
    std::vector<int> color;
    int current_number;

    int dfs(int vertice) {
        color[vertice] = 1;
        int depth = 0;
        for (int i : adjacency[vertice]) {
            if (color[i] == 0) {
                int res = dfs(i);
                if (res > depth) {
                    depth = res;
                }
            }
        }
        return depth + 1;
    }
public:
    Graph() {
        current_number = 0;
    }

    void add_edge(std::string name1, std::string name2) {
        std::transform(name1.begin(), name1.end(), name1.begin(), tolower);
        std::transform(name2.begin(), name2.end(), name2.begin(), tolower);
        int begin, end;
        if (dict_of_names.find(name2) == dict_of_names.end()) {
            dict_of_names.insert(std::make_pair(name2, current_number));
            begin = current_number;
            ++current_number;
            adjacency.push_back(std::vector<int>());
            color.push_back(0);
        }
        else {
            begin = dict_of_names.find(name2)->second;
        }
        if (dict_of_names.find(name1) == dict_of_names.end()) {
            dict_of_names.insert(std::make_pair(name1, current_number));
            end = current_number;
            ++current_number;
            adjacency.push_back(std::vector<int>());
            color.push_back(0);
        }
        else {
            end = dict_of_names.find(name1)->second;
        }
        adjacency[begin].push_back(end);
    }

    int max_depth() {
        return dfs(0);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::string name1, name2, reposted;
    Graph graph;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> name1 >> reposted >> name2;
        graph.add_edge(name1, name2);
    }
    std::cout << graph.max_depth();
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
