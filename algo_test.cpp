/**
 * @brief this file is for testing function and classes in engine.cpp
 */

#include "engine.hpp"
using Event = SDLGame::event::Event;
using Rect = SDLGame::rect::Rect;
using Vector2 = SDLGame::math::Vector2;
using Surface = SDLGame::surface::Surface;
using Color = SDLGame::color::Color;
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
    double g_force = 1;
    Rect player_rect;
    Color color;

    Player(Vector2 _pos = Vector2(0,0), Vector2 _size = Vector2(50, 50), Color _color = Color(0, 255, 0))
    {
        pos = _pos;
        player_size = _size;
        color = _color;
    }
    void draw()
    {
        SDLGame::draw::window_rect(color, player_rect);
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
            player_rect.setBottom(HEIGHT);
        }

    }
};

Player player = Player(Vector2(50,50));
void draw(Surface& window)
{
    window.fill(Color(255,255,255));
    // player.draw();
    // SDLGame::draw::window_rect(Color(0,255,0), player.player_rect,0);
}

void update()
{
    player.update();
}

int main(int argc, char *argv[])
{
    bool debugging = true;
    SDLGame::init();
    Surface window = SDLGame::display::set_mode(WIDTH, HEIGHT, SDLGame::SKIP_TASK_BAR | SDLGame:);
    SDLGame::time::Clock clock = SDLGame::time::Clock();

    printf("window address: %p\n",window.surface);

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
                SDLGame::quit();
                exit(0);
            }
        }
        update();
        draw(window);
        clock.tick(10);
        SDLGame::display::flip();
        SDLGame::display::set_caption(std::to_string(clock.get_fps()).c_str());
    }
}