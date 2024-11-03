#pragma once

class Point {
private:
  float x, y; // Coordonnées du point (privées)

public:
  // Constructeur avec paramètres pour initialiser les coordonnées
  Point(float x = 0.0, float y = 0.0);

  // Fonction pour déplacer le point
  void deplace(float dx, float dy);

  // Fonction pour afficher les coordonnées du point
  void affiche() const;
};
