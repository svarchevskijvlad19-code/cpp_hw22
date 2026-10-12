#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

class Vector2D {
private:
    double x;
    double y;
    char* name;

public:
    // Конструктор без параметрів
    Vector2D() : x(0), y(0), name(nullptr) {}

    // Конструктор з координатами
    Vector2D(double x, double y) : x(x), y(y), name(nullptr) {}

    // Конструктор з ім'ям
    Vector2D(double x, double y, const char* name)
        : x(x), y(y), name(nullptr) {
        setName(name);
    }

    // Конструктор копіювання
    Vector2D(const Vector2D& other)
        : x(other.x), y(other.y), name(nullptr) {
        setName(other.name);
    }

    // Аксесори для координати X
    double getX() const {
        return x;
    }

    void setX(double value) {
        x = value;
    }

    // Аксесори для координати Y
    double getY() const {
        return y;
    }

    void setY(double value) {
        y = value;
    }

    // Аксесори для імені вектора
    const char* getName() const {
        return name ? name : "";
    }

    void setName(const char* newName) {
        delete[] name;
        name = nullptr;

        if (newName != nullptr && newName[0] != '\0') {
            name = new char[strlen(newName) + 1];
            strcpy_s(name, strlen(newName) + 1, newName);
        }
    }

    // Рядкове представлення вектора
    string to_string() const {
        ostringstream out;

        if (name != nullptr) {
            out << "Ім'я: " << name << ", ";
        }

        out << "Координати: (" << x << ", " << y << ")";

        return out.str();
    }

    // Деструктор
    ~Vector2D() {
        delete[] name;
    }
};

int main() {
    setlocale(LC_ALL, "");

    // Створення об'єктів різними конструкторами
    Vector2D v1;
    Vector2D v2(3, 4);
    Vector2D v3(5, 7, "Вектор A");

    // Створення об'єкта за допомогою копіювання
    Vector2D v4(v3);

    // Зміна імені копії
    v4.setName("Копія вектора A");

    // Встановлення імені іншому вектору
    v1.setName("Нульовий вектор");

    // Виведення даних
    cout << v1.to_string() << endl;
    cout << v2.to_string() << endl;
    cout << v3.to_string() << endl;
    cout << v4.to_string() << endl;

    return 0;
}