// implicit value.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Decart_tree {
public:
    struct Node {
        int value;
        int priority;
        int size;
        Node* left;
        Node* right;

        Node() {
            value = 0;
            priority = 0;
            size = 1;
            left = nullptr;
            right = nullptr;
        }

        Node(int x, int y) {
            value = x;
            priority = y;
            size = 1;
            left = nullptr;
            right = nullptr;
        }

        Node(const Node& copy) {
            value = copy.value;
            priority = copy.priority;
            size = copy.size;
            left = copy.left;
            right = copy.right;
        }
    };

    Node* root;

    Decart_tree() {
        root = nullptr;
    }

    int get_size(Node* p) {
        if (p == nullptr) {
            return 0;
        }
        else {
            return p->size;
        }
    }

    void fix_size(Node* p) {
        p->size = get_size(p->left) + get_size(p->right) + 1;
    }

    std::pair<Node*, Node*> split(Node* vertice, int x) {
        if (vertice == nullptr) {
            return std::make_pair(nullptr, nullptr);
        }
        else if (get_size(vertice->left) >= x) {
            auto t = split(vertice->left, x);
            vertice->left = t.second;
            fix_size(vertice);
            return std::make_pair(t.first, vertice);
        }
        else {
            auto t = split(vertice->right, x - get_size(vertice->left) - 1);
            vertice->right = t.first;
            fix_size(vertice);
            return std::make_pair(vertice, t.second);
        }
    }

    Node* merge(std::pair<Node*, Node*> t) {
        if (t.first == nullptr) {
            return t.second;
        }
        else if (t.second == nullptr) {
            return t.first;
        }
        else if (t.first->priority > t.second->priority) {
            t.first->right = merge(std::make_pair(t.first->right, t.second));
            fix_size(t.first);
            return t.first;
        }
        else {
            t.second->left = merge(std::make_pair(t.first, t.second->left));
            fix_size(t.second);
            return t.second;
        }
    }

    Node* insert(Node* vertice, int i, int x, int y) {
        auto t = split(vertice, i);
        Node* new_node = new Node(x, y);
        Node* t1 = merge(std::make_pair(t.first, new_node));
        return merge(std::make_pair(t1, t.second));
    }

    Node* remove_last(Node* vertice) {
        if (vertice->right == nullptr) {
            Node* l = vertice->left;
            delete vertice;
            return l;
        }
        else {
            vertice->right = remove_last(vertice->right);
            fix_size(vertice);
            return vertice;
        }
    }

    Node* remove(Node* vertice, int i) {
        auto t = split(vertice, i);
        t.first = remove_last(t.first);
        return merge(t);
    }

    void print(Node* vertice) {
        if (vertice == root) {
            std::cout << get_size(vertice) << '\n';
        }
        if (vertice == nullptr) {
            return;
        }
        else {
            print(vertice->left);
            std::cout << vertice->value << ' ';
            print(vertice->right);
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    Decart_tree dec_t;
    int i, x;
    int n0, m;
    std::cin >> n0 >> m;
    for (i = 0; i < n0; ++i) {
        std::cin >> x;
        dec_t.root = dec_t.insert(dec_t.root, i, x, rand());
    }
    std::string command;
    for (int j = 0; j < m; ++j) {
        std::cin >> command;
        if (command == "add") {
            std::cin >> i >> x;
            dec_t.root = dec_t.insert(dec_t.root, i, x, rand());
        }
        else {
            std::cin >> i;
            dec_t.root = dec_t.remove(dec_t.root, i);
        }
    }
    dec_t.print(dec_t.root);
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
