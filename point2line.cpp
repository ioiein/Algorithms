// point2line.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Point {
public:
    double x;
    double y;

    Point(double x_, double y_) {
        x = x_;
        y = y_;
    }

    bool operator==(const Point& other) {
        if (this->x == other.x && this->y == other.y) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Vector {
public:
    double x;
    double y;

    Vector(double x_, double y_) {
        x = x_;
        y = y_;
    }

    Vector(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    Vector operator+(const Vector& other) {
        return Vector(other.x + this->x, other.y + this->y);
    }

    double operator*(const Vector& other) {
        return this->x * other.x + this->y * other.y;
    }

    double operator&(const Vector& other) {
        return this->x * other.y - this->y * other.x;
    }
};

bool check_point_belong_to_line(Point start, Point end, Point c) {
    Vector ca(c, start);
    Vector cb(c, end);
    if ((ca & cb) == 0 && ca * cb < 0 || c == start || c == end) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double x, y;
    std::cin >> x >> y;
    Point c(x, y);
    std::cin >> x >> y;
    Point start(x, y);
    std::cin >> x >> y;
    Point end(x, y);
    if (check_point_belong_to_line(start, end, c)) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
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
