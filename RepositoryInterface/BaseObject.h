#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include"Common_Function.h"

class BaseObject
{
public:
	BaseObject();
	~BaseObject();
	void Show(SDL_Surface* des);
	bool LoadImg(const char* file_name);
	void SetRect(const int& x, const int &y){rect_.x =x, rect_.y =y;} // nhap toa do object
	SDL_Rect GetRect() const {return rect_;} //tra ve toa do object
	SDL_Surface* GetObject() {return p_object_;}
protected:
	SDL_Rect rect_; //toa do cua doi tuong
	SDL_Surface* p_object_;
};

#endif
