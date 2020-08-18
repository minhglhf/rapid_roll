#include"Common_Function.h"
#include"BaseObject.h"
#include"MainObject.h"
#include"WoodObject.h"
#include"Spines.h"
#include <ctime>
#include"Text.h"
#include"Heart_Bonus.h"
#include "ImpTimer.h"
#include"Snow_falling.h"
#include"fstream"
#undef main
using namespace std;

//////////////---------GAME RAPID ROLL----------/////////////////
// ------------ luy y cam sac de game choi game muot  -----------//

TTF_Font* g_font_text = NULL;

bool Init() //khoi tao cac thuoc tinh ban dau
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
  {
    return false;
  }
  g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  if (g_screen == NULL)
  {
    return false;
  }
  if(TTF_Init() == -1) return false;

  g_font_text = TTF_OpenFont("OpenSans-Bold.ttf", 40);
  if(g_font_text == NULL) return false;
  if(Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096)==-1)
    return false;
  g_sound=Mix_LoadMUS("theme_song.mp3");
  g_sound_game_over=Mix_LoadWAV("audio_game_over.wav");
  if(g_sound == NULL || g_sound_game_over == NULL)
  {
      return false;
  }
  return true;
}



int main(int arc, char* argv[])
{
     ImpTimer fps_timer;
	 bool is_quit = false;
     if (Init() == false)
     return 0;
	 g_bkground = SDLCommonFunc::LoadImage("bk5.jpg");
	 if (g_bkground == NULL) return 0;

     MainObject ball_object;
	 ball_object.SetRect(282, 200); // toa do main obejct hien ra
	 bool ret = ball_object.LoadImg("snowman.png");
	 if(ret == false) return 0;


     Mix_PlayMusic(g_sound, -1);
	 int speed_wph = 1;

     HeartBonus heart_extra;
     heart_extra.LoadImg("heart_bonus.png");

	 srand(time(NULL));

     //Wood Object
	 WoodObject p_wood[NUM_WOOD];
	 for(int t=0; t<NUM_WOOD; t++) // tao nhieu threat xuat hien ngau nhien
	 {
		 int rand_x1;
		 p_wood[t].LoadImg("wood3.jpg");
		 rand_x1 = rand()%505 + 1;
		 p_wood[t].SetRect(rand_x1 , SCREEN_HEIGHT/2 + t * 125); // vi tri  xuat hien
		 p_wood[t].set_y_val(speed_wph); //toc do
	 }

	 SnowFalling p_snow[NUM_SNOW];
	 for(int ttt=0; ttt<NUM_SNOW; ttt++) // tao nhieu threat xuat hien ngau nhien
	 {
		 int rand_x1;
         p_snow[ttt].LoadImg("snow_8.png");

		 rand_x1 = rand()%600 + 1;
		 p_snow[ttt].SetRect(rand_x1 , 96 + ttt * 30); // vi tri  xuat hien
		 p_snow[ttt].set_y_val(-1); //toc do
	 }

     //spines object
	 SpinesObject p_threat[NUM_SPINES];
	 for(int tt=0; tt<NUM_SPINES; tt++) // tao nhieu threat xuat hien ngau nhien
	 {
		int rand_x2;
		p_threat[tt].LoadImg("spines2.png");
		rand_x2 = rand()%505 + 1;
		if(tt == 0) p_threat[tt].SetRect(rand_x2, SCREEN_HEIGHT/2 + 50); // vi tri threat xuat hien
		else p_threat[tt].SetRect(rand_x2, SCREEN_HEIGHT/2 + tt * 280); // vi tri threat xuat hien
		p_threat[tt].set_y_val(speed_wph); //toc do threat;	 }
	 }


     int rect_y_before = ball_object.get_y_rect();
     int y_val_begin = 1;
     int mark_val = 0;
     int heart = NUM_OF_HEARTS;
     int speedup_point = 300;
     int heart_point = 500;
     int a=0;

     int ret_menu = SDLCommonFunc::ShowMenu(g_screen, g_font_text);
        if (ret_menu == 1)
        {
              is_quit = true;
        }

	 while (!is_quit)
        {


            while (SDL_PollEvent(&g_even)) //vong lap dien ra su kien cuq handle move action
            {
              if (g_even.type == SDL_QUIT) // neu kieu su kien = quit
              {
                is_quit = true;
                break;
              }
              ball_object.HandleInputAction(g_even); //goi su kien
            }

        ball_object.set_y_val(y_val_begin);
        ball_object.HandleMove(heart); // goi ham handmove
        SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0); // sau moi lan handlemove xoa hinh cu va thay the hinh moi
        ball_object.Show(g_screen); // update lai hinh sau moi lan handmove.

        if(ball_object.get_y_rect() == rect_y_before + ball_object.get_y_val() * 10)
        {
            rect_y_before = ball_object.get_y_rect();
            y_val_begin+=1;
        }


      //  cout<<ball_object.get_y_val()<<"     "<<ball_object.get_x_val()<<"      "<<speed_wph<<"    "<<heart_point<<endl;
      // cout<<v<<"   "<<ball_object.get_y_val()<<endl;

         mark_val++;


        if(mark_val == speedup_point && speedup_point <= 2400 )
        {
            speedup_point += 300;
            speed_wph++;
        }


        if(ball_object.CheckBallTouchSpines() == 1)
            {
                heart--;
                y_val_begin = 1;
                int lowest_wood = 0, k;
                for(int t=0; t<NUM_WOOD;t++)
                {
                    if(p_wood[t].get_y_rect()< 670 && p_wood[t].get_y_rect() > lowest_wood)
                        {
                    lowest_wood = p_wood[t].get_y_rect();
                    k=t;
                        }
                }
                ball_object.SetRect(p_wood[k].get_x_rect() + WIDTH_WOOD/2, p_wood[k].get_y_rect() - HEIGHT_MAIN_OBJECT);
            }


            p_threat[0].set_y_val(speed_wph);
            p_threat[1].set_y_val(speed_wph);
            for(int t=0; t<NUM_WOOD; t++)
                {
                    p_wood[t].HandleMove();
                    p_wood[t].Show(g_screen);
                    p_wood[t].set_y_val(speed_wph);
                }

            for(int ttt=0; ttt<NUM_SNOW; ttt++)
                {
                    p_snow[ttt].HandleMove();
                    p_snow[ttt].Show(g_screen);
                }

            if(mark_val == heart_point )
              {

              int lowest_wood = 0, k;
                for(int t=0; t<NUM_WOOD;t++)
                {
                    if(p_wood[t].get_y_rect() < 670 && p_wood[t].get_y_rect() > lowest_wood)
                        {
                            lowest_wood = p_wood[t].get_y_rect();
                            k=t;
                        }
                }
                 heart_extra.SetRect(p_wood[k].get_x_rect() + WIDTH_WOOD/2, p_wood[k].get_y_rect() - HEIGHT_HEART_BONUS - 2);
                a=k;
              }


            if(heart_extra.get_y_rect() > 96)
                {
                    heart_extra.SetRect(p_wood[a].get_x_rect() + WIDTH_WOOD/2, p_wood[a].get_y_rect() - HEIGHT_HEART_BONUS - 2);
                    heart_extra.Show(g_screen);
                    if(heart_extra.get_y_rect() <= 96) heart_point+=500;
                }
             if(SDLCommonFunc::CheckTouch( heart_extra.GetRect(), ball_object.GetRect()) == true)
                    {
                    heart++;
                    heart_point += 500;
                    heart_extra.SetRect(-1,-1);
                    }

        for(int t=0; t<NUM_WOOD; t++)
            {
                bool is_touch = SDLCommonFunc::CheckTouch( ball_object.GetRect(), p_wood[t].GetRect());
                if(is_touch == true)
                    {
                        ball_object.SetRect(ball_object.get_x_rect(), p_wood[t].get_y_rect() - HEIGHT_MAIN_OBJECT);
                        //ball_object.HandleMoveWhenTouch(p_wood[t].GetRect());
                        ball_object.Show(g_screen);
                        rect_y_before = ball_object.get_y_rect();
                        y_val_begin = 1;

                        if(ball_object.get_y_rect() + HEIGHT_MAIN_OBJECT < p_wood[t].get_y_rect() + 2) mark_val--;
                        for(int t=0; t<NUM_WOOD; t++)
                            {
                                p_wood[t].Show(g_screen);
                            }

                    }
            }

        if(heart > 6 ) heart--;

        for(int tt=0; tt<NUM_SPINES; tt++)
        {
            p_threat[tt].HandleMove();
            p_threat[tt].Show(g_screen);

            //check touch
            bool is_col = SDLCommonFunc::CheckTouch( ball_object.GetRect(), p_threat[tt].GetRect());
            if(is_col == true)
            {
                heart--;
                y_val_begin = 1;
                int lowest_wood = 0, k;
                for(int t=0; t<NUM_WOOD;t++)
                {
                    if(p_wood[t].get_y_rect()< 670 && p_wood[t].get_y_rect() > lowest_wood)
                        {
                            lowest_wood = p_wood[t].get_y_rect();
                            k=t;
                        }
                }
                ball_object.SetRect(p_wood[k].get_x_rect() + WIDTH_WOOD/2, p_wood[k].get_y_rect() - HEIGHT_MAIN_OBJECT);
            }
        }




        Text mark;
        std::string val_str_mark = std::to_string(mark_val);
        mark.setText(val_str_mark);
        mark.SetRect(440,4);
        SDL_Color mark_color = {0, 0 ,0};
        mark.setColor(mark_color);
        mark.MakeText(g_font_text, g_screen);

        Text main_heart;
        std::string val_str_heart = std::to_string(heart);
        main_heart.setText(val_str_heart);
        main_heart.SetRect(110, 4);
        SDL_Color heart_color = {255, 0 ,0};
        main_heart.setColor(heart_color);
        main_heart.MakeText(g_font_text, g_screen);

        if(heart == 0)
        {Mix_PlayChannel(-1, g_sound_game_over, 0 );
        heart--;
        }

            if(heart <= 0)
                    {

                        Mix_HaltMusic();
                        SDLCommonFunc::GameOver(g_screen, g_font_text, val_str_mark);



                        fstream file;
                        file.open("high_score.txt", ios::in);
                        int highscore;
                        file >> highscore;
                        file.close();

                        if(mark_val > highscore)
                        {
                                highscore = mark_val;
                                fstream file;
                                file.open("high_score.txt", ios::out);
                                file << highscore <<endl;
                                file.close();
                        }

                        Text high_score;
                        std::string val_str_score = std::to_string(highscore);
                        high_score.setText(val_str_score);
                        high_score.SetRect(270,315);
                        SDL_Color color2 = {255, 0 ,0};
                        high_score.setColor(color2);
                        high_score.MakeText(g_font_text, g_screen);

                    }
        if ( SDL_Flip(g_screen) == -1) // giu window luon update va giu chuong trinh lien tuc chay
        return 0;



        int real_imp_time = fps_timer.get_ticks();
        int time_one_frame = 1000/FRAME_PER_SECOND;//ms

        if(real_imp_time < time_one_frame)
        {
            int delay_time = time_one_frame - real_imp_time;
            if(delay_time >= 0)
                SDL_Delay(delay_time);
        }

      }

    SDLCommonFunc::CleanUp();
    SDL_Quit();
    return 0;
}
