#ifndef ALGORITHMMENU_H
#define ALGORITHMMENU_H

#include <QMainWindow>

namespace Ui {
class AlgorithmMenu;
}

class AlgorithmMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlgorithmMenu(QWidget *parent = 0);
    ~AlgorithmMenu();

private:
    Ui::AlgorithmMenu *ui;
};

#endif // ALGORITHMMENU_H
