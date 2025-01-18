#include "ListaKont.h"
#include <iostream>
#include <fstream>

// Konstruktor domyœlny
ListaKont::ListaKont()
    : m_nLiczbaKont(0), m_pPoczatek(nullptr)
{
}

// Destruktor zwalniaj¹cy pamiêæ
ListaKont::~ListaKont()
{
    Konto* usun = m_pPoczatek; // Zaczyna od pierwszego elementu
    while (usun != nullptr)        // Dopóki lista nie jest pusta
    {
        Konto* next = usun->m_pNastepny; // Zapamiêtuje wskaŸnik na nastêpny element
        delete usun;                         // Usuwa bie¿¹cy element
        m_nLiczbaKont--;              // Zmniejsza licznik kont
        usun = next;                         // Przechodzi do kolejnego elementu
    }
}

// Dodaje konto do listy
void ListaKont::Dodaj(const Konto& p)
{
    bool wasFoundInList = false;
    Konto* test = m_pPoczatek;

    // Sprawdza, czy konto ju¿ istnieje w liœcie
    while (test != nullptr)
    {
        if (test->getNumerKonta() == p.getNumerKonta()) // Jeœli konto ju¿ istnieje, ustawia flagê
        {
            wasFoundInList = true;
            break;
        }
        test = test->m_pNastepny;
    }

    // Jeœli konta nie ma na liœcie, dodaje je
    if (!wasFoundInList)
    {
        Konto* noweKonto = new Konto(p); // Tworzy nowe konto
        noweKonto->m_pNastepny = nullptr;       // Ustawia `nullptr` jako nastêpny element
        noweKonto->m_pPoprzedni = nullptr;      // Ustawia `nullptr` jako poprzedni element
        if (m_nLiczbaKont == 0)     // Jeœli lista jest pusta
        {
            m_pPoczatek = noweKonto;  // Nowe konto staje siê pocz¹tkiem
        }
        else
        {
            Konto* last = m_pPoczatek;
            while (last->m_pNastepny != nullptr) // Znajduje ostatni element listy
            {
                last = last->m_pNastepny;
            }
            last->m_pNastepny = noweKonto;   // Dodaje nowe konto na koñcu
            noweKonto->m_pPoprzedni = last;  // £¹czy wstecz z poprzednim elementem
        }
        m_nLiczbaKont++;  // Zwiêksza liczbê kont
    }
}

// Usuwa konto z listy
void ListaKont::Usun(const Konto& wzorzec)
{
    Konto* test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez ca³¹ listê
    {
        if (test->getNumerKonta() == wzorzec.getNumerKonta()) // Szuka konta do usuniêcia
        {
            Konto* next = test->m_pNastepny;
            Konto* prev = test->m_pPoprzedni;
            if (test == m_pPoczatek)
                m_pPoczatek = next; // Jeœli to pierwszy element, przesuwa pocz¹tek
            if (prev)
                prev->m_pNastepny = next; // £¹czy poprzedni element z nastêpnym
            if (next)
                next->m_pPoprzedni = prev; // £¹czy nastêpny element z poprzednim
            m_nLiczbaKont--;       // Zmniejsza licznik kont
            delete test;           // Usuwa bie¿¹cy element
            break;
        }
        test = test->m_pNastepny; // Przechodzi do kolejnego elementu
    }
}





// Szuka konta na podstawie numeru konta
const Konto* ListaKont::Szukaj(const std::string& numerKonta) const
{
    Konto* test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez listê
    {
        if (test->getNumerKonta() == numerKonta) // Szuka konta po numerze
        {
            return test; // Zwraca znalezione konto
        }
        test = test->m_pNastepny; // Przechodzi do nastêpnego elementu
    }
    return nullptr; // Jeœli konta nie ma, zwraca `nullptr`
}

void ListaKont::ZapiszDoPliku(const char* nazwaPliku) const
{
    std::ofstream plik(nazwaPliku);
    if (plik.is_open())
    {
        Konto* p = m_pPoczatek;
        while (p != nullptr)
        {
            plik << *p << '\n';  // Zapisuje dane konta
            p = p->m_pNastepny; // Przechodzi do kolejnego konta
        }
        plik.close();
    }
    else
    {
        std::cerr << "Nie udalo sie otworzyc pliku " << nazwaPliku << std::endl;
    }
}

void ListaKont::OdczytZPliku(const char* nazwaPliku)
{
    std::ifstream plik(nazwaPliku);
    if (plik.is_open())
    {
        Konto k;
        while (plik >> k) // Wykorzystuje operator >> do odczytu danych
        {
            Dodaj(k); // Dodaje konto do listy
        }
        plik.close();
        std::cout << "Pomyslnie wczytano liste kont z pliku\n";
    }
    else
    {
        std::cerr << "Nie udalo sie otworzyc pliku " << nazwaPliku << std::endl;
    }
}


void ListaKont::Inicjalizuj(const char* nazwaPliku) {
    // Wyczyœæ istniej¹c¹ listê
    while (m_pPoczatek) {
        Konto* usun = m_pPoczatek;
        m_pPoczatek = m_pPoczatek->m_pNastepny;
        delete usun;
    }
    m_nLiczbaKont = 0;

    // Wczytaj dane z pliku
    OdczytZPliku(nazwaPliku);
}
