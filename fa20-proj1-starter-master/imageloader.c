/************************************************************************
**
** NAME:        imageloader.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**              Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-15
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "imageloader.h"

//Opens a .ppm P3 image file, and constructs an Image object. 
//You may find the function fscanf useful.
//Make sure that you close the file with fclose before returning.
Image *readData(char *filename) 
{
	//YOUR CODE HERE
	FILE *fp;
	fp = fopen(filename , "r");

	if(fp == NULL){
		// perror prints a descriptive error message to stderr.
		perror("Failed to open file");
		printf("/nfail");
	}

	// Read the format of the file.
	char format[3]; 
	fscanf(fp , "%s" , format);

	// Read the the width and the height of our image.
	Image *ImgPtr = (Image*) malloc(sizeof(Image));
	fscanf(fp, "%u" ,&ImgPtr->rows);
	fscanf(fp, "%u" ,&ImgPtr->cols);

	// Read the scale with which we are describing colors.
	int max_colour;
	fscanf(fp , "%u" ,&max_colour);

	// Read the data of each pixel.
	int total_pixel = ImgPtr->cols * ImgPtr->rows;
	ImgPtr->image == (Color**) malloc(sizeof(Color*) * total_pixel);
	for(int i = 0; i <total_pixel; i++){
		*(ImgPtr->image + i) = (Color*) malloc(sizeof(Color));
		Color *pixel = *(ImgPtr->image + i);
		fscanf(fp, "%hhu %hhu %hhu", &pixel->R, &pixel->G, &pixel->B);
	}

	// Close the file.
	fclose(fp);

	return fp;
}

//Given an image, prints to stdout (e.g. with printf) a .ppm P3 file with the image's data.
void writeData(Image *image)
{
	//YOUR CODE HERE
	printf("p3\n%d\n255\n", image->cols, image->rows);
	Color** ptr = image->image;
	for (int i = 0; i < image->rows; i++){
		for(int j = 0; j < image->cols-1; j++){
			printf("%3hhu %3hhu %3hhu", (*ptr)->R, (*ptr)->G, (*ptr)->B);
			ptr++;
		}
		printf("%3hhu %3hhu %3hhu\n", (*ptr)->R, (*ptr)->G, (*ptr)->B);
		ptr++;
	}
}

//Frees an image
void freeImage(Image *image)
{
	//YOUR CODE HERE
	int total_pixel = image->cols * image->rows;
	for (int i = 0; i < total_pixel; i++){
		free(*(image->image + i));
	}
	free(image->image);
}