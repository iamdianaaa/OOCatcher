#pragma once
#include "base_line.h"

class line1 : public base_line
{
public:
	line1(const point& that_p1, const point& that_p2);

	double get_x() const override;
	double get_y() const override;
	double end_x() const override;
	double end_y() const override;

	double length() const override;
	double slope()  const override;

	void shift(double dx, double dy) override;
	void rotate(double da) override;

private:
	shared_ptr<point> start;
	double len, ang;
};

