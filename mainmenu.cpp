#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <algmenu.h>

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_clicked()
{
    hide();
    AlgMenu aui;
    aui.setWindowTitle("Welcome!");
    aui.setModal(true);
    aui.exec();
}
