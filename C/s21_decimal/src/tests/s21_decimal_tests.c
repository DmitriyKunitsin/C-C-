/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "s21_decimal_tests.check" instead.
 */

#include <check.h>

#line 1 "s21_decimal_tests.check"
#include "../s21_decimal.h"
#include "../s21_decimal_shared.h"

START_TEST(s21_greater_test)
{
#line 5
// normal_diff
ck_assert_int_eq(1, s21_is_greater(str_to_decimal("1"), str_to_decimal("0")));
ck_assert_int_eq(0, s21_is_greater(str_to_decimal("0"), str_to_decimal("1")));

ck_assert_int_eq(1,
                 s21_is_greater(str_to_decimal("3245"), str_to_decimal("223")));
ck_assert_int_eq(0,
                 s21_is_greater(str_to_decimal("223"), str_to_decimal("3245")));

// normal_equal
ck_assert_int_eq(0, s21_is_greater(str_to_decimal("5123"),
                                   str_to_decimal("5123")));

// edge_diff
ck_assert_int_eq(1, s21_is_greater(str_to_decimal("0.14264337593543950334"),
                                   str_to_decimal("-0.14264337593543950334")));
ck_assert_int_eq(0, s21_is_greater(str_to_decimal("-0.14264337593543950334"),
                                   str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(1, s21_is_greater(str_to_decimal("0.14264337593543950334"),
                                   str_to_decimal("0.114264337593543950334")));
ck_assert_int_eq(0, s21_is_greater(str_to_decimal("0.114264337593543950334"),
                                   str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(0, s21_is_greater(str_to_decimal("0.000000000000004"),
                                   str_to_decimal("0.00000000000004")));
ck_assert_int_eq(1, s21_is_greater(str_to_decimal("0.00000000000004"),
                                   str_to_decimal("0.000000000000004")));

ck_assert_int_eq(0, s21_is_greater(str_to_decimal("0.000000000000004"),
                                   str_to_decimal("0.0000000000000041")));
ck_assert_int_eq(1, s21_is_greater(str_to_decimal("0.0000000000000041"),
                                   str_to_decimal("0.000000000000004")));

ck_assert_int_eq(
    1, s21_is_greater(str_to_decimal("792281625.14264337593543950334"),
                      str_to_decimal("79228162.514264337593543950334")));
ck_assert_int_eq(
    0, s21_is_greater(str_to_decimal("79228162.514264337593543950334"),
                      str_to_decimal("792281625.14264337593543950334")));

ck_assert_int_eq(
    0, s21_is_greater(str_to_decimal("-792281625.14264337593543950334"),
                      str_to_decimal("792281625.14264337593543950334")));
ck_assert_int_eq(
    1, s21_is_greater(str_to_decimal("792281625.14264337593543950334"),
                      str_to_decimal("-792281625.14264337593543950334")));

// edge_equal
ck_assert_int_eq(0, s21_is_greater(str_to_decimal("0.00000000000004"),
                                   str_to_decimal("0.00000000000004")));

ck_assert_int_eq(0, s21_is_greater(str_to_decimal("0.14264337593543950334"),
                                   str_to_decimal("0.14264337593543950334")));

}
END_TEST

START_TEST(s21_greater_or_equal_test)
{
#line 61
// normal_diff
ck_assert_int_eq(1, s21_is_greater_or_equal(str_to_decimal("1"),
                                            str_to_decimal("0")));
ck_assert_int_eq(0, s21_is_greater_or_equal(str_to_decimal("0"),
                                            str_to_decimal("1")));

ck_assert_int_eq(1, s21_is_greater_or_equal(str_to_decimal("3245"),
                                            str_to_decimal("223")));
ck_assert_int_eq(0, s21_is_greater_or_equal(str_to_decimal("223"),
                                            str_to_decimal("3245")));

// normal_equal
ck_assert_int_eq(1, s21_is_greater_or_equal(str_to_decimal("5123"),
                                            str_to_decimal("5123")));

// edge_diff
ck_assert_int_eq(
    1, s21_is_greater_or_equal(str_to_decimal("0.14264337593543950334"),
                               str_to_decimal("-0.14264337593543950334")));
ck_assert_int_eq(
    0, s21_is_greater_or_equal(str_to_decimal("-0.14264337593543950334"),
                               str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(
    1, s21_is_greater_or_equal(str_to_decimal("0.14264337593543950334"),
                               str_to_decimal("0.114264337593543950334")));
ck_assert_int_eq(
    0, s21_is_greater_or_equal(str_to_decimal("0.114264337593543950334"),
                               str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(0,
                 s21_is_greater_or_equal(str_to_decimal("0.000000000000004"),
                                         str_to_decimal("0.00000000000004")));
ck_assert_int_eq(1,
                 s21_is_greater_or_equal(str_to_decimal("0.00000000000004"),
                                         str_to_decimal("0.000000000000004")));

ck_assert_int_eq(0,
                 s21_is_greater_or_equal(str_to_decimal("0.000000000000004"),
                                         str_to_decimal("0.0000000000000041")));
ck_assert_int_eq(1,
                 s21_is_greater_or_equal(str_to_decimal("0.0000000000000041"),
                                         str_to_decimal("0.000000000000004")));

ck_assert_int_eq(1, s21_is_greater_or_equal(
                        str_to_decimal("792281625.14264337593543950334"),
                        str_to_decimal("79228162.514264337593543950334")));
ck_assert_int_eq(0, s21_is_greater_or_equal(
                        str_to_decimal("79228162.514264337593543950334"),
                        str_to_decimal("792281625.14264337593543950334")));

ck_assert_int_eq(0, s21_is_greater_or_equal(
                        str_to_decimal("-792281625.14264337593543950334"),
                        str_to_decimal("792281625.14264337593543950334")));
ck_assert_int_eq(1, s21_is_greater_or_equal(
                        str_to_decimal("792281625.14264337593543950334"),
                        str_to_decimal("-792281625.14264337593543950334")));

// edge_equal
ck_assert_int_eq(1,
                 s21_is_greater_or_equal(str_to_decimal("0.00000000000004"),
                                         str_to_decimal("0.00000000000004")));

ck_assert_int_eq(
    1, s21_is_greater_or_equal(str_to_decimal("0.14264337593543950334"),
                               str_to_decimal("0.14264337593543950334")));

}
END_TEST

START_TEST(s21_less_test)
{
#line 129
// normal_diff
ck_assert_int_eq(0, s21_is_less(str_to_decimal("1"), str_to_decimal("0")));
ck_assert_int_eq(1, s21_is_less(str_to_decimal("0"), str_to_decimal("1")));

ck_assert_int_eq(0, s21_is_less(str_to_decimal("3245"), str_to_decimal("223")));
ck_assert_int_eq(1, s21_is_less(str_to_decimal("223"), str_to_decimal("3245")));

// normal_equal
ck_assert_int_eq(0,
                 s21_is_less(str_to_decimal("5123"), str_to_decimal("5123")));

// edge_diff
ck_assert_int_eq(0, s21_is_less(str_to_decimal("0.14264337593543950334"),
                                str_to_decimal("-0.14264337593543950334")));
ck_assert_int_eq(1, s21_is_less(str_to_decimal("-0.14264337593543950334"),
                                str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(0, s21_is_less(str_to_decimal("0.14264337593543950334"),
                                str_to_decimal("0.114264337593543950334")));
ck_assert_int_eq(1, s21_is_less(str_to_decimal("0.114264337593543950334"),
                                str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(1, s21_is_less(str_to_decimal("0.000000000000004"),
                                str_to_decimal("0.00000000000004")));
ck_assert_int_eq(0, s21_is_less(str_to_decimal("0.00000000000004"),
                                str_to_decimal("0.000000000000004")));

ck_assert_int_eq(1, s21_is_less(str_to_decimal("0.000000000000004"),
                                str_to_decimal("0.0000000000000041")));
ck_assert_int_eq(0, s21_is_less(str_to_decimal("0.0000000000000041"),
                                str_to_decimal("0.000000000000004")));

ck_assert_int_eq(0,
                 s21_is_less(str_to_decimal("792281625.14264337593543950334"),
                             str_to_decimal("79228162.514264337593543950334")));
ck_assert_int_eq(1,
                 s21_is_less(str_to_decimal("79228162.514264337593543950334"),
                             str_to_decimal("792281625.14264337593543950334")));

ck_assert_int_eq(1,
                 s21_is_less(str_to_decimal("-792281625.14264337593543950334"),
                             str_to_decimal("792281625.14264337593543950334")));
ck_assert_int_eq(
    0, s21_is_less(str_to_decimal("792281625.14264337593543950334"),
                   str_to_decimal("-792281625.14264337593543950334")));

// edge_equal
ck_assert_int_eq(0, s21_is_less(str_to_decimal("0.00000000000004"),
                                str_to_decimal("0.00000000000004")));

ck_assert_int_eq(0, s21_is_less(str_to_decimal("0.14264337593543950334"),
                                str_to_decimal("0.14264337593543950334")));

}
END_TEST

START_TEST(s21_less_or_equal_test)
{
#line 183
// normal_diff
ck_assert_int_eq(0, s21_is_less_or_equal(str_to_decimal("1"),
                                         str_to_decimal("0")));
ck_assert_int_eq(1, s21_is_less_or_equal(str_to_decimal("0"),
                                         str_to_decimal("1")));

ck_assert_int_eq(0, s21_is_less_or_equal(str_to_decimal("3245"),
                                         str_to_decimal("223")));
ck_assert_int_eq(1, s21_is_less_or_equal(str_to_decimal("223"),
                                         str_to_decimal("3245")));

// normal_equal
ck_assert_int_eq(1, s21_is_less_or_equal(str_to_decimal("5123"),
                                         str_to_decimal("5123")));

// edge_diff
ck_assert_int_eq(
    0, s21_is_less_or_equal(str_to_decimal("0.14264337593543950334"),
                            str_to_decimal("-0.14264337593543950334")));
ck_assert_int_eq(
    1, s21_is_less_or_equal(str_to_decimal("-0.14264337593543950334"),
                            str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(
    0, s21_is_less_or_equal(str_to_decimal("0.14264337593543950334"),
                            str_to_decimal("0.114264337593543950334")));
ck_assert_int_eq(
    1, s21_is_less_or_equal(str_to_decimal("0.114264337593543950334"),
                            str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(1, s21_is_less_or_equal(str_to_decimal("0.000000000000004"),
                                         str_to_decimal("0.00000000000004")));
ck_assert_int_eq(0, s21_is_less_or_equal(str_to_decimal("0.00000000000004"),
                                         str_to_decimal("0.000000000000004")));

ck_assert_int_eq(1, s21_is_less_or_equal(str_to_decimal("0.000000000000004"),
                                         str_to_decimal("0.0000000000000041")));
ck_assert_int_eq(0, s21_is_less_or_equal(str_to_decimal("0.0000000000000041"),
                                         str_to_decimal("0.000000000000004")));

ck_assert_int_eq(
    0, s21_is_less_or_equal(str_to_decimal("792281625.14264337593543950334"),
                            str_to_decimal("79228162.514264337593543950334")));
ck_assert_int_eq(
    1, s21_is_less_or_equal(str_to_decimal("79228162.514264337593543950334"),
                            str_to_decimal("792281625.14264337593543950334")));

ck_assert_int_eq(
    1, s21_is_less_or_equal(str_to_decimal("-792281625.14264337593543950334"),
                            str_to_decimal("792281625.14264337593543950334")));
ck_assert_int_eq(
    0, s21_is_less_or_equal(str_to_decimal("792281625.14264337593543950334"),
                            str_to_decimal("-792281625.14264337593543950334")));

// edge_equal
ck_assert_int_eq(1, s21_is_less_or_equal(str_to_decimal("0.00000000000004"),
                                         str_to_decimal("0.00000000000004")));

ck_assert_int_eq(
    1, s21_is_less_or_equal(str_to_decimal("0.14264337593543950334"),
                            str_to_decimal("0.14264337593543950334")));

}
END_TEST

START_TEST(s21_is_equal_test)
{
#line 246
// normal_diff
ck_assert_int_eq(0, s21_is_equal(str_to_decimal("1"), str_to_decimal("0")));
ck_assert_int_eq(0, s21_is_equal(str_to_decimal("0"), str_to_decimal("1")));

ck_assert_int_eq(0,
                 s21_is_equal(str_to_decimal("3245"), str_to_decimal("223")));
ck_assert_int_eq(0,
                 s21_is_equal(str_to_decimal("223"), str_to_decimal("3245")));

// normal_equal
ck_assert_int_eq(1,
                 s21_is_equal(str_to_decimal("5123"), str_to_decimal("5123")));

// edge_diff
ck_assert_int_eq(0, s21_is_equal(str_to_decimal("0.14264337593543950334"),
                                 str_to_decimal("-0.14264337593543950334")));
ck_assert_int_eq(0, s21_is_equal(str_to_decimal("-0.14264337593543950334"),
                                 str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(0, s21_is_equal(str_to_decimal("0.14264337593543950334"),
                                 str_to_decimal("0.114264337593543950334")));
ck_assert_int_eq(0, s21_is_equal(str_to_decimal("0.114264337593543950334"),
                                 str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(0, s21_is_equal(str_to_decimal("0.000000000000004"),
                                 str_to_decimal("0.00000000000004")));
ck_assert_int_eq(0, s21_is_equal(str_to_decimal("0.00000000000004"),
                                 str_to_decimal("0.000000000000004")));

ck_assert_int_eq(0, s21_is_equal(str_to_decimal("0.000000000000004"),
                                 str_to_decimal("0.0000000000000041")));
ck_assert_int_eq(0, s21_is_equal(str_to_decimal("0.0000000000000041"),
                                 str_to_decimal("0.000000000000004")));

ck_assert_int_eq(
    0, s21_is_equal(str_to_decimal("792281625.14264337593543950334"),
                    str_to_decimal("79228162.514264337593543950334")));
ck_assert_int_eq(
    0, s21_is_equal(str_to_decimal("79228162.514264337593543950334"),
                    str_to_decimal("792281625.14264337593543950334")));

ck_assert_int_eq(
    0, s21_is_equal(str_to_decimal("-792281625.14264337593543950334"),
                    str_to_decimal("792281625.14264337593543950334")));
ck_assert_int_eq(
    0, s21_is_equal(str_to_decimal("792281625.14264337593543950334"),
                    str_to_decimal("-792281625.14264337593543950334")));

// edge_equal
ck_assert_int_eq(1, s21_is_equal(str_to_decimal("0.00000000000004"),
                                 str_to_decimal("0.00000000000004")));

ck_assert_int_eq(1, s21_is_equal(str_to_decimal("0.14264337593543950334"),
                                 str_to_decimal("0.14264337593543950334")));

}
END_TEST

START_TEST(s21_is_not_equal_test)
{
#line 302
// normal_diff
ck_assert_int_eq(1, s21_is_not_equal(str_to_decimal("1"), str_to_decimal("0")));
ck_assert_int_eq(1, s21_is_not_equal(str_to_decimal("0"), str_to_decimal("1")));

ck_assert_int_eq(1, s21_is_not_equal(str_to_decimal("3245"),
                                     str_to_decimal("223")));
ck_assert_int_eq(1, s21_is_not_equal(str_to_decimal("223"),
                                     str_to_decimal("3245")));

// normal_equal
ck_assert_int_eq(0, s21_is_not_equal(str_to_decimal("5123"),
                                     str_to_decimal("5123")));

// edge_diff
ck_assert_int_eq(1,
                 s21_is_not_equal(str_to_decimal("0.14264337593543950334"),
                                  str_to_decimal("-0.14264337593543950334")));
ck_assert_int_eq(1, s21_is_not_equal(str_to_decimal("-0.14264337593543950334"),
                                     str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(1,
                 s21_is_not_equal(str_to_decimal("0.14264337593543950334"),
                                  str_to_decimal("0.114264337593543950334")));
ck_assert_int_eq(1, s21_is_not_equal(str_to_decimal("0.114264337593543950334"),
                                     str_to_decimal("0.14264337593543950334")));

ck_assert_int_eq(1, s21_is_not_equal(str_to_decimal("0.000000000000004"),
                                     str_to_decimal("0.00000000000004")));
ck_assert_int_eq(1, s21_is_not_equal(str_to_decimal("0.00000000000004"),
                                     str_to_decimal("0.000000000000004")));

ck_assert_int_eq(1, s21_is_not_equal(str_to_decimal("0.000000000000004"),
                                     str_to_decimal("0.0000000000000041")));
ck_assert_int_eq(1, s21_is_not_equal(str_to_decimal("0.0000000000000041"),
                                     str_to_decimal("0.000000000000004")));

ck_assert_int_eq(
    1, s21_is_not_equal(str_to_decimal("792281625.14264337593543950334"),
                        str_to_decimal("79228162.514264337593543950334")));
ck_assert_int_eq(
    1, s21_is_not_equal(str_to_decimal("79228162.514264337593543950334"),
                        str_to_decimal("792281625.14264337593543950334")));

ck_assert_int_eq(
    1, s21_is_not_equal(str_to_decimal("-792281625.14264337593543950334"),
                        str_to_decimal("792281625.14264337593543950334")));
ck_assert_int_eq(
    1, s21_is_not_equal(str_to_decimal("792281625.14264337593543950334"),
                        str_to_decimal("-792281625.14264337593543950334")));

// edge_equal
ck_assert_int_eq(0, s21_is_not_equal(str_to_decimal("0.00000000000004"),
                                     str_to_decimal("0.00000000000004")));

ck_assert_int_eq(0, s21_is_not_equal(str_to_decimal("0.14264337593543950334"),
                                     str_to_decimal("0.14264337593543950334")));

}
END_TEST

START_TEST(s21_add_test)
{
#line 360
s21_decimal a = str_to_decimal("-12321321"), b = str_to_decimal("-345"), res;
s21_add(a, b, &res);
char str[100];
decimal_to_str(res, str);
ck_assert_str_eq(str, "-12321666");

a = str_to_decimal("79228162514264337593543950335"), b = str_to_decimal("1");
ck_assert_int_eq(1, s21_add(a, b, &res));
a = str_to_decimal("-79228162514264337593543950335"), b = str_to_decimal("-1");
ck_assert_int_eq(2, s21_add(a, b, &res));
a = str_to_decimal("-79228162514264337593543950335"), b = str_to_decimal("1");
ck_assert_int_eq(0, s21_add(a, b, &res));

a = str_to_decimal("-79228162514264337593543950335"),
    b = str_to_decimal("879878978898787888900");
ck_assert_int_eq(0, s21_add(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq(str, "-79228161634385358694756061435");

a = str_to_decimal("79228162514264337593543950334"), b = str_to_decimal("0.6");
s21_add(a, b, &res);
decimal_to_str(res, str);
ck_assert_str_eq(str, "79228162514264337593543950335");

a = str_to_decimal("79228162514264337593543950335"), b = str_to_decimal("-0.6");
s21_add(a, b, &res);
decimal_to_str(res, str);
ck_assert_str_eq(str, "79228162514264337593543950334");

a = str_to_decimal("-0.6"), b = str_to_decimal("79228162514264337593543950335");
s21_add(a, b, &res);
decimal_to_str(res, str);
ck_assert_str_eq(str, "79228162514264337593543950334");

a = str_to_decimal("0.6"), b = str_to_decimal("-79228162514264337593543950335");
s21_add(a, b, &res);
decimal_to_str(res, str);
ck_assert_str_eq(str, "-79228162514264337593543950334");

a = str_to_decimal("0.6"), b = str_to_decimal("0");
s21_add(a, b, &res);
decimal_to_str(res, str);
ck_assert_str_eq(str, "0.6");

}
END_TEST

START_TEST(s21_sub_test)
{
#line 405
s21_decimal a = str_to_decimal("-12321321"), b = str_to_decimal("-345"), res;
s21_sub(a, b, &res);

char str[100];
decimal_to_str(res, str);
ck_assert_str_eq(str, "-12320976");

a = str_to_decimal("79228162514264337593543950335"), b = str_to_decimal("-1");
ck_assert_int_eq(1, s21_sub(a, b, &res));

a = str_to_decimal("-79228162514264337593543950335"), b = str_to_decimal("1");
ck_assert_int_eq(2, s21_sub(a, b, &res));

a = str_to_decimal("-79228162514264337593543950335"), b = str_to_decimal("-1");
ck_assert_int_eq(0, s21_sub(a, b, &res));

a = str_to_decimal("79228162514264337593543950335"),
    b = str_to_decimal("879878978898787888900");
ck_assert_int_eq(0, s21_sub(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq(str, "79228161634385358694756061435");

a = str_to_decimal("79228162514264337593543950334"), b = str_to_decimal("0.6");
ck_assert_int_eq(0, s21_sub(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq(str, "79228162514264337593543950333");

a = str_to_decimal("792281625142643375.93543950335"),
    b = str_to_decimal("-0.6");
ck_assert_int_eq(0, s21_sub(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq(str, "792281625142643376.5354395034");

a = str_to_decimal("79228162514264337593543950335"),
    b = str_to_decimal("0.50000000000000000000000000001");
ck_assert_int_eq(0, s21_sub(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq(str, "79228162514264337593543950334");

a = str_to_decimal("79228162514264337593543950335"),
    b = str_to_decimal("0.499999999999999999");
ck_assert_int_eq(0, s21_sub(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq(str, "79228162514264337593543950335");

a = str_to_decimal("792281625142643375.93543950335"),
    b = str_to_decimal("-500");
ck_assert_int_eq(0, s21_sub(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq(str, "792281625142643875.9354395034");

a = str_to_decimal("-792281625142643375.93543950335"), b = str_to_decimal("-2");
ck_assert_int_eq(0, s21_sub(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("-792281625142643373.93543950335", str);

a = str_to_decimal("2"), b = str_to_decimal("792281625142643375.93543950335");
ck_assert_int_eq(0, s21_sub(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("-792281625142643373.93543950335", str);

a = str_to_decimal("-100000000000"),
    b = str_to_decimal("792281625142643375.93543950335");
ck_assert_int_eq(0, s21_sub(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("-792281725142643375.9354395034", str);

}
END_TEST

START_TEST(s21_mul_test)
{
#line 473

char str[100];

s21_decimal a = str_to_decimal("-12321321"), b = str_to_decimal("-345"), res;
ck_assert_int_eq(0, s21_mul(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("4250855745", str);

a = str_to_decimal("12321321"), b = str_to_decimal("-345");
ck_assert_int_eq(0, s21_mul(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("-4250855745", str);

a = str_to_decimal("12321321"),
    b = str_to_decimal("-5935439503352131232131215");
ck_assert_int_eq(2, s21_mul(a, b, &res));

a = str_to_decimal("-12321321"),
    b = str_to_decimal("-5935439503352131232131215");
ck_assert_int_eq(1, s21_mul(a, b, &res));
decimal_to_str(res, str);

a = str_to_decimal("-12321321"),
    b = str_to_decimal("-5935439503352131232131215");
ck_assert_int_eq(1, s21_mul(a, b, &res));
decimal_to_str(res, str);

a = str_to_decimal("-12321321"), b = str_to_decimal("0");
ck_assert_int_eq(0, s21_mul(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("-0", str);

a = str_to_decimal("-123213.21"), b = str_to_decimal("100");
ck_assert_int_eq(0, s21_mul(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("-12321321", str);

}
END_TEST

START_TEST(s21_div_test)
{
#line 511

char str[100];

s21_decimal a = str_to_decimal("10"), b = str_to_decimal("3"), res;
s21_div(a, b, &res);

ck_assert_int_eq(0, s21_div(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("3.3333333333333333333333333333", str);

a = str_to_decimal("-12321321"), b = str_to_decimal("-59354");
ck_assert_int_eq(0, s21_div(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("207.59040671226876031943929642", str);

a = str_to_decimal("-123213.21"), b = str_to_decimal("-59354");
ck_assert_int_eq(0, s21_div(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("2.0759040671226876031943929642", str);

a = str_to_decimal("-1232132.1"), b = str_to_decimal("-5935.4");
ck_assert_int_eq(0, s21_div(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("207.59040671226876031943929642", str);

a = str_to_decimal("-123213.21"), b = str_to_decimal("-59.354");
ck_assert_int_eq(0, s21_div(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("2075.9040671226876031943929642", str);

a = str_to_decimal("-12321321"), b = str_to_decimal("100000000");
ck_assert_int_eq(0, s21_div(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("-0.12321321", str);

a = str_to_decimal("-12321.321"), b = str_to_decimal("12.05");
ck_assert_int_eq(0, s21_div(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("-1022.5162655601659751037344398", str);

a = str_to_decimal("-1"), b = str_to_decimal("10000000000000000000000000000");
ck_assert_int_eq(0, s21_div(a, b, &res));
decimal_to_str(res, str);
ck_assert_str_eq("-0.0000000000000000000000000001", str);

a = str_to_decimal("-1"), b = str_to_decimal("0");
ck_assert_int_eq(3, s21_div(a, b, &res));

a = str_to_decimal("-12"), b = str_to_decimal("0.0000000000000000000000000001");
ck_assert_int_eq(2, s21_div(a, b, &res));

a = str_to_decimal("12"), b = str_to_decimal("0.0000000000000000000000000001");
ck_assert_int_eq(1, s21_div(a, b, &res));

}
END_TEST

START_TEST(s21_from_int_to_decimal_test)
{
#line 566
int retval;
s21_decimal res;

int num = 1232132;
retval = s21_from_int_to_decimal(num, &res);
ck_assert_int_eq(retval, 0);
s21_from_decimal_to_int(res, &retval);
ck_assert_int_eq(num, retval);

num = -1232132;
retval = s21_from_int_to_decimal(num, &res);
ck_assert_int_eq(retval, 0);
s21_from_decimal_to_int(res, &retval);
ck_assert_int_eq(num, retval);

num = INT_MAX;
retval = s21_from_int_to_decimal(num, &res);
ck_assert_int_eq(retval, 0);
s21_from_decimal_to_int(res, &retval);
ck_assert_int_eq(num, retval);

num = INT_MIN;
retval = s21_from_int_to_decimal(num, &res);
ck_assert_int_eq(retval, 0);
ck_assert_int_eq(0, s21_from_decimal_to_int(res, &retval));
ck_assert_int_eq(num, retval);

}
END_TEST

START_TEST(s21_from_float_to_decimal_test)
{
#line 594
int retval;
s21_decimal res;
char str[100];

float num = 123213.2;
retval = s21_from_float_to_decimal(num, &res);
ck_assert_int_eq(retval, 0);
decimal_to_str(res, str);
ck_assert_str_eq("123213.2", str);

num = 123213200;
retval = s21_from_float_to_decimal(num, &res);
ck_assert_int_eq(retval, 0);
decimal_to_str(res, str);
ck_assert_str_eq("123213200", str);

num = 0.123213200;
retval = s21_from_float_to_decimal(num, &res);
ck_assert_int_eq(retval, 0);
decimal_to_str(res, str);
ck_assert_str_eq("0.1232132", str);

num = 1.0 / 0.0;
retval = s21_from_float_to_decimal(num, &res);
ck_assert_int_eq(retval, 1);

num = -1.0 / 0.0;
retval = s21_from_float_to_decimal(num, &res);
ck_assert_int_eq(retval, 1);

num = 0.0 / 0.0;
retval = s21_from_float_to_decimal(num, &res);
ck_assert_int_eq(retval, 1);

num = 5 * 1e-29;
retval = s21_from_float_to_decimal(num, &res);
ck_assert_int_eq(retval, 1);

num = 1e-28 / 2;
retval = s21_from_float_to_decimal(num, &res);
ck_assert_int_eq(retval, 1);

num = -1e-28 / 2;
retval = s21_from_float_to_decimal(num, &res);
ck_assert_int_eq(retval, 1);

}
END_TEST

START_TEST(s21_from_decimal_to_float_test)
{
#line 641
int retval;
s21_decimal res;
// char str[100];
float num;
float eps = 1e-5;

float sample = -12.2;
res = str_to_decimal("-12.2");
retval = s21_from_decimal_to_float(res, &num);
ck_assert_int_eq(0, retval);
if (!(sample - eps < num && num < sample + eps)) ck_assert_int_eq(0, 1);

sample = -100;
res = str_to_decimal("-100");
retval = s21_from_decimal_to_float(res, &num);
ck_assert_int_eq(0, retval);
if (!(sample - eps < num && num < sample + eps)) ck_assert_int_eq(0, 1);

eps = 1e-10;
sample = 0.000000001;
res = str_to_decimal("0.000000001");
retval = s21_from_decimal_to_float(res, &num);
ck_assert_int_eq(0, retval);
if (!(sample - eps < num && num < sample + eps)) ck_assert_int_eq(0, 1);

}
END_TEST

START_TEST(s21_from_decimal_to_int_test)
{
#line 667
int retval;
s21_decimal res;
int num;

res = str_to_decimal("132");
retval = s21_from_decimal_to_int(res, &num);
ck_assert_int_eq(retval, 0);
ck_assert_int_eq(num, 132);

res = str_to_decimal("-132");
retval = s21_from_decimal_to_int(res, &num);
ck_assert_int_eq(retval, 0);
ck_assert_int_eq(num, -132);

res = str_to_decimal("-123123123123");
retval = s21_from_decimal_to_int(res, &num);
ck_assert_int_eq(retval, 1);

res = str_to_decimal("123123123123");
retval = s21_from_decimal_to_int(res, &num);
ck_assert_int_eq(retval, 1);

}
END_TEST

START_TEST(s21_truncate_test)
{
#line 690
s21_decimal val1, res;
char str[100];

val1 = str_to_decimal("12321.1232131");
s21_truncate(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("12321", str);

val1 = str_to_decimal("0.1232131");
s21_truncate(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("0", str);

val1 = str_to_decimal("0");
s21_truncate(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("0", str);

val1 = str_to_decimal("123213");
s21_truncate(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("123213", str);

}
END_TEST

START_TEST(s21_round_test)
{
#line 714
s21_decimal val1, res;
char str[100];

val1 = str_to_decimal("12321.1232131");
s21_round(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("12321", str);

val1 = str_to_decimal("0.1232131");
s21_round(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("0", str);

val1 = str_to_decimal("0.5232131");
s21_round(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("1", str);

val1 = str_to_decimal("0");
s21_round(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("0", str);

val1 = str_to_decimal("-1");
s21_round(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("-1", str);

val1 = str_to_decimal("-1.5");
s21_round(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("-2", str);

}
END_TEST

START_TEST(s21_floor_test)
{
#line 748
s21_decimal val1, res;
char str[100];

val1 = str_to_decimal("12321.1232131");
s21_floor(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("12321", str);

val1 = str_to_decimal("0.99999");
s21_floor(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("0", str);

val1 = str_to_decimal("0");
s21_floor(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("0", str);

val1 = str_to_decimal("1");
s21_floor(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("1", str);

val1 = str_to_decimal("-1.00000001");
s21_floor(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("-2", str);

val1 = str_to_decimal("-1.5");
s21_floor(val1, &res);
decimal_to_str(res, str);
ck_assert_str_eq("-2", str);

}
END_TEST

START_TEST(s21_negate_test)
{
#line 782
s21_decimal res;
char str[100];

s21_negate(str_to_decimal("-12321.121"), &res);
decimal_to_str(res, str);
ck_assert_str_eq("12321.121", str);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, s21_greater_test);
    tcase_add_test(tc1_1, s21_greater_or_equal_test);
    tcase_add_test(tc1_1, s21_less_test);
    tcase_add_test(tc1_1, s21_less_or_equal_test);
    tcase_add_test(tc1_1, s21_is_equal_test);
    tcase_add_test(tc1_1, s21_is_not_equal_test);
    tcase_add_test(tc1_1, s21_add_test);
    tcase_add_test(tc1_1, s21_sub_test);
    tcase_add_test(tc1_1, s21_mul_test);
    tcase_add_test(tc1_1, s21_div_test);
    tcase_add_test(tc1_1, s21_from_int_to_decimal_test);
    tcase_add_test(tc1_1, s21_from_float_to_decimal_test);
    tcase_add_test(tc1_1, s21_from_decimal_to_float_test);
    tcase_add_test(tc1_1, s21_from_decimal_to_int_test);
    tcase_add_test(tc1_1, s21_truncate_test);
    tcase_add_test(tc1_1, s21_round_test);
    tcase_add_test(tc1_1, s21_floor_test);
    tcase_add_test(tc1_1, s21_negate_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
