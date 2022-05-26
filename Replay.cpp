#include"Replay.h"
Replay::Replay()
{
    isClicked = false;
}
void Replay::Initialize(SDL_Renderer* ren)
{
    replayBackground.CreateTexture("Image/Replay.jpg", ren);
}
void Replay::Render(SDL_Renderer* ren)
{
    SDL_RenderClear(ren);
	replayBackground.GroundRender(ren);
	SDL_RenderPresent(ren);
}
int Replay::EventHandling(SDL_Event& e)
{
    SDL_PollEvent(&e);
	if (e.type == SDL_QUIT)
	{
		return -1;
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 285 && e.motion.x < 510 && e.motion.y > 395 && e.motion.y < 460)
	{
        isClicked = true;
        return 1;
	}
    else if(e.type == SDL_MOUSEBUTTONDOWN && e.motion.x > 285 && e.motion.x < 510 && e.motion.y > 470 && e.motion.y < 535)
    {
        isClicked = true;
        return -1;
    }
	return 0;
}
bool Replay::getClicked()
{
    return isClicked;
}
void Replay::reset()
{
    isClicked = false;
}