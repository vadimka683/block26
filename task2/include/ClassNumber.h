#pragma once
#include<string>

class Number {
private:
	std::string phone_number;
public:
	bool Set_number(std::string& value);
	std::string Get_number();
};