#pragma once
#include "Konto.h"

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
		Home(Konto* klient)
		{
			InitializeComponent();
			// Ustawienie salda na labelSaldo
			labelSaldo->Text = System::String::Format(L"{0:F2}", klient->getSaldo());
			// Ustawienie imienia na labelImie
			labelImie->Text = gcnew System::String(klient->getImie().c_str());
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelImie;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labelSaldo;
	private: System::Windows::Forms::Button^ buttonBack;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxKwotaWplata;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBoxKwotaWyplata;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBoxKwotaPrzelew;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxNrKontaPrzelewu;

	private: System::Windows::Forms::Label^ label9;

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBoxKwotaWyplata = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBoxKwotaPrzelew = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxNrKontaPrzelewu = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(21, 26);
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
			this->labelImie->Location = System::Drawing::Point(116, 26);
			this->labelImie->Name = L"labelImie";
			this->labelImie->Size = System::Drawing::Size(90, 37);
			this->labelImie->TabIndex = 1;
			this->labelImie->Text = L"Imie!";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 90);
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
			this->labelSaldo->Location = System::Drawing::Point(22, 119);
			this->labelSaldo->Name = L"labelSaldo";
			this->labelSaldo->Size = System::Drawing::Size(30, 32);
			this->labelSaldo->TabIndex = 3;
			this->labelSaldo->Text = L"0";
			// 
			// buttonBack
			// 
			this->buttonBack->Location = System::Drawing::Point(28, 365);
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(419, 69);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 50);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Wp³aæ";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(419, 216);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 50);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Wyp³aæ";
			this->button2->UseVisualStyleBackColor = true;
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
			this->label4->Size = System::Drawing::Size(92, 16);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Wp³aæ œrodki:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(418, 365);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(90, 50);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Przelej";
			this->button3->UseVisualStyleBackColor = true;
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
			this->label5->Size = System::Drawing::Size(92, 16);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Wp³aæ œrodki:";
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
			// Home
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(700, 500);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBoxNrKontaPrzelewu);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBoxKwotaPrzelew);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBoxKwotaWyplata);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
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

private: System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
