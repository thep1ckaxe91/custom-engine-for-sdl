/**
 * @brief this file is for testing function and classes in engine.cpp
 */

#include "engine.h"
using Event = SDLGame::event::Event;
using Rect = SDLGame::rect::Rect;
using Vector2 = SDLGame::math::Vector2;
using Surface = SDLGame::surface::Surface;
using Color = SDLGame::color::Color;
const int WIDTH = 1280, HEIGHT = 720;

class Player
{
public:
    Vector2 pos;
    Vector2 player_size;
    Vector2 dir;
    double speed = 10;
    double jump_speed = 10;
    double g_force = 1;
    Rect player_rect;
    Color color;
    Player(){
        pos = Vector2(0,0);
        player_size = Vector2(50,50);

    }
    Player(Vector2 _pos = Vector2(0, 0), Vector2 _size = Vector2(50, 50), Color _color = Color(0, 255, 0));
    {
        pos = _pos;
        player_size = _size;
        color = _color;
    }
    void draw(Surface &window)
    {
        SDLGame::draw::window_rect(window, color, player_rect);
    }
    void update()
    {
        auto keys = SDLGame::key::get_pressed();
        if (keys[SDLGame::K_a])
        {
            dir.x = -1;
        }
        if (keys[SDLGame::K_d])
        {
            dir.x = 1;
        }
        if (keys[SDLGame::K_w])
        {
            dir.y = -jump_speed;
        }
        dir.y += g_force;

        player_rect.x += dir.x * speed;
        if (player_rect.getRight() > WIDTH)
        {
            player_rect.setRight(WIDTH);
        }
        if (player_rect.getLeft() < 0)
        {
            player_rect.setLeft(0);
        }
        player_rect.y += dir.y;
        if (player_rect.getBottom > HEIGHT)
        {
            player_rect.setBottom(HEIGHT);
        }

    }
};

Player player;
void draw()
{
    
}

void update()
{

}

int main(int argc, char *argv[])
{
    SDLGame::init();
    Surface window = SDLGame::display::set_mode(WIDTH, HEIGHT, SDLGame::SKIP_TASK_BAR);
    SDLGame::time::Clock clock = SDLGame::time::Clock();
    /**
     * @warning ATTENTION: ALWAYS CAP FPS, other wise the program will be to fast and lag your computer
     */

    while (true)
    {
        std::vector<Event> events = SDLGame::event::get();
        for (Event &event : events)
        {
            if (event.type == SDLGame::QUIT)
            {
                printf("quit right a fucking way");
                SDLGame::quit();
                exit(0);
            }
        }
        draw();
        update();
        clock.tick(120);
        SDLGame::display::set_caption(std::to_string(clock.get_fps()).c_str());
    }
}