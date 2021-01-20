// Balance_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Decart_tree {
public:
    struct Node {
        int key;
        int priority;
        Node* left;
        Node* right;

        Node() {
            key = 0;
            priority = 0;
            left = nullptr;
            right = nullptr;
        }

        Node(int x, int y) {
            key = x;
            priority = y;
            left = nullptr;
            right = nullptr;
        }

        Node(const Node& copy) {
            key = copy.key;
            priority = copy.priority;
            left = copy.left;
            right = copy.right;
        }
    };

    Node* root;

    Decart_tree() {
        root = nullptr;
    }

    std::pair<Node*, Node*> split(Node* vertice, int x) {
        if (vertice == nullptr) {
            return std::make_pair(nullptr, nullptr);
        }
        else if (vertice->key > x) {
            auto t = split(vertice->left, x);
            vertice->left = t.second;
            return std::make_pair(t.first, vertice);
        }
        else {
            auto t = split(vertice->right, x);
            vertice->right = t.first;
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
            return t.first;
        }
        else {
            t.second->left = merge(std::make_pair(t.first, t.second->left));
            return t.second;
        }
    }

    Node* insert(Node* vertice, int x, int y) {
        if (search(vertice, x) != nullptr) {
            return vertice;
        }
        else {
            auto t = split(vertice, x);
            Node* new_node = new Node(x, y);
            Node* t1 = merge(std::make_pair(t.first, new_node));
            return merge(std::make_pair(t1, t.second));
        }
    }

    Node* remove(Node* vertice, int x) {
        auto t = split(vertice, x);
        auto t1 = split(t.first, x - 1);
        return merge(std::make_pair(t1.first, t.second));
    }

    Node* search(Node* vertice, int x) {
        if (vertice == nullptr) {
            return nullptr;
        }
        else if (vertice->key == x) {
            return vertice;
        }
        else if (x < vertice->key) {
            return search(vertice->left, x);
        }
        else {
            return search(vertice->right, x);
        }
    }

    Node* next(int x) {
        Node* vertice = root;
        Node* result = nullptr;
        while (vertice != nullptr) {
            if (vertice->key > x) {
                result = vertice;
                vertice = vertice->left;
            }
            else {
                vertice = vertice->right;
            }
        }
        return result;
    }

    Node* previous(int x) {
        Node* vertice = root;
        Node* result = nullptr;
        while (vertice != nullptr) {
            if (vertice->key < x) {
                result = vertice;
                vertice = vertice->right;
            }
            else {
                vertice = vertice->left;
            }
        }
        return result;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    Decart_tree dec_t;
    int x;
    std::string command;
    while (std::cin >> command) {
        std::cin >> x;
        if (command == "insert") {
            dec_t.root = dec_t.insert(dec_t.root, x, rand());
        }
        else if (command == "delete") {
            dec_t.root = dec_t.remove(dec_t.root, x);
        }
        else if (command == "exists") {
            auto result = dec_t.search(dec_t.root, x);
            if (result == nullptr) {
                std::cout << "false\n";
            }
            else {
                std::cout << "true\n";
            }
        }
        else if (command == "next") {
            auto result = dec_t.next(x);
            if (result == nullptr) {
                std::cout << "none\n";
            }
            else {
                std::cout << result->key << '\n';
            }
        }
        else {
            auto result = dec_t.previous(x);
            if (result == nullptr) {
                std::cout << "none\n";
            }
            else {
                std::cout << result->key << '\n';
            }
        }
    }
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
