#ifndef __COLOR_HPP__
# define __COLOR_HPP__

# include "interval.hpp"
# include "vec3.hpp"

using color = vec3;

void write_color( std::ostream& out, color const &pixel_color )
{
	auto	r = pixel_color.x();
	auto	g = pixel_color.y();
	auto	b = pixel_color.z();

	static	const interval intensity(0.000, 0.999);
	int		rbyte = int(256 * intensity.clamp(r));
	int		gbyte = int(256 * intensity.clamp(g));
	int		bbyte = int(256 * intensity.clamp(b));

	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif