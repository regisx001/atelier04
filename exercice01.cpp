#include <iostream>
using namespace std;

class Complex {
private:
  double real;
  double imag;

public:
  // Constructor
  Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

  // Method to display the complex number
  void display() const { cout << real << " + " << imag << "i" << endl; }

  // Addition
  Complex add(const Complex &other) const {
    return Complex(real + other.real, imag + other.imag);
  }

  // Subtraction
  Complex subtract(const Complex &other) const {
    return Complex(real - other.real, imag - other.imag);
  }

  // Multiplication
  Complex multiply(const Complex &other) const {
    return Complex(real * other.real - imag * other.imag,
                   real * other.imag + imag * other.real);
  }

  // Division
  Complex divide(const Complex &other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    return Complex((real * other.real + imag * other.imag) / denominator,
                   (imag * other.real - real * other.imag) / denominator);
  }

  // Equality check
  bool isEqual(const Complex &other) const {
    return real == other.real && imag == other.imag;
  }
};

void showMenu() {
  cout << "Choose an operation:" << endl;
  cout << "1. Addition" << endl;
  cout << "2. Subtraction" << endl;
  cout << "3. Multiplication" << endl;
  cout << "4. Division" << endl;
  cout << "5. Equality check" << endl;
  cout << "Enter your choice: ";
}

int main() {
  double r1, i1, r2, i2;
  cout << "Enter the real and imaginary parts of the first complex number: ";
  cin >> r1 >> i1;
  cout << "Enter the real and imaginary parts of the second complex number: ";
  cin >> r2 >> i2;

  Complex c1(r1, i1);
  Complex c2(r2, i2);
  Complex result;

  int choice;
  showMenu();
  cin >> choice;

  switch (choice) {
  case 1: // Addition
    result = c1.add(c2);
    cout << "Result of addition: ";
    result.display();
    break;
  case 2: // Subtraction
    result = c1.subtract(c2);
    cout << "Result of subtraction: ";
    result.display();
    break;
  case 3: // Multiplication
    result = c1.multiply(c2);
    cout << "Result of multiplication: ";
    result.display();
    break;
  case 4: // Division
    result = c1.divide(c2);
    cout << "Result of division: ";
    result.display();
    break;
  case 5: // Equality check
    if (c1.isEqual(c2))
      cout << "The complex numbers are equal." << endl;
    else
      cout << "The complex numbers are not equal." << endl;
    break;
  default:
    cout << "Invalid choice!" << endl;
  }

  return 0;
}
