#pragma once
#include "Login.h"
#include "Worker.h"
#include <string>




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

		}
	System::String^ aktualnyUzytkownik;

		
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^ buttonKonta;
	private: System::Windows::Forms::Button^ buttonUzytkownik;
	private: System::Windows::Forms::Button^ buttonZamknij;

#pragma region 
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonKonta = (gcnew System::Windows::Forms::Button());
			this->buttonUzytkownik = (gcnew System::Windows::Forms::Button());
			this->buttonZamknij = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(142, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(488, 69);
			this->label1->TabIndex = 0;
			this->label1->Text = L"System Bankowy";
			// 
			// buttonKonta
			// 
			this->buttonKonta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonKonta->Location = System::Drawing::Point(137, 225);
			this->buttonKonta->Name = L"buttonKonta";
			this->buttonKonta->Size = System::Drawing::Size(200, 100);
			this->buttonKonta->TabIndex = 5;
			this->buttonKonta->Text = L"Pracownik";
			this->buttonKonta->UseVisualStyleBackColor = true;
			this->buttonKonta->Click += gcnew System::EventHandler(this, &MyForm::buttonKonta_Click);
			// 
			// buttonUzytkownik
			// 
			this->buttonUzytkownik->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonUzytkownik->Location = System::Drawing::Point(343, 225);
			this->buttonUzytkownik->Name = L"buttonUzytkownik";
			this->buttonUzytkownik->Size = System::Drawing::Size(200, 100);
			this->buttonUzytkownik->TabIndex = 6;
			this->buttonUzytkownik->Text = L"U¿ytkownik";
			this->buttonUzytkownik->UseVisualStyleBackColor = true;
			this->buttonUzytkownik->Click += gcnew System::EventHandler(this, &MyForm::buttonUzytkownik_Click);
			// 
			// buttonZamknij
			// 
			this->buttonZamknij->Location = System::Drawing::Point(12, 438);
			this->buttonZamknij->Name = L"buttonZamknij";
			this->buttonZamknij->Size = System::Drawing::Size(90, 50);
			this->buttonZamknij->TabIndex = 7;
			this->buttonZamknij->Text = L"Zamknij";
			this->buttonZamknij->UseVisualStyleBackColor = true;
			this->buttonZamknij->Click += gcnew System::EventHandler(this, &MyForm::buttonZamknij_Click);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(700, 500);
			this->ControlBox = false;
			this->Controls->Add(this->buttonZamknij);
			this->Controls->Add(this->buttonUzytkownik);
			this->Controls->Add(this->buttonKonta);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void buttonUzytkownik_Click(System::Object^ sender, System::EventArgs^ e) {
	Login^ loginForm = gcnew Login(globalnaListaKont);
	loginForm->Show();
	
}
private: System::Void buttonKonta_Click(System::Object^ sender, System::EventArgs^ e) {
	Worker^ workerForm = gcnew Worker(globalnaListaKont);
	workerForm->Show();
}
private: System::Void buttonZamknij_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
