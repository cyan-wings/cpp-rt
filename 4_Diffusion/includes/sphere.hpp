#ifndef __SPHERE_HPP__
# define __SPHERE_HPP__

# include "hittable.hpp"
# include "cpp_rt.hpp"

class sphere : public hittable
{
	public:
		sphere(const point3& center, double radius) : center(center), radius(std::fmax(0,radius)) {}

		/*
		 Simplified to make computations faster.
		 b = -2h , which removes the -2.0 factor in b
		 and 4 factor in discriminant
		*/
		bool hit(const ray& r, interval ray_t, hit_record& rec) const override
		{
			vec3 oc = center - r.origin();
			auto a = r.direction().length_squared();
			auto h = dot(r.direction(), oc);
			auto c = oc.length_squared() - radius*radius;

			auto discriminant = h*h - a*c;
			if (discriminant < 0)
				return false;

			auto sqrtd = std::sqrt(discriminant);

			// Find the nearest root that lies in the acceptable range.
			auto root = (h - sqrtd) / a;
			if (!ray_t.surrounds(root))
			{
				root = (h + sqrtd) / a;
				if (!ray_t.surrounds(root))
					return false;
			}

			rec.t = root;
			rec.p = r.at(rec.t);
			vec3 outward_normal = (rec.p - center) / radius;
			rec.set_face_normal(r, outward_normal);

			return true;
		}

	private:
		point3 center;
		double radius;
};

#endif