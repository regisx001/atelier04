#include <iostream>
#include <string>
using namespace std;

class Personne {
protected:
  string nom;
  string prenom;
  string date_naissance;

public:
  Personne(const string &nom, const string &prenom,
           const string &date_naissance)
      : nom(nom), prenom(prenom), date_naissance(date_naissance) {}

  virtual void Afficher() const {
    cout << "Nom: " << nom << ", Prénom: " << prenom
         << ", Date de naissance: " << date_naissance << endl;
  }
};

class Employe : public Personne {
protected:
  double salaire;

public:
  Employe(const string &nom, const string &prenom, const string &date_naissance,
          double salaire)
      : Personne(nom, prenom, date_naissance), salaire(salaire) {}

  void Afficher() const override {
    Personne::Afficher();
    cout << "Salaire: " << salaire << " EUR" << endl;
  }
};

class Chef : public Employe {
protected:
  string service;

public:
  Chef(const string &nom, const string &prenom, const string &date_naissance,
       double salaire, const string &service)
      : Employe(nom, prenom, date_naissance, salaire), service(service) {}

  void Afficher() const override {
    Employe::Afficher();
    cout << "Service: " << service << endl;
  }
};
class Directeur : public Chef {
private:
  string societe;

public:
  Directeur(const string &nom, const string &prenom,
            const string &date_naissance, double salaire, const string &service,
            const string &societe)
      : Chef(nom, prenom, date_naissance, salaire, service), societe(societe) {}

  void Afficher() const override {
    Chef::Afficher();
    cout << "Société: " << societe << endl;
  }
};

int main() { return 0; }
