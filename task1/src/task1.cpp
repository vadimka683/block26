#include "ClassPlayer.h"
#include<iostream>

using namespace std;

int main()
{
	Player* player = new Player;
	while (true) {
		std::cout << "Input number comand: 1.Input songs 2.Play 3.Pause 4.Next 5.Stop 6.Exit";
		int answer;
		std::cin >> answer;
		if (answer == 1) {
			player->inputBuffer();
		}
		else if (answer == 2) {
			player->play();
		}
		else if (answer == 3) {
			player->pause();
		}
		else if (answer == 4) {
			player->next();
		}
		else if (answer == 5) {
			player->stop();
		}
		else if (answer == 6) {
			break;
		}
		else {
			std::cout << "Error comand\n";
		}
	}
}
