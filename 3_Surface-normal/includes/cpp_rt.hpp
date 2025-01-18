#ifndef __CPP_RT_HPP__
# define __CPP_RT_HPP__

# include <cmath>
# include <iostream>
# include <limits>
# include <memory>


// C++ Std Usings

using std::make_shared;
using std::shared_ptr;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees)
{
	return ( degrees * pi / 180.0 );
}

// Common Headers

# include "color.hpp"
# include "interval.hpp"
# include "ray.hpp"
# include "vec3.hpp"

#endif