#pragma once

#include "DataSQLite.h"
#include "Globals.h"
#include <msclr\marshal_cppstd.h>
#include "MainForm.h" 
#include <msclr\marshal_cppstd.h>
using namespace System::Text;

namespace ChessApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonEntire;
	private: System::Windows::Forms::Button^ buttonRegister;
	private: System::Windows::Forms::TextBox^ textBoxLogin;
	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::Label^ labelLogin;
	private: System::Windows::Forms::Label^ labelError;
	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonEntire = (gcnew System::Windows::Forms::Button());
			this->buttonRegister = (gcnew System::Windows::Forms::Button());
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->labelLogin = (gcnew System::Windows::Forms::Label());
			this->labelError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonEntire
			// 
			this->buttonEntire->Location = System::Drawing::Point(152, 251);
			this->buttonEntire->Name = L"buttonEntire";
			this->buttonEntire->Size = System::Drawing::Size(75, 23);
			this->buttonEntire->TabIndex = 0;
			this->buttonEntire->Text = L"Вход";
			this->buttonEntire->UseVisualStyleBackColor = true;
			this->buttonEntire->Click += gcnew System::EventHandler(this, &RegisterForm::buttonEntire_Click);
			// 
			// buttonRegister
			// 
			this->buttonRegister->Location = System::Drawing::Point(289, 251);
			this->buttonRegister->Name = L"buttonRegister";
			this->buttonRegister->Size = System::Drawing::Size(103, 23);
			this->buttonRegister->TabIndex = 1;
			this->buttonRegister->Text = L"Регистрация";
			this->buttonRegister->UseVisualStyleBackColor = true;
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Location = System::Drawing::Point(200, 104);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(100, 20);
			this->textBoxLogin->TabIndex = 2;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Location = System::Drawing::Point(200, 172);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '*';
			this->textBoxPassword->Size = System::Drawing::Size(100, 20);
			this->textBoxPassword->TabIndex = 3;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Location = System::Drawing::Point(197, 145);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(45, 13);
			this->labelPassword->TabIndex = 4;
			this->labelPassword->Text = L"Пароль";
			// 
			// labelLogin
			// 
			this->labelLogin->AutoSize = true;
			this->labelLogin->Location = System::Drawing::Point(200, 76);
			this->labelLogin->Name = L"labelLogin";
			this->labelLogin->Size = System::Drawing::Size(38, 13);
			this->labelLogin->TabIndex = 5;
			this->labelLogin->Text = L"Логин";
			// 
			// labelError
			// 
			this->labelError->AutoSize = true;
			this->labelError->ForeColor = System::Drawing::Color::Red;
			this->labelError->Location = System::Drawing::Point(228, 220);
			this->labelError->Name = L"labelError";
			this->labelError->Size = System::Drawing::Size(0, 13);
			this->labelError->TabIndex = 6;
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(504, 406);
			this->Controls->Add(this->labelError);
			this->Controls->Add(this->labelLogin);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->textBoxLogin);
			this->Controls->Add(this->buttonRegister);
			this->Controls->Add(this->buttonEntire);
			this->Name = L"RegisterForm";
			this->Text = L"Регистрация";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonEntire_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ login = textBoxLogin->Text;
		String^ password = textBoxPassword->Text;

		// Проверка на пустоту
		if (login == "" || password == "") {
			labelError->Text = "Введите логин и пароль!";
			return;
		}

		array<Byte>^ bytesLogin = Encoding::UTF8->GetBytes(login);
		array<Byte>^ bytesPassword = Encoding::UTF8->GetBytes(password);

		// Переводим байты в std::string
		std::string strLogin = "";
		for each (Byte b in bytesLogin) strLogin += (char)b;

		std::string strPassword = "";
		for each (Byte b in bytesPassword) strPassword += (char)b;

		// 3. Формируем условие (используем функцию escapeString из твоего кода)
		std::string condition = "Login = '";
		condition += escapeString(strLogin);
		condition += "' AND Password = '";
		condition += escapeString(strPassword);
		condition += "'";

		// 4. Ищем в БД
		char* errMsg = 0;
		// Вызываем getRecords для таблицы users (передай свойство DB, которое у тебя открыто)
		auto result = getRecords(GlobalDB, "users", condition, "", &errMsg);

		// 5. Проверяем результат
		if (result.empty()) {
			// Если пусто — неверные данные
			labelError->Text = "Неверно введён логин/пароль";
		}
		else {
			// Если нашли — сохраняем имя и проверяем на админа
			CurrentUserName = strLogin;

			// Допустим, у админа логин "admin" (или у тебя есть колонка role)
			if (strLogin == "Admin") {
				IsAdmin = true;
			}
			else {
				IsAdmin = false;
			}

			// Переходим на следующую форму
			this->Hide();
			MainForm^ mainForm = gcnew MainForm();
			mainForm->Show();
		}
	}
};
}
