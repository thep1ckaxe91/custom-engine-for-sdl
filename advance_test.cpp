/**
 * @brief this file is for testing function and classes in advance_engine.cpp
 */
#include "engine.hpp"
#include <windows.h>
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
const int WIDTH = 1280, HEIGHT = 720;

class Player
{
private:
    Vector2 pos;
    Vector2 player_size;
    Vector2 dir;
public:
    double speed = 10;
    double jump_speed = 10;
    double g_force = 0.2;
    Rect player_rect;
    Color color;

    Player(Vector2 _pos = Vector2(0,0), Vector2 _size = Vector2(50, 50), Color _color = Color(0, 255, 0))
    {
        pos = _pos;
        player_size = _size;
        color = _color;
        player_rect = Rect(pos,player_size);
    }
    void draw(Surface& window)
    {
        sdlgame::draw::rect(window,color, player_rect);
    }
    void update()
    {
        std::vector<bool> keys = sdlgame::key::get_pressed();
        if (keys[sdlgame::K_a])
        {
            // printf("A is pressed");
            dir.x = -1;
        }
        else if (keys[sdlgame::K_d])
        {
            // printf("D is pressed");
            dir.x = 1;
        }
        else dir.x = 0;
        if (keys[sdlgame::K_w])
        {
            // printf("W is pressed");
            dir.y = -jump_speed;
        }
        dir.y += g_force;

        player_rect.move_ip(dir.x * speed,0.0);
        if (player_rect.getRight() > WIDTH)
        {
            player_rect.setRight(WIDTH);
        }
        if (player_rect.getLeft() < 0)
        {
            player_rect.setLeft(0);
        }
        player_rect.move_ip(0.0,dir.y);
        if (player_rect.getBottom() > HEIGHT)
        {
            player_rect.setTop(HEIGHT-player_size.y);
            dir.y = 0;
        }
    }
};

Player player = Player(Vector2(50,50), Vector2(50,50), Color(255,0,0));
void draw(Surface& window)
{
    window.fill(Color(255,255,255));
    player.draw(window);
    // sdlgame::draw::rect(window,Color(0,255,0), Rect(30,30,20,20));
}

void update()
{
    player.update();
}

int main(int argc, char *argv[])
{
    bool debugging = true;
    sdlgame::init();
    Surface window = sdlgame::display::set_mode(
        WIDTH, HEIGHT,
        sdlgame::SKIP_TASK_BAR | sdlgame::RENDERER_ACCELERATED
    );

    sdlgame::time::Clock clock = sdlgame::time::Clock();
    /**
     * @warning ATTENTION: ALWAYS CAP FPS, other wise the program will be to fast and lag your computer
     */

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
        draw(window);
        clock.tick(500);
        sdlgame::display::flip();
        sdlgame::display::set_caption(std::to_string(clock.get_fps()).c_str());
    }
}