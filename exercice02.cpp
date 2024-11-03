#include <iostream>
#include <string>
using std::string;

class Animal {
public:
  void setValue(string nom, int age) {
    this->age = age;
    this->nom = nom;
  }

protected:
  string nom;
  int age;
};

class Zebra : public Animal {
public:
  void printInfo() {
    std::cout << "Nom :" << nom << "\n";
    std::cout << "Age :" << age << "\n";
    std::cout << "Lieu d'origine :" << lieu_origin << "\n";
  }

private:
  string lieu_origin = "Ocean";
};

class Dolphin : public Animal {
public:
  void printInfo() {
    std::cout << "Nom :" << nom << "\n";
    std::cout << "Age :" << age << "\n";
    std::cout << "Lieu d'origine :" << lieu_origin << "\n";
  }

private:
  string lieu_origin = "Savana";
};

int main() {
  Zebra zebra;
  Dolphin dolphin;

  dolphin.setValue("Dolphin01", 10);
  zebra.setValue("Zebra01", 20);

  dolphin.printInfo();
  zebra.printInfo();
  return 0;
}
