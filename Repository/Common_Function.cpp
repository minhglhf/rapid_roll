#include"Common_Function.h"
#include"Text.h"
#include"MainObject.h"
#include"WoodObject.h"
#include"Heart_Bonus.h"


bool SDLCommonFunc::CheckFocusWithRect(const int& x, const int& y, const SDL_Rect& rect)
{
    if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
    {
        return true;
    }
    return false;
}

int SDLCommonFunc::ShowMenu(SDL_Surface* des, TTF_Font* font)
{
    g_img_menu =LoadImage("menu.jpg");
    if(g_img_menu == NULL)
    {
        return 1;
    }

    const int kMenuItem = 2;
    SDL_Rect pos_arr[kMenuItem];
    pos_arr[0].x = 215;
    pos_arr[0].y = 215;

    pos_arr[1].x = 280;
    pos_arr[1].y = 275;

    Text text_menu[kMenuItem];

    text_menu[0].setText("Play Game");
    text_menu[0].testColor(Text::WHITE_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].setText("Exit");
    text_menu[1].testColor(Text::WHITE_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);

    bool selected[kMenuItem] = {0,0};
    int xm = 0;
    int ym = 0;

    SDL_Event m_event;
    while(true)
    {
        SDLCommonFunc::ApplySurface(g_img_menu,des ,0 ,0);
        for (int i = 0; i < kMenuItem; ++i)
        {
            text_menu[i].MakeText(font, des);

        }

        while(SDL_PollEvent(&m_event))
        {
            switch(m_event.type)
            {
            case SDL_QUIT:
                return 1;
            case SDL_MOUSEMOTION:
                {
                    xm = m_event.motion.x;
                    ym = m_event.motion.y;

                    for (int i = 0; i < kMenuItem; ++i)
                    {
                        if (CheckFocusWithRect(xm, ym, text_menu[i].GetRect()))
                        {
                            if (selected[i] == false)
                            {
                                selected[i] = 1;
                                text_menu[i].testColor(Text::AQUA_TEXT);
                            }
                        }
                        else
                        {
                            if (selected[i] == true)
                            {
                                selected[i] = 0;
                                text_menu[i].testColor(Text::WHITE_TEXT);
                            }
                        }
                    }
                    break;
                }
            case SDL_MOUSEBUTTONDOWN:
                {
                    xm = m_event.button.x;
                    ym = m_event.button.y;

                    for (int i = 0; i < kMenuItem; i++)
                    {
                        if (CheckFocusWithRect(xm, ym, text_menu[i].GetRect()))
                        {
                            return i;
                        }
                    }
                    break;
                }
            case SDL_KEYDOWN:
                    if (m_event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        return 1;
                    }
                    default:
                    break;
            }
        }
        SDL_Flip(des);
    }
    return 1;
}

int SDLCommonFunc::GameOver(SDL_Surface* des, TTF_Font* font, string a)
{
    g_img_menu =LoadImage("gameover.jpg");
    if(g_img_menu == NULL)
    {
        return 1;
    }



    Text score;

    score.setText(a);
    score.testColor(Text::WHITE_TEXT);
    score.SetRect(270,200);




        SDLCommonFunc::ApplySurface(g_img_menu,des ,0 ,0);
        score.MakeText(font, des);
        SDL_Flip(des);

    return 1;
}



SDL_Surface* SDLCommonFunc::LoadImage(string file_path) // ham load image
{
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;
	load_image = IMG_Load(file_path.c_str());
	if(load_image != NULL){
		optimize_image = SDL_DisplayFormat(load_image);
		SDL_FreeSurface(load_image);
		 if (optimize_image != NULL)
			 {
			   UINT32 color_key = SDL_MapRGB(optimize_image->format, 0x00, 0xFF, 0xFF); // mã màu dạng hexa xóa phông nền ảnh
			   SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
			 }
	}
	return optimize_image;
}

SDL_Rect SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)// load surface nguon vao surface dich
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, des, &offset);

  return offset;
}

void SDLCommonFunc::CleanUp()// giai phong doi tuong
{
  SDL_FreeSurface(g_screen);
  SDL_FreeSurface(g_bkground);
}

bool SDLCommonFunc::CheckTouch(const SDL_Rect& object1, const SDL_Rect& object2)
{
      int l_a = object1.x;
      int r_a = object1.x + object1.w;
      int t_a = object1.y;
      int b_a = object1.y + object1.h;

      int l_b = object2.x;
      int r_b = object2.x + object2.w;
      int t_b = object2.y;
      int b_b = object2.y + object2.h;


      if (l_a > l_b && l_a < r_b)
      {
        if (t_a > t_b && t_a < b_b)  return true;
        if (b_a > t_b && b_a < b_b) return true;
      }
      if (r_a > l_b && r_a < r_b)
      {
        if (t_a > t_b && t_a < b_b) return true;
        else if (b_a > t_b && b_a < b_b) return true;
      }


      if (l_b > l_a && l_b < r_a)
      {
        if (t_b > t_a && t_b < b_a) return true;
        else if (b_b > t_a && b_b < b_a) return true;
      }
      if (r_b > l_a && r_b < r_a)
      {
        if (t_b > t_a && t_b < b_a) return true;
        else if (b_b > t_a && b_b < b_a) return true;
      }

      if (t_a == t_b && r_a == r_b && b_a == b_b && l_a == l_b) return true;
      return false;

}


