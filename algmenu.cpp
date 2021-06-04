#include "algmenu.h"
#include "ui_algmenu.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"


AlgMenu::AlgMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlgMenu)
{
    ui->setupUi(this);
}

AlgMenu::~AlgMenu()
{
    delete ui;
}


void AlgMenu::on_pushButton_clicked()
{
   //ui->pushButton_2->setEnabled(true);
    MainWindow *w = new MainWindow( ui->comboBox->currentIndex(), this);
    connect (w, SIGNAL(finished(int)),w,SLOT(deleteLater()));
    w->show();

}

