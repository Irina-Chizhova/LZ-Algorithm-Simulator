#ifndef QUESTION_H
#define QUESTION_H

#include <QDialog>
#include <header/algorithmdecoding.h>
#include <header/algorithmencoding.h>
#include <QString>

namespace Ui {
class question;
}

class question : public QDialog
{
    Q_OBJECT

public:
    explicit question(AlgorithmEncoding *enc, AlgorithmDecoding *dec, bool flag_a, int flag_q, QString in, QWidget *parent = 0);
    ~question();
    int flag;
    bool alg;
    AlgorithmEncoding *alg_enc;
    AlgorithmDecoding *alg_dec;

private slots:
    void on_pushButton_clicked();

private:
    Ui::question *ui;
};

#endif // QUESTION_H
