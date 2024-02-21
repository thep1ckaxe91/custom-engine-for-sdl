#include "engine.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
const int WIDTH = 1920, HEIGHT = 1080, FPS=60;

void init()__attribute__((constructor));
void init(){sdlgame::init();} //should do this if need to declare window for global purpose
Surface window = sdlgame::display::set_mode(
    WIDTH, HEIGHT,
    sdlgame::RENDERER_ACCELERATED
    // | sdlgame::FULLSCREEN
);
sdlgame::time::Clock sdlclock = sdlgame::time::Clock();
bool updating = 1;
int main(int argc, char *argv[])
{
    sdlgame::font::init();
    Font minecraft_font(sdlgame::get_base_path()+"consolaz.ttf",32);
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
            // else if (event.type == sdlgame::WINDOWEVENT){
            //     if(event["event"] == sdlgame::WINDOWFOCUSLOST){
            //         updating = 0;
            //     }
            //     else if(event["event"] == sdlgame::WINDOWFOCUSGAINED){
            //         updating = 1;

            //     }
            // }
        }
        if(updating){
            printf("Still updating\n");
            window.fill(Color("white"));
            window.blit(
                minecraft_font.render(
                    std::to_string(sdlclock.get_fps()),
                    2,
                    Color("black"),
                    300,
                    Color("none")
                ),
                Vector2(50,50)
            );
            sdlgame::display::flip();
        }
        sdlclock.tick(FPS);
    }
}
