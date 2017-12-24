#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

// global variable
static Mat g_img_src;
static Mat g_img_dst;
static Mat g_img_sub;
static bool g_is_rect_inited = false;
static Point g_rect_tl;
static string g_window_name = "image";
const int NUM = 0x3f3f3f3f;

static void help()
{
    cout << "\nThis program is designed to screenshot frame from video.\n"
            "UsageL\n"
            "./screenshot [video_filename|camera_index]\n\n"
            "Example:\n"
            "./screenshot test.mp4\n\n"
            "During execution:\n\tHit space key to write photo. "
            "\n\tHit ESC to quit."
            "\n\tHit 'j' to skip.\n\n"
            "\tUsing OpenCV version" << CV_VERSION << "\n" <<endl;
}

static void onMouse(int event, int x, int y, int, void*)
{
    if (CV_EVENT_LBUTTONDOWN == event)
    {
        g_is_rect_inited = true;
        g_rect_tl = Point(x, y);
    }
    else if (CV_EVENT_MOUSEMOVE == event && g_is_rect_inited)
    {
        g_img_src.copyTo(g_img_dst);
        rectangle(g_img_dst, g_rect_tl, Point(x, y), Scalar_<uchar>::all(200), 3, 8);
        imshow(g_window_name, g_img_dst);
    }
    else if (CV_EVENT_LBUTTONUP == event && g_rect_tl != Point(x, y))
    {
        g_img_src(Rect(g_rect_tl, Point(x, y))).copyTo(g_img_sub);
        imshow("sub image", g_img_sub);
        g_is_rect_inited = false;
    }
}

//调用shell命令
string getCmdRes(const string sc)
{
    FILE* crs = popen(sc.c_str(), "r");	// execute the shell command
    char result[1024] = "0";
    fread(result, sizeof(char), sizeof(result), crs);
    if (NULL != crs)
    {
        fclose(crs);
        crs = NULL;
    }
    std::string res = result;
    return res;
}

int main(int argc, const char** argv)
{
    string sc = "ls image | wc -l";     //shell命令，用于统计目录下文件的数目
    string res = getCmdRes(sc);
    stringstream count_s;
    count_s << res;
    int count;
    count_s >> count;       //得到文件数目，为了使新样本不覆盖老样本



    VideoCapture cap;
    string inputName;
    string fileout;

    help();
    cv::CommandLineParser parser(argc, argv,
                                 "{help h||}"
                                 "{@input||}"    );
    if(parser.has("help"))
    {
        help();
        return 0;
    }
    inputName = parser.get<string>("@input");

    if( inputName.empty() || (isdigit(inputName[0]) && inputName.size() == 1) )
    {
        int c = inputName.empty() ? 0 : inputName[0] - '0';
        if(!cap.open(c))
            cout << "Capture from camera #" <<  c << " didn't work" << endl;
    }
    else if(inputName.size())
    {
        if(!cap.open(inputName))
            cout << "Could not read " << inputName << endl;
    }

    if( !cap.isOpened() )
    {
        cerr << "ERROR: Could not initiate capture" << endl;
        return -1;
    }

    namedWindow(g_window_name, CV_WINDOW_NORMAL);
    setMouseCallback(g_window_name, onMouse, 0);

    for(int i = count; i < NUM; )
    {
        //用于跳帧
        for(int j=0; j<6; j++)
        {
            cap >> g_img_src;
        }


        if (g_img_src.empty())
        {
            cerr << "[ERROR] : please check your image file name." << endl;
            return EXIT_FAILURE;
        }

        stringstream ss;
        ss << "image//" << i << ".jpg";
        fileout = ss.str();
        while (true)
        {
            imshow(g_window_name, g_img_src);
            int c = waitKey(10);
            if ((c & 255) == 32)
            { // 回车
                //destroyAllWindows();
                imwrite(fileout, g_img_sub);
                cout << fileout << " has been written." << endl;
                i++;
                break;
            }
            else if(c == 27)
            {
                cout << "Program exited."<< endl;
                return 0;
            }
            else if(c == 'j')
            {
                break;
            }

        }

    }
    return EXIT_SUCCESS;
}
