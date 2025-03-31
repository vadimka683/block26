#include "ClassPlayer.h"
#include "ClassTrack.h"
#include<map>
#include<iostream>
#include<sstream>
#include<ctime>
#include<iomanip>

void Player::inputBuffer() {
	std::cin.clear();
	std::cin.ignore();
	do {
		shuffleMode = false;
		std::cout << "Input the track name and its length in sec or exit: ";
		std::string answer;
		getline(std::cin, answer);
		std::stringstream answer1(answer);
		std::string name;
		time_t leght;
		answer1 >> name >> leght;
		if (name == "exit") {
			break;
		}
		MyTrack* track = new MyTrack;
		track->SetName(name);
		if (!track->SetTrackLeght(leght)) {
			continue;
		}
		time_t temp = time(nullptr);
		tm realtime;
		localtime_s(&realtime, &temp);
		track->SetDateCreation(realtime);
		buffer.insert(make_pair(name,*track));
	} while (true);
}

void Player::songSelection() {
	if (!shuffleMode) {
		std::cout << "Input the title of the song: ";
		std::string answer;
		std::cin >> answer;
		std::map<std::string, MyTrack>::iterator it = buffer.find(answer);
		if (it == buffer.end()) {
			std::cout << "Imposible song title\n";
			return;
		}
		std::string name = it->second.GetName();
		trackPlayNow->SetName(name);
		time_t temp = it->second.GetTrackLeght();
		trackPlayNow->SetTrackLeght(temp);
		std::tm temp1 = it->second.GetDateCreation();
		trackPlayNow->SetDateCreation(temp1);
	}
	else {
		srand(time(nullptr));
		int shift = rand() % buffer.size();
		std::map<std::string, MyTrack>::iterator it = buffer.begin();
		std::advance(it, shift);
		std::string name = it->second.GetName();
		trackPlayNow->SetName(name);
		time_t temp = it->second.GetTrackLeght();
		trackPlayNow->SetTrackLeght(temp);
		std::tm temp1 = it->second.GetDateCreation();
		trackPlayNow->SetDateCreation(temp1);
	}
}

void Player::playing() {
	pauseON = false;
	trackPlayNow = new MyTrack;
	songSelection();
	tm temp = trackPlayNow->GetDateCreation();
	std::cout << "Playing: " << trackPlayNow->GetName() << " Made in: "
		<< std::put_time(&temp,"%d/%m/%Y %H:%M")
		<< " Song leght: " << trackPlayNow->GetTrackLeght() / 60 << ":"
		<< trackPlayNow->GetTrackLeght() % 60 << "\n";
}
void Player::play() {
	shuffleMode = false;
	playing();
}
void Player::next() {
	shuffleMode = true;
	playing();
}
void Player::pause() {
	if (pauseON) {
		return;
	}
	pauseON = true;
	std::cout << "Pause!\n";
}
void Player::stop() {
	if (trackPlayNow == nullptr) {
		std::cout << "You can't stop it twice\n";
		return;
	}
	delete trackPlayNow;
	std::cout << "Stop!\n";
	trackPlayNow = nullptr;
}
