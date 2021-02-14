/* Author: Sebastian Bruchhold */

#ifndef HYPERCUBE_C
#define HYPERCUBE_C

#include <stdbool.h>
#include <stddef.h>

#define X 4
#define Y 4
#define Z 4

void set(size_t x, size_t y, size_t z, bool val);

bool init(size_t x, size_t y, size_t z)
{
	return false;
}

bool fill(size_t x, size_t y, size_t z)
{
	return true;
}

void plot_pred(bool arr[Z][Y][X], bool (*pred)(size_t, size_t, size_t))
{
	size_t z, y, x;
	for (z = 0; z < Z; z++)
		for (y = 0; y < Y; y++)
			for (x = 0; x < X; x++)
				arr[z][y][x] = pred(x, y, z);
}

void plot_fun(bool arr[Z][Y][X], size_t (*fun)(size_t, size_t))
{
	size_t z, y, x;
	for (y = 0; y < Y; y++)
		for (x = 0; x < X; x++) {
			z = fun(x, y);
			if (z < Z)
				arr[z][y][x] = true;
		}
}

void convert(bool arr[Z][Y][X])
{
	size_t z, y, x;
	for (z = 0; z < Z; z++)
		for (y = 0; y < Y; y++)
			for (x = 0; x < X; x++)
				set(x, y, z, arr[z][y][x]);
}

#endif
