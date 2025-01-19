#pragma once
#include "Konto.h"
#include <iostream>
#include <fstream>
#include <string>



class ListaKont {
private:
    Konto* m_pPoczatek; // Wskaznik na pierwszy element w liscie
    int m_nLiczbaKont;  // Liczba kont w liscie

public:
    // Konstruktor
    ListaKont();

    // Destruktor
    ~ListaKont();

    // Metody zarzadzania lista
    void Dodaj(const Konto& konto);             // Dodaje konto do listy
    void Usun(const Konto& wzorzec);            // Usuwa konto z listy              
    Konto* Szukaj(const std::string& numerKonta) const; // Wyszukuje konto

    // Metody plikowe
    void ZapiszDoPliku(const char* nazwaPliku) const; // Zapisuje liste kont do pliku
    void OdczytZPliku(const char* nazwaPliku);        // Odczytuje liste kont z pliku

    // Getter dla pierwszego elementu
    Konto* getPoczatek() const { return m_pPoczatek; }

    void Inicjalizuj(const char* nazwaPliku);
};