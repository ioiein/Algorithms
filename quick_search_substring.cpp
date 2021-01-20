// quick_search_substring.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

std::vector<int> p_function(std::string s) {
    std::vector<int> p(s.size(), 0);
    int k;
    for (int i = 1; i < s.size(); ++i) {
        k = p[i - 1];
        while (k > 0 && s[i] != s[k]) {
            k = p[k - 1];
        }
        if (s[i] == s[k]) {
            k++;
        }
        p[i] = k;
    }
    return p;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string p, t;
    std::cin >> p >> t;
    std::string s = p + "#" + t;
    std::vector<int> pf = p_function(s);
    std::vector<int> repeats;
    for (int i = p.size() + 1; i < s.size(); ++i) {
        if (p.size() == pf[i]) {
            repeats.push_back(i - 2 * p.size() + 1);
        }
    }
    std::cout << repeats.size() << '\n';
    for (int i = 0; i < repeats.size(); ++i) {
        std::cout << repeats[i] << ' ';
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
