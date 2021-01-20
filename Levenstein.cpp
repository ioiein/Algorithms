// Levenstein.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <algorithm>

int levenstein_distance(const std::string& str1, const std::string& str2) {
    int** dp = new int* [str1.length() + 1];
    for (int i = 0; i < str1.length() + 1; i++) {
        dp[i] = new int[str2.length() + 1];
    }
    for (int i = 0; i < str1.length() + 1; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i < str2.length() + 1; i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i < str1.length() + 1; i++) {
        for (int j = 1; j < str2.length() + 1; j++) {
            dp[i][j] = std::min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, 
                dp[i - 1][j - 1] + !(str1[i - 1] == str2[j - 1]) });
        }
    }
    return dp[str1.length()][str2.length()];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str1, str2;
    std::cin >> str1 >> str2;
    int result = levenstein_distance(str1, str2);
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
