#include"WoodObject.h"

WoodObject::WoodObject()
{
	rect_.x = SCREEN_HEIGHT; //vi tri threat xuat hien
	rect_.y = SCREEN_HEIGHT;
	rect_.w = WIDTH_WOOD;
	rect_.h = HEIGHT_WOOD;
	y_val_ = 0;
}



WoodObject::~WoodObject()
{

}

void WoodObject::HandleMove()
{
	rect_.y -= y_val_;
	if(rect_.y < 96)
	{
		rect_.y = 670;// khi threat toi cuoi man hinh thi rect_.y ve vi tri ban dau
		int rand_x1 = rand()%400;
		rect_.x = rand_x1;
	}
}


