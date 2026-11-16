#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Запускаем форму. Имя проекта - ChessApplication, имя формы - MyForm
    ChessApplication::MyForm form;
    Application::Run(% form);

    return 0;
}