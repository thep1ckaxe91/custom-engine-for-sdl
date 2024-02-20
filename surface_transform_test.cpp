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
void init()__attribute__((constructor));
void init(){
    sdlgame::init();
}
Surface window = sdlgame::display::set_mode(
    WIDTH, HEIGHT,
    sdlgame::RENDERER_ACCELERATED);
sdlgame::time::Clock sdlclock = sdlgame::time::Clock();
std::string base_path = sdlgame::get_base_path();
Surface image = sdlgame::image::load(base_path+"/resources/test.jpg");
int main(int argc, char *argv[])
{
    Vector2 pos = Vector2(50,50);
    // Surface image = sdlgame::image::load(base_path+"test.png");

    double effect_time = 0.1; //second
    double cur_t = 0;

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
        window.fill(Color(255,255,255));
        window.blit(image,pos);
        cur_t += sdlclock.delta_time();

        if(cur_t>=effect_time){
            printf("Effect trigger\n");
            cur_t -= effect_time;
            image = sdlgame::transform::flip(image,1,0);
            if(pos.x==50) pos.x = 500;
            else pos.x = 50;
            // image = sdlgame::transform::rotate(image,30,image.getRect().getCenter());
            // image = sdlgame::transform::scale_by(image,1.1);
        }
        sdlgame::display::flip();
        sdlclock.tick(FPS);
    }
}