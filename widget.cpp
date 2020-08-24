#include "widget.h"
#include "ui_widget.h"
#include "infodialog.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent,Qt::WindowSystemMenuHint | Qt::WindowTitleHint)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}




void Widget::on_provideInfoPushButton_clicked()
{
      InfoDialog * dialog = new InfoDialog(this);

      //Show Dialog Model
   /*   int ret = dialog->exec();

      if(ret == QDialog::Accepted)
      {
          QString position = dialog->getPosition();
          QString chooseOs = dialog->getChooseOS();
          qDebug() << "Dialog Accepted, position is "<<position<<" OS is "<<chooseOs;
          ui->testLabel->setText("Your Position is : " + position + " and your favorite OS is : " + chooseOs );

      }

      if(ret == QDialog::Rejected)
      {
          qDebug() << "Dialog Rejected";
      }*/

      //Show Dialog Non Model

      connect(dialog,&InfoDialog::accepted,[=](){
          QString position = dialog->getPosition();
          QString chooseOs = dialog->getChooseOS();
          qDebug() << "Dialog Accepted, position is "<<position<<" OS is "<<chooseOs;
          ui->testLabel->setText("Your Position is : " + position + " and your favorite OS is : " + chooseOs );
      });

      connect(dialog,&InfoDialog::rejected,[=](){
          qDebug() << "Debug Rejected";
      });

      //Show the dialog
      dialog->show();
      dialog->raise();
      dialog->activateWindow();




}
