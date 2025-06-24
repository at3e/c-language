#include<stdio.h>
#include "bmp.h"

int main() {
    image o_file;

    // initialize header
    o_file.file_header.header.signature[0] = 'B';
    o_file.file_header.header.signature[1] = 'M';
    o_file.file_header.header.file_size = sizeof(o_file);
    o_file.file_header.header.reserved = 0;
    o_file.file_header.header.data_offset = sizeof(o_file.file_header);
    o_file.file_header.header.dib_size = sizeof(o_file.file_header.dib_header);
    o_file.file_header.header.width = SQUARE_SIZE;
    o_file.file_header.header.height = SQUARE_SIZE;
    o_file.file_header.header.num_planes = 1;
    o_file.file_header.header.bpp = sizeof(pixel) * 8;
    o_file.file_header.header.compression = 0;
    o_file.file_header.header.image_size = sizeof(o_file.pixel_data);
    o_file.file_header.header.x_ppm = 0;
    o_file.file_header.header.y_ppm = 0;
    o_file.file_header.header.num_colors = 0;
    o_file.file_header.header.important_colors = 0;


    // generate pixel data
    for (int x = 0; x < SQUARE_SIZE; x++) {
        for (int y = 0; y < SQUARE_SIZE; y++) {
            o_file.pixel_data[x][y].blue = 0;
            o_file.pixel_data[x][y].green = 0;
            o_file.pixel_data[x][y].red = 255;
        }
    }

    FILE *file = fopen("red-square.bmp", "wb");
    if (file == NULL) {
        printf("Error: could not create file.\n");
        return 1;
    }

    fwrite(&o_file, sizeof(o_file), 1, file);
    fclose(file);

    return 0;
}