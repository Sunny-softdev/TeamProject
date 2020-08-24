#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    QString getPosition() const;

    QString getChooseOS() const;

private slots:
    void on_okPushButton_clicked();

    void on_cancelPushButton_clicked();

private:
    QString position;
    QString chooseOS;
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
