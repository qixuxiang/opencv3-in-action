#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;//包含cv命名空间
int main()
{

    Mat src_img = imread("C:\\test.png");//imread()函数载入图像
    //从文件中读入图像，注意图像路径最好不要用相对路径，因为CLion生成的exe不在当前目录下。
    if(src_img.empty())
    {
        fprintf(stderr, "Can not load image\n");//如果读入图像失败，返回错误信息
        return -1;
    }
    //显示图像
    imshow("origin image and erode operation", src_img);//imshow()函数显示图像
    Mat ele = getStructuringElement(MORPH_RECT,Size(15,15));//getStructuringElement返回值定义内核矩阵
    Mat des_img;
    erode(src_img,des_img,ele);//erode函数直接进行腐蚀操作
    imshow("after erode operation",des_img);
    waitKey();//此函数等待按键，按键盘任意键就返回
    return 0;
}