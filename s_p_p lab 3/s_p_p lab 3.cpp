#include <iostream>
using namespace std;

class Complex_number {
private:
    double real;
    double imag;

public:
    // Конструктор за замовчуванням
    Complex_number() : real(0), imag(0) {}

    // Конструктор з параметрами для double чисел
    Complex_number(double r, double i) : real(r), imag(i) {}

    // Конструктор з параметрами для цілих чисел
    Complex_number(int r, int i) : real(static_cast<double>(r)), imag(static_cast<double>(i)) {}

    // Операція додавання
    Complex_number operator+(const Complex_number& other) const {
        return Complex_number(real + other.real, imag + other.imag);
    }

    // Операція віднімання
    Complex_number operator-(const Complex_number& other) const {
        return Complex_number(real - other.real, imag - other.imag);
    }

    // Операція множення
    Complex_number operator*(const Complex_number& other) const {
        double result_real = real * other.real - imag * other.imag;
        double result_imag = real * other.imag + imag * other.real;
        return Complex_number(result_real, result_imag);
    }

    // Функція для виводу комплексного числа
    friend ostream& operator<<(ostream& output, const Complex_number& c) {
        output << c.real << " + " << c.imag << "i";
        return output;
    }
};

int main() {
    Complex_number a(3.0, 2.0);
    Complex_number b(1, -1);

    Complex_number sum = a + b;
    Complex_number difference = a - b;
    Complex_number product = a * b;

    cout << "sum: " << sum << endl;
    cout << "difference: " << difference << endl;
    cout << "product: " << product << endl;

    return 0;
}
/*Скласти опис класу для представлення комплексних чисел з
можливістю задання дійсної і уявної частин як числами типів double,
так і цілими числами. Забезпечити виконання операцій додавання,
віднімання і множення комплексних чисел. 
*/