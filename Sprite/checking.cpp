#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <memory>

class Sprite;

class SpriteGroup
{
public:
    void add(std::shared_ptr<Sprite> sprite);
    void kill(std::shared_ptr<Sprite> sprite);
    void remove(std::shared_ptr<Sprite> sprite);
    bool alive(std::shared_ptr<Sprite> sprite) const;
    void update();
    void draw() const;

private:
    std::vector<std::shared_ptr<Sprite>> sprites;
    float spriteX = 0;
    float spriteY = 0;
};

std::shared_ptr<SDL_Surface> loadImage(const std::string& file);



class Sprite
{
public:
    Sprite(SDL_Renderer* renderer, const std::string& file);

    virtual void update() {}
    virtual void draw() const {}

    int getWidth() const;
    int getHeight() const;

private:
    SDL_Renderer* renderer;
    std::shared_ptr<SDL_Surface> surface;
    std::shared_ptr<SDL_Texture> texture;
    int width;
    int height;
};

//creating funcs

Sprite::Sprite(SDL_Renderer* renderer, const std::string& file)
    : renderer(renderer)
{
    surface = loadImage(file);
    if (!surface)
    {
        std::cerr << "Error loading image: " << SDL_GetError() << std::endl;
        return;
    }

    texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(renderer, surface.get()), SDL_DestroyTexture);
    SDL_QueryTexture(texture.get(), nullptr, nullptr, &width, &height);
}

void Sprite::update()
{
}

//explain :


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

std::shared_ptr<SDL_Surface> loadImage(const std::string& file)
{
    SDL_Surface* surface = IMG_Load(file.c_str());
    if (!surface)
    {
        std::cerr << "Error loading image: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    return std::shared_ptr<SDL_Surface>(surface, SDL_FreeSurface);
}

void SpriteGroup::add(std::shared_ptr<Sprite> sprite)
{
    sprites.push_back(sprite);
}

void SpriteGroup::kill(std::shared_ptr<Sprite> sprite)
{
    sprites.erase(std::remove(sprites.begin(), sprites.end(), sprite), sprites.end());
}

void SpriteGroup::remove(std::shared_ptr<Sprite> sprite)
{
    sprites.erase(std::remove(sprites.begin(), sprites.end(), sprite), sprites.end());
}

bool SpriteGroup::alive(std::shared_ptr<Sprite> sprite) const
{
    return std::find(sprites.begin(), sprites.end(), sprite) != sprites.end();
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
