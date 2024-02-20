#include "engine.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
const int WIDTH = 1280, HEIGHT = 720, FPS=60;

void init()__attribute__((constructor));
void init(){sdlgame::init();} //should do this if need to declare window for global purpose
Surface window = sdlgame::display::set_mode(
    WIDTH, HEIGHT,
    sdlgame::RENDERER_ACCELERATED
);
sdlgame::time::Clock sdlclock = sdlgame::time::Clock();
int main(int argc, char *argv[])
{
    sdlgame::font::init();
    // Font minecraft_font(sdlgame::get_base_path()+"test.ttf");
    Font minecraft_font = sdlgame::font::SysFont("Consolas");
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
        window.fill(Color("white"));
        window.blit(minecraft_font.render("ur mom fat as hell i wish she sit on my face",0,Color("red"),100,Color("blue")),Vector2(50,50));
        sdlgame::display::flip();
        sdlclock.tick(FPS);
    }
}
