#ifndef SNOW_FALLING_H_
#define SNOW_FALLING_H_

#include"BaseObject.h"
#include"Common_Function.h"
#include<vector>
#define WIDTH_SNOW 25
#define HEIGHT_SNOW 28

class SnowFalling : public BaseObject
{
public:
	SnowFalling();
	~SnowFalling();
	void HandleMove();
	void set_y_val(const int& val) {y_val_ = val;}
	int get_y_val() const {return y_val_;}
	int get_x_rect() const {return rect_.x;}
	int get_y_rect() const {return rect_.y;}


private:
	int y_val_;

};

#endif
