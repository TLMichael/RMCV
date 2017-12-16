#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

Rect box;
bool drawingBox = false;
bool gotBB = false;

void onMouse(int event, int x, int y, int flags, void *param)
{
    switch(event)
    {
        case CV_EVENT_MOUSEMOVE:
            if (drawingBox)
            {
                box.width = x - box.x;
                box.height = y - box.y;
            }
            break;
        case CV_EVENT_LBUTTONDOWN:
            drawingBox = true;
            box = Rect(x, y, 0, 0);
            break;
        case CV_EVENT_LBUTTONUP:
            drawingBox = false;
            if(box.width < 0)
            {
                box.x +=box.width;
                box.width *= -1;
            }
            if(box.height < 0)
            {
                box.y += box.height;
                box.height *= -1;
            }
            gotBB = true;
            break;
    }
}

void tracking(Mat frame, Mat &model, Rect &trackBox)
{
    Mat gray;
    cvtColor(frame, gray, CV_RGB2GRAY);

    Rect searchWindow;
    searchWindow.width = trackBox.width * 3;
    searchWindow.height = trackBox.width * 3;
    searchWindow.x = trackBox.x + trackBox.width * 0.5 - searchWindow.width * 0.5;
    searchWindow.y = trackBox.y + trackBox.height * 0.5 - searchWindow.height * 0.5;
    searchWindow &= Rect(0, 0, frame.cols, frame.rows);

    Mat similarity;
    matchTemplate(gray(searchWindow), model, similarity, CV_TM_CCOEFF_NORMED);

    double mag_r;
    Point point;
    minMaxLoc(similarity, 0, &mag_r, 0, &point);
    trackBox.x = point.x + searchWindow.x;
    trackBox.y = point.y + searchWindow.y;
    model = gray(trackBox);
}

int main(int argc, char * argv[])
{
    VideoCapture capture;
    capture.open(0);

    if(!capture.isOpened())
    {
        cout << "capture device failed to open!" << endl;
        return -1;
    }
    cvNamedWindow("Tracker", CV_WINDOW_AUTOSIZE);
    cvSetMouseCallback("Tracker", onMouse, NULL);

    Mat frame, model;
    capture >> frame;
    while (!gotBB)
    {
        capture >> frame;

        imshow("Tracker", frame);
        if (cvWaitKey(20) == 'q')
            return 1;
    }
    cvSetMouseCallback("Tracker", NULL, NULL);

    Mat gray;
    cvtColor(frame, gray, CV_RGB2GRAY);
    model = gray(box);

    int frameCount = 0;

    while (1)
    {
        capture >> frame;
        if (frame.empty())
            return -1;
        double t = (double)cvGetTickCount();
        frameCount++;

        // tracking
        tracking(frame, model, box);

        // show
        stringstream buf;
        buf << frameCount;
        string num = buf.str();
        putText(frame, num, Point(20, 20), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3);
        rectangle(frame, box, Scalar(0, 0, 255), 3);
        imshow("Tracker", frame);


        t = (double)cvGetTickCount() - t;
        cout << "cost time: " << t / ((double)cvGetTickFrequency()*1000.) << endl;

        if (cvWaitKey(1) == 27)
            break;
    }

    return 0;
}