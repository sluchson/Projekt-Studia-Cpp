#include "ListaKont.h"
#include <iostream>
#include <fstream>

// Konstruktor domy�lny
ListaKont::ListaKont()
    : m_nLiczbaKont(0), m_pPoczatek(nullptr)
{
}

// Destruktor zwalniaj�cy pami��
ListaKont::~ListaKont()
{
    Konto* usun = m_pPoczatek; // Zaczyna od pierwszego elementu
    while (usun != nullptr)        // Dop�ki lista nie jest pusta
    {
        Konto* next = usun->m_pNastepny; // Zapami�tuje wska�nik na nast�pny element
        delete usun;                         // Usuwa bie��cy element
        m_nLiczbaKont--;              // Zmniejsza licznik kont
        usun = next;                         // Przechodzi do kolejnego elementu
    }
}

// Dodaje konto do listy
void ListaKont::Dodaj(const Konto& p)
{
    bool wasFoundInList = false;
    Konto* test = m_pPoczatek;

    // Sprawdza, czy konto ju� istnieje w li�cie
    while (test != nullptr)
    {
        if (test->getNumerKonta() == p.getNumerKonta()) // Je�li konto ju� istnieje, ustawia flag�
        {
            wasFoundInList = true;
            break;
        }
        test = test->m_pNastepny;
    }

    // Je�li konta nie ma na li�cie, dodaje je
    if (!wasFoundInList)
    {
        Konto* noweKonto = new Konto(p); // Tworzy nowe konto
        noweKonto->m_pNastepny = nullptr;       // Ustawia `nullptr` jako nast�pny element
        noweKonto->m_pPoprzedni = nullptr;      // Ustawia `nullptr` jako poprzedni element
        if (m_nLiczbaKont == 0)     // Je�li lista jest pusta
        {
            m_pPoczatek = noweKonto;  // Nowe konto staje si� pocz�tkiem
        }
        else
        {
            Konto* last = m_pPoczatek;
            while (last->m_pNastepny != nullptr) // Znajduje ostatni element listy
            {
                last = last->m_pNastepny;
            }
            last->m_pNastepny = noweKonto;   // Dodaje nowe konto na ko�cu
            noweKonto->m_pPoprzedni = last;  // ��czy wstecz z poprzednim elementem
        }
        m_nLiczbaKont++;  // Zwi�ksza liczb� kont
    }
}

// Usuwa konto z listy
void ListaKont::Usun(const Konto& wzorzec)
{
    Konto* test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez ca�� list�
    {
        if (test->getNumerKonta() == wzorzec.getNumerKonta()) // Szuka konta do usuni�cia
        {
            Konto* next = test->m_pNastepny;
            Konto* prev = test->m_pPoprzedni;
            if (test == m_pPoczatek)
                m_pPoczatek = next; // Je�li to pierwszy element, przesuwa pocz�tek
            if (prev)
                prev->m_pNastepny = next; // ��czy poprzedni element z nast�pnym
            if (next)
                next->m_pPoprzedni = prev; // ��czy nast�pny element z poprzednim
            m_nLiczbaKont--;       // Zmniejsza licznik kont
            delete test;           // Usuwa bie��cy element
            break;
        }
        test = test->m_pNastepny; // Przechodzi do kolejnego elementu
    }
}





// Szuka konta na podstawie numeru konta
const Konto* ListaKont::Szukaj(const std::string& numerKonta) const
{
    Konto* test = m_pPoczatek;
    while (test != nullptr) // Przechodzi przez list�
    {
        if (test->getNumerKonta() == numerKonta) // Szuka konta po numerze
        {
            return test; // Zwraca znalezione konto
        }
        test = test->m_pNastepny; // Przechodzi do nast�pnego elementu
    }
    return nullptr; // Je�li konta nie ma, zwraca `nullptr`
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
    // Wyczy�� istniej�c� list�
    while (m_pPoczatek) {
        Konto* usun = m_pPoczatek;
        m_pPoczatek = m_pPoczatek->m_pNastepny;
        delete usun;
    }
    m_nLiczbaKont = 0;

    // Wczytaj dane z pliku
    OdczytZPliku(nazwaPliku);
}
