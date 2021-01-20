// Fenvick_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

class Fenwick_tree {
public:
    std::vector<long long> arr;
    std::vector<long long> T;

    int F(int i) {
        return i & (i + 1);
    }

    Fenwick_tree(const std::vector<long long>& input) {
        arr = input;
        T.resize(arr.size());
        for (int i = 0; i < T.size(); ++i) {
            for (int j = F(i); j < i + 1; j++) {
                T[i] += arr[j];
            }
        }
    }

    long long get(int i) {
        long long result = 0;
        while (i >= 0) {
            result += T[i];
            i = F(i) - 1;
        }
        return result;
    }

    long long rsq(int left, int right) {
        if (left == 0) {
            return get(right);
        }
        else {
            return get(right) - get(left - 1);
        }
    }

    void add(int i, long long x) {
        int j = i;
        while (j < arr.size()) {
            T[j] += x;
            j = j | (j + 1);
        }
    }

    void set(int i, long long x) {
        long long d = x - arr[i];
        arr[i] = x;
        add(i, d);
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
    Fenwick_tree ft(input_array);
    std::string command;
    while (std::cin >> command) {
        if (command == "sum") {
            int i, j;
            std::cin >> i >> j;
            std::cout << ft.rsq(i - 1, j - 1) << '\n';
        }
        else {
            int i;
            long long x;
            std::cin >> i;
            std::cin >> x;
            ft.set(i - 1, x);
        }
    }
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
