#ifndef CLASSPLAYER
#define CLASSPLAYER
#include "ClassTrack.h"
#include<map>

class Player {
private:
	std::map<std::string, MyTrack> buffer;
	MyTrack* trackPlayNow;
	bool shuffleMode;
	bool pauseON = false;
public:
	void inputBuffer();
	void songSelection();
	void playing();
	void play();
	void next();
	void pause();
	void stop();
};
#endif 
