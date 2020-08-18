#include"BaseObject.h"
#include"Common_Function.h"
#include"MainObject.h"
#include"WoodObject.h"



MainObject::MainObject()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	x_val_ =0;
	y_val_ = 0;
}

MainObject::~MainObject()
{
	;
}


void MainObject::HandleInputAction(SDL_Event events)
{

	if(events.type == SDL_KEYDOWN) // 1 phim dc nhan
	{
		switch(events.key.keysym.sym)
		 {
		   case SDLK_LEFT:
                 x_val_ -= X_VAL_MOVE;
		   break;
		   case SDLK_RIGHT:
			   x_val_ += X_VAL_MOVE;
		   break;
		   default:
		   break;
		 }
	}
	else if(events.type == SDL_KEYUP)//  phim nao dc nha ra
	{
		switch(events.key.keysym.sym)
			 {
			   case SDLK_LEFT:
				  x_val_ += X_VAL_MOVE;
			   break;
			   case SDLK_RIGHT:
                x_val_ -= X_VAL_MOVE;
			   default:
			   break;
			 }
	}
}


void MainObject::HandleMove(int &stop)
{
	rect_.x += x_val_;
	if(rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH || stop <= 0) rect_.x -= x_val_;
	rect_.y += y_val_ ;

}





bool MainObject::CheckBallTouchSpines()
{
	if(rect_.y < 96 || rect_.y + HEIGHT_MAIN_OBJECT > 670) return 1;
	return 0;
}






