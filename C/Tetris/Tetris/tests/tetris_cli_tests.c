#include "tetris_cli_tests.h"

int main() {
  SRunner *runner = srunner_create(tetris_suite());

  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  int number_run = srunner_ntests_run(runner);

  printf("\033[36mКоличество запущенных тестов: %d\033[0m\n", number_run);
  printf("\033[31mКоличество проваленных тестов: %d\033[0m\n", number_failed);
  srunner_free(runner);
  // FreeMemory();
  return (number_failed == 0) ? 0 : 1;
}