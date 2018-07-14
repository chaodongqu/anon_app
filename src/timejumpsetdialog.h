#ifndef TIMEJUMPSETDIALOG_H
#define TIMEJUMPSETDIALOG_H

#include <QDialog>

namespace Ui {
class TimeJumpSetDialog;
}

class TimeJumpSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimeJumpSetDialog(QWidget *parent = nullptr);
    ~TimeJumpSetDialog();

private:
    Ui::TimeJumpSetDialog *ui;
};

#endif // TIMEJUMPSETDIALOG_H
