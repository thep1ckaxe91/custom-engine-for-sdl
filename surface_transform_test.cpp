/**
 * @brief Test surface and transform namespace
 */
#include "advance_engine.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
const int WIDTH = 1280, HEIGHT = 720, FPS=60;

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
    std::string base_path = sdlgame::get_abs_path();
    Surface image = sdlgame::image::load(base_path+"test.png");

    double effect_time = 1; //second
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
        window.blit(image,Vector2(50,50));
        cur_t += clock.delta_time();

        if(cur_t>=effect_time){
            printf("Effect trigger\n");
            cur_t -= effect_time;
            // image = sdlgame::transform::flip(image,1,1);
            // image = sdlgame::transform::rotate(image,30,image.getRect().getCenter());
            // image = sdlgame::transform::scale_by(image,1.1);
            image.scroll(2,2);
        }
        update();
        draw();
        sdlgame::display::flip();
        clock.tick(FPS);
    }
}