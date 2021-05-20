#include <stdio.h>

typedef union
{
  struct {
    unsigned long long fractional: 23;
    unsigned exponent: 8;
    int sign: 1;
  } df;
  double f;
} du;

void print_bits(unsigned long long v, int width)
{
  char r[width+1];
  for(int i = 0; i < width; r[i++] = '0');
  r[width] = '\0';

  while(width--)
  {
    if(v & 1)
      r[width] = '1';
    v >>= 1;
  }

  printf(r);
}

void println_float_fields(double d)
{
  du u;
  u.d = d;
  printf("S: %d\t E: %03u (%03d) ", u.df.sign, u.df.exponent, u.df.exponent - 1023);
  print_bits(u.df.fractional, 23);
  printf(" <-----n");
}

int main(void)
{
  println_float_fields(0);
  println_float_fields(5);
  println_float_fields(-3);
  println_float_fields(3);
  return 0;
}
