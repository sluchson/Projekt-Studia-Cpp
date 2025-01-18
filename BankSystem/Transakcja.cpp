#include "Transakcja.h"
#include <iomanip>
#include <sstream>

Transakcja::Transakcja() : typ(""), numerKontaNadawcy(""), numerKontaOdbiorcy(""), kwota(0.0), data("") {}

Transakcja::Transakcja(const std::string& typ, const std::string& numerKontaNadawcy,
    const std::string& numerKontaOdbiorcy, double kwota, const std::string& data)
    : typ(typ), numerKontaNadawcy(numerKontaNadawcy), numerKontaOdbiorcy(numerKontaOdbiorcy), kwota(kwota), data(data) {}

std::string Transakcja::getTyp() const { return typ; }
std::string Transakcja::getNumerKontaNadawcy() const { return numerKontaNadawcy; }
std::string Transakcja::getNumerKontaOdbiorcy() const { return numerKontaOdbiorcy; }
double Transakcja::getKwota() const { return kwota; }
std::string Transakcja::getData() const { return data; }

void Transakcja::setTyp(const std::string& nowyTyp) { typ = nowyTyp; }
void Transakcja::setNumerKontaNadawcy(const std::string& nowyNumer) { numerKontaNadawcy = nowyNumer; }
void Transakcja::setNumerKontaOdbiorcy(const std::string& nowyNumer) { numerKontaOdbiorcy = nowyNumer; }
void Transakcja::setKwota(double nowaKwota) { kwota = nowaKwota; }
void Transakcja::setData(const std::string& nowaData) { data = nowaData; }

std::string Transakcja::pobierzAktualnaDate() {
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

std::ostream& operator<<(std::ostream& wy, const Transakcja& t) {
    wy << t.typ << "," << t.numerKontaNadawcy << "," << t.numerKontaOdbiorcy << "," << t.kwota << "," << t.data;
    return wy;
}

std::istream& operator>>(std::istream& we, Transakcja& t) {
    std::getline(we, t.typ, ',');
    std::getline(we, t.numerKontaNadawcy, ',');
    std::getline(we, t.numerKontaOdbiorcy, ',');
    we >> t.kwota;
    we.ignore(1, ',');
    std::getline(we, t.data);
    return we;
}
