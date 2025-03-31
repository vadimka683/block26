#ifndef CLASSTRACK
#define CLASSTRACK
#include<string>

class MyTrack {
private:
	std::string name;
	std::tm dateCreation;
	time_t trackLeght;
public:
	std::string GetName();
	time_t GetTrackLeght(); 
	std::tm GetDateCreation();
	void SetName(std::string& value);
	void SetTrackLeght(time_t& value);
	void SetDateCreation(tm& value);

};
#endif	

