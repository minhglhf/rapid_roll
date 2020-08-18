#include"Spines.h"

SpinesObject::SpinesObject()
{
	rect_.x = SCREEN_HEIGHT; //vi tri threat xuat hien
	rect_.y = SCREEN_HEIGHT;
	rect_.w = WIDTH_SPINES;
	rect_.h = HEIGHT_SPINES;
	y_val_ = 0;
}


SpinesObject::~SpinesObject()
{

}

void SpinesObject::HandleMove()
{
	rect_.y -= y_val_;
	if(rect_.y < 96)
	{
		rect_.y = 670;// khi threat toi cuoi man hinh thi rect_.y ve vi tri ban dau
		int rand_x2 = rand()%400;
		rect_.x = rand_x2;
	}
}

