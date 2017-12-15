#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

String cascade_name = "cascade4.xml";
CascadeClassifier face_cascade;
string window_name = "Capture - Face detection";


static void ShowHelpText()
{
	cout << "\n\n\t   当前使用的OpenCV版本为：" << CV_VERSION
		<< "功能：实现cascade detect"
		<< "\n\n  ----------------------------------------------------------------------------\n";
}

int main()
{
	VideoCapture capture(0);
	Mat frame;
	double t;//用于计算帧率
	double fps;//帧率
	char ch;//用于退出循环
	if (!capture.isOpened())
	{
		cout << "--(!)Error capture\n";
		return -1;
	}
	capture >> frame;
	int frameCount = 0;

	if (!face_cascade.load(cascade_name))
	{
		cout << "--(!)Error loading\n";
		return -1;
	}

	ShowHelpText();

	while (true)
	{
		capture >> frame;

		if (frame.empty())
		{
			cout << " --(!) No captured frame -- Break!";
			break;
		}
		t = (double)cvGetTickCount();
		frameCount++;

		vector<Rect> faces;
        vector<int> levels;
        vector<double> weights;
		Mat frame_gray;
		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
		equalizeHist(frame_gray, frame_gray);

		face_cascade.detectMultiScale(frame_gray, faces, levels, weights, 1.1, 3, 0 | CASCADE_SCALE_IMAGE, Size(20, 20), Size(200, 200), true);

		for (int i = 0; i < faces.size(); i++)
		{
            stringstream buff;
            buff << i;
            string c = buff.str();
			Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
			ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 2, 8, 0);
            putText(frame, c, Point(faces[i].x, faces[i].y), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3);
            cout << "[" << i << "]" << "weights:" << weights[i] << "\tlevels:" << levels[i] << endl;
        }
        cout << endl;
		t = (double)cvGetTickCount() - t;
		fps = ((double)cvGetTickFrequency()*1000000.) / t;
        
		stringstream buf;
		buf << "fps:" << fps;
		string num = buf.str();
		putText(frame, num, Point(20, 40), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3);




		imshow(window_name, frame);

		ch = waitKey();
		if (ch == 'q')
			break;

	}
	
	return 0;
}
