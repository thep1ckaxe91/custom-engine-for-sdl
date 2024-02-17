/**
 * @brief Test surface and transform namespace
 * TEST: Approved?
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
    Player(Surface image, Vector2 pos){
        this->image = image;
        this->rect = Rect(pos,image.get_size());
    }
    void update() override{
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
Player player(
    sdlgame::transform::scale_by(sdlgame::image::load(sdlgame::get_abs_path()+"player.png"),3),
    Vector2(50,50)
);
sdlgame::sprite::GroupSingle player_group(&player);
sdlgame::sprite::Group bounce_rects;
class BounceRect : public sdlgame::sprite::Sprite
{
public:
    Vector2 dir;
    Vector2 prepos;
    double speed = 3;
    BounceRect() = default;
    BounceRect(Rect rect,Color color){
        this->rect = rect;
        this->image = Surface(rect.getWidth(),rect.getHeight());
        this->image.fill(color);
        double angle = sdlgame::random::randf() * 360;
        dir = Vector2(speed,0.0).rotate(angle);
    }
    BounceRect& operator = (const BounceRect& oth){
        dir = oth.dir;
        image = oth.image;
        rect = oth.rect;
        group_list = oth.group_list;
        return *this;
    }
    void update() override{
        int collide_num=0;
        rect.move_ip(dir.x,0.0);
        if(rect.getLeft() < 0){
            rect.setLeft(0);
            dir.x = -dir.x;
        }
        else if(rect.getRight() > WIDTH){
            rect.setRight(WIDTH);
            dir.x = -dir.x;
        }
        else if((collide_num=sdlgame::sprite::spritecollide(player_group.sprite, &bounce_rects).size())>0){
            std::cout<< collide_num <<" x\n";
            if(dir.x > 0){
                rect.setRight(player_group.sprite->rect.getLeft());
                dir.x = -dir.x;
            }
            else if(dir.x < 0){
                rect.setLeft(player_group.sprite->rect.getRight());
                dir.x = -dir.x;
            }
        }
        rect.move_ip(0.0,dir.y);
        if(rect.getTop() < 0){
            rect.setTop(0);
            dir.y = -dir.y;
        }
        else if(rect.getBottom() > HEIGHT){
            rect.setBottom(HEIGHT);
            dir.y = -dir.y;
        }
        else if((collide_num=sdlgame::sprite::spritecollide(player_group.sprite, &bounce_rects).size())>0){
            std::cout<< collide_num << "y\n";
            if(dir.y > 0){
                rect.setBottom(player_group.sprite->rect.getTop());
                dir.y = -dir.y;
            }
            else if(dir.y < 0){
                rect.setTop(player_group.sprite->rect.getBottom());
                dir.y = -dir.y;
            }
        }
        if(collide_num) 
            std::cout<<"_________________\n";
    }
};
void draw()
{
    window.fill(Color("white"));
    player_group.draw(window);
    bounce_rects.draw(window);
}
void update()
{
    player_group.update();
    bounce_rects.update();
}

int main(int argc, char *argv[])
{
    const int brnum = 2;
    BounceRect brect_list[brnum];
    std::cout << "init address\n";
    for(int i=0;i<brnum;i++){
        Vector2 newsize(
            sdlgame::random::randint(20,50),
            sdlgame::random::randint(20,50)
        );
        Vector2 newpos(
            sdlgame::random::randint(100,WIDTH-newsize.x-50),
            sdlgame::random::randint(100,HEIGHT-newsize.y-50)
        );
        Rect newrect(newpos,newsize);
        Color newcolor(sdlgame::random::randint(0,255),sdlgame::random::randint(0,255),sdlgame::random::randint(0,255));
        BounceRect newbr(newrect,newcolor);
        brect_list[i]=newbr;
        std::cout << i << ":" << &brect_list[i].rect << std::endl;
    }
    for(int i=0;i<brnum;i++) 
        bounce_rects.add(&brect_list[i]);

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