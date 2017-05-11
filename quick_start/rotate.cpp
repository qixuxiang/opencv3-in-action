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
    imshow("origin image and rotate operation", src_img);//imshow()函数显示图像
    Mat des_img;
    flip(src_img,des_img,1);//1代表水平方向旋转180度
    //flip(src_img,des_img,0);//0代表垂直方向旋转180度
    //flip(src_img,des_img,-1);//-1代表垂直和水平方向同时旋转
    imshow(" after rotate operation", des_img);//imshow()函数显示图像
    waitKey();


    return 0;
}

