#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zeroButton,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->oneButton,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->twoButton,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->threeButton,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->fourButton,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->fiveButton,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->sixButton,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->sevenButton,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->eightButton,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->nineButton,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->plus_minusButton,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->percentButton,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->slashButton,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->minusButton,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->plusButton,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->xButton,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->slashButton->setCheckable(true);
    ui->minusButton->setCheckable(true);
    ui->plusButton->setCheckable(true);
    ui->xButton->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){
    QPushButton *button = (QPushButton *)sender();
    double numbers;
    QString newLabel;

    if(ui->resultBar->text().contains(".") && button->text()=="0"){
        newLabel = ui->resultBar->text() + button->text();
    } else {
        numbers = (ui->resultBar->text() + button->text()).toDouble();
        newLabel = QString::number(numbers, 'g', 15);
    }
    ui->resultBar->setText(newLabel);
}

void MainWindow::on_dotButton_clicked()
{
    if(!(ui->resultBar->text().contains('.'))){
    ui->resultBar->setText(ui->resultBar->text() + ".");
    }
}

void MainWindow::operations(){
    QPushButton *button = (QPushButton *)sender();
    double numbers;
    QString newLabel;

    if(button->text() == "+/-"){
        numbers = (ui->resultBar->text()).toDouble();
        numbers = numbers * -1;
        newLabel = QString::number(numbers, 'g', 15);

        ui->resultBar->setText(newLabel);
    }
    else if(button->text() == "%"){
        numbers = (ui->resultBar->text()).toDouble();
        numbers = numbers * 0.01;
        newLabel = QString::number(numbers, 'g', 15);

        ui->resultBar->setText(newLabel);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();
    num_first = ui->resultBar->text().toDouble();
    ui->resultBar->setText("");
    button->setCheckable(true);

}


void MainWindow::on_ACButton_clicked()
{
    QString newLabel = "0";
    ui->resultBar->setText(newLabel);
}


void MainWindow::on_equalButton_clicked()
{
    double firstNum, secondNum;
    QString newLabel;

    secondNum = ui->resultBar->text().toDouble();

    if(ui->plusButton->isChecked()){
        firstNum = num_first + secondNum;
        newLabel = QString::number(firstNum, 'g', 15);

        ui->resultBar->setText(newLabel);
        ui->plusButton->setChecked(false);
    }
    else if(ui->minusButton->isChecked()){
        if(secondNum == 0){
            ui->resultBar->setText("0");
        } else {
            firstNum = num_first - secondNum;
            newLabel = QString::number(firstNum, 'g', 15);

            ui->resultBar->setText(newLabel);
            ui->minusButton->setChecked(false);
        }
    }
    else if(ui->xButton->isChecked()){
        firstNum = num_first * secondNum;
        newLabel = QString::number(firstNum, 'g', 15);

        ui->resultBar->setText(newLabel);
        ui->xButton->setChecked(false);
    }
    else if(ui->slashButton->isChecked()){
        firstNum = num_first / secondNum;
        newLabel = QString::number(firstNum, 'g', 15);

        ui->resultBar->setText(newLabel);
        ui->slashButton->setChecked(false);
    }
}

