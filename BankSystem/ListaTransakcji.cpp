#include "ListaTransakcji.h"
#include <iostream>
#include <fstream>

void ListaTransakcji::dodajTransakcje(const Transakcja& transakcja) {
    listaTransakcji.push_back(transakcja);
}

void ListaTransakcji::odczytZPliku(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (plik.is_open()) {
        Transakcja t;
        while (plik >> t) {
            listaTransakcji.push_back(t);
        }
        plik.close();
    }
    else {
        std::cerr << "Nie uda³o siê otworzyæ pliku " << nazwaPliku << std::endl;
    }
}

void ListaTransakcji::zapiszDoPliku(const std::string& nazwaPliku) const {
    std::ofstream plik(nazwaPliku);
    if (plik.is_open()) {
        for (const auto& t : listaTransakcji) {
            plik << t << '\n';
        }
        plik.close();
    }
    else {
        std::cerr << "Nie uda³o siê otworzyæ pliku " << nazwaPliku << std::endl;
    }
}

void ListaTransakcji::wypiszTransakcje() const {
    for (const auto& t : listaTransakcji) {
        std::cout << t << std::endl;
    }
}

std::vector<Transakcja> ListaTransakcji::szukajPoNumerzeKonta(const std::string& numerKonta) const {
    std::vector<Transakcja> wynik;
    for (const auto& t : listaTransakcji) {
        if (t.getNumerKontaNadawcy() == numerKonta || t.getNumerKontaOdbiorcy() == numerKonta) {
            wynik.push_back(t);
        }
    }
    return wynik;
}
