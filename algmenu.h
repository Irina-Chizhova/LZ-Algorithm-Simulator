#ifndef ALGMENU_H
#define ALGMENU_H

#include <QDialog>

namespace Ui {
class AlgMenu;
}

class AlgMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AlgMenu(QWidget *parent = 0);
    ~AlgMenu();

private slots:

    void on_pushButton_clicked();

private:
    Ui::AlgMenu *ui;
};

#endif // ALGMENU_H
