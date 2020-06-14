#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDateTime>
#include <QScreen>
#include <QTimer>
#include <QFileDialog>
#include <QSettings>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include "screensavedialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void writeSettings();
    void readSettings();
public slots:
    void slotGrabFullScreen(void);
private slots:
    void on_screenShoot_clicked();
    void on_pushButton_2_clicked();

protected:
    void closeEvent(QCloseEvent *event)     override;
private:
    Ui::MainWindow *ui;
    QPixmap image;
    QSystemTrayIcon *mSysTrayIcon;
};

#endif // MAINWINDOW_H
