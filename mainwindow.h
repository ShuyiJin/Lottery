#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <ctime>
#include <QtAlgorithms>

#define NUM 7

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init_button();
    void print_selection();
    void compare();
    void rand_num();
    void show_rand();
    void print_result();

public slots:
    void deal_clear();
    void deal_save();
    void deal_num();
    void deal_enter();

private:
    Ui::MainWindow *ui;
    QVector<int> selection;
    QVector<int> lottery;
    QString selected;
};

#endif // MAINWINDOW_H
