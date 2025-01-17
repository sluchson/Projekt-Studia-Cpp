#include "MyForm.h"
#include "Register.h"
#include "Konto.h"
#include "ListaKont.h"

// Globalny wska�nik na list� kont
ListaKont* globalnaListaKont = nullptr;

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args) {
    // Inicjalizacja globalnej listy kont
    globalnaListaKont = new ListaKont();
    globalnaListaKont->Inicjalizuj("dane_klientow.txt");

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    BankSystem::MyForm form;
    Application::Run(% form);

    // Zapisanie ko�cowej wersji listy do pliku przed zamkni�ciem
    globalnaListaKont->ZapiszDoPliku("dane_klientow.txt");

    // Zwolnienie pami�ci
    delete globalnaListaKont;
}
