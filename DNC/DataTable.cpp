#include "DataTable.h"

namespace dnc::Data{

	DataTable::DataTable(){
		this->columns.table = this;
	}

	DataTable::DataTable(const char * name){
		this->name = name;
		this->columns.table = this;
	}

	DataTable::DataTable(String & name){
		this->name = name;
		this->columns.table = this;
	}


	DataTable::~DataTable(){
		this->Clear();
	}

	string DataTable::toString(){
		return string("System.Data.DataTable");
	}

	string DataTable::getTypeString(){
		return string("DataTable");
	}

	DataRow DataTable::NewRow(){
		DataRow* row;

		row = new DataRow(&this->columns);

		return *row;
	}

	void DataTable::Clear(){
		this->columns.Clear();
		this->rows.Clear();
	}

	String DataTable::TableName(){
		return this->name;
	}

	void DataTable::TableName(String & name){
		this->name = name;
	}

	DataColumnCollection& DataTable::Columns(){
		return this->columns;
	}

	DataRowCollection& DataTable::Rows(){
		return this->rows;
	}

	DataRow & DataTable::operator[](unsigned int rowIndex){
		return this->rows[rowIndex];
	}

	void DataTable::RemoveColumn(size_t index){
		size_t len = 0;

		len = this->rows.rows.size();

		for(size_t i = 0; i < len; i++){
			this->rows.rows[i].RemoveItem(index);
		}
	}
}