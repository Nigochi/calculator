#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // инициализация нового окна
  plot_window = new plotwindow();
  // подключаем к слоту запуска главного окна по кнопке во втором окне
  connect(plot_window, &plotwindow::graphwindow, this, &MainWindow::show);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_plot_clicked() { plot_window->show(); }

void MainWindow::on_equal_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "") {
    QString temp = {"0"};
    ui->calc_text->setText(temp);
  } else {
    double result = 0;
    QByteArray ba = text.toLocal8Bit();
    char *src = ba.data();
    int error = s21_start_calc(src, &result);
    if (error != 1) {
      QString temp = QString::number(result);
      ui->calc_text->setText(temp);
    } else {
      QString temp = {"error"};
      ui->calc_text->setText(temp);
    }
  }
}

void MainWindow::on_push_x_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString text_num = ui->edit_x_eq->toPlainText();
  text_num.toFloat();
  QString str = {text_num};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_button_0_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"0"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_button_1_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"1"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_button_2_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"2"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_button_3_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"3"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_button_4_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"4"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_button_5_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"5"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_button_6_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"6"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_button_7_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"7"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_button_8_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"8"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_button_9_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"9"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_open_bracket_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"("};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_close_bracket_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {")"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_div_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"/"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_mod_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"mod("};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_mul_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"*"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_sub_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"-"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_add_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"+"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_pow_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"^"};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_ce_clicked() {
  QString result = {""};
  ui->calc_text->setText(result);
}

void MainWindow::on_sqrt_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"sqrt("};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_sin_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"sin("};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_cos_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"cos("};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_tan_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"tan("};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_asin_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"asin("};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_acos_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"acos("};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_atan_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"atan("};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_ln_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"ln("};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_log_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"log("};
  QString result = text + str;
  ui->calc_text->setText(result);
}

void MainWindow::on_point_clicked() {
  QString text = ui->calc_text->toPlainText();
  if (text == "0" || text == "error") {
    text = "";
  }
  QString str = {"."};
  QString result = text + str;
  ui->calc_text->setText(result);
}
