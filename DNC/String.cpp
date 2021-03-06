#include "String.h"

namespace dnc{

	String::String(){}

	String::String(const String & str): value(str.value){}

	String::String(String && str) : value(std::move(str.value)){}

	String::String(String * str){
		this->value = str->value;
	}

	/*String::String(Object & str){
		//String& strRef = (String&)str;

		this->value = str.ToString();
	}*/

	String::String(std::string & str){
		this->value = str;
	}

	String::String(const char * str){
		this->value = str;
	}


	String::~String(){}

	String String::Clone(){
		return String(this->value);
	}

	std::string String::GetStringValue(){
		return value;
	}

	int String::CompareTo(String * str){
		int res = this->value.compare(str->value);
		return res;
	}

	bool String::Contains(String str){
		size_t pos = value.find(str.value);

		if(pos != std::string::npos){
			return true;
		} else{
			return false;
		}
	}

	void String::CopyTo(unsigned int sourceIndex, String * destination, unsigned int destinationIndex, unsigned int count){
		std::string buf = this->value.substr(sourceIndex, count);
		destination->value.insert(destinationIndex, buf);
	}

	bool String::EndsWith(String * str){
		size_t lenEnding = 0;
		size_t lenValue = 0;

		lenEnding = str->value.size();
		lenValue = this->value.size();

		if(lenEnding > lenValue){
			return false;
		} else{
			if(this->value.compare(lenValue - lenEnding, lenEnding, str->value) == 0){
				return true;
			} else{
				return false;
			}
		}

		return false;
	}

	unsigned int String::IndexOf(char c){
		size_t found = 0;

		found = this->value.find(c);

		if(found == std::string::npos){
			return -1;
		}

		return found;
	}

	unsigned int String::IndexOf(char c, unsigned int startIndex){
		size_t found = 0;

		found = this->value.find(c, startIndex);

		if(found == std::string::npos){
			return -1;
		}

		return found;
	}

	unsigned int String::IndexOf(char c, unsigned int startIndex, unsigned int count){
		size_t found = 0;

		found = this->value.find(c, startIndex);

		if(found == std::string::npos){
			return -1;
		}
		if(found > (startIndex + count)){
			return -1;
		}
		return found;
	}

	unsigned int String::IndexOf(String * str){
		size_t found = 0;

		found = this->value.find(str->value);

		if(found == std::string::npos){
			return -1;
		}

		return found;
	}

	unsigned int String::IndexOf(String * str, unsigned int startIndex){
		size_t found = 0;

		found = this->value.find(str->value, startIndex);

		if(found == std::string::npos){
			return -1;
		}

		return found;
	}

	unsigned int String::IndexOf(String * str, unsigned int startIndex, unsigned int count){
		size_t found = 0;

		found = this->value.find(str->value, startIndex);

		if(found == std::string::npos){
			return -1;
		}
		if(found > (startIndex + count)){
			return -1;
		}
		return found;
	}

	String String::Insert(unsigned int startIndex, String * str){
		this->value.insert(startIndex, str->value);
		return this;
	}

	String String::Join(String separator, dnc::Collections::Generic::List<String> vals){
		std::ostringstream s;
		std::vector<String> tmp;
		String res;

		tmp = vals.Vector();

		std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<std::string>(s, separator.ToCharArray()));

		res = s.str();

		res = res.Substring(0, res.Length() - separator.Length());

		return res;
	}

	unsigned int String::LastIndexOf(char c){
		size_t found = this->value.find_last_of(c);
		if(found == std::string::npos){
			return -1;
		}

		return found;
	}

	unsigned int String::LastIndexOf(char c, unsigned int startIndex){
		size_t found = this->value.find_last_of(c, startIndex);
		if(found == std::string::npos){
			return -1;
		}

		return found;
	}

	unsigned int String::LastIndexOf(char c, unsigned int startIndex, unsigned int count){
		size_t found = this->value.find_last_of(new char[1]{c}, startIndex, count);
		if(found == std::string::npos){
			return -1;
		}

		return found;
	}

	unsigned int String::LastIndexOf(String * str){
		size_t found = this->value.rfind(str->value);
		if(found == std::string::npos){
			return -1;
		}

		return found;
	}

	unsigned int String::LastIndexOf(String * str, unsigned int startIndex){
		size_t found = this->value.rfind(str->value, startIndex);
		if(found == std::string::npos){
			return -1;
		}

		return found;
	}

	unsigned int String::LastIndexOf(String * str, unsigned int startIndex, unsigned int count){
		size_t found = this->value.rfind(str->value, startIndex);
		if(found == std::string::npos){
			return -1;
		}
		if(found > (startIndex - str->value.size()) && found < (startIndex - count + str->value.size())){
			return -1;
		}

		return found;
	}

	unsigned int String::Length(){
		return this->value.length();
	}

	String String::PadLeft(int totalWidth){
		int len = 0;

		len = this->value.size();

		if(totalWidth > len){
			this->value.insert(0, totalWidth - len, ' ');
		}

		return this;
	}

	String String::PadLeft(int totalWidth, char paddingChar){
		int len = 0;

		len = this->value.size();

		if(totalWidth > len){
			this->value.insert(0, totalWidth - len, paddingChar);
		}

		return this;
	}

	String String::PadRight(int totalWidth){
		int len = 0;

		len = this->value.size();

		if(totalWidth > len){
			this->value.insert(len, totalWidth - len, ' ');
		}

		return this;
	}

	String String::PadRight(int totalWidth, char paddingChar){
		int len = 0;

		len = this->value.size();

		if(totalWidth > len){
			this->value.insert(len, totalWidth - len, paddingChar);
		}

		return this;
	}

	String String::Remove(unsigned int startIndex){
		this->value.erase(startIndex);

		return this;
	}

	String String::Remove(unsigned int startIndex, unsigned int count){
		this->value.erase(startIndex, count);

		return this;
	}

	String String::Replace(char oldChar, char newChar){
		std::replace(this->value.begin(), this->value.end(), oldChar, newChar);

		return this;
	}

	String String::Replace(String * oldString, String * newString){
		size_t startPos = 0;

		while((startPos = this->value.find(oldString->value, startPos)) != std::string::npos){
			this->value.replace(startPos, oldString->value.length(), newString->value);
			//startPos += newString->value.length();
			startPos += 1;
		}

		return this;
	}

	Collections::Generic::List<String> String::Split(char separator){
		std::string str;
		std::stringstream ss;
		Collections::Generic::List<String> res;
		//String* s;


		ss.str(this->value);

		while(std::getline(ss, str, separator)){
			res.Add(String(str));
		}

		return res;
	}

	Collections::Generic::List<String> String::Split(String separator){
		size_t currentPos = 0;
		size_t oldPos = 0;
		size_t len = 0;
		Collections::Generic::List<String> res;

		len = this->value.length();

		while((currentPos = this->value.find(separator.value, currentPos)) != std::string::npos){
			res.Add(String(this->value.substr(oldPos, currentPos - oldPos)));
			currentPos += separator.value.length();
			oldPos = currentPos;
		}


		if(oldPos < len){
			res.Add(new String(this->value.substr(oldPos, len - oldPos)));
		}

		return res;
	}

	bool String::StartsWith(String str){
		if(this->value.compare(0, str.value.size(), str.value) == 0){
			return true;
		} else{
			return false;
		}
	}

	String String::Substring(unsigned int startIndex){
		return String(this->value.substr(startIndex));
	}

	String String::Substring(unsigned int startIndex, unsigned int length){
		return String(this->value.substr(startIndex, length));
	}

	char * String::ToCharArray(){
		size_t len = 0;
		char* target;

		len = this->value.length();
		target = new char[len + 1];

		//std::copy(this->value.begin(), this->value.begin(), target);
		for(size_t i = 0; i < len; ++i){
			target[i] = this->value[i];
		}
		target[len] = '\0';

		return target;
	}

	char * String::ToCharArray(unsigned int startIndex, unsigned int length){
		char* target;
		std::string buf;

		buf = this->value.substr(startIndex, length);
		target = new char[length + 1];

		//std::copy(buf.begin(), buf.begin(), target);
		for(unsigned int i = 0; i < length; ++i){
			target[i] = buf[i];
		}
		target[length] = '\0';

		return target;
	}

	String String::ToLower(){
		std::locale loc;
		String target;


		for(std::string::size_type i = 0; i < this->value.length(); i++){
			target.value += std::tolower(this->value[i], loc);
		}

		return target;
	}

	std::string String::ToString(){
		return this->value;
	}

	std::string String::GetTypeString(){
		std::string res("String");

		return res;
	}

	String String::ToUpper(){
		std::locale loc;
		String target;


		for(std::string::size_type i = 0; i < this->value.length(); i++){
			target.value += std::toupper(this->value[i], loc);
		}

		return target;
	}

	String String::Trim(){
		size_t first = 0;
		size_t last = 0;

		first = this->value.find_first_not_of(' ');
		if(std::string::npos == first){
			return this;
		}
		last = this->value.find_last_not_of(' ');
		this->value = this->value.substr(first, (last - first + 1));
		return this;
	}

	String String::TrimEnd(){
		size_t last = 0;

		last = this->value.find_last_not_of(' ');
		this->value = this->value.substr(0, last + 1);
		return this;
	}

	String String::TrimStart(){
		size_t first = 0;

		first = this->value.find_first_not_of(' ');
		if(std::string::npos == first){
			return this;
		}
		this->value = this->value.substr(first);
		return this;
	}

	// Operators

	String operator+(String str1, String str2){
		//String res(str1.value + str2.value);
		str1 += str2;
		return str1;
	}

	/*String operator+(String str1, const char * str2){
		str1 += str2;

		return str1;
	}

	String operator+(const char * str, String str2){
		const char* bla1 = "dfgdfg";
		std::string bla2 = "dfsgf";
		bla2 = bla1 + bla2;
		//str2.value = str + str2.value;
		//str2 += str;
		//String res = str;

		return str2;
	}*/

	/*String operator+(std::string & str, String str2){
		str2.value = str + str2.value;

		return str2;
	}*/

	/*String operator+(String str, std::string & str2){
		str += str2;

		return str;
	}*/

	/*String operator+(String& str, int number){
		str += std::to_string(number);

		return str;
	}

	String operator+(int number, String & str){
		str.value = std::to_string(number) + str.value;

		return str;
	}

	String operator+(String & str, unsigned long long number) {
		str += std::to_string(number);

		return str;
	}

	String operator+(unsigned long long number, String & str) {
		str.value = std::to_string(number) + str.value;

		return str;
	}*/

	String String::operator+=(String& str){
		this->value += str.value;

		return *this;
	}

	String String::operator+=(std::string& str){
		this->value += str;

		return *this;
	}

	String String::operator+=(const char * str){
		this->value += str;

		return *this;
	}

	String String::operator+=(char str) {
		value += str;
		return *this;
	}

	/*String String::operator+=(int number){
		this->value += std::to_string(number);

		return *this;
	}*/

	bool String::operator==(String & str){
		return (this->value.compare(str.value) == 0);
	}

	bool String::operator==(const char * str){
		std::string tmp1(str);

		return (this->value.compare(tmp1) == 0);
	}

	bool String::operator!=(String & str){
		return (this->value.compare(str.value) != 0);
	}

	bool String::operator!=(const char * str){
		std::string tmp1(str);

		return (this->value.compare(tmp1) != 0);
	}

	String String::operator=(const char * str){
		this->value = str;

		return *this;
	}

	String String::operator=(const std::string & str){
		this->value = str;

		return *this;
	}

	String & String::operator=(String& str){
		if(this != &str){
			std::swap(this->value, str.value);
		}

		return *this;
	}
	String & String::operator=(String && str){
		this->value = std::move(str.value);
		return *this;
	}
	String::operator std::string(){
		return this->value;
	}

	char String::operator[](unsigned int index) {
		return this->value[index];
	}

	void String::FromString(std::string val) {
		this->value = val;
	}

}