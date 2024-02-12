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
    Color bg_color = Color("white");
    Rect test_rect = Rect(20,60,50,30);
    std::cout << bg_color.toString()<<std::endl;
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

        window.fill(bg_color);
        sdlgame::draw::rect(window,Color("red"),test_rect);
        sdlgame::draw::draw_circle(window,Color("blue"),500,500,30);
        sdlgame::draw::line(window,Color("black"),600,600,800,720);
        sdlgame::draw::draw_polygon(window,Color("green"),{{60,60},{60,80},{100,60}});
        update();
        draw();
        sdlgame::display::flip();
        clock.tick(FPS);
    }
}