#include "MyForm.h"
#include "Register.h"
#include "Konto.h"
#include "ListaKont.h"

// Globalny wskaŸnik na listê kont
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

    // Zapisanie koñcowej wersji listy do pliku przed zamkniêciem
    globalnaListaKont->ZapiszDoPliku("dane_klientow.txt");

    // Zwolnienie pamiêci
    delete globalnaListaKont;
}
