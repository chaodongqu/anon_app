#include "outcontrysetdialog.h"
#include "ui_outcontrysetdialog.h"

OutContrySetDialog::OutContrySetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutContrySetDialog)
{
    ui->setupUi(this);
}

OutContrySetDialog::~OutContrySetDialog()
{
    delete ui;
}
