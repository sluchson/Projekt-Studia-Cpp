#include "MyForm.h"
#include "Register.h"
#include "Konto.h"

using namespace System;
using namespace System::Windows::Forms;
 [STAThread]
	 void main(array<String^>^ args) {
	 Application::EnableVisualStyles();
	 Application::SetCompatibleTextRenderingDefault(false);
	 BankSystem::MyForm form;
	 Application::Run(% form);
 }