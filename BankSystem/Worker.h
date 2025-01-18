#pragma once
#include "Register.h"
#include "Konto.h"
#include "Home.h"
#include "Login.h"
#include "Lista.h"
#include "ListaKont.h"
#include "Usun.h"

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

    public ref class Worker : public System::Windows::Forms::Form {
    public:
        Worker(ListaKont* listaKont) {
            InitializeComponent();
            this->listaKont = listaKont;
        }

    protected:
        ~Worker() {
            if (components) {
                delete components;
            }
        }

    private:
        ListaKont* listaKont; // WskaŸnik do listy kont
        System::String^ aktualnyUzytkownik;

        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Button^ buttonList;
        System::Windows::Forms::Button^ buttonRegister;
        System::Windows::Forms::Button^ buttonDelete;
        System::Windows::Forms::Button^ buttonWroc;

        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
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
            this->buttonList->Click += gcnew System::EventHandler(this, &Worker::buttonList_Click);
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
            this->buttonRegister->Click += gcnew System::EventHandler(this, &Worker::buttonRegister_Click);
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
            this->buttonDelete->Click += gcnew System::EventHandler(this, &Worker::buttonDelete_Click);
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

    private: System::Void buttonList_Click(System::Object^ sender, System::EventArgs^ e) {
        Lista^ listaForm = gcnew Lista(globalnaListaKont); // Przeka¿ istniej¹c¹ instancjê ListaKont
        listaForm->ShowDialog();
    }

    private: System::Void buttonRegister_Click(System::Object^ sender, System::EventArgs^ e) {
        Register^ registerForm = gcnew Register();
        registerForm->Show();
    }

    private: System::Void buttonWroc_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
    }
    private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
        Usun^ usunForm = gcnew Usun(globalnaListaKont);
        usunForm->Show();
    }
};
}
