#include "timejumpsetdialog.h"
#include "ui_timejumpsetdialog.h"

TimeJumpSetDialog::TimeJumpSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeJumpSetDialog)
{
    ui->setupUi(this);
}

TimeJumpSetDialog::~TimeJumpSetDialog()
{
    delete ui;
}
