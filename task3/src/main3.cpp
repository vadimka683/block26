#include "ClassMonitor.h"
#include "ClassWindow.h"
#include<iostream>

int main()
{
	Window* win = new Window;
	while (true) {
		int answer;
		std::cout << "Input number comand: 1.Display 2.Move 3.Resize 4.Close: ";
		std::cin >> answer;
		if (answer == 1) {
			Monitor* mon = new Monitor;
			mon->set_window(win);
			mon->display();
			delete mon;
		}
		else if (answer == 2) {
			win->move();
		}
		else if (answer == 3) {
			win->resize();
		}
		else if (answer == 4) {
			delete win;
			win = nullptr;
			break;
		}
		else {
			continue;
		}
	}
}
