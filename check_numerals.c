#include <check.h>
#include <stdlib.h>

#include "numerals.h"


// CONVERSION TESTS

START_TEST(test_convert_I)
{
    ck_assert_int_eq(1, IntValueOf('I'));
 
}
END_TEST

START_TEST(test_convert_V)
{
    ck_assert_int_eq(5, IntValueOf('V'));
 
}
END_TEST

START_TEST(test_convert_X)
{
    ck_assert_int_eq(10, IntValueOf('X'));
 
}
END_TEST

START_TEST(test_convert_L)
{
    ck_assert_int_eq(50, IntValueOf('L'));
 
}
END_TEST

START_TEST(test_convert_C)
{
    ck_assert_int_eq(100, IntValueOf('C'));
 
}
END_TEST

START_TEST(test_convert_D)
{
    ck_assert_int_eq(500, IntValueOf('D'));
 
}
END_TEST

START_TEST(test_convert_M)
{
    ck_assert_int_eq(1000, IntValueOf('M'));
 
}
END_TEST

START_TEST(test_compute_VII)
{
    ck_assert_int_eq(7, NumeralToInteger("VII"));
 
}
END_TEST

START_TEST(test_compute_XLIV)
{
    ck_assert_int_eq(44, NumeralToInteger("XLIV"));
 
}
END_TEST

START_TEST(test_compute_7)
{
    ck_assert_str_eq("VII", IntegerToNumeral(7));
 
}
END_TEST

Suite * numeral_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("numeral");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_convert_I);
    tcase_add_test(tc_core, test_convert_V);
    tcase_add_test(tc_core, test_convert_X);
    tcase_add_test(tc_core, test_convert_L);
    tcase_add_test(tc_core, test_convert_C);
    tcase_add_test(tc_core, test_convert_D);
    tcase_add_test(tc_core, test_convert_M);

    tcase_add_test(tc_core, test_compute_VII);
    tcase_add_test(tc_core, test_compute_XLIV);
    tcase_add_test(tc_core, test_compute_7);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = numeral_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}