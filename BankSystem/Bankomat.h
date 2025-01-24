#pragma once
#include "Konto.h"
#include "ListaKont.h"
#include <msclr/marshal_cppstd.h>

#include <chrono>
#include <iomanip>
#include <fstream>

namespace BankSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Bankomat : public System::Windows::Forms::Form {
    public:
        Bankomat(Konto* klient, ListaKont* listaKont) {
            InitializeComponent();
            this->klient = klient;
            this->listaKont = listaKont;

            // Ustawienie salda na etykiecie
            labelSaldo->Text = System::String::Format(L"{0:F2}", klient->getSaldo());
        }

    protected:
        ~Bankomat() {
            if (components) {
                delete components;
            }
        }

    private:
        TextBox^ activeTextBox;
        ListaKont* listaKont;
        Konto* klient;

    private: System::Windows::Forms::Label^ labelKwotaWplata;
    private: System::Windows::Forms::Label^ labelKwotaWyplata;
    private: System::Windows::Forms::Label^ labelSaldo;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ textBoxKwotaWplata;
    private: System::Windows::Forms::Button^ buttonWplac;
    private: System::Windows::Forms::TextBox^ textBoxKwotaWyplata;
    private: System::Windows::Forms::Button^ buttonWyplac;
    private: System::Windows::Forms::Button^ buttonWroc;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Button^ buttonBackround;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::Button^ button7;
    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::Button^ button9;
    private: System::Windows::Forms::Button^ buttonDel;
    private: System::Windows::Forms::Button^ button0;
    private: System::Windows::Forms::Button^ buttonComma;




    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {


            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Bankomat::typeid));
            this->buttonBackround = (gcnew System::Windows::Forms::Button());
            this->labelKwotaWplata = (gcnew System::Windows::Forms::Label());
            this->labelKwotaWyplata = (gcnew System::Windows::Forms::Label());
            this->labelSaldo = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->textBoxKwotaWplata = (gcnew System::Windows::Forms::TextBox());
            this->buttonWplac = (gcnew System::Windows::Forms::Button());
            this->textBoxKwotaWyplata = (gcnew System::Windows::Forms::TextBox());
            this->buttonWyplac = (gcnew System::Windows::Forms::Button());
            this->buttonWroc = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->button9 = (gcnew System::Windows::Forms::Button());
            this->buttonDel = (gcnew System::Windows::Forms::Button());
            this->button0 = (gcnew System::Windows::Forms::Button());
            this->buttonComma = (gcnew System::Windows::Forms::Button());
            this->button1->Click += gcnew System::EventHandler(this, &Bankomat::DigitButton_Click);
            this->button2->Click += gcnew System::EventHandler(this, &Bankomat::DigitButton_Click);
            this->button3->Click += gcnew System::EventHandler(this, &Bankomat::DigitButton_Click);
            this->button4->Click += gcnew System::EventHandler(this, &Bankomat::DigitButton_Click);
            this->button5->Click += gcnew System::EventHandler(this, &Bankomat::DigitButton_Click);
            this->button6->Click += gcnew System::EventHandler(this, &Bankomat::DigitButton_Click);
            this->button7->Click += gcnew System::EventHandler(this, &Bankomat::DigitButton_Click);
            this->button8->Click += gcnew System::EventHandler(this, &Bankomat::DigitButton_Click);
            this->button9->Click += gcnew System::EventHandler(this, &Bankomat::DigitButton_Click);
            this->button0->Click += gcnew System::EventHandler(this, &Bankomat::DigitButton_Click);
            this->buttonComma->Click += gcnew System::EventHandler(this, &Bankomat::DigitButton_Click);
            this->buttonDel->Click += gcnew System::EventHandler(this, &Bankomat::BackspaceButton_Click);
            textBoxKwotaWplata->Enter += gcnew System::EventHandler(this, &Bankomat::TextBox_Enter);
            textBoxKwotaWyplata->Enter += gcnew System::EventHandler(this, &Bankomat::TextBox_Enter);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // labelSaldo
            // 
            this->labelSaldo->AutoSize = true;
            this->labelSaldo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->labelSaldo->Location = System::Drawing::Point(236, 83);
            this->labelSaldo->Name = L"labelSaldo";
            this->labelSaldo->Size = System::Drawing::Size(63, 25);
            this->labelSaldo->TabIndex = 0;
            this->labelSaldo->Text = L"Saldo";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label2->Location = System::Drawing::Point(102, 83);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(128, 25);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Twoje œrodki:";
            // 
            // textBoxKwotaWplata
            // 
            this->textBoxKwotaWplata->Location = System::Drawing::Point(107, 127);
            this->textBoxKwotaWplata->Name = L"textBoxKwotaWplata";
            this->textBoxKwotaWplata->Size = System::Drawing::Size(200, 22);
            this->textBoxKwotaWplata->TabIndex = 2;
            this->textBoxKwotaWplata->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Bankomat::KwotaTextBox_KeyPress);
            // 
            // buttonWplac
            // 
            this->buttonWplac->Location = System::Drawing::Point(108, 278);
            this->buttonWplac->Name = L"buttonWplac";
            this->buttonWplac->Size = System::Drawing::Size(147, 72);
            this->buttonWplac->TabIndex = 3;
            this->buttonWplac->Text = L"Wp³aæ";
            this->buttonWplac->Click += gcnew System::EventHandler(this, &Bankomat::buttonWplac_Click);
            // 
            // textBoxKwotaWyplata
            // 
            this->textBoxKwotaWyplata->Location = System::Drawing::Point(356, 127);
            this->textBoxKwotaWyplata->Name = L"textBoxKwotaWyplata";
            this->textBoxKwotaWyplata->Size = System::Drawing::Size(200, 22);
            this->textBoxKwotaWyplata->TabIndex = 4;
            this->textBoxKwotaWyplata->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Bankomat::KwotaTextBox_KeyPress);
            // 
            // buttonWyplac
            // 
            this->buttonWyplac->Location = System::Drawing::Point(108, 384);
            this->buttonWyplac->Name = L"buttonWyplac";
            this->buttonWyplac->Size = System::Drawing::Size(147, 72);
            this->buttonWyplac->TabIndex = 5;
            this->buttonWyplac->Text = L"Wyp³aæ";
            this->buttonWyplac->Click += gcnew System::EventHandler(this, &Bankomat::buttonWyplac_Click);
            // 
            // buttonWroc
            // 
            this->buttonWroc->Location = System::Drawing::Point(12, 438);
            this->buttonWroc->Name = L"buttonWroc";
            this->buttonWroc->Size = System::Drawing::Size(90, 50);
            this->buttonWroc->TabIndex = 8;
            this->buttonWroc->Text = L"Wróæ";
            this->buttonWroc->UseVisualStyleBackColor = true;
            this->buttonWroc->Click += gcnew System::EventHandler(this, &Bankomat::buttonWroc_Click_1);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(-321, -287);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(1346, 972);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 9;
            this->pictureBox1->TabStop = false;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label1->Location = System::Drawing::Point(313, 130);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(33, 16);
            this->label1->TabIndex = 10;
            this->label1->Text = L"PLN";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label3->Location = System::Drawing::Point(562, 130);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(33, 16);
            this->label3->TabIndex = 11;
            this->label3->Text = L"PLN";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(391, 277);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(50, 50);
            this->button1->TabIndex = 12;
            this->button1->Text = L"1";
            this->button1->UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(484, 278);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(50, 50);
            this->button2->TabIndex = 13;
            this->button2->Text = L"2";
            this->button2->UseVisualStyleBackColor = true;
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(585, 277);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(50, 50);
            this->button3->TabIndex = 14;
            this->button3->Text = L"3";
            this->button3->UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            this->button4->Location = System::Drawing::Point(391, 333);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(50, 50);
            this->button4->TabIndex = 15;
            this->button4->Text = L"4";
            this->button4->UseVisualStyleBackColor = true;
            // 
            // button5
            // 
            this->button5->Location = System::Drawing::Point(484, 334);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(50, 50);
            this->button5->TabIndex = 16;
            this->button5->Text = L"5";
            this->button5->UseVisualStyleBackColor = true;
            // 
            // button6
            // 
            this->button6->Location = System::Drawing::Point(585, 333);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(50, 50);
            this->button6->TabIndex = 17;
            this->button6->Text = L"6";
            this->button6->UseVisualStyleBackColor = true;
            // 
            // button7
            // 
            this->button7->Location = System::Drawing::Point(391, 389);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(50, 50);
            this->button7->TabIndex = 18;
            this->button7->Text = L"7";
            this->button7->UseVisualStyleBackColor = true;
            // 
            // button8
            // 
            this->button8->Location = System::Drawing::Point(484, 389);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(50, 50);
            this->button8->TabIndex = 19;
            this->button8->Text = L"8";
            this->button8->UseVisualStyleBackColor = true;
            // 
            // button9
            // 
            this->button9->Location = System::Drawing::Point(585, 389);
            this->button9->Name = L"button9";
            this->button9->Size = System::Drawing::Size(50, 50);
            this->button9->TabIndex = 20;
            this->button9->Text = L"9";
            this->button9->UseVisualStyleBackColor = true;
            // 
            // buttonDel
            // 
            this->buttonDel->Location = System::Drawing::Point(585, 445);
            this->buttonDel->Name = L"buttonDel";
            this->buttonDel->Size = System::Drawing::Size(50, 50);
            this->buttonDel->TabIndex = 21;
            this->buttonDel->Text = L"<-";
            this->buttonDel->UseVisualStyleBackColor = true;
            // 
            // button0
            // 
            this->button0->Location = System::Drawing::Point(484, 445);
            this->button0->Name = L"button0";
            this->button0->Size = System::Drawing::Size(50, 50);
            this->button0->TabIndex = 22;
            this->button0->Text = L"0";
            this->button0->UseVisualStyleBackColor = true;
            // 
            // buttonComma
            // 
            this->buttonComma->Location = System::Drawing::Point(391, 445);
            this->buttonComma->Name = L"buttonComma";
            this->buttonComma->Size = System::Drawing::Size(50, 50);
            this->buttonComma->TabIndex = 23;
            this->buttonComma->Text = L",";
            this->buttonComma->UseVisualStyleBackColor = true;
            // 
            // buttonBackround
            //
            this->buttonBackround->Location = System::Drawing::Point(380, 270);
            this->buttonBackround->Name = L"buttonBackround";
            this->buttonBackround->Size = System::Drawing::Size(270, 250);
            this->buttonBackround->TabIndex = 24;
            this->buttonBackround->Text = L"";
            this->buttonBackround->UseVisualStyleBackColor = false;
            this->buttonBackround->BackColor = System::Drawing::Color::LightGray;
            this->buttonBackround->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonBackround->Enabled = false; // Ustawienie na nieinteraktywne
            // Dodanie labelKwotaWplata
            this->labelKwotaWplata = (gcnew System::Windows::Forms::Label());
            this->labelKwotaWplata->AutoSize = true;
            this->labelKwotaWplata->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->labelKwotaWplata->Location = System::Drawing::Point(107, 105);
            this->labelKwotaWplata->Name = L"labelKwotaWplata";
            this->labelKwotaWplata->Size = System::Drawing::Size(103, 20);
            this->labelKwotaWplata->TabIndex = 25;
            this->labelKwotaWplata->Text = L"Kwota wp³aty:";
            this->Controls->Add(this->labelKwotaWplata);

            // Dodanie labelKwotaWyplata
            this->labelKwotaWyplata = (gcnew System::Windows::Forms::Label());
            this->labelKwotaWyplata->AutoSize = true;
            this->labelKwotaWyplata->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->labelKwotaWyplata->Location = System::Drawing::Point(356, 105);
            this->labelKwotaWyplata->Name = L"labelKwotaWyplata";
            this->labelKwotaWyplata->Size = System::Drawing::Size(111, 20);
            this->labelKwotaWyplata->TabIndex = 26;
            this->labelKwotaWyplata->Text = L"Kwota wyp³aty:";
            this->Controls->Add(this->labelKwotaWyplata);
            // 
            // Bankomat
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->ClientSize = System::Drawing::Size(700, 500);
            this->Controls->Add(this->buttonBackround);
            this->Controls->Add(this->buttonComma);
            this->Controls->Add(this->button0);
            this->Controls->Add(this->buttonDel);
            this->Controls->Add(this->button9);
            this->Controls->Add(this->button8);
            this->Controls->Add(this->button7);
            this->Controls->Add(this->button6);
            this->Controls->Add(this->button5);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->buttonWroc);
            this->Controls->Add(this->labelSaldo);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->textBoxKwotaWplata);
            this->Controls->Add(this->buttonWplac);
            this->Controls->Add(this->textBoxKwotaWyplata);
            this->Controls->Add(this->buttonWyplac);
            this->Controls->Add(this->pictureBox1);
            // Ustaw przyciski na wierzch
            this->buttonComma->BringToFront();
            this->button0->BringToFront();
            this->buttonDel->BringToFront();
            this->button9->BringToFront();
            this->button8->BringToFront();
            this->button7->BringToFront();
            this->button6->BringToFront();
            this->button5->BringToFront();
            this->button4->BringToFront();
            this->button3->BringToFront();
            this->button2->BringToFront();
            this->button1->BringToFront();
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"Bankomat";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Bankomat";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
        System::Void TextBox_Enter(System::Object^ sender, System::EventArgs^ e) {
            activeTextBox = dynamic_cast<TextBox^>(sender);
        }


        System::Void DigitButton_Click(System::Object^ sender, System::EventArgs^ e) {
            Button^ clickedButton = dynamic_cast<Button^>(sender);
            if (clickedButton != nullptr && activeTextBox != nullptr) {
                String^ newText = activeTextBox->Text + clickedButton->Text;

                // Walidacja nowego tekstu
                if (ValidateDecimalInput(newText)) {
                    activeTextBox->Text = newText;
                }
            }
        }

        System::Void BackspaceButton_Click(System::Object^ sender, System::EventArgs^ e) {
            if (activeTextBox != nullptr && activeTextBox->Text->Length > 0) {
                activeTextBox->Text = activeTextBox->Text->Substring(0, activeTextBox->Text->Length - 1);
            }
        }

        bool ValidateDecimalInput(String^ input) {
            int commaIndex = input->IndexOf(",");
            if (commaIndex == -1) {
                // Brak przecinka - tylko liczba ca³kowita
                return input->Length <= 15;
            }

            // Czêœæ dziesiêtna istnieje
            String^ integerPart = input->Substring(0, commaIndex);
            String^ decimalPart = input->Substring(commaIndex + 1);

            // Walidacja d³ugoœci czêœci ca³kowitej i dziesiêtnej
            return integerPart->Length <= 15 && decimalPart->Length <= 2;
        }


        System::Void KwotaTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
            // Obs³uga poprawnoœci wprowadzanych danych (jak w Home)
            if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '\b') {
                e->Handled = true;
            }
        }


        System::Void buttonWplac_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                double kwota = Convert::ToDouble(textBoxKwotaWplata->Text);
                if (kwota <= 0) {
                    MessageBox::Show("Kwota musi byæ wiêksza ni¿ 0.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }
                klient->setSaldo(klient->getSaldo() + kwota);
                listaKont->ZapiszDoPliku("dane_klientow.txt");
                ZapiszTransakcjeDoPliku("Wplata", klient->getNumerKonta(), "", kwota);
                labelSaldo->Text = System::String::Format(L"{0:F2}", klient->getSaldo());
                MessageBox::Show("Wp³ata zakoñczona sukcesem.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (Exception^ ex) {
                MessageBox::Show("B³¹d podczas wp³aty: " + ex->Message, "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void buttonWyplac_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                double kwota = Convert::ToDouble(textBoxKwotaWyplata->Text);
                if (kwota <= 0 || kwota > klient->getSaldo()) {
                    MessageBox::Show("Kwota jest nieprawid³owa lub brak œrodków.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }
                klient->setSaldo(klient->getSaldo() - kwota);
                listaKont->ZapiszDoPliku("dane_klientow.txt");
                ZapiszTransakcjeDoPliku("Wyplata", klient->getNumerKonta(), "", kwota);
                labelSaldo->Text = System::String::Format(L"{0:F2}", klient->getSaldo());
                MessageBox::Show("Wyp³ata zakoñczona sukcesem.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (Exception^ ex) {
                MessageBox::Show("B³¹d podczas wyp³aty: " + ex->Message, "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void ZapiszTransakcjeDoPliku(const std::string& typTransakcji, const std::string& numerKontaNadawcy, const std::string& numerKontaOdbiorcy, double kwota) {
            std::ofstream plik("dane_transakcji.txt", std::ios::app); // Otwórz plik w trybie dopisywania
            if (plik.is_open()) {
                auto teraz = std::chrono::system_clock::now();
                auto czas = std::chrono::system_clock::to_time_t(teraz);
                plik << typTransakcji << ","
                    << numerKontaNadawcy << ","
                    << (numerKontaOdbiorcy.empty() ? "N/A" : numerKontaOdbiorcy) << ","
                    << kwota << ","
                    << std::put_time(std::localtime(&czas), "%Y-%m-%d %H:%M:%S") << "\n";
                plik.close();
            }
            else {
                MessageBox::Show("Nie uda³o siê zapisaæ transakcji do pliku.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

         private: System::Void buttonWroc_Click_1(System::Object^ sender, System::EventArgs^ e) {
             this->Close();
         }
};
}
