#include <iostream>
#include <cmath>

#include "color.hpp"
#include "vec3.hpp"

/*
Red increases from left - right;
Blue reverse of Red;
Green increases from top - bottom;
*/
int	main( void )
{
	int	image_width = 256;
	int	image_height = 256;

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; ++j)
	{
		std::clog << "\rScanlines remaining: " << ( image_height - j ) << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i)
		{
			auto	r = double(i) / (image_width - 1);
			auto	pixel_color = color( r, double(j) / (image_height - 1), 1.0 - r);
			write_color( std::cout, pixel_color );
		}
	}

	std::clog << "\rDone.                  " << std::endl;
	return ( 0 );
}
