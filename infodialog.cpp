#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_okPushButton_clicked()
{
    QString userPosition = ui->positionLineEdit->text();

    if(!userPosition.isEmpty())
    {
        position = userPosition;
    }

    if(ui->windowsRadioButton->isChecked())
    {
        chooseOS = "Windows";
    }

    if(ui->linuxRadioButton->isChecked())
    {
        chooseOS = "Linux";
    }

    if(ui->macRadioButton->isChecked())
    {
        chooseOS = "Mac";
    }

    accept();
}

void InfoDialog::on_cancelPushButton_clicked()
{
    reject();
}

QString InfoDialog::getChooseOS() const
{
    return chooseOS;
}

QString InfoDialog::getPosition() const
{
    return position;
}
