#include "body.h"

body::body(double neck_x, double neck_y, double seg_length) : neck(neck_x, neck_y), back(neck_x, neck_y + seg_length)
{
	segs[0] = make_unique<line1>(neck, back); //armL
	segs[1] = make_unique<line1>(neck, back); //armR

	segs[2] = make_unique<line1>(back, neck); //legL
	segs[3] = make_unique<line1>(back, neck); //legR

	segs[4] = make_unique<line2>(neck, back); //torsoD
	segs[5] = make_unique<line2>(back, neck); //torsoU
}

void body::rand_rotate()
{

}