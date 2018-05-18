#include "lib/svpng.inc"
#include "Detail/Sphere.hpp"
#include "Detail/Camera_F.hpp"

#include <algorithm>

const int height = 512;
const int width = 512;


void render_depth(Sphere scene, Camera_F camera, int max_depth)
{
	unsigned char depth_test[width * height * 3];
	auto pixels = depth_test;
	FILE *fp = fopen("img/depth_test.png", "wb");
    
    camera.initialize();

    float dD=255.0f / max_depth;
	
	int i = 0;
    for (int y = 0; y < height; y++)
    {
        float sy = 1 - y * 1.0f / height;
        for (int x = 0; x < width; x++) {
            float sx = 1 - x * 1.0f / width;
            Ray3 ray = camera.generate_ray(sx, sy);
            Intersect_result result = scene.intersect(ray);
			if (result.geometry)
			{
				auto depth = (unsigned char)(255 - std::min(result.distance * dD, 255.0f));
				pixels[i	] = depth;
				pixels[i + 1] = depth;
				pixels[i + 2] = depth;
			}
			else pixels[i] = pixels[i + 1] = pixels[i + 2] = 0;
			
			i += 3;
        }
    }

	svpng(fp, width, height, depth_test, false);
	fclose(fp);
}

void render_normal(Sphere scene, Camera_F camera)
{
	unsigned char normal_test[width * height * 3], *pixels = normal_test;
	FILE *fp = fopen("img/normal_test.png", "wb");

	camera.initialize();

	int i = 0;
	for (int y = 0; y < height; y++)
	{
		float sy = 1 - y * 1.0f / height;
		for (int x = 0; x < width; x++) {
			float sx = 1 - x * 1.0f / width;
			Ray3 ray = camera.generate_ray(sx, sy);
			Intersect_result result = scene.intersect(ray);
			if (result.geometry)
			{
				pixels[i	] = (result.normal.x + 1) * 128;
				pixels[i + 1] = (result.normal.y + 1) * 128;
				pixels[i + 2] = (result.normal.z + 1) * 128;
			}
			else pixels[i] = pixels[i + 1] = pixels[i + 2] = 0;

			i += 3;
		}
	}

	svpng(fp, width, height, normal_test, false);
	fclose(fp);
}

int main(int argc, char *argv[])
{
	Sphere sp(Vector3(0, 10, -10), 10);
	Camera_F caf(Vector3(0, 10, 10), 
				 Vector3(0, 0, -1), 
				 Vector3(0, 1, 0), 90);
	
	render_depth(sp, caf, 20);

	render_normal(sp, caf);

    return 0;
}