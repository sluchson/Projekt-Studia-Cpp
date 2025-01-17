#pragma once
#include "ListaKont.h"
#include "Konto.h"
#include <msclr/marshal_cppstd.h>

namespace BankSystem {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Lista : public System::Windows::Forms::Form {
    public:
        Lista(ListaKont* listaKont) {
            InitializeComponent();
            this->listaKont = listaKont; // Przypisz wskaŸnik do istniej¹cej listy
            WyswietlKonta();            // Wyœwietl konta w ListBox
        }

    protected:
        ~Lista() {
            if (components) {
                delete components;
            }
        }

    private:
        ListaKont* listaKont; // WskaŸnik do istniej¹cej listy kont
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Button^ buttonWroc;
        System::Windows::Forms::ListBox^ listBoxKonta;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->buttonWroc = (gcnew System::Windows::Forms::Button());
            this->listBoxKonta = (gcnew System::Windows::Forms::ListBox());
            this->SuspendLayout();

            // Label
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F));
            this->label1->Location = System::Drawing::Point(223, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(229, 52);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Lista kont:";

            // Button Wroc
            this->buttonWroc->Location = System::Drawing::Point(12, 438);
            this->buttonWroc->Name = L"buttonWroc";
            this->buttonWroc->Size = System::Drawing::Size(90, 50);
            this->buttonWroc->TabIndex = 8;
            this->buttonWroc->Text = L"Wróæ";
            this->buttonWroc->UseVisualStyleBackColor = true;
            this->buttonWroc->Click += gcnew System::EventHandler(this, &Lista::buttonWroc_Click);

            // ListBox Konta
            this->listBoxKonta->FormattingEnabled = true;
            this->listBoxKonta->ItemHeight = 20;
            this->listBoxKonta->Location = System::Drawing::Point(50, 100);
            this->listBoxKonta->Name = L"listBoxKonta";
            this->listBoxKonta->Size = System::Drawing::Size(600, 300);
            this->listBoxKonta->TabIndex = 9;
            this->listBoxKonta->Click += gcnew System::EventHandler(this, &Lista::listBoxKonta_Click);

            // Lista Form
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->ClientSize = System::Drawing::Size(700, 500);
            this->Controls->Add(this->listBoxKonta);
            this->Controls->Add(this->buttonWroc);
            this->Controls->Add(this->label1);
            this->Name = L"Lista";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Lista";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void WyswietlKonta() {
            listBoxKonta->Items->Clear(); // Wyczyœæ listê przed ponownym za³adowaniem
            Konto* aktualneKonto = listaKont->getPoczatek(); // Pobierz pierwszy element listy
            while (aktualneKonto != nullptr) {
                String^ item = gcnew String(
                    (aktualneKonto->getNumerKonta() + " - " +
                        aktualneKonto->getImie() + " " +
                        aktualneKonto->getNazwisko()).c_str());
                listBoxKonta->Items->Add(item);
                aktualneKonto = aktualneKonto->m_pNastepny; // PrzejdŸ do nastêpnego konta
            }
        }

        void listBoxKonta_Click(System::Object^ sender, System::EventArgs^ e) {
            if (listBoxKonta->SelectedItem != nullptr) {
                String^ selectedItem = listBoxKonta->SelectedItem->ToString();
                array<String^>^ parts = selectedItem->Split(' ');
                if (parts->Length > 0) {
                    String^ accountString = parts[0]; // Wyodrêbnij numer konta jako String^
                    std::string numerKonta = msclr::interop::marshal_as<std::string>(accountString); // Konwersja na std::string

                    // ZnajdŸ konto
                    const Konto* konto = listaKont->Szukaj(numerKonta);

                    if (konto) {
                        MessageBox::Show(
                            "Numer konta: " + gcnew String(konto->getNumerKonta().c_str()) + "\n" +
                            "Imiê: " + gcnew String(konto->getImie().c_str()) + "\n" +
                            "Nazwisko: " + gcnew String(konto->getNazwisko().c_str()) + "\n" +
                            "PESEL: " + gcnew String(konto->getPesel().c_str()) + "\n" +
                            "Saldo: " + konto->getSaldo().ToString(),
                            "Szczegó³y konta"
                        );
                    }
                    else {
                        MessageBox::Show("Nie znaleziono konta.", "B³¹d");
                    }
                }
            }
        }


        void buttonWroc_Click(System::Object^ sender, System::EventArgs^ e) {
            listaKont->ZapiszDoPliku("dane_klientow.txt"); // Zapisz listê kont tylko raz przed zamkniêciem
            this->Close(); // Zamknij formularz
        }
    };
}
