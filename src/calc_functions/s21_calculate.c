#include "s21_smart_calc.h"

calc_t s21_intermediate_calculations_for_2(stack_calc_t *output,
                                           stack_calc_t *operations) {
  calc_t result;
  result.operation = '\0';
  result.priority = 0;
  result.value = 0;
  if (operations->object.operation == '+') {
    result.value = output->next->object.value + output->object.value;
  } else if (operations->object.operation == '-') {
    result.value = output->next->object.value - output->object.value;
  } else if (operations->object.operation == '/') {
    result.value = output->next->object.value / output->object.value;
  } else if (operations->object.operation == '*') {
    result.value = output->next->object.value * output->object.value;
  } else if (operations->object.operation == '%') {
    result.value = fmod(output->next->object.value, output->object.value);
  } else if (operations->object.operation == '^') {
    result.value = pow(output->next->object.value, output->object.value);
  }
  return result;
}

calc_t s21_intermediate_calculations_for_1(stack_calc_t *output,
                                           stack_calc_t *operations) {
  calc_t result;
  result.operation = '\0';
  result.priority = 0;
  result.value = 0;
  if (operations->object.operation == SIN) {
    result.value = sin(output->object.value);
  } else if (operations->object.operation == COS) {
    result.value = cos(output->object.value);
  } else if (operations->object.operation == TAN) {
    result.value = tan(output->object.value);
  } else if (operations->object.operation == ASIN) {
    result.value = asin(output->object.value);
  } else if (operations->object.operation == ACOS) {
    result.value = acos(output->object.value);
  } else if (operations->object.operation == ATAN) {
    result.value = atan(output->object.value);
  } else if (operations->object.operation == SQRT) {
    result.value = sqrt(output->object.value);
  } else if (operations->object.operation == LN) {
    result.value = log(output->object.value);
  } else if (operations->object.operation == LOG) {
    result.value = log10(output->object.value);
  } else if (operations->object.operation == '(') {
    result.value = output->object.value;
  }
  return result;
}

void s21_calculate(stack_calc_t *list, double *result) {
  calc_t node_end;
  node_end.operation = '\0';
  node_end.priority = -1;
  node_end.value = 0;
  stack_calc_t *output = s21_create_node(node_end);
  stack_calc_t *operations = s21_create_node(node_end);
  calc_t res;
  res.operation = '\0';
  res.priority = 0;
  res.value = 0;
  while (list->object.priority != -1) {
    if (list->object.priority == 0) {
      s21_push(&output, list->object);
      list = list->next;
    } else if (list->object.priority > 0 && list->object.priority < 4) {
      if (list->object.priority > operations->object.priority ||
          operations->object.priority == 4) {
        s21_push(&operations, list->object);
        list = list->next;
      } else {
        res = s21_intermediate_calculations_for_2(output, operations);
        s21_pop(&output);
        s21_pop(&output);
        s21_pop(&operations);
        s21_push(&output, res);
      }
    } else if (list->object.priority == 4) {
      if (list->object.operation == ')') {
        while (operations->object.priority != 4) {
          res = s21_intermediate_calculations_for_2(output, operations);
          s21_pop(&output);
          s21_pop(&output);
          s21_pop(&operations);
          s21_push(&output, res);
        }
        res = s21_intermediate_calculations_for_1(output, operations);
        s21_pop(&operations);
        s21_pop(&output);
        s21_push(&output, res);
        list = list->next;
      } else {
        s21_push(&operations, list->object);
        list = list->next;
      }
    }
  }
  while (operations->object.priority != -1) {
    if (operations->object.priority != 4) {
      res = s21_intermediate_calculations_for_2(output, operations);
      s21_pop(&output);
      s21_pop(&output);
      s21_pop(&operations);
      s21_push(&output, res);
    } else {
      res = s21_intermediate_calculations_for_1(operations, output);
      s21_pop(&operations);
      s21_pop(&output);
      s21_push(&output, res);
    }
  }
  *result = output->object.value;
  s21_delete(&output);
  s21_delete(&operations);
  s21_delete(&list);
}