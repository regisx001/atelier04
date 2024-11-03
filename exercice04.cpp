#include <cmath>
#include <iostream>
using namespace std;

class Vecteur3D {
private:
  float x, y, z;

public:
  // Constructeur avec des valeurs par défaut
  Vecteur3D(float x = 0.0, float y = 0.0, float z = 0.0) : x(x), y(y), z(z) {}

  // Fonction d'affichage des composantes
  void afficher() const {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
  }

  // Fonction pour obtenir la somme de deux vecteurs
  Vecteur3D somme(const Vecteur3D &v) const {
    return Vecteur3D(x + v.x, y + v.y, z + v.z);
  }

  // Fonction pour obtenir le produit scalaire de deux vecteurs
  float produitScalaire(const Vecteur3D &v) const {
    return x * v.x + y * v.y + z * v.z;
  }

  // Fonction pour vérifier si deux vecteurs coïncident
  bool coincide(const Vecteur3D &v) const {
    return x == v.x && y == v.y && z == v.z;
  }

  // Fonction pour obtenir la norme du vecteur
  float norme() const { return sqrt(x * x + y * y + z * z); }

  // Fonction pour obtenir le vecteur avec la plus grande norme (par valeur)
  Vecteur3D normaxParValeur(const Vecteur3D &v) const {
    return (this->norme() > v.norme()) ? *this : v;
  }

  // Fonction pour obtenir le vecteur avec la plus grande norme (par adresse)
  const Vecteur3D *normaxParAdresse(const Vecteur3D *v) const {
    return (this->norme() > v->norme()) ? this : v;
  }

  // Fonction pour obtenir le vecteur avec la plus grande norme (par référence)
  const Vecteur3D &normaxParReference(const Vecteur3D &v) const {
    return (this->norme() > v.norme()) ? *this : v;
  }
};

int main() {
  Vecteur3D v1(1.0, 2.0, 3.0);
  Vecteur3D v2(4.0, 5.0, 6.0);

  cout << "Vecteur v1 : ";
  v1.afficher();
  cout << "Vecteur v2 : ";
  v2.afficher();

  // Somme de v1 et v2
  Vecteur3D somme = v1.somme(v2);
  cout << "Somme de v1 et v2 : ";
  somme.afficher();

  // Produit scalaire de v1 et v2
  float produitScalaire = v1.produitScalaire(v2);
  cout << "Produit scalaire de v1 et v2 : " << produitScalaire << endl;

  // Vérifier si v1 et v2 coïncident
  if (v1.coincide(v2)) {
    cout << "v1 et v2 coïncident." << endl;
  } else {
    cout << "v1 et v2 ne coïncident pas." << endl;
  }

  // Norme de v1
  cout << "Norme de v1 : " << v1.norme() << endl;

  // Normax par valeur
  Vecteur3D maxParValeur = v1.normaxParValeur(v2);
  cout << "Vecteur avec la plus grande norme (par valeur) : ";
  maxParValeur.afficher();

  // Normax par adresse
  const Vecteur3D *maxParAdresse = v1.normaxParAdresse(&v2);
  cout << "Vecteur avec la plus grande norme (par adresse) : ";
  maxParAdresse->afficher();

  // Normax par référence
  const Vecteur3D &maxParReference = v1.normaxParReference(v2);
  cout << "Vecteur avec la plus grande norme (par référence) : ";
  maxParReference.afficher();

  return 0;
}
