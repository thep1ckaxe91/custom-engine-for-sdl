/**
 * @authors thep1ckaxe, and many authors from SDL2's developers
 * email: ThePickaxe91@gmail.com
 *
 * @brief this file tried to replicate all classes and function that they have in pygame but implement for SDL2 in C++
 * if you spot or have problem while using this engine, please let me know through email
 *
 * REQUIREMENT: SDL2 installed to your mingw directory
 *
 * all pixel format is consider RGBA32
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
 * @brief this namespace replace pygame module, also replicate the way everything is just from pygame. ish
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
    const int K_KP_PERIOD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD);
    const int K_APPLICATION = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION);
    const int K_POWER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER);
    const int K_KP_EQUALS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS);
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
    const int K_EXECUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE);
    const int K_HELP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP);
    const int K_MENU = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU);
    const int K_SELECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT);
    const int K_STOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP);
    const int K_AGAIN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN);
    const int K_UNDO = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO);
    const int K_CUT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT);
    const int K_COPY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY);
    const int K_PASTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE);
    const int K_FIND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND);
    const int K_MUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE);
    const int K_VOLUMEUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP);
    const int K_VOLUMEDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN);
    const int K_KP_COMMA = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA);
    const int K_KP_EQUALSAS400 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400);
    const int K_ALTERASE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE);
    const int K_SYSREQ = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ);
    const int K_CANCEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL);
    const int K_CLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR);
    const int K_PRIOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR);
    const int K_RETURN2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2);
    const int K_SEPARATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR);
    const int K_OUT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT);
    const int K_OPER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER);
    const int K_CLEARAGAIN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN);
    const int K_CRSEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL);
    const int K_EXSEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL);
    const int K_KP_00 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00);
    const int K_KP_000 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000);
    const int K_THOUSANDSSEPARATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR);
    const int K_DECIMALSEPARATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR);
    const int K_CURRENCYUNIT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT);
    const int K_CURRENCYSUBUNIT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT);
    const int K_KP_LEFTPAREN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN);
    const int K_KP_RIGHTPAREN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN);
    const int K_KP_LEFTBRACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE);
    const int K_KP_RIGHTBRACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE);
    const int K_KP_TAB = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB);
    const int K_KP_BACKSPACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE);
    const int K_KP_A = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A);
    const int K_KP_B = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B);
    const int K_KP_C = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C);
    const int K_KP_D = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D);
    const int K_KP_E = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E);
    const int K_KP_F = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F);
    const int K_KP_XOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR);
    const int K_KP_POWER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER);
    const int K_KP_PERCENT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT);
    const int K_KP_LESS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS);
    const int K_KP_GREATER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER);
    const int K_KP_AMPERSAND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND);
    const int K_KP_DBLAMPERSAND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND);
    const int K_KP_VERTICALBAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR);
    const int K_KP_DBLVERTICALBAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR);
    const int K_KP_COLON = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON);
    const int K_KP_HASH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH);
    const int K_KP_SPACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE);
    const int K_KP_AT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT);
    const int K_KP_EXCLAM = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM);
    const int K_KP_MEMSTORE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE);
    const int K_KP_MEMRECALL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL);
    const int K_KP_MEMCLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR);
    const int K_KP_MEMADD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD);
    const int K_KP_MEMSUBTRACT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT);
    const int K_KP_MEMMULTIPLY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY);
    const int K_KP_MEMDIVIDE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE);
    const int K_KP_PLUSMINUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS);
    const int K_KP_CLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR);
    const int K_KP_CLEARENTRY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY);
    const int K_KP_BINARY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY);
    const int K_KP_OCTAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL);
    const int K_KP_DECIMAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL);
    const int K_KP_HEXADECIMAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL);
    const int K_LCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL);
    const int K_LSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT);
    const int K_LALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT);
    const int K_LGUI = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI);
    const int K_RCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL);
    const int K_RSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT);
    const int K_RALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT);
    const int K_RGUI = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI);
    const int K_MODE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE);
    const int K_AUDIONEXT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIONEXT);
    const int K_AUDIOPREV = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPREV);
    const int K_AUDIOSTOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOSTOP);
    const int K_AUDIOPLAY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPLAY);
    const int K_AUDIOMUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOMUTE);
    const int K_MEDIASELECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIASELECT);
    const int K_WWW = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WWW);
    const int K_MAIL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MAIL);
    const int K_CALCULATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALCULATOR);
    const int K_COMPUTER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COMPUTER);
    const int K_AC_SEARCH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH);
    const int K_AC_HOME = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME);
    const int K_AC_BACK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK);
    const int K_AC_FORWARD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD);
    const int K_AC_STOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP);
    const int K_AC_REFRESH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH);
    const int K_AC_BOOKMARKS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS);
    const int K_BRIGHTNESSDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSDOWN);
    const int K_BRIGHTNESSUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSUP);
    const int K_DISPLAYSWITCH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DISPLAYSWITCH);
    const int K_KBDILLUMTOGGLE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMTOGGLE);
    const int K_KBDILLUMDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMDOWN);
    const int K_KBDILLUMUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMUP);
    const int K_EJECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EJECT);
    const int K_SLEEP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP);
    const int K_APP1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP1);
    const int K_APP2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP2);
    const int K_AUDIOREWIND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOREWIND);
    const int K_AUDIOFASTFORWARD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOFASTFORWARD);
    const int K_SOFTLEFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTLEFT);
    const int K_SOFTRIGHT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTRIGHT);
    const int K_CALL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALL);
    const int K_ENDCALL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ENDCALL);

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

    void quit(SDL_Window *window, SDL_Renderer *renderer, std::vector<SDL_Texture *> textures)
    {
        for (SDL_Texture *tex : textures)
            SDL_DestroyTexture(tex);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(0);
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

        template <class T>
        Vector2 operator*(const T &scalar, const Vector2 &v)
        {
            static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
            return Vector2(scalar * v.x, scalar * v.y);
        }

        /**
         * @brief a class for 2D vector, also can represent a point on a 2d surface
         * since the simplicity of 2d vector, we dont need get and set function
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
            Vector2 &operator+=(const Vector2 &oth)
            {
                if (this != &oth)
                {
                    x += oth.x;
                    y += oth.y;
                }
                return *this;
            }
            Vector2 &operator-=(const Vector2 &oth)
            {
                if (this != &oth)
                {
                    x -= oth.x;
                    y -= oth.y;
                }
                return *this;
            }
            template <class T>
            Vector2 &operator*=(const T &scalar)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
                x *= scalar;
                y *= scalar;
                return *this;
            }
            Vector2 operator+(const Vector2 &oth) const
            {
                return Vector2(x + oth.x, y + oth.y);
            }
            Vector2 operator-() const
            {
                return Vector2(-x, -y);
            }
            Vector2 operator-(const Vector2 &oth) const
            {
                return Vector2(x - oth.x, y - oth.y);
            }
            template <class T>
            Vector2 operator*(const T &scalar) const
            {
                std::static_assert(std::is_arithmetic<T>::value, "Invalid type to multiply with vector");
                return Vector2(scalar * x, scalar * y);
            }

            bool operator==(const Vector2 &oth) const
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
            Vector2 normalize() const
            {
                return Vector2(x / this->magnitude(), y / this->magnitude());
            }
            /**
             * @brief normalize the vector
             */
            void normalize_ip()
            {
                x /= this->magnitude();
                y /= this->magnitude();
            }
            double dot(const Vector2 &oth) const
            {
                return x * oth.x + y * oth.y;
            }
            /**
             * @return angle in degree to another vector in range [0,180] degrees, which is the smallest of 2 angle
             * */
            double angle_to(const Vector2 &oth) const
            {
                return acos(this->dot(oth) / (this->magnitude() * oth.magnitude())) * 180.0 / M_PI;
            }

            /**
             * @return a vector that rotated deg degrees counter clockwise
             * */
            Vector2 rotate(double deg) const
            {
                double angleInRadians = degree_to_radian(deg);
                return Vector2(x * cos(angleInRadians) - y * sin(angleInRadians), x * sin(angleInRadians) + y * cos(angleInRadians));
            }
            /**
             * @brief make the vector rotate deg degrees counter-clockwise
             */
            Vector2 rotate_ip(double deg)
            {
                double _x = x, _y = y, angleInRadians = degree_to_radian(deg);
                x = _x * cos(angleInRadians) - _y * sin(angleInRadians);
                y = x * sin(angleInRadians) + y * cos(angleInRadians);
            }
            double distance_to(const Vector2 &oth) const
            {
                return sqrt((x - oth.x) * (x - oth.x) + (y - oth.y) * (y - oth.y));
            }
            /**
             * @return the vector that is the reflection of the current vector to a normal vector
             */
            Vector2 reflect(const Vector2 &normal) const
            {
                double dotProduct = this->dot(normal);
                return (*this) - 2 * normal * this->dot(normal);
            }
            void reflect_ip(const Vector2 &normal)
            {
                *this = this->reflect(normal);
            }
            Vector2 project(const Vector2 &normal) const
            {
                return (this->dot(normal) / (normal.sqr_magnitude())) * normal;
            }
            void project_ip(const Vector2 &normal)
            {
                *this = this->project(normal);
            }
            std::string toString() const
            {
                return "Vector2<" + std::to_string(x) + " , " + std::to_string(y) + ">";
            }
        };
    }

    using Vector2 = SDLGame::math::Vector2;

    namespace rect
    {
        /**
         * @brief this is a class represent a Rectangle in SDL2, the coordination
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
            Vector2 center, topleft, bottomleft, topright, bottomright, midtop, midleft, midbottom, midright;
            Vector2 size;
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
                size = Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = Vector2(centerx, centery);
                topleft = Vector2(left, top);
                bottomleft = Vector2(left, bottom);
                bottomright = Vector2(right, bottom);
                topright = Vector2(right, top);
                midtop = Vector2(centerx, top);
                midleft = Vector2(left, centery);
                midbottom = Vector2(centerx, bottom);
                midright = Vector2(right, centery);
            }
            template <class T>
            Rect(T _left, T _top, const Vector2 &_size)
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
                center = Vector2(centerx, centery);
                topleft = Vector2(left, top);
                bottomleft = Vector2(left, bottom);
                bottomright = Vector2(right, bottom);
                topright = Vector2(right, top);
                midtop = Vector2(centerx, top);
                midleft = Vector2(left, centery);
                midbottom = Vector2(centerx, bottom);
                midright = Vector2(right, centery);
            }
            template <class T>
            Rect(const Vector2 &pos, T _w, T _h)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                x = left = pos.x;
                y = top = pos.y;
                w = width = _w;
                h = height = _y;
                bottom = top + h;
                right = left + w;
                size = Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = Vector2(centerx, centery);
                topleft = Vector2(left, top);
                bottomleft = Vector2(left, bottom);
                bottomright = Vector2(right, bottom);
                topright = Vector2(right, top);
                midtop = Vector2(centerx, top);
                midleft = Vector2(left, centery);
                midbottom = Vector2(centerx, bottom);
                midright = Vector2(right, centery);
            }
            Rect(const Vector2 &pos, const Vector2 &_size)
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
                center = Vector2(centerx, centery);
                topleft = Vector2(left, top);
                bottomleft = Vector2(left, bottom);
                bottomright = Vector2(right, bottom);
                topright = Vector2(right, top);
                midtop = Vector2(centerx, top);
                midleft = Vector2(left, centery);
                midbottom = Vector2(centerx, bottom);
                midright = Vector2(right, centery);
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
                    size = Vector2(w, h);
                    centerx = x + width / 2;
                    centery = y + height / 2;
                    center = Vector2(centerx, centery);
                    topleft = Vector2(left, top);
                    bottomleft = Vector2(left, bottom);
                    bottomright = Vector2(right, bottom);
                    topright = Vector2(right, top);
                    midtop = Vector2(centerx, top);
                    midleft = Vector2(left, centery);
                    midbottom = Vector2(centerx, bottom);
                    midright = Vector2(right, centery);
                }
                return *this;
            }
            bool operator==(const Rect &oth) const
            {
                if (this == &oth)
                    return true;
                return abs(x - oth.getLeft()) <= epsilon and abs(y - oth.getTop()) <= epsilon and abs(w - oth.getWidth()) <= epsilon and abs(h - oth.getHeight()) <= epsilon;
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
                res.center = Vector2(res.centerx, res.centery);
                res.topleft = Vector2(res.left, res.top);
                res.bottomleft = Vector2(res.left, res.bottom);
                res.bottomright = Vector2(res.right, res.bottom);
                res.topright = Vector2(res.right, res.top);
                res.midtop = Vector2(res.centerx, res.top);
                res.midleft = Vector2(res.left, res.centery);
                res.midbottom = Vector2(res.centerx, res.bottom);
                res.midright = Vector2(res.right, res.centery);
                return res;
            }

            /**
             * @brief instead of a new one, this just move the rect that called this function
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
            Rect move(const Vector2 &offset) const
            {
                return this->move(offset.x, offset.y);
            }
            /**
             * @brief instead of a new one, this just move the rect that called this function
             */
            void move_ip(const Vector2 &offset)
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
                res.size += Vector2(offset_w, offset_h);
                res.w = res.width += offset_w;
                res.h = res.height += offset_h;
                res.bottom = res.top + res.h;
                res.right = res.left + res.w;
                res.centerx = res.x + res.width / 2;
                res.centery = res.y + res.height / 2;
                res.center = Vector2(res.centerx, res.centery);
                res.topleft = Vector2(res.left, res.top);
                res.bottomleft = Vector2(res.left, res.bottom);
                res.bottomright = Vector2(res.right, res.bottom);
                res.topright = Vector2(res.right, res.top);
                res.midtop = Vector2(res.centerx, res.top);
                res.midleft = Vector2(res.left, res.centery);
                res.midbottom = Vector2(res.centerx, res.bottom);
                res.midright = Vector2(res.right, res.centery);
                return res;
            }
            Rect inflate(const Vector2 &offset) const
            {
                return this->inflate(offset.x, offset.y);
            }
            /**
             * @brief resize current rectangle with given offset, the topleft of the rectangle is remain still
             */
            template <class T>
            void inflate_ip(T offset_w, T offset_h)
            {
                *this = this->inflate(offset_w, offset_h);
            }
            void inflate_ip(const Vector2 &offset)
            {
                *this = this->inflate(offset.x, offset.y);
            }

            /**
             * @brief to update the current rectangle that call the function
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
                size = Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = Vector2(centerx, centery);
                topleft = Vector2(left, top);
                bottomleft = Vector2(left, bottom);
                bottomright = Vector2(right, bottom);
                topright = Vector2(right, top);
                midtop = Vector2(centerx, top);
                midleft = Vector2(left, centery);
                midbottom = Vector2(centerx, bottom);
                midright = Vector2(right, centery);
            }
            template <class T>
            void update(T _left, T _top, const Vector2 &_size)
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
                center = Vector2(centerx, centery);
                topleft = Vector2(left, top);
                bottomleft = Vector2(left, bottom);
                bottomright = Vector2(right, bottom);
                topright = Vector2(right, top);
                midtop = Vector2(centerx, top);
                midleft = Vector2(left, centery);
                midbottom = Vector2(centerx, bottom);
                midright = Vector2(right, centery);
            }
            template <class T>
            void update(const Vector2 &pos, T _w, T _h)
            {
                static_assert(std::is_arithmetic<T>::value, "Invalid type for Rect param");
                x = left = pos.x;
                y = top = pos.y;
                w = width = _w;
                h = height = _y;
                bottom = top + h;
                right = left + w;
                size = Vector2(w, h);
                centerx = x + width / 2;
                centery = y + height / 2;
                center = Vector2(centerx, centery);
                topleft = Vector2(left, top);
                bottomleft = Vector2(left, bottom);
                bottomright = Vector2(right, bottom);
                topright = Vector2(right, top);
                midtop = Vector2(centerx, top);
                midleft = Vector2(left, centery);
                midbottom = Vector2(centerx, bottom);
                midright = Vector2(right, centery);
            }
            void update(const Vector2 &pos, const Vector2 &_size)
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
                center = Vector2(centerx, centery);
                topleft = Vector2(left, top);
                bottomleft = Vector2(left, bottom);
                bottomright = Vector2(right, bottom);
                topright = Vector2(right, top);
                midtop = Vector2(centerx, top);
                midleft = Vector2(left, centery);
                midbottom = Vector2(centerx, bottom);
                midright = Vector2(right, centery);
            }
            /**
             * @brief return a new rectangle that fit another rect but keep the aspect ratio of the caller
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
            bool collidepoint(const Vector2 &point)
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
            bool collidelist(std::vector<const Rect &> &rect_list) const
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
            void setSize(const Vector2 &_size)
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
            void setCenter(const Vector2 &pos)
            {
                move_ip(pos.x - centerx, pos.y - centery);
            }
            template <class T>
            void setMidTop(T _x, T _y)
            {
                move_ip(_x - centerx, _y - y);
            }
            void setMidTop(const Vector2 &pos)
            {
                move_ip(pos.x - centerx, pos.y - y);
            }
            template <class T>
            void setMidBottom(T _x, T _y)
            {
                move_ip(_x - centerx, _y - bottom);
            }
            void setMidBottom(const Vector2 &pos)
            {
                move_ip(pos.x - centerx, pos.y - bottom);
            }
            template <class T>
            void setMidLeft(T _x, T _y)
            {
                move_ip(_x - x, _y - centery);
            }
            void setMidLeft(const Vector2 &pos)
            {
                move_ip(pos.x - x, pos.y - centery);
            }
            template <class T>
            void setMidRight(T _x, T _y)
            {
                move_ip(_x - right, _y - centery);
            }
            void setMidRight(const Vector2 &pos)
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
            Vector2 getSize() const { return size; }
            Vector2 getCenter() const { return center; }
            Vector2 getTopLeft() const { return topleft; }
            Vector2 getTopRight() const { return topright; }
            Vector2 getBottomLeft() const { return bottomleft; }
            Vector2 getBottomRight() const { return bottomright; }
            Vector2 getMidTop() const { return midtop; }
            Vector2 getMidLeft() const { return midleft; }
            Vector2 getMidBottom() const { return midbottom; }
            Vector2 getMidRight() const { return midright; }

            /**
             * @brief return a SDL_Rect object from this rect
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
         * @brief class for color, all values range from [0,255]
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
            Uint32 toUint32Color(const SDL_PixelFormat *format) const
            {
                return SDL_MapRGBA(format, r, g, b, a);
            }
            std::string toString()
            {
                return "Color(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + "," + std::to_string(a) + ")";
            }
        };
    }
    
    using Rect = SDLGame::rect::Rect;
    using Color = SDLGame::color::Color;
    //may be not done yet but good enough
    namespace surface
    {
        class Surface
        {
        private:
            Rect rect;

        public:
            SDL_Surface *surface;
            Uint32 flags;
            Surface(){
                flags=0;
                surface = SDL_CreateRGBSurface(flags, 0, 0, 0, 0, 0, 0, 0);
            }
            Surface(int width, int height, Uint32 _flags=0)
            {
                flags = _flags;
                surface = SDL_CreateRGBSurface(flags, width, height, 0, 0, 0, 0, 0);
            }

            Surface(const Surface& oth) {
                flags = oth.flags;
                surface = SDL_ConvertSurface(oth.surface, oth.surface->format, 0);
            }

            Surface(SDL_Surface* oth){
                flags=oth->flags;
                surface = SDL_ConvertSurface(oth, oth->format, 0);
            }

            Surface& operator=(const Surface& other) {
                if (this != &other) {
                    SDL_FreeSurface(surface);
                    flags = other.flags;
                    surface = SDL_ConvertSurface(other.surface, other.surface->format, 0);
                }
                return *this;
            }

            Rect &getRect()
            {
                return rect;
            }
            void blit(const Surface &source, const Rect &destrect, Rect area = Rect())
            {
                if (area == Rect())
                    area = Rect(0, 0, source.surface->w, source.surface->h);
                SDL_BlitSurface(source.surface, &area.toSDL_Rect(), surface, &destrect.toSDL_Rect());
            }
            void fill(const Color &color, Rect rect = Rect())
            {
                if (rect == Rect())
                    rect = Rect(0, 0, surface->w, surface->h);
                SDL_FillRect(surface, &rect.toSDL_Rect(), color.toUint32Color(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA32)));
            }
            template <class T>
            void scroll(T offset_x, T offset_y)
            {
                rect.move_ip(offset_x, offset_y);
            }
            Vector2 get_size() const
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
            ~Surface(){
                SDL_FreeSurface(surface);
            }
        };
    }

    using Surface = SDLGame::surface::Surface;
    //not yet, this only possible after install SDL3 then we should have the all image format load
    namespace image
    {
        Surface load(const char* img_path){
            Surface res(0,0);
            res.surface = IMG_Load(img_path);

        }
    }

};
