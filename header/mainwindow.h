#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <header/algorithmencoding.h>
#include <header/algorithmdecoding.h>
#include <memory>
#include "qlist.h"
#include "header/codeword.h"
#include "QTimer"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:

    void doStart();

    void doNextStep();

    void doClear();

    void doChooseDec();

    void doChooseEnc();

    void doBackStep();

    void openQuestionNextCode();

    void openQuestionNextDict();

    void changeAlg(int index);

    void doPause();

    void showAbout();



private:
    Ui::MainWindow *ui;
    AlgorithmEncoding *algo_enc; //uniq
    AlgorithmDecoding *algo_dec;
    QString in;
    int i;
    bool stop;
    QList <CodeWord> result;
    QTimer *auto_start;
};

#endif // MAINWINDOW_H
