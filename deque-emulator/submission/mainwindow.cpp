#include "mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <algorithm>
#include <string>
#include "algo.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ApplyModel();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::ApplyIterator() {
  int d = std::distance(deque_model_.items.begin(), deque_model_.iterator);
  ui->list_widget->setCurrentRow(d);
  bool disabled = deque_model_.iterator == deque_model_.items.end();
  ui->btn_edit->setDisabled(disabled);
  ui->btn_inc_iterator->setDisabled(disabled);
  ui->btn_erase->setDisabled(disabled);
  if (disabled) {
    ui->txt_elem_content->clear();
  } else {
    ui->txt_elem_content->setText(
        QString::fromStdString(*deque_model_.iterator));
  }
  bool is_begin = (deque_model_.iterator == deque_model_.items.begin());
  ui->btn_dec_iterator->setDisabled(is_begin);
}

void MainWindow::ApplyModel() {
  auto preserve_iter = deque_model_.iterator;
  ui->list_widget->clear();
  for (int i = 0; i < deque_model_.items.size(); i++) {
    QString text = QString::number(i) + ": " +
                   QString::fromStdString(deque_model_.items[i]);
    ui->list_widget->addItem(text);
  }
  ui->list_widget->addItem("end");
  ui->list_widget->update();
  ui->txt_size->setText(QString::number(deque_model_.items.size()));
  deque_model_.iterator = preserve_iter;
  ApplyIterator();
  ui->btn_pop_back->setDisabled(deque_model_.items.empty());
  ui->btn_pop_front->setDisabled(deque_model_.items.empty());
}

void MainWindow::on_btn_pop_front_clicked() {
  if (deque_model_.items.size() != 0) {
    ui->btn_pop_front->setDisabled(false);
    deque_model_.items.pop_front();
    deque_model_.iterator = deque_model_.items.begin();
    ApplyModel();
  } else {
    ui->btn_pop_front->setDisabled(true);
  }
}

void MainWindow::on_btn_pop_back_clicked() {
  if (deque_model_.items.size() != 0) {
    ui->btn_pop_back->setDisabled(false);
    deque_model_.items.pop_back();
    deque_model_.iterator = deque_model_.items.begin();
    ApplyModel();
  } else {
    ui->btn_pop_back->setDisabled(true);
  }
}

void MainWindow::on_btn_push_front_clicked() {
  QString str = ui->txt_elem_content->text();
  if (str.toStdString() != "") {
    deque_model_.items.push_front(str.toStdString());
    deque_model_.iterator = deque_model_.items.begin();
    ApplyModel();
  }
}

void MainWindow::on_btn_push_back_clicked() {
  QString str = ui->txt_elem_content->text();
  if (str.toStdString() != "") {
    deque_model_.items.push_back(str.toStdString());
    deque_model_.iterator = deque_model_.items.begin();
    ApplyModel();
  }
}

void MainWindow::on_btn_clear_clicked() {
  deque_model_.items.clear();
  deque_model_.iterator = deque_model_.items.begin();
  ApplyModel();
}

void MainWindow::on_btn_tea_clicked() {
  deque_model_.items.clear();
  deque_model_.items = tea;
  deque_model_.iterator = deque_model_.items.begin();
  ApplyModel();
}

void MainWindow::on_btn_cakes_clicked() {
  deque_model_.items.clear();
  deque_model_.items = cakes;
  deque_model_.iterator = deque_model_.items.begin();
  ApplyModel();
}

void MainWindow::on_list_widget_currentRowChanged(int currentRow) {
  if (currentRow == -1) return;
  if (currentRow >= 0 && currentRow < deque_model_.items.size()) {
    deque_model_.iterator = deque_model_.items.begin() + currentRow;
    ui->txt_elem_content->setText(
        QString::fromStdString(*deque_model_.iterator));
  } else {
    deque_model_.iterator = deque_model_.items.end();
    ui->txt_elem_content->clear();
  }
  ApplyIterator();
}

void MainWindow::on_btn_dec_iterator_clicked() {
  deque_model_.iterator = deque_model_.iterator - 1;
  ApplyIterator();
}

void MainWindow::on_btn_inc_iterator_clicked() {
  deque_model_.iterator = deque_model_.iterator + 1;
  ApplyIterator();
}

void MainWindow::on_btn_begin_clicked() {
  deque_model_.iterator = deque_model_.items.begin();
  ApplyIterator();
  ui->btn_dec_iterator->setDisabled(true);
}

void MainWindow::on_btn_end_clicked() {
  deque_model_.iterator = deque_model_.items.end();
  ApplyIterator();
  ui->btn_dec_iterator->setDisabled(false);
}

void MainWindow::on_btn_erase_clicked() {
  deque_model_.items.erase(deque_model_.iterator);
  deque_model_.iterator = deque_model_.items.begin();
  ApplyModel();
}

void MainWindow::on_btn_insert_clicked() {
  QString str = ui->txt_elem_content->text();
  if (!str.isEmpty()) {
    deque_model_.items.insert(deque_model_.iterator, str.toStdString());
    deque_model_.iterator = deque_model_.items.begin();
    ApplyModel();
  }
}

void MainWindow::on_btn_edit_clicked() {
  if (deque_model_.iterator != deque_model_.items.end()) {
    QString str = ui->txt_elem_content->text();
    *deque_model_.iterator = str.toStdString();
    ApplyModel();
  }
}

void MainWindow::on_btn_resize_clicked() {
  QString size_v = ui->txt_size->text();
  if (size_v.isEmpty()) {
    return;
  }
  int size = stoi(size_v.toStdString());
  if (size >= 0 && size <= 1000) {
    deque_model_.items.resize(size);
    deque_model_.iterator = deque_model_.items.begin();
    ApplyModel();
  }
}

void MainWindow::on_btn_find_clicked() {
  QString str = ui->txt_elem_content->text();
  auto it = std::find(deque_model_.items.begin(), deque_model_.items.end(),
                      str.toStdString());
  if (it != deque_model_.items.end()) {
    deque_model_.iterator = it;
    ApplyIterator();
  } else {
    deque_model_.iterator = deque_model_.items.end();
    ApplyIterator();
  }
}

void MainWindow::on_btn_count_clicked() {
  QString str = ui->le_count->text();
  int c = std::count(deque_model_.items.begin(), deque_model_.items.end(),
                     str.toStdString());
  QString result = QString::fromStdString(std::to_string(c));
  ui->lbl_count->setText(result);
}

void MainWindow::on_btn_min_element_clicked() {
  auto it =
      std::min_element(deque_model_.items.begin(), deque_model_.items.end());
  if (it != deque_model_.items.end()) {
    deque_model_.iterator = it;
    ApplyIterator();
  } else {
    deque_model_.iterator = deque_model_.items.end();
    ApplyIterator();
  }
}

void MainWindow::on_btn_max_element_clicked() {
  auto it =
      std::max_element(deque_model_.items.begin(), deque_model_.items.end());
  if (it != deque_model_.items.end()) {
    deque_model_.iterator = it;
    ApplyIterator();
  } else {
    deque_model_.iterator = deque_model_.items.end();
    ApplyIterator();
  }
}

void MainWindow::on_btn_sort_clicked() {
  deque_model_.items = MergeSort(
      deque_model_.items,
      [](const std::string& a, const std::string& b) { return a < b; });
  deque_model_.iterator = deque_model_.items.begin();
  ApplyModel();
}

void MainWindow::on_btn_sOrT_clicked() {
  deque_model_.items = MergeSort(deque_model_.items, [](const std::string& a,
                                                        const std::string& b) {
    return QString::compare(QString::fromStdString(a),
                            QString::fromStdString(b), Qt::CaseInsensitive) < 0;
  });
  deque_model_.iterator = deque_model_.items.begin();
  ApplyModel();
}

void MainWindow::on_btn_unique_clicked() {
  if (std::is_sorted(deque_model_.items.begin(), deque_model_.items.end())) {
    auto to_del =
        std::unique(deque_model_.items.begin(), deque_model_.items.end());
    deque_model_.items.erase(to_del, deque_model_.items.end());
    ApplyModel();
  }
}

void MainWindow::on_btn_reverse_clicked() {
  int idx = std::distance(deque_model_.items.begin(), deque_model_.iterator);
  std::reverse(deque_model_.items.begin(), deque_model_.items.end());
  if (idx > deque_model_.items.size()) {
    idx = deque_model_.items.size();
  }
  deque_model_.iterator = deque_model_.items.begin() + idx;
  ApplyModel();
}

void MainWindow::SetRandomGen(const std::mt19937& random_gen) {
  random_gen_ = random_gen;
}

void MainWindow::on_btn_shuffle_clicked() {
  std::shuffle(deque_model_.items.begin(), deque_model_.items.end(),
               random_gen_);
  ApplyModel();
}

void MainWindow::on_btn_lower_bound_clicked() {
  QString str = ui->txt_elem_content->text();
  if (str.toStdString() != "") {
    bool deque_is_sorted =
        std::is_sorted(deque_model_.items.begin(), deque_model_.items.end());
    if (deque_is_sorted) {
      deque_model_.iterator =
          std::lower_bound(deque_model_.items.begin(), deque_model_.items.end(),
                           str.toStdString());
      ApplyModel();
    }
  }
}

void MainWindow::on_btn_upper_bound_clicked() {
  QString str = ui->txt_elem_content->text();
  if (str.toStdString() != "") {
    bool deque_is_sorted =
        std::is_sorted(deque_model_.items.begin(), deque_model_.items.end());
    if (deque_is_sorted) {
      deque_model_.iterator =
          std::upper_bound(deque_model_.items.begin(), deque_model_.items.end(),
                           str.toStdString());
      ApplyModel();
    }
  }
}
