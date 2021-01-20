// compare_substring.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

uint64_t SHIFT = (uint64_t)('a');

uint64_t ord(char c) {
    return (uint64_t)c - SHIFT + 1;
}

class str {
private:
    std::string text;
    std::vector<uint64_t> hash;
    std::vector<uint64_t> powp;
    uint64_t p;

    uint64_t gethash(size_t left, size_t right) {
        if (left == 0) {
            return hash[right];
        }
        else {
            return hash[right] - hash[left - 1] * powp[right - left + 1];
        }
    }

public:
    str(std::string s) {
        text = s;
        p = 37;
        hash.resize(text.size());
        powp.resize(text.size());
        hash[0] = ord(text[0]);
        powp[0] = 1;
        for (size_t i = 1; i < text.size(); ++i) {
            hash[i] = hash[i - 1] * p + ord(text[i]);
            powp[i] = powp[i - 1] * p;
        }
    }

    bool compare_substring(size_t a, size_t b, size_t c, size_t d) {
        return gethash(a - 1, b - 1) == gethash(c - 1, d - 1);
    }
};


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::cin >> s;
    str cs(s);
    int m;
    std::cin >> m;
    size_t a, b, c, d;
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> c >> d;
        if (cs.compare_substring(a, b, c, d)) {
            std::cout << "Yes\n";
        }
        else {
            std::cout << "No\n";
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
