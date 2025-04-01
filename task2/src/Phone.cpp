#include "Phone.h"
#include "record.h"
#include "ClassNumber.h"
#include<map>
#include<iostream>

void Phone::add() {
	Record* record_temp = new Record;
	record_temp->input_record();
	std::pair<std::string, Number> temp = record_temp->getPhoneRecord();
	records.insert(temp);
	std::pair<std::string, std::string> temp1 = record_temp->getPhoneRecordRevers();
	record_revers.insert(temp1);
	delete record_temp;
	record_temp = nullptr;
}

void Phone::call() {
	std::cout << "Input name or phone number format (+7): ";
	std::string answer;
	std::cin >> answer;
	if (answer[0] == '+') {
		std::map<std::string, std::string>::iterator it = record_revers.find(answer);
		if (it == record_revers.end()) {
			std::cout << "Error number\n";
			return;
		}
		std::cout << "CALL: " << it->second << " " << it->first << "\n";
	}
	else {
		std::map<std::string, Number>::iterator it = records.find(answer);
		if (it == records.end()) {
			std::cout << "Error number\n";
			return;
		}
		std::cout << "CALL: " << it->first << " " << it->second.Get_number() << "\n";
	}
}

void Phone::sms() {
	std::cout << "Input name or phone number format (+7): ";
	std::string answer;
	std::cin >> answer;
	std::cout << "Input text sms: ";
	std::string sms;
	getline(std::cin, sms);
	if (answer[0] == '+') {
		std::map<std::string, std::string>::iterator it = record_revers.find(answer);
		if (it == record_revers.end()) {
			std::cout << "Error number\n";
			return;
		}
		std::cout << "SMS: " << it->second << " " << it->first << " " << sms;
	}
	else {
		std::map<std::string, Number>::iterator it = records.find(answer);
		if (it == records.end()) {
			std::cout << "Error number\n";
			return;
		}
		std::cout << "SMS: " << it->first << " " << it->second.Get_number() << " " << sms;
	}
}