#include <iostream>
#include <cmath>

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
			auto	b = 1.0 - r;
			auto	g = double(j) / (image_height - 1);

			auto	ir = int(255.999 * r);
			auto	ig = int(255.999 * g);
			auto	ib = int(255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}

	std::clog << "\rDone.                  " << std::endl;
	return ( 0 );
}
