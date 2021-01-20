// Cafe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

const int MAX_COST = 301;
const int TICKET_BORDER = 100;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> input_array;
    copy_n(std::istream_iterator<int>(std::cin), n, back_inserter(input_array));
    int k1, k2;
    int** dp = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = new int[n + 2];
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 2; j++)
            dp[i][j] = INT32_MAX - MAX_COST;
    }
    dp[0][0] = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) {
                if (input_array[i - 1] <= TICKET_BORDER) {
                    dp[i][j] = std::min(dp[i - 1][j + 1], dp[i - 1][j] + input_array[i - 1]);
                }
                else {
                    dp[i][j] = dp[i - 1][j + 1];
                }
            }
            else {
                if (input_array[i - 1] > TICKET_BORDER) {
                    dp[i][j] = std::min(dp[i - 1][j + 1], dp[i - 1][j - 1] + input_array[i - 1]);
                }
                else {
                    dp[i][j] = std::min(dp[i - 1][j + 1], dp[i - 1][j] + input_array[i - 1]);
                }
            }
        }
    }
    int ans = INT32_MAX;
    for (int i = 0; i < n + 1; i++) {
        if (ans >= dp[n][i]) {
            ans = dp[n][i];
            k1 = i;
        }
    }

    std::vector<int> day_use_ticket;
    int i = n;
    int j = k1;

    while (j < i) {
        if (j <= 0) {
            if (i >= 1) {
                if (input_array[i - 1] > TICKET_BORDER) {
                    day_use_ticket.push_back(i);
                    --i;
                    ++j;
                }
                else {
                    if (dp[i][j] == dp[i - 1][j + 1]) {
                        day_use_ticket.push_back(i);
                        --i; 
                        ++j;
                    }
                    else {
                        --i;
                    }
                }
            }
        }
        else {
            if (input_array[i - 1] <= TICKET_BORDER) {
                if (dp[i - 1][j + 1] == dp[i][j]) {
                    day_use_ticket.push_back(i);
                    --i;
                    ++j;
                }
                else {
                    --i;
                }
            }
            else {
                if (dp[i - 1][j + 1] == dp[i][j]) {
                    day_use_ticket.push_back(i);
                    --i;
                    ++j;
                }
                else {
                    --i;
                    --j;
                }
            }
        }
    }
    k2 = day_use_ticket.size();
    std::cout << ans << '\n';
    std::cout << k1 << ' ' << k2 << '\n';
    for (int s = 0; s < k2; s++) {
        std::cout << day_use_ticket[k2 - 1 - s] << '\n';
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
