//class đối tượng chung

#pragma once
#include"TextureManager.h"

class Object
{
    private:
        //HCN lưu tọa độ để render
        SDL_Rect src, dest;
        //khởi tạo texture
        SDL_Texture* Tex;
    public:
        //cập nhật HCN source
        void setSrc(int x, int y, int w, int h);
        //cập nhật HCN Destination
        void setDest(int x, int y, int w, int h);
        //hàm trả về Tex
        SDL_Texture* getTexture();
        //hàm trả về src
        SDL_Rect getSrc();
        //hàm trả về dest
        SDL_Rect getDest();
        //hàm khởi tạo texture
        void CreateTexture(const char* address, SDL_Renderer* ren);
        //hàm ảo render để viết lại cho những class con
        virtual void Render(SDL_Renderer* ren, SDL_Rect src, SDL_Rect dest) = 0;
};