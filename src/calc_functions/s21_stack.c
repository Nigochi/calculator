#include "s21_smart_calc.h"

stack_calc_t *s21_create_node(calc_t object) {
  stack_calc_t *node = (stack_calc_t *)malloc(sizeof(stack_calc_t));
  node->object = object;
  node->next = NULL;
  return node;
}

void s21_push(stack_calc_t **head, calc_t object) {
  stack_calc_t *tmp = malloc(sizeof(stack_calc_t));  // создали узел
  tmp->next = *head;  // присваеваем адрес предыдущего узла
  tmp->object = object;  // кладем данные
  *head = tmp;  // указателю head присваеваем адрес tmp
}

void s21_push_back(stack_calc_t **node, calc_t object) {
  stack_calc_t *new_node = s21_create_node(object);
  stack_calc_t *temp = *node;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
}

void s21_pop(stack_calc_t **head) {
  stack_calc_t *temp = *head;
  *head = temp->next;
  free(temp);
}

void s21_delete(stack_calc_t **node) {
  stack_calc_t *temp = *node;
  while (temp != NULL) {
    temp = temp->next;
    s21_pop(node);
    *node = temp;
  }
}