#include "ClassTrack.h"
#include<string>
#include<iostream>
#include<ctime>

std::string MyTrack::GetName(){
	return name;
}

time_t MyTrack::GetTrackLeght() {
	return trackLeght;
}

std::tm MyTrack::GetDateCreation() {
	return dateCreation;
}

void MyTrack::SetName(std::string& value) {
	name = value;
}

void MyTrack::SetTrackLeght(time_t& value) {
	if (value < 0 || (value / 60) > 10) {
		std::cout << "Error Track Leght\n";
		return;
	}
	trackLeght = value;
}
void MyTrack::SetDateCreation(std::tm& value) {
	dateCreation = value;
}