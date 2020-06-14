#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_SaveDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Qt::WindowFlags m_flags = windowFlags();
    readSettings();
    setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::writeSettings()
{
    QSettings settings;

    settings.beginGroup("MainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();
}

void MainWindow::readSettings()
{
    QSettings settings;
    settings.beginGroup("MainWindow");
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    settings.endGroup();
}


void MainWindow::slotGrabFullScreen()
{
    QScreen *screen = QGuiApplication::primaryScreen();

        QString filePathName = "/home/fxsh/图片/full-";

        filePathName += QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss-zzz");

        filePathName += ".jpg";

        image = screen->grabWindow(0);
        qDebug()<<"width:"<<image.size().width()<<"height:"<<image.size().height()
               <<"depth:"<<image.depth()<<endl;

        if(!image.save(filePathName, "jpg"))

        {

            qDebug()<<"save full screen failed"<<endl;
        }
}

void MainWindow::on_screenShoot_clicked()
{
    this->setVisible(false);
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(200, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();
    //slotGrabFullScreen();

    QScreen *screen = QGuiApplication::primaryScreen();
    QPixmap image1 = screen->grabWindow(0);

    this->setVisible(true);
    screenSaveDialog dialog(image1,this);
    int ret=dialog.exec();

//    QString curPath=QCoreApplication::applicationDirPath(); //获取应用程序的路径
//    QString dlgTitle="保存文件"; //对话框标题
//    QString filter="Images (*.png *.xpm *.jpg)"; //文件过滤器
//    QString aFileName=QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);

    //ui->setupUi(this);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
      writeSettings();
      event->accept();
}

void MainWindow::on_pushButton_2_clicked()
{
    showMinimized();
}

