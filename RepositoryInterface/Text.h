#ifndef TEXT_H_
#define TEXT_H_

#include"BaseObject.h"
#include<string>
#include<SDL_ttf.h>


class Text : public BaseObject
{
public:
    enum TextColor
    {
        AQUA_TEXT = 0,
        WHITE_TEXT = 1,
        RED_TEXT = 2,
    };

    Text();
    ~Text();
    void setText(const std::string& text) {text_screen = text;}
    void MakeText(TTF_Font* font, SDL_Surface* des);
    void setColor(SDL_Color &color);
    void testColor(const int& type);
private:
    std::string text_screen;
    SDL_Color text_color;
};

#endif // TEXT_H_
