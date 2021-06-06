#include "header/mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QTimer"
#include "QThread"
#include "QEventLoop"
#include "header/algorithm.h"
#include "header/lzw.h"
#include "header/lzwdecoding.h"
#include "header/lz78.h"
#include "header/lz78decoding.h"
#include "header/question.h"
#include "memory"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->chooseEnc->setChecked(true);

        algo_enc = new LZW;
        algo_dec = new LZWDecoding;

          QString init="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ1234567890,. !?:;-~";
            QString forDict;

            for (int i=0;i<init.length();i++)
            {
                forDict.clear();
                forDict+=QString::number(i+1);
                forDict+=": ";
                forDict+=init[i];
                ui->dictionary->append(forDict);
            }

    algo_enc->setPosition(0);
    algo_dec->setPosition(0);
    stop=false;
    algo_enc->start();
    algo_dec->start();
    auto_start = new QTimer();

}

MainWindow::~MainWindow()
{
    delete auto_start;
    delete ui;
}


void MainWindow::doStart()
{
    ui->back->setEnabled(false);
    ui->forvard->setEnabled(false);
    ui->startButton->setEnabled(false);

    int speed=10;
    auto_start->setInterval(speed);
    connect(auto_start, SIGNAL(timeout()), this, SLOT(doNextStep()));

    if((!ui->chooseEnc->isChecked()) && (!ui->chooseDec->isChecked()))
        QMessageBox::about(this,"Erorr","Не выбран режм работы программы(кодирование или декодирование)!");


        auto_start->start();

}

void MainWindow::doNextStep()
{

    QString rez;
    in=ui->input->toPlainText();
    in+="~";//специфичный символ конца строки,может найти еще более специфичный?

    algo_enc->setData(in);
    if((!ui->chooseEnc->isChecked()) && (!ui->chooseDec->isChecked()))
        QMessageBox::about(this,"Erorr","Не выбран режим работы программы(кодирование или декодирование)!");

    if(ui->chooseEnc->isChecked()) //если выбран режим кодирования
    {
        if(algo_enc->getPosition()>=in.length())
        {
            QMessageBox::about(this,"!","Кодирование завершено!");
            i=0;
            auto_start->stop();
            disconnect(auto_start, SIGNAL(timeout()), this, SLOT(doNextStep()));
            ui->startButton->setEnabled(true);
            ui->forvard->setEnabled(true);
            ui->back->setEnabled(true);
            stop=true;
            ui->menu_3->setEnabled(false);
        }
        else
        {
            i=algo_enc->getPosition();
            if(algo_enc->getPosition()<in.length())
            {
                algo_enc->nextStep();
                if (algo_enc->errorFlag())
                {
                    QMessageBox::about(this,"Ошибка!","Введенного вами символа нет в словаре, дальнейшее кодирование невозможно!");
                    i=0;
                    auto_start->stop();
                    stop=true;
                }
                else
                {
                ui->output->setText(algo_enc->getTextRezult());

                if(algo_enc->getOneDict()!="")
                    ui->dictionary->append(algo_enc->getOneDict());
                ui->description->setText(algo_enc->getDescription());
                i++;
                algo_enc->setPosition(i);
                if(algo_enc->getCode().flag)
                    result.push_back(algo_enc->getCode());
                algo_dec->setOneCode(algo_enc->getCode());//паралелльно с кодирование, заполняем ин в декодирование
}
            }
        }
    }

    if(ui->chooseDec->isChecked())//если выбран режим декодирования
    {
        if(algo_dec->getPosition()>=result.size())
        {
            QMessageBox::about(this,"!","Декодирование завершено!");
            auto_start->stop();
            disconnect(auto_start, SIGNAL(timeout()), this, SLOT(doNextStep()));
            ui->startButton->setEnabled(true);
            ui->forvard->setEnabled(true);
            ui->begin->setEnabled(true);
            stop=true;
            ui->menu_3->setEnabled(false);
        }
        else
        {
            i=algo_dec->getPosition();

            if(algo_dec->getPosition()<result.size())
            {
                algo_dec->nextStep();
                rez=algo_dec->getResult();
                if (rez[rez.length()-1]=='~')
                    rez.chop(1);
                ui->output->setText(rez);
                if (!algo_dec->getOneDict().isEmpty())
                  {
                    ui->dictionary->append(algo_dec->getOneDict());
                }
                ui->description->setText(algo_dec->getDescription());
                i++;
                algo_dec->setPosition(i);


            }
        }

    }
}

void MainWindow::doClear()
{
    ui->menu_3->setEnabled(true);
    algo_enc->start();
    algo_dec->start();
    ui->input->setText("abracadabra");
    ui->output->clear();
    ui->dictionary->clear();
    ui->description->clear();
    ui->chooseEnc->setChecked(true);
    ui->chooseDec->setChecked(false);
    result.clear();
    stop=false;
    if(ui->chooseAlg->currentIndex()==0)
    {
        algo_enc->initDict();
        algo_dec->initDict();

        QString init="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ1234567890,. !?:;-~";
        QString forDict;

        for (int i=0;i<init.length();i++)
        {
            forDict.clear();
            forDict+=QString::number(i+1);
            forDict+=": ";
            forDict+=init[i];
            ui->dictionary->append(forDict);
        }
    }

}

void MainWindow::doChooseDec()
{
    ui->input->setText(algo_dec->setIn());
    stop=false;
    ui->output->clear();
    ui->dictionary->clear();
    ui->description->clear();
    if(ui->chooseAlg->currentIndex()==0)
    {

        QString init="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ1234567890,. !?:;-~";
        QString forDict;

        for (int i=0;i<init.length();i++)
        {
            forDict.clear();
            forDict+=QString::number(i+1);
            forDict+=": ";
            forDict+=init[i];
            ui->dictionary->append(forDict);
        }
    }

    algo_enc->start();
}

void MainWindow::doChooseEnc()
{
    ui->input->setText(ui->output->toPlainText());
    ui->output->clear();
    ui->dictionary->clear();
    ui->description->clear();
    if(ui->chooseAlg->currentIndex()==0)
    {

        QString init="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ1234567890,. !?:;-~";
        QString forDict;

        for (int i=0;i<init.length();i++)
        {
            forDict.clear();
            forDict+=QString::number(i+1);
            forDict+=": ";
            forDict+=init[i];
            ui->dictionary->append(forDict);
        }
    }
    algo_enc->start();
    algo_dec->start();
}

void MainWindow:: doBackStep()
{
    ui->menu_3->setEnabled(true);
    if (ui->chooseEnc->isChecked())
    {
    if(algo_enc->getOutFlag())
    {
        algo_dec->doClearInForPrevStepEnc();
        result.pop_back();
    }

    algo_enc->prevStep();
    ui->dictionary->clear();
    ui->output->setText(algo_enc->getTextRezult());
    ui->dictionary->append(algo_enc->getDictPrev());
    ui->description->setText(algo_enc->getDescription());
   // ui->textBrowser_3->verticalScrollBar().setValue(0);
    }

    if(ui->chooseDec->isChecked())
    {
        algo_dec->prevStep();
        ui->output->setText(algo_dec->getResult());
        ui->dictionary->clear();
        ui->dictionary->append(algo_dec->getDictPrev());
        ui->description->setText(algo_dec->getDescription());
    }

}

void MainWindow::openQuestionNextCode()
{
    in=ui->input->toPlainText();
    in+="~";
    question *q;
    q = new question(algo_enc, algo_dec, ui->chooseEnc->isChecked(), 1, in, this);
    q->show();
}

void MainWindow:: openQuestionNextDict()
{
    in=ui->input->toPlainText();
    in+="~";
    question *q;
    q = new question(algo_enc, algo_dec, ui->chooseEnc->isChecked(), 2, in, this);
    q->show();
}

void MainWindow::changeAlg(int index)
{
    if (index==0)
    {

        algo_enc = new LZW;
        algo_dec = new LZWDecoding;
    }
    else
            if(index==1)
            {
                algo_enc = new LZ78;
                algo_dec = new LZ78Decoding;
            }


    algo_enc->setPosition(0);
    algo_dec->setPosition(0);

    doClear();
}

void MainWindow::doPause()
{
   auto_start->stop();
   disconnect(auto_start, SIGNAL(timeout()), this, SLOT(doNextStep()));
   ui->startButton->setEnabled(true);
   ui->forvard->setEnabled(true);
   ui->begin->setEnabled(true);
}

void MainWindow::showAbout()
{
    QMessageBox aboutDlg(this);
    aboutDlg.setTextFormat(Qt::RichText);

    aboutDlg.setWindowTitle(tr("О программе"));
    aboutDlg.setText(tr(
                        "Author: <a href=\"mailto:chizhovaig20@gmail.com\">Chizhova Irina</a>, 2021.<br>"
                        "Academic supervisor: <a href=\"mailto:kpushkaryov@sfu-kras.ru\">Kirill Pushkaryov</a>.<br>"
                        "This application is dynamically linked against the "
                        "<a href=\"https://www.qt.io/developers/\">Qt Library</a> "
                        "which is under the LGPLv3 license.<br>"));
    aboutDlg.exec();
}
