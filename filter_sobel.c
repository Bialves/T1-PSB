#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib_ppm.h"
#include "filter_sobel.h"

int sobel(struct image_s *src_image, struct image_s *dst_image)
{
    // Declaração das matrizes
    int Gx[3][3] = {{-1,0,1},
                    {-2,0,2},
                    {-1,0,1}};

    int Gy[3][3] = {{1,2,3},
                    {0,0,0},
                    {-1,-2,-3}};

    // Estrutura auxiliar
    struct pixel_s p[3][3] = {};

    for (int i = 1; i < src_image->height-1; i++) {
        for (int j = 1; j < src_image->width-1; j++) {
            // Posição do pixel target
            int pixel = i * src_image->width + j;

            // Linha anterior
            p[0][0] = src_image->pix[(i-1) * src_image->width + (j-1)];
            p[0][1] = src_image->pix[(i-1) * src_image->width + j];
            p[0][2] = src_image->pix[(i-1) * src_image->width + (j+1)];
            // Linha atual (do target)
            p[1][1] = src_image->pix[pixel];
            p[1][0] = src_image->pix[i * src_image->width + (j-1)];
            p[1][2] = src_image->pix[i * src_image->width + (j+1)];
            // Linha posterior
            p[2][0] = src_image->pix[(i+1) * src_image->width + (j-1)];
            p[2][1] = src_image->pix[(i+1) * src_image->width + j];
            p[2][2] = src_image->pix[(i+1) * src_image->width + (j+1)];

            // Aplica a fórmula
            int one = 0;
            int second = 0;
            for (int y = 0; y<3; y++) {
                for (int x = 0; x<3; x++) {
                    int red = p[y][x].r;
			        int green = p[y][x].g;
			        int blue = p[y][x].b;

                    one += (Gx[y][x] * red) + (Gx[y][x] * green) + (Gx[y][x] * blue);
                    second += (Gy[y][x] * red) + (Gy[y][x] * green) + (Gy[y][x] * blue);
                }
            
            }
            // Grava o resultado
            int result = abs(one) + abs(second);
            dst_image->pix[pixel].r = result;
            dst_image->pix[pixel].g = result;
            dst_image->pix[pixel].b = result;
        }
	}

    return 0;
}