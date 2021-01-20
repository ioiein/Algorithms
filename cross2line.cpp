// cross2line.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

bool two_line_intersect(Point start1, Point end1, Point start2, Point end2) {
    Vector ab(start1, end1);
    Vector ac(start1, start2);
    Vector ad(start1, end2);
    Vector ca(start2, start1);
    Vector cb(start2, end1);
    Vector cd(start2, end2);
    if ((ab & ac) * (ab & ad) <= 0 && (cd & ca) * (cd & cb) <= 0) {
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
    Point a(x, y);
    std::cin >> x >> y;
    Point b(x, y);
    std::cin >> x >> y;
    Point c(x, y);
    std::cin >> x >> y;
    Point d(x, y);
    if (two_line_intersect(a, b, c, d)) {
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
