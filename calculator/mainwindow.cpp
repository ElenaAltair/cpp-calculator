#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->l_result->setText("0");
  ui->l_memory->setText("");
  ui->l_formula->setText("");
  SetText("0");
}

MainWindow::~MainWindow() { delete ui; }

QString MainWindow::RemoveTrailingZeroes(const QString& text) {
  for (qsizetype i = 0; i < text.size(); ++i) {
    if (text[i] != '0') {
      return text.mid(i);
    }
  }
  return "";
}

QString MainWindow::NormalizeNumber(const QString& text) {
  if (text == "-") {
    return text;
  }
  if (text.isEmpty()) {
    return "0";
  }
  if (text.startsWith('.')) {
    // Рекурсивный вызов.
    return NormalizeNumber("0" + text);
  }
  if (text.startsWith('-')) {
    // Рекурсивный вызов.
    return "-" + NormalizeNumber(text.mid(1));
  }
  if (text.startsWith('0') && !text.startsWith("0.")) {
    return NormalizeNumber(RemoveTrailingZeroes(text));
  }
  return text;
}

void MainWindow::SetText(const QString& text) {
  input_number_ = NormalizeNumber(text);
  active_number_ = input_number_.toDouble();
  ui->l_result->setText(input_number_);
  if (current_operation_ != Operation::NO_OPERATION) {
    QString formula_new = "%1 %2 %3";
    QString formula_formatted = formula_new.arg(calculator_.GetNumber())
                                    .arg(OpToString(current_operation_))
                                    .arg(input_number_);
    ui->l_formula->setText(formula_formatted);
  } else {
    ui->l_formula->clear();
  }
}

void MainWindow::AddText(const QString& suffix) {
  if (is_result_shown_) {
    ui->l_formula->clear();
    input_number_ = "";
    is_result_shown_ = false;
  }
  input_number_ += suffix;
  SetText(input_number_);
}

void MainWindow::SetOperation(Operation op) {
  calculator_.Set(active_number_);
  current_operation_ = op;
  QString formula = "%1 %2 ";
  QString formula_formatted =
      formula.arg(calculator_.GetNumber()).arg(OpToString(op));
  ui->l_formula->setText(formula_formatted);
  ui->l_result->setText(QString::number(calculator_.GetNumber()));
  input_number_ = "";
}

QString MainWindow::OpToString(Operation op) {
  switch (op) {
    case Operation::NO_OPERATION:
      return "";
    case Operation::ADDITION:
      return "+";
    case Operation::DIVISION:
      return "÷";
    case Operation::MULTIPLICATION:
      return "×";
    case Operation::SUBTRACTION:
      return "−";
    case Operation::POWER:
      return "^";
    default:
      return "";
  }
}

void MainWindow::on_tb_one_clicked() {
  AddText("1");
}

void MainWindow::on_tb_two_clicked() {
  AddText("2");
}

void MainWindow::on_tb_three_clicked() {
  AddText("3");
}

void MainWindow::on_tb_four_clicked() {
  AddText("4");
}

void MainWindow::on_tb_five_clicked() {
  AddText("5");
}

void MainWindow::on_tb_six_clicked() {
  AddText("6");
}

void MainWindow::on_tb_seven_clicked() {
  AddText("7");
}

void MainWindow::on_tb_eight_clicked() {
  AddText("8");
}

void MainWindow::on_tb_nine_clicked() {
  AddText("9");
}

void MainWindow::on_tb_zero_clicked() {
  AddText("0");
}

void MainWindow::on_tb_comma_clicked() {
  if (input_number_.toStdString().find_first_of(".") == std::string::npos) {
    AddText(".");
  }
}

void MainWindow::on_tb_negate_clicked() {
  if (is_result_shown_) {
    ui->l_formula->clear();
    input_number_ = "";
    is_result_shown_ = false;
  }
  if (input_number_ == "0") {
    input_number_ = "-";
    SetText(input_number_);
    return;
  }
  if (input_number_.startsWith("-")) {
    SetText(input_number_.mid(1));
  } else {
    QString input_number_with_minus = "%1%2";
    SetText(input_number_with_minus.arg("-").arg(input_number_));
  }
}

void MainWindow::on_tb_backspace_clicked() {
  if (is_result_shown_) {
    ui->l_formula->clear();
    input_number_ = "";
    is_result_shown_ = false;
    SetText("0");
    return;
  }
  QString result_number = ui->l_result->text();
  if (result_number == "0") {
    return;
  }
  result_number.chop(1);
  SetText(result_number);
}

void MainWindow::on_tb_power_clicked() {
  SetOperation(Operation::POWER);
  is_result_shown_ = false;
}

void MainWindow::on_tb_add_clicked() {
  SetOperation(Operation::ADDITION);
  is_result_shown_ = false;
}

void MainWindow::on_tb_divide_clicked() {
  SetOperation(Operation::DIVISION);
  is_result_shown_ = false;
}

void MainWindow::on_tb_multiplicate_clicked() {
  SetOperation(Operation::MULTIPLICATION);
  is_result_shown_ = false;
}

void MainWindow::on_tb_substract_clicked() {
  SetOperation(Operation::SUBTRACTION);
  is_result_shown_ = false;
}

void MainWindow::on_tb_equal_clicked() {
  if (current_operation_ == Operation::NO_OPERATION) {
    return;
  }
  QString formula = "%1 %2 %3 =";
  QString formula_formatted = formula.arg(calculator_.GetNumber())
                                  .arg(OpToString(current_operation_))
                                  .arg(active_number_);
  ui->l_formula->setText(formula_formatted);
  switch (current_operation_) {
    case Operation::POWER:
      calculator_.Pow(active_number_);
      break;
    case Operation::ADDITION:
      calculator_.Add(active_number_);
      break;
    case Operation::DIVISION:
      calculator_.Div(active_number_);
      break;
    case Operation::MULTIPLICATION:
      calculator_.Mul(active_number_);
      break;
    case Operation::SUBTRACTION:
      calculator_.Sub(active_number_);
      break;
    default:
      break;
  }
  active_number_ = calculator_.GetNumber();
  ui->l_result->setText(QString::number(active_number_));
  input_number_ = "";
  current_operation_ = Operation::NO_OPERATION;
  is_result_shown_ = true;
}

void MainWindow::on_tb_reset_clicked() {
  current_operation_ = Operation::NO_OPERATION;
  ui->l_formula->clear();
  is_result_shown_ = false;
  input_number_ = "0";
  active_number_ = 0;
  ui->l_result->setText("0");
}

void MainWindow::on_tb_ms_clicked() {
  number_in_memory_ui_ = active_number_;
  memory_is_used_ui_ = true;
  ui->l_memory->setText("M");
}

void MainWindow::on_tb_mc_clicked() {
  number_in_memory_ui_ = 0;
  memory_is_used_ui_ = false;
  ui->l_memory->setText("");
}

void MainWindow::on_tn_mr_clicked() {
  if (memory_is_used_ui_) {
    if (is_result_shown_) {
      ui->l_formula->clear();
      is_result_shown_ = false;
    }
    active_number_ = number_in_memory_ui_;
    input_number_ = QString::number(active_number_);
    SetText(QString::number(active_number_));
  }
}
