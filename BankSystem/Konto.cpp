#pragma once

#include "Konto.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include <sstream>
#include <vector>

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


void Konto::setImie(const std::string& noweImie) { imie = noweImie; }
void Konto::setDrugieImie(const std::string& noweDrugieImie) { drugieImie = noweDrugieImie; }
void Konto::setNazwisko(const std::string& noweNazwisko) { nazwisko = noweNazwisko; }
void Konto::setNumerKierunkowy(const std::string& nowyNumerKierunkowy) { numerKierunkowy = nowyNumerKierunkowy; }
void Konto::setNumerTelefonu(const std::string& nowyNumerTelefonu) { numerTelefonu = nowyNumerTelefonu; }
void Konto::setEmail(const std::string& nowyEmail) { email = nowyEmail; }
void Konto::setPesel(const std::string& nowyPesel) { pesel = nowyPesel; }
void Konto::setSeriaDowodu(const std::string& nowaSeriaDowodu) { seriaDowodu = nowaSeriaDowodu; }
void Konto::setNumerDowodu(const std::string& nowyNumerDowodu) { numerDowodu = nowyNumerDowodu; }
void Konto::setNumerKonta(const std::string& nowyNumerKonta) { numerKonta = nowyNumerKonta; }
void Konto::setHaslo(const std::string& noweHaslo) { haslo = noweHaslo; }
void Konto::setSaldo(double noweSaldo) { saldo = noweSaldo; }



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

std::istream& operator>>(std::istream& we, Konto& p)
{
    std::string linia;
    if (std::getline(we, linia)) { // Odczyt jednej linii z wejœcia
        std::stringstream ss(linia); // Przetwarzanie linii jako strumienia
        std::string numerKonta, haslo, saldoStr, imie, drugieImie, nazwisko, numerKierunkowy, numerTelefonu, email, pesel, seriaDowodu, numerDowodu;

        // Rozdzielanie linii na poszczególne czêœci (przy za³o¿eniu, ¿e s¹ oddzielone przecinkami)
        if (std::getline(ss, numerKonta, ',') &&
            std::getline(ss, haslo, ',') &&
            std::getline(ss, saldoStr, ',') &&
            std::getline(ss, imie, ',') &&
            std::getline(ss, drugieImie, ',') &&
            std::getline(ss, nazwisko, ',') &&
            std::getline(ss, numerKierunkowy, ',') &&
            std::getline(ss, numerTelefonu, ',') &&
            std::getline(ss, email, ',') &&
            std::getline(ss, pesel, ',') &&
            std::getline(ss, seriaDowodu, ',') &&
            std::getline(ss, numerDowodu, ','))
        {
            // Konwersja string -> double dla salda
            double saldo = std::stod(saldoStr);

            // Ustawianie pól za pomoc¹ setterów
            p.setNumerKonta(numerKonta);
            p.setHaslo(haslo);
            p.setSaldo(saldo);
            p.setImie(imie);
            p.setDrugieImie(drugieImie);
            p.setNazwisko(nazwisko);
            p.setNumerKierunkowy(numerKierunkowy);
            p.setNumerTelefonu(numerTelefonu);
            p.setEmail(email);
            p.setPesel(pesel);
            p.setSeriaDowodu(seriaDowodu);
            p.setNumerDowodu(numerDowodu);
        }
    }

    return we;
}


std::string Konto::getAccountDetails() const {
    return "Numer konta: " + getNumerKonta() + "\n" +
        "Imiê: " + getImie() + "\n" +
        "Drugie imiê: " + getDrugieImie() + "\n" +
        "Nazwisko: " + getNazwisko() + "\n" +
        "Numer telefonu: " + getNumerKierunkowy() + " " + getNumerTelefonu() + "\n" +
        "Adres e-mail: " + getEmail() + "\n" +
        "PESEL: " + getPesel() + "\n" +
        "Seria dowodu: " + getSeriaDowodu() + "\n" +
        "Numer dowodu: " + getNumerDowodu() + "\n" +
        "Saldo: " + std::to_string(getSaldo());
}







