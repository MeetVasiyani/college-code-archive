/*Return the maximum of three floating-point numbers.*/
#include <stdio.h>

int main() {
  float a, b, c;
  printf("Enter three floating-point numbers: ");
  scanf("%f %f %f", &a, &b, &c);
  printf("The maximum of %.2f, %.2f, and %.2f is %.2f.\n", a, b, c, maximum(a, b, c));
  return 0;
}

float maximum(float x, float y, float z) {
  float max = x;
  if (y > max) {
    max = y;
  }
  if (z > max) {
    max = z;
  }
  return max;
}


