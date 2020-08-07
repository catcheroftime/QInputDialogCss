#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QInputDialog>
#include <QDialogButtonBox>
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDialog(QInputDialog &dialog, const QString &title, const QString &lable_text, const QString text)
{
    dialog.setWindowTitle(title);
    dialog.setInputMode(QInputDialog::InputMode::TextInput);
    dialog.setTextEchoMode(QLineEdit::Normal);
    dialog.setLabelText(lable_text);
    dialog.setOkButtonText(QObject::tr("确定"));
    dialog.setCancelButtonText(QObject::tr("取消"));
    dialog.setFixedSize(350,250);
    dialog.setTextValue(text);
}

void MainWindow::on_ptn_default_clicked()
{
    QInputDialog dialog{this, Qt::WindowCloseButtonHint};
    initDialog(dialog,tr("创建文件夹"), tr("请输入文件夹名称:") );

    QString style = ui->te_default->toPlainText();
    dialog.setStyleSheet(style);

    if(dialog.exec() == QDialog::Accepted)
        qDebug() << dialog.textValue();


}

void MainWindow::on_ptn_new_clicked()
{
    QInputDialog dialog{this, Qt::WindowCloseButtonHint};
    initDialog(dialog,tr("创建文件夹"), tr("请输入文件夹名称:") );

    if (QDialogButtonBox *btn_box =  dialog.findChild<QDialogButtonBox*>() ){
        QString ok_style = ui->te_okbtn->toPlainText();
        btn_box->button(QDialogButtonBox::Ok)->setStyleSheet(ok_style);
        QString cancel_style = ui->te_cancelbtn->toPlainText();
        btn_box->button(QDialogButtonBox::Cancel)->setStyleSheet(cancel_style);
    }

    if (QLineEdit * edit = dialog.findChild<QLineEdit*>()) {
        QString style = ui->te_edit->toPlainText();
        edit->setStyleSheet(style);
    }

    if (QLabel * label = dialog.findChild<QLabel*>()) {
        QString style = ui->te_lable->toPlainText();
        label->setStyleSheet(style);
    }

//    if (QVBoxLayout * layout = dialog.findChild<QVBoxLayout *>() ) {
//        layout->setSpacing(15);
//    }


    if(dialog.exec() == QDialog::Accepted)
        qDebug() << dialog.textValue();
}
