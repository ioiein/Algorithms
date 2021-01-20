// algo_hw_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>

const int TWO_16 = (int)pow(2, 16);
const long long TWO_30 = (long long)pow(2, 30);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, x, y;
    std::cin >> n >> x >> y;
    int* a = new int[n];
    std::cin >> a[0];
    int m;
    long long z, t;
    std::cin >> m >> z >> t;
    long long* b = new long long[2 * m];
    std::cin >> b[0];
    long long* sum = new long long[n + 1];
    sum[0] = 0;
    sum[1] = (long long)a[0];
    for (int i = 1; i < n; ++i) {
        a[i] = (((x * a[i - 1]) % TWO_16) + y) % TWO_16;
        sum[i + 1] = sum[i] + (long long)a[i];
    }
    for (int i = 1; i < 2 * m; ++i) {
        b[i] = (((z * b[i - 1]) % TWO_30) + t + TWO_30) % TWO_30;
    }
    for (int i = 0; i < 2 * m; ++i) {
        b[i] %= n;
    }
    long long result = 0;
    for (int i = 0; i < m; ++i) {
        if (b[2 * i + 1] > b[2 * i]) {
            result += (sum[b[2 * i + 1] + 1] - sum[b[2 * i]]);
        }
        else {
            result += (sum[b[2 * i] + 1] - sum[b[2 * i + 1]]);
        }
    }
    std::cout << result;
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
