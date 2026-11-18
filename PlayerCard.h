#pragma once
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;


namespace ChessApplication {


	/// <summary>
	/// Сводка для PlayerCard
	/// </summary>
	public ref class PlayerCard : public System::Windows::Forms::UserControl
	{
	public:
		PlayerCard(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		int PlayerID;

		// Конструктор (обычно генерируется автоматически)

		// ==========================================
		// ГЛАВНЫЙ МЕТОД ЗАГРУЗКИ ДАННЫХ
		// ==========================================
		void LoadData(int id, String^ name, String^ years, String^ relativeImagePath) {
			PlayerID = id;

			// 1. Заполняем Label'ы
			labelName->Text = name;
			labelYears->Text = years;

			// 2. Загружаем картинку
			// Получаем путь к папке, где лежит .exe (например, x64/Debug)
			String^ baseDir = Path::GetDirectoryName(Application::ExecutablePath);

			// Склеиваем путь (например: x64/Debug/ + Images/Alekhin.jpg)
			String^ fullImagePath = Path::Combine(baseDir, relativeImagePath);

			// Проверяем, существует ли файл, и загружаем
			if (File::Exists(fullImagePath)) {
				// Важно: используем Image::FromFile, чтобы файл не блокировался программой
				pictureBoxPhoto->Image = Image::FromFile(fullImagePath);
			}
			else {
				// Если файла нет, показываем пустоту (или картинку-заглушку)
				pictureBoxPhoto->Image = nullptr;
			}
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PlayerCard()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::Label^ labelName;
		System::ComponentModel::Container^ components;
	protected:
	private: System::Windows::Forms::Label^ labelText;
	private: System::Windows::Forms::Label^ labelYears;
	private: System::Windows::Forms::PictureBox^ pictureBoxPhoto;


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
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelText = (gcnew System::Windows::Forms::Label());
			this->labelYears = (gcnew System::Windows::Forms::Label());
			this->pictureBoxPhoto = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPhoto))->BeginInit();
			this->SuspendLayout();
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(355, 15);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(35, 13);
			this->labelName->TabIndex = 0;
			this->labelName->Text = L"label1";
			// 
			// labelText
			// 
			this->labelText->AutoSize = true;
			this->labelText->Location = System::Drawing::Point(23, 24);
			this->labelText->Name = L"labelText";
			this->labelText->Size = System::Drawing::Size(35, 13);
			this->labelText->TabIndex = 1;
			this->labelText->Text = L"label1";
			// 
			// labelYears
			// 
			this->labelYears->AutoSize = true;
			this->labelYears->Location = System::Drawing::Point(355, 214);
			this->labelYears->Name = L"labelYears";
			this->labelYears->Size = System::Drawing::Size(35, 13);
			this->labelYears->TabIndex = 2;
			this->labelYears->Text = L"label1";
			// 
			// pictureBoxPhoto
			// 
			this->pictureBoxPhoto->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBoxPhoto->Location = System::Drawing::Point(315, 44);
			this->pictureBoxPhoto->Name = L"pictureBoxPhoto";
			this->pictureBoxPhoto->Size = System::Drawing::Size(120, 150);
			this->pictureBoxPhoto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxPhoto->TabIndex = 3;
			this->pictureBoxPhoto->TabStop = false;
			// 
			// PlayerCard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pictureBoxPhoto);
			this->Controls->Add(this->labelYears);
			this->Controls->Add(this->labelText);
			this->Controls->Add(this->labelName);
			this->Name = L"PlayerCard";
			this->Size = System::Drawing::Size(453, 372);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
