#include "ClassNumber.h"
#include<string>

bool Number::Set_number(std::string& value) {
	if (value[0] != '+' || value.length() != 12) {
		return false;
	}
	phone_number = value;
	return true;
}

std::string Number::Get_number() {
	return phone_number;
}