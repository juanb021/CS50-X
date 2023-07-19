#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop trough each row of the image.
    for (int i = 0; i < height; i ++)
    {
        // Loop trough each column.
        for (int j = 0; j < width; j++)
        {
            // Convert pixels to float.
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            // Calculate the average value of the pixels.
            int average = round((red + green + blue) / 3);

            // Replace the value on each pixel to the average.
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop trough each row.
    for (int i = 0; i < height; i ++)
    {
        // Loop trough each column.
        for (int j = 0; j < width; j++)
        {
            // Convert pixels to float.
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            // Make the Sepia value.
            int sepia_red = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepia_green = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepia_blue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            // Updated the pixels.
            if (sepia_red > 255)
            {
                sepia_red = 255;
            }
            if (sepia_green > 255)
            {
                sepia_green = 255;
            }
            if (sepia_blue > 255)
            {
                sepia_blue = 255;
            }

            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen  = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop trough each row.
    for (int i = 0; i < height; i ++)
    {
        // Loop trough each column.
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the original image.
    RGBTRIPLE temp[height][width];
    // Loop trough each row.
    for (int i = 0; i < height; i ++)
    {
        // Loop trough each column.
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // CHECK

    // Loop trough each row.
    for (int i = 0; i < height; i ++)
    {
        // Loop trough each column.
        for (int j = 0; j < width; j++)
        {
            int total_red, total_green, total_blue;
            total_red = total_green = total_blue = 0;
            float counter = 0.0;

            // Get the value of the adyacent pixels (-1,-1) to (1,1).
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int current_x = i + x;
                    int current_y = j + y;

                    // Check if the pixel is valid.
                    if (current_x < 0 || current_x > (height - 1) || current_y < 0 || current_y > (width - 1))
                    {
                        continue;
                    }
                    total_red += image[current_x][current_y].rgbtRed;
                    total_green += image[current_x][current_y].rgbtGreen;
                    total_blue += image[current_x][current_y].rgbtBlue;

                    counter ++;
                }
                // Calculate the average.
                temp[i][j].rgbtRed = round(total_red / counter);
                temp[i][j].rgbtGreen = round(total_green / counter);
                temp[i][j].rgbtBlue = round(total_blue / counter);
            }
        }
    }

    // Copy the blurred values into the original image.
    // Loop trough each row.
    for (int i = 0; i < height; i++)
    {
        // Loop trough each column.
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
