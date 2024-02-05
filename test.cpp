/**
 * @brief this file is for testing function and classes in engine.cpp
*/

#include "engine.h"
using Event = SDLGame::event::Event;
using Rect = SDLGame::rect::Rect;
using Vector2 = SDLGame::math::Vector2;
using Surface = SDLGame::surface::Surface;
using Color = SDLGame::color::Color;
const int WIDTH=1280, HEIGHT = 720;

class Player
{
    Vector2 pos = Vector2();
    Vector2 player_size = Vector2(20,20);
    Vector2 direction = Vector2(0,0);
    double speed = 10;
    double jump_speed = 10;
    Rect player_rect = Rect();
    Color color = Color(0,255,0);
    Player(Vector2 _pos = Vector2(0,0),Vector2 _size = Vector2(50,50),Color _color = Color(0,255,0));
    {
        pos = _pos;
        size = _size;
        color = _color;
    }
    void draw(Surface& window){
        SDLGame::draw::window_rect(window,color,player_rect);
    }
    void update(){

    }
};
void draw()
{

}

void update()
{
    std::vector<bool> keys = SDLGame::key::get_pressed();
    if(keys[SDLGame::K_a])
}

int main(int argc, char* argv[]){
    SDLGame::init();
    Surface window = SDLGame::display::set_mode(WIDTH,HEIGHT,SDLGame::SKIP_TASK_BAR);
    SDLGame::time::Clock clock = SDLGame::time::Clock();
    /**
     * @warning ATTENTION: ALWAYS CAP FPS, other wise the program will be to fast and lag your computer
    */


    while(true){
        std::vector<Event> events = SDLGame::event::get();
        for(Event& event : events){
            if(event.type == SDLGame::QUIT)
            {
                printf("quit right a fucking way");
                SDLGame::quit();
                exit(0);
            }
        }
        draw();
        update();
        clock.tick(120);
        SDLGame::display::set_caption(std::to_string(clock.get_fps()).c_str());
    }
    printf("Some fucking how");
}