/**
 * @authors thep1ckaxe, Ngô Hoan Tài and many authors from SDL2's developers
 * email: ThePickaxe91@gmail.com
 *
 *  this file tried to replicate all classes and function that they have in pygame but implement for SDL2 in C++
 * if you spot or have problem while using this engine, please let me know through email
 *
 * REQUIREMENT: SDL2 installed to your mingw directory
 *
 * all pixel format is consider RGBA32
 *
 * @warning this is not thread-safe, recommend only sigle threading
 *
 * @copyright if you want to use this file, please contact for permission, after that, feel free to use and modify this file
 */

#include <bits/stdc++.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_audio.h"
#include "SDL2/SDL_assert.h"
#include "SDL2/SDL_atomic.h"
#include "SDL2/SDL_vulkan.h"
#include "SDL2/SDL_video.h"
#include "SDL2/SDL_version.h"
#include "SDL2/SDL_touch.h"
#include "SDL2/SDL_timer.h"
#include "SDL2/SDL_thread.h"
#include "SDL2/SDL_system.h"
#include "SDL2/SDL_surface.h"
#include "SDL2/SDL_stdinc.h"
#include "SDL2/SDL_sensor.h"
#include "SDL2/SDL_scancode.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_quit.h"
#include "SDL2/SDL_power.h"
#include "SDL2/SDL_platform.h"
#include "SDL2/SDL_pixels.h"
#include "SDL2/SDL_mouse.h"
#include "SDL2/SDL_main.h"
#include "SDL2/SDL_keycode.h"
#include "SDL2/SDL_keyboard.h"
#include "SDL2/SDL_filesystem.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_clipboard.h"
#include "SDL2/SDL_blendmode.h"
#include "SDL2/SDL_error.h"
#include "SDL2/SDL_bits.h"
#include "SDL3/SDL_image.h"
#include "SDL3/SDL_mixer.h"
#include "SDL3/SDL_ttf.h"
#define null NULL

/**
 *  this namespace replace pygame module, also replicate the way everything is just from pygame. ish
 */
namespace SDLGame
{
    const int K_UNKNOWN = 0;
    const int K_RETURN = '\r';
    const int K_ESCAPE = '\x1B';
    const int K_BACKSPACE = '\b';
    const int K_TAB = '\t';
    const int K_SPACE = ' ';
    const int K_EXCLAIM = '!';
    const int K_QUOTEDBL = '"';
    const int K_HASH = '#';
    const int K_PERCENT = '%';
    const int K_DOLLAR = '$';
    const int K_AMPERSAND = '&';
    const int K_QUOTE = '\'';
    const int K_LEFTPAREN = '(';
    const int K_RIGHTPAREN = ')';
    const int K_ASTERISK = '*';
    const int K_PLUS = '+';
    const int K_COMMA = ',';
    const int K_MINUS = '-';
    const int K_PERIOD = '.';
    const int K_SLASH = '/';
    const int K_0 = '0';
    const int K_1 = '1';
    const int K_2 = '2';
    const int K_3 = '3';
    const int K_4 = '4';
    const int K_5 = '5';
    const int K_6 = '6';
    const int K_7 = '7';
    const int K_8 = '8';
    const int K_9 = '9';
    const int K_COLON = ':';
    const int K_SEMICOLON = ';';
    const int K_LESS = '<';
    const int K_EQUALS = '=';
    const int K_GREATER = '>';
    const int K_QUESTION = '?';
    const int K_AT = '@';
    const int K_LEFTBRACKET = '[';
    const int K_BACKSLASH = '\\';
    const int K_RIGHTBRACKET = ']';
    const int K_CARET = '^';
    const int K_UNDERSCORE = '_';
    const int K_BACKQUOTE = '`';
    const int K_a = 'a';
    const int K_b = 'b';
    const int K_c = 'c';
    const int K_d = 'd';
    const int K_e = 'e';
    const int K_f = 'f';
    const int K_g = 'g';
    const int K_h = 'h';
    const int K_i = 'i';
    const int K_j = 'j';
    const int K_k = 'k';
    const int K_l = 'l';
    const int K_m = 'm';
    const int K_n = 'n';
    const int K_o = 'o';
    const int K_p = 'p';
    const int K_q = 'q';
    const int K_r = 'r';
    const int K_s = 's';
    const int K_t = 't';
    const int K_u = 'u';
    const int K_v = 'v';
    const int K_w = 'w';
    const int K_x = 'x';
    const int K_y = 'y';
    const int K_z = 'z';
    const int K_CAPSLOCK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK);
    const int K_F1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1);
    const int K_F2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2);
    const int K_F3 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3);
    const int K_F4 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4);
    const int K_F5 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5);
    const int K_F6 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6);
    const int K_F7 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7);
    const int K_F8 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8);
    const int K_F9 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9);
    const int K_F10 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10);
    const int K_F11 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11);
    const int K_F12 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12);
    const int K_PRINTSCREEN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN);
    const int K_SCROLLLOCK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK);
    const int K_PAUSE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE);
    const int K_INSERT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT);
    const int K_HOME = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME);
    const int K_PAGEUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP);
    const int K_DELETE = '\x7F';
    const int K_END = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END);
    const int K_PAGEDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN);
    const int K_RIGHT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT);
    const int K_LEFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT);
    const int K_DOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN);
    const int K_UP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP);
    const int K_NUMLOCKCLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR);
    const int K_KP_DIVIDE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE);
    const int K_KP_MULTIPLY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY);
    const int K_KP_MINUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS);
    const int K_KP_PLUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS);
    const int K_KP_ENTER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER);
    const int K_KP_1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1);
    const int K_KP_2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2);
    const int K_KP_3 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3);
    const int K_KP_4 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4);
    const int K_KP_5 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5);
    const int K_KP_6 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6);
    const int K_KP_7 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7);
    const int K_KP_8 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8);
    const int K_KP_9 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9);
    const int K_KP_0 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0);
    const int K_F13 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13);
    const int K_F14 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14);
    const int K_F15 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15);
    const int K_F16 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16);
    const int K_F17 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17);
    const int K_F18 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18);
    const int K_F19 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19);
    const int K_F20 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20);
    const int K_F21 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21);
    const int K_F22 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22);
    const int K_F23 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23);
    const int K_F24 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24);
    const int K_CLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR);
    const int K_PRIOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR);
    const int K_RETURN2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2);
    const int K_KP_TAB = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB);
    const int K_KP_BACKSPACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE);
    const int K_LCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL);
    const int K_LSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT);
    const int K_LALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT);
    const int K_LGUI = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI);
    const int K_RCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL);
    const int K_RSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT);
    const int K_RALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT);

    /*window flag here*/
    const Uint32 FULLSCREEN = SDL_WINDOW_FULLSCREEN;
    const Uint32 NO_FRAME = SDL_WINDOW_BORDERLESS;
    const Uint32 RESIZABLE = SDL_WINDOW_RESIZABLE;
    const Uint32 HIDDEN = SDL_WINDOW_HIDDEN;
    const Uint32 SKIP_TASK_BAR = SDL_WINDOW_SKIP_TASKBAR;
    const Uint32 POPUP_MENU = SDL_WINDOW_POPUP_MENU;
    const Uint32 ALWAYS_ON_TOP = SDL_WINDOW_ALWAYS_ON_TOP;

    /*event type here*/
    const Uint32 QUIT = SDL_QUIT;
    const Uint32 KEYUP = SDL_KEYUP;
    const Uint32 KEYDOWN = SDL_KEYDOWN;
    const Uint32 MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN;
    const Uint32 MOUSEBUTTONUP = SDL_MOUSEBUTTONUP;
    const Uint32 MOUSEMOTION = SDL_MOUSEMOTION;
    const Uint32 MOUSEWHEEL = SDL_MOUSEWHEEL;
    const Uint32 USEREVENT = SDL_USEREVENT;

    /*Variable here*/
    bool isInit = false;

    void init()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            printf("Error initializing SDL: %s\n", SDL_GetError());
            isInit = false;
            return;
        }
        else
        {
            printf("SDL successfully initialized\n");
            isInit = true;
            return;
        }
    }
    bool get_init() { return isInit; }

    namespace time
    {
        /**
         * @return get time from init in milisecond
         */
        Uint64 get_ticks()
        {
            return SDL_GetTicks64();
        }
        void wait(Uint32 miliseconds)
        {
            SDL_Delay(miliseconds);
        }

        class Clock
        {
        private:
            Uint32 time;
            std::list<Uint32> elapsedTimes;

        public:
            Clock()
            {
                time = SDL_GetTicks();
            }

            Uint32 tick(double fps = 0)
            {
                Uint32 currentTime = SDL_GetTicks();
                Uint32 elapsedTime = currentTime - time;
                time = currentTime;

                if (fps > 0)
                {
                    Uint32 frameTime = 1000 / fps;
                    if (frameTime > elapsedTime)
                    {
                        SDL_Delay(frameTime - elapsedTime);
                        elapsedTime = frameTime;
                    }
                }
                elapsedTimes.push_back(elapsedTime);
                if (elapsedTimes.size() > 10)
                    elapsedTimes.pop_front();
                return elapsedTime;
            }

            double get_fps() const
            {
                double res = 0;
                for (auto et : elapsedTimes)
                {
                    res += et;
                }
                res /= elapsedTimes.size() * 1000;
                res = 1 / res;
                return res;
            }
        };

    };

    namespace math
    {
        double degree_to_radian(double deg)
        {
            return deg * M_PI / 180.0;
        }
        double radian_to_degree(double rad)
        {
            return rad * 180.0 / M_PI;
        }

        /**
         *  a class for 2D vector, also can represent a point on a 2d surface
         * since the simplicity of 2d vector, we dont need get and set function
         * 
         * also for some dumb reason, you can do Vector2 * number, but not number * Vector2
         *
         */
        class Vector2
        {
        public:
            double x, y;
            double epsilon = 1e-6;
            Vector2()
            {
                x = 0;
                y = 0;
            }
            Vector2(const SDL_Point &p)
            {
                x = (double)p.x;
                y = (double)p.y;
            }
            Vector2(const Vector2 &oth)
            {
                x = oth.x;
                y = oth.y;
            }
            template <class T>
            Vector2(T _x, T _y)
            {
                x = _x;
                y = _y;
            }
            Vector2 &operator=(const Vector2 &oth)
            {
                if (this != &oth)
                {
                    x = oth.x;
                    y = oth.y;
                }
                return *this;
            }
            SDLGame::math::Vector2 &operator+=(const SDLGame::math::Vector2 &oth)
            {
                if (this != &oth)
                {
                    x += oth.x;
                    y += oth.y;
                }
                return *this;
            }
            SDLGame::math::Vector2 &operator-=(const SDLGame::math::Vector2 &oth)
            {
                if (this != &oth)
                {
                    x -= oth.x;
                    y -= oth.y;
                }
                return *this;
            }
            template <class T>
            SDLGame::math::Vector2 &operator*=(const T &scalar)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
                x *= scalar;
                y *= scalar;
                return *this;
            }
            SDLGame::math::Vector2 operator+(const SDLGame::math::Vector2 &oth) const
            {
                return SDLGame::math::Vector2(x + oth.x, y + oth.y);
            }
            SDLGame::math::Vector2 operator-() const
            {
                return SDLGame::math::Vector2(-x, -y);
            }
            SDLGame::math::Vector2 operator-(const SDLGame::math::Vector2 &oth) const
            {
                return SDLGame::math::Vector2(x - oth.x, y - oth.y);
            }
            template <class T>
            SDLGame::math::Vector2 operator*(const T &scalar) const
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
                return SDLGame::math::Vector2(scalar * x, scalar * y);
            }

            bool operator==(const SDLGame::math::Vector2 &oth) const
            {
                return abs(x - oth.x) <= epsilon and abs(y - oth.y) <= epsilon;
            }
            double magnitude() const
            {
                return sqrt(x * x + y * y);
            }
            double sqr_magnitude() const
            {
                return x * x + y * y;
            }
            /**
             * @return a normalized vector (a vector with length 1 unit) that have the same direction with the original
             */
            SDLGame::math::Vector2 normalize() const
            {
                return SDLGame::math::Vector2(x / this->magnitude(), y / this->magnitude());
            }
            /**
             *  normalize the vector
             */
            void normalize_ip()
            {
                x /= this->magnitude();
                y /= this->magnitude();
            }
            double dot(const SDLGame::math::Vector2 &oth) const
            {
                return x * oth.x + y * oth.y;
            }
            /**
             * @return angle in degree to another vector in range [0,180] degrees, which is the smallest of 2 angle
             * */
            double angle_to(const SDLGame::math::Vector2 &oth) const
            {
                return acos(this->dot(oth) / (this->magnitude() * oth.magnitude())) * 180.0 / M_PI;
            }

            /**
             * @return a vector that rotated deg degrees counter clockwise
             * */
            SDLGame::math::Vector2 rotate(double deg) const
            {
                double angleInRadians = degree_to_radian(deg);
                return SDLGame::math::Vector2(x * cos(angleInRadians) - y * sin(angleInRadians), x * sin(angleInRadians) + y * cos(angleInRadians));
            }
            /**
             *  make the vector rotate deg degrees counter-clockwise
             */
            void rotate_ip(double deg)
            {
                double _x = x, _y = y, angleInRadians = degree_to_radian(deg);
                x = _x * cos(angleInRadians) - _y * sin(angleInRadians);
                y = x * sin(angleInRadians) + y * cos(angleInRadians);
            }
            double distance_to(const SDLGame::math::Vector2 &oth) const
            {
                return sqrt((x - oth.x) * (x - oth.x) + (y - oth.y) * (y - oth.y));
            }
            /**
             * @return the vector that is the reflection of the current vector to a normal vector
             */
            SDLGame::math::Vector2 reflect(const SDLGame::math::Vector2 &normal) const
            {
                double dotProduct = this->dot(normal);
                return (*this) - normal * 2 * (this->dot(normal));
            }
            void reflect_ip(const SDLGame::math::Vector2 &normal)
            {
                *this = this->reflect(normal);
            }
            SDLGame::math::Vector2 project(const SDLGame::math::Vector2 &normal) const
            {
                return normal * (this->dot(normal) / (normal.sqr_magnitude()));
            }
            void project_ip(const SDLGame::math::Vector2 &normal)
            {
                *this = this->project(normal);
            }
            std::string toString() const
            {
                return "Vector2<" + std::to_string(x) + " , " + std::to_string(y) + ">";
            }
        };
    
        template <class T>
        SDLGame::math::Vector2 operator*(const T &scalar, const SDLGame::math::Vector2 &v)
        {
            static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
            return SDLGame::math::Vector2(scalar * v.x, scalar * v.y);
        }
    }

    namespace rect
    {
        /**
         *  this is a class represent a Rectangle in SDL2, the coordination
         * in sdl2 is x axis points to the right and y axis points downward
         * it's a little unintuitive, but you'll sure have the hang of it and why it should be like that
         *
         * Also for pygame user, there's no = and the rect do it for you, you have to use get and set method,
         * otherwise, ready for immense amount of bug.
         *
         * Though width and height can be negative, it's mostly illegal Rect for most opration, so just dont
         *
         * Most function that have here also have in pygame.Rect, but just some that are most used
         */
        class Rect
        {

        private:
            double x, y, left, top, bottom, right;
            double w, h, width, height;
            double centerx, centery;
            SDLGame::math::Vector2 center, topleft, bottomleft, topright, bottomright, midtop, midleft, midbottom, midright;
            SDLGame::math::Vector2 size;
            double epsilon = 1e-6;

        public:
            Rect()
            {
                x = y = left = top = bottom = right = w = h = width = height = centerx = centery = 0;
            }
            template <class T>
            Rect(T _left, T _top, T _w, T _h)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                x = left = _left;
                y = top = _top;
                w = width = _w;
                h = height = _h;
                bottom = top + h;
                right = left + w;
                size = SDLGame::math::Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = SDLGame::math::Vector2(centerx, centery);
                topleft = SDLGame::math::Vector2(left, top);
                bottomleft = SDLGame::math::Vector2(left, bottom);
                bottomright = SDLGame::math::Vector2(right, bottom);
                topright = SDLGame::math::Vector2(right, top);
                midtop = SDLGame::math::Vector2(centerx, top);
                midleft = SDLGame::math::Vector2(left, centery);
                midbottom = SDLGame::math::Vector2(centerx, bottom);
                midright = SDLGame::math::Vector2(right, centery);
            }
            template <class T>
            Rect(T _left, T _top, const SDLGame::math::Vector2 &_size)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                x = left = _left;
                y = top = _top;
                w = width = _size.x;
                h = height = _size.y;
                bottom = top + h;
                right = left + w;
                size = _size;
                centerx = x + width / 2;
                centery = y + height / 2;
                center = SDLGame::math::Vector2(centerx, centery);
                topleft = SDLGame::math::Vector2(left, top);
                bottomleft = SDLGame::math::Vector2(left, bottom);
                bottomright = SDLGame::math::Vector2(right, bottom);
                topright = SDLGame::math::Vector2(right, top);
                midtop = SDLGame::math::Vector2(centerx, top);
                midleft = SDLGame::math::Vector2(left, centery);
                midbottom = SDLGame::math::Vector2(centerx, bottom);
                midright = SDLGame::math::Vector2(right, centery);
            }
            template <class T>
            Rect(const SDLGame::math::Vector2 &pos, T _w, T _h)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                x = left = pos.x;
                y = top = pos.y;
                w = width = _w;
                h = height = _h;
                bottom = top + h;
                right = left + w;
                size = SDLGame::math::Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = SDLGame::math::Vector2(centerx, centery);
                topleft = SDLGame::math::Vector2(left, top);
                bottomleft = SDLGame::math::Vector2(left, bottom);
                bottomright = SDLGame::math::Vector2(right, bottom);
                topright = SDLGame::math::Vector2(right, top);
                midtop = SDLGame::math::Vector2(centerx, top);
                midleft = SDLGame::math::Vector2(left, centery);
                midbottom = SDLGame::math::Vector2(centerx, bottom);
                midright = SDLGame::math::Vector2(right, centery);
            }
            Rect(const SDLGame::math::Vector2 &pos, const SDLGame::math::Vector2 &_size)
            {
                x = left = pos.x;
                y = top = pos.y;
                w = width = _size.x;
                h = height = _size.y;
                bottom = top + h;
                right = left + w;
                size = _size;
                centerx = x + width / 2;
                centery = y + height / 2;
                center = SDLGame::math::Vector2(centerx, centery);
                topleft = SDLGame::math::Vector2(left, top);
                bottomleft = SDLGame::math::Vector2(left, bottom);
                bottomright = SDLGame::math::Vector2(right, bottom);
                topright = SDLGame::math::Vector2(right, top);
                midtop = SDLGame::math::Vector2(centerx, top);
                midleft = SDLGame::math::Vector2(left, centery);
                midbottom = SDLGame::math::Vector2(centerx, bottom);
                midright = SDLGame::math::Vector2(right, centery);
            }
            /**
             * @return a new rectangle that have been moved by given OFFSET x and y
             */
            Rect &operator=(const Rect &oth)
            {
                if (this != &oth)
                {
                    x = left = oth.getLeft();
                    y = top = oth.getTop();
                    w = width = oth.getWidth();
                    h = height = oth.getHeight();
                    bottom = top + h;
                    right = left + w;
                    size = SDLGame::math::Vector2(w, h);
                    centerx = x + width / 2;
                    centery = y + height / 2;
                    center = SDLGame::math::Vector2(centerx, centery);
                    topleft = SDLGame::math::Vector2(left, top);
                    bottomleft = SDLGame::math::Vector2(left, bottom);
                    bottomright = SDLGame::math::Vector2(right, bottom);
                    topright = SDLGame::math::Vector2(right, top);
                    midtop = SDLGame::math::Vector2(centerx, top);
                    midleft = SDLGame::math::Vector2(left, centery);
                    midbottom = SDLGame::math::Vector2(centerx, bottom);
                    midright = SDLGame::math::Vector2(right, centery);
                }
                return *this;
            }
            bool operator==(const Rect &oth) const
            {
                if (this == &oth)
                    return true;
                return abs(x - oth.getLeft()) <= epsilon and abs(y - oth.getTop()) <= epsilon and abs(w - oth.getWidth()) <= epsilon and abs(h - oth.getHeight()) <= epsilon;
            }
            SDL_FRect to_SDL_FRect() const
            {
                SDL_FRect res = {(float)x, (float)y, (float)w, (float)h};
                return res;
            }
            template <class T>
            Rect move(T offset_x, T offset_y) const
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                Rect res = *this;
                res.x = res.left += offset_x;
                res.y = res.top += offset_y;
                res.bottom = res.top + res.h;
                res.right = res.left + res.w;
                res.centerx = res.x + res.width / 2;
                res.centery = res.y + res.height / 2;
                res.center = SDLGame::math::Vector2(res.centerx, res.centery);
                res.topleft = SDLGame::math::Vector2(res.left, res.top);
                res.bottomleft = SDLGame::math::Vector2(res.left, res.bottom);
                res.bottomright = SDLGame::math::Vector2(res.right, res.bottom);
                res.topright = SDLGame::math::Vector2(res.right, res.top);
                res.midtop = SDLGame::math::Vector2(res.centerx, res.top);
                res.midleft = SDLGame::math::Vector2(res.left, res.centery);
                res.midbottom = SDLGame::math::Vector2(res.centerx, res.bottom);
                res.midright = SDLGame::math::Vector2(res.right, res.centery);
                return res;
            }

            /**
             *  instead of a new one, this just move the rect that called this function
             */
            template <class T>
            void move_ip(T offset_x, T offset_y)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                *this = this->move(offset_x, offset_y);
            }
            /**
             * @return a new rectangle that have been moved by given OFFSET x and y
             */
            Rect move(const SDLGame::math::Vector2 &offset) const
            {
                return this->move(offset.x, offset.y);
            }
            /**
             *  instead of a new one, this just move the rect that called this function
             */
            void move_ip(const SDLGame::math::Vector2 &offset)
            {
                *this = this->move(offset.x, offset.y);
            }

            /**
             * @return a new rectangle that changed the size to given OFFSET, the topleft of the rectangle is remain still
             */
            template <class T>
            Rect inflate(T offset_w, T offset_h) const
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                Rect res = *this;
                res.size += SDLGame::math::Vector2(offset_w, offset_h);
                res.w = res.width += offset_w;
                res.h = res.height += offset_h;
                res.bottom = res.top + res.h;
                res.right = res.left + res.w;
                res.centerx = res.x + res.width / 2;
                res.centery = res.y + res.height / 2;
                res.center = SDLGame::math::Vector2(res.centerx, res.centery);
                res.topleft = SDLGame::math::Vector2(res.left, res.top);
                res.bottomleft = SDLGame::math::Vector2(res.left, res.bottom);
                res.bottomright = SDLGame::math::Vector2(res.right, res.bottom);
                res.topright = SDLGame::math::Vector2(res.right, res.top);
                res.midtop = SDLGame::math::Vector2(res.centerx, res.top);
                res.midleft = SDLGame::math::Vector2(res.left, res.centery);
                res.midbottom = SDLGame::math::Vector2(res.centerx, res.bottom);
                res.midright = SDLGame::math::Vector2(res.right, res.centery);
                return res;
            }
            Rect inflate(const SDLGame::math::Vector2 &offset) const
            {
                return this->inflate(offset.x, offset.y);
            }
            /**
             *  resize current rectangle with given offset, the topleft of the rectangle is remain still
             */
            template <class T>
            void inflate_ip(T offset_w, T offset_h)
            {
                *this = this->inflate(offset_w, offset_h);
            }
            void inflate_ip(const SDLGame::math::Vector2 &offset)
            {
                *this = this->inflate(offset.x, offset.y);
            }

            /**
             *  to update the current rectangle that call the function
             */
            template <class T>
            void update(T _left, T _top, T _w, T _h)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                x = left = _left;
                y = top = _top;
                w = width = _w;
                h = height = _h;
                bottom = top + h;
                right = left + w;
                size = SDLGame::math::Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = SDLGame::math::Vector2(centerx, centery);
                topleft = SDLGame::math::Vector2(left, top);
                bottomleft = SDLGame::math::Vector2(left, bottom);
                bottomright = SDLGame::math::Vector2(right, bottom);
                topright = SDLGame::math::Vector2(right, top);
                midtop = SDLGame::math::Vector2(centerx, top);
                midleft = SDLGame::math::Vector2(left, centery);
                midbottom = SDLGame::math::Vector2(centerx, bottom);
                midright = SDLGame::math::Vector2(right, centery);
            }
            template <class T>
            void update(T _left, T _top, const SDLGame::math::Vector2 &_size)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                x = left = _left;
                y = top = _top;
                w = width = _size.x;
                h = height = _size.y;
                bottom = top + h;
                right = left + w;
                size = _size;
                centerx = x + width / 2;
                centery = y + height / 2;
                center = SDLGame::math::Vector2(centerx, centery);
                topleft = SDLGame::math::Vector2(left, top);
                bottomleft = SDLGame::math::Vector2(left, bottom);
                bottomright = SDLGame::math::Vector2(right, bottom);
                topright = SDLGame::math::Vector2(right, top);
                midtop = SDLGame::math::Vector2(centerx, top);
                midleft = SDLGame::math::Vector2(left, centery);
                midbottom = SDLGame::math::Vector2(centerx, bottom);
                midright = SDLGame::math::Vector2(right, centery);
            }
            template <class T>
            void update(const SDLGame::math::Vector2 &pos, T _w, T _h)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                x = left = pos.x;
                y = top = pos.y;
                w = width = _w;
                h = height = _h;
                bottom = top + h;
                right = left + w;
                size = SDLGame::math::Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = SDLGame::math::Vector2(centerx, centery);
                topleft = SDLGame::math::Vector2(left, top);
                bottomleft = SDLGame::math::Vector2(left, bottom);
                bottomright = SDLGame::math::Vector2(right, bottom);
                topright = SDLGame::math::Vector2(right, top);
                midtop = SDLGame::math::Vector2(centerx, top);
                midleft = SDLGame::math::Vector2(left, centery);
                midbottom = SDLGame::math::Vector2(centerx, bottom);
                midright = SDLGame::math::Vector2(right, centery);
            }
            void update(const SDLGame::math::Vector2 &pos, const SDLGame::math::Vector2 &_size)
            {
                x = left = pos.x;
                y = top = pos.y;
                w = width = _size.x;
                h = height = _size.y;
                bottom = top + h;
                right = left + w;
                size = _size;
                centerx = x + width / 2;
                centery = y + height / 2;
                center = SDLGame::math::Vector2(centerx, centery);
                topleft = SDLGame::math::Vector2(left, top);
                bottomleft = SDLGame::math::Vector2(left, bottom);
                bottomright = SDLGame::math::Vector2(right, bottom);
                topright = SDLGame::math::Vector2(right, top);
                midtop = SDLGame::math::Vector2(centerx, top);
                midleft = SDLGame::math::Vector2(left, centery);
                midbottom = SDLGame::math::Vector2(centerx, bottom);
                midright = SDLGame::math::Vector2(right, centery);
            }
            /**
             *  return a new rectangle that fit another rect but keep the aspect ratio of the caller
             * the position of the rect that return is the position of the caller
             */
            Rect fit(const Rect &oth) const
            {
                Rect res = *this;
                res.setSize(res.size * (oth.getWidth() / res.getWidth()));
                return res;
            }
            /**
             * @return return true if the other rect is completely inside the caller
             */
            bool contains(const Rect &oth) const
            {
                return left <= oth.getLeft() && right >= oth.getRight() && top <= oth.getTop() && bottom >= oth.getBottom();
            }

            template <class T>
            bool collidepoint(T _x, T _y) const
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                return left <= _x and _x <= right and top <= _y and _y <= bottom;
            }
            /**
             * @return return whether the point in param is inside the caller or not
             */
            bool collidepoint(const SDLGame::math::Vector2 &point)
            {
                return left <= point.x and point.x <= right and top <= point.y and point.y <= bottom;
            }
            /**
             * @return return whether the caller collide with the other rect or not
             */
            bool colliderect(const Rect &oth) const
            {
                return !(left > oth.getRight() || right < oth.getLeft() || top > oth.getBottom() || bottom < oth.getTop());
            }
            /**
             * @return return whether the caller collide with any of the rect in the list
             */
            bool collidelist(std::vector<Rect> &rect_list) const
            {
                for (Rect &rect : rect_list)
                    if (this->colliderect(rect))
                        return true;
                return false;
            }

            // Under is mostly get and set func
            template <class T>
            void setWidth(T _w)
            {
                inflate_ip(_w - w, 0);
            }
            template <class T>
            void setHeight(T _h)
            {
                inflate_ip(0, _h - h);
            }
            template <class T>
            void setSize(T _w, T _h)
            {
                inflate_ip(_w - w, _h - h);
            }
            void setSize(const SDLGame::math::Vector2 &_size)
            {
                inflate_ip(_size - size);
            }
            template <class T>
            void setTop(T _y)
            {
                move_ip(0, _y - y);
            }
            template <class T>
            void setLeft(T _x)
            {
                move_ip(_x - x, 0);
            }
            template <class T>
            void setRight(T _x)
            {
                move_ip(_x - right, 0);
            }
            template <class T>
            void setBottom(T _y)
            {
                move_ip(_y - bottom, 0);
            }
            template <class T>
            void setCenter(T _x, T _y)
            {
                move_ip(_x - centerx, _y - centery);
            }
            void setCenter(const SDLGame::math::Vector2 &pos)
            {
                move_ip(pos.x - centerx, pos.y - centery);
            }
            template <class T>
            void setMidTop(T _x, T _y)
            {
                move_ip(_x - centerx, _y - y);
            }
            void setMidTop(const SDLGame::math::Vector2 &pos)
            {
                move_ip(pos.x - centerx, pos.y - y);
            }
            template <class T>
            void setMidBottom(T _x, T _y)
            {
                move_ip(_x - centerx, _y - bottom);
            }
            void setMidBottom(const SDLGame::math::Vector2 &pos)
            {
                move_ip(pos.x - centerx, pos.y - bottom);
            }
            template <class T>
            void setMidLeft(T _x, T _y)
            {
                move_ip(_x - x, _y - centery);
            }
            void setMidLeft(const SDLGame::math::Vector2 &pos)
            {
                move_ip(pos.x - x, pos.y - centery);
            }
            template <class T>
            void setMidRight(T _x, T _y)
            {
                move_ip(_x - right, _y - centery);
            }
            void setMidRight(const SDLGame::math::Vector2 &pos)
            {
                move_ip(pos.x - right, pos.y - centery);
            }
            double getWidth() const { return w; }
            double getHeight() const { return h; }
            double getTop() const { return y; }
            double getLeft() const { return x; }
            double getRight() const { return right; }
            double getBottom() const { return bottom; }
            double getCenterX() const { return centerx; }
            double getCenterY() const { return centery; }
            SDLGame::math::Vector2 getSize() const { return size; }
            SDLGame::math::Vector2 getCenter() const { return center; }
            SDLGame::math::Vector2 getTopLeft() const { return topleft; }
            SDLGame::math::Vector2 getTopRight() const { return topright; }
            SDLGame::math::Vector2 getBottomLeft() const { return bottomleft; }
            SDLGame::math::Vector2 getBottomRight() const { return bottomright; }
            SDLGame::math::Vector2 getMidTop() const { return midtop; }
            SDLGame::math::Vector2 getMidLeft() const { return midleft; }
            SDLGame::math::Vector2 getMidBottom() const { return midbottom; }
            SDLGame::math::Vector2 getMidRight() const { return midright; }

            /**
             *  return a SDL_Rect object from this rect
             */
            SDL_Rect toSDL_Rect() const
            {
                SDL_Rect res = {(int)x, (int)y, (int)w, (int)h};
                return res;
            }
            std::string toString() const
            {
                return "Rect<" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(w) + "," + std::to_string(h) + ">";
            }
        };
    };

    namespace color
    {
        /**
         *  class for color, all values range from [0,255]
         */
        class Color
        {
        public:
            Uint8 r, g, b, a;
            Color()
            {
                r = 0;
                g = 0;
                b = 0;
            }
            template <class T>
            Color(T _r, T _g, T _b)
            {
                r = _r;
                g = _g;
                b = _b;
                a = 255;
            }
            template <class T>
            Color(T _r, T _g, T _b, T _a)
            {
                r = _r;
                g = _g;
                b = _b;
                a = _a;
            }

            SDL_Color toSDL_Color() const
            {
                SDL_Color res = {r, g, b, a};
                return res;
            }
            /**return Uint32 kind of color*/
            Uint32 toUint32Color() const
            {
                return SDL_MapRGBA(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA32), r, g, b, a);
            }
            std::string toString()
            {
                return "Color(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + "," + std::to_string(a) + ")";
            }
        };
    }

    // may be not done yet but good enough
    namespace surface
    {
        class Surface
        {
        private:
            SDLGame::rect::Rect rect;
        public:
            SDL_Surface *surface;
            Uint32 flags;
            Surface()
            {
                flags = 0;
                surface = SDL_CreateRGBSurface(flags, 0, 0, 0, 0, 0, 0, 0);
            }
            Surface(int width, int height, Uint32 _flags = 0)
            {
                flags = _flags;
                surface = SDL_CreateRGBSurface(flags, width, height, 0, 0, 0, 0, 0);
            }

            Surface(const Surface &oth)
            {
                flags = oth.flags;
                surface = SDL_ConvertSurface(oth.surface, oth.surface->format, 0);
            }

            Surface(SDL_Surface *oth)
            {
                flags = oth->flags;
                surface = SDL_ConvertSurface(oth, oth->format, 0);
            }

            Surface &operator=(const Surface &other)
            {
                if (this != &other)
                {
                    SDL_FreeSurface(surface);
                    flags = other.flags;
                    surface = SDL_ConvertSurface(other.surface, other.surface->format, 0);
                }
                return *this;
            }

            SDLGame::rect::Rect &getRect()
            {
                return rect;
            }
            void blit(const Surface &source, const SDLGame::rect::Rect &destrect, SDLGame::rect::Rect area = SDLGame::rect::Rect())
            {
                if (area == SDLGame::rect::Rect())
                    area = SDLGame::rect::Rect(0, 0, source.surface->w, source.surface->h);
                SDL_Rect tmp = rect.toSDL_Rect();
                SDL_BlitSurface(source.surface, &tmp, surface, &tmp);
            }
            void fill(const SDLGame::color::Color &color, SDLGame::rect::Rect area = SDLGame::rect::Rect())
            {
                if (area == SDLGame::rect::Rect())
                    area = SDLGame::rect::Rect(0, 0, surface->w, surface->h);
                SDL_Rect tmp = rect.toSDL_Rect();
                SDL_FillRect(surface, &tmp, color.toUint32Color());
            }
            template <class T>
            void scroll(T offset_x, T offset_y)
            {
                rect.move_ip(offset_x, offset_y);
            }
            SDLGame::math::Vector2 get_size() const
            {
                return rect.getSize();
            }
            double getWidth() const
            {
                return rect.getWidth();
            }
            double getHeight() const
            {
                return rect.getHeight();
            }
            ~Surface()
            {
                SDL_FreeSurface(surface);
            }
        };
    }

    namespace display
    {
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;
        SDLGame::surface::Surface win_surf;
        bool isInit = false;

        SDL_Window *set_mode(int width = 0, int height = 0, Uint32 flags = 0)
        {
            if (width == 0 or height == 0)
            {
                SDL_DisplayMode DM;
                SDL_GetDesktopDisplayMode(0, &DM);
                width = DM.w;
                height = DM.h;
            }
            window = SDL_CreateWindow("SDLGame Custom Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
            renderer = SDL_CreateRenderer(window, -1, 0);
            return window;
        }

        /**
         *  return a Surface object that have reference SDL_surface to the window surface
         */
        SDLGame::surface::Surface &get_surface()
        {
            win_surf = SDLGame::surface::Surface(SDL_GetWindowSurface(window));
            return win_surf;
        }
        /**
         *  if set to true, the mouse will be confine to the window
         * this function get or set the state of mouse being confine or not
         *
         */
        bool grab(int enable = -1)
        {
            if (enable == -1)
                return SDL_GetWindowGrab(window);
            SDL_SetWindowGrab(window, (enable ? SDL_TRUE : SDL_FALSE));
            return enable;
        }

        void set_icon(const SDLGame::surface::Surface &icon)
        {
            SDL_SetWindowIcon(window, icon.surface);
        }

        /**
         *  get and set the borderless state of the active window;
         */
        bool borderless(int enable = -1)
        {
            if (enable == -1)
                return (SDL_GetWindowFlags(window) & SDL_WINDOW_BORDERLESS);
            SDL_SetWindowBordered(window, (enable ? SDL_FALSE : SDL_TRUE));
            return (SDL_GetWindowFlags(window) & SDL_WINDOW_BORDERLESS) > 0;
        }
        void set_caption(const char *title)
        {
            SDL_SetWindowTitle(window, title);
        }
        SDL_Window *get_window()
        {
            return window;
        }
        SDL_Renderer *get_renderer()
        {
            return renderer;
        }
        void quit()
        {
            if (window)
                SDL_DestroyWindow(window);
            if (renderer)
                SDL_DestroyRenderer(renderer);
        }
        void flip()
        {
            if (renderer and window)
                SDL_RenderPresent(renderer);
            else
            {
                printf("Display have not set mode");
            }
        }
    }

    // not yet, this only possible after install SDL3 then we should have the all image format load
    namespace image
    {
        SDLGame::surface::Surface load(const char *img_path)
        {
            return SDLGame::surface::Surface(IMG_Load(img_path));
        }
    }

    namespace key
    {
        namespace
        {
            const Uint8 *keyState;
        }
        /**
         *  assume that you called the SDL_PumpEvents function before calling this, this funciton should work fine
         */
        std::vector<bool> get_pressed()
        {
            int numKeys;
            keyState = SDL_GetKeyboardState(&numKeys);
            std::vector<bool> keys(numKeys);
            for (int i = 0; i < numKeys; ++i)
            {
                keys[i] = keyState[i];
            }
            return keys;
        }
    }

    namespace mouse
    {
        // this weird shiet called anonymous namespace, which can only access within the same namespace unit
        // best for not mess up these var some how
        namespace
        {
            SDLGame::math::Vector2 last_mouse_pos = SDLGame::math::Vector2(-1, -1);
            bool isVisible = true;
        }
        SDLGame::math::Vector2 get_pos()
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            return SDLGame::math::Vector2(x, y);
        }
        std::vector<bool> get_pressed()
        {
            int numButtons = 32;
            Uint32 buttonState = SDL_GetMouseState(NULL, NULL);

            std::vector<bool> buttons(numButtons);
            for (int i = 0; i < numButtons; ++i)
            {
                buttons[i] = buttonState & (1 << i);
            }
            return buttons;
        }
        SDLGame::math::Vector2 get_rel()
        {
            if (last_mouse_pos == SDLGame::math::Vector2(-1, -1))
                return SDLGame::math::Vector2(0, 0);
            int x, y;
            SDL_GetMouseState(&x, &y);
            SDLGame::math::Vector2 res = SDLGame::math::Vector2(x, y) - last_mouse_pos;
            last_mouse_pos = SDLGame::math::Vector2(x, y);
            return res;
        }
        void set_visible(int enable)
        {
            isVisible = SDL_ShowCursor(enable);
        }
        bool get_visible()
        {
            return isVisible;
        }
    }

    namespace event
    {
        /**
         *  class represent a event like keyboard input or mouse click (anything happening in the game)
         */
        class Event
        {
        private:
            std::map<std::string, Uint32> dict;

        public:
            Uint32 type;
            Uint32 timestamp;
            SDL_Event tmp_e;
            Event() {}
            Event(SDL_Event e)
            {
                tmp_e = e;
                type = e.type;
                /**
                 * @todo: leave these here in case need, now type only is good enough
                 */
                // if(e.type == SDL_WINDOWEVENT)
                // {
                //     timestamp = e.window.timestamp;
                //     dict["windowID"] = e.window.windowID;    /**< The associated window */
                //     dict["event"] = e.window.event;
                //     dict["padding1"] = e.window.padding1;
                //     dict["padding2"] = e.window.padding2;
                //     dict["padding3"] = e.window.padding3;
                //     dict["data1"] = e.window.data1;
                //     dict["data2"] = e.window.data2;
                // }
                // else
                if (e.type == SDL_KEYDOWN or e.type == SDL_KEYUP)
                {
                    timestamp = e.key.timestamp;
                    dict["key"] = e.key.keysym.sym;
                }
                else if (e.type == SDL_QUIT)
                {
                    // lol, just here to write const event
                }
                else if (e.type == SDL_MOUSEWHEEL)
                {
                    timestamp = e.wheel.timestamp;
                    dict["x"] = e.wheel.x;
                    dict["y"] = e.wheel.y;
                }
                else if (e.type == SDL_MOUSEBUTTONUP or e.type == SDL_MOUSEBUTTONDOWN)
                {
                    timestamp = e.button.timestamp;
                    dict["button"] = e.button.button;
                    dict["x"] = e.button.x;
                    dict["y"] = e.button.y;
                }
                else if (e.type == SDL_MOUSEMOTION)
                {
                    timestamp = e.motion.timestamp;
                    dict["x"] = e.motion.x;
                    dict["y"] = e.motion.y;
                    dict["xrel"] = e.motion.xrel;
                    dict["yrel"] = e.motion.yrel;
                }
                // else if(e.type == SDL_TEXTINPUT)
                // {

                // }
            }
            Uint32 &operator[](std::string &key)
            {
                if (dict.find(key) != dict.end())
                {
                    return dict[key];
                }
                else
                {
                    throw std::invalid_argument("There's no such key: " + key);
                }
            }
        };
        std::vector<Event> current_events;
        std::vector<Event> &get()
        {
            SDL_PumpEvents();
            current_events.clear();
            SDL_Event e;
            while (SDL_PollEvent(&e))
                current_events.push_back(Event(e));
            return current_events;
        }
        Event tmp;
        /**please only use this for user event*/
        void post(Uint32 event_type)
        {
            tmp.tmp_e.type = event_type;
            SDL_PushEvent(&tmp.tmp_e);
        }
    }

    // TODO: not done, ot yet call quit for everything, sprcificly: window, renderer, mixer, image? ...
    void quit()
    {
        // for (SDL_Texture *tex : textures)
        //     SDL_DestroyTexture(tex);
        SDL_DestroyRenderer(SDLGame::display::renderer);
        SDL_DestroyWindow(SDLGame::display::window);
        SDL_Quit();
        exit(0);
    }

    /**
     *  for the optimization purposes, draw function that affect dirrectly to window now
     * will have a window_ prefix, for example, for draw a rect to window, the funcion name is window_rect
     * every other draw function without the window_ prefix still use CPU to draw, not GPU
     */
    namespace draw
    {
        void window_rect(SDLGame::surface::Surface &surface, SDLGame::color::Color &color, SDLGame::rect::Rect &rect, int width = 0)
        {
            SDL_SetRenderDrawColor(display::renderer, color.r, color.g, color.b, color.a);
            SDL_FRect tmp = rect.to_SDL_FRect();
            if (width == 0)
            {
                SDL_RenderFillRectF(display::renderer, &tmp);
            }
            else
            {
                SDL_RenderDrawRectF(display::renderer, &tmp);
            }
            SDL_RenderPresent(display::renderer);
        }
        void set_pixel(SDLGame::surface::Surface &surface, int x, int y, Uint32 pixel)
        {
            Uint32 *target_pixel = (Uint32 *)((Uint8 *)surface.surface->pixels + y * surface.surface->pitch + x * sizeof(*target_pixel));
            *target_pixel = pixel;
        }

        // Bresenham's line algorithm
        void line(SDLGame::surface::Surface &surface, int x1, int y1, int x2, int y2, SDLGame::color::Color color)
        {
            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);
            int sx = (x1 < x2) ? 1 : -1;
            int sy = (y1 < y2) ? 1 : -1;
            int err = dx - dy;
            SDL_LockSurface(surface.surface);
            while (true)
            {
                set_pixel(surface, x1, y1, color.toUint32Color());

                if (x1 == x2 && y1 == y2)
                {
                    break;
                }

                int e2 = 2 * err;
                if (e2 > -dy)
                {
                    err -= dy;
                    x1 += sx;
                }
                if (e2 < dx)
                {
                    err += dx;
                    y1 += sy;
                }
            }
            SDL_UnlockSurface(surface.surface);
        }
        void draw_ellipse(SDLGame::surface::Surface &surface, int centerX, int centerY, int radiusX, int radiusY, SDLGame::color::Color color)
        {
            SDL_LockSurface(surface.surface);
            for (double angle = 0.0; angle < 2 * M_PI; angle += 0.01)
            {
                int x = centerX + radiusX * cos(angle);
                int y = centerY + radiusY * sin(angle);
                set_pixel(surface, x, y, color.toUint32Color());
            }
            SDL_UnlockSurface(surface.surface);
        }

        void draw_arc(SDLGame::surface::Surface &surface, int centerX, int centerY, int radius, double startAngle, double endAngle, SDLGame::color::Color color)
        {
            SDL_LockSurface(surface.surface);
            for (double angle = startAngle; angle < endAngle; angle += 0.01)
            {
                int x = centerX + radius * cos(angle);
                int y = centerY + radius * sin(angle);
                set_pixel(surface, x, y, color.toUint32Color());
            }
            SDL_UnlockSurface(surface.surface);
        }
        void draw_circle(SDLGame::surface::Surface &surface, int centerX, int centerY, int radius, SDLGame::color::Color color)
        {
            SDL_LockSurface(surface.surface);
            for (double angle = 0.0; angle < 2 * M_PI; angle += 0.01)
            {
                int x = centerX + radius * cos(angle);
                int y = centerY + radius * sin(angle);
                set_pixel(surface, x, y, color.toUint32Color());
            }
            SDL_UnlockSurface(surface.surface);
        }

        void draw_polygon(SDLGame::surface::Surface &surface, std::vector<std::pair<int, int>> points, SDLGame::color::Color color)
        {
            if (points.size() < 3)
                throw std::invalid_argument("can't draw polygon with only 2 vertices or less");
            for (int i = 0; i < int(points.size()) - 1; i++)
            {
                SDLGame::draw::line(surface, points[i].first, points[i].second, points[i + 1].first, points[i + 1].second, color);
            }
            SDLGame::draw::line(surface, points[0].first, points[0].second, points[points.size() - 1].first, points[points.size() - 1].second, color);
        }
    }

};