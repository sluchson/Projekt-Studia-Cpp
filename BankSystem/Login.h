#pragma once
#include "Konto.h"
#include "Home.h"
#include "ListaKont.h"
#include "Bankomat.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <regex>
#include <msclr/marshal_cppstd.h>


namespace BankSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Podsumowanie informacji o Login
    /// </summary>
    public ref class Login : public System::Windows::Forms::Form
    {
    public:
        Login(ListaKont* listaKont)
        {
            InitializeComponent();
            this->listaKont = listaKont;
        }

    protected:
        /// <summary>
        /// Wyczyœæ wszystkie u¿ywane zasoby.
        /// </summary>
        ~Login()
        {
            if (components) {
                delete components;
            }
        }

    private:
        ListaKont* listaKont; // WskaŸnik do obiektu ListaKont
        System::String^ aktualnyUzytkownik;
        Konto* zalogowanyKlient; // WskaŸnik do obiektu zalogowanego klienta

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::TextBox^ textBoxNrKonta;
    private: System::Windows::Forms::TextBox^ textBoxHaslo;
    private: System::Windows::Forms::Button^ buttonZaloguj;
    private: System::Windows::Forms::Button^ buttonWroc;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::TextBox^ textBoxHasloBankomat;


    private: System::Windows::Forms::TextBox^ textBoxNrKontaBankomat;

    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Button^ buttonBankomat;



    protected:
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
        /// jej zawartoœci w edytorze kodu.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->textBoxNrKonta = (gcnew System::Windows::Forms::TextBox());
            this->textBoxHaslo = (gcnew System::Windows::Forms::TextBox());
            this->buttonZaloguj = (gcnew System::Windows::Forms::Button());
            this->buttonWroc = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->textBoxHasloBankomat = (gcnew System::Windows::Forms::TextBox());
            this->textBoxNrKontaBankomat = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->buttonBankomat = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->label1->Location = System::Drawing::Point(8, 18);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(221, 42);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Zaloguj siê ";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(12, 88);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(60, 16);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Nr konta:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(12, 150);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(49, 16);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Has³o:";
            // 
            // textBoxNrKonta
            // 
            this->textBoxNrKonta->Location = System::Drawing::Point(12, 107);
            this->textBoxNrKonta->MaxLength = 26;
            this->textBoxNrKonta->Name = L"textBoxNrKonta";
            this->textBoxNrKonta->Size = System::Drawing::Size(200, 22);
            this->textBoxNrKonta->TabIndex = 3;
            // 
            // textBoxHaslo
            // 
            this->textBoxHaslo->Location = System::Drawing::Point(12, 169);
            this->textBoxHaslo->Name = L"textBoxHaslo";
            this->textBoxHaslo->PasswordChar = '*';
            this->textBoxHaslo->Size = System::Drawing::Size(200, 22);
            this->textBoxHaslo->TabIndex = 4;
            // 
            // buttonZaloguj
            // 
            this->buttonZaloguj->Location = System::Drawing::Point(12, 201);
            this->buttonZaloguj->Name = L"buttonZaloguj";
            this->buttonZaloguj->Size = System::Drawing::Size(90, 50);
            this->buttonZaloguj->TabIndex = 5;
            this->buttonZaloguj->Text = L"Zaloguj";
            this->buttonZaloguj->UseVisualStyleBackColor = true;
            this->buttonZaloguj->Click += gcnew System::EventHandler(this, &Login::buttonZaloguj_Click);
            // 
            // buttonWroc
            // 
            this->buttonWroc->Location = System::Drawing::Point(12, 438);
            this->buttonWroc->Name = L"buttonWroc";
            this->buttonWroc->Size = System::Drawing::Size(90, 50);
            this->buttonWroc->TabIndex = 7;
            this->buttonWroc->Text = L"Wróæ";
            this->buttonWroc->UseVisualStyleBackColor = true;
            this->buttonWroc->Click += gcnew System::EventHandler(this, &Login::buttonWroc_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(230, 0);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(471, 502);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 8;
            this->pictureBox1->TabStop = false;
            // 
            // textBoxHasloBankomat
            // 
            this->textBoxHasloBankomat->Location = System::Drawing::Point(378, 254);
            this->textBoxHasloBankomat->Name = L"textBoxHasloBankomat";
            this->textBoxHasloBankomat->PasswordChar = '*';
            this->textBoxHasloBankomat->Size = System::Drawing::Size(174, 22);
            this->textBoxHasloBankomat->TabIndex = 13;
            // 
            // textBoxNrKontaBankomat
            // 
            this->textBoxNrKontaBankomat->Location = System::Drawing::Point(378, 210);
            this->textBoxNrKontaBankomat->MaxLength = 26;
            this->textBoxNrKontaBankomat->Name = L"textBoxNrKontaBankomat";
            this->textBoxNrKontaBankomat->Size = System::Drawing::Size(174, 22);
            this->textBoxNrKontaBankomat->TabIndex = 12;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(378, 235);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(49, 16);
            this->label5->TabIndex = 11;
            this->label5->Text = L"Has³o:";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(378, 191);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(60, 16);
            this->label6->TabIndex = 10;
            this->label6->Text = L"Nr konta:";
            // 
            // buttonBankomat
            // 
            this->buttonBankomat->Location = System::Drawing::Point(365, 296);
            this->buttonBankomat->Name = L"buttonBankomat";
            this->buttonBankomat->Size = System::Drawing::Size(90, 50);
            this->buttonBankomat->TabIndex = 14;
            this->buttonBankomat->Text = L"Wejdz";
            this->buttonBankomat->UseVisualStyleBackColor = true;
            this->buttonBankomat->Click += gcnew System::EventHandler(this, &Login::buttonBankomat_Click);
            // 
            // Login
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->ClientSize = System::Drawing::Size(700, 500);
            this->ControlBox = false;
            this->Controls->Add(this->buttonBankomat);
            this->Controls->Add(this->textBoxHasloBankomat);
            this->Controls->Add(this->textBoxNrKontaBankomat);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->buttonWroc);
            this->Controls->Add(this->buttonZaloguj);
            this->Controls->Add(this->textBoxHaslo);
            this->Controls->Add(this->textBoxNrKonta);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"Login";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Login";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void buttonZaloguj_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string nrKonta = msclr::interop::marshal_as<std::string>(textBoxNrKonta->Text);
        std::string hasloText = msclr::interop::marshal_as<std::string>(textBoxHaslo->Text);

        std::regex regexNumerKonta("^[0-9]{26}$");
        if (!std::regex_match(nrKonta, regexNumerKonta)) {
            MessageBox::Show("Numer konta musi sk³adaæ siê dok³adnie z 26 cyfr.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        Konto* znalezioneKonto = listaKont->Szukaj(nrKonta);
        if (znalezioneKonto && znalezioneKonto->getHaslo() == hasloText) {
            MessageBox::Show("Zalogowano pomyœlnie", "Sukces!", MessageBoxButtons::OK, MessageBoxIcon::Information);
            Home^ homeForm = gcnew Home(znalezioneKonto, listaKont);
            homeForm->Show();
            this->Close();
        }
        else {
            MessageBox::Show("Nieprawid³owy numer konta lub has³o.", "B³¹d logowania");
        }
    }



    private: System::Void buttonBankomat_Click(System::Object^ sender, System::EventArgs^ e) {
        std::string nrKonta = msclr::interop::marshal_as<std::string>(textBoxNrKontaBankomat->Text);
        std::string hasloText = msclr::interop::marshal_as<std::string>(textBoxHasloBankomat->Text);

        std::regex regexNumerKonta("^[0-9]{26}$");
        if (!std::regex_match(nrKonta, regexNumerKonta)) {
            MessageBox::Show("Numer konta musi sk³adaæ siê dok³adnie z 26 cyfr.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        Konto* znalezioneKonto = listaKont->Szukaj(nrKonta);
        if (znalezioneKonto && znalezioneKonto->getHaslo() == hasloText) {
            MessageBox::Show("Zalogowano pomyœlnie", "Sukces!", MessageBoxButtons::OK, MessageBoxIcon::Information);
            Bankomat^ bankomatForm = gcnew Bankomat(znalezioneKonto, listaKont);
            bankomatForm->Show();
            this->Close();
        }
        else {
            MessageBox::Show("Nieprawid³owy numer konta lub has³o.", "B³¹d logowania");
        }
    }


    private: System::Void buttonWroc_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
    }


};
}
