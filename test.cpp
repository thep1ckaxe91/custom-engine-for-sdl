/**
 * @brief this file is for testing function and classes in engine.cpp
*/

#include "engine.h"
using Event = SDLGame::event::Event;
using Rect = SDLGame::rect::Rect;
using Vector2 = SDLGame::math::Vector2;
using Surface = SDLGame::surface::Surface;
const int WIDTH=1280, HEIGHT = 720;


Vector2 pos = Vector2();
Vector2 play_size = Vector2(20,20);

void draw()
{

}

void update()
{
    std::vector<bool> keys = SDLGame::key::get_pressed();
    for
}

int main(int argc, char* argv[]){
    SDLGame::init();
    SDLGame::display::set_mode(WIDTH,HEIGHT,SDLGame::SKIP_TASK_BAR);
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