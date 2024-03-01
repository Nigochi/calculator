#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <plotwindow.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "../calc_functions/s21_smart_calc.h"

#ifdef __cplusplus
}
#endif

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_button_0_clicked();
  void on_button_1_clicked();
  void on_button_2_clicked();
  void on_button_3_clicked();
  void on_button_4_clicked();
  void on_button_5_clicked();
  void on_button_6_clicked();
  void on_button_7_clicked();
  void on_button_8_clicked();
  void on_button_9_clicked();
  void on_open_bracket_clicked();
  void on_close_bracket_clicked();
  void on_div_clicked();
  void on_mod_clicked();
  void on_mul_clicked();
  void on_sub_clicked();
  void on_add_clicked();
  void on_point_clicked();
  void on_equal_clicked();
  void on_ce_clicked();
  void on_plot_clicked();
  void on_sqrt_clicked();
  void on_pow_clicked();
  void on_sin_clicked();
  void on_cos_clicked();
  void on_asin_clicked();
  void on_acos_clicked();
  void on_tan_clicked();
  void on_atan_clicked();
  void on_ln_clicked();
  void on_log_clicked();
  void on_push_x_clicked();

 private:
  Ui::MainWindow *ui;
  plotwindow *plot_window;
};
#endif  // MAINWINDOW_H
