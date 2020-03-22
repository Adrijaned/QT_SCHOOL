#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::on_SWP_clicked() {
    QPalette p = ui->numA->palette();
    ui->numA->setPalette(ui->numB->palette());
    ui->numB->setPalette(p);
}

void MainWindow::on_add_clicked() {
    popUp(ui->numA->text() + " + " + ui->numB->text() + " = " + QString::number(getNumA() + getNumB()));
}

void MainWindow::on_divide_clicked() {
    popUp(ui->numA->text() + " / " + ui->numB->text() + " = " + QString::number(getNumA() / getNumB()));
}

void MainWindow::on_multiply_clicked() {
    popUp(ui->numA->text() + " * " + ui->numB->text() + " = " + QString::number(getNumA() * getNumB()));
}

void MainWindow::on_subtract_clicked() {
    popUp(ui->numA->text() + " - " + ui->numB->text() + " = " + QString::number(getNumA() - getNumB()));
}

float MainWindow::getNumA() {
    return ui->numA->text().toFloat();
}

float MainWindow::getNumB() {
    return ui->numB->text().toFloat();
}

void MainWindow::popUp(QString msg) {
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

