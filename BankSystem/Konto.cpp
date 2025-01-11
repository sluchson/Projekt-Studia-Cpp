#pragma once

#include "Konto.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include <sstream>
#include <vector>



// Globalny kontener na obiekty Konto
std::vector<Konto*> listaKlientow;

Konto::Konto(
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
    double saldo)
    : imie(imie),
    drugieImie(drugieImie),
    nazwisko(nazwisko),
    numerKierunkowy(numerKierunkowy),
    numerTelefonu(numerTelefonu),
    email(email),
    pesel(pesel),
    seriaDowodu(seriaDowodu),
    numerDowodu(numerDowodu),
    numerKonta(numerKonta),
    haslo(haslo),
    saldo(saldo) {

}


std::string Konto::getImie() const { return imie; }
std::string Konto::getDrugieImie() const { return drugieImie; }
std::string Konto::getNazwisko() const { return nazwisko; }
std::string Konto::getNumerKierunkowy() const { return numerKierunkowy; }
std::string Konto::getNumerTelefonu() const { return numerTelefonu; }
std::string Konto::getEmail() const { return email; }
std::string Konto::getPesel() const { return pesel; }
std::string Konto::getSeriaDowodu() const { return seriaDowodu; }
std::string Konto::getNumerDowodu() const { return numerDowodu; }
std::string Konto::getNumerKonta() const { return numerKonta; }
std::string Konto::getHaslo() const { return haslo; }
double Konto::getSaldo() const { return saldo; }

void Konto::wplac(double kwota) {
    saldo += kwota;
}

bool Konto::wyplac(double kwota) {
    if (kwota > saldo) return false;
    saldo -= kwota;
    return true;
}


std::string Konto::ustalNumerKonta() {
    // U¿ycie generatora liczb losowych
    std::random_device rd;  // Ziarno generatora
    std::mt19937 gen(rd()); // Generator Mersenne Twister
    std::uniform_int_distribution<> dis(0, 9); // Rozk³ad równomierny dla cyfr (0-9)

    std::string nowyNumerKonta;

    // Generujemy 26-cyfrowy numer konta
    for (int i = 0; i < 26; ++i) {
        nowyNumerKonta += std::to_string(dis(gen));  // Dodajemy losow¹ cyfrê do numeru konta
    }

    return nowyNumerKonta; // Zwracamy wygenerowany numer konta
}

std::ostream& operator<<(std::ostream& wy, const Konto& p)
{
    wy << p.getNumerKonta() << "," << p.getHaslo() << "," << p.getSaldo() << "," << p.getImie() << "," << p.getDrugieImie() << "," << p.getNazwisko() << "," << p.getNumerKierunkowy() << "," << p.getNumerTelefonu() << "," << p.getEmail() << ","
        << p.getPesel() << "," << p.getSeriaDowodu() << "," << p.getNumerDowodu() << "\n";
    return wy;
}







