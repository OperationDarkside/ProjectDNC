#include "Convert.h"

namespace dnc{

	Convert::Convert(){}


	Convert::~Convert(){}

	bool Convert::toBoolean(bool value){
		return value;
	}

	bool Convert::toBoolean(char value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(double value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(float value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(short value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(int value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(long value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(unsigned short value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(unsigned int value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(unsigned long value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(Object* value){
		if(value == nullptr){
			return false;
		}

		return true;
	}

	bool Convert::toBoolean(String & value){
		String* tmp = &value.ToLower();
		if(*tmp == "true"){
			return true;
		} else if(*tmp == "false"){
			return false;
		} else{
			std::cerr << "wrong format" << std::endl;
		}

		return false;
	}

	DateTime Convert::toDateTime(String & value){
		unsigned short year = 0;
		unsigned short month = 0;
		unsigned short day = 0;
		unsigned short hour = 0;
		unsigned short min = 0;
		unsigned short sec = 0;
		unsigned short ms = 0;
		Collections::Generic::List<String> dates;
		Collections::Generic::List<String> times;
		Collections::Generic::List<String> tmp;
		DateTime* dt;

		try{
			tmp = value.Split('T');
			dates = tmp[0].Split('-');
			times = tmp[1].Split(':');

			if(dates.Count() == 3 && times.Count() == 4){
				year = std::stoi(dates[0].GetStringValue().c_str());
				month = std::stoi(dates[1].GetStringValue().c_str());
				day = std::stoi(dates[2].GetStringValue().c_str());
				hour = std::stoi(times[0].GetStringValue().c_str());
				min = std::stoi(times[1].GetStringValue().c_str());
				sec = std::stoi(times[2].GetStringValue().c_str());
				ms = std::stoi(times[3].GetStringValue().c_str());

				dt = new DateTime(year, month, day, hour, min, sec, ms);

				return *dt;
			} else{
				std::cerr << "Wrong format";
			}
		} catch(std::exception ex){
			std::cerr << ex.what();
		}

		return NULL;
	}

	double Convert::toDouble(String & value){
		double res = 0;

		res = std::stod(value.GetStringValue().c_str());

		return res;
	}

	float Convert::toFloat(String & value){
		float res = 0;

		res = std::stof(value.GetStringValue().c_str());

		return res;
	}

	int Convert::toInt(String & value){
		int res = 0;

		res = std::stoi(value.GetStringValue().c_str());

		return res;
	}

	long Convert::toLong(String & value){
		long res = 0;

		res = std::stol(value.GetStringValue().c_str());

		return res;
	}

	String Convert::toString(bool value){
		String res(value ? "true" : "false");

		return res;
	}

	String Convert::toString(char value){
		return String(std::string(&value));
	}

	String Convert::toString(double value){
		return String(std::to_string(value));
	}

	String Convert::toString(float value){
		return String(std::to_string(value));
	}

	String Convert::toString(short value){
		return String(std::to_string(value));
	}

	String Convert::toString(int value){
		return String(std::to_string(value));
	}

	String Convert::toString(long value){
		return String(std::to_string(value));
	}

	String Convert::toString(long long value){
		return String(std::to_string(value));
	}

	String Convert::toString(unsigned short value){
		return String(std::to_string(value));
	}

	String Convert::toString(unsigned int value){
		return String(std::to_string(value));
	}

	String Convert::toString(unsigned long value){
		return String(std::to_string(value));
	}

	String Convert::toString(Object * value){
		return String(value->ToString());
	}

	String Convert::toString(DateTime & value){
		return String(value.ToString());
	}
}