#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QWidget>

#ifdef __cplusplus
extern "C" {
#endif

#include "../calc_functions/s21_smart_calc.h"

#ifdef __cplusplus
}
#endif

namespace Ui {
class plotwindow;
}

class plotwindow : public QWidget {
  Q_OBJECT

 public:
  explicit plotwindow(QWidget *parent = nullptr);
  ~plotwindow();

 signals:
  void graphwindow();  // сигнал на открытие

 private slots:
  // Слот-обработчик нажатия кнопки
  void on_plot_clicked();
  void on_draw_graph_clicked();

 private:
  Ui::plotwindow *ui;

  double step, count_x, result;
  QVector<double> x, y;
};

#endif  // PLOTWINDOW_H
