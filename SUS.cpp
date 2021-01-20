// SUS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

class System_unjoined_sets {
private:
    std::vector<int> p;
    std::vector<int> rank;
    std::vector<int> min;
    std::vector<int> max;
    std::vector<int> count;

public:
    System_unjoined_sets(int size) {
        p.resize(size);
        rank.resize(size);
        min.resize(size);
        max.resize(size);
        count.resize(size);
        for (int i = 0; i < size; ++i) {
            p[i] = i;
            rank[i] = 0;
            min[i] = i;
            max[i] = i;
            count[i] = 1;
        }
    }

    int get(int x, bool print = false) {
        if (p[x] != x) {
            p[x] = get(p[x], print);
        }
        else if (print == true) {
            std::cout << min[x] + 1 << ' ' << max[x] + 1 << ' ' << count[x] << '\n';
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
            min[y] = std::min(min[x], min[y]);
            max[y] = std::max(max[x], max[y]);
            count[y] = count[x] + count[y];
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    System_unjoined_sets sus(n);
    std::string command;
    int x, y;
    while (std::cin >> command) {
        if (command == "union") {
            std::cin >> x >> y;
            sus.join(x - 1, y - 1);
        }
        else {
            std::cin >> x;
            sus.get(x - 1, true);
        }
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