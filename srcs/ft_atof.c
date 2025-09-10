#include "../includes/libft.h"

float ft_atof(const char *nptr) {
  int sign;
  double res;
  double frac;
  double divisor;

  res = 0.0;
  frac = 0.0;
  divisor = 1.0;
  sign = 1;

  while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
    nptr++;

  if (*nptr == '-' || *nptr == '+')
    if (*(nptr++) == '-')
      sign = -sign;

  while (*nptr >= '0' && *nptr <= '9')
    res = res * 10.0 + (*(nptr++) - '0');

  if (*nptr == '.') {
    nptr++;
    while (*nptr >= '0' && *nptr <= '9') {
      frac = frac * 10.0 + (*(nptr++) - '0');
      divisor *= 10.0;
    }
  }

  res = (res + frac / divisor) * sign;
  if (res > FLT_MAX)
    return (FLT_MAX);
  if (res < -FLT_MAX)
    return (0);
  return res;
}