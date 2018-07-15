#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void        handleTimeout();  //超时处理函数
    virtual void timerEvent( QTimerEvent *event);

private slots:
    void on_actiontimeset_triggered();

    void on_actionoutset_triggered();

    void on_pushButton_clicked();

    void on_action_triggered();

private:
    void updateNetworkStatus();

private:
    Ui::MainWindow *ui;

    int m_nTimerID;

    int m_StartRunTime ; // 开始计时--运行时间

    int m_UsedNetwork; //  已经使用流量

    int m_IsConnect; // 网络状态


};

#endif // MAINWINDOW_H
