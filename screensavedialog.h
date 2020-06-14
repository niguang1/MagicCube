#ifndef SCREENSAVEDIALOG_H
#define SCREENSAVEDIALOG_H
#include <QDebug>
#include <QWidget>
#include <QDialog>
#include <QFileDialog>
#include "ui_SaveDialog.h"

namespace Ui {
    class SaveDialog;
}

class screenSaveDialog : public QDialog
{
    Q_OBJECT
public:
    explicit screenSaveDialog(QPixmap image, QWidget *parent = nullptr);
    ~screenSaveDialog();

    QString getFilePath();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_browseButton_clicked();

private:
    Ui::SaveDialog *ui;
    QPixmap m_image;
};

#endif // SCREENSAVEDIALOG_H
