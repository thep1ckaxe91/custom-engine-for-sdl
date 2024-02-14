/**
 * @authors thep1ckaxe, Ngô Hoan Tài and many authors from SDL2's developers
 * email: ThePickaxe91@gmail.com
 *
 * @brief this is also a replicate for pygame in c++, but due to some exploitation, redoing and still testing
 *
 * REQUIREMENT: SDL2 installed to your mingw/include directory, SDL_image/mixer/ttf in a folder named SDL3 also in your mingw/include
 *
 * all pixel format is RGBA32, fixed
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
#include <windows.h>
#define null NULL
//request high performance gpu
#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;

#ifdef __cplusplus
}
#endif

namespace sdlgame
{
    const int K_a = SDL_SCANCODE_A;
    const int K_b = SDL_SCANCODE_B;
    const int K_c = SDL_SCANCODE_C;
    const int K_d = SDL_SCANCODE_D;
    const int K_e = SDL_SCANCODE_E;
    const int K_f = SDL_SCANCODE_F;
    const int K_g = SDL_SCANCODE_G;
    const int K_h = SDL_SCANCODE_H;
    const int K_i = SDL_SCANCODE_I;
    const int K_j = SDL_SCANCODE_J;
    const int K_k = SDL_SCANCODE_K;
    const int K_l = SDL_SCANCODE_L;
    const int K_m = SDL_SCANCODE_M;
    const int K_n = SDL_SCANCODE_N;
    const int K_o = SDL_SCANCODE_O;
    const int K_p = SDL_SCANCODE_P;
    const int K_q = SDL_SCANCODE_Q;
    const int K_r = SDL_SCANCODE_R;
    const int K_s = SDL_SCANCODE_S;
    const int K_t = SDL_SCANCODE_T;
    const int K_u = SDL_SCANCODE_U;
    const int K_v = SDL_SCANCODE_V;
    const int K_w = SDL_SCANCODE_W;
    const int K_x = SDL_SCANCODE_X;
    const int K_y = SDL_SCANCODE_Y;
    const int K_z = SDL_SCANCODE_Z;

    const int K_0 = SDL_SCANCODE_0;
    const int K_1 = SDL_SCANCODE_1;
    const int K_2 = SDL_SCANCODE_2;
    const int K_3 = SDL_SCANCODE_3;
    const int K_4 = SDL_SCANCODE_4;
    const int K_5 = SDL_SCANCODE_5;
    const int K_6 = SDL_SCANCODE_6;
    const int K_7 = SDL_SCANCODE_7;
    const int K_8 = SDL_SCANCODE_8;
    const int K_9 = SDL_SCANCODE_9;

    const int K_F1 = SDL_SCANCODE_F1;
    const int K_F2 = SDL_SCANCODE_F2;
    const int K_F3 = SDL_SCANCODE_F3;
    const int K_F4 = SDL_SCANCODE_F4;
    const int K_F5 = SDL_SCANCODE_F5;
    const int K_F6 = SDL_SCANCODE_F6;
    const int K_F7 = SDL_SCANCODE_F7;
    const int K_F8 = SDL_SCANCODE_F8;
    const int K_F9 = SDL_SCANCODE_F9;
    const int K_F10 = SDL_SCANCODE_F10;
    const int K_F11 = SDL_SCANCODE_F11;
    const int K_F12 = SDL_SCANCODE_F12;

    const int K_SPACE = SDL_SCANCODE_SPACE;
    const int K_COMMA = SDL_SCANCODE_COMMA;
    const int K_PERIOD = SDL_SCANCODE_PERIOD;
    const int K_SLASH = SDL_SCANCODE_SLASH;
    const int K_SEMICOLON = SDL_SCANCODE_SEMICOLON;
    const int K_APOSTROPHE = SDL_SCANCODE_APOSTROPHE;
    const int K_LEFTBRACKET = SDL_SCANCODE_LEFTBRACKET;
    const int K_RIGHTBRACKET = SDL_SCANCODE_RIGHTBRACKET;
    const int K_BACKSLASH = SDL_SCANCODE_BACKSLASH;
    const int K_MINUS = SDL_SCANCODE_MINUS;
    const int K_EQUALS = SDL_SCANCODE_EQUALS;
    const int K_BACKSPACE = SDL_SCANCODE_BACKSPACE;
    const int K_RETURN = SDL_SCANCODE_RETURN;

    const int K_CAPSLOCK = SDL_SCANCODE_CAPSLOCK;
    const int K_SCROLLLOCK = SDL_SCANCODE_SCROLLLOCK;
    const int K_NUMLOCKCLEAR = SDL_SCANCODE_NUMLOCKCLEAR;
    const int K_INSERT = SDL_SCANCODE_INSERT;
    const int K_HOME = SDL_SCANCODE_HOME;
    const int K_PAGEUP = SDL_SCANCODE_PAGEUP;
    const int K_DELETE = SDL_SCANCODE_DELETE;
    const int K_END = SDL_SCANCODE_END;
    const int K_PAGEDOWN = SDL_SCANCODE_PAGEDOWN;
    const int K_RIGHT = SDL_SCANCODE_RIGHT;
    const int K_LEFT = SDL_SCANCODE_LEFT;
    const int K_DOWN = SDL_SCANCODE_DOWN;
    const int K_UP = SDL_SCANCODE_UP;

    const int K_KP_DIVIDE = SDL_SCANCODE_KP_DIVIDE;
    const int K_KP_MULTIPLY = SDL_SCANCODE_KP_MULTIPLY;
    const int K_KP_MINUS = SDL_SCANCODE_KP_MINUS;
    const int K_KP_PLUS = SDL_SCANCODE_KP_PLUS;
    const int K_KP_ENTER = SDL_SCANCODE_KP_ENTER;
    const int K_KP_1 = SDL_SCANCODE_KP_1;
    const int K_KP_2 = SDL_SCANCODE_KP_2;
    const int K_KP_3 = SDL_SCANCODE_KP_3;
    const int K_KP_4 = SDL_SCANCODE_KP_4;
    const int K_KP_5 = SDL_SCANCODE_KP_5;
    const int K_KP_6 = SDL_SCANCODE_KP_6;
    const int K_KP_7 = SDL_SCANCODE_KP_7;
    const int K_KP_8 = SDL_SCANCODE_KP_8;
    const int K_KP_9 = SDL_SCANCODE_KP_9;
    const int K_KP_0 = SDL_SCANCODE_KP_0;
    const int K_KP_PERIOD = SDL_SCANCODE_KP_PERIOD;

    const int K_APPLICATION = SDL_SCANCODE_APPLICATION;
    const int K_POWER = SDL_SCANCODE_POWER;
    const int K_KP_EQUALS = SDL_SCANCODE_KP_EQUALS;
    const int K_F13 = SDL_SCANCODE_F13;
    const int K_F14 = SDL_SCANCODE_F14;
    const int K_F15 = SDL_SCANCODE_F15;
    const int K_F16 = SDL_SCANCODE_F16;
    const int K_F17 = SDL_SCANCODE_F17;
    const int K_F18 = SDL_SCANCODE_F18;
    const int K_F19 = SDL_SCANCODE_F19;
    const int K_F20 = SDL_SCANCODE_F20;
    const int K_F21 = SDL_SCANCODE_F21;
    const int K_F22 = SDL_SCANCODE_F22;
    const int K_F23 = SDL_SCANCODE_F23;
    const int K_F24 = SDL_SCANCODE_F24;
    const int K_EXECUTE = SDL_SCANCODE_EXECUTE;
    const int K_HELP = SDL_SCANCODE_HELP;
    const int K_MENU = SDL_SCANCODE_MENU;
    const int K_SELECT = SDL_SCANCODE_SELECT;
    const int K_STOP = SDL_SCANCODE_STOP;
    const int K_AGAIN = SDL_SCANCODE_AGAIN;
    const int K_UNDO = SDL_SCANCODE_UNDO;
    const int K_CUT = SDL_SCANCODE_CUT;
    const int K_COPY = SDL_SCANCODE_COPY;
    const int K_PASTE = SDL_SCANCODE_PASTE;
    const int K_FIND = SDL_SCANCODE_FIND;
    const int K_MUTE = SDL_SCANCODE_MUTE;
    const int K_VOLUMEUP = SDL_SCANCODE_VOLUMEUP;
    const int K_VOLUMEDOWN = SDL_SCANCODE_VOLUMEDOWN;

    /*window flag here*/

    const Uint32 FULLSCREEN = SDL_WINDOW_FULLSCREEN;
    const Uint32 NO_FRAME = SDL_WINDOW_BORDERLESS;
    const Uint32 RESIZABLE = SDL_WINDOW_RESIZABLE;
    const Uint32 HIDDEN = SDL_WINDOW_HIDDEN;
    const Uint32 SKIP_TASK_BAR = SDL_WINDOW_SKIP_TASKBAR;
    const Uint32 POPUP_MENU = SDL_WINDOW_POPUP_MENU;
    const Uint32 ALWAYS_ON_TOP = SDL_WINDOW_ALWAYS_ON_TOP;
    const Uint32 RENDERER_ACCELERATED = SDL_RENDERER_ACCELERATED;
    // const Uint32 DOUBLE_BUFFERING = SDL_GL_DOUBLEBUFFER; /**not working, pls dont use*/

    /*Texture flags ?*/

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
            exit(0);
            isInit = false;
            return;
        }
        else
        {
            printf("SDL successfully initialized\n");
            isInit = true;
            return;
        }
        if(IMG_Init(IMG_INIT_AVIF|IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_WEBP|IMG_INIT_TIF)){
            printf("Failed to init any image flags\n");
            exit(0);
        }
    }
    bool get_init() { return isInit; }
    std::string get_abs_path(){
        return std::string(SDL_GetBasePath());
    }
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
            double delta_time() const {
                return elapsedTimes.back()*1.0/1000.0;
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
            sdlgame::math::Vector2 &operator+=(const sdlgame::math::Vector2 &oth)
            {
                if (this != &oth)
                {
                    x += oth.x;
                    y += oth.y;
                }
                return *this;
            }
            sdlgame::math::Vector2 &operator-=(const sdlgame::math::Vector2 &oth)
            {
                if (this != &oth)
                {
                    x -= oth.x;
                    y -= oth.y;
                }
                return *this;
            }
            template <class T>
            sdlgame::math::Vector2 &operator*=(const T &scalar)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
                x *= scalar;
                y *= scalar;
                return *this;
            }
            sdlgame::math::Vector2 operator+(const sdlgame::math::Vector2 &oth) const
            {
                return sdlgame::math::Vector2(x + oth.x, y + oth.y);
            }
            sdlgame::math::Vector2 operator-() const
            {
                return sdlgame::math::Vector2(-x, -y);
            }
            sdlgame::math::Vector2 operator-(const sdlgame::math::Vector2 &oth) const
            {
                return sdlgame::math::Vector2(x - oth.x, y - oth.y);
            }
            template <class T>
            sdlgame::math::Vector2 operator*(const T &scalar) const
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
                return sdlgame::math::Vector2(scalar * x, scalar * y);
            }

            bool operator==(const sdlgame::math::Vector2 &oth) const
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
            sdlgame::math::Vector2 normalize() const
            {
                return sdlgame::math::Vector2(x / this->magnitude(), y / this->magnitude());
            }
            /**
             *  normalize the vector
             */
            void normalize_ip()
            {
                x /= this->magnitude();
                y /= this->magnitude();
            }
            double dot(const sdlgame::math::Vector2 &oth) const
            {
                return x * oth.x + y * oth.y;
            }
            /**
             * @return angle in degree to another vector in range [0,180] degrees, which is the smallest of 2 angle
             * */
            double angle_to(const sdlgame::math::Vector2 &oth) const
            {
                return acos(this->dot(oth) / (this->magnitude() * oth.magnitude())) * 180.0 / M_PI;
            }

            /**
             * @return a vector that rotated deg degrees counter clockwise
             * */
            sdlgame::math::Vector2 rotate(double deg) const
            {
                double angleInRadians = degree_to_radian(deg);
                return sdlgame::math::Vector2(x * cos(angleInRadians) - y * sin(angleInRadians), x * sin(angleInRadians) + y * cos(angleInRadians));
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
            double distance_to(const sdlgame::math::Vector2 &oth) const
            {
                return sqrt((x - oth.x) * (x - oth.x) + (y - oth.y) * (y - oth.y));
            }
            /**
             * @return the vector that is the reflection of the current vector to a normal vector
             */
            sdlgame::math::Vector2 reflect(const sdlgame::math::Vector2 &normal) const
            {
                double dotProduct = this->dot(normal);
                return (*this) - normal * 2 * (this->dot(normal));
            }
            void reflect_ip(const sdlgame::math::Vector2 &normal)
            {
                *this = this->reflect(normal);
            }
            sdlgame::math::Vector2 project(const sdlgame::math::Vector2 &normal) const
            {
                return normal * (this->dot(normal) / (normal.sqr_magnitude()));
            }
            void project_ip(const sdlgame::math::Vector2 &normal)
            {
                *this = this->project(normal);
            }
            std::string toString() const
            {
                return "Vector2<" + std::to_string(x) + " , " + std::to_string(y) + ">";
            }
        };

        template <class T>
        sdlgame::math::Vector2 operator*(const T &scalar, const sdlgame::math::Vector2 &v)
        {
            static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
            return sdlgame::math::Vector2(scalar * v.x, scalar * v.y);
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
         * 
         * WARNING: not fully tested yet
         */
        class Rect
        {

        private:
            double x, y, left, top, bottom, right;
            double w, h, width, height;
            double centerx, centery;
            sdlgame::math::Vector2 center, topleft, bottomleft, topright, bottomright, midtop, midleft, midbottom, midright;
            sdlgame::math::Vector2 size;
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
                size = sdlgame::math::Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = sdlgame::math::Vector2(centerx, centery);
                topleft = sdlgame::math::Vector2(left, top);
                bottomleft = sdlgame::math::Vector2(left, bottom);
                bottomright = sdlgame::math::Vector2(right, bottom);
                topright = sdlgame::math::Vector2(right, top);
                midtop = sdlgame::math::Vector2(centerx, top);
                midleft = sdlgame::math::Vector2(left, centery);
                midbottom = sdlgame::math::Vector2(centerx, bottom);
                midright = sdlgame::math::Vector2(right, centery);
            }
            template <class T>
            Rect(T _left, T _top, sdlgame::math::Vector2 _size)
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
                center = sdlgame::math::Vector2(centerx, centery);
                topleft = sdlgame::math::Vector2(left, top);
                bottomleft = sdlgame::math::Vector2(left, bottom);
                bottomright = sdlgame::math::Vector2(right, bottom);
                topright = sdlgame::math::Vector2(right, top);
                midtop = sdlgame::math::Vector2(centerx, top);
                midleft = sdlgame::math::Vector2(left, centery);
                midbottom = sdlgame::math::Vector2(centerx, bottom);
                midright = sdlgame::math::Vector2(right, centery);
            }
            template <class T>
            Rect(sdlgame::math::Vector2 pos, T _w, T _h)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                x = left = pos.x;
                y = top = pos.y;
                w = width = _w;
                h = height = _h;
                bottom = top + h;
                right = left + w;
                size = sdlgame::math::Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = sdlgame::math::Vector2(centerx, centery);
                topleft = sdlgame::math::Vector2(left, top);
                bottomleft = sdlgame::math::Vector2(left, bottom);
                bottomright = sdlgame::math::Vector2(right, bottom);
                topright = sdlgame::math::Vector2(right, top);
                midtop = sdlgame::math::Vector2(centerx, top);
                midleft = sdlgame::math::Vector2(left, centery);
                midbottom = sdlgame::math::Vector2(centerx, bottom);
                midright = sdlgame::math::Vector2(right, centery);
            }
            Rect(sdlgame::math::Vector2 pos, sdlgame::math::Vector2 _size)
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
                center = sdlgame::math::Vector2(centerx, centery);
                topleft = sdlgame::math::Vector2(left, top);
                bottomleft = sdlgame::math::Vector2(left, bottom);
                bottomright = sdlgame::math::Vector2(right, bottom);
                topright = sdlgame::math::Vector2(right, top);
                midtop = sdlgame::math::Vector2(centerx, top);
                midleft = sdlgame::math::Vector2(left, centery);
                midbottom = sdlgame::math::Vector2(centerx, bottom);
                midright = sdlgame::math::Vector2(right, centery);
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
                    size = sdlgame::math::Vector2(w, h);
                    centerx = x + width / 2;
                    centery = y + height / 2;
                    center = sdlgame::math::Vector2(centerx, centery);
                    topleft = sdlgame::math::Vector2(left, top);
                    bottomleft = sdlgame::math::Vector2(left, bottom);
                    bottomright = sdlgame::math::Vector2(right, bottom);
                    topright = sdlgame::math::Vector2(right, top);
                    midtop = sdlgame::math::Vector2(centerx, top);
                    midleft = sdlgame::math::Vector2(left, centery);
                    midbottom = sdlgame::math::Vector2(centerx, bottom);
                    midright = sdlgame::math::Vector2(right, centery);
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
                res.center = sdlgame::math::Vector2(res.centerx, res.centery);
                res.topleft = sdlgame::math::Vector2(res.left, res.top);
                res.bottomleft = sdlgame::math::Vector2(res.left, res.bottom);
                res.bottomright = sdlgame::math::Vector2(res.right, res.bottom);
                res.topright = sdlgame::math::Vector2(res.right, res.top);
                res.midtop = sdlgame::math::Vector2(res.centerx, res.top);
                res.midleft = sdlgame::math::Vector2(res.left, res.centery);
                res.midbottom = sdlgame::math::Vector2(res.centerx, res.bottom);
                res.midright = sdlgame::math::Vector2(res.right, res.centery);
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
            Rect move(const sdlgame::math::Vector2 &offset) const
            {
                return this->move(offset.x, offset.y);
            }
            /**
             *  instead of a new one, this just move the rect that called this function
             */
            void move_ip(const sdlgame::math::Vector2 &offset)
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
                res.size += sdlgame::math::Vector2(offset_w, offset_h);
                res.w = res.width += offset_w;
                res.h = res.height += offset_h;
                res.bottom = res.top + res.h;
                res.right = res.left + res.w;
                res.centerx = res.x + res.width / 2;
                res.centery = res.y + res.height / 2;
                res.center = sdlgame::math::Vector2(res.centerx, res.centery);
                res.topleft = sdlgame::math::Vector2(res.left, res.top);
                res.bottomleft = sdlgame::math::Vector2(res.left, res.bottom);
                res.bottomright = sdlgame::math::Vector2(res.right, res.bottom);
                res.topright = sdlgame::math::Vector2(res.right, res.top);
                res.midtop = sdlgame::math::Vector2(res.centerx, res.top);
                res.midleft = sdlgame::math::Vector2(res.left, res.centery);
                res.midbottom = sdlgame::math::Vector2(res.centerx, res.bottom);
                res.midright = sdlgame::math::Vector2(res.right, res.centery);
                return res;
            }
            Rect inflate(const sdlgame::math::Vector2 &offset) const
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
            void inflate_ip(const sdlgame::math::Vector2 &offset)
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
                size = sdlgame::math::Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = sdlgame::math::Vector2(centerx, centery);
                topleft = sdlgame::math::Vector2(left, top);
                bottomleft = sdlgame::math::Vector2(left, bottom);
                bottomright = sdlgame::math::Vector2(right, bottom);
                topright = sdlgame::math::Vector2(right, top);
                midtop = sdlgame::math::Vector2(centerx, top);
                midleft = sdlgame::math::Vector2(left, centery);
                midbottom = sdlgame::math::Vector2(centerx, bottom);
                midright = sdlgame::math::Vector2(right, centery);
            }
            template <class T>
            void update(T _left, T _top, const sdlgame::math::Vector2 &_size)
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
                center = sdlgame::math::Vector2(centerx, centery);
                topleft = sdlgame::math::Vector2(left, top);
                bottomleft = sdlgame::math::Vector2(left, bottom);
                bottomright = sdlgame::math::Vector2(right, bottom);
                topright = sdlgame::math::Vector2(right, top);
                midtop = sdlgame::math::Vector2(centerx, top);
                midleft = sdlgame::math::Vector2(left, centery);
                midbottom = sdlgame::math::Vector2(centerx, bottom);
                midright = sdlgame::math::Vector2(right, centery);
            }
            template <class T>
            void update(const sdlgame::math::Vector2 &pos, T _w, T _h)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                x = left = pos.x;
                y = top = pos.y;
                w = width = _w;
                h = height = _h;
                bottom = top + h;
                right = left + w;
                size = sdlgame::math::Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = sdlgame::math::Vector2(centerx, centery);
                topleft = sdlgame::math::Vector2(left, top);
                bottomleft = sdlgame::math::Vector2(left, bottom);
                bottomright = sdlgame::math::Vector2(right, bottom);
                topright = sdlgame::math::Vector2(right, top);
                midtop = sdlgame::math::Vector2(centerx, top);
                midleft = sdlgame::math::Vector2(left, centery);
                midbottom = sdlgame::math::Vector2(centerx, bottom);
                midright = sdlgame::math::Vector2(right, centery);
            }
            void update(const sdlgame::math::Vector2 &pos, const sdlgame::math::Vector2 &_size)
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
                center = sdlgame::math::Vector2(centerx, centery);
                topleft = sdlgame::math::Vector2(left, top);
                bottomleft = sdlgame::math::Vector2(left, bottom);
                bottomright = sdlgame::math::Vector2(right, bottom);
                topright = sdlgame::math::Vector2(right, top);
                midtop = sdlgame::math::Vector2(centerx, top);
                midleft = sdlgame::math::Vector2(left, centery);
                midbottom = sdlgame::math::Vector2(centerx, bottom);
                midright = sdlgame::math::Vector2(right, centery);
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
            bool collidepoint(const sdlgame::math::Vector2 &point)
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
            void setSize(const sdlgame::math::Vector2 &_size)
            {
                inflate_ip(_size - size);
            }
            template <class T>
            void setTop(T _y)
            {
                move_ip(T(0), T(_y - y));
            }
            template <class T>
            void setLeft(T _x)
            {
                move_ip(T(_x - x), T(0));
            }
            template <class T>
            void setRight(T _x)
            {
                move_ip(T(_x - right), T(0));
            }
            template <class T>
            void setBottom(T _y)
            {
                move_ip(T(_y - bottom), T(0));
            }
            template <class T>
            void setCenter(T _x, T _y)
            {
                move_ip(_x - centerx, _y - centery);
            }
            void setCenter(const sdlgame::math::Vector2 &pos)
            {
                move_ip(pos.x - centerx, pos.y - centery);
            }
            template <class T>
            void setMidTop(T _x, T _y)
            {
                move_ip(_x - centerx, _y - y);
            }
            void setMidTop(const sdlgame::math::Vector2 &pos)
            {
                move_ip(pos.x - centerx, pos.y - y);
            }
            template <class T>
            void setMidBottom(T _x, T _y)
            {
                move_ip(_x - centerx, _y - bottom);
            }
            void setMidBottom(const sdlgame::math::Vector2 &pos)
            {
                move_ip(pos.x - centerx, pos.y - bottom);
            }
            template <class T>
            void setMidLeft(T _x, T _y)
            {
                move_ip(_x - x, _y - centery);
            }
            void setMidLeft(const sdlgame::math::Vector2 &pos)
            {
                move_ip(pos.x - x, pos.y - centery);
            }
            template <class T>
            void setMidRight(T _x, T _y)
            {
                move_ip(_x - right, _y - centery);
            }
            void setMidRight(const sdlgame::math::Vector2 &pos)
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
            sdlgame::math::Vector2 getSize() const { return size; }
            sdlgame::math::Vector2 getCenter() const { return center; }
            sdlgame::math::Vector2 getTopLeft() const { return topleft; }
            sdlgame::math::Vector2 getTopRight() const { return topright; }
            sdlgame::math::Vector2 getBottomLeft() const { return bottomleft; }
            sdlgame::math::Vector2 getBottomRight() const { return bottomright; }
            sdlgame::math::Vector2 getMidTop() const { return midtop; }
            sdlgame::math::Vector2 getMidLeft() const { return midleft; }
            sdlgame::math::Vector2 getMidBottom() const { return midbottom; }
            sdlgame::math::Vector2 getMidRight() const { return midright; }

            /**
             *  return a SDL_Rect object from this rect
             */
            SDL_Rect to_SDL_Rect() const
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
        std::unordered_map<std::string,std::vector<uint8_t>> color_name = {
            {"maroon",{128,0,0}},
            {"dark red",{139,0,0}},
            {"brown",{165,42,42}},
            {"firebrick",{178,34,34}},
            {"crimson",{220,20,60}},
            {"red",{255,0,0}},
            {"tomato",{255,99,71}},
            {"coral",{255,127,80}},
            {"indian red",{205,92,92}},
            {"light coral",{240,128,128}},
            {"dark salmon",{233,150,122}},
            {"salmon",{250,128,114}},
            {"light salmon",{255,160,122}},
            {"orange red",{255,69,0}},
            {"dark orange",{255,140,0}},
            {"orange",{255,165,0}},
            {"gold",{255,215,0}},
            {"dark golden rod",{184,134,11}},
            {"golden rod",{218,165,32}},
            {"pale golden rod",{238,232,170}},
            {"dark khaki",{189,183,107}},
            {"khaki",{240,230,140}},
            {"olive",{128,128,0}},
            {"yellow",{255,255,0}},
            {"yellow green",{154,205,50}},
            {"dark olive green",{85,107,47}},
            {"olive drab",{107,142,35}},
            {"lawn green",{124,252,0}},
            {"chartreuse",{127,255,0}},
            {"green yellow",{173,255,47}},
            {"dark green",{0,100,0}},
            {"green",{0,128,0}},
            {"forest green",{34,139,34}},
            {"lime",{0,255,0}},
            {"lime green",{50,205,50}},
            {"light green",{144,238,144}},
            {"pale green",{152,251,152}},
            {"dark sea green",{143,188,143}},
            {"medium spring green",{0,250,154}},
            {"spring green",{0,255,127}},
            {"sea green",{46,139,87}},
            {"medium aqua marine",{102,205,170}},
            {"medium sea green",{60,179,113}},
            {"light sea green",{32,178,170}},
            {"dark slate gray",{47,79,79}},
            {"teal",{0,128,128}},
            {"dark cyan",{0,139,139}},
            {"aqua",{0,255,255}},
            {"cyan",{0,255,255}},
            {"light cyan",{224,255,255}},
            {"dark turquoise",{0,206,209}},
            {"turquoise",{64,224,208}},
            {"medium turquoise",{72,209,204}},
            {"pale turquoise",{175,238,238}},
            {"aqua marine",{127,255,212}},
            {"powder blue",{176,224,230}},
            {"cadet blue",{95,158,160}},
            {"steel blue",{70,130,180}},
            {"corn flower blue",{100,149,237}},
            {"deep sky blue",{0,191,255}},
            {"dodger blue",{30,144,255}},
            {"light blue",{173,216,230}},
            {"sky blue",{135,206,235}},
            {"light sky blue",{135,206,250}},
            {"midnight blue",{25,25,112}},
            {"navy",{0,0,128}},
            {"dark blue",{0,0,139}},
            {"medium blue",{0,0,205}},
            {"blue",{0,0,255}},
            {"royal blue",{65,105,225}},
            {"blue violet",{138,43,226}},
            {"indigo",{75,0,130}},
            {"dark slate blue",{72,61,139}},
            {"slate blue",{106,90,205}},
            {"medium slate blue",{123,104,238}},
            {"medium purple",{147,112,219}},
            {"dark magenta",{139,0,139}},
            {"dark violet",{148,0,211}},
            {"dark orchid",{153,50,204}},
            {"medium orchid",{186,85,211}},
            {"purple",{128,0,128}},
            {"thistle",{216,191,216}},
            {"plum",{221,160,221}},
            {"violet",{238,130,238}},
            {"magenta",{255,0,255}},
            {"fuchsia",{255,0,255}},
            {"orchid",{218,112,214}},
            {"medium violet red",{199,21,133}},
            {"pale violet red",{219,112,147}},
            {"deep pink",{255,20,147}},
            {"hot pink",{255,105,180}},
            {"light pink",{255,182,193}},
            {"pink",{255,192,203}},
            {"antique white",{250,235,215}},
            {"beige",{245,245,220}},
            {"bisque",{255,228,196}},
            {"blanched almond",{255,235,205}},
            {"wheat",{245,222,179}},
            {"corn silk",{255,248,220}},
            {"lemon chiffon",{255,250,205}},
            {"light golden rod yellow",{250,250,210}},
            {"light yellow",{255,255,224}},
            {"saddle brown",{139,69,19}},
            {"sienna",{160,82,45}},
            {"chocolate",{210,105,30}},
            {"peru",{205,133,63}},
            {"sandy brown",{244,164,96}},
            {"burly wood",{222,184,135}},
            {"tan",{210,180,140}},
            {"rosy brown",{188,143,143}},
            {"moccasin",{255,228,181}},
            {"navajo white",{255,222,173}},
            {"peach puff",{255,218,185}},
            {"misty rose",{255,228,225}},
            {"lavender blush",{255,240,245}},
            {"linen",{250,240,230}},
            {"old lace",{253,245,230}},
            {"papaya whip",{255,239,213}},
            {"sea shell",{255,245,238}},
            {"mint cream",{245,255,250}},
            {"slate gray",{112,128,144}},
            {"light slate gray",{119,136,153}},
            {"light steel blue",{176,196,222}},
            {"lavender",{230,230,250}},
            {"floral white",{255,250,240}},
            {"alice blue",{240,248,255}},
            {"ghost white",{248,248,255}},
            {"honeydew",{240,255,240}},
            {"ivory",{255,255,240}},
            {"azure",{240,255,255}},
            {"snow",{255,250,250}},
            {"black",{0,0,0}},
            {"dim gray",{105,105,105}},
            {"dim grey",{105,105,105}},
            {"gray",{128,128,128}},
            {"grey",{128,128,128}},
            {"dark gray",{169,169,169}},
            {"dark grey",{169,169,169}},
            {"silver",{192,192,192}},
            {"light gray",{211,211,211}},
            {"light grey",{211,211,211}},
            {"gainsboro",{220,220,220}},
            {"white smoke",{245,245,245}},
            {"white",{255,255,255}}
        };
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
            Color(const char* c_name){
                std::string name = std::string(c_name);
                for(char& c:name) c=std::tolower(c);
                if(color_name.find(name)==color_name.end()){
                    printf("no such color: %s\n",c_name);
                    exit(0);
                }
                r = color_name[name][0];
                g = color_name[name][1];
                b = color_name[name][2];
                a = 255;
            }
            Color(std::string name){
                for(char& c:name) c=std::tolower(c);
                if(color_name.find(name)==color_name.end()){
                    std::cout<<"no such color: "<<name<<"\n";
                    exit(0);
                }
                r = color_name[name][0];
                g = color_name[name][1];
                b = color_name[name][2];
                a = 255;
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
    namespace surface{
        class Surface;
    }
    
    namespace display{
        extern SDL_Window *window;
        extern SDL_Renderer *renderer;
        extern bool isInit;
    }
    
    namespace surface
    {
        /**
         * @brief since the problem mostly related to the heavy draw and surface manage in pygame
         * this module is mostly focus optimiszing the surface class, the texture pointer should be null if the surface is represent window
         * after set_mode is called
         */
        class Surface
        {
        public:
            sdlgame::math::Vector2 size;
            SDL_Texture *texture = nullptr;
            Uint32 flags = 0;
            Surface()
            {
                flags = 0;
                texture = SDL_CreateTexture(sdlgame::display::renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, 0, 0);
            }
            Surface(int width, int height, Uint32 _flags = 0)
            {
                flags = _flags;
                if(!(texture = SDL_CreateTexture(sdlgame::display::renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, width, height))){
                    printf("Failed to create texture\n");
                    exit(0);
                }
                size = sdlgame::math::Vector2(width, height);
                SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
                SDL_SetRenderTarget(sdlgame::display::renderer, texture);
                SDL_SetRenderDrawColor(sdlgame::display::renderer, 0, 0, 0, 0);
                SDL_RenderClear(sdlgame::display::renderer);
                SDL_SetRenderTarget(sdlgame::display::renderer, NULL);
            }
            Surface(const Surface &oth)
            {
                flags = oth.flags;
                texture = oth.texture;
                size = oth.size;
            }

            Surface(SDL_Texture *oth)
            {
                int w,h;
                SDL_QueryTexture(oth,NULL,NULL,&w,&h);
                texture = SDL_CreateTexture(sdlgame::display::renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,w,h);
                SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
                SDL_SetRenderTarget(sdlgame::display::renderer, texture);
                SDL_SetRenderDrawColor(sdlgame::display::renderer, 0, 0, 0, 0);
                SDL_RenderClear(sdlgame::display::renderer);
                SDL_RenderCopy(sdlgame::display::renderer,oth,NULL,NULL);
                SDL_SetRenderTarget(sdlgame::display::renderer, NULL);
                size = sdlgame::math::Vector2(w, h);
            }
            Surface(SDL_Surface *surf)
            {
                texture = SDL_CreateTextureFromSurface(sdlgame::display::renderer, surf);
                // printf("tex: %p | surf: %p\n",texture,surf);
                if(texture == NULL){
                    printf("Failed to create texture form surface\nErr:%s\n",SDL_GetError());
                    exit(0);
                }
                size = sdlgame::math::Vector2(surf->w,surf->h);
            }
            Surface &operator=(const Surface &other)
            {
                if (this != &other)
                {
                    SDL_DestroyTexture(texture);
                    flags = other.flags;
                    int w,h;
                    SDL_QueryTexture(other.texture,NULL,NULL,&w,&h);
                    texture = SDL_CreateTexture(sdlgame::display::renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_TARGET,w,h);
                    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
                    SDL_SetRenderTarget(sdlgame::display::renderer, texture);
                    SDL_SetRenderDrawColor(sdlgame::display::renderer, 0, 0, 0, 0);
                    SDL_RenderClear(sdlgame::display::renderer);
                    SDL_RenderCopy(sdlgame::display::renderer,other.texture,NULL,NULL);
                    SDL_SetRenderTarget(sdlgame::display::renderer, NULL);
                    size = other.size;
                }
                return *this;
            }
            /**
             * Return a copy of this surface, 
            */
            Surface copy() const {
                sdlgame::surface::Surface res = sdlgame::surface::Surface((int)this->getWidth(),(int)this->getHeight());
                SDL_SetRenderTarget(sdlgame::display::renderer,res.texture);
                SDL_RenderCopy(sdlgame::display::renderer,texture,NULL,NULL);
                SDL_SetRenderTarget(sdlgame::display::renderer,NULL);
                return res;
            }
            /**
             * Return a copy of the surface rect
             */
            sdlgame::rect::Rect getRect() const
            {
                return sdlgame::rect::Rect(0.0,0.0,size.x,size.y);
            }
            /**
             * Blit a surface onto this surface with position and size, leave size be -1,-1 will be its original size
             * the surface or image will stretch or shrink acoording to the size
            */
            void blit(const Surface source, sdlgame::math::Vector2 pos, sdlgame::math::Vector2 size = sdlgame::math::Vector2(-1,-1), sdlgame::rect::Rect area = sdlgame::rect::Rect())
            {
                if (area == sdlgame::rect::Rect())
                {
                    area = sdlgame::rect::Rect(0.0, 0.0, source.getWidth(), source.getHeight());
                }
                sdlgame::rect::Rect destrect = sdlgame::rect::Rect(
                    pos.x, pos.y,
                    (size.x < 0 ? source.getWidth() : size.x),(size.y < 0 ? source.getHeight() : size.y)
                );
                if(SDL_SetRenderTarget(sdlgame::display::renderer, texture)){
                    printf("Failed to set target: %s\n",SDL_GetError());
                }

                SDL_Rect srcrect = area.to_SDL_Rect();
                SDL_FRect dstrect = destrect.to_SDL_FRect();
                if (SDL_RenderCopyF(sdlgame::display::renderer, source.texture, &srcrect, &dstrect))
                {
                    printf("Error copy texture onto another\n");
                    printf("%s\n",SDL_GetError());
                    exit(0);
                }
                if(SDL_SetRenderTarget(sdlgame::display::renderer, NULL)){
                    printf("Failed to set target: %s\n",SDL_GetError());
                }

            }
            void fill(sdlgame::color::Color color, sdlgame::rect::Rect area = sdlgame::rect::Rect())
            {
                if (area == sdlgame::rect::Rect())
                {
                    area = sdlgame::rect::Rect(0.0, 0.0, size.x, size.y);
                }
                if(SDL_SetRenderTarget(sdlgame::display::renderer, texture)){
                    printf("Failed to set target: %s\n",SDL_GetError());
                }

                if (SDL_SetRenderDrawColor(sdlgame::display::renderer, color.r, color.g, color.b, color.a))
                {
                    printf("Failed to set draw color\nErr:%s\n", SDL_GetError());
                    exit(0);
                }
                if (SDL_RenderClear(sdlgame::display::renderer))
                {
                    printf("Failed to clear the render target\nErr:%s\n", SDL_GetError());
                    exit(0);
                }
                if(SDL_SetRenderTarget(sdlgame::display::renderer, NULL)){
                    printf("Failed to set target: %s\n",SDL_GetError());
                }

            }
            sdlgame::math::Vector2 get_size() const
            {
                return size;
            }
            double getWidth() const
            {
                return size.x;
            }
            double getHeight() const
            {
                return size.y;
            }
            ~Surface()
            {
                if (texture != NULL)
                    SDL_DestroyTexture(texture);
            }
        };
    }

    namespace display
    {
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;
        sdlgame::surface::Surface win_surf;
        bool isInit = false;

        sdlgame::surface::Surface &set_mode(int width = 0, int height = 0, Uint32 flags = 0)
        {
            if (width == 0 or height == 0)
            {
                SDL_DisplayMode DM;
                SDL_GetDesktopDisplayMode(0, &DM);
                width = DM.w;
                height = DM.h;
            }
            window = SDL_CreateWindow("sdlgame Custom Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
            if (window == nullptr)
            {
                printf("Failed to create a window object\nErr: %s\n", SDL_GetError());
                exit(0);
            }
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer == nullptr)
            {
                printf("Failed to create a renderer\nErr: %s\n", SDL_GetError());
                exit(0);
            }

            win_surf.texture = null; // THIS IS INTENDED!
            return win_surf;
        }

        /**
         *  return a Surface object that have reference SDL_surface to the window surface (NOT GARUANTEE IN ADVANCE ENGINE)
         */
        sdlgame::surface::Surface &get_surface()
        {
            win_surf.texture = NULL;
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

        void set_icon(const char *icon_path)
        {
            SDL_Surface *icon = IMG_Load(icon_path);
            SDL_SetWindowIcon(window, icon);
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
            if(SDL_GetRenderTarget(renderer)) SDL_SetRenderTarget(renderer,NULL);
            SDL_RenderPresent(renderer);
        }
    }

    // not yet, this only possible after install SDL3 then we should have the all image format load
    namespace image
    {
        // SDL_Surface *tmp;
        // sdlgame::surface::Surface load(std::string path)
        // {
        //     const char* img_path = path.c_str();
        //     SDL_RWops *ops = SDL_RWFromFile(img_path,"rb");
        //     if(ops==NULL){
        //         printf("Failed to RW from file\nErr:%s\n",SDL_GetError());
        //         exit(0);
        //     }
        //     tmp = IMG_Load_RW(ops,SDL_FALSE);
        //     if(!tmp){
        //         printf("Failed to load image\n");
        //         exit(0);
        //     }
        //     SDL_RWclose(ops);
        //     return sdlgame::surface::Surface(tmp);
        // }
        sdlgame::surface::Surface load(std::string path)
        {
            sdlgame::surface::Surface res = sdlgame::surface::Surface(IMG_LoadTexture(sdlgame::display::renderer,path.c_str()));
            return res;
        }

    }

    namespace key
    {
        namespace
        {
            const Uint8 *keyState;
            std::vector<bool> keys;
        }
        /**
         *  assume that you called the SDL_PumpEvents function before calling this, this funciton should work fine
         */
        std::vector<bool> &get_pressed()
        {
            int numKeys;
            SDL_PumpEvents();
            keyState = SDL_GetKeyboardState(&numKeys);
            if (keys.size() == 0)
                keys.resize(numKeys);
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
            sdlgame::math::Vector2 last_mouse_pos = sdlgame::math::Vector2(-1, -1);
            bool isVisible = true;
        }
        sdlgame::math::Vector2 get_pos()
        {
            int x, y;
            SDL_GetMouseState(&x, &y);
            return sdlgame::math::Vector2(x, y);
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
        sdlgame::math::Vector2 get_rel()
        {
            if (last_mouse_pos == sdlgame::math::Vector2(-1, -1))
                return sdlgame::math::Vector2(0, 0);
            int x, y;
            SDL_GetMouseState(&x, &y);
            sdlgame::math::Vector2 res = sdlgame::math::Vector2(x, y) - last_mouse_pos;
            last_mouse_pos = sdlgame::math::Vector2(x, y);
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
        SDL_DestroyWindowSurface(sdlgame::display::window);
        SDL_DestroyRenderer(sdlgame::display::renderer);
        SDL_DestroyWindow(sdlgame::display::window);
        Mix_Quit();
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
        /**
         * width determine how far the border will expand to the INSIDE
         */
        void rect(sdlgame::surface::Surface surface, sdlgame::color::Color color, sdlgame::rect::Rect rect, int width = 0)
        {
            // std::cout << surface.texture << " color: "<<color.toString() << " rect: "<<rect.toString()<<std::endl;
            SDL_SetRenderDrawColor(sdlgame::display::renderer,color.r,color.g,color.b,color.a);
            if(SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
            if (width == 0)
            {
                SDL_FRect tmp = rect.to_SDL_FRect();
                if(SDL_RenderFillRectF(sdlgame::display::renderer, &tmp)){
                    printf("Error filling a rectangle: %s\n",SDL_GetError());
                    exit(0);
                }
            }
            else if (width > 0)
            {
                SDL_FRect top = rect.inflate(width - rect.getHeight(), 0.0).to_SDL_FRect();
                SDL_FRect left = rect.inflate(0.0, width - rect.getWidth()).to_SDL_FRect();
                SDL_FRect bottom = rect.inflate(width - rect.getHeight(), 0.0).move(0.0, rect.getHeight() - width).to_SDL_FRect();
                SDL_FRect right = rect.inflate(0.0, width - rect.getWidth()).move(rect.getWidth() - width, 0.0).to_SDL_FRect();
                if( SDL_RenderFillRectF(sdlgame::display::renderer, &top) or
                    SDL_RenderFillRectF(sdlgame::display::renderer, &left) or
                    SDL_RenderFillRectF(sdlgame::display::renderer, &bottom) or
                    SDL_RenderFillRectF(sdlgame::display::renderer, &right)){
                        printf("Error drawing a rectangle: %s\n",SDL_GetError());
                        exit(0);
                    }
            }
            if(SDL_SetRenderTarget(sdlgame::display::renderer, NULL)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
        }

        template <class T>
        void line(sdlgame::surface::Surface surface, sdlgame::color::Color color, T x1, T y1, T x2, T y2)
        {
            if(SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
            SDL_SetRenderDrawColor(sdlgame::display::renderer,color.r,color.g,color.b,color.a);
            if(SDL_RenderDrawLineF(sdlgame::display::renderer, x1, y1, x2, y2)){
                printf("Failed to draw a line: %s\n",SDL_GetError());
                exit(0);
            }
            if(SDL_SetRenderTarget(sdlgame::display::renderer, NULL)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
        }
        void draw_circle(sdlgame::surface::Surface surface, sdlgame::color::Color color, int centerX, int centerY, int radius)
        {
            if(SDL_SetRenderTarget(sdlgame::display::renderer, surface.texture)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
            SDL_SetRenderDrawColor(sdlgame::display::renderer,color.r,color.g,color.b,color.a);
            for (double angle = 0.0; angle < 2 * M_PI; angle += 0.01)
            {
                float x = centerX + radius * cos(angle);
                float y = centerY + radius * sin(angle);
                SDL_RenderDrawPointF(sdlgame::display::renderer, x, y);
            }
            if(SDL_SetRenderTarget(sdlgame::display::renderer, NULL)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
        }

        void draw_polygon(sdlgame::surface::Surface surface, sdlgame::color::Color color, std::vector<std::pair<int, int>> points)
        {
            if (points.size() < 3)
                throw std::invalid_argument("can't draw polygon with only 2 vertices or less");
            for (int i = 0; i < int(points.size()) - 1; i++)
            {
                sdlgame::draw::line(surface, color, points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
            }
            sdlgame::draw::line(surface, color, points[0].first, points[0].second, points[points.size() - 1].first, points[points.size() - 1].second);
        }
    }

    namespace transform
    {
        sdlgame::surface::Surface flip(sdlgame::surface::Surface &surface, bool flip_x, bool flip_y)
        {
            sdlgame::surface::Surface res = surface.copy();
            if(SDL_SetRenderTarget(sdlgame::display::renderer, res.texture)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
            SDL_RendererFlip flipType = SDL_FLIP_NONE;
            if (flip_x) flipType = (SDL_RendererFlip)(flipType | SDL_FLIP_HORIZONTAL);
            if (flip_y) flipType = (SDL_RendererFlip)(flipType | SDL_FLIP_VERTICAL);
            if (SDL_RenderCopyEx(sdlgame::display::renderer, surface.texture, NULL, NULL, 0, NULL, flipType))
                printf("Failed to flip\n");
            if(SDL_SetRenderTarget(sdlgame::display::renderer, NULL)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
            return res;
        }
        sdlgame::surface::Surface scale(sdlgame::surface::Surface &surface, sdlgame::math::Vector2 size)
        {
            sdlgame::surface::Surface res = sdlgame::surface::Surface(size.x, size.y);
            if(SDL_SetRenderTarget(sdlgame::display::renderer, res.texture)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
            SDL_RenderCopyF(sdlgame::display::renderer, surface.texture, NULL, NULL);
            if(SDL_SetRenderTarget(sdlgame::display::renderer, NULL)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
            return res;
        }

        sdlgame::surface::Surface scale_by(sdlgame::surface::Surface &surface, double factor)
        {
            return sdlgame::transform::scale(surface,surface.get_size() * factor);
        }

        /**
         * return a surface that rotated a certain angle counter-clokcwise with passed center
         * angle unit is degrees
         * TODO: calculate the new size for the res surface
         */
        sdlgame::surface::Surface rotate(sdlgame::surface::Surface &surface, double angle_deg, sdlgame::math::Vector2 center)
        {
            sdlgame::math::Vector2 newtopleft = (surface.getRect().getTopLeft() - center).rotate(angle_deg);
            sdlgame::math::Vector2 newbotleft = (surface.getRect().getBottomLeft() - center).rotate(angle_deg);
            sdlgame::math::Vector2 newtopright = (surface.getRect().getTopRight() - center).rotate(angle_deg);
            sdlgame::math::Vector2 newbotright = (surface.getRect().getBottomRight() - center).rotate(angle_deg);

            sdlgame::surface::Surface res = sdlgame::surface::Surface(
                std::max({newtopleft.x, newbotleft.x, newbotright.x, newtopright.x}) - std::min({newtopleft.x, newbotleft.x, newbotright.x, newtopright.x}),
                std::max({newtopleft.y, newbotleft.y, newbotright.y, newtopright.y}) - std::min({newtopleft.y, newbotleft.y, newbotright.y, newtopright.y}));
            if(SDL_SetRenderTarget(sdlgame::display::renderer, res.texture)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
            SDL_FPoint tmp = {float(center.x), float(center.y)};
            SDL_RenderCopyExF(sdlgame::display::renderer, surface.texture, NULL, NULL, angle_deg, &tmp, SDL_FLIP_NONE);
            if(SDL_SetRenderTarget(sdlgame::display::renderer, NULL)){
                printf("Failed to set target: %s\n",SDL_GetError());
            }
            return res;
        }
    }

    namespace sprite
    {
        /**
         * Should be test heavyly around pointer
         * just use stack-alloc like normal
         * treat the pointer as a address holder only,
         * not an pointer to a heap allocated object
        */
        class Sprite;
        class Group
        {
        public:
            std::set<Sprite*> sprite_list;
            std::set<Sprite*> &sprites()
            {
                return sprite_list;
            }
            void add(Sprite* sprite)
            {
                sprite_list.insert(sprite);
                sprite->group_list.insert(this);
            }
            void add(std::vector<Sprite*> &sprites)
            {
                for(auto &sprite : sprites){
                    sprite_list.insert(sprite);
                    sprite->group_list.insert(this);
                }
            }
            void remove(std::vector<Sprite*> &sprites)
            {
                for(auto &sprite: sprites){
                    auto it = sprite_list.find(sprite);
                    if(it!=sprite_list.end()) {
                        sprite->remove(this);
                        sprite_list.erase(it);
                    }
                }
            }
            void remove(Sprite* sprite)
            {
                auto it = sprite_list.find(sprite);
                if(it!=sprite_list.end()){
                    sprite->remove(this);
                    sprite_list.erase(it);
                }
            }
            bool has(std::vector<Sprite*> &sprites){
                for(auto &sprite: sprites){
                    if(sprite_list.find(sprite)==sprite_list.end()) return false;
                }
                return true;
            }
            bool has(Sprite* sprite){
                if(sprite_list.find(sprite)==sprite_list.end()) return false;
                return true;
            }
            void update(){
                for(auto &sprite : sprite_list){
                    sprite->update();
                }
            }
            void draw(sdlgame::surface::Surface &surface){
                for(auto &sprite : sprite_list){
                    sprite->draw(surface);
                }
            }
        };
        /**
         * 
         * The base class for visible game objects.
         * Derived classes will want to override the Sprite.update() and assign a Sprite.image and Sprite.rect attributes.
         * The initializer can accept any number of Group instances to be added to
         * 
        */
        class Sprite
        {
        public:
            sdlgame::rect::Rect rect;
            sdlgame::surface::Surface image;
            std::set<Group*> group_list;
            Sprite(sdlgame::surface::Surface surface, sdlgame::math::Vector2 pos){
                image = surface;
                rect = sdlgame::rect::Rect(pos, image.get_size());
            }
            /**
             * return a set of group that conrtain this sprite
            */
            std::set<Group*> &groups(){
                return group_list;
            }
            virtual void update() = 0;
            void add(std::vector<Group*> groups){
                for(auto &group : groups) group_list.insert(group);
            }
            void add(Group* group){
                group_list.insert(group);
            }   
            void remove(std::vector<Group*> groups){
                for(auto &group : groups){
                    auto it = group_list.find(group);
                    if(it!=group_list.end()){
                        group->sprite_list.erase(this);
                        group_list.erase(group);
                    }
                }
            }
            void remove(Group* group){
                auto it = group_list.find(group);
                if(it!=group_list.end()){
                    group->sprite_list.erase(this);
                    group_list.erase(group);
                }
            }
            /**
             * remove this sprite from all group, still usable after call
            */
            void kill(){
                for(auto& group : group_list) group->sprite_list.erase(this);
                group_list.clear();
            }
            bool alive(){
                return group_list.size()>0;
            }
            void draw(sdlgame::surface::Surface &surface){
                surface.blit(image, rect.getTopLeft(), rect.getSize());
            }
        };

        /**
         * @return a list containing all Sprites in a Group that intersect with another Sprite.
         * Intersection is determined by comparing the Sprite.rect attribute of each Sprite.
         * The dokill argument is a bool. If set to True, all Sprites that collide will be removed from the Group.
        */
        std::vector<Sprite*> spritecollide(Sprite* sprite, Group* group, bool dokill = false){
            std::vector<Sprite*> res;
            for(auto &img : group->sprite_list){
                if(img->rect.colliderect(sprite->rect)){
                    res.push_back(img);
                }
            }
            if(dokill) group->remove(res);
            return res;
        }
        /**
         * @return if 2 sprite is collide or not, but using 2 sprite, both must have rect attr defined
        */
        bool collide_rect(Sprite* left, Sprite* right){
            return left->rect.colliderect(right->rect);
        }
        /**
         * Tests for collision between two sprites,
         * by testing to see if two circles centered on the sprites overlap.
         * If the radius value is passed, it will check if 2 circle center at the both rect center is collide with that center and that radius or not
         * otherwise a circle is created that is big enough to completely enclose the sprites rect as given by the "rect" attribute.
         */
        bool collide_circle(Sprite* left, Sprite* right, double left_radius = 0, double right_radius = 0){
            left_radius = (left_radius==0 ? (left->rect.getTopLeft() - left->rect.getBottomRight()).magnitude()/2 : left_radius);
            right_radius = (right_radius==0 ? (right->rect.getTopLeft() - right->rect.getBottomRight()).magnitude()/2 : right_radius);
            return (left->rect.getCenter() - right->rect.getCenter()).magnitude() <= left_radius + right_radius;
        }

    }

    namespace mixer
    {

    }

    namespace font{}
};
