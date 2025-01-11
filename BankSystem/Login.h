#pragma once
#include "Konto.h"
#include "Home.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>	
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
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}
		System::String^ aktualnyUzytkownik;
	private: System::Windows::Forms::Button^ buttonWroc;
	public:
		Konto* zalogowanyKlient;  // U�ywamy wska�nika zarz�dzanego do obiektu Konto

	protected:
		/// <summary>
		/// Wyczy�� wszystkie u�ywane zasoby.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxNrKonta;
	private: System::Windows::Forms::TextBox^ textBoxHaslo;
	private: System::Windows::Forms::Button^ buttonZaloguj;





	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs�ugi projektanta � nie nale�y modyfikowa�
		/// jej zawarto�ci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxNrKonta = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHaslo = (gcnew System::Windows::Forms::TextBox());
			this->buttonZaloguj = (gcnew System::Windows::Forms::Button());
			this->buttonWroc = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(5, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(174, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Zaloguj si�";
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
			this->label3->Location = System::Drawing::Point(12, 159);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Has�o:";
			// 
			// textBoxNrKonta
			// 
			this->textBoxNrKonta->Location = System::Drawing::Point(12, 107);
			this->textBoxNrKonta->Name = L"textBoxNrKonta";
			this->textBoxNrKonta->Size = System::Drawing::Size(200, 22);
			this->textBoxNrKonta->TabIndex = 3;
			// 
			// textBoxHaslo
			// 
			this->textBoxHaslo->Location = System::Drawing::Point(12, 178);
			this->textBoxHaslo->Name = L"textBoxHaslo";
			this->textBoxHaslo->Size = System::Drawing::Size(200, 22);
			this->textBoxHaslo->TabIndex = 4;
			// 
			// buttonZaloguj
			// 
			this->buttonZaloguj->Location = System::Drawing::Point(12, 225);
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
			this->buttonWroc->Text = L"Wr��";
			this->buttonWroc->UseVisualStyleBackColor = true;
			this->buttonWroc->Click += gcnew System::EventHandler(this, &Login::buttonWroc_Click);
			// 
			// Login
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(700, 500);
			this->Controls->Add(this->buttonWroc);
			this->Controls->Add(this->buttonZaloguj);
			this->Controls->Add(this->textBoxHaslo);
			this->Controls->Add(this->textBoxNrKonta);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void buttonZaloguj_Click(System::Object^ sender, System::EventArgs^ e) {
		// �cie�ka do pliku z danymi klient�w
		const std::string sciezkaPliku = "dane_klientow.txt";

		// Otwieranie pliku
		std::ifstream plik(sciezkaPliku);
		if (!plik.is_open()) {
			MessageBox::Show("Nie mo�na otworzy� pliku z danymi klient�w!");
			return;
		}

		std::vector<Konto> klienci;  // Lista obiekt�w klient�w
		std::string linia;

		// Odczyt danych z pliku linia po linii
		while (std::getline(plik, linia)) {
			std::stringstream ss(linia);
			std::string numerKonta, haslo, saldo, imie, drugieImie, nazwisko, numerKierunkowy, numerTelefonu, email, pesel, seriaDowodu, numerDowodu;

			// Parsowanie danych
			if (std::getline(ss, numerKonta, ',') &&
				std::getline(ss, haslo, ',') &&
				std::getline(ss, saldo, ',') &&
				std::getline(ss, imie, ',') &&
				std::getline(ss, drugieImie, ',') &&
				std::getline(ss, nazwisko, ',') &&
				std::getline(ss, numerKierunkowy, ',') &&
				std::getline(ss, numerTelefonu, ',') &&
				std::getline(ss, email, ',') &&
				std::getline(ss, pesel, ',') &&
				std::getline(ss, seriaDowodu, ',') &&
				std::getline(ss, numerDowodu)) {

				// Tworzenie obiektu Konto
				Konto klient(imie, drugieImie, nazwisko, numerKierunkowy, numerTelefonu, email, pesel, seriaDowodu, numerDowodu, numerKonta, haslo, std::stod(saldo));

				// Sprawdzenie, czy numer konta i has�o pasuj�
				std::string nrKonta = msclr::interop::marshal_as<std::string>(textBoxNrKonta->Text);
				std::string hasloText = msclr::interop::marshal_as<std::string>(textBoxHaslo->Text);

				if (klient.getNumerKonta() == nrKonta && klient.getHaslo() == hasloText) {
					MessageBox::Show("Zalogowano pomy�lnie!");

					// Zapisz dane zalogowanego u�ytkownika
					aktualnyUzytkownik = msclr::interop::marshal_as<System::String^>(nrKonta);
					zalogowanyKlient = &klient;  // Przechowaj obiekt klienta

					plik.close();

					// Przeka� dane do formularza Home
					Home^ homeForm = gcnew Home(zalogowanyKlient);  // Konstruktor przyjmuj�cy klienta
					homeForm->Show();
					return; // Zako�cz procedur� logowania
				}
			}
		}

		plik.close();
		MessageBox::Show("Nie znaleziono klienta z podanym numerem konta i has�em.");
	}



	private: System::Void buttonWroc_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
};
}
