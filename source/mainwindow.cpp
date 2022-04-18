#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>

#include "joiner.h"

jns::Joiner joiner;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_firstPickFileButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Pick a lua file");
    joiner.setFirstFileData(joiner.getFileData(filePath));

    if (!joiner.getFirstFileData().isEmpty())
    {
        ui->firstFileLocation->setText(filePath.section("/", -1, -1));
    }
    else
    {
        ui->statusbar->showMessage("Incorrect first file", 5000);
    }
}


void MainWindow::on_secondPickFileButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Pick a lua file");
    joiner.setSecondFileData(joiner.getFileData(filePath));

    if (!joiner.getSecondFileData().isEmpty())
    {
        ui->secondFileLocation->setText(filePath.section("/", -1, -1));
    }
    else
    {
        ui->statusbar->showMessage("Incorrect second file", 5000);
    }
}

void MainWindow::on_joinFilesButton_clicked()
{
    if (joiner.joinFiles())
    {
        ui->statusbar->showMessage("Files are joined successfully! The result is saved in current folder (joined.lua)", 5000);
    }
    else
    {
        ui->statusbar->showMessage("Files aren't joined!", 5000);
    }
}

