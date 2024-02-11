/**
 * @brief this file is for testing function and classes in advance_engine.cpp
 */
#include "engine.hpp"
#include <mapinls.h>

// this code force the program to use better gpu for rendering
#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;

#ifdef __cplusplus
}
#endif
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
        SDLGame::draw::rect(window,color, player_rect);
    }
    void update()
    {
        std::vector<bool> keys = SDLGame::key::get_pressed();
        if (keys[SDLGame::K_a])
        {
            // printf("A is pressed");
            dir.x = -1;
        }
        else if (keys[SDLGame::K_d])
        {
            // printf("D is pressed");
            dir.x = 1;
        }
        else dir.x = 0;
        if (keys[SDLGame::K_w])
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
    // SDLGame::draw::rect(window,Color(0,255,0), Rect(30,30,20,20));
}

void update()
{
    player.update();
}

int main(int argc, char *argv[])
{
    bool debugging = true;
    SDLGame::init();
    Surface window = SDLGame::display::set_mode(
        WIDTH, HEIGHT,
        SDLGame::SKIP_TASK_BAR | SDLGame::RENDERER_ACCELERATED
    );

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
                SDLGame::quit();
                exit(0);
            }
        }
        update();
        draw(window);
        clock.tick(500);
        SDLGame::display::flip();
        SDLGame::display::set_caption(std::to_string(clock.get_fps()).c_str());
    }
}