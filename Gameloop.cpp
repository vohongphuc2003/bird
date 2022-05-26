#include"Gameloop.h"
#include<iostream>
using namespace std;

Gameloop::Gameloop()
{
    window = NULL;
	renderer = NULL;
	GameState = false;
	GameIsPlay = false;
	p.setSrc(0, 0, 24, 32);
	p.setDest(25, HEIGHT/2, 28, 38);
	ground1.setSrc(0, 0, 112, 336);
	ground1.setDest(0, 520, 112, 805);
	ground2.setSrc(0, 0, 112, 336);
	ground2.setDest(805, 520, 112, 805);
	Pipe_Above1.setSrc(0, 0, 320, 52);
	Pipe_Above1.setDest(400, -200, 400, 52);
	Pipe_Below1.setSrc(0, 0, 320, 52);
	Pipe_Below1.setDest(400, 350, 400, 52);
	Pipe_Above2.setSrc(0, 0, 320, 52);
	Pipe_Above2.setDest(700, -200, 400, 52);
	Pipe_Below2.setSrc(0, 0, 320, 52);
	Pipe_Below2.setDest(700, 350, 400, 52);
	Pipe_Above3.setSrc(0, 0, 320, 52);
	Pipe_Above3.setDest(1000, -200, 400, 52);
	Pipe_Below3.setSrc(0, 0, 320, 52);
	Pipe_Below3.setDest(1000, 350, 400, 52);
	for (int i = 0; i < 10; i++)
	{
		a[i].setSrc(0,0,800,600);
	}
	number1.x = 390, number1.y = 30, number1.w = 25, number1.h = 50;
	number2.x = 371, number2.y = 30, number2.w = 25, number2.h = 50;
	number3.x = 404, number3.y = 30, number3.w = 25, number3.h = 50;
}
bool Gameloop::getGameState()
{
    return GameState;
}
bool Gameloop::getGameIsPlay()
{
	return GameIsPlay;
}
void Gameloop::Intialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    if(window)
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            b.CreateTexture("Image/back.png", renderer);
            ground1.CreateTexture("Image/base.png", renderer);
			ground2.CreateTexture("Image/base.png", renderer);
            p.CreateTexture("Image/yellowbird1.png", renderer);
			p.CreateTexture1("Image/yellowbird2.png", renderer);
			p.CreateTexture2("Image/yellowbird3.png", renderer);
			Pipe_Above1.CreateTexture("Image/Pipe_Above.png", renderer);
			Pipe_Below1.CreateTexture("Image/Pipe_Below.png", renderer);
			Pipe_Above2.CreateTexture("Image/Pipe_Above.png", renderer);
			Pipe_Below2.CreateTexture("Image/Pipe_Below.png", renderer);
			Pipe_Above3.CreateTexture("Image/Pipe_Above.png", renderer);
			Pipe_Below3.CreateTexture("Image/Pipe_Below.png", renderer);
			replay.Initialize(renderer);
			menu.Initialize(renderer);
			a[0].CreateTexture("image/0.png", renderer);
			a[1].CreateTexture("image/1.png", renderer);
			a[2].CreateTexture("image/2.png", renderer);
			a[3].CreateTexture("image/3.png", renderer);
			a[4].CreateTexture("image/4.png", renderer);
			a[5].CreateTexture("image/5.png", renderer);
			a[6].CreateTexture("image/6.png", renderer);
			a[7].CreateTexture("image/7.png", renderer);
			a[8].CreateTexture("image/8.png", renderer);
			a[9].CreateTexture("image/9.png", renderer);
			if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
			return;
			SoundPunch = Mix_LoadWAV("sound/punch.wav");
			SoundPoint = Mix_LoadWAV("sound/ting.wav");
			if(SoundPunch == NULL || SoundPoint == NULL)
			{
				cerr << -1 ;
				return;
			}
        }
    }
}
int k = 0;
void Gameloop::MainMenu()
{
	while (!menu.getClicked())
	{
		int Clicked = menu.EventHandling(event1);
		if ( Clicked== -1)
		{
			GameState = GameIsPlay = false;
			break;
		}
		else if(Clicked == 1)GameIsPlay = GameState = true;
		SDL_RenderClear(renderer);
		menu.Render(renderer);
		SDL_RenderPresent(renderer);
	}
}
void Gameloop::Replay()
{
	while (!replay.getClicked())
	{
		int Clicked = replay.EventHandling(event1);
		if(Clicked == -1)
		{
			GameState = GameIsPlay = false;
			break;
		}
		else if(Clicked == 1)
		{
			GameIsPlay = true;
		}
		replay.Render(renderer);
	}
	
}
void Gameloop::Event()
{
	p.GetJumpTime();
	SDL_PollEvent(&event1);
	if (event1.type == SDL_QUIT)
	{
		GameState = GameIsPlay = false;
	}
	if (event1.type == SDL_MOUSEBUTTONDOWN)
	{
		if (!p.JumpState())
		{
			p.Jump();
		}
		else
		{
			p.Gravity();
		}
	}
	else
	{
		p.Gravity();
	}
}
void Gameloop::Update()
{
	if (Pipe_Below1.getPipe1X() < Pipe_Below2.getPipe2X() && Pipe_Below1.getPipe1X() < Pipe_Below3.getPipe3X())
	{
		if (Pipe_Below1.getPipe1X() < -5)
		{
			nextCheckPoint = Pipe_Below2.getPipe2Y();
		}
		else
		{
			nextCheckPoint = Pipe_Below1.getPipe1Y();
		}
	}
	else if (Pipe_Below2.getPipe2X() < Pipe_Below1.getPipe1X() && Pipe_Below2.getPipe2X() < Pipe_Below3.getPipe3X())
	{
		if (Pipe_Below2.getPipe2X() < -5)
		{
			nextCheckPoint = Pipe_Below3.getPipe3Y();
		}
		else
		{
			nextCheckPoint = Pipe_Below2.getPipe2Y();
		}
		
	}
	else if (Pipe_Below3.getPipe3X() < Pipe_Below1.getPipe1X() && Pipe_Below3.getPipe3X() < Pipe_Below2.getPipe2X())
	{
		if (Pipe_Below3.getPipe3X() < -5)
		{
			nextCheckPoint = Pipe_Below1.getPipe1Y();
		}
		else
		{
			nextCheckPoint = Pipe_Below3.getPipe3Y();
		}
		
	}

	bool flag1 = false, flag2 = false;
	ground1.GroundUpdate1();
	ground2.GroundUpdate2();
	flag1 = Pipe_Above1.Pipe_Above1Update(variance1, points, SoundPoint);
	flag2 = Pipe_Below1.Pipe_Below1Update(variance1);
	if (flag1 && flag2)
	{
		srand(SDL_GetTicks());
		variance1 = rand() % 201 - 100;
		Pipe_Above1.Pipe_Above1Update(variance1, points, SoundPoint);
		Pipe_Below1.Pipe_Below1Update(variance1);
	}
	flag1 = Pipe_Above2.Pipe_Above2Update(variance2, points, SoundPoint);
	flag2 = Pipe_Below2.Pipe_Below2Update(variance2);
	if (flag1 && flag2)
	{
		srand(SDL_GetTicks());
		variance2 = rand() % 201 - 100;
		Pipe_Above2.Pipe_Above2Update(variance2, points, SoundPoint);
		Pipe_Below2.Pipe_Below2Update(variance2);
	}
	flag1 = Pipe_Above3.Pipe_Above3Update(variance3, points, SoundPoint);
	flag1 = Pipe_Below3.Pipe_Below3Update(variance3);
	if (flag1 && flag2)
	{
		srand(SDL_GetTicks());
		variance3 = rand() % 201 - 100;
		Pipe_Above3.Pipe_Above3Update(variance3, points, SoundPoint);
		Pipe_Below3.Pipe_Below3Update(variance3);
	}
}
void Gameloop::CollisionDetection()
{
	SDL_Rect p_fake = p.getDest(), pa1 = Pipe_Above1.getDest(), pa2 = Pipe_Above2.getDest(), pa3 = Pipe_Above3.getDest(),
								   pb1 = Pipe_Below1.getDest(), pb2 = Pipe_Below2.getDest(), pb3 = Pipe_Below3.getDest(),
								   gr1 = ground1.getDest(), gr2 = ground2.getDest();
	if (CollisionManager::CheckCollision(&p_fake, &pa1) || CollisionManager::CheckCollision(&p_fake, &pb1) || 
		CollisionManager::CheckCollision(&p_fake, &pa2) || CollisionManager::CheckCollision(&p_fake, &pb2) || 
		CollisionManager::CheckCollision(&p_fake, &pa3) || CollisionManager::CheckCollision(&p_fake, &pb3))
	{
		Mix_PlayChannelTimed(-1,SoundPunch,0,300);
		SDL_Delay(300);
		Reset();
	}
	else if (CollisionManager::CheckCollision(&p_fake, &gr1) || CollisionManager::CheckCollision(&p_fake, &gr2) || p.getYpos() < 0)
	{
		SDL_Delay(300); 
		Mix_PlayChannelTimed(-1,SoundPunch,0,300);
		Reset();
	}
}
void Gameloop::Reset()
{
	points = 0;
	variance1 = rand() % 201 - 100;
	variance2 = rand() % 201 - 100;
	variance3 = rand() % 201 - 100;
	p.Reset();
	Pipe_Above1.Reset();
	Pipe_Above2.Reset();
	Pipe_Above3.Reset();
	Pipe_Below1.Reset();
	Pipe_Below2.Reset();
	Pipe_Below3.Reset();
	GameState = false;
	menu.reset();
	replay.reset();
}

void Gameloop::Render()
{
	//Mix_PlayChannel(-1, SoundGame, 0);
    SDL_RenderClear(renderer);
    b.GroundRender(renderer);
	Pipe_Above1.PipeRender(renderer, Pipe_Above1.getSrc(), Pipe_Above1.getDest());
	Pipe_Below1.PipeRender(renderer, Pipe_Below1.getSrc(), Pipe_Below1.getDest());
	Pipe_Above2.PipeRender(renderer, Pipe_Above2.getSrc(), Pipe_Above2.getDest());
	Pipe_Below2.PipeRender(renderer, Pipe_Below2.getSrc(), Pipe_Below2.getDest());
	Pipe_Above3.PipeRender(renderer, Pipe_Above3.getSrc(), Pipe_Above3.getDest());
	Pipe_Below3.PipeRender(renderer, Pipe_Below3.getSrc(), Pipe_Below3.getDest());
    ground1.Render(renderer,ground1.getSrc(), ground1.getDest());
	ground2.Render(renderer,ground2.getSrc(), ground2.getDest());
    p.Render(renderer, p.getSrc(), p.getDest());
	int stt = 0;
	int num = points;
	if(num == 0)s[stt++] = 0;
	while(num > 0)
	{
		s[stt++] = num%10;
		num/=10;
	}
	if(stt == 1)
	{
		a[s[0]].Render(renderer, a[s[0]].getSrc(), number1);
	}
	else
	{
		a[s[1]].Render(renderer, a[s[1]].getSrc(), number2);
		a[s[0]].Render(renderer, a[s[0]].getSrc(), number3);
		
	}
    SDL_RenderPresent(renderer);        
}
void Gameloop::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);  
}
