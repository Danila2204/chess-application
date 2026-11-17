#pragma once

#include <string>
#include <sqlite3.h>

extern sqlite3* GlobalDB;
extern std::string CurrentUserName;
extern bool IsAdmin;