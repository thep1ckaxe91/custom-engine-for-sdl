#include "engine.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;
//If global declare is bad, i make MY OWN global declare :)
class Game
{
public:
    bool gameactive = true;
    Vector2 desktop_size = sdlgame::display::get_desktop_size();
    string base_path = sdlgame::get_base_path();
    Surface window = sdlgame::display::set_mode(
        desktop_size.x,desktop_size.y,
        sdlgame::RENDERER_ACCELERATED | sdlgame::RESIZABLE | sdlgame::MAXIMIZED
    );
    sdlgame::time::Clock clock;

    Game() = default;
    Surface test_surf = Surface(500,500);
    Vector2 pos = Vector2(20,20);
    Vector2 size = test_surf.get_size();
    void draw()
    {
        window.fill("white");
        test_surf.fill(Color("black"));
        sdlgame::draw::circle(
            test_surf,
            Color(255,0,0,0),
            sin(sdlgame::time::get_ticks()/50)*50+size.x/2+pos.x,
            cos(sdlgame::time::get_ticks()/50)*50+size.y/2+pos.y,
            50
        );
        window.blit(test_surf,pos);
    }
    void update()
    {

    }
    void run(){
        while(true)
        {
            auto events = sdlgame::event::get();
            for(auto &event : events)
            {
                if(event.type == sdlgame::QUIT)
                {
                    sdlgame::quit();
                    exit(0);
                }
                else if(event.type == sdlgame::WINDOWENTER){
                    if(event["event"] == sdlgame::WINDOWFOCUSLOST) gameactive = false;
                    else if(event["event"] == sdlgame::WINDOWFOCUSGAINED) gameactive = true;
                }
            }
            if(gameactive)
            {
                update();
                draw();
                sdlgame::display::flip();
            }
            clock.tick();
        }
    }
};
int main(int argc, char** argv)
{
    sdlgame::init();
    sdlgame::font::init();
    sdlgame::image::init();
    sdlgame::mixer::init();
    Game game;
    game.run();
    return 0;
}