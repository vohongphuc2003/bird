//class màn hình replay

#pragma once
#include"Background.h"
class Replay
{
    private:
        //biến cho bt click vào tùy chọn chưa
        bool isClicked;
        //biến màn hình replay
        Background replayBackground;
    public:
        //khởi tạo
        Replay();
        //trả về isClicked
        bool getClicked();
        //hàm khởi tạo tex của replayBackground
        void Initialize(SDL_Renderer* ren);
        //hàm sự kiện nhấn nút
        int EventHandling(SDL_Event& e);
        //hàm vẽ
        void Render(SDL_Renderer* ren);
        //hàm reset
        void reset();
};