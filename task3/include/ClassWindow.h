#ifndef WINDOW
#define WINDOW
#include<vector>

class Window
{
private:
	std::vector<int> cordsX_Y = { 0,0 };
	std::vector<int> windowSizeH_W = { 0,0 };
public:
	std::vector<int> get_cords();
	std::vector<int> get_size();
	bool set_cords(std::vector<int>& win_cords, std::vector<int>& win_size);
	void move();
	void resize();
};
#endif