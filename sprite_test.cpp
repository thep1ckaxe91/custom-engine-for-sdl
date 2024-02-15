/**
 * @brief Test surface and transform namespace
 */
#include "engine.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
const int WIDTH = 1280, HEIGHT = 720, FPS=60;
class Player : public sdlgame::sprite::Sprite {
    
    Player(Surface image, Vector2 pos) : sdlgame::sprite::Sprite(image,pos){
        
    }

    void update(){
        
    }
};
void draw()
{

}
void update()
{

}

int main(int argc, char *argv[])
{
    sdlgame::init();
    Surface window = sdlgame::display::set_mode(
        WIDTH, HEIGHT,
        sdlgame::RENDERER_ACCELERATED);
    sdlgame::time::Clock clock = sdlgame::time::Clock();
    while (true)
    {
        std::vector<Event> events = sdlgame::event::get();
        for (Event &event : events)
        {
            if (event.type == sdlgame::QUIT)
            {
                sdlgame::quit();
                exit(0);
            }
        }
        update();
        draw();
        sdlgame::display::flip();
        clock.tick(FPS);
    }
}