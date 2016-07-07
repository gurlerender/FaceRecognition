#-------------------------------------------------
#
# Project created by QtCreator 2014-08-11T11:39:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FaceRecognitionI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\\opencv-2.4.6.1\\build-msvc2012\\install\\include
LIBS += -LC:\\opencv-2.4.6.1\\build-msvc2012\\install\\lib \
-lopencv_calib3d246d \
-lopencv_contrib246d \
-lopencv_core246d \
-lopencv_features2d246d \
-lopencv_flann246d \
-lopencv_gpu246d \
-lopencv_highgui246d \
-lopencv_imgproc246d \
-lopencv_legacy246d \
-lopencv_ml246d \
-lopencv_nonfree246d \
-lopencv_objdetect246d \
-lopencv_photo246d \
-lopencv_stitching246d \
-lopencv_superres246d \
-lopencv_ts246d \
-lopencv_video246d \
-lopencv_videostab246d \
