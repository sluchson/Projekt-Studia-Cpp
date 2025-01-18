#pragma once
#include "Konto.h"
#include <iostream>
#include <fstream>
#include <string>



class ListaKont {
private:
    Konto* m_pPoczatek; // WskaŸnik na pierwszy element w liœcie
    int m_nLiczbaKont;  // Liczba kont w liœcie

public:
    // Konstruktor
    ListaKont();

    // Destruktor
    ~ListaKont();

    // Metody zarz¹dzania list¹
    void Dodaj(const Konto& konto);             // Dodaje konto do listy
    void Usun(const Konto& wzorzec);            // Usuwa konto z listy              
    const Konto* Szukaj(const std::string& numerKonta) const; // Wyszukuje konto

    // Metody plikowe
    void ZapiszDoPliku(const char* nazwaPliku) const; // Zapisuje listê kont do pliku
    void OdczytZPliku(const char* nazwaPliku);        // Odczytuje listê kont z pliku

    // Getter dla pierwszego elementu
    Konto* getPoczatek() const { return m_pPoczatek; }

    void Inicjalizuj(const char* nazwaPliku);
};
