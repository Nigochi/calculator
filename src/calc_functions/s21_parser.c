#include "s21_smart_calc.h"

int s21_parse_operand(char *src, int *i, double *result) {
  int res = 0;
  char number[256];
  int mantisa = 0;
  int j = 0;
  while ((src[*i] > 47 && src[*i] < 58) || src[*i] == '.') {
    if (src[*i] == '.' && !mantisa) {
      mantisa = 1;
    } else if (src[*i] == '.' && mantisa) {
      res = 1;  // проверка на наличие двух точек
    }
    number[j] = src[*i];
    j++;
    number[j] = '\0';
    *i += 1;
  }
  *i -= 1;
  *result = strtod(number, NULL);
  return res;
}

calc_t s21_parse_operation(char *src, int *i) {
  calc_t res;
  res.operation = '\0';
  res.priority = 0;
  res.value = 0;

  switch (src[*i]) {
    case '+':
      if (*i > 0) {
        if (src[*i - 1] == '(') {
          res.operation = 'P';
        } else {
          res.operation = '+';
          res.priority = 1;
        }
      } else if (*i == 0) {
        res.operation = 'P';
      }
      break;
    case '-':
      if (*i > 0) {
        if (src[*i - 1] == '(') {
          res.operation = '~';
          res.priority = 4;
        } else {
          res.operation = '-';
          res.priority = 1;
        }
      } else if (*i == 0) {
        res.operation = '~';
        res.priority = 4;
      }
      break;
    case '*':
      res.operation = '*';
      res.priority = 2;
      break;
    case '/':
      res.operation = '/';
      res.priority = 2;
      break;
    case 'm':
      if (src[*i + 1] == 'o' && src[*i + 2] == 'd') {
        *i += 2;
        res.operation = '%';
        res.priority = 2;
      }
      break;
    case '^':
      res.operation = '^';
      res.priority = 3;
      break;
    case 'c':
      if (src[*i + 1] == 'o' && src[*i + 2] == 's' && src[*i + 3] == '(') {
        *i += 3;
        res.operation = COS;
        res.priority = 4;
      }
      break;
    case 's':
      if (src[*i + 1] == 'i' && src[*i + 2] == 'n' && src[*i + 3] == '(') {
        *i += 3;
        res.operation = SIN;
        res.priority = 4;
      } else if (src[*i + 1] == 'q' && src[*i + 2] == 'r' &&
                 src[*i + 3] == 't' && src[*i + 4] == '(') {
        *i += 4;
        res.operation = SQRT;
        res.priority = 4;
      }
      break;
    case 't':
      if (src[*i + 1] == 'a' && src[*i + 2] == 'n' && src[*i + 3] == '(') {
        *i += 3;
        res.operation = TAN;
        res.priority = 4;
      }
      break;
    case 'a':
      if (src[*i + 1] == 'c' && src[*i + 2] == 'o' && src[*i + 3] == 's' &&
          src[*i + 4] == '(') {
        *i += 4;
        res.operation = ACOS;
        res.priority = 4;
      } else if (src[*i + 1] == 's' && src[*i + 2] == 'i' &&
                 src[*i + 3] == 'n' && src[*i + 4] == '(') {
        *i += 4;
        res.operation = ASIN;
        res.priority = 4;
      } else if (src[*i + 1] == 't' && src[*i + 2] == 'a' &&
                 src[*i + 3] == 'n' && src[*i + 4] == '(') {
        *i += 4;
        res.operation = ATAN;
        res.priority = 4;
      }
      break;
    case 'l':
      if (src[*i + 1] == 'n' && src[*i + 2] == '(') {
        *i += 2;
        res.operation = LN;
        res.priority = 4;
      } else if (src[*i + 1] == 'o' && src[*i + 2] == 'g' &&
                 src[*i + 3] == '(') {
        *i += 3;
        res.operation = LOG;
        res.priority = 4;
      }
      break;
    case '(':
      res.operation = '(';
      res.priority = 4;
      break;
    case ')':
      res.operation = ')';
      res.priority = 4;
      break;
    default:
      res.operation = '\0';
      res.priority = 100;
      break;
  }
  return res;
}

int s21_check_operator(char check) {
  int to_return;
  if (strchr("+-/*.^%", check)) {
    to_return = 1;
  } else {
    to_return = 0;
  }
  return to_return;
}

int s21_check_correct_src(char *src) {
  int res = 0;
  int open_bracket = 0;
  int close_bracket = 0;
  int last = 0;
  for (int i = 0; src[i] != '\0'; i++) {
    if (src[i] == '(') {
      open_bracket++;
    }
    if (src[i] == ')') {
      close_bracket++;
    }
  }
  for (int i = 0; src[i] != '\0'; i++) {
    if (s21_check_operator(src[i]) && last) {
      res = 1;
    }
    last = s21_check_operator(src[i]);
  }
  if (open_bracket != close_bracket) {
    res = 1;
  }
  for (int i = 0; src[i] != '\0'; i++) {
    if (s21_check_operator(src[i]) && src[i + 1] == '\0') {
      res = 1;
    }
    if (src[i] < 58 && src[i] > 47 && src[i + 1] == '(') {
      res = 1;
    }
  }
  return res;
}

// глобальный парсер, раскидывает по мелким парсерам
int s21_parse(char *src, stack_calc_t **list) {
  int res = 0;
  calc_t object;

  object.operation = '\0';
  object.priority = 0;
  object.value = 0;

  int i = 0;

  res = s21_check_correct_src(src);

  while (src[i] != '\0') {
    if (src[i] != ' ' && (src[i] < 48 || src[i] > 57)) {
      object = s21_parse_operation(src, &i);

      if (object.operation != '\0' && object.operation != 'P' &&
          object.operation != '~') {
        s21_push_back(list, object);
      } else if (object.operation == 'P') {
      } else if (object.operation == '~') {
        calc_t minus;
        minus.operation = '-';
        minus.priority = 1;
        minus.value = 0;
        calc_t zero;
        zero.operation = '\0';
        zero.priority = 0;
        zero.value = 0;
        s21_push_back(list, minus);
        s21_push_back(list, zero);
      } else {
        res = 1;
      }

    } else if (src[i] != ' ') {
      object.operation = '\0';
      object.priority = 0;
      if (s21_parse_operand(src, &i, &object.value)) res = 1;
      s21_push_back(list, object);
    }

    i++;
  }
  return res;
}