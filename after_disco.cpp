// after_disco.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int Range = 26;
const int Shift = 97;

int asciitocnt(char a)
{
	return (int)a - Shift;
}

bool cnt_cmp(const vector<int>& A, const vector<int> B)
{
	for (int i = 0; i < Range; i++)
	{
		if (A[i] < B[i])
		{
			return false;
		}
	}
	return true;
}

uint64_t count_substring(const string& s, const string& cards, const int length, const int count_cards)
{
	vector<int> cnt_cards(Range);
	for (int i = 0; i < count_cards; i++)
	{
		cnt_cards[asciitocnt(cards[i])]++;
	}
	uint64_t count = 0;
	vector<int> cnt_substring(Range);
	cnt_substring[asciitocnt(s[0])]++;
	int start = 0;
	int end = 0;
	while (end < length)
	{
		if (cnt_cmp(cnt_cards, cnt_substring))
		{
			count += end - start + 1;
			if (end - start < count_cards)
			{
				end++;
				if (end < length)
				{
					cnt_substring[asciitocnt(s[end])]++;
				}
			}
			else
			{
				cnt_substring[asciitocnt(s[start])]--;
				start++;
			}
		}
		else
		{
			if (end - start > 0)
			{
				cnt_substring[asciitocnt(s[start])]--;
				start++;
			}
			else
			{
				cnt_substring[asciitocnt(s[start])]--;
				start++;
				end++;
				if (end < length)
				{
					cnt_substring[asciitocnt(s[end])]++;
				}
			}
		}
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	uint64_t result = count_substring(s, t, n, m);
	cout << result;
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
