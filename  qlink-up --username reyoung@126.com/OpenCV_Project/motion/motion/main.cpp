#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<math.h>
using namespace std;

double costFuncMSE(IplImage *ref,IplImage *cur);
double GetPixel(IplImage *frame,int row,int col);
IplImage* GetRegion(IplImage *frame,int row,int col,int mbSize);
int* minCost(double **costs,int p);
void SetPixel(IplImage *frame,int row,int col,CvScalar scv);
double costFuncMAD(IplImage *ref,IplImage *cur,int mbSize);
double FuncPSNR(double);
double FuncMAD(IplImage *ref,int i,int j,IplImage *cur,int m,int n,int mbSize);
double MAD(double **ref,int i,int j,double  **cur,int m,int n,int mbSize);
double FuncMSE(double **relt,double **cur,int height,int width);

int main()
{
	IplImage *IFrame,*PFrame;
	IFrame=cvLoadImage("mobile_ref.bmp",1);
	PFrame=cvLoadImage("mobile_cur.bmp",1);
	int mbSize=16;
	int p=16;
	int i,j,m,n;
	int refBlockVer,refBlockHor;
	int **vectors;
	
	vectors=new int*[(IFrame->width*IFrame->height)/(mbSize*mbSize)];
	for(i=0;i<(IFrame->width*IFrame->height)/(mbSize*mbSize);i++)
		vectors[i]=new int[2];
	
	for(i=0;i<(IFrame->width*IFrame->height)/(mbSize*mbSize);i++)
		for(j=0;j<2;j++)
			vectors[i][j]=0;


	double **costs;
	costs=new double*[2*p+1];
	for(i=0;i<2*p+1;i++)
		costs[i]=new double[2*p+1];
   
	double **cur;
	cur=new double*[PFrame->height];
	for(i=0;i<PFrame->height;i++)
		cur[i]=new double[PFrame->width];

	double **ref;
	ref=new double*[IFrame->height];
	for(i=0;i<IFrame->height;i++)
		ref[i]=new double[IFrame->width];
   
	for(i=0;i<PFrame->height;i++)
	{
		for(j=0;j<PFrame->width;j++)
		{
         cur[i][j]=GetPixel(PFrame,i,j);
         ref[i][j]=GetPixel(IFrame,i,j);
		}
	}
	
    double **relt;
	relt=new double*[IFrame->height];
	for(i=0;i<IFrame->height;i++)
		relt[i]=new double[IFrame->width];

int ii,jj;
   int height=IFrame->height;
	int width=IFrame->width;
	int mbCount=0;
	int *dxy=new int[3] ;
	/*FILE *fp=fopen("out.txt","w");*/
   double min;

	for(i=0;i<height;i=i+mbSize)
	{
		for(j=0;j<width;j=j+mbSize)
		{
			/*for(ii=0;ii<2*p+1;ii++){
				for(jj=0;jj<2*p+1;jj++){
			costs[ii][jj]=1000000;
				}}*/
          min=10000;
			for(m=-p;m<=p;m++)
			{
				for(n=-p;n<=p;n++)
				{
					refBlockVer=i+m;
					refBlockHor=j+n;
				
					if(refBlockVer>=0 && refBlockHor>=0 && refBlockVer+mbSize<=height && refBlockHor+mbSize<=width)
					{
						costs[m+p][n+p]=MAD(ref,refBlockVer,refBlockHor,cur,i,j,  mbSize);
					  
						//costs[m+p][n+p]=FuncMAD(IFrame,refBlockVer,refBlockHor,PFrame,i,j,mbSize);
						//costs[m+p][n+p]=costFuncMAD(GetRegion(IFrame,refBlockHor,refBlockVer,mbSize),GetRegion(PFrame,j,i,mbSize),mbSize);
						if(costs[m+p][n+p]<min){min=costs[m+p][n+p];dxy[1]=m;dxy[0]=n;} 
					}
		
					
				}
			}
          // dxy=minCost(costs,p);

		
			 vectors[mbCount][0]= dxy[1];    
            vectors[mbCount][1]= dxy[0]; 
			


mbCount++;
		}
	}

	CvScalar scv;
	IplImage *tmp;
	IplImage *result=cvCreateImage(cvGetSize(IFrame),IFrame->depth,IFrame->nChannels);

	mbCount=0;
	for(i=0;i<IFrame->height;i+=mbSize){
		for(j=0;j<IFrame->width;j+=mbSize){
			for(m=0;m<mbSize;m++){
				for(n=0;n<mbSize;n++){
					scv=cvGet2D(IFrame,vectors[mbCount][0]+i+m,vectors[mbCount][1]+n+j);
					relt[i+m][j+n]=scv.val[0];
		    SetPixel(result,i+m,j+n,scv);
				}
			}
			mbCount++;
		}
	}

	cvSaveImage("result1.bmp",result);
   cvNamedWindow("RESULT",1);
   cvMoveWindow("RESULT",250,250);
   cvShowImage("RESULT",result);
	cout<<"Full Search PSNR="<<FuncPSNR(FuncMSE(relt,cur,result->height,result->width))<<endl;
	//cout<<"psnr="<<FuncPSNR(costFuncMSE(result,PFrame))<<endl;




cvWaitKey(0);
return 0;
}
	
double costFuncMSE(IplImage *ref,IplImage *cur)
{

	double err=0.0;
	double cost=0;
	int i,j;

	for(i=0;i<ref->height;i++)
	{
		for(j=0;j<ref->width;j++)
		{
			
			err=err+(GetPixel(ref,i,j)-GetPixel(cur,i,j))*(GetPixel(ref,i,j)-GetPixel(cur,i,j));
			
		}
	}
	cost=((double)err/(ref->width*ref->height));

  return cost;
}

double GetPixel(IplImage *frame,int row,int col)
{
	CvScalar scv;
	scv=cvGet2D(frame,row,col);
    return scv.val[0];
}




void SetPixel(IplImage *frame,int row,int col,CvScalar scv)
{
	/*CvScalar scv;*/
	cvSet2D(frame,row,col,scv);
    //return scv.val[0];
}
IplImage* GetRegion(IplImage *frame,int row,int col,int mbSize)
{
	CvRect r=cvRect(row,col,mbSize,mbSize);
	cvSetImageROI(frame,r);
	IplImage *tmp=cvCreateImage(cvGetSize(frame),frame->depth,frame->nChannels);
	cvCopy(frame,tmp,NULL);
	cvResetImageROI(frame);
	//std::cout<<tmp->height<<std::endl;
	//std::cout<<tmp->width<<std::endl;
return tmp;
}

int* minCost(double **costs,int p)
{
	double min=1000000;
	int i,j;
	int dx,dy;
	int *dxy=new int[3];
	for(i=0;i<2*p+1;i++)
	{
		for(j=0;j<2*p+1;j++)
		{
		/*	std::cout<<"costs="<<costs[i][j]<<std::endl;*/
			if(costs[i][j]<min)
			{
				min=costs[i][j];

				dx=j;
				dy=i;
			}
		}
	}
	/*std::cout<<"dx="<<dx<<",dy="<<dy<<std::endl;*/

   dxy[0]=dx;
   dxy[1]=dy;
   dxy[2]=min;
//system("pause");
   return dxy;
}


double costFuncMAD(IplImage *ref,IplImage *cur,int mbSize)
{
static int time=0;
	double err=0.0;
	double cost=0;
	int i,j;
//cout<<GetPixel(ref,0,1)<<endl;
//cout<<GetPixel(cur,0,1)<<endl;
//system("pause");
	for(i=0;i<mbSize;i++)
	{
		for(j=0;j<mbSize;j++)
		{
		
			err+=abs((double)((double)GetPixel(ref,i,j)-(double)GetPixel(cur,i,j)));
			
		}
	}
  cost=((double)err/(mbSize*mbSize));

  return cost;
}

double FuncPSNR(double MSE){

	return 10*log10((double)255*255/MSE);



}

double FuncMAD(IplImage *ref,int i,int j,IplImage *cur,int m,int n,int mbSize)
{
double err=0;
int l,k;
//cout<<"=============="<<endl;
//cout<<"i,j="<<i<<","<<j<<endl;
//cout<<"m,n="<<m<<","<<n<<endl;
//system("pause");
	for(l=0;l<mbSize;l++){
		for(k=0;k<mbSize;k++){
//cout<<"i,j="<<i<<","<<j<<endl;
//cout<<"m,n="<<m<<","<<n<<endl;
//system("pause");
        err+=abs((double)GetPixel(ref,i+l,j+k)-GetPixel(cur,m+l,n+k));

		}
	}
err/=(mbSize*mbSize);
//cout<<err<<endl;
//system("pause");
return err;
}

double MAD(double **ref,int i,int j,double  **cur,int m,int n,int mbSize)
{
double err=0;
int l,k;

	for(l=0;l<mbSize;l++){
		for(k=0;k<mbSize;k++){
			err+=abs(ref[i+l][j+k]-cur[m+l][n+k]);
        //err+=abs((double)GetPixel(ref,i+l,j+k)-GetPixel(cur,m+l,n+k));

		}
	}
err/=(mbSize*mbSize);
//cout<<err<<endl;
//system("pause");
return err;
}


double FuncMSE(double **relt,double **cur,int height,int width)
{

	double err=0.0;
	double cost=0;
	int i,j;

	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			
			err=err+pow((double)(relt[i][j]-cur[i][j]),(double)2);
			
		}
	}
	cost=((double)err/(width*height));

  return cost;
}