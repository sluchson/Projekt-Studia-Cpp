#pragma once
#include "Konto.h"
#include "ListaKont.h"
#include <msclr/marshal_cppstd.h>

#include <chrono>
#include <iomanip>
#include <fstream>

#include <sstream>



namespace BankSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Podsumowanie informacji o Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(Konto* klient, ListaKont* listaKont)
		{
			InitializeComponent();
			this->klient = klient;
			this->listaKont = listaKont;
			// Ustawienie salda na labelSaldo
			labelSaldo->Text = System::String::Format(L"{0:F2}", klient->getSaldo());
			// Ustawienie imienia na labelImie
			labelImie->Text = gcnew System::String(klient->getImie().c_str());
			WczytajTransakcje();
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ListaKont* listaKont; // WskaŸnik do obiektu ListaKont
	private: Konto* klient;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelImie;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labelSaldo;
	private: System::Windows::Forms::Button^ buttonBack;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxKwotaWplata;
	private: System::Windows::Forms::Button^ buttonWplac;
	private: System::Windows::Forms::Button^ buttonWyplac;
	private: System::Windows::Forms::TextBox^ textBoxKwotaWyplata;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ buttonPrzelej;
	private: System::Windows::Forms::TextBox^ textBoxKwotaPrzelew;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxNrKontaPrzelewu;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ListBox^ listBoxTransakcje;
	private: System::Windows::Forms::Label^ label10;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelImie = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelSaldo = (gcnew System::Windows::Forms::Label());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxKwotaWplata = (gcnew System::Windows::Forms::TextBox());
			this->buttonWplac = (gcnew System::Windows::Forms::Button());
			this->buttonWyplac = (gcnew System::Windows::Forms::Button());
			this->textBoxKwotaWyplata = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buttonPrzelej = (gcnew System::Windows::Forms::Button());
			this->textBoxKwotaPrzelew = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxNrKontaPrzelewu = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->listBoxTransakcje = (gcnew System::Windows::Forms::ListBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(5, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Witaj,";
			// 
			// labelImie
			// 
			this->labelImie->AutoSize = true;
			this->labelImie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelImie->Location = System::Drawing::Point(101, 21);
			this->labelImie->Name = L"labelImie";
			this->labelImie->Size = System::Drawing::Size(90, 37);
			this->labelImie->TabIndex = 1;
			this->labelImie->Text = L"Imie!";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Twoje œrodki:";
			// 
			// labelSaldo
			// 
			this->labelSaldo->AutoSize = true;
			this->labelSaldo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelSaldo->Location = System::Drawing::Point(8, 87);
			this->labelSaldo->Name = L"labelSaldo";
			this->labelSaldo->Size = System::Drawing::Size(30, 32);
			this->labelSaldo->TabIndex = 3;
			this->labelSaldo->Text = L"0";
			// 
			// buttonBack
			// 
			this->buttonBack->Location = System::Drawing::Point(12, 438);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(90, 50);
			this->buttonBack->TabIndex = 4;
			this->buttonBack->Text = L"Wróæ";
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &Home::buttonBack_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(419, 22);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Wp³aæ œrodki:";
			// 
			// textBoxKwotaWplata
			// 
			this->textBoxKwotaWplata->Location = System::Drawing::Point(418, 41);
			this->textBoxKwotaWplata->Name = L"textBoxKwotaWplata";
			this->textBoxKwotaWplata->Size = System::Drawing::Size(200, 22);
			this->textBoxKwotaWplata->TabIndex = 6;
			// 
			// buttonWplac
			// 
			this->buttonWplac->Location = System::Drawing::Point(419, 69);
			this->buttonWplac->Name = L"buttonWplac";
			this->buttonWplac->Size = System::Drawing::Size(90, 50);
			this->buttonWplac->TabIndex = 7;
			this->buttonWplac->Text = L"Wp³aæ";
			this->buttonWplac->UseVisualStyleBackColor = true;
			this->buttonWplac->Click += gcnew System::EventHandler(this, &Home::buttonWplac_Click);
			// 
			// buttonWyplac
			// 
			this->buttonWyplac->Location = System::Drawing::Point(419, 216);
			this->buttonWyplac->Name = L"buttonWyplac";
			this->buttonWyplac->Size = System::Drawing::Size(90, 50);
			this->buttonWyplac->TabIndex = 10;
			this->buttonWyplac->Text = L"Wyp³aæ";
			this->buttonWyplac->UseVisualStyleBackColor = true;
			this->buttonWyplac->Click += gcnew System::EventHandler(this, &Home::buttonWyplac_Click);
			// 
			// textBoxKwotaWyplata
			// 
			this->textBoxKwotaWyplata->Location = System::Drawing::Point(419, 188);
			this->textBoxKwotaWyplata->Name = L"textBoxKwotaWyplata";
			this->textBoxKwotaWyplata->Size = System::Drawing::Size(200, 22);
			this->textBoxKwotaWyplata->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(419, 169);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 16);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Wyp³aæ œrodki:";
			// 
			// buttonPrzelej
			// 
			this->buttonPrzelej->Location = System::Drawing::Point(418, 365);
			this->buttonPrzelej->Name = L"buttonPrzelej";
			this->buttonPrzelej->Size = System::Drawing::Size(90, 50);
			this->buttonPrzelej->TabIndex = 13;
			this->buttonPrzelej->Text = L"Przelej";
			this->buttonPrzelej->UseVisualStyleBackColor = true;
			this->buttonPrzelej->Click += gcnew System::EventHandler(this, &Home::buttonPrzelej_Click);
			// 
			// textBoxKwotaPrzelew
			// 
			this->textBoxKwotaPrzelew->Location = System::Drawing::Point(419, 311);
			this->textBoxKwotaPrzelew->Name = L"textBoxKwotaPrzelew";
			this->textBoxKwotaPrzelew->Size = System::Drawing::Size(200, 22);
			this->textBoxKwotaPrzelew->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(416, 292);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 16);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Przelej œrodki:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(367, 42);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 16);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Kwota:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(370, 191);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 16);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Kwota:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(367, 314);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(46, 16);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Kwota:";
			// 
			// textBoxNrKontaPrzelewu
			// 
			this->textBoxNrKontaPrzelewu->Location = System::Drawing::Point(418, 339);
			this->textBoxNrKontaPrzelewu->Name = L"textBoxNrKontaPrzelewu";
			this->textBoxNrKontaPrzelewu->Size = System::Drawing::Size(200, 22);
			this->textBoxNrKontaPrzelewu->TabIndex = 17;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(300, 342);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(116, 16);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Nr konta przelewu:";
			// 
			// listBoxTransakcje
			// 
			this->listBoxTransakcje->FormattingEnabled = true;
			this->listBoxTransakcje->ItemHeight = 16;
			this->listBoxTransakcje->Location = System::Drawing::Point(12, 169);
			this->listBoxTransakcje->Name = L"listBoxTransakcje";
			this->listBoxTransakcje->Size = System::Drawing::Size(243, 260);
			this->listBoxTransakcje->TabIndex = 19;
			this->listBoxTransakcje->Click += gcnew System::EventHandler(this, &Home::listBoxTransakcje_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(9, 150);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(87, 16);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Twoje œrodki:";
			// 
			// Home
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(700, 500);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->listBoxTransakcje);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBoxNrKontaPrzelewu);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->buttonPrzelej);
			this->Controls->Add(this->textBoxKwotaPrzelew);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->buttonWyplac);
			this->Controls->Add(this->textBoxKwotaWyplata);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->buttonWplac);
			this->Controls->Add(this->textBoxKwotaWplata);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->buttonBack);
			this->Controls->Add(this->labelSaldo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->labelImie);
			this->Controls->Add(this->label1);
			this->Name = L"Home";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Home";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: void WczytajTransakcje() {
	listBoxTransakcje->Items->Clear(); // Wyczyœæ ListBox przed za³adowaniem danych
	listBoxTransakcje->DisplayMember = "Item1"; // Wyœwietlaj tylko Item1 z Tuple
	std::ifstream plik("dane_transakcji.txt");
	if (plik.is_open()) {
		std::string linia;
		while (std::getline(plik, linia)) {
			std::stringstream ss(linia);
			std::string typ, nadawca, odbiorca, kwotaStr, timestamp;
			std::getline(ss, typ, ',');
			std::getline(ss, nadawca, ',');
			std::getline(ss, odbiorca, ',');
			std::getline(ss, kwotaStr, ',');
			std::getline(ss, timestamp, ',');

			// Sprawdzamy, czy transakcja dotyczy bie¿¹cego u¿ytkownika
			if (nadawca == klient->getNumerKonta() || odbiorca == klient->getNumerKonta()) {
				// Tekst widoczny w ListBox
				String^ widocznaTransakcja = gcnew String((typ + ", " + kwotaStr + " PLN, " + timestamp.substr(0, 10)).c_str());

				// Pe³ne dane transakcji
				String^ pelnaTransakcja = gcnew String(
					("Typ: " + typ + "\nNadawca: " + nadawca + "\nOdbiorca: " + odbiorca +
						"\nKwota: " + kwotaStr + " PLN\nData: " + timestamp).c_str());

				// Dodanie elementu do ListBox
				listBoxTransakcje->Items->Add(gcnew Tuple<String^, String^>(widocznaTransakcja, pelnaTransakcja));
			}
		}
		plik.close();
	}
	else {
		MessageBox::Show("Nie uda³o siê wczytaæ transakcji z pliku.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}



private: System::Void listBoxTransakcje_Click(System::Object^ sender, System::EventArgs^ e) {
	if (listBoxTransakcje->SelectedItem != nullptr) {
		// Pobierz zaznaczony element jako Tuple
		Tuple<String^, String^>^ transakcja = dynamic_cast<Tuple<String^, String^>^>(listBoxTransakcje->SelectedItem);
		if (transakcja != nullptr) {
			// Wyœwietl pe³ne dane w MessageBox
			MessageBox::Show(transakcja->Item2, "Szczegó³y transakcji", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
}



private: void ZapiszTransakcjeDoPliku(const std::string& typTransakcji, const std::string& numerKontaNadawcy, const std::string& numerKontaOdbiorcy, double kwota) {
	std::ofstream plik("dane_transakcji.txt", std::ios::app); // Otwórz plik w trybie dopisywania
	if (plik.is_open()) {
		// Zapisz transakcjê w formacie: typ,numer_nadawcy,numer_odbiorcy,kwota,timestamp
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



private: void UpdateSaldoLabel() {
		 labelSaldo->Text = System::String::Format(L"{0:F2}", klient->getSaldo());
}

private: System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

private: System::Void buttonWplac_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		double kwota = Convert::ToDouble(textBoxKwotaWplata->Text);
		if (kwota <= 0) {
			MessageBox::Show("Kwota musi byæ wiêksza ni¿ 0.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		klient->setSaldo(klient->getSaldo() + kwota);
		listaKont->ZapiszDoPliku("dane_klientow.txt");
		ZapiszTransakcjeDoPliku("Wplata", klient->getNumerKonta(), "", kwota);
		UpdateSaldoLabel();
		WczytajTransakcje();

		MessageBox::Show("Wp³ata zakoñczona sukcesem.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		MessageBox::Show("B³¹d podczas wp³aty: " + ex->Message, "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}



private: System::Void buttonWyplac_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		double kwota = Convert::ToDouble(textBoxKwotaWyplata->Text);
		if (kwota <= 0 || kwota > klient->getSaldo()) {
			MessageBox::Show("Kwota jest nieprawid³owa lub brak œrodków.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		klient->setSaldo(klient->getSaldo() - kwota);
		listaKont->ZapiszDoPliku("dane_klientow.txt");
		ZapiszTransakcjeDoPliku("Wyplata", klient->getNumerKonta(), "", kwota);
		UpdateSaldoLabel();
		WczytajTransakcje();

		MessageBox::Show("Wyp³ata zakoñczona sukcesem.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		MessageBox::Show("B³¹d podczas wyp³aty: " + ex->Message, "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void buttonPrzelej_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		double kwota = Convert::ToDouble(textBoxKwotaPrzelew->Text);
		std::string numerKontaOdbiorcy = msclr::interop::marshal_as<std::string>(textBoxNrKontaPrzelewu->Text);

		if (kwota <= 0 || kwota > klient->getSaldo()) {
			MessageBox::Show("Kwota jest nieprawid³owa lub brak œrodków.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Konto* odbiorca = listaKont->Szukaj(numerKontaOdbiorcy);
		if (!odbiorca) {
			MessageBox::Show("Nie znaleziono odbiorcy o podanym numerze konta.", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		klient->setSaldo(klient->getSaldo() - kwota);
		odbiorca->setSaldo(odbiorca->getSaldo() + kwota);
		listaKont->ZapiszDoPliku("dane_klientow.txt");
		ZapiszTransakcjeDoPliku("Przelew", klient->getNumerKonta(), numerKontaOdbiorcy, kwota);
		UpdateSaldoLabel();
		WczytajTransakcje();

		MessageBox::Show("Przelew zakoñczony sukcesem.", "Sukces", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		MessageBox::Show("B³¹d podczas przelewu: " + ex->Message, "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

};
} 