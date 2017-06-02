#include "Integer.h"

namespace dnc{

	Integer::Integer(){}

	Integer::Integer(int i): value(i){}

	Integer::Integer(Object & o){
		Integer& in_ref = (Integer&)o;

		this->value = in_ref.value;
	}


	Integer::~Integer(){}

	std::string Integer::ToString(){
		return std::to_string(this->value);
	}

	std::string Integer::GetTypeString(){
		return std::string("Integer");
	}

	Integer Integer::operator=(int i){
		this->value = i;

		return *this;
	}

	Integer::operator int(){
		return this->value;
	}
}