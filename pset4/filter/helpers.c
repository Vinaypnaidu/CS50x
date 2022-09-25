#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            unsigned int tempBlue = image[i][j].rgbtBlue;
            unsigned int tempGreen = image[i][j].rgbtGreen;
            unsigned int tempRed = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = (unsigned int)(round)(((float)tempBlue + (float)tempGreen + (float)tempRed) / 3);
            image[i][j].rgbtGreen = (unsigned int)(round)(((float)tempBlue + (float)tempGreen + (float)tempRed) / 3);
            image[i][j].rgbtRed = (unsigned int)(round)(((float)tempBlue + (float)tempGreen + (float)tempRed) / 3);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int low = 0;
        int high = width - 1;
        for (int j = 0; j < width; j++)
        {
            while (low < high)
            {
                unsigned int tempred = 0;
                tempred = image[i][low].rgbtRed;
                image[i][low].rgbtRed = image[i][high].rgbtRed;
                image[i][high].rgbtRed = tempred;
                unsigned int tempgreen = 0;
                tempgreen = image[i][low].rgbtGreen;
                image[i][low].rgbtGreen = image[i][high].rgbtGreen;
                image[i][high].rgbtGreen = tempgreen;
                unsigned int tempblue = 0;
                tempblue = image[i][low].rgbtBlue;
                image[i][low].rgbtBlue = image[i][high].rgbtBlue;
                image[i][high].rgbtBlue = tempblue;
                low++;
                high--;
            }
        }
    }
    return;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimage[height][width];
    unsigned int redsum = 0;
    unsigned int greensum = 0;
    unsigned int bluesum = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            redsum = image[i][j].rgbtRed;
            greensum = image[i][j].rgbtGreen;
            bluesum = image[i][j].rgbtBlue;
            int count = 1;
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                redsum = redsum + image[i - 1][j - 1].rgbtRed;
                greensum = greensum + image[i - 1][j - 1].rgbtGreen;
                bluesum = bluesum + image[i - 1][j - 1].rgbtBlue;
                count ++;
            }
            if (i - 1 >= 0)
            {
                redsum = redsum + image[i - 1][j].rgbtRed;
                greensum = greensum + image[i - 1][j].rgbtGreen;
                bluesum = bluesum + image[i - 1][j].rgbtBlue;
                count ++;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                redsum = redsum + image[i - 1][j + 1].rgbtRed;
                greensum = greensum + image[i - 1][j + 1].rgbtGreen;
                bluesum = bluesum + image[i - 1][j + 1].rgbtBlue;
                count ++;
            }
            if (j + 1 < width)
            {
                redsum = redsum + image[i][j + 1].rgbtRed;
                greensum = greensum + image[i][j + 1].rgbtGreen;
                bluesum = bluesum + image[i][j + 1].rgbtBlue;
                count ++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                redsum = redsum + image[i + 1][j + 1].rgbtRed;
                greensum = greensum + image[i + 1][j + 1].rgbtGreen;
                bluesum = bluesum + image[i + 1][j + 1].rgbtBlue;
                count ++;
            }
            if (i + 1 < height)
            {
                redsum = redsum + image[i + 1][j].rgbtRed;
                greensum = greensum + image[i + 1][j].rgbtGreen;
                bluesum = bluesum + image[i + 1][j].rgbtBlue;
                count ++;
            }
            if (j - 1 >= 0)
            {
                redsum = redsum + image[i][j - 1].rgbtRed;
                greensum = greensum + image[i][j - 1].rgbtGreen;
                bluesum = bluesum + image[i][j - 1].rgbtBlue;
                count ++;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                redsum = redsum + image[i + 1][j - 1].rgbtRed;
                greensum = greensum + image[i + 1][j - 1].rgbtGreen;
                bluesum = bluesum + image[i + 1][j - 1].rgbtBlue;
                count ++;
            }
            tempimage[i][j].rgbtRed = (unsigned int)((round)((float)redsum / count));
            tempimage[i][j].rgbtGreen = (unsigned int)((round)((float)greensum / count));
            tempimage[i][j].rgbtBlue = (unsigned int)((round)((float)bluesum / count));

        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempimage[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempimage[height][width];
    int redsumgx = 0;
    int redsumgy = 0;
    int greensumgx = 0;
    int greensumgy = 0;
    int bluesumgx = 0;
    int bluesumgy = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            redsumgx = image[i][j].rgbtRed;
            redsumgy = image[i][j].rgbtRed;
            greensumgx = image[i][j].rgbtGreen;
            greensumgy = image[i][j].rgbtGreen;
            bluesumgx = image[i][j].rgbtBlue;
            bluesumgy = image[i][j].rgbtBlue;
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                redsumgx = redsumgx - image[i - 1][j - 1].rgbtRed;
                redsumgy = redsumgy - image[i - 1][j - 1].rgbtRed;
                greensumgx = greensumgx - image[i - 1][j - 1].rgbtGreen;
                greensumgy = greensumgy - image[i - 1][j - 1].rgbtGreen;
                bluesumgx = bluesumgx - image[i - 1][j - 1].rgbtBlue;
                bluesumgy = bluesumgy - image[i - 1][j - 1].rgbtBlue;
            }
            if (i - 1 >= 0)
            {
                redsumgy = redsumgy - (2 * image[i - 1][j].rgbtRed);
                greensumgy = greensumgy - (2 * image[i - 1][j].rgbtGreen);
                bluesumgy = bluesumgy - (2 * image[i - 1][j].rgbtBlue);
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                redsumgx = redsumgx + image[i - 1][j + 1].rgbtRed;
                redsumgy = redsumgy + image[i - 1][j + 1].rgbtRed;
                greensumgx = greensumgx + image[i - 1][j + 1].rgbtGreen;
                greensumgy = greensumgy + image[i - 1][j + 1].rgbtGreen;
                bluesumgx = bluesumgx + image[i - 1][j + 1].rgbtBlue;
                bluesumgy = bluesumgy + image[i - 1][j + 1].rgbtBlue;
            }
            if (j + 1 < width)
            {
                redsumgx = redsumgx + (2 * image[i][j + 1].rgbtRed);
                greensumgx = greensumgx + (2 * image[i][j + 1].rgbtGreen);
                bluesumgx = bluesumgx + (2 * image[i][j + 1].rgbtBlue);
            }
            if (i + 1 < height && j + 1 < width)
            {
                redsumgx = redsumgx + image[i + 1][j + 1].rgbtRed;
                redsumgy = redsumgy + image[i + 1][j + 1].rgbtRed;
                greensumgx = greensumgx + image[i + 1][j + 1].rgbtGreen;
                greensumgy = greensumgy + image[i + 1][j + 1].rgbtGreen;
                bluesumgx = bluesumgx + image[i + 1][j + 1].rgbtBlue;
                bluesumgy = bluesumgy + image[i + 1][j + 1].rgbtBlue;
            }
            if (i + 1 < height)
            {
                redsumgy = redsumgy + (2 * image[i + 1][j].rgbtRed);
                greensumgy = greensumgy + (2 * image[i + 1][j].rgbtGreen);
                bluesumgy = bluesumgy + (2 * image[i + 1][j].rgbtBlue);
            }
            if (j - 1 >= 0)
            {
                redsumgx = redsumgx - (2 * image[i][j - 1].rgbtRed);
                greensumgx = greensumgx - (2 * image[i][j - 1].rgbtGreen);
                bluesumgx = bluesumgx - (2 * image[i][j - 1].rgbtBlue);
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                redsumgx = redsumgx - image[i + 1][j - 1].rgbtRed;
                redsumgy = redsumgy + image[i + 1][j - 1].rgbtRed;
                greensumgx = greensumgx - image[i + 1][j - 1].rgbtGreen;
                greensumgy = greensumgy + image[i + 1][j - 1].rgbtGreen;
                bluesumgx = bluesumgx - image[i + 1][j - 1].rgbtBlue;
                bluesumgy = bluesumgy + image[i + 1][j - 1].rgbtBlue;
            }
            tempimage[i][j].rgbtRed = (round)((sqrt)((float)(redsumgx) * (float)(redsumgx)) + ((float)(redsumgy) * (float)(redsumgy)));
            if (tempimage[i][j].rgbtRed > 255)
            {
                tempimage[i][j].rgbtRed = 255;
            }
            tempimage[i][j].rgbtGreen = (round)((sqrt)((float)(greensumgx) * (float)(greensumgx)) + ((float)(greensumgy) * (float)(greensumgy)));
            if (tempimage[i][j].rgbtGreen > 255)
            {
                tempimage[i][j].rgbtGreen = 255;
            }
            tempimage[i][j].rgbtBlue = (round)((sqrt)((float)(bluesumgx) * (float)(bluesumgx)) + ((float)(bluesumgy) * (float)(bluesumgy)));
            if (tempimage[i][j].rgbtBlue > 255)
            {
                tempimage[i][j].rgbtBlue = 255;
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempimage[i][j];
        }
    }
    return;
}







