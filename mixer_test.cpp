/**
 * TEST: mixer
*/
#include "engine.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
const int WIDTH = 1280, HEIGHT = 720, FPS=60;

void init()__attribute__((constructor));
void init(){
    sdlgame::init();
} //should do this if need to declare window for global purpose
Surface window = sdlgame::display::set_mode(
    WIDTH, HEIGHT,
    sdlgame::RENDERER_ACCELERATED
);
sdlgame::time::Clock sdlclock = sdlgame::time::Clock();
void draw()
{
    
}
void update()
{
    // testSFX.play();
    /**
     * TODO: cant play sound for some reason, check init, funciton and stuff
    */
}

int main(int argc, char *argv[])
{
    sdlgame::mixer::init();
    Sound testMusic(sdlgame::get_abs_path()+"/resources/test.mp3");
    sdlgame::mixer::set_num_channels(16);
    testMusic.play(2,-1,3000);
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
        sdlclock.tick(FPS);
    }
}