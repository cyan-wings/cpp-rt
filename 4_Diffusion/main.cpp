#include "cpp_rt.hpp"
#include "camera.hpp"
#include "hittable.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"

color ray_color( ray const &r, hittable const &world )
{
	hit_record rec;
	if (world.hit(r, interval(0, infinity), rec))
		return 0.5 * (rec.normal + color(1,1,1));
	vec3	unit_direction = unit_vector(r.direction());
	auto	a = 0.5*(unit_direction.y() + 1.0);
	return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int	main( void )
{
	hittable_list	world;

	world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
	world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

	camera			cam;

	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width  = 400;
	cam.samples_per_pixel = 100;

	cam.render( world );
	return ( 0 );
}
