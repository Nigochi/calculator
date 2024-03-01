#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIN '0'
#define COS '1'
#define TAN '2'
#define ASIN '3'
#define ACOS '4'
#define ATAN '5'
#define SQRT '6'
#define LN '7'
#define LOG '8'

typedef struct calc {
  double value;
  char operation;
  int priority;
} calc_t;

typedef struct stack {
  calc_t object;
  struct stack *next;
} stack_calc_t;

stack_calc_t *s21_create_node(calc_t object);
void s21_push(stack_calc_t **head, calc_t object);
void s21_push_back(stack_calc_t **node, calc_t object);
void s21_pop(stack_calc_t **head);
void s21_delete(stack_calc_t **node);

int s21_parse(char *src, stack_calc_t **list);
int s21_parse_operand(char *src, int *i, double *result);
calc_t s21_parse_operation(char *src, int *i);

int s21_check_operator(char check);
int s21_check_correct_src(char *src);

void s21_calculate(stack_calc_t *list, double *result);
calc_t s21_intermediate_calculations_for_2(stack_calc_t *output,
                                           stack_calc_t *operations);
calc_t s21_intermediate_calculations_for_1(stack_calc_t *output,
                                           stack_calc_t *operations);

int s21_start_calc(char *src, double *result);

#endif  // S21_SMART_CALC_H
