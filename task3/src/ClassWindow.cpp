#include "ClassWindow.h"
#include<vector>
#include<iostream>

std::vector<int> Window::get_cords() {
	return cordsX_Y;
}
std::vector<int> Window::get_size() {
	return windowSizeH_W;
}
bool Window::set_cords(std::vector<int>& win_cords, std::vector<int>& win_size) {
	if (win_cords[0] < 0 || win_cords[1] < 0 || win_size[0] < 0 || win_size[1] < 0) {
		return false;
	}
	if (win_cords[0] + win_size[1] > 79 || win_cords[1] + win_size[0] > 49 ) {
		return false;
	}
	cordsX_Y = win_cords;
	windowSizeH_W = win_size;
	return true;
}

void Window::move() {
	std::cout << "Input coordinates vector for move X and Y: ";
	int move_X, move_Y;
	std::cin >> move_X >> move_Y;
	std::vector<int> temp = { cordsX_Y[0] + move_X, cordsX_Y[1] + move_Y};
	if (!set_cords(temp, windowSizeH_W)) {
		std::cout << "Imposible move\n";
		return;
	}
}

void Window::resize() {
	std::cout << "Input new height and widht: ";
	int height, weidht;
	std::cin >> height >> weidht;
	std::vector<int> temp = { height, weidht };
	if (!set_cords(cordsX_Y, temp)) {
		std::cout << "Imposible size\n";
		return;
	}
}