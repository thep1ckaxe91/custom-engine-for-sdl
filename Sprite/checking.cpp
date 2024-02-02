#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <algorithm>

using namespace std;

SDL_Texture* loadImage(const string& file)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, file.c_str());
    if (!texture)
    {
        cerr << "Error loading image: " << IMG_GetError() << endl;
    }
    return texture;
}

//creating Sprite Class
class Sprite
{
public:
    Sprite() = default;
    Sprite(SDL_Renderer* renderer, const string& file)
        : renderer(renderer), texture(loadImage(file)) {}

    void render(int x, int y)
    {
        SDL_Rect dest = { x, y, width, height };
        SDL_RenderCopy(renderer, texture, nullptr, &dest);
    }

    int getWidth() { return width; }
    int getHeight() { return height; }

private:
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;
    int width = 0;
    int height = 0;
};


//creating Sprite's function
class SpriteGroup
{
public:
    void add(Sprite* sprite)
    {
        sprites.push_back(sprite);
    }

    void kill(Sprite* sprite)
    {
        sprites.erase(remove(sprites.begin(), sprites.end(), sprite), sprites.end());
    }

    void remove(Sprite* sprite)
    {
        sprites.erase(remove(sprites.begin(), sprites.end(), sprite), sprites.end());
    }

    bool alive(Sprite* sprite)
    {
        return find(sprites.begin(), sprites.end(), sprite) != sprites.end();
    }

    void render()
    {
        for (Sprite* sprite : sprites)
        {
            sprite->render(sprite->getWidth() * spriteX, sprite->getHeight() * spriteY);
        }
    }

private:
    vector<Sprite*> sprites;
    float spriteX = 0;
    float spriteY = 0;
};
