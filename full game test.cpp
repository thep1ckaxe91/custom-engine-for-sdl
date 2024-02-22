#include "engine.hpp"
using Event = sdlgame::event::Event;
using Rect = sdlgame::rect::Rect;
using Vector2 = sdlgame::math::Vector2;
using Surface = sdlgame::surface::Surface;
using Color = sdlgame::color::Color;
using Sound = sdlgame::mixer::Sound;
using Channel = sdlgame::mixer::Channel;
using Font = sdlgame::font::Font;
using namespace std;
const int WIDTH = 800, HEIGHT = 600, FPS=60;

void init()__attribute__((constructor));
void init(){sdlgame::init();}
Surface window = sdlgame::display::set_mode(
    WIDTH, HEIGHT,
    sdlgame::RENDERER_ACCELERATED
);
sdlgame::time::Clock sdlclock = sdlgame::time::Clock();
string base_path = sdlgame::get_base_path();
void gameover()
{
    printf("ur mom fat");
    exit(0);
}

double cooldown = 1;
double cooldown_cnt = 0;
double gap = 200; //pixle
class Pole : public sdlgame::sprite::Sprite
{
    double speed = 2;
public:
    Pole(const Surface& pole_image, bool isUnder, int yPos=300)
    {
        this->image = pole_image;
        if(!isUnder) this->image = sdlgame::transform::flip(this->image,0,1);
        this->rect = this->image.getRect();
        this->rect.setLeft(WIDTH);
        this->rect.setTop(yPos);
    }
    void update() override
    {
        this->rect.move_ip(-speed,0.0);
    }
};
vector<Pole> pole_list;
class Bird : public sdlgame::sprite::Sprite
{
public:
    Vector2 vel;
    double jump_speed=3,g_force = 0.1;
    Sound jump_sound;
    Bird(Vector2 pos)
    {
        this->image = sdlgame::image::load(base_path+"bird.png");
        this->rect = this->image.getRect();
        rect.setTop(pos.y); rect.setLeft(pos.x);
        jump_sound.load(base_path+"jump.wav");
    }
    void jump()
    {
        jump_sound.play();
        vel.y = -jump_speed;
    }
    void collision_check(){ 
        for(auto &pole : pole_list)
        {
            if(rect.colliderect(pole.rect))
            {
                gameover();
            }
        }
    }
    void update() override
    {
        collision_check();
        vel.y += g_force;
        rect.move_ip(vel); 
        if(rect.getBottom()>HEIGHT) exit(0);
        if(rect.getTop()<0) vel.y = 0, rect.setTop(1);
    }
};
int main(int argc, char *argv[])
{
    sdlgame::image::init();
    sdlgame::font::init();
    sdlgame::mixer::init();
    Surface pole_image = sdlgame::image::load(base_path+"pole.png");

    Bird player(Vector2(0.3*WIDTH,HEIGHT/2.0));

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
            if (event.type == sdlgame::KEYDOWN)
            {
                if(event["key"] == sdlgame::K_SPACE)
                {
                    player.jump();
                }
            }
        }

        {//update
            player.update();
            for(auto &pole : pole_list)
            {
                pole.update();
            }
            cooldown_cnt += sdlclock.delta_time();
            if(cooldown_cnt>=cooldown)
            {
                cooldown_cnt-=cooldown;
                int offset = sdlgame::random::randint(HEIGHT/2,HEIGHT/2+gap); 
                pole_list.push_back(Pole(pole_image,0,int(offset-gap-256)));
                pole_list.push_back(Pole(pole_image,1,(int)offset));
                if(pole_list.size()>0)
                    if(pole_list[0].rect.getRight()<0)
                    {
                        pole_list.erase(pole_list.begin());
                    }
            }
        }
        {//render
            window.fill(Color("black"));
            window.blit(player.image,player.rect.getTopLeft());
            for(auto &pole : pole_list)
            {
                window.blit(pole.image,pole.rect.getTopLeft());
            }
        }
        sdlgame::display::flip();
        sdlclock.tick(FPS);
    }
}