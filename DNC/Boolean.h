#include "Object.h"
#include "String.h"

#pragma once
namespace dnc{
	/**
	Object related wrapper for primitive bool type
	*/
	class Boolean: public Object{
	public:
		Boolean();
		Boolean(bool b);
		~Boolean();

		std::string toString();
		std::string getTypeString();

		Boolean operator=(bool b);
		operator bool();
	private:
		bool value;
	};
}