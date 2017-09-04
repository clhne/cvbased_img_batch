#include "opencv2/opencv.hpp"  
#include "iostream"  
#include <fstream>  
using namespace std;
using namespace cv;

int main()
{
	// 定义相关参数  
	const int num = 924;
	char fileName[500];
	char windowName[500];
	string savefile;
	int count = 1;
	cv::Mat srcImage;
	for (int i = 1; i <= num; i++)
	{
		// sprintf读入指定路径下图片序列  
		sprintf_s(fileName, "E:\\projects\\DataSet\\pedestrians128x64_ppm\\per (%d).ppm", i);
		sprintf_s(windowName, "NO%d", i);
		// 按照图像文件名读取  
		savefile = "E:\\projects\\DataSet\\pedestrians128x64_jpg\\" + to_string(count) + ".jpg";
		srcImage = cv::imread(fileName);
		if (!srcImage.data)
		{
			std::cout << "No data!" << std::endl;
			return -1;
		}
		//cv::namedWindow(windowName);
		//cv::imshow(windowName, srcImage);
		count++;

		std::cout << "NO" << i << std::endl;
		imwrite(savefile, srcImage);

	}
	system("pause");
	cv::waitKey(0);
	return 0;
}