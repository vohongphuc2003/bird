#include "Player.h"
#include<iostream>

void Player::Render(SDL_Renderer* ren,SDL_Rect src, SDL_Rect dest)
{
	animationTimer++;
	if (animationTimer < 16)
	{
		SDL_RenderCopyEx(ren, getTexture(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer >= 16 && animationTimer <= 32)
	{
		SDL_RenderCopyEx(ren, Tex1, &src, &dest, 0, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer > 32)
	{
		SDL_RenderCopyEx(ren, Tex2, &src, &dest, 0, NULL, SDL_FLIP_NONE);
	}
	if (animationTimer > 48)
	{
		animationTimer = 0;
	}
}
void Player::Gravity()
{
	if (JumpState())
	{
		accelerator1 = accelerator1 + 0.03;
		accelerator2 = accelerator2 + 0.03;
		jumpHeight = jumpHeight + gravity;
		Ypos = Ypos + gravity + accelerator1 + accelerator2 + jumpHeight;
		setDest(25, Ypos, 28, 38);
        
		if (jumpHeight > 0)
		{
			inJump = false;
			jumpHeight = -6;
		}
	}
	else
	{
		if(Ypos >= 490)
		{
			setDest(25, Ypos, 28, 38);
			return;
		}
		accelerator1 = accelerator1 + 0.03;
		accelerator2 = accelerator2 + 0.03;
		Ypos = Ypos + gravity + accelerator1 + accelerator2;
		setDest(25, Ypos, 28, 38);
	}
}

void Player::Jump()
{
	if (jumpTimer - lastJump > 180)
	{
		accelerator1 = 0;
		accelerator2 = 0;
		inJump = true;
		lastJump = jumpTimer;
	}
	else
	{
		Gravity();
	}
}
void Player::Reset()
{
	accelerator1 = 0;
	accelerator2 = 0;
	Ypos = 256;
	lastJump = 0;
}

void Player::GetJumpTime()
{
	jumpTimer = SDL_GetTicks();
}

bool Player::JumpState()
{
	return inJump;	
}
int Player::getYpos()
{
	return Ypos;
}
void Player::CreateTexture1(const char* address, SDL_Renderer* ren)
{
	Tex1 = TextureManager::Texture(address, ren);
}

void Player::CreateTexture2(const char* address, SDL_Renderer* ren)
{
	Tex2 = TextureManager::Texture(address, ren);
}