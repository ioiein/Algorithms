// AVL_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class AVL_tree {
public:
    struct Node {
        int key;
        int height;
        int count;
        Node* left;
        Node* right;

        Node() {
            key = 0;
            height = 1;
            count = 1;
            left = nullptr;
            right = nullptr;
        }

        Node(int x) {
            key = x;
            height = 1;
            count = 1;
            left = nullptr;
            right = nullptr;
        }

        Node(const Node& copy) {
            key = copy.key;
            height = copy.height;
            count = 1;
            left = copy.left;
            right = copy.right;
        }
    };

    Node* root;

    AVL_tree() {
        root = nullptr;
    }

    int get_height(Node* p) {
        if (p != nullptr) {
            return p->height;
        }
        else {
            return 0;
        }
    }

    int get_count(Node* p) {
        if (p != nullptr) {
            return p->count;
        }
        else {
            return 0;
        }
    }

    int get_balance(Node* p) {
        return get_height(p->right) - get_height(p->left);
    }

    void fix_height(Node* p) {
        int left_height = get_height(p->left);
        int right_height = get_height(p->right);
        p->height = std::max(left_height, right_height) + 1;
    }

    void fix_count(Node* p) {
        int left_count = get_count(p->left);
        int right_count = get_count(p->right);
        p->count = left_count + right_count + 1;
    }

    Node* rotate_right(Node* p) {
        Node* q = p->left;
        p->left = q->right;
        q->right = p;
        fix_height(p);
        fix_height(q);
        fix_count(p);
        fix_count(q);
        return q;
    }

    Node* rotate_left(Node* p) {
        Node* q = p->right;
        p->right = q->left;
        q->left = p;
        fix_height(p);
        fix_height(q);
        fix_count(p);
        fix_count(q);
        return q;
    }

    Node* balance(Node* p) {
        fix_height(p);
        fix_count(p);
        if (get_balance(p) == 2) {
            if (get_balance(p->right) < 0) {
                p->right = rotate_right(p->right);
            }
            return rotate_left(p);
        }
        else if (get_balance(p) == -2) {
            if (get_balance(p->left) > 0) {
                p->left = rotate_left(p->left);
            }
            return rotate_right(p);
        }
        else {
            return p;
        }
    }

    Node* insert(Node* vertice, int x) {
        if (vertice == nullptr) {
            vertice = new Node(x);
        }
        else if (x < vertice->key) {
            vertice->left = insert(vertice->left, x);
        }
        else if (x > vertice->key) {
            vertice->right = insert(vertice->right, x);
        }
        return balance(vertice);
    }

    Node* find_max(Node* vertice) {
        while (vertice->right != nullptr) {
            vertice = vertice->right;
        }
        return vertice;
    }

    Node* remove(Node* vertice, int x) {
        if (vertice == nullptr) { return nullptr; }
        else if (x < vertice->key) {
            vertice->left = remove(vertice->left, x);
            return balance(vertice);
        }
        else if (x > vertice->key) {
            vertice->right = remove(vertice->right, x);
            return balance(vertice);
        }
        else {
            Node* l = vertice->left;
            Node* r = vertice->right;
            delete vertice;
            if (r == nullptr && l == nullptr) { return nullptr; }
            else if (r == nullptr) { return l; }
            else if (l == nullptr) { return r; }
            else {
                Node* max = new Node(*find_max(l));
                max->left = remove(l, max->key);
                max->right = r;
                return balance(max);
            }
        }
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

    int k_max(Node* vertice, int k) {
        if (vertice->right->count == k - 1) {
            return vertice->key;
        }
        else if (vertice->right->count >= k) {
            return k_max(vertice->right, k);
        }
        else if (vertice->right->count < k - 1) {
            return k_max(vertice->left, k - vertice->right->count - 1);
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    AVL_tree avl_t;
    int x;
    std::string command;
    while (std::cin >> command) {
        std::cin >> x;
        if (command == "insert") {
            avl_t.root = avl_t.insert(avl_t.root, x);
        }
        else if (command == "delete") {
            avl_t.root = avl_t.remove(avl_t.root, x);
        }
        else if (command == "exists") {
            auto result = avl_t.search(avl_t.root, x);
            if (result == nullptr) {
                std::cout << "false\n";
            }
            else {
                std::cout << "true\n";
            }
        }
        else if (command == "next") {
            auto result = avl_t.next(x);
            if (result == nullptr) {
                std::cout << "none\n";
            }
            else {
                std::cout << result->key << '\n';
            }
        }
        else {
            auto result = avl_t.previous(x);
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
