#include "Phone.h"
#include<iostream>

int main(){
	Phone* newPhone = new Phone;
	while (true) {
		std::cout << "Input number comand: 1.add 2.call 3.sms 4.exit ";
		int answer;
		std::cin >> answer;
		if (answer == 1) {
			newPhone->add();
		}
		else if (answer == 2) {
			newPhone->call();
		}
		else if (answer == 3) {
			newPhone->sms();
		}
		else if (answer == 4) {
			delete newPhone;
			newPhone = nullptr;
			break;
		}
	}
}