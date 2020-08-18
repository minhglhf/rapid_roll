#include"Snow_falling.h"

SnowFalling::SnowFalling()
{
	rect_.x = 96;
	rect_.y = 96;
	rect_.w = WIDTH_SNOW;
	rect_.h = HEIGHT_SNOW;
	y_val_ = 0;
}



SnowFalling::~SnowFalling()
{

}

void SnowFalling::HandleMove()
{
	rect_.y -= y_val_;
	if(rect_.y + rect_.h > 670)
	{
		rect_.y = 96;// khi threat toi cuoi man hinh thi rect_.y ve vi tri ban dau
		int rand_x1 = rand()%600;
		rect_.x = rand_x1;
	}
}
