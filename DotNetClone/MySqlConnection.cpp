#include "MySqlConnection.h"
#include "Convert.h"



MySqlConnection::MySqlConnection(){}

MySqlConnection::MySqlConnection(String & conString){
	this->ConnectionString(conString);
}

MySqlConnection::~MySqlConnection(){}

string MySqlConnection::toString(){
	return string("System.Data.MySqlClient.MySqlConnection");
}

string MySqlConnection::getTypeString(){
	return string("MySqlConnection");
}

void MySqlConnection::Close(){
	// this->conn.disconnect();
}

MySqlCommand MySqlConnection::CreateCommand(){
	return MySqlCommand(String(), this);
}

void MySqlConnection::Open(){
	int indexColon;
	int port = 0;
	String address;
	String host;
	String portStr;
	String db;
	String uname;
	String pw;
	String conStr;
	vector<String*> conKeyValues;

	conStr = this->ConnectionString();

	if(conStr == ""){
		throw "Connection string is empty";
	}

	conKeyValues = conStr.split(';');

	if(conKeyValues.size() != 4){
		throw "Not enough parameter in the connection string";
	}

	address = conKeyValues[0]->substring(7);
	indexColon = address.indexOf(':');

	if(indexColon == -1){
		port = 3306;
	} else{
		portStr = address.substring(indexColon + 1, address.length() - indexColon);
		port = Convert::toInt(portStr);
	}

	host = address.substring(0, indexColon);
	db = conKeyValues[1]->substring(9);
	uname = conKeyValues[2]->substring(4);
	pw = conKeyValues[3]->substring(9);

	this->connection = mysql_init(NULL);

	this->connection = mysql_real_connect(this->connection, host.toCharArray(), uname.toCharArray(), pw.toCharArray(), db.toCharArray(), port, NULL, 0);

	if(!this->connection){
		cerr << mysql_error(this->connection);
		mysql_close(this->connection);
		throw "Establishing a connection failed!";
	}
}
