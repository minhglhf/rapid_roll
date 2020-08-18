#include"Text.h"

Text::Text()
{
  rect_.x = 0;
  rect_.y = 0;
}

Text::~Text()
{

}

void Text::setColor(SDL_Color &color)
{
    text_color = color;
}

void Text::MakeText(TTF_Font* font, SDL_Surface* des)
{
    p_object_ = TTF_RenderText_Solid(font, text_screen.c_str(), text_color);
    Show(des);
}
void Text::testColor(const int& type)
{
    if (type == AQUA_TEXT)
    {
        SDL_Color color = {0, 255, 255};
        text_color = color;
    }
    else if (type == RED_TEXT)
    {
        SDL_Color color = {172, 7 , 16};
        text_color = color;
    }
    else
    {
        SDL_Color color = {255, 255 ,255};
        text_color = color;
    }
}


