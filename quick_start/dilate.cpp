#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;//包含cv命名空间


int main()
{
    Mat src_img = imread("D:\\1.png");//imread()函数载入图像
    //从文件中读入图像，注意图像路径最好不要用相对路径，因为CLion生成的exe不在当前目录下。
    if(src_img.empty())
    {
        fprintf(stderr, "Can not load image\n");//如果读入图像失败，返回错误信息
        return -1;
    }
    //显示图像
    imshow("origin image and dilate operation", src_img);//imshow()函数显示图像
    Mat ele,des_img;
    ele = getStructuringElement(MORPH_RECT,Size(2,2));
    dilate(src_img,des_img,ele);
    imshow(" after dilate operation", des_img);//imshow()函数显示图像
    waitKey();


    return 0;
}

