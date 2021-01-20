// simple_BST.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class Binary_tree {
public:
    struct Node {
        int key;
        Node* left;
        Node* right;

        Node() {
            key = 0;
            left = nullptr;
            right = nullptr;
        }

        Node(int value) {
            key = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    Binary_tree() {
        root = nullptr;
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

    Node* insert(Node* vertice, int x) {
        if (vertice == nullptr) {
            return new Node(x);
        }
        else if (vertice->key == x) {
            return vertice;
        }
        else if (x < vertice->key) {
            vertice->left = insert(vertice->left, x);
            return vertice;
        }
        else {
            vertice->right = insert(vertice->right, x);
            return vertice;
        }
    }

    Node* remove(Node* vertice, int x) {
        if (vertice == nullptr) {
            return nullptr;
        }
        else if (x < vertice->key) {
            vertice->left = remove(vertice->left, x);
            return vertice;
        }
        else if (x > vertice->key) {
            vertice->right = remove(vertice->right, x);
            return vertice;
        }
        else if (vertice->left == nullptr && vertice->right == nullptr) {
            delete vertice;
            return nullptr;
        }
        else if (vertice->left == nullptr) {
            Node* new_vertice = vertice->right;
            delete vertice;
            return new_vertice;
        }
        else if (vertice->right == nullptr) {
            Node* new_vertice = vertice->left;
            delete vertice;
            return new_vertice;
        }
        else {
            vertice->key = find_max(vertice->left)->key;
            vertice->left = remove(vertice->left, vertice->key);
            return vertice;
        }
    }

    Node* find_max(Node* vertice) {
        while (vertice->right != nullptr) {
            vertice = vertice->right;
        }
        return vertice;
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
    Binary_tree bt;
    int x;
    std::string command;
    while (std::cin >> command) {
        std::cin >> x;
        if (command == "insert") {
            bt.root = bt.insert(bt.root, x);
        }
        else if (command == "delete") {
            bt.root = bt.remove(bt.root, x);
        }
        else if (command == "exists") {
            auto result = bt.search(bt.root, x);
            if (result == nullptr) {
                std::cout << "false\n";
            }
            else {
                std::cout << "true\n";
            }
        }
        else if (command == "next") {
            auto result = bt.next(x);
            if (result == nullptr) {
                std::cout << "none\n";
            }
            else {
                std::cout << result->key << '\n';
            }
        }
        else {
            auto result = bt.previous(x);
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