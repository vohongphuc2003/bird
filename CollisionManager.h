//Class va chạm
#pragma once
#include<SDL.h>
#include<SDL_image.h>

class CollisionManager
{
public:
	//hàm cho bt điểm cắt 2 HCN
	static bool CheckCollision(SDL_Rect* A, SDL_Rect* B);
};