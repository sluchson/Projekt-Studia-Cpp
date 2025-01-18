
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

    Konto() : saldo(0.0) {} // Domyœlny konstruktor inicjuje saldo na 0


    Konto* m_pNastepny;
    Konto* m_pPoprzedni;

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
    Konto* getNastepny() const { return m_pNastepny; }
    Konto* getPoprzedni() const { return m_pPoprzedni; }

    // Settery
    void setImie(const std::string& noweImie);
    void setDrugieImie(const std::string& noweDrugieImie);
    void setNazwisko(const std::string& noweNazwisko);
    void setNumerKierunkowy(const std::string& nowyNumerKierunkowy);
    void setNumerTelefonu(const std::string& nowyNumerTelefonu);
    void setEmail(const std::string& nowyEmail);
    void setPesel(const std::string& nowyPesel);
    void setSeriaDowodu(const std::string& nowaSeriaDowodu);
    void setNumerDowodu(const std::string& nowyNumerDowodu);
    void setNumerKonta(const std::string& nowyNumerKonta);
    void setHaslo(const std::string& noweHaslo);
    void setSaldo(double noweSaldo);



    // Metody
    static std::string ustalNumerKonta();
    std::string getAccountDetails() const;


    friend std::ostream& operator<<(std::ostream& wy, const Konto& p);
    friend std::istream& operator>>(std::istream& we, Konto& p);
};
std::ostream& operator<<(std::ostream& wy, const Konto& p);
std::istream& operator>>(std::istream& we, Konto& p);