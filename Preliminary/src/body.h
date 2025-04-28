#pragma once
#include "line1.h"
#include "line2.h"

class body
{
public:
	body(double neck_x, double neck_y, double seg_length);

	void rand_rotate();

	const point& get_neck() const { return neck; }
    const point& get_back() const { return back; }
    const base_line* get_segment(int idx) const { return segs[idx].get(); }

//private:
	point neck, back;
	unique_ptr<base_line> segs[6];
};

