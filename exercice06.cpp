// main.cpp
#include "point.h"
#include <iostream>
using namespace std;

int main() {
  // Déclaration d'un point avec des coordonnées initiales
  Point p(2.5, 3.5);

  // Affichage des coordonnées du point
  cout << "Point initial : ";
  p.affiche();

  // Déplacement du point
  p.deplace(1.0, -2.0);

  // Affichage des nouvelles coordonnées après déplacement
  cout << "Point après déplacement : ";
  p.affiche();

  return 0;
}
