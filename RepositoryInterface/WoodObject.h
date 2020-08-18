
#ifndef WOOD_OBJECT_H_
#define WOOD_OBJECT_H_

#include"BaseObject.h"
#include"Common_Function.h"
#include<vector>
#define WIDTH_WOOD 137
#define HEIGHT_WOOD 24

class WoodObject : public BaseObject
{
public:
	WoodObject();
	~WoodObject();
	void HandleMove();
	void set_y_val(const int& val) {y_val_ = val;}
	int get_y_val() const {return y_val_;}
	int get_x_rect() const {return rect_.x;}
	int get_y_rect() const {return rect_.y;}


private:
	int y_val_;

};

#endif
