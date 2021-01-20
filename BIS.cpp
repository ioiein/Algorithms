// BIS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iterator>;
#include <algorithm>

void subseq(const std::vector<int>& arr) {
    std::vector<std::pair<int, int>> dp(arr.size());
    dp[0] = std::make_pair(1, -1);
    int max_seq = 1;
    int end = 0;
    for (int i = 1; i < arr.size(); i++) {
        int max = 0;
        dp[i].second = -1;
        for (int j = 0; j < i; j++) {
            if (dp[j].first > max && arr[j] < arr[i]) {
                max = dp[j].first;
                dp[i].second = j;
            }
        }
        dp[i].first = max + 1;
        if (max + 1 > max_seq) {
            max_seq = max + 1;
            end = i;
        }
    }
    int i = end;
    std::vector<int> sub;
    while (i > -1) {
        sub.push_back(arr[i]);
        i = dp[i].second;
    }
    std::cout << sub.size() << '\n';
    for (int i = 0; i < sub.size(); i++) {
        std::cout << sub[sub.size() - 1 - i] << ' ';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> input_array;
    copy_n(std::istream_iterator<int>(std::cin), n, back_inserter(input_array));
    subseq(input_array);
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
