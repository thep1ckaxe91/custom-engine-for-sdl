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
void init(){sdlgame::init();} //should do this if need to declare window for global purpose
Surface window = sdlgame::display::set_mode(
    WIDTH, HEIGHT,
    sdlgame::RENDERER_ACCELERATED
);
sdlgame::time::Clock sdlclock = sdlgame::time::Clock();

class Player : public sdlgame::sprite::Sprite {
public:
    double speed = 5;
    Vector2 dir = Vector2();
    Player(int width,int height, Vector2 pos, Color color){
        this->image = Surface(width,height);
        this->image.fill(color);
        this->rect = Rect(pos,width,height);
    }
    Player(int width,int height, int x, int y, Color color){
        this->image = Surface(width,height);
        this->image.fill(color);
        this->rect = Rect(x,y,width,height);
    }
    void update(){
        auto keys = sdlgame::key::get_pressed();
        if(keys[sdlgame::K_w]) dir.y = -speed;
        else if(keys[sdlgame::K_s]) dir.y = speed;
        else dir.y = 0;
        if(keys[sdlgame::K_a]) dir.x = -speed;
        else if(keys[sdlgame::K_d]) dir.x = speed;
        else dir.x = 0;

        this->rect.move_ip(dir);
    }
};
Player player(50,100,50,50,Color("red"));
sdlgame::sprite::GroupSingle player_group(&player);

/**
 * TODO: continue test Group, try to make tile, also the sprite collide function
*/
void draw()
{
    player_group.draw(window);
}
void update()
{
    window.fill(Color("white"));
    player_group.update();
}

int main(int argc, char *argv[])
{
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
        draw();
        sdlgame::display::flip();
        sdlclock.tick(FPS);
    }
}