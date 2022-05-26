//class hiện thị menu
#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"Background.h"

class MainMenu
{
private:
	//biến click vào nút chưa
	bool isClicked;
	//biến màn hình menu
	Background menuBackground;
public:
	//khởi tạo menu
	MainMenu();
	~MainMenu();
	//hàm khởi tạo tex
	void Initialize(SDL_Renderer* ren);
	//hàm sự kiện ấn nút
	int EventHandling(SDL_Event& e);
	//hàm vẽ
	void Render(SDL_Renderer* ren);
	//trả về isClicked
	bool getClicked();
	//hàm reset
    void reset();
};
