/**
 * TODO: TEST:
 * collision
 * all set, get fucntion 
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
Rect rect1(50,50,100,100); Color color1("red");
Rect rect2(300,300,100,100); Color color2("blue");
void draw()
{
    window.fill("black");
    sdlgame::draw::rect(window,color2,rect2);
    sdlgame::draw::rect(window,color1,rect1);
}
double speed=5;
void update()
{
    auto keys = sdlgame::key::get_pressed();
    rect1.move_ip((keys[sdlgame::K_d]-keys[sdlgame::K_a])*speed,(keys[sdlgame::K_s]-keys[sdlgame::K_w])*speed);

    if(rect1.colliderect(rect2)) color1 = Color("lime");
    else color1 = Color("red");
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
            if (event.type == sdlgame::KEYDOWN){
                if(event[std::string("key")] == sdlgame::K_LEFT){
                    printf("rect1 should be on the left and not collide\n");
                    rect1.setRight(rect2.getLeft());
                }
                if(event[std::string("key")] == sdlgame::K_RIGHT){
                    printf("rect1 should be on the right and not collide\n");
                    rect1.setLeft(rect2.getRight());
                }
                if(event[std::string("key")] == sdlgame::K_UP){
                    printf("rect1 should be on top and not collide\n");
                    rect1.setBottom(rect2.getTop());
                    std::cout<<rect2.getTop()<<std::endl;
                }
                if(event[std::string("key")] == sdlgame::K_DOWN){
                    printf("rect1 should be under and not collide\n");
                    rect1.setTop(rect2.getBottom());
                }
            }
        }
        update();
        draw();
        sdlgame::display::flip();
        sdlclock.tick(FPS);
        sdlgame::display::set_caption(std::to_string(sdlclock.get_fps()).c_str());
    }
}