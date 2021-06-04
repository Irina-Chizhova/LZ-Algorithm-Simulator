#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <algorithmencoding.h>
#include <algorithmdecoding.h>
#include <memory>
#include "qlist.h"
#include "codeword.h"
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
    AlgorithmEncoding *algo_enc; //uniq
    AlgorithmDecoding *algo_dec;
    QString in;
    int i;
    bool stop;
    QList <CodeWord> result;
    QTimer *auto_start;
     void doMagic();

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



    void on_back_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
