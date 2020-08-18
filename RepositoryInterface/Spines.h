#ifndef SPINES_H_
#define SPINES_H_

#include"BaseObject.h"
#include"Common_Function.h"
#include<vector>
#define WIDTH_SPINES 136
#define HEIGHT_SPINES 24

class SpinesObject : public BaseObject
{
public:
	SpinesObject();
	~SpinesObject();
	void HandleMove();
	void set_y_val(const int& val) {y_val_ = val;}
	int get_y_val() const {return y_val_;}

private:
	int y_val_;

};

#endif
