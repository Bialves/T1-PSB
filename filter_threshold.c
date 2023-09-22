#include <stdio.h>
#include "./include/lib_ppm.h"
#include "./include/filter_threshold.h"

int threshold(struct image_s *src_image, struct image_s *dst_image, unsigned char value)
{
    for (int i = 0; i < src_image->height; i++) {
		for (int j = 0; j < src_image->width; j++) {
            // Posição do pixel atual
            int pixel = i * src_image->width + j;

            // Coleta o RGB do pixel
			int red = src_image->pix[pixel].r;
			int green = src_image->pix[pixel].g;
			int blue = src_image->pix[pixel].b;

            // Grava o resultado
            int y = (int)(red + green + blue)/3;
            if (y > value) {
                y = 255;
            } else {
                y = 0;
            }
            dst_image->pix[pixel].r = y;
            dst_image->pix[pixel].g = y;
            dst_image->pix[pixel].b = y;
		}
	}

    return 0;
}