#ifndef __COLOR_HPP__
# define __COLOR_HPP__

# include "vec3.hpp"

# include <iostream>

using color = vec3;

void write_color( std::ostream& out, color const &pixel_color )
{
	auto	r = pixel_color.x();
	auto	g = pixel_color.y();
	auto	b = pixel_color.z();

	int		rbyte = int(255.999 * r);
	int		gbyte = int(255.999 * g);
	int		bbyte = int(255.999 * b);

	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif