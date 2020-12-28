#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QDateTime>
#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QScreen>
#include <QSettings>
#include <QStandardItemModel>
#include <QSystemTrayIcon>
#include <QTimer>
#include "screensavedialog.h"

#include <QListWidgetItem>
#include "ItemDelegate.h"
#include "common.h"

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
    void initList();
    void readyData();
public slots:
    void slotGrabFullScreen(void);
private slots:
    void on_screenShoot_clicked();
    void on_pushButton_2_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QSystemTrayIcon *mSysTrayIcon;

    QStandardItemModel *ItemModel;

    QList<STTodoItem> todoList;
};

#endif // MAINWINDOW_H
