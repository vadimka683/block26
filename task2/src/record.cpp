#include "record.h"
#include<string>
#include<map>
#include "ClassNumber.h"
#include<iostream>
#include<sstream>

void Record::input_record() {
	std::string name;
	std::string number;
	std::string answer;
	std::cin.clear();
	std::cin.ignore();
	std::cout << "Input name and phone number format(+7): ";
	getline(std::cin, answer);
	std::stringstream answer1(answer);
	answer1 >> name >> number;
	Number* new_number = new Number;
	if (!new_number->Set_number(number)) {
		std::cout << "Error number\n";
	}
	phone_record.first = name;
	phone_record.second = *new_number;
	phone_record_revers.first = new_number->Get_number();
	phone_record_revers.second = name;
	delete new_number;
	new_number = nullptr;
}

std::pair<std::string, Number> Record::getPhoneRecord() {
	return phone_record;
}

std::pair<std::string, std::string> Record::getPhoneRecordRevers() {
	return phone_record_revers;
}