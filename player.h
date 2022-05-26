//class hiện thị con chim

#pragma once
#include "Object.h"

class Player :public Object
{
private:
    //độ giảm chiều cao của chim
    double gravity = 0.2;
    // tọa độ Y của chim
    int Ypos = 256;
    //Biến gia tốc khi lên thì giảm dần khi xuống thì tăng dần
    double accelerator1 = 0;
    double accelerator2 = 0;
    //Biến cho biết có nhảy được không
    bool inJump = false;
    //biến thay đổi y để chim nhảy lên
    double jumpHeight = -6;
    //thời gian hiện tại
    double jumpTimer;
    //thời gian nhảy gần nhất
    double lastJump = 0;
    
    SDL_Texture* Tex1;
    SDL_Texture* Tex2;
    int animationTimer;
public:
    //hàm chuyển động của chim
    void Gravity();
    //hàm cập nhất jumpTimer
    void GetJumpTime();
    //hàm reset biến
    void Reset();
    //hàm trả về Ypos
    int getYpos();
    //hàm cho bt trang thái của inJump hay là gravity()
    void Jump();
    //hàm trả về inJump
    bool JumpState();
    //hàm khởi tạo tex và vẽ
    void CreateTexture1(const char* address, SDL_Renderer* ren);
    void CreateTexture2(const char* address, SDL_Renderer* ren);
    void Render(SDL_Renderer* ren, SDL_Rect src, SDL_Rect dest);
};
    