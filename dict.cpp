// dict.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

int ALPHABET_POWER = 26;
int SHIFT = (int)('a');
int MAX_LENGTH = 30;

int ord(char c) {
    return (int)c - SHIFT;
}

class Trie {
private:
    int size;
    int number;
    std::vector<std::vector<int>> next;
    std::vector<int> is_terminal;

public:
    Trie() {
        size = 1;
        number = 1;
        next.push_back(std::vector<int>(ALPHABET_POWER, -1));
        is_terminal.push_back(0);
    }

    void insert(std::string s) {
        int v = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (next[v][ord(s[i])] == -1) {
                next[v][ord(s[i])] = size;
                ++size;
                next.push_back(std::vector<int>(ALPHABET_POWER, -1));
                is_terminal.push_back(0);
            }
            v = next[v][ord(s[i])];
        }
        is_terminal[v] = number;
        ++number;
    }

    void contains(std::string s, std::vector<int>& answer) {
        int v = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (next[v][ord(s[i])] == -1) {
                return;
            }
            v = next[v][ord(s[i])];
            if (is_terminal[v] != 0) {
                answer[is_terminal[v] - 1] = 1;
            }
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::cin >> s;
    Trie trie;
    int m;
    std::string word;
    std::cin >> m;
    std::vector<int> answer(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> word;
        trie.insert(word);
    }
    for (int i = 0; i < s.size(); ++i) {
        trie.contains(s.substr(i, std::min(MAX_LENGTH, (int)(s.size() - i))), answer);
    }
    for (int i = 0; i < answer.size(); ++i) {
        if (answer[i] == 1) {
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
