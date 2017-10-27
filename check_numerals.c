#include <check.h>
#include <stdlib.h>

#include "numerals.h"

START_TEST(test_convert_I)
{
    ck_assert_int_eq(1, IntValueOf('I'));
 
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