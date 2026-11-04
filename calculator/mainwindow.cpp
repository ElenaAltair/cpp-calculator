#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->l_result->setText("0");
  ui->l_memory->setText("");
  ui->l_formula->setText("");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::SetInputText(const std::string& text) {
  ui->l_result->setStyleSheet("");
  ui->l_result->setText(QString::fromStdString(text));
}

void MainWindow::SetErrorText(const std::string& text) {
  ui->l_result->setText(QString::fromStdString(text));
  ui->l_result->setStyleSheet("color: red;");
}

void MainWindow::SetFormulaText(const std::string& text) {
  ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string& text) {
  ui->l_memory->setText(QString::fromStdString(text));
}

void MainWindow::SetExtraKey(const std::optional<std::string>& key) {
  if (key == std::nullopt) {
    ui->tb_extra->setVisible(false);
  } else {
    ui->tb_extra->setVisible(true);
    ui->tb_extra->setText(QString::fromStdString(key.value()));
  }
}

void MainWindow::SetDigitKeyCallback(std::function<void(int)> cb) {
  digit_cb_ = cb;
}

void MainWindow::SetProcessOperationKeyCallback(
    std::function<void(Operation)> cb) {
  operation_cb_ = cb;
}

void MainWindow::SetProcessControlKeyCallback(
    std::function<void(ControlKey)> cb) {
  control_cb_ = cb;
}

void MainWindow::SetControllerCallback(std::function<void(ControllerType)> cb) {
  controller_cb_ = cb;
}

void MainWindow::on_tb_one_clicked() {
  CallDigit(1);
}

void MainWindow::on_tb_two_clicked() {
  CallDigit(2);
}

void MainWindow::on_tb_three_clicked() {
  CallDigit(3);
}

void MainWindow::on_tb_four_clicked() {
  CallDigit(4);
}

void MainWindow::on_tb_five_clicked() {
  CallDigit(5);
}

void MainWindow::on_tb_six_clicked() {
  CallDigit(6);
}

void MainWindow::on_tb_seven_clicked() {
  CallDigit(7);
}

void MainWindow::on_tb_eight_clicked() {
  CallDigit(8);
}

void MainWindow::on_tb_nine_clicked() {
  CallDigit(9);
}

void MainWindow::on_tb_zero_clicked() {
  CallDigit(0);
}

void MainWindow::on_tb_power_clicked() {
  CallOperation(Operation::POWER);
}

void MainWindow::on_tb_add_clicked() {
  CallOperation(Operation::ADDITION);
}

void MainWindow::on_tb_divide_clicked() {
  CallOperation(Operation::DIVISION);
}

void MainWindow::on_tb_multiplicate_clicked() {
  CallOperation(Operation::MULTIPLICATION);
}

void MainWindow::on_tb_substract_clicked() {
  CallOperation(Operation::SUBTRACTION);
}

void MainWindow::on_tb_equal_clicked() {
  CallControl(ControlKey::EQUALS);
}

void MainWindow::on_cmb_controller_currentIndexChanged(int index) {
  QString type = ui->cmb_controller->currentText();
  ControllerType controller_type = ControllerType::DOUBLE;
  if (type == "float") {
    controller_type = ControllerType::FLOAT;
  } else if (type == "uint8_t") {
    controller_type = ControllerType::UINT8_T;
  } else if (type == "int") {
    controller_type = ControllerType::INT;
  } else if (type == "int64_t") {
    controller_type = ControllerType::INT64_T;
  } else if (type == "size_t") {
    controller_type = ControllerType::SIZE_T;
  } else if (type == "Rational") {
    controller_type = ControllerType::RATIONAL;
  }
  if (controller_cb_) {
    controller_cb_(controller_type);
  }
}

void MainWindow::on_tb_reset_clicked() {
  CallControl(ControlKey::CLEAR);
}

void MainWindow::on_tb_ms_clicked() {
  CallControl(ControlKey::MEM_SAVE);
}

void MainWindow::on_tn_mr_clicked() {
  CallControl(ControlKey::MEM_LOAD);
}

void MainWindow::on_tb_mc_clicked() {
  CallControl(ControlKey::MEM_CLEAR);
}

void MainWindow::on_tb_negate_clicked() {
  CallControl(ControlKey::PLUS_MINUS);
}

void MainWindow::on_tb_backspace_clicked() {
  CallControl(ControlKey::BACKSPACE);
}

void MainWindow::on_tb_extra_clicked() {
  CallControl(ControlKey::EXTRA_KEY);
}
