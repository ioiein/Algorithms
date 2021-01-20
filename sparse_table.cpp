// sparse_table.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

const uint32_t A1 = 23;
const uint32_t B1 = 21563;
const uint32_t M1 = 16714589;

const uint32_t A2 = 17;
const uint32_t B2 = 751;
const uint32_t C2 = 2;

const uint32_t A3 = 13;
const uint32_t B3 = 593;
const uint32_t C3 = 5;

uint32_t rmq(uint32_t** min, uint32_t left, uint32_t right) {
    if (left > right) {
        std::swap(left, right);
    }
    uint32_t k;
    for (k = 0; (1 << k) <= right - left + 1; ++k) {};
    --k;
    return std::min(min[left][k], min[right - (1 << k) + 1][k]);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    uint32_t n, m;
    std::cin >> n >> m;
    uint32_t* a = new uint32_t[n];
    std::cin >> a[0];
    uint32_t u, v;
    std::cin >> u >> v;
    for (size_t i = 1; i < n; ++i) {
        a[i] = (((A1 * a[i - 1]) % M1) + B1) % M1;
    }
    uint32_t lg_n = (uint32_t)std::log2(n) + 1;
    uint32_t** min = new uint32_t * [n];
    for (int i = 0; i < n; ++i) {
        min[i] = new uint32_t[lg_n];
    }
    for (int i = 0; i < n; ++i) {
        min[i][0] = a[i];
    }
    for (int j = 1; j < lg_n; ++j) {
        for (int i = 0; i < n; ++i) {
            min[i][j] = std::min(min[i][j - 1], min[std::min(i + (1 << (j - 1)), (int)n - 1)][j - 1]);
        }
    }
    uint32_t result = rmq(min, u - 1, v - 1);
    for (int i = 1; i < m; ++i) {
        u = ((A2 * u + B2 + result + C2 * i) % n) + 1;
        v = ((A3 * v + B3 + result + C3 * i) % n) + 1;
        result = rmq(min, u - 1, v - 1);
    }
    std::cout << u << ' ' << v << ' ' << result;
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
