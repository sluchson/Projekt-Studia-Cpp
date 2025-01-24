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
        System::Windows::Forms::TextBox^ textBoxSzukaj;
        System::Windows::Forms::Button^ buttonSzukaj;
    private: System::Windows::Forms::Label^ label2;
           System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->buttonWroc = (gcnew System::Windows::Forms::Button());
            this->listBoxKonta = (gcnew System::Windows::Forms::ListBox());
            this->textBoxSzukaj = (gcnew System::Windows::Forms::TextBox());
            this->buttonSzukaj = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F));
            this->label1->Location = System::Drawing::Point(223, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(188, 42);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Lista kont:";
            // 
            // buttonWroc
            // 
            this->buttonWroc->Location = System::Drawing::Point(12, 438);
            this->buttonWroc->Name = L"buttonWroc";
            this->buttonWroc->Size = System::Drawing::Size(90, 50);
            this->buttonWroc->TabIndex = 8;
            this->buttonWroc->Text = L"Wróæ";
            this->buttonWroc->UseVisualStyleBackColor = true;
            this->buttonWroc->Click += gcnew System::EventHandler(this, &Lista::buttonWroc_Click);
            // 
            // listBoxKonta
            // 
            this->listBoxKonta->ForeColor = System::Drawing::SystemColors::HotTrack;
            this->listBoxKonta->FormattingEnabled = true;
            this->listBoxKonta->ItemHeight = 16;
            this->listBoxKonta->Location = System::Drawing::Point(50, 65);
            this->listBoxKonta->Name = L"listBoxKonta";
            this->listBoxKonta->Size = System::Drawing::Size(600, 292);
            this->listBoxKonta->TabIndex = 9;
            this->listBoxKonta->Click += gcnew System::EventHandler(this, &Lista::listBoxKonta_Click);
            // 
            // textBoxSzukaj
            // 
            this->textBoxSzukaj->Location = System::Drawing::Point(50, 398);
            this->textBoxSzukaj->Name = L"textBoxSzukaj";
            this->textBoxSzukaj->Size = System::Drawing::Size(400, 22);
            this->textBoxSzukaj->TabIndex = 10;
            // 
            // buttonSzukaj
            // 
            this->buttonSzukaj->Location = System::Drawing::Point(469, 398);
            this->buttonSzukaj->Name = L"buttonSzukaj";
            this->buttonSzukaj->Size = System::Drawing::Size(90, 30);
            this->buttonSzukaj->TabIndex = 11;
            this->buttonSzukaj->Text = L"Szukaj";
            this->buttonSzukaj->UseVisualStyleBackColor = true;
            this->buttonSzukaj->Click += gcnew System::EventHandler(this, &Lista::buttonSzukaj_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(47, 379);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(216, 16);
            this->label2->TabIndex = 12;
            this->label2->Text = L"Podaj numer konta do wyszukania: ";
            // 
            // Lista
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->ClientSize = System::Drawing::Size(700, 500);
            this->ControlBox = false;
            this->Controls->Add(this->label2);
            this->Controls->Add(this->buttonSzukaj);
            this->Controls->Add(this->textBoxSzukaj);
            this->Controls->Add(this->listBoxKonta);
            this->Controls->Add(this->buttonWroc);
            this->Controls->Add(this->label1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
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
                        // Wywo³anie metody `getAccountDetails` i pokazanie MessageBox
                        std::string details = konto->getAccountDetails();
                        MessageBox::Show(gcnew String(details.c_str()), "Szczegó³y konta", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    }
                    else {
                        MessageBox::Show("Nie znaleziono konta.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                }
            }
        }


        void buttonSzukaj_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ szukanyNumer = textBoxSzukaj->Text;
            if (String::IsNullOrEmpty(szukanyNumer)) {
                MessageBox::Show("WprowadŸ numer konta do wyszukania.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            std::string numerKonta = msclr::interop::marshal_as<std::string>(szukanyNumer);
            const Konto* konto = listaKont->Szukaj(numerKonta);

            if (konto) {
                // Wywo³anie metody `getAccountDetails` i pokazanie MessageBox
                std::string details = konto->getAccountDetails();
                MessageBox::Show(gcnew String(details.c_str()), "Szczegó³y konta", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            else {
                MessageBox::Show("Nie znaleziono konta.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
                
        }
        

        void buttonWroc_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close(); // Zamknij formularz
        }
    };
}
