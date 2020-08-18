#ifndef HEART_BONUS_H_
#define HEART_BONUS_H_

#define WIDTH_HEART_BONUS 32 // kich thuoc cua main object
#define HEIGHT_HEART_BONUS 32

#include"BaseObject.h"
#include"Common_Function.h"


class HeartBonus : public BaseObject
{
public:
    HeartBonus();
    ~HeartBonus();

	int get_y_rect() const {return rect_.y;}

};

#endif // HEART_BONUS_H_
