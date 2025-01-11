#pragma once
#include "Konto.h"
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>


namespace BankSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Register
	/// </summary>
	public ref class Register : public System::Windows::Forms::Form
	{
	public:
		Register(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Register()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonWroc;
	private: System::Windows::Forms::TextBox^ textBoxImie;
	private: System::Windows::Forms::TextBox^ textBoxDrugieImie;
	private: System::Windows::Forms::TextBox^ textBoxNazwisko;
	private: System::Windows::Forms::TextBox^ textBoxNrKierunkowy;
	private: System::Windows::Forms::TextBox^ textBoxEmail;
	private: System::Windows::Forms::TextBox^ textBoxPesel;
	private: System::Windows::Forms::TextBox^ textBoxSeriaDowodu;







	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBoxNrDowodu;

	private: System::Windows::Forms::TextBox^ textBoxNrTelefonu;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ buttonZarejestruj;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBoxHaslo;


	protected:

	protected:

	private:
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
			this->buttonWroc = (gcnew System::Windows::Forms::Button());
			this->textBoxImie = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDrugieImie = (gcnew System::Windows::Forms::TextBox());
			this->textBoxNazwisko = (gcnew System::Windows::Forms::TextBox());
			this->textBoxNrKierunkowy = (gcnew System::Windows::Forms::TextBox());
			this->textBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPesel = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSeriaDowodu = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxNrDowodu = (gcnew System::Windows::Forms::TextBox());
			this->textBoxNrTelefonu = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->buttonZarejestruj = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxHaslo = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// buttonWroc
			// 
			this->buttonWroc->Location = System::Drawing::Point(148, 325);
			this->buttonWroc->Name = L"buttonWroc";
			this->buttonWroc->Size = System::Drawing::Size(90, 50);
			this->buttonWroc->TabIndex = 0;
			this->buttonWroc->Text = L"Wróæ";
			this->buttonWroc->UseVisualStyleBackColor = true;
			this->buttonWroc->Click += gcnew System::EventHandler(this, &Register::buttonWroc_Click);
			// 
			// textBoxImie
			// 
			this->textBoxImie->Location = System::Drawing::Point(38, 128);
			this->textBoxImie->Name = L"textBoxImie";
			this->textBoxImie->Size = System::Drawing::Size(200, 22);
			this->textBoxImie->TabIndex = 1;
			// 
			// textBoxDrugieImie
			// 
			this->textBoxDrugieImie->Location = System::Drawing::Point(38, 180);
			this->textBoxDrugieImie->Name = L"textBoxDrugieImie";
			this->textBoxDrugieImie->Size = System::Drawing::Size(200, 22);
			this->textBoxDrugieImie->TabIndex = 2;
			// 
			// textBoxNazwisko
			// 
			this->textBoxNazwisko->Location = System::Drawing::Point(38, 239);
			this->textBoxNazwisko->Name = L"textBoxNazwisko";
			this->textBoxNazwisko->Size = System::Drawing::Size(200, 22);
			this->textBoxNazwisko->TabIndex = 3;
			// 
			// textBoxNrKierunkowy
			// 
			this->textBoxNrKierunkowy->Location = System::Drawing::Point(38, 297);
			this->textBoxNrKierunkowy->Name = L"textBoxNrKierunkowy";
			this->textBoxNrKierunkowy->Size = System::Drawing::Size(44, 22);
			this->textBoxNrKierunkowy->TabIndex = 4;
			// 
			// textBoxEmail
			// 
			this->textBoxEmail->Location = System::Drawing::Point(313, 133);
			this->textBoxEmail->Name = L"textBoxEmail";
			this->textBoxEmail->Size = System::Drawing::Size(200, 22);
			this->textBoxEmail->TabIndex = 5;
			// 
			// textBoxPesel
			// 
			this->textBoxPesel->Location = System::Drawing::Point(316, 180);
			this->textBoxPesel->Name = L"textBoxPesel";
			this->textBoxPesel->Size = System::Drawing::Size(200, 22);
			this->textBoxPesel->TabIndex = 6;
			// 
			// textBoxSeriaDowodu
			// 
			this->textBoxSeriaDowodu->Location = System::Drawing::Point(316, 232);
			this->textBoxSeriaDowodu->Name = L"textBoxSeriaDowodu";
			this->textBoxSeriaDowodu->Size = System::Drawing::Size(60, 22);
			this->textBoxSeriaDowodu->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(38, 106);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 16);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Imiê:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(41, 158);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 16);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Drugie imiê:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(38, 217);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 16);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Nazwisko:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(38, 275);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(74, 16);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Nr telefonu:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(313, 106);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 16);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Adres e-mail:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(316, 158);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 16);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Nr PESEL:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(316, 210);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(184, 16);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Seria i nr dowodu osobistego:";
			// 
			// textBoxNrDowodu
			// 
			this->textBoxNrDowodu->Location = System::Drawing::Point(382, 232);
			this->textBoxNrDowodu->Name = L"textBoxNrDowodu";
			this->textBoxNrDowodu->Size = System::Drawing::Size(134, 22);
			this->textBoxNrDowodu->TabIndex = 15;
			// 
			// textBoxNrTelefonu
			// 
			this->textBoxNrTelefonu->Location = System::Drawing::Point(88, 297);
			this->textBoxNrTelefonu->Name = L"textBoxNrTelefonu";
			this->textBoxNrTelefonu->Size = System::Drawing::Size(150, 22);
			this->textBoxNrTelefonu->TabIndex = 16;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(31, 31);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(222, 38);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Zarejestruj siê";
			// 
			// buttonZarejestruj
			// 
			this->buttonZarejestruj->Location = System::Drawing::Point(38, 325);
			this->buttonZarejestruj->Name = L"buttonZarejestruj";
			this->buttonZarejestruj->Size = System::Drawing::Size(90, 50);
			this->buttonZarejestruj->TabIndex = 18;
			this->buttonZarejestruj->Text = L"Zarejestruj";
			this->buttonZarejestruj->UseVisualStyleBackColor = true;
			this->buttonZarejestruj->Click += gcnew System::EventHandler(this, &Register::buttonZarejestruj_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(313, 325);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(86, 16);
			this->label9->TabIndex = 20;
			this->label9->Text = L"Ustaw has³o:";
			// 
			// textBoxHaslo
			// 
			this->textBoxHaslo->Location = System::Drawing::Point(313, 347);
			this->textBoxHaslo->Name = L"textBoxHaslo";
			this->textBoxHaslo->Size = System::Drawing::Size(200, 22);
			this->textBoxHaslo->TabIndex = 19;
			// 
			// Register
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(700, 500);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBoxHaslo);
			this->Controls->Add(this->buttonZarejestruj);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBoxNrTelefonu);
			this->Controls->Add(this->textBoxNrDowodu);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxSeriaDowodu);
			this->Controls->Add(this->textBoxPesel);
			this->Controls->Add(this->textBoxEmail);
			this->Controls->Add(this->textBoxNrKierunkowy);
			this->Controls->Add(this->textBoxNazwisko);
			this->Controls->Add(this->textBoxDrugieImie);
			this->Controls->Add(this->textBoxImie);
			this->Controls->Add(this->buttonWroc);
			this->Name = L"Register";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Register";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void buttonWroc_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void buttonZarejestruj_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string imie = msclr::interop::marshal_as<std::string>(textBoxImie->Text);
		std::string drugieImie = msclr::interop::marshal_as<std::string>(textBoxDrugieImie->Text);
		std::string nazwisko = msclr::interop::marshal_as<std::string>(textBoxNazwisko->Text);
		std::string numerKierunkowy = msclr::interop::marshal_as<std::string>(textBoxNrKierunkowy->Text);
		std::string numerTelefonu = msclr::interop::marshal_as<std::string>(textBoxNrTelefonu->Text);
		std::string email = msclr::interop::marshal_as<std::string>(textBoxEmail->Text);
		std::string pesel = msclr::interop::marshal_as<std::string>(textBoxPesel->Text);
		std::string seriaDowodu = msclr::interop::marshal_as<std::string>(textBoxSeriaDowodu->Text);
		std::string numerDowodu = msclr::interop::marshal_as<std::string>(textBoxNrDowodu->Text);
		std::string haslo = msclr::interop::marshal_as<std::string>(textBoxHaslo->Text);
		std::string numerKonta = Konto::ustalNumerKonta();

		Konto* noweKonto = new Konto(imie, drugieImie, nazwisko, numerKierunkowy, numerTelefonu, email, pesel, seriaDowodu, numerDowodu, numerKonta, haslo);

		// Zapisanie danych do pliku
		std::ofstream plik("dane_klientow.txt", std::ios::app);
		if (plik.is_open()) {
			plik << *noweKonto;
			/*plik << noweKonto->getNumerKonta() << ",";
			plik << noweKonto->getHaslo() << ",";
			plik << noweKonto->getSaldo() << ",";
			plik <<  noweKonto->getImie() << ",";
			plik <<  noweKonto->getDrugieImie() << ",";
			plik <<  noweKonto->getNazwisko() << ",";
			plik <<  noweKonto->getNumerKierunkowy() << ",";
			plik <<  noweKonto->getNumerTelefonu() << ",";
			plik <<  noweKonto->getEmail() << ",";
			plik <<  noweKonto->getPesel() << ",";
			plik <<  noweKonto->getSeriaDowodu() << ",";
			plik <<  noweKonto->getNumerDowodu() << "\n";*/

			plik.close();
		}

		MessageBox::Show("Rejestracja zakoñczona sukcesem!\nNumer konta: " + gcnew String(noweKonto->getNumerKonta().c_str()), "Sukces");
		this->Close();

	}


	};
}
