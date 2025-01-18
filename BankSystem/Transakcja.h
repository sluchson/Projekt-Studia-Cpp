#pragma once
#include <string>
#include <ctime>

class Transakcja {
private:
    std::string typ; // Wp³ata, Wyp³ata, Przelew
    std::string numerKontaNadawcy;
    std::string numerKontaOdbiorcy;
    double kwota;
    std::string data;

public:
    // Konstruktor domyœlny
    Transakcja();

    // Konstruktor z parametrami
    Transakcja(const std::string& typ, const std::string& numerKontaNadawcy,
        const std::string& numerKontaOdbiorcy, double kwota, const std::string& data);

    // Gettery
    std::string getTyp() const;
    std::string getNumerKontaNadawcy() const;
    std::string getNumerKontaOdbiorcy() const;
    double getKwota() const;
    std::string getData() const;

    // Settery
    void setTyp(const std::string& nowyTyp);
    void setNumerKontaNadawcy(const std::string& nowyNumer);
    void setNumerKontaOdbiorcy(const std::string& nowyNumer);
    void setKwota(double nowaKwota);
    void setData(const std::string& nowaData);

    // Metoda do pobrania aktualnej daty
    static std::string pobierzAktualnaDate();

    // Operatory do zapisu i odczytu
    friend std::ostream& operator<<(std::ostream& wy, const Transakcja& t);
    friend std::istream& operator>>(std::istream& we, Transakcja& t);
};
