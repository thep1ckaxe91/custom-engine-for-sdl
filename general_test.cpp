#include<bits/stdc++.h>
#include<SDL2/SDL.h>

using namespace std;

int main(int argc, char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("sadasd",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);
    const Uint8 *keyState;
    int key_num;
    while(true){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            
            if(event.type == SDL_KEYUP){
                if(event.key.keysym.scancode == SDL_SCANCODE_A){
                    exit(0);
                }
            }
            keyState = SDL_GetKeyboardState(&key_num);
            if(keyState[SDL_SCANCODE_L]){
                printf("pressing L key\n");
            }

        }
    }
}