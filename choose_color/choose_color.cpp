#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

void on_mouse(int EVENT, int x, int y, int flags, void *userdata);

int main()
{
	double t;	//���ڼ���֡��
	int fps;	//֡��
	Point point(0, 0); //������ȡ����
	Mat imgOriginal, imgHSV;
	vector<Mat> hsvSplit;
	Mat imgThresholded;

	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		cout << "Cannot open the web cam\n";
		return -1;
	}
	namedWindow("Control", CV_WINDOW_AUTOSIZE);
	int iLowH = 100,			//H�� [0, 180���� S �� [0, 255]�� V �� [0, 255]
		iHighH = 140, 
		iLowS = 90,
		iHighS = 255,
		iLowV = 90,
		iHighV = 255;	//��ɫ
	//int iLowH = 150,		
	//	iHighH = 179,
	//	iLowS = 90,
	//	iHighS = 255,
	//	iLowV = 90,
	//	iHighV = 255;	//��ɫ
	createTrackbar("LowH", "Control", &iLowH, 179);		//Hue (0 - 179)
	createTrackbar("HighH", "Control", &iHighH, 179);
	createTrackbar("LowS", "Control", &iLowS, 255);		//Saturation (0 - 255)
	createTrackbar("HighS", "Control", &iHighS, 255);
	createTrackbar("LowV", "Control", &iLowV, 255);		//Value (0 - 255)
	createTrackbar("HighV", "Control", &iHighV, 255);

	namedWindow("Original", CV_WINDOW_AUTOSIZE);
	setMouseCallback("Original", on_mouse, &point);

	while (true)
	{
		cap >> imgOriginal;
		if (imgOriginal.empty())
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		
		t = (double)getTickCount();
		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);
		split(imgHSV, hsvSplit);
		equalizeHist(hsvSplit[2], hsvSplit[2]);
		merge(hsvSplit, imgHSV);

		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded);
		//������ (ȥ��һЩ���)
		Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
		morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
		//�ղ��� (����һЩ��ͨ��)
		morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
		t = (double)getTickCount() - t;
		fps = getTickFrequency() / t;

		stringstream buf;
		buf << "fps: " << fps << "  HSV: " 
			<< (int)imgHSV.at<Vec3b>(point)[0] << " "
			<< (int)imgHSV.at<Vec3b>(point)[1] << " "
			<< (int)imgHSV.at<Vec3b>(point)[2];

		cout << point.x << " " << point.y << endl;

		string fps_ = buf.str();
		putText(imgOriginal, fps_, Point(20, 40), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3);//��ʾ֡��

		imshow("Thresholded Image", imgThresholded); //show the thresholded image
		imshow("Original", imgOriginal); //show the original image

		char key = (char)waitKey(10);
		if (key == 27)
			break;
	}

	return 0;
}

void on_mouse(int EVENT, int x, int y, int flags, void *userdata)
{
	Point& point = *(Point *)userdata;
	switch (EVENT)
	{
	case EVENT_LBUTTONDOWN:
	{
		point.x = x;
		point.y = y;
		cout << x << " " << y << endl;
	}
	default:
		break;
	}
}