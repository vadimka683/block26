#ifndef RECORD
#define RECORD
#include<map>
#include<string>
#include "ClassNumber.h"

class Record {
private:
	std::pair<std::string, Number> phone_record;
	std::pair<std::string, std::string> phone_record_revers;
public:
	void input_record();
	std::pair<std::string, Number> getPhoneRecord();
	std::pair<std::string, std::string> getPhoneRecordRevers();
};
#endif 
