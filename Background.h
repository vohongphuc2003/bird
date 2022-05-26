//Class đối tượng hiện thị trên màn hình
#pragma once

#include"object.h"
#include<SDL_mixer.h>
class Background :public Object
{
    private:
        //Biến tọa độ x của cột đầu và cuối
        int distance1 = 0;
        int distance2 = 805;
        //vị trí khởi tạo vủa 3 cột
        int pipeDistance1 = 400;
        int pipeDistance2 = 700;
        int pipeDistance3 = 1000;
        //chiều cao 3 cột
        int incY1 = 0;
        int incY2 = 0;
        int incY3 = 0;
    public:
        //6 hàm chạy của cột
        bool Pipe_Above1Update(int incY, int &score, Mix_Chunk* audio);
        bool Pipe_Below1Update(int incY);
        bool Pipe_Above2Update(int incY, int& score, Mix_Chunk* audio);
        bool Pipe_Below2Update(int incY);
        bool Pipe_Above3Update(int incY, int& score, Mix_Chunk* audio);
        bool Pipe_Below3Update(int incY);
        //hàm khởi tạo
        void Reset();
        //6 hàm trả về tọa độ của các cột
        int getPipe1X();
        int getPipe1Y();
        int getPipe2X();
        int getPipe2Y();
        int getPipe3X();
        int getPipe3Y();
        //hàm quay lại của 2 cột đầu
        void GroundUpdate1();
        void GroundUpdate2();
        //hàm vẽ theo tọa độ
        void Render(SDL_Renderer* ren, SDL_Rect src, SDL_Rect dest);
        //hàm vẽ toàn màn hình
        void GroundRender(SDL_Renderer* ren);
        //hàm vẽ cột theo tọa độ
        void PipeRender(SDL_Renderer* ren, SDL_Rect src, SDL_Rect dest  );
};