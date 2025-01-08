
#pragma once
#include <string>

class Konto {
private:
    std::string imie;
    std::string drugieImie;
    std::string nazwisko;
    std::string numerKierunkowy;
    std::string numerTelefonu;
    std::string email;
    std::string pesel;
    std::string seriaDowodu;
    std::string numerDowodu;
    std::string numerKonta;
    std::string haslo;
    double saldo;



public:
    // Konstruktor
    Konto(
        const std::string& imie,
        const std::string& drugieImie,
        const std::string& nazwisko,
        const std::string& numerKierunkowy,
        const std::string& numerTelefonu,
        const std::string& email,
        const std::string& pesel,
        const std::string& seriaDowodu,
        const std::string& numerDowodu,
        const std::string& numerKonta,
        const std::string& haslo,
        double saldo = 0.0);

    // Gettery
    std::string getImie() const;
    std::string getDrugieImie() const;
    std::string getNazwisko() const;
    std::string getNumerKierunkowy() const;
    std::string getNumerTelefonu() const;
    std::string getEmail() const;
    std::string getPesel() const;
    std::string getSeriaDowodu() const;
    std::string getNumerDowodu() const;
    std::string getNumerKonta() const;
    std::string getHaslo() const;
    double getSaldo() const;

    // Metody
    void wplac(double kwota);
    bool wyplac(double kwota);
    static std::string ustalNumerKonta();

};


