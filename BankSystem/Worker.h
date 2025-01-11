#pragma once
#include "Register.h"
#include "Konto.h"
#include "Home.h"
#include "Login.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>	



namespace BankSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Worker
	/// </summary>
	public ref class Worker : public System::Windows::Forms::Form
	{
	public:
		Worker(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}
		System::String^ aktualnyUzytkownik;
	private: System::Windows::Forms::Button^ buttonList;
	public:

	private: System::Windows::Forms::Button^ buttonRegister;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonWroc;



	public:

	public:

		Konto* zalogowanyKlient;  // U¿ywamy wskaŸnika zarz¹dzanego do obiektu Konto

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Worker()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;










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
			this->buttonList = (gcnew System::Windows::Forms::Button());
			this->buttonRegister = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonWroc = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(74, 85);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(563, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Witaj pracowniku! Wybierz akcjê:";
			// 
			// buttonList
			// 
			this->buttonList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonList->Location = System::Drawing::Point(19, 181);
			this->buttonList->Name = L"buttonList";
			this->buttonList->Size = System::Drawing::Size(200, 100);
			this->buttonList->TabIndex = 5;
			this->buttonList->Text = L"Lista kont";
			this->buttonList->UseVisualStyleBackColor = true;
			// 
			// buttonRegister
			// 
			this->buttonRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonRegister->Location = System::Drawing::Point(252, 181);
			this->buttonRegister->Name = L"buttonRegister";
			this->buttonRegister->Size = System::Drawing::Size(200, 100);
			this->buttonRegister->TabIndex = 6;
			this->buttonRegister->Text = L"Za³ó¿ konto";
			this->buttonRegister->UseVisualStyleBackColor = true;
			this->buttonRegister->Click += gcnew System::EventHandler(this, &Worker::buttonUzytkownik_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonDelete->Location = System::Drawing::Point(488, 181);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(200, 100);
			this->buttonDelete->TabIndex = 7;
			this->buttonDelete->Text = L"Usuñ konto";
			this->buttonDelete->UseVisualStyleBackColor = true;
			// 
			// buttonWroc
			// 
			this->buttonWroc->Location = System::Drawing::Point(12, 438);
			this->buttonWroc->Name = L"buttonWroc";
			this->buttonWroc->Size = System::Drawing::Size(90, 50);
			this->buttonWroc->TabIndex = 8;
			this->buttonWroc->Text = L"Wróæ";
			this->buttonWroc->UseVisualStyleBackColor = true;
			this->buttonWroc->Click += gcnew System::EventHandler(this, &Worker::buttonWroc_Click);
			// 
			// Worker
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(700, 500);
			this->Controls->Add(this->buttonWroc);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonRegister);
			this->Controls->Add(this->buttonList);
			this->Controls->Add(this->label1);
			this->Name = L"Worker";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Worker";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion




	private: System::Void buttonUzytkownik_Click(System::Object^ sender, System::EventArgs^ e) {
		Register^ registerForm = gcnew Register();
		registerForm->Show();

	}
	private: System::Void buttonWroc_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
};
}
