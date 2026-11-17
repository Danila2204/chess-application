#include "DataSQLite.h"

using namespace std;

// Функция для безопасного экранирования одинарных кавычек в строках (защита от ошибок SQL)
string escapeString(const string& input) {
    string output = "";
    for (char c : input) {
        if (c == '\'') output += "''"; // Заменяем ' на ''
        else output += c;
    }
    return output;
}

// ==========================================
// 1. МЕТОД ДОБАВЛЕНИЯ (INSERT)
// ==========================================
bool addRecord(sqlite3* DB, const string& tableName,
    const vector<string>& columns, const vector<Value>& values,
    char** errMsg)
{
    if (columns.size() != values.size()) return false;

    string sql = "INSERT INTO " + tableName + " (";

    // Формируем список колонок
    for (size_t i = 0; i < columns.size(); ++i) {
        sql += columns[i];
        if (i < columns.size() - 1) sql += ", ";
    }

    sql += ") VALUES (";

    // Формируем значения
    for (size_t i = 0; i < values.size(); ++i) {
        if (values[i].isInt) {
            sql += to_string(values[i].intVal);
        }
        else {
            sql += "'" + escapeString(values[i].strVal) + "'";
        }
        if (i < values.size() - 1) sql += ", ";
    }
    sql += ");";

    // Выполняем
    int rc = sqlite3_exec(DB, (sql).c_str(), 0, 0, errMsg);
    return rc == SQLITE_OK;
}

// ==========================================
// 2. МЕТОД ОБНОВЛЕНИЯ (UPDATE)
// ==========================================
bool updateRecord(sqlite3* DB, const string& tableName,
    const vector<string>& setColumns, const vector<Value>& setValues,
    const string& whereCondition, char** errMsg)
{
    if (setColumns.size() != setValues.size()) return false;

    string sql = "UPDATE " + tableName + " SET ";

    // Формируем пары "колонка = значение"
    for (size_t i = 0; i < setColumns.size(); ++i) {
        sql += setColumns[i] + " = ";
        if (setValues[i].isInt) {
            sql += to_string(setValues[i].intVal);
        }
        else {
            sql += "'" + escapeString(setValues[i].strVal) + "'";
        }
        if (i < setColumns.size() - 1) sql += ", ";
    }

    // Добавляем условие (например, "id = 5" или "name = 'Алехин'")
    if (!whereCondition.empty()) {
        sql += " WHERE " + whereCondition;
    }
    sql += ";";

    int rc = sqlite3_exec(DB, (sql).c_str(), 0, 0, errMsg);
    return rc == SQLITE_OK;
}

// ==========================================
// 3. МЕТОД УДАЛЕНИЯ (DELETE)
// ==========================================
bool deleteRecord(sqlite3* DB, const string& tableName,
    const string& whereCondition, char** errMsg)
{
    string sql = "DELETE FROM " + tableName;

    if (!whereCondition.empty()) {
        sql += " WHERE " + whereCondition;
    }
    sql += ";";

    int rc = sqlite3_exec(DB, (sql).c_str(), 0, 0, errMsg);
    return rc == SQLITE_OK;
}

// Функция для получения данных из таблицы
// Возвращает вектор строк. Каждая строка - это вектор колонок.
vector<vector<string>> getRecords(sqlite3* DB,
    const string& tableName,
    const string& whereCondition,
    const string& orderBy,
    char** errMsg)
{
    vector<vector<string>> result;

    // Формируем запрос
    string sql = "SELECT * FROM " + tableName;

    if (!whereCondition.empty()) {
        sql += " WHERE " + whereCondition;
    }
    if (!orderBy.empty()) {
        sql += " ORDER BY " + orderBy;
    }
    sql += ";";

    sqlite3_stmt* stmt;

    // Подготавливаем запрос
    if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK) {

        int columnCount = sqlite3_column_count(stmt); // Узнаем количество колонок

        // Перебираем строки
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            vector<string> row;
            for (int i = 0; i < columnCount; ++i) {
                const unsigned char* text = sqlite3_column_text(stmt, i);
                // Если значение NULL, пишем пустую строку, иначе текст
                row.push_back(text ? (const char*)text : "");
            }
            result.push_back(row);
        }
    }
    else {
        // Если произошла ошибка, записываем её
        if (errMsg) *errMsg = sqlite3_mprintf("%s", sqlite3_errmsg(DB));
    }

    sqlite3_finalize(stmt);
    return result;
}