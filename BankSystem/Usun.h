#pragma once
#include "ListaKont.h"
#include "Konto.h"
#include <msclr/marshal_cppstd.h>

namespace BankSystem {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Usun : public System::Windows::Forms::Form {
    public:
        Usun(ListaKont* listaKont) {
            InitializeComponent();
            this->listaKont = listaKont; // Przypisz wskaŸnik do istniej¹cej listy
            WyswietlKonta();            // Wyœwietl konta w ListBox
        }

    protected:
        ~Usun() {
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
            this->label1->Size = System::Drawing::Size(218, 42);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Usuñ konto:";
            // 
            // buttonWroc
            // 
            this->buttonWroc->Location = System::Drawing::Point(12, 438);
            this->buttonWroc->Name = L"buttonWroc";
            this->buttonWroc->Size = System::Drawing::Size(90, 50);
            this->buttonWroc->TabIndex = 8;
            this->buttonWroc->Text = L"Wróæ";
            this->buttonWroc->UseVisualStyleBackColor = true;
            this->buttonWroc->Click += gcnew System::EventHandler(this, &Usun::buttonWroc_Click);
            // 
            // listBoxKonta
            // 
            this->listBoxKonta->FormattingEnabled = true;
            this->listBoxKonta->ItemHeight = 16;
            this->listBoxKonta->Location = System::Drawing::Point(50, 71);
            this->listBoxKonta->Name = L"listBoxKonta";
            this->listBoxKonta->Size = System::Drawing::Size(600, 292);
            this->listBoxKonta->TabIndex = 9;
            this->listBoxKonta->Click += gcnew System::EventHandler(this, &Usun::listBoxKonta_Click);
            // 
            // textBoxSzukaj
            // 
            this->textBoxSzukaj->Location = System::Drawing::Point(50, 410);
            this->textBoxSzukaj->Name = L"textBoxSzukaj";
            this->textBoxSzukaj->Size = System::Drawing::Size(400, 22);
            this->textBoxSzukaj->TabIndex = 10;
            // 
            // buttonSzukaj
            // 
            this->buttonSzukaj->Location = System::Drawing::Point(456, 406);
            this->buttonSzukaj->Name = L"buttonSzukaj";
            this->buttonSzukaj->Size = System::Drawing::Size(90, 30);
            this->buttonSzukaj->TabIndex = 11;
            this->buttonSzukaj->Text = L"Szukaj";
            this->buttonSzukaj->UseVisualStyleBackColor = true;
            this->buttonSzukaj->Click += gcnew System::EventHandler(this, &Usun::buttonSzukaj_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(47, 391);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(170, 13);
            this->label2->TabIndex = 13;
            this->label2->Text = L"Podaj numer konta do usuniêcia: ";
            // 
            // Usun
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->ClientSize = System::Drawing::Size(700, 500);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->buttonSzukaj);
            this->Controls->Add(this->textBoxSzukaj);
            this->Controls->Add(this->listBoxKonta);
            this->Controls->Add(this->buttonWroc);
            this->Controls->Add(this->label1);
            this->Name = L"Usun";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Usun";
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
                        System::Windows::Forms::DialogResult result = MessageBox::Show(
                            gcnew String(konto->getAccountDetails().c_str()) + "\n\nCzy chcesz usun¹æ to konto?",
                            "Potwierdzenie",
                            MessageBoxButtons::YesNo,
                            MessageBoxIcon::Question
                        );

                        if (result == System::Windows::Forms::DialogResult::Yes) {
                            listaKont->Usun(*konto); // Usuñ konto z listy
                            listaKont->ZapiszDoPliku("dane_klientow.txt"); // Zapisz zmiany do pliku
                            MessageBox::Show("Konto zosta³o pomyœlnie usuniête.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
                            WyswietlKonta(); // Odœwie¿ listê
                        }
                    }
                    else {
                        MessageBox::Show("Nie znaleziono konta.", "B³¹d");
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
                System::Windows::Forms::DialogResult result = MessageBox::Show(
                    gcnew String(konto->getAccountDetails().c_str()) + "\n\nCzy chcesz usun¹æ to konto?",
                    "Potwierdzenie",
                    MessageBoxButtons::YesNo,
                    MessageBoxIcon::Question
                );

                if (result == System::Windows::Forms::DialogResult::Yes) {
                    listaKont->Usun(*konto); // Usuñ konto z listy
                    listaKont->ZapiszDoPliku("dane_klientow.txt"); // Zapisz zmiany do pliku
                    MessageBox::Show("Konto zosta³o pomyœlnie usuniête.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    WyswietlKonta(); // Odœwie¿ listê
                }
            }
            else {
                MessageBox::Show("Nie znaleziono konta o podanym numerze.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void buttonWroc_Click(System::Object^ sender, System::EventArgs^ e) {
            listaKont->ZapiszDoPliku("dane_klientow.txt"); // Zapisz listê kont tylko raz przed zamkniêciem
            this->Close(); // Zamknij formularz
        }
    };
}
