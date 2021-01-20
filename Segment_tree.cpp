// Segment_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

class Segment_tree {
public:
    std::vector<long long> t;
    std::vector<long long> upd;
    int x;

    Segment_tree(const std::vector<long long>& input) {
        x = 1;
        while (x < input.size()) {
            x *= 2;
        }
        t.resize(2 * x - 1);
        upd.resize(2 * x - 1);
        for (int i = 0; i < input.size(); ++i) {
            t[i + x - 1] = input[i];
        }
        for (int i = input.size(); i < x; ++i) {
            t[i + x - 1] = INT64_MAX;
        }
        for (int i = x - 2; i >= 0; --i) {
            t[i] = std::min(t[2 * i + 1], t[2 * i + 2]);
        }
    }

    long long get(int vertice) {
        if (t[vertice] == INT64_MAX) {
            return t[vertice];
        }
        else {
            return t[vertice] + upd[vertice];
        }
    }

    void push(int vertice, int left, int right) {
        if (left == right) {
            if (t[vertice] != INT64_MAX) {
                t[vertice] += upd[vertice];
            }
        }
        else {
            upd[2 * vertice + 1] += upd[vertice];
            upd[2 * vertice + 2] += upd[vertice];
            t[vertice] = std::min(get(2 * vertice + 1), get(2 * vertice + 2));
        }
        upd[vertice] = 0;
    }

    void add(int vertice, int left, int right, int left_bord, int right_bord, long long value) {
        push(vertice, left, right);
        if (left > right_bord || right < left_bord) {}
        else if (left >= left_bord && right <= right_bord) {
            upd[vertice] += value;
        }
        else {
            int mid = (left + right) / 2;
            add(2 * vertice + 1, left, mid, left_bord, right_bord, value);
            add(2 * vertice + 2, mid + 1, right, left_bord, right_bord, value);
            t[vertice] = std::min(get(2 * vertice + 1), get(2 * vertice + 2));
        }
    }

    void set(int vertice, int left, int right, int left_bord, int right_bord, long long value) {
        if (left > right_bord || right < left_bord) {}
        else if (left == right) {
            t[vertice] = value;
            upd[vertice] = 0;
        }
        else if (left >= left_bord && right <= right_bord) {
            t[vertice] = value;
            upd[vertice] = 0;
            int mid = (left + right) / 2;
            set(2 * vertice + 1, left, mid, left_bord, right_bord, value);
            set(2 * vertice + 2, mid + 1, right, left_bord, right_bord, value);
        }
        else {
            int mid = (left + right) / 2;
            set(2 * vertice + 1, left, mid, left_bord, right_bord, value);
            set(2 * vertice + 2, mid + 1, right, left_bord, right_bord, value);
            t[vertice] = std::min(t[2 * vertice + 1], t[2 * vertice + 2]);
        }
    }

    long long rmq(int vertice, int left, int right, int left_bord, int right_bord) {
        push(vertice, left, right);
        if (left > right_bord || right < left_bord) {
            return INT64_MAX;
        }
        else if (left >= left_bord && right <= right_bord) {
            return get(vertice);
        }
        else {
            int mid = (left + right) / 2;
            long long value1 = rmq(2 * vertice + 1, left, mid, left_bord, right_bord);
            long long value2 = rmq(2 * vertice + 2, mid + 1, right, left_bord, right_bord);
            return std::min(value1, value2);
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<long long> input_array;
    input_array.reserve(n);
    copy_n(std::istream_iterator<long long>(std::cin), n, back_inserter(input_array));
    Segment_tree st(input_array);
    int i, j;
    long long value;
    std::string command;
    while (std::cin >> command) {
        if (command == "set") {
            std::cin >> i >> j;
            std::cin >> value;
            st.set(0, 0, st.x - 1, i - 1, j - 1, value);
        }
        else if (command == "add") {
            std::cin >> i >> j;
            std::cin >> value;
            st.add(0, 0, -1 + st.x, i - 1, j - 1, value);
        }
        else {
            std::cin >> i >> j;
            std::cout << st.rmq(0, 0, -1 + st.x, i - 1, j - 1) << '\n';
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
