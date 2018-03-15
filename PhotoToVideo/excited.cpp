#include <opencv2/opencv.hpp>

#include <fstream>
#include <iostream>

using namespace cv;
using namespace std;




int main()
{
	string image_folder = "./data/";
	vector<String> filenames;
	String folder(image_folder);
	glob(folder, filenames);

	Mat frame;
	int fps = 3;
	VideoWriter output_dst("Car.avi", CV_FOURCC('M', 'J', 'P', 'G'), fps, Size(640, 480), 1);

	for(size_t i = 0; i < filenames.size(); i++)
	{
		frame = imread(filenames[i]);
		output_dst << frame;
		cout << "Processed: " << i << " : " << filenames.size() << endl;
	}
	

	return 0;

}
