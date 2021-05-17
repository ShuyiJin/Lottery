#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lottery.reserve(7);
    selection.reserve(7);
    srand(time(0));

    init_button();
    rand_num();
    //show_rand();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_button()
{
    connect(ui->pushButton_0, &QPushButton::clicked, this, &MainWindow::deal_num);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::deal_num);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::deal_num);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::deal_num);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::deal_num);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::deal_num);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::deal_num);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::deal_num);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::deal_num);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::deal_num);
    connect(ui->pushButton_save, &QPushButton::clicked, this, &MainWindow::deal_save);
    connect(ui->pushButton_enter, &QPushButton::clicked, this, &MainWindow::deal_enter);
    connect(ui->pushButton_clear, &QPushButton::clicked, this, &MainWindow::deal_clear);
}

void MainWindow::print_selection()
{
    QVector<int>::const_iterator it;
    QString tmp = "";
    for(it = selection.begin(); it < selection.end(); ++it)
    {
        tmp += QString::number(*it);
        tmp += " ";
    }
    tmp += selected;
    ui->lineEdit_select->clear();
    ui->lineEdit_select->setText(tmp);
}

void MainWindow::compare()
{
    qSort(selection.begin(), selection.end());
    int count = 0;
    QVector<int>::const_iterator s_it = selection.begin();
    QVector<int>::const_iterator l_it = lottery.begin();
    while(s_it != selection.end() && l_it != lottery.end())
    {
        if(*s_it < *l_it)
        {
            s_it++;
        }
        else if(*s_it > *l_it)
        {
            l_it++;
        }
        if(*s_it == *l_it)
        {
            count++;
            s_it++;
            l_it++;
        }
    }
    qDebug() << count;
    QString result;
    result.append(QString::number(count));
    if(count == 1)
    {
        result.append(" matching.");
    }
    else
    {
        result.append(" matchings");
    }
    if(count == 5)
    {
        result.append("\nYou won 20,000 RMB!");
    }
    else if(count == 6)
    {
        result.append("\nYou won 100,000 RMB!");
    }
    else if(count == 7)
    {
        result.append("\nYou won 500,000 RMB!");
    }
    ui->label_result->setText(result);
}

void MainWindow::rand_num()
{
    int tmp = 0;
    while(lottery.size() < 7)
    {
        tmp = rand()%35+1;
        if(!lottery.contains(tmp))
            lottery.push_back(tmp);
    }

    qSort(lottery.begin(), lottery.end());
}

void MainWindow::show_rand()
{
    QString line;
    QVector<int>::const_iterator it;
    for(it = lottery.begin(); it != lottery.end(); ++it)
    {
        line.append(QString::number(*it));
        line += " ";
    }
    qDebug() << line;
    ui->lineEdit_lot->setText(line);
}

void MainWindow::deal_clear()
{
    selected.clear();
    print_selection();
}

void MainWindow::deal_save()
{
    deal_enter();
    if(selection.size() == 7)
    {
        show_rand();
        compare();
        print_result();
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Need to choose 7 numbers");
    }
}

void MainWindow::deal_num()
{
    if(selection.size() == 7)
    {
        QMessageBox::warning(this, "Warning", "You have entered 7 numbers. Please press start button.");
        return;
    }
    QObject *send = QObject::sender();
    if(send == ui->pushButton_0)
    {
        selected += "0";
    }
    else if(send == ui->pushButton_1)
    {
        selected += "1";
    }
    else if(send == ui->pushButton_2)
    {
        selected += "2";
    }
    else if(send == ui->pushButton_3)
    {
        selected += "3";
    }
    else if(send == ui->pushButton_4)
    {
        selected += "4";
    }
    else if(send == ui->pushButton_5)
    {
        selected += "5";
    }
    else if(send == ui->pushButton_6)
    {
        selected += "6";
    }
    else if(send == ui->pushButton_7)
    {
        selected += "7";
    }
    else if(send == ui->pushButton_8)
    {
        selected += "8";
    }
    if(send == ui->pushButton_9)
    {
        selected += "9";
    }
    print_selection();
}

void MainWindow::deal_enter()
{
    if(selected == "")
        return;
    if(selected.toInt() > 35)
    {
        QMessageBox::warning(this, "Warning", "Number must be within 1~35");
    }
    else
    {
        selection.push_back(selected.toInt());
    }
    selected.clear();
    print_selection();
}

void MainWindow::print_result()
{

}
