#include "ClassWindow.h"
#include "ClassMonitor.h"
#include<iostream>

void Monitor::set_window(Window* temp) {
	window = temp;
}
void Monitor::display() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 80; j++) {
			if ((j > window->get_cords()[0] && j <= window->get_cords()[0] + window->get_size()[1]) &&
					(i > window->get_cords()[1] && i <= window->get_cords()[1] + window->get_size()[0])) {
				std::cout << "1";
			}
			else {
				std::cout << "0";
			}
		}
		std::cout << "\n";
	}
}