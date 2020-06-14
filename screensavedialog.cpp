#include "screensavedialog.h"



screenSaveDialog::screenSaveDialog(QPixmap image, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveDialog),
    m_image(image)
{
    ui->setupUi(this);
    ui->imageLabel->setPixmap(m_image.scaled(ui->imageLabel->size()));
    ui->pathLine->setText(QCoreApplication::applicationDirPath() + "/");
}

screenSaveDialog::~screenSaveDialog()
{
    delete ui;
}

QString screenSaveDialog::getFilePath()
{
    return ui->nameLine->text();
}

void screenSaveDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QString filePathName = ui->pathLine->text() + ui->nameLine->text();
    qDebug()<<"filePathName:"<<filePathName<<endl;
    if(!m_image.save(filePathName, "jpg"))
    {
        qDebug()<<"save full screen failed"<<endl;
    }
}

void screenSaveDialog::on_browseButton_clicked()
{
    ui->pathLine->setText(QFileDialog::getSaveFileUrl(this).toString());
}
