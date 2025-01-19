#ifndef __COLOR_HPP__
# define __COLOR_HPP__

# include "interval.hpp"
# include "vec3.hpp"

using color = vec3;

inline double linear_to_gamma(double linear_component)
{
	if (linear_component > 0)
		return std::sqrt(linear_component);

	return 0;
}

void write_color( std::ostream& out, color const &pixel_color )
{
	auto	r = pixel_color.x();
	auto	g = pixel_color.y();
	auto	b = pixel_color.z();

	// Apply a linear to gamma transform for gamma 2
	r = linear_to_gamma(r);
	g = linear_to_gamma(g);
	b = linear_to_gamma(b);

	static	const interval intensity(0.000, 0.999);
	int		rbyte = int(256 * intensity.clamp(r));
	int		gbyte = int(256 * intensity.clamp(g));
	int		bbyte = int(256 * intensity.clamp(b));

	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif