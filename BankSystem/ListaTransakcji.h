#pragma once
#include "Transakcja.h"
#include <vector>
#include <string>

class ListaTransakcji {
private:
    std::vector<Transakcja> listaTransakcji;

public:
    // Dodawanie transakcji
    void dodajTransakcje(const Transakcja& transakcja);

    // Odczyt z pliku
    void odczytZPliku(const std::string& nazwaPliku);

    // Zapis do pliku
    void zapiszDoPliku(const std::string& nazwaPliku) const;

    // Wyœwietlanie transakcji
    void wypiszTransakcje() const;

    // Szukanie transakcji po numerze konta
    std::vector<Transakcja> szukajPoNumerzeKonta(const std::string& numerKonta) const;
};
