#include <SDL.h>
#include <SDL_image.h>

class Sprite {
public:
    Sprite(const char* imagePath, int x, int y, int width, int height) {
        texture = loadTexture(imagePath);
        position.x = x;
        position.y = y;
        this->width = width;
        this->height = height;
    }

    void draw(SDL_Renderer* renderer) {
        SDL_Rect destRect = { position.x, position.y, width, height };
        SDL_RenderCopy(renderer, texture, NULL, &destRect);
    }

    void updatePosition(int x, int y) {
        position.x = x;
        position.y = y;
    }

    ~Sprite() {
        SDL_DestroyTexture(texture);
    }

private:
    SDL_Texture* loadTexture(const char* imagePath) {
        SDL_Surface* loadedSurface = IMG_Load(imagePath);
        if (loadedSurface == NULL) {
            printf("Unable to load image %s! SDL_image Error: %s\n", imagePath, IMG_GetError());
            return NULL;
        }

        SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", imagePath, SDL_GetError());
        }

        SDL_FreeSurface(loadedSurface);
        return newTexture;
    }

    SDL_Point position;
    int width;
    int height;
    SDL_Texture* texture;
};
