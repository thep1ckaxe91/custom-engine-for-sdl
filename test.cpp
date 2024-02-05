/**
 * @brief this file is for testing function and classes in engine.cpp
*/

#include "engine.h"
using Event = SDLGame::event::Event;
using Rect = SDLGame::rect::Rect;
using Vector2 = SDLGame::math::Vector2;
using Surface = SDLGame::surface::Surface;
int main(int argc, char* argv[]){
    SDLGame::init();
    SDLGame::display::set_mode(1280,720,SDLGame::SKIP_TASK_BAR);
    
    

    while(true){
        std::vector<Event> events = SDLGame::event::get();
        for(Event& event : events){
            if(event.type == SDLGame::QUIT)
            {
                SDLGame::quit();
                exit(0);
            }
        }
    }    
}