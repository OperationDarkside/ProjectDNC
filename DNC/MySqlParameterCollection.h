#pragma once

#ifndef MYSQLPARAMETERCOLLECTION_H
#define MYSQLPARAMETERCOLLECTION_H

#include "MySqlParameter.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			class MySqlParameterCollection: public Object{
			public:
				MySqlParameterCollection();
				~MySqlParameterCollection();

				std::string ToString() override;
				std::string GetTypeString() override;

				friend class DataTable;

				/**
				Adds a MySqlParameter instance to this collection

				@param The MySqlParameter to be added
				*/
				void Add(MySqlParameter& parameter);
				/**
				Removes all MySqlParameters from this instance
				*/
				void Clear();
				/**
				Returns the amount of MySqlParameters in this collection

				@return The row count
				*/
				long Count();
				/**
				Returns the index of the given MySqlParameter instance in this collection
				*/
				int IndexOf(MySqlParameter& parameter);
				/**
				Inserts the given MySqlParameter at the given position
				*/
				void InsertAt(MySqlParameter& parameter, int pos);

				MySqlParameter& operator[](int columnNr);

			private:
				Collections::Generic::List<MySqlParameter> parameters;
			};
		}
	}
}
#endif // !MYSQLPARAMETERCOLLECTION_H