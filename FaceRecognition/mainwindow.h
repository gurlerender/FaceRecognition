#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QFileInfo>
#include <QString>
#include <QPixmap>
#include <QComboBox>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Change_file_clicked();

    void on_Change_directory_clicked();

private:
    Ui::MainWindow *ui;
    QComboBox *dirComboBox;
};





#endif // MAINWINDOW_H
