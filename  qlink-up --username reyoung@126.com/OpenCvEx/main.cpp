#include "cv.h"
#include "highgui.h"
#include <QString>
#include <QApplication>
#include <QFileDialog>
int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    CvCapture* capture = cvCreateFileCapture((QFileDialog::getOpenFileName(0,("Get Open File Name"),QDir::currentPath(),"*.mpg *.avi").toStdString().c_str()));
    QString saveFileName = QFileDialog::getSaveFileName(0,("Save"),QDir::currentPath(),"*.mpg");
    double fps = cvGetCaptureProperty(capture,CV_CAP_PROP_FPS);
    CvSize size = cvSize((int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH),(int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT));
    CvVideoWriter *writer =
            cvCreateVideoWriter(saveFileName.toStdString().c_str(),-1,fps,size);
    IplImage* logpolar_frame = cvCreateImage(size,IPL_DEPTH_8U,3);
    IplImage* bgr_frame;
    while( (bgr_frame=cvQueryFrame(capture)) != NULL )
    {
        cvLogPolar( bgr_frame, logpolar_frame,
        cvPoint2D32f(bgr_frame->width/2,
        bgr_frame->height/2),
        40,
        CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS );
        cvWriteFrame( writer, logpolar_frame );
    }
    cvReleaseVideoWriter( &writer );
    cvReleaseImage( &logpolar_frame );
    cvReleaseCapture( &capture );
    return 0;
}
