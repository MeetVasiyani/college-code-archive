/*In digital world colors are specified in RGB format, with values of R, G, and B varying on integer scale from 
0 to 255. Colors are mentioned in Cyan-Magenta-Yellow-Black (CMYK) format with values of C, M, Y and K 
varying on a real scale from 0.0 to 1.0. Convert RGB color to CMYK as per formula:
 - White=Max(red/255,green/255,blue/255) 
 - Cyan=(white - red/255)/white 
 - Magenta=(white - green/255)/white 
 - Yellow=(white - blue/255)/white 
 - Black=1 - white 
Note: if RGB values are all 0, then the CMY values are all 0 and the K value is 1. */
#include <stdio.h>

void main() {
    int red, green, blue;
    float cyan, magenta, yellow, black, white;

    printf("Enter the RGB values (0-255): ");
    scanf("%d %d %d", &red, &green, &blue);

    white = (float) (red > green && red > blue ? red : (green > blue ? green : blue)) / 255.0;

    cyan = (white - (float) red / 255.0) / white;
    magenta = (white - (float) green / 255.0) / white;
    yellow = (white - (float) blue / 255.0) / white;
    black = 1.0 - white;

    if (red == 0 && green == 0 && blue == 0) {
        cyan = magenta = yellow = 0.0;
        black = 1.0;
    }

    printf("CMYK values: Cyan = %.2f, Magenta = %.2f, Yellow = %.2f, Black = %.2f\n", cyan, magenta, yellow, black);

}