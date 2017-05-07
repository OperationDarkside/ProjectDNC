#pragma once
#include "DateTime.h"
#include "Type.h"
#include "DataTable.h"
#include "SqlDataReader.h"
#include <my_global.h>
#include "mysql.h"
#include <iostream>

namespace dnc::Data::SqlClient{

	class MySqlDataReader: public SqlDataReader{

		friend class MySqlCommand;
		friend class MySqlDataAdapter;

	public:
		~MySqlDataReader();

		unsigned int FieldCount();
		bool GetBoolean(int i);
		char GetByte(int i);
		long GetBytes(int i, long dataIndex, char* buffer, int bufferIndex, int length);
		long GetChars(int i, long dataIndex, char* buffer, int bufferIndex, int length);
		String GetDataTypeName(int i);
		DateTime GetDateTime(int i);
		double GetDouble(int i);
		Type GetFieldType(int i);
		float GetFloat(int i);
		int GetInteger(int i);
		long GetLong(int i);
		String GetName(int i);
		int GetOrdinal(String& name);
		DataTable GetSchemaTable();
		short GetShort(int i);
		String GetString(int i);
		bool HasRows();

		bool NextResult();

	private:
		String tableName;
		vector<pair<String, Type>> cols;
		MYSQL_STMT* stmt;
		MYSQL_RES* resultset;
		MYSQL_BIND* row;
		char** buffers;
		unsigned long* buffer_lengths;
		unsigned long* lengths;
		my_bool* is_nulls;
		my_bool* errors;

		MySqlDataReader(MYSQL_STMT* stmt, MYSQL_RES* _resultset);
		void LoadColumns();

		void FillTable(DataTable& table);
	};
}