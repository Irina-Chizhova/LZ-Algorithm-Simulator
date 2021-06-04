#include "algorithmmenu.h"
#include "ui_algorithmmenu.h"

AlgorithmMenu::AlgorithmMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AlgorithmMenu)
{
    ui->setupUi(this);
}

AlgorithmMenu::~AlgorithmMenu()
{
    delete ui;
}
