#include "s21_smart_calc.h"

int s21_start_calc(char *src, double *result) {
  int res = 0;
  calc_t init_object;
  init_object.operation = '\0';
  init_object.priority = -1;
  init_object.value = 0;

  stack_calc_t *list = s21_create_node(init_object);

  res = s21_parse(src, &list);

  if (!res) {
    s21_pop(&list);  // удаляет мусорную фигню в начале
    s21_push_back(&list, init_object);
    s21_calculate(list, result);
  } else {
    s21_delete(&list);
  }
  return res;
}