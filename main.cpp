#include "Gameloop.h"
#include<bits/stdc++.h>
using namespace std;
Gameloop* g = new Gameloop();
double first;
double last = 0;
void Playing()
{
    g->Event();
    g->Update();    
    g->Render();
    g->CollisionDetection();
    first = SDL_GetTicks();
    if(first - last < 15)
    {
        SDL_Delay(15 - (first - last));
    }
    last = first;
}
int main(int argc, char** argv)
{
    g->Intialize();
    label:
        last = 0;
        g->MainMenu();
        while(g->getGameState())
        {
            Playing();  
        }
        g->Replay();
    if(g->getGameIsPlay())goto label;
    g->Clear();
    return 0;
}
