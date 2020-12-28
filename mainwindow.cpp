#include "mainwindow.h"
#include "ui_SaveDialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Qt::WindowFlags m_flags = windowFlags();
    readSettings();
    setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);
    readyData();
    initList();
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

void MainWindow::initList()
{
    ItemModel = new QStandardItemModel(this);

    QSettings *config = new QSettings("./setting.ini", QSettings::IniFormat);
    int size = config->beginReadArray("todoList");
    for(int i = 0; i < size; ++i)
    {
        STTodoItem item;
        config->setArrayIndex(i);
        item.info = config->value("info").toString();
        item.title = "111";
        item.deadLine = config->value("deadLine").toDateTime();

        qDebug() << item.info;
        qDebug() << item.title;
        qDebug() << item.deadLine;

        QStandardItem *item1 = new QStandardItem(config->value("info").toString());
        item1->setData(QVariant::fromValue(item), Qt::UserRole+1);
        ItemModel->appendRow(item1);
    }
    config->endArray();

    if(config)
    {
        delete config;
    }

    ItemDelegate *pItemDelegate = new ItemDelegate(this);
    ui->todolist->setItemDelegate(pItemDelegate);
    ui->todolist->setModel(ItemModel);
}

void MainWindow::readyData()
{

    STTodoItem item;

    item.info = "qqwqqwqwqwqwqq";
    item.deadLine = QDateTime::currentDateTime();
    todoList << item;

    item.info = "sdfasvav";
    item.deadLine = QDateTime::currentDateTime();
    todoList << item;

    item.info = "FdcCwefeagvw";
    item.deadLine = QDateTime::currentDateTime();
    todoList << item;

    item.info = "tevaqgeqthb";
    item.deadLine = QDateTime::currentDateTime();
    todoList << item;

    QSettings *config = new QSettings("./setting.ini", QSettings::IniFormat);
    config->beginWriteArray("todoList");
    for(int i = 0; i < todoList.size(); ++i)
    {
        config->setArrayIndex(static_cast<int>(i));
        config->setValue("info", todoList.at(i).info);
        config->setValue("deadLine", todoList.at(i).deadLine);
    }
    config->endArray();
    config->sync();

    if(config)
    {
        delete config;
    }
}

void MainWindow::slotGrabFullScreen()
{
    QScreen *screen = QGuiApplication::primaryScreen();

    QString filePathName = "/home/fxsh/图片/full-";

    filePathName += QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss-zzz");

    filePathName += ".jpg";

    image = screen->grabWindow(0);
    qDebug() << "width:" << image.size().width() << "height:" << image.size().height() << "depth:" << image.depth()
             << endl;

    if(!image.save(filePathName, "jpg"))

    {

        qDebug() << "save full screen failed" << endl;
    }
}

void MainWindow::on_screenShoot_clicked()
{
    this->setVisible(false);
    QEventLoop loop;                              //定义一个新的事件循环
    QTimer::singleShot(200, &loop, SLOT(quit())); //创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();
    // slotGrabFullScreen();

    QScreen *screen = QGuiApplication::primaryScreen();
    QPixmap image1 = screen->grabWindow(0);

    this->setVisible(true);
    screenSaveDialog dialog(image1, this);
    int ret = dialog.exec();

    //    QString curPath=QCoreApplication::applicationDirPath(); //获取应用程序的路径
    //    QString dlgTitle="保存文件"; //对话框标题
    //    QString filter="Images (*.png *.xpm *.jpg)"; //文件过滤器
    //    QString aFileName=QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);

    // ui->setupUi(this);
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
