#include "RegisterForm.h"
#include "Globals.h"

using namespace System;
using namespace System::Windows::Forms;


std::string CurrentUserName = "";
bool IsAdmin = false;
sqlite3* GlobalDB = nullptr;

[STAThreadAttribute]
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    sqlite3_open("chess.db", &GlobalDB);

    ChessApplication::RegisterForm form;
    Application::Run(% form);

    return 0;
}