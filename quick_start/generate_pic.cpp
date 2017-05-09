#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;//包含cv命名空间
void createAlpha(Mat&);

int main()
{
    Mat mat(480,360,CV_8UC4);//创建带Alpha通道的Mat
    createAlpha(mat);

    vector<int>compression_params;
    compression_params.push_back(IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(9);
    try {
        imwrite("D:\\Alppa.png",mat,compression_params);
        imshow("generated png file", mat);
        fprintf(stdout,"generate a png file in D\n");
    }
    catch (runtime_error& ex){
        fprintf(stderr,"generate file error：%s\n",ex.what());//捕获错误
        return 1;
    }


    return 0;
}
void createAlpha(Mat &mat)
{
    for (int i = 0;i<mat.rows;++i)
    {
        for (int j = 0; j < mat.cols; ++j) {
            Vec4b &rgba = mat.at<Vec4b>(i,j);
            rgba[0] = UCHAR_MAX;
            rgba[1] = saturate_cast<uchar>((float (mat.cols -j))/((float)mat.cols)*UCHAR_MAX);
            rgba[2] = saturate_cast<uchar>((float (mat.cols -i))/((float)mat.cols)*UCHAR_MAX);
            rgba[3] = saturate_cast<uchar> (0.5*(rgba[1]+rgba[2]));

        }
    }

}