#pragma once

namespace ChessApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelHeader;
	protected:
	private: System::Windows::Forms::Panel^ panelSide;
	private: System::Windows::Forms::Panel^ panelMain;
	private: System::Windows::Forms::Button^ buttonChessmasters;
	private: System::Windows::Forms::Button^ buttonAdmin;
	private: System::Windows::Forms::Button^ buttonMain;
	private: System::Windows::Forms::Button^ buttonDebuts;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelHeader = (gcnew System::Windows::Forms::Panel());
			this->panelSide = (gcnew System::Windows::Forms::Panel());
			this->panelMain = (gcnew System::Windows::Forms::Panel());
			this->buttonChessmasters = (gcnew System::Windows::Forms::Button());
			this->buttonDebuts = (gcnew System::Windows::Forms::Button());
			this->buttonMain = (gcnew System::Windows::Forms::Button());
			this->buttonAdmin = (gcnew System::Windows::Forms::Button());
			this->panelSide->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelHeader
			// 
			this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHeader->Location = System::Drawing::Point(0, 0);
			this->panelHeader->Name = L"panelHeader";
			this->panelHeader->Size = System::Drawing::Size(1089, 87);
			this->panelHeader->TabIndex = 0;
			// 
			// panelSide
			// 
			this->panelSide->Controls->Add(this->buttonAdmin);
			this->panelSide->Controls->Add(this->buttonMain);
			this->panelSide->Controls->Add(this->buttonDebuts);
			this->panelSide->Controls->Add(this->buttonChessmasters);
			this->panelSide->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSide->Location = System::Drawing::Point(0, 87);
			this->panelSide->Name = L"panelSide";
			this->panelSide->Size = System::Drawing::Size(222, 566);
			this->panelSide->TabIndex = 1;
			// 
			// panelMain
			// 
			this->panelMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelMain->Location = System::Drawing::Point(222, 87);
			this->panelMain->Name = L"panelMain";
			this->panelMain->Size = System::Drawing::Size(867, 566);
			this->panelMain->TabIndex = 2;
			// 
			// buttonChessmasters
			// 
			this->buttonChessmasters->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonChessmasters->Location = System::Drawing::Point(59, 167);
			this->buttonChessmasters->Name = L"buttonChessmasters";
			this->buttonChessmasters->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->buttonChessmasters->Size = System::Drawing::Size(88, 23);
			this->buttonChessmasters->TabIndex = 0;
			this->buttonChessmasters->Text = L"Ўахматисты";
			this->buttonChessmasters->UseVisualStyleBackColor = true;
			// 
			// buttonDebuts
			// 
			this->buttonDebuts->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDebuts->Location = System::Drawing::Point(59, 273);
			this->buttonDebuts->Name = L"buttonDebuts";
			this->buttonDebuts->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->buttonDebuts->Size = System::Drawing::Size(88, 23);
			this->buttonDebuts->TabIndex = 1;
			this->buttonDebuts->Text = L"ƒебюты";
			this->buttonDebuts->UseVisualStyleBackColor = true;
			// 
			// buttonMain
			// 
			this->buttonMain->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMain->Location = System::Drawing::Point(59, 62);
			this->buttonMain->Name = L"buttonMain";
			this->buttonMain->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->buttonMain->Size = System::Drawing::Size(88, 23);
			this->buttonMain->TabIndex = 2;
			this->buttonMain->Text = L"√лавна€";
			this->buttonMain->UseVisualStyleBackColor = true;
			// 
			// buttonAdmin
			// 
			this->buttonAdmin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAdmin->Location = System::Drawing::Point(33, 495);
			this->buttonAdmin->Name = L"buttonAdmin";
			this->buttonAdmin->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->buttonAdmin->Size = System::Drawing::Size(135, 59);
			this->buttonAdmin->TabIndex = 3;
			this->buttonAdmin->Text = L"јдминистраторска€ панель";
			this->buttonAdmin->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1089, 653);
			this->Controls->Add(this->panelMain);
			this->Controls->Add(this->panelSide);
			this->Controls->Add(this->panelHeader);
			this->Name = L"MainForm";
			this->Text = L"ChessInfo";
			this->panelSide->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
