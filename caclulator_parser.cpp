// caclulator_parser.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

std::string END_OF_LEXEMS = "end";

std::string convert_chr_to_str(char c) {
    std::string result(1, c);
    return result;
}

class Lexer {
private:
    std::vector<std::string> lexems;
    size_t position;
public:
    Lexer(std::string s) {
        position = 0;
        int i = 0;
        while (s[i] != '.') {
            switch (s[i]) {
            case '*':
            case '+':
            case '-':
            case '(':
            case ')':
                lexems.push_back(convert_chr_to_str(s[i]));
                ++i;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                std::string number;
                while (s[i] >= '0' && s[i] <= '9') {
                    number += s[i];
                    ++i;
                }
                lexems.push_back(number);
                break;
            }
        }
    }

    std::string next_lexem() {
        if (position < lexems.size()) {
            ++position;
            return lexems[position - 1];
        }
        else {
            return END_OF_LEXEMS;
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
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
