#ifndef PHONE
#define PHONE
#include<map>
#include<string>
#include "ClassNumber.h"

class Phone {
private:
	std::map<std::string, Number> records;
	std::map<std::string, std::string> record_revers;
public:
	void add();
	void call();
	void sms();
};
#endif