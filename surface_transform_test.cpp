/**
 * @brief Test surface and transform namespace
 */
#include "advance_engine.hpp"
using Event = SDLGame::event::Event;
using Rect = SDLGame::rect::Rect;
using Vector2 = SDLGame::math::Vector2;
using Surface = SDLGame::surface::Surface;
using Color = SDLGame::color::Color;
const int WIDTH = 1280, HEIGHT = 720, FPS=60;

void draw()
{

}
void update()
{

}

int main(int argc, char *argv[])
{
    SDLGame::init();
    Surface window = SDLGame::display::set_mode(
        WIDTH, HEIGHT,
        SDLGame::RENDERER_ACCELERATED);
    SDLGame::time::Clock clock = SDLGame::time::Clock();
    std::string base_path = SDLGame::get_abs_path();
    Surface image = SDLGame::image::load(base_path+"test.png");

    while (true)
    {
        
        std::vector<Event> events = SDLGame::event::get();
        for (Event &event : events)
        {
            if (event.type == SDLGame::QUIT)
            {
                SDLGame::quit();
                exit(0);
            }
        }
        window.fill(Color(255,255,255));
        window.blit(image,Vector2(50,50));
        update();
        draw();
        SDLGame::display::flip();
        clock.tick(FPS);
    }
}