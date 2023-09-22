/*
 * TRABALHO 1 -Programção de Software Básico
 *
 * Alunos: Bianca da Silva Alves e Giuliano Roy Pontello
 * Contato: b.alves03@edu.pucrs.br ou giuliano.r@edu.pucrs.br
 * 
 * Professor: Sergio Johann Filho <sergio.johann@acad.pucrs.br>
*/

#include <stdio.h>
#include <stdint.h>
#include "./include/lib_ppm.h"
#include "./include/filter_grayscale.h"
#include "./include/filter_threshold.h"
#include "./include/filter_sobel.h"
#include "./include/filter_roberts.h"

struct image_s dataOne;
struct image_s *input = &dataOne;
struct image_s dataSecond;
struct image_s *output = &dataSecond;
struct image_s dataNew;
struct image_s *new = &dataNew;

int main(void)
{
	int r;
	r = read_ppm("images/cervo.ppm", input);

	// FILTRO GRAYSCALE
	if (r == 0) {
		r = new_ppm(output, input->width, input->height);
		if (r == 0) {
			int g = grayscale(input, output);
			if (g == 0) {
				write_ppm("images/out/grayscale.ppm", output);
			}
		}
	}

	// FILTRO THRESHOLD
	int limiar;
	r = new_ppm(new, input->width, input->height);
	if (r == 0) {
		// Coleta o limiar com o usuário
		printf("\nInforme um limiar: ");
		scanf("%d", &limiar);
		int t = threshold(output, new, limiar);
		if (t == 0) {
			write_ppm("images/out/threshold.ppm", new);
		}
	}

	// FILTRO SOBEL
	r = new_ppm(output, input->width, input->height);
	if (r == 0) {
		int s = sobel(input,output);
		if (s == 0) {
			write_ppm("images/out/sobel.ppm", output);
		}
	}

	// FILTRO ROBERT CROSS
	r = new_ppm(output, input->width, input->height);
	if (r == 0) {
		int c = roberts(input,output);
		if (c == 0) {
			write_ppm("images/out/roberts.ppm", output);
		}
	}
	
	return 0;
}
