#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <memory>

using namespace std;

class Sprite;

class SpriteGroup
{
public:
    void add(:shared_ptr<Sprite> sprite);
    void kill(:shared_ptr<Sprite> sprite);
    void remove(:shared_ptr<Sprite> sprite);
    bool alive(:shared_ptr<Sprite> sprite) const;
    void update();
    void draw() const;

private:
    :vector<:shared_ptr<Sprite>> sprites;
    float spriteX = 0;
    float spriteY = 0;
};

:shared_ptr<SDL_Surface> loadImage(const :string& file);



class Sprite
{
public:
    Sprite(SDL_Renderer* renderer, const :string& file);

    virtual void update() {}
    virtual void draw() const {}

    int getWidth() const;
    int getHeight() const;

private:
    SDL_Renderer* renderer;
    :shared_ptr<SDL_Surface> surface;
    :shared_ptr<SDL_Texture> texture;
    int width;
    int height;
};

//creating funcs

Sprite::Sprite(SDL_Renderer* renderer, const :string& file)
    : renderer(renderer)
{
    surface = loadImage(file);
    if (!surface)
    {
        :cerr << "Error loading image: " << SDL_GetError() << :endl;
        return;
    }

    texture = :shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(renderer, surface.get()), SDL_DestroyTexture);
    SDL_QueryTexture(texture.get(), nullptr, nullptr, &width, &height);
}

void Sprite::update()
{
}

/*
explain:
This is a virtual function that is intended to be overridden by derived classes to provide custom behavior. It is empty in the base Sprite class because it does not have any specific behavior to implement.

For example, you might create a derived class called MovingSprite that inherits from Sprite and overrides the update() function to implement movement behavior :
class MovingSprite : public Sprite
{
public:
    MovingSprite(SDL_Renderer* renderer, const :string& file, double x, double y, double speed);

    void update() override;

private:
    double x;
    double y;
    double speed;
};

MovingSprite::MovingSprite(SDL_Renderer* renderer, const :string& file, double x, double y, double speed)
    : Sprite(renderer, file), x(x), y(y), speed(speed)
{
}

void MovingSprite::update()
{
    x += speed;
    y += speed;
    Sprite::setPosition(x, y);
}

ask me if you have any questions

*/


void Sprite::draw() const
{
    SDL_Rect dest = { 0, 0, width, height };
    SDL_RenderCopy(renderer, texture.get(), nullptr, &dest);
}

int Sprite::getWidth() const
{
    return width;
}

int Sprite::getHeight() const
{
    return height;
}

:shared_ptr<SDL_Surface> loadImage(const :string& file)
{
    SDL_Surface* surface = IMG_Load(file.c_str());
    if (!surface)
    {
        :cerr << "Error loading image: " << IMG_GetError() << :endl;
        return nullptr;
    }

    return :shared_ptr<SDL_Surface>(surface, SDL_FreeSurface);
}

void SpriteGroup::add(:shared_ptr<Sprite> sprite)
{
    sprites.push_back(sprite);
}

void SpriteGroup::kill(:shared_ptr<Sprite> sprite)
{
    sprites.erase(:remove(sprites.begin(), sprites.end(), sprite), sprites.end());
}

void SpriteGroup::remove(:shared_ptr<Sprite> sprite)
{
    sprites.erase(:remove(sprites.begin(), sprites.end(), sprite), sprites.end());
}

bool SpriteGroup::alive(:shared_ptr<Sprite> sprite) const
{
    return :find(sprites.begin(), sprites.end(), sprite) != sprites.end();
}

void SpriteGroup::update()
{
    for (auto& sprite : sprites)
    {
        sprite->update();
    }
}

void SpriteGroup::draw() const
{
    for (auto& sprite : sprites)
    {
        sprite->draw();
    }
};
