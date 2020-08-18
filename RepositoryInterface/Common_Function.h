#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<Windows.h>
#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include<iostream>
#include<cmath>
#include"BaseObject.h"
#include <SDL_ttf.h>
#include<SDL_mixer.h>


using namespace std;
const int SCREEN_WIDTH =640;
const int SCREEN_HEIGHT = 701;
const int SCREEN_BPP = 32;
const int NUM_WOOD = 5;
const int NUM_SPINES = 2;
const int NUM_OF_HEARTS = 6;
const int NUMBER_BEGIN = 4;
const int NUM_SNOW = 20;
const unsigned long long int FRAME_PER_SECOND = 8446744073709551615;
const int X_VAL_MOVE = 6;



static SDL_Surface *g_gameover = NULL;
static SDL_Surface *g_img_menu = NULL;
static SDL_Surface *g_screen = NULL;
static SDL_Surface *g_bkground = NULL;
static SDL_Event g_even; //quan ly event
static Mix_Music* g_sound;
static Mix_Chunk* g_sound_game_over;


namespace SDLCommonFunc //tao 1 namespace de tranh trung lap o ham khac trung ten
{
	SDL_Surface* LoadImage(string file_path);
	SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();
	bool CheckTouch(const SDL_Rect& object1, const SDL_Rect& object2) ; // ham kiểm tra xem 2 object có va chạm ko
    bool CheckFocusWithRect(const int& x, const int& y, const SDL_Rect& rect);
    int ShowMenu(SDL_Surface* des, TTF_Font* font);
    int GameOver(SDL_Surface* des, TTF_Font* font, string a);
}

#endif
