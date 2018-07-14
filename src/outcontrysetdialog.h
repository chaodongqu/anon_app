#ifndef OUTCONTRYSETDIALOG_H
#define OUTCONTRYSETDIALOG_H

#include <QDialog>

namespace Ui {
class OutContrySetDialog;
}

class OutContrySetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OutContrySetDialog(QWidget *parent = nullptr);
    ~OutContrySetDialog();

private:
    Ui::OutContrySetDialog *ui;
};

#endif // OUTCONTRYSETDIALOG_H
