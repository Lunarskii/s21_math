#include "s21_test.h"

int main(void) {
  Suite *s = st_math();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);  // CK_ENV
  srunner_free(sr);

  return 0;
}

START_TEST(TEST_ABS) {
  int x = 5;
  ck_assert_int_eq(s21_abs(x), abs(x));
  x = -5;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(TEST_ACOS) {
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 0.000001);
  ck_assert_ldouble_nan(s21_acos(10));
  ck_assert_ldouble_nan(s21_acos(-10));
  ck_assert_ldouble_nan(s21_acos(__builtin_huge_vall()));
  ck_assert_ldouble_nan(s21_acos(-__builtin_huge_vall()));
  ck_assert_ldouble_eq_tol(s21_acos(-0.7), acos(-0.7), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(0.7), acos(0.7), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(-0.717268), acos(-0.717268), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(0.717268), acos(0.717268), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(-0.3026500846836411),
                           acos(-0.3026500846836411), 0.000001);
  ck_assert_ldouble_eq_tol(s21_acos(0.3026500846836411),
                           acos(0.3026500846836411), 0.000001);
  ck_assert_ldouble_nan(s21_acos(-(0.0 / 0.0)));
  ck_assert_ldouble_nan(s21_acos(0.0 / 0.0));
}
END_TEST

START_TEST(TEST_ASIN) {
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 0.000001);
  ck_assert_ldouble_nan(s21_asin(10));
  ck_assert_ldouble_nan(s21_asin(-10));
  ck_assert_ldouble_nan(s21_asin(__builtin_huge_vall()));
  ck_assert_ldouble_nan(s21_asin(-__builtin_huge_vall()));
  ck_assert_ldouble_eq_tol(s21_asin(-0.7), asin(-0.7), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(0.7), asin(0.7), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(-0.717268), asin(-0.717268), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(0.717268), asin(0.717268), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(-0.3026500846836411),
                           asin(-0.3026500846836411), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(0.3026500846836411),
                           asin(0.3026500846836411), 0.000001);
  ck_assert_ldouble_nan(s21_asin(-(0.0 / 0.0)));
  ck_assert_ldouble_nan(s21_asin(0.0 / 0.0));
}
END_TEST

START_TEST(TEST_ATAN) {
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(10), atan(10), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(-10), atan(-10), 0.000001);
  ck_assert_ldouble_eq(s21_atan(__builtin_huge_vall()),
                       atan(__builtin_huge_vall()));
  ck_assert_ldouble_eq(s21_atan(-__builtin_huge_vall()),
                       atan(-__builtin_huge_vall()));
  ck_assert_ldouble_eq_tol(s21_atan(-0.7), atan(-0.7), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(0.7), atan(0.7), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(-0.717268), atan(-0.717268), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(0.717268), atan(0.717268), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(-0.3026500846836411),
                           atan(-0.3026500846836411), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(0.3026500846836411),
                           atan(0.3026500846836411), 0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(2780809446.591906), atan(2780809446.591906),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_atan(-2780809446.591906),
                           atan(-2780809446.591906), 0.000001);
  ck_assert_ldouble_nan(s21_atan(-(0.0 / 0.0)));
  ck_assert_ldouble_nan(s21_atan(0.0 / 0.0));
}
END_TEST

START_TEST(TEST_CEIL) {
  ck_assert_ldouble_eq_tol(s21_ceil(2.4), ceil(2.4), 0.000001);
  ck_assert_ldouble_eq_tol(s21_ceil(-2.5e-10), ceil(-2.5e-10), 0.000001);
  ck_assert_ldouble_eq_tol(s21_ceil(10), ceil(10), 0.000001);
  ck_assert_ldouble_eq_tol(s21_ceil(38e-48), ceil(38e-48), 0.000001);
  ck_assert_ldouble_eq_tol(
      s21_ceil(2.128935190825870123598127935753890125097812378905),
      ceil(2.128935190825870123598127935753890125097812378905), 0.000001);
  ck_assert_ldouble_eq_tol(
      s21_ceil(-8923578.3258912378105218351203590812357891235),
      ceil(-8923578.3258912378105218351203590812357891235), 0.000001);
  ck_assert_ldouble_eq_tol(s21_ceil(-2.4), ceil(-2.4), 0.000001);
  ck_assert_ldouble_eq(s21_ceil(S21_INF), ceil(S21_INF));
  ck_assert_ldouble_eq(s21_ceil(-S21_INF), ceil(-S21_INF));
  ck_assert_ldouble_eq(s21_ceil(-0), ceil(-0));
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
  ck_assert_ldouble_eq(s21_ceil(1), ceil(1));
  ck_assert_ldouble_eq(s21_ceil(-1), ceil(-1));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
}
END_TEST

START_TEST(TEST_COS) {
  ck_assert_ldouble_eq_tol(s21_cos(1.0471975511965976), cos(1.0471975511965976),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_cos(4.570796326794897), cos(4.570796326794897),
                           0.000001);
  ck_assert_ldouble_nan(s21_cos(__builtin_huge_vall()));
  ck_assert_ldouble_nan(s21_cos(0.0 / 0.0));
  ck_assert_ldouble_nan(s21_cos(-__builtin_huge_vall()));
  ck_assert_ldouble_eq(s21_cos(0.0), cos(0.0));
}
END_TEST

START_TEST(TEST_EXP) {
  ck_assert_ldouble_eq_tol(
      s21_exp(-8923578.3258912378105218351203590812357891235),
      exp(-8923578.3258912378105218351203590812357891235), 0.000001);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 0.000001);
  ck_assert_ldouble_eq_tol(
      s21_exp(2.128935190825870123598127935753890125097812378905),
      exp(2.128935190825870123598127935753890125097812378905), 0.000001);
  ck_assert_ldouble_eq_tol(s21_exp(10), exp(10), 0.000001);
  ck_assert_ldouble_eq(s21_exp(__builtin_huge_vall()),
                       exp(__builtin_huge_vall()));
  ck_assert_ldouble_eq(s21_exp(-__builtin_huge_vall()),
                       exp(-__builtin_huge_vall()));
  ck_assert_ldouble_eq_tol(s21_exp(-348), exp(-348), 0.000001);
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_exp(0.5e-8), exp(0.5e-8), 0.000001);
  ck_assert_ldouble_nan(s21_exp(-(0.0 / 0.0)));
  ck_assert_ldouble_nan(s21_exp(0.0 / 0.0));
}
END_TEST

START_TEST(TEST_FABS) {
  ck_assert_ldouble_eq(s21_fabs(-1.0), fabs(-1.0));
  ck_assert_ldouble_eq(s21_fabs(-9382571298512.0), fabs(-9382571298512.0));
  ck_assert_ldouble_eq(s21_fabs(18923579812.0), fabs(18923579812.0));
  ck_assert_ldouble_eq(s21_fabs(__builtin_huge_vall()),
                       fabs((double)__builtin_huge_vall()));
  ck_assert_ldouble_eq(s21_fabs(-__builtin_huge_vall()),
                       fabs((double)-__builtin_huge_vall()));
  ck_assert_ldouble_eq(s21_fabs(-0.12877947986), fabs(-0.12877947986));
  ck_assert_ldouble_eq(s21_fabs(2.509), fabs(2.509));
  ck_assert_ldouble_eq(s21_fabs(-2.5e+10), fabs(-2.5e+10));
  ck_assert_ldouble_eq(s21_fabs(0.0), fabs(0.0));
  ck_assert_ldouble_eq(s21_fabs(38e-48), fabs(38e-48));
  ck_assert_ldouble_nan(s21_fabs(-(0.0 / 0.0)));
  ck_assert_ldouble_nan(s21_fabs(0.0 / 0.0));
}
END_TEST

START_TEST(TEST_FLOOR) {
  ck_assert_ldouble_eq_tol(
      s21_ceil(2.128935190825870123598127935753890125097812378905),
      ceil(2.128935190825870123598127935753890125097812378905), 0.000001);
  ck_assert_ldouble_eq_tol(
      s21_ceil(-8923578.3258912378105218351203590812357891235),
      ceil(-8923578.3258912378105218351203590812357891235), 0.000001);
  ck_assert_ldouble_eq_tol(s21_ceil(-2.5e-10), ceil(-2.5e-10), 0.000001);
  ck_assert_ldouble_eq(s21_floor(1.0), floor(1.0));
  ck_assert_ldouble_eq(s21_floor(125), floor(125));
  ck_assert_ldouble_eq(s21_floor(-125), floor(-125));
  ck_assert_ldouble_eq(s21_floor(47e16), floor(47e16));
  ck_assert_ldouble_eq(s21_floor((long long int)37e2),
                       floor((long long int)37e2));
  ck_assert_ldouble_eq(s21_floor(-47e16), floor(-47e16));
  ck_assert_ldouble_eq(s21_floor(-47e2), floor(-47e2));
  ck_assert_ldouble_eq(s21_floor(S21_INF), floor(S21_INF));
  ck_assert_ldouble_eq(s21_floor(-S21_INF), floor(-S21_INF));
  ck_assert_ldouble_eq(s21_floor(1.523), floor(1.523));
  ck_assert_ldouble_eq(s21_floor(-0.123), floor(-0.123));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
}
END_TEST

START_TEST(TEST_FMOD) {
  ck_assert_ldouble_eq_tol(s21_fmod(6.7, 2.0), fmod(6.7, 2.0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(-6.7, 2.0), fmod(-6.7, 2.0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(6.7, -2.0), fmod(6.7, -2.0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(-6.7, -2.0), fmod(-6.7, -2.0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(S21_EPS, 5.7), fmod(S21_EPS, 5.7),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(302, 15.1), fmod(302, 15.1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(5.6, S21_INF), fmod(5.6, S21_INF),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(5.6, -S21_INF), fmod(5.6, -S21_INF),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(-5.6, S21_INF), fmod(-5.6, S21_INF),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(-5.6, -S21_INF), fmod(-5.6, -S21_INF),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(6.1, S21_INF), fmod(6.1, S21_INF),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(6.1, -S21_INF), fmod(6.1, -S21_INF),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(-6.1, S21_INF), fmod(-6.1, S21_INF),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(0.0, 7.2), fmod(0.0, 7.2), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(2.328797, 0.000000001),
                           fmod(2.328797, 0.000000001), 0.000001);
  ck_assert_ldouble_eq_tol(s21_fmod(2.328797, -0.000000001),
                           fmod(2.328797, -0.000000001), 0.000001);
  ck_assert_ldouble_nan(s21_fmod(0.0, 0.0));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 5.4));
  ck_assert_ldouble_nan(s21_fmod(6.7, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, -S21_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 0.0));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, 0.0));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, -S21_INF));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, 5.6));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, -5.6));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 7.5));
}
END_TEST

START_TEST(TEST_LOG) {
  ck_assert_ldouble_eq_tol(s21_log(238e+10), log(238e+10), 0.000001);
  ck_assert_ldouble_eq_tol(
      s21_log(13895718152.265892357291086401928631203967123908671236081236),
      log(13895718152.265892357291086401928631203967123908671236081236),
      0.000001);
  ck_assert_ldouble_eq_tol(s21_log(100000), log(100000), 0.000001);
  ck_assert_ldouble_eq(s21_log(0), log(0));
  ck_assert_ldouble_eq(s21_log(1), log(1));
  ck_assert_ldouble_eq(s21_log(__builtin_huge_vall()),
                       log(__builtin_huge_vall()));
  ck_assert_ldouble_eq_tol(s21_log(89235798), log(89235798), 0.000001);
  ck_assert_ldouble_eq_tol(s21_log(238), log(238), 0.000001);
  ck_assert_ldouble_eq_tol(s21_log(845974589012), log(845974589012), 0.000001);
  ck_assert_ldouble_eq_tol(s21_log(245.3879235), log(245.3879235), 0.000001);
  ck_assert_ldouble_nan(s21_log(-(0.0 / 0.0)));
  ck_assert_ldouble_nan(s21_log(0.0 / 0.0));
  ck_assert_ldouble_nan(s21_log(-873954));
  ck_assert_ldouble_nan(s21_log(-__builtin_huge_vall()));
}
END_TEST

START_TEST(TEST_POW) {
  ck_assert_ldouble_eq(s21_pow(1, S21_NAN), pow(1, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(12, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(-12, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 1));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -1));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 1), pow(S21_INF, 1));
  ck_assert_ldouble_eq(s21_pow(S21_INF, -1), pow(S21_INF, -1));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 0), pow(S21_INF, 0));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 0), pow(-S21_INF, 0));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 0.1), pow(S21_INF, 0.1));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 0.1), pow(-S21_INF, 0.1));
  ck_assert_ldouble_eq(s21_pow(S21_INF, -0.1), pow(S21_INF, -0.1));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, -0.1), pow(-S21_INF, -0.1));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 12), pow(S21_INF, 12));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 12), pow(-S21_INF, 12));
  ck_assert_ldouble_eq(s21_pow(S21_INF, -1.1), pow(S21_INF, -1.1));
  ck_assert_ldouble_eq(s21_pow(S21_INF, -0.0000000000001),
                       pow(S21_INF, -0.0000000000001));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 0.0000000000001),
                       pow(S21_INF, 0.0000000000001));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, -1.1), pow(-S21_INF, -1.1));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, -0.0000000000001),
                       pow(-S21_INF, -0.0000000000001));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 0.0000000000001),
                       pow(-S21_INF, 0.0000000000001));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, -1), pow(-S21_INF, -1));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 1), pow(-S21_INF, 1));
  ck_assert_ldouble_eq(s21_pow(-1, S21_INF), pow(-1, S21_INF));
  ck_assert_ldouble_eq(s21_pow(-1, -S21_INF), pow(-1, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(-11.05, S21_INF), pow(-11.05, S21_INF));
  ck_assert_ldouble_eq(s21_pow(11.05, -S21_INF), pow(11.05, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(1, S21_INF), pow(1, S21_INF));
  ck_assert_ldouble_eq(s21_pow(1, -S21_INF), pow(1, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(0, S21_INF), pow(0, S21_INF));
  ck_assert_ldouble_eq(s21_pow(0, -S21_INF), pow(0, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(15, S21_INF), pow(15, S21_INF));
  ck_assert_ldouble_eq(s21_pow(-15, S21_INF), pow(-15, S21_INF));
  ck_assert_ldouble_eq(s21_pow(15, -S21_INF), pow(15, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(0.5, S21_INF), pow(0.5, S21_INF));
  ck_assert_ldouble_eq(s21_pow(0.5, -S21_INF), pow(0.5, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(-15, -S21_INF), pow(-15, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(15, 0), pow(15, 0));
  ck_assert_ldouble_nan(s21_pow(-0.12, 2.2));
  ck_assert_ldouble_eq_tol(s21_pow(0.12, 2.2), pow(0.12, 2.2), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_pow(15, 2.5), pow(15, 2.5), 0.0000001);
  ck_assert_ldouble_eq(s21_pow(S21_INF, S21_INF), pow(S21_INF, S21_INF));
  ck_assert_ldouble_eq(s21_pow(S21_INF, -S21_INF), pow(S21_INF, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, -S21_INF), pow(-S21_INF, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, S21_INF), pow(-S21_INF, S21_INF));
  ck_assert_ldouble_eq(s21_pow(1, S21_INF), pow(1, S21_INF));
  ck_assert_ldouble_eq(s21_pow(1, S21_NAN), pow(1, S21_NAN));
  ck_assert_ldouble_eq(s21_pow(1, -S21_INF), pow(1, -S21_INF));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 0), pow(S21_INF, 0));
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 0), pow(-S21_INF, 0));
  ck_assert_ldouble_eq(s21_pow(0, 0), pow(0, 0));
  ck_assert_ldouble_eq(s21_pow(0, 1), pow(0, 1));
  ck_assert_ldouble_eq(s21_pow(S21_NAN, 0), pow(S21_NAN, 0));
  ck_assert_ldouble_eq_tol(s21_pow(8239751.897124678591871412, 1e-3),
                           pow(8239751.897124678591871412, 1e-3), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 2), pow(-2, 2), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 3), pow(-2, 3), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -2), pow(-2, -2), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -3), pow(-2, -3), 0.000001);
  ck_assert_ldouble_nan(s21_pow(-35, 2.125));
}
END_TEST

START_TEST(TEST_SIN) {
  ck_assert_ldouble_eq_tol(s21_sin(0.5235987755982989), sin(0.5235987755982989),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(3.1415926535897932), sin(3.1415926535897932),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(-3.1415926535897932),
                           sin(-3.1415926535897932), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(1.5707963267948966), sin(1.5707963267948966),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(-1.5707963267948966),
                           sin(-1.5707963267948966), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sin(-4.7123889803846899),
                           sin(-4.7123889803846899), 0.000001);
  ck_assert_ldouble_nan(s21_sin(__builtin_huge_vall()));
  ck_assert_ldouble_nan(s21_sin(-__builtin_huge_vall()));
  ck_assert_ldouble_nan(s21_sin(0.0 / 0.0));
  ck_assert_ldouble_eq_tol(s21_sin(-0.0), sin(-0.0), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_sin(0.0), sin(0.0), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_sin(-0.05), sin(-0.05), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_sin(0.05), sin(0.05), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_sin(-13.05), sin(-13.05), 0.0000001);
  ck_assert_ldouble_eq_tol(s21_sin(13.05), sin(13.05), 0.0000001);
}
END_TEST

START_TEST(TEST_SQRT) {
  ck_assert_ldouble_eq_tol(s21_sqrt(4), sqrt(4), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sqrt(6), sqrt(6), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sqrt(400), sqrt(400), 0.000001);
  ck_assert_ldouble_eq(s21_sqrt(S21_INF), sqrt(S21_INF));
  ck_assert_ldouble_eq_tol(s21_sqrt(300), sqrt(300), 0.000001);
  ck_assert_ldouble_eq_tol(s21_sqrt(82937.189724), sqrt(82937.189724),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_sqrt(8217079354.12497821231),
                           sqrt(8217079354.12497821231), 0.000001);
  ck_assert_ldouble_nan(s21_sqrt(-1));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-S21_INF));
}
END_TEST

START_TEST(TEST_TAN) {
  ck_assert_ldouble_eq_tol(s21_tan(0.7853981633974483), tan(0.7853981633974483),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_tan(2.3561944901923449), tan(2.3561944901923449),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_tan(-2.3561944901923449),
                           tan(-2.3561944901923449), 0.000001);
  ck_assert_ldouble_eq_tol(s21_tan(1.5707963267948966), tan(1.5707963267948966),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_tan(-1.5707963267948966),
                           tan(-1.5707963267948966), 0.000001);
  ck_assert_ldouble_eq_tol(s21_tan(3.9269908169872415), tan(3.9269908169872415),
                           0.000001);
  ck_assert_ldouble_eq_tol(s21_tan(5.4977871437821382), tan(5.4977871437821382),
                           0.000001);
  ck_assert_ldouble_nan(s21_tan(__builtin_huge_vall()));
  ck_assert_ldouble_nan(s21_tan(0.0 / 0.0));
  ck_assert_ldouble_nan(s21_tan(-__builtin_huge_vall()));
  ck_assert_ldouble_eq(s21_tan(0.0), tan(0.0));
  ck_assert_ldouble_eq(s21_tan(-0.0), tan(-0.0));
}
END_TEST

Suite *st_math(void) {
  Suite *s = suite_create("st_math");
  TCase *tc = tcase_create("math_tc");

  tcase_add_test(tc, TEST_ABS);
  tcase_add_test(tc, TEST_ACOS);
  tcase_add_test(tc, TEST_ASIN);
  tcase_add_test(tc, TEST_ATAN);
  tcase_add_test(tc, TEST_CEIL);
  tcase_add_test(tc, TEST_COS);
  tcase_add_test(tc, TEST_EXP);
  tcase_add_test(tc, TEST_FABS);
  tcase_add_test(tc, TEST_FLOOR);
  tcase_add_test(tc, TEST_FMOD);
  tcase_add_test(tc, TEST_LOG);
  tcase_add_test(tc, TEST_POW);
  tcase_add_test(tc, TEST_SIN);
  tcase_add_test(tc, TEST_SQRT);
  tcase_add_test(tc, TEST_TAN);

  suite_add_tcase(s, tc);
  return s;
}
