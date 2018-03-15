#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include "predict_car.h"

#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
using namespace cv;

void detectAndDisplay( Mat frame );
String face_cascade_name = "cascade.xml";;
CascadeClassifier face_cascade;
CarPredict net;
String window_name = "Capture - Face detection";

int main( int argc, const char** argv )
{
    VideoCapture capture;
    Mat frame;
    //-- 1. Load the cascades
    if( !face_cascade.load( face_cascade_name ) )
        { printf("--(!)Error loading face cascade\n"); return -1; };
    
    //-- 2. Read the video stream
    capture.open( "Car.avi" );
    if ( ! capture.isOpened() ) 
        { printf("--(!)Error opening video capture\n"); return -1; }
    
    
    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            printf(" --(!) No captured frame -- Break!");
            break;
        }
        //-- 3. Apply the classifier to the frame
        detectAndDisplay( frame );
        if( waitKey(0) == 27 ) { break; } // escape
    }


    return 0;
}

void detectAndDisplay( Mat frame )
{
    std::vector<Rect> boards;
    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );
    face_cascade.detectMultiScale( frame_gray, boards, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(60, 60) ,Size(100, 100));
    cout << boards.size() << endl;
    
    for ( size_t i = 0; i < boards.size(); i++ )
    {
        Rect roi = Rect(Point(boards[i].x, boards[i].y), Size(boards[i].width, boards[i].height));
        Mat board = frame(roi);
        net.predict(board);

        if(net.getId() == 0)
        {
            rectangle( frame, cvPoint(cvRound(boards[i].x), cvRound(boards[i].y)),
                    cvPoint(cvRound((boards[i].x + boards[i].width-1)), cvRound((boards[i].y + boards[i].height-1))),
                    Scalar( 220, 20, 60 ), 3, 8, 0);
            putText( frame, to_string(net.getProb()), cvPoint(cvRound(boards[i].x), cvRound(boards[i].y)), 
                    cv::FONT_HERSHEY_COMPLEX, 0.6, Scalar( 220, 20, 60 ), 1, 8);
        }
        else
        {
            rectangle( frame, cvPoint(cvRound(boards[i].x), cvRound(boards[i].y)),
                    cvPoint(cvRound((boards[i].x + boards[i].width-1)), cvRound((boards[i].y + boards[i].height-1))),
                   Scalar( 105, 105, 105 ), 1, 8, 0);
            putText( frame, to_string(net.getProb()), cvPoint(cvRound(boards[i].x), cvRound(boards[i].y)), 
                    cv::FONT_HERSHEY_COMPLEX, 0.4, Scalar( 105, 105, 105 ), 1, 8);
        }
    }
    imshow( window_name, frame );
}