#include "question.h"
#include "ui_question.h"
#include "algorithmdecoding.h"
#include "algorithmEncoding.h"
#include "QString"
#include "QMessageBox"

//работает но я смогла найти ошибку в шаге назад

question::question(AlgorithmEncoding *enc, AlgorithmDecoding *dec, bool flag_a, int flag_q, QString in, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::question)
{
    ui->setupUi(this);

    flag=flag_q;

    if (flag_q==1)
        ui->label->setText("Какое слово будет добавлено следующим в \nвыходную последовательность?");
    if (flag_q==2)
        ui->label->setText("Какое слово будет добавлено в словарь \n следующим?");
    alg_enc=enc;
    enc->setData(in);
    alg_dec=dec;
    alg=flag_a;
}

question::~question()
{
    delete ui;
}

void question::on_pushButton_clicked()
{
    bool out_flag=0;
    int steps=0;
    int i;
    int post=0;
    if (ui->lineEdit->text()=="")
        QMessageBox::about(this,"Erorr","Вы не предоставили ответ!");
    else
    {
        if(flag==1)
        {
            if(alg)
            {   while(!out_flag)
                {
                    i=alg_enc->getPost();
                    alg_enc->nextStep();
                    i++;
                    alg_enc->setPost(i);
                    alg_dec->setOneCode(alg_enc->getCode());
                    steps++;
                    out_flag=alg_enc->getOutFlag();
                }
                if (alg_enc->getOneCodeRes()==ui->lineEdit->text())
                {
                    QMessageBox::about(this,"Поздравляем!","Ответ верный!");
                    for (;steps>0;steps--)
                    {
                        if(alg_enc->getOutFlag())
                            alg_dec->doClearInForPrevStepEnc();
                        alg_enc->prevStep();

                    }
                }
                else
                {
                    QMessageBox::about(this,"Сожалеем!","Ответ неверный!");

                }
            }
            else
            {
                alg_dec->nextStep();
                post=alg_dec->getPost()+1;
                alg_dec->setPost(post);

                if (alg_dec->getOneWord()==ui->lineEdit->text())
                {
                    QMessageBox::about(this,"Поздравляем!","Ответ верный!");
                    alg_dec->prevStep();
                    return;
                }
                else
                {
                    QMessageBox::about(this,"Cожалеем!","Ответ неверный!");
                    alg_dec->prevStep();
                    return;
                }
            }
        }

        else
        {
            if(flag==2)
            {
                if(alg)
                {   while(!out_flag)
                    {
                        i=alg_enc->getPost();
                        alg_enc->nextStep();
                        i++;
                        alg_enc->setPost(i);
                        alg_dec->setOneCode(alg_enc->getCode());
                        steps++;
                        out_flag=alg_enc->getDictFlag();
                    }
                    if (alg_enc->getOneDictWord()==ui->lineEdit->text())
                    {
                        QMessageBox::about(this,"Поздравляем!","Ответ верный!");
                        for (;steps>0;steps--)
                        {
                            if(alg_enc->getOutFlag())
                                alg_dec->doClearInForPrevStepEnc();
                            alg_enc->prevStep();

                        }
                        exec();
                    }
                    else
                    {
                        QMessageBox::about(this,"Сожалеем!","Ответ неверный!");
                        for (;steps>0;steps--)
                        {
                            if(alg_enc->getOutFlag())
                                alg_dec->doClearInForPrevStepEnc();
                            alg_enc->prevStep();

                        }
                        //exec();
                    }
                }
                else
                {
                    if((alg_enc->getName()=="LZW") && (alg_dec->getPost()==0) )
                    {
                    alg_dec->nextStep();
                    post=alg_dec->getPost()+1;
                    alg_dec->setPost(post);
                     }

                    alg_dec->nextStep();
                    post=alg_dec->getPost()+1;
                    alg_dec->setPost(post);

                    if (alg_dec->getOneDictWord()==ui->lineEdit->text())
                    {
                        QMessageBox::about(this,"Поздравляем!","Ответ верный!");
                        alg_dec->prevStep();
                        return;
                    }
                    else
                    {
                        QMessageBox::about(this,"Cожалеем!","Ответ неверный!");
                        alg_dec->prevStep();
                        return;
                    }
                }
            }
        }
    }
}
