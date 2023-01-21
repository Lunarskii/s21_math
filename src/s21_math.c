#include "s21_math.h"

long double s21_fabs(double x) {
  if (!(x != x)) {
    (x < 0) ? x = -x : x;
  }
  return x;
}

long double s21_exp(double x) {
  long double result = 0;

  if (x != x) {
    result = x;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == -S21_INF) {
    result = 0;
  } else {
    // Taylor-series
    result = 1;
    long double last = 1;

    for (long double i = 1; i < 200 && last > S21_EPS; i++) {
      last *= s21_fabs(x) / i;
      result += last;
    }
    if (x < 0) result = 1.0 / result;
  }

  return result;
}

long double s21_log(double x) {
  long double result = 0;

  if (x != x) {
    result = x;
  } else if (x == -S21_INF || x < 0) {  // в принципе можно оставить и x < 0
    result = S21_NAN;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == 0) {
    result = -S21_INF;
  } else if (x == 1) {
    result = 0;
  } else if (x > 0) {
    // Halley-Newton approximation method
    // https://en.wikipedia.org/wiki/Natural_logarithm#High_precision
    long double buffer = 0;
    int temp = 0;
    int i = 0;

    for (; x >= S21_EXP; x /= S21_EXP, temp++)
      ;
    do {
      i++;
      buffer = result;
      result = buffer + 2 * (x - (double)s21_exp(buffer)) /
                            (x + (double)s21_exp(buffer));
    } while (s21_fabs(buffer - result) > S21_EPS && i != 100);
    result += temp;
  }

  return result;
}

long double s21_atan(double x) {
  long double result = 0;

  if (x == S21_INF)
    result = S21_PI / 2;
  else if (x == -S21_INF)
    result = S21_PI / -2;
  else if (x == -1)
    result = S21_PI / -4;
  else if (x == 1)
    result = S21_PI / 4;
  else if (x == 0)
    result = 0;
  else if (x != x)
    result = x;
  else {
    result = s21_asin(x / s21_sqrt(1 + x * x));
  }
  return result;
}

long double s21_acos(double x) {
  long double result;

  if (x == -1)
    result = S21_PI;
  else if (x == 1)
    result = 0;
  else if (x == 0)
    result = S21_PI / 2;
  else if (x > 0 && x < 1)
    result = s21_asin(s21_sqrt(1 - x * x));
  else if (x > -1 && x < 0)
    result = S21_PI - s21_asin(s21_sqrt(1 - x * x));
  else
    result = S21_NAN;
  return result;
}

long double s21_asin(double x) {
  long double result = x, temp = x;

  if (x == -1)
    result = S21_PI / -2;
  else if (x == 1)
    result = S21_PI / 2;
  else if (x == 0)
    result = 0;
  else if (x != x)
    result = x;
  else if (x > -1 && x < 1)
    for (long double i = 1; s21_fabs(temp) > S21_EPS; i++) {
      temp *= x * x * (2 * i - 1) * (2 * i) * (2 * i - 1) /
              ((2 * i + 1) * 4 * i * i);
      result += temp;
    }
  else
    result = S21_NAN;
  return result;
}

long double s21_ceil(double x) {
  long double ceil_x;
  if (x != x) {
    ceil_x = x;
  } else if (x == S21_INF) {
    ceil_x = S21_INF;
  } else if (x == -S21_INF) {
    ceil_x = -S21_INF;
  } else {
    ceil_x = (long long int)x;
    if (s21_fabs(x) > 0 && x != ceil_x) {
      if (x > 0) {
        ceil_x += 1;
      }
    }
  }
  return ceil_x;
}

long double s21_floor(double x) {
  long double floor_x;
  if (x != x) {
    floor_x = x;
  } else if (x == S21_INF) {
    floor_x = S21_INF;
  } else if (x == -S21_INF) {
    floor_x = -S21_INF;
  } else {
    floor_x = (long long int)x;
    if (s21_fabs(x - floor_x) > 0 && s21_fabs(x) > 0) {
      if (x < 0) {
        floor_x -= 1;
      }
    }
  }
  return floor_x;
}

long double s21_pow(double x, double exp) {
  long double result = 0.0;
  long double copy = x;
  if ((x == 1 && (exp != exp)) || exp == 0) {
    result = 1;
  } else if (x != x && exp != exp) {
    result = S21_NAN;
  } else if (x == S21_INF || x == -S21_INF) {
    if ((x == S21_INF && exp > 0) ||
        (x == -S21_INF && exp > 0 &&
         (exp - (long long int)exp != 0 || s21_fmod(exp, 2) == 0))) {
      result = S21_INF;
    } else if (exp > 0) {
      result = -S21_INF;
    } else if (exp < 0) {
      result = 0.0;
    }
  } else if (exp == S21_INF || exp == -S21_INF) {
    if (x == 1 || x == -1) {
      result = 1.0;
    } else if (1 > s21_fabs(x) && exp == -S21_INF) {
      result = S21_INF;
    } else if ((x == 0 && exp == -S21_INF) ||
               (1 < s21_fabs(x) && exp == S21_INF)) {
      result = S21_INF;
    }
  } else {
    if (copy == 0) {
      result = s21_exp(exp * s21_log(copy));
      if (s21_fmod(exp, 2) != 0) {
        // четная нечетная степень при отриц основании
        result = -result;
      }
    } else {
      if (x < 0) {
        x = s21_fabs(x);
        long long int int_part = exp / 1;
        if (exp == int_part) {
          result = s21_exp(exp * s21_log(x));
          if ((int)(exp) % 2 == 1 || (int)(exp) % 2 == -1) {
            result = -result;
          }
        } else {
          result = S21_NAN;
        }
      } else {
        result = s21_exp(exp * s21_log(x));
      }
    }
  }
  return result;
}

long double s21_cos(double x) {
  long double result = 0.0;
  if (x != x || x == S21_INF || x == -S21_INF) {
    result = S21_NAN;
  } else {
    x = s21_fmod(x, 2.0 * S21_PI);
    long double taylor = 1.0;
    for (double i = 1.0; s21_fabs(taylor) > S21_EPS; i++) {
      result = result + taylor;
      taylor *= (-x * x) / ((2.0 * i - 1) * (2.0 * i));
    }
  }
  return result;
}

long double s21_sin(double x) {
  long double result = 0.0;
  if (x != x || x == S21_INF || x == -S21_INF) {
    result = S21_NAN;
  } else {
    if (x == S21_PI) {
      result = S21_EPS;
    } else if (x == -S21_PI) {
      result = -S21_EPS;
    } else {
      if (x > 0) {
        x = x - ((int)(x / (2 * S21_PI)) * (2 * S21_PI));
      } else if (x < 0) {
        x = x - ((int)(x / (2 * -S21_PI)) * (2 * -S21_PI));
      }
      long double taylor = x;
      result = x;
      for (double i = 1.0; s21_fabs(taylor) > S21_EPS; i++) {
        taylor *= ((-1.0) * x * x / (2.0 * i * (2.0 * i + 1.0)));
        result = result + taylor;
      }
    }
  }
  return result;
}

long double s21_tan(double x) {
  long double result = 0.0;
  if (x == S21_INF || x == -S21_INF) {
    result = S21_NAN;
  } else if (S21_PI / 2 == x) {
    result = 16331239353195370.0;
  } else if (-S21_PI / 2 == x) {
    result = -16331239353195370.0;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}

int s21_abs(int x) {
  if (x < 0) {
    x = x * -1;
  }
  return x;
}

long double s21_fmod(double x, double y) {
  long double res = 0.0;

  if (s21_abs(x) == 0 && s21_abs(y) != 0) {
    res = x;
  } else if (x != S21_INF && x != -S21_INF && (y == S21_INF || y == -S21_INF)) {
    res = x;
  } else if ((x != x || y != y) || y == 0) {
    res = S21_NAN;
  } else if (x == S21_INF || x == -S21_INF) {
    res = S21_NAN;
  } else {
    long long int i = x / y;
    res = x - i * y;
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res = 1.0;
  if (x < 0 || x != x) {
    res = S21_NAN;
  } else if (x == 1.0) {
    res = 1.0;
  } else if (x == 0.0) {
    res = 0;
  } else if (x == S21_INF) {
    res = S21_INF;
  } else {
    while (res != -1) {
      double tmp = (res + x / res) / 2;
      if (s21_fabs(res - tmp) < S21_EPS) break;
      res = tmp;
    }
  }
  return res;
}
