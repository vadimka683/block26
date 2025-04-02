#pragma once
#include "ClassWindow.h"

class Monitor
{
private:
	Window* window;
public:
	void set_window(Window* temp);
	void display();
};