#pragma once
#include "Register.h"



namespace BankSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
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
	private: System::Windows::Forms::Button^ buttonRejestroj;




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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxNrKonta = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHaslo = (gcnew System::Windows::Forms::TextBox());
			this->buttonZaloguj = (gcnew System::Windows::Forms::Button());
			this->buttonRejestroj = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(25, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(174, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Zaloguj siê";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nr konta:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 159);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Has³o:";
			// 
			// textBoxNrKonta
			// 
			this->textBoxNrKonta->Location = System::Drawing::Point(32, 107);
			this->textBoxNrKonta->Name = L"textBoxNrKonta";
			this->textBoxNrKonta->Size = System::Drawing::Size(200, 22);
			this->textBoxNrKonta->TabIndex = 3;
			// 
			// textBoxHaslo
			// 
			this->textBoxHaslo->Location = System::Drawing::Point(32, 178);
			this->textBoxHaslo->Name = L"textBoxHaslo";
			this->textBoxHaslo->Size = System::Drawing::Size(200, 22);
			this->textBoxHaslo->TabIndex = 4;
			// 
			// buttonZaloguj
			// 
			this->buttonZaloguj->Location = System::Drawing::Point(32, 225);
			this->buttonZaloguj->Name = L"buttonZaloguj";
			this->buttonZaloguj->Size = System::Drawing::Size(90, 50);
			this->buttonZaloguj->TabIndex = 5;
			this->buttonZaloguj->Text = L"Zaloguj";
			this->buttonZaloguj->UseVisualStyleBackColor = true;
			// 
			// buttonRejestroj
			// 
			this->buttonRejestroj->Location = System::Drawing::Point(142, 225);
			this->buttonRejestroj->Name = L"buttonRejestroj";
			this->buttonRejestroj->Size = System::Drawing::Size(90, 50);
			this->buttonRejestroj->TabIndex = 6;
			this->buttonRejestroj->Text = L"Zarejestruj";
			this->buttonRejestroj->UseVisualStyleBackColor = true;
			this->buttonRejestroj->Click += gcnew System::EventHandler(this, &MyForm::buttonRegister_Click);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(700, 500);
			this->Controls->Add(this->buttonRejestroj);
			this->Controls->Add(this->buttonZaloguj);
			this->Controls->Add(this->textBoxHaslo);
			this->Controls->Add(this->textBoxNrKonta);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonRegister_Click(System::Object^ sender, System::EventArgs^ e) {
		Register^ registerForm = gcnew Register();
		registerForm->Show();
	}
};
}
