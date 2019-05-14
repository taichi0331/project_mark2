#include <iostream>
#include <opencv2/opencv.hpp>

#include <stdio.h>


using namespace cv;


int main(){
    
    Mat src = cv::imread("lena.jpg");
    int h = src.rows;
    int w = src.cols;
    Mat out = src.clone();
    
    int cont = 0;
    int r[h*w],g[h*w],b[h*w];
    
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            
            b[cont]   =  src.at<Vec3b>(i, j)[0] ;
            g[cont]   =  src.at<Vec3b>(i, j)[1] ;
            r[cont]   =  src.at<Vec3b>(i, j)[2] ;
            cont++;
            
        }
    
    std::cout<<"cont="<<cont<<std::endl;
    std::cout<<"hw="<<h*w<<std::endl;
    
    int rc,bc,gc;
    
    rc = gc = bc = 0;
    
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            
            if( bc < (h*w) ){
                out.at<Vec3b>(i, j)[0] = b[bc];
                bc++;
                out.at<Vec3b>(i, j)[1] = b[bc];
                bc++;
                out.at<Vec3b>(i, j)[2] = b[bc];
                bc++;
            }
            else if( gc < (h*w)){
                out.at<Vec3b>(i, j)[0] = g[gc];
                gc++;
                out.at<Vec3b>(i, j)[1] = g[gc];
                gc++;
                out.at<Vec3b>(i, j)[2] = g[gc];
                gc++;
            }
            else if( rc < (h*w) ){
                out.at<Vec3b>(i, j)[0] = r[rc];
                rc++;
                out.at<Vec3b>(i, j)[1] = r[rc];
                rc++;
                out.at<Vec3b>(i, j)[2] = r[rc];
                rc++;
            }
            
            
            
        }
    
    

    imshow("jack", out);

    
    waitKey();
    
    
    return 0;
}
