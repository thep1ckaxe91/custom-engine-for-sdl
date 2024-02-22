#include "engine.hpp"
#ifndef SCENE_HPP
#define SCENE_HPP
class Game;
class Scene
{
    public:
    Scene(Game &game);
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void event_handler(sdlgame::event::Event &event) = 0;
    private:
    Game game;
};

class SceneTransition
{

};

#endif