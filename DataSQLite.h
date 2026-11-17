#pragma once
#include <string>
#include <vector>
#include <sqlite3.h>

class Value {
public:
    std::string strVal;
    int intVal;
    bool isInt;
    Value(const std::string& s) : strVal(s), intVal(0), isInt(false) {}
    Value(int i) : intVal(i), strVal(""), isInt(true) {}
};

// Только объявления функций с точкой с запятой в конце!
std::string escapeString(const std::string& input);

bool addRecord(sqlite3* DB, const std::string& tableName,
    const std::vector<std::string>& columns, const std::vector<Value>& values,
    char** errMsg);

bool updateRecord(sqlite3* DB, const std::string& tableName,
    const std::vector<std::string>& setColumns, const std::vector<Value>& setValues,
    const std::string& whereCondition, char** errMsg);

bool deleteRecord(sqlite3* DB, const std::string& tableName,
    const std::string& whereCondition, char** errMsg);

std::vector<std::vector<std::string>> getRecords(sqlite3* DB,
    const std::string& tableName,
    const std::string& whereCondition = "",
    const std::string& orderBy = "",
    char** errMsg = 0);