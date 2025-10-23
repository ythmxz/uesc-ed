#include <math.h>
#include <stdio.h>

int sum_digits(int n) {
  if (n < 10) {
    return n;
  }

  return (n % 10) + sum_digits(n / 10);
}

int main() {
  int n = 0;
  scanf("%d", &n);

  if (n < 0 || n > pow(10, 9)) {
    return 1;
  }

  printf("%d\n", sum_digits(n));

  return 0;
}
