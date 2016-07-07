#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace cv;
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}



MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_Change_file_clicked()
{
    CascadeClassifier face_cascade;
    face_cascade.load("C:\\opencv-2.4.6.1\\data\\haarcascades\\haarcascade_frontalface_alt.xml");
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Images"), "/home/Sample_Pictures",
                                                    tr("Image Files (*.png *.jpg *.bmp)"));
    const std::string file =fileName.toStdString();


    if(!fileName.isEmpty())
    {

        QImage image(fileName);
        Mat mat_image;
        mat_image = imread(file, CV_LOAD_IMAGE_COLOR);
        QImage imgIn = QImage((uchar*) mat_image.data,mat_image.cols,mat_image.rows,mat_image.step,QImage::Format_RGB888);

        std::vector<Rect> faces;
        face_cascade.detectMultiScale( mat_image, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
        // Draw circles on the detected faces

        for( int i = 0; i < faces.size(); i++ ) {

            Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
            ellipse( mat_image, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
        }


        ui->label_pic->setPixmap(QPixmap::fromImage(imgIn));
        QFile f(fileName);
        QString str = f.fileName();
        ui->choosen_image->setHtml(str);

    }
}

void MainWindow::on_Change_directory_clicked()
{

    QString dir = QFileDialog::getExistingDirectory(this, tr("Find Files"), QDir::currentPath());
    ui->dirComboBox ->addItem(dir);




}


