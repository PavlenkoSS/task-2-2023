#include "matrlib.h"


using namespace std;

int main()
{	
	//double pi = 3.1415926535;
	double e = 2.718281828;
	matrix res1(3,4);
	matrix res2(3,4);
	matrix res3(3,4);
	matrix res4(3,4);
	matrix res5(3,4);
	matrix res6(3,4);
	double n[4];
	n[0]=1;
	n[1]=2;
	n[2]=3;
	n[3]=6;
	double A[3];
	A[0] = 1;
	A[1] = 10;
	A[2] = 1000;
	for(int i=0; i < 3;i++)
	{
		double a = A[i];
		for(int j=0;j<4;j++)
		{
			double h = pow(0.1, n[j]);
			double y1_0 = 1, y2_0 = 1 , y3_0 = 1, y4_0 = 1,y5_0 = 1,y6_0 = 1; 
			double y4_1 = 1-a*h, y5_1 = 1-a*h,y6_1 = 1-a*h;
			double X = 0;
			double y1,y2,y3,y4,y5,y6;
			double max1 = 0;
			double max2 = 0;
			double max3 = 0; 
			double max4 = 0;
			double max5 = 0;
			double max6 = 0;
			while(X<1)
			{
				y1 = (1-h*a)*y1_0;
				if(abs(y1 - a*pow(e,X) > max1 ))
					max1 = abs(y1 - a*pow(e,X));
				y1_0 = y1;

				y2 = y2_0/(1+h*a);
				if(abs(y2 - a*pow(e,X) > max2 ))
					max2 = abs(y2 - a*pow(e,X));
				y2_0 = y2;

				y3 = (2-h*a)*y3_0/(2+h*a);
				if(abs(y3 - a*pow(e,X) > max3 ))
					max3 = abs(y3 - a*pow(e,X));
				y3_0 = y3;

				y4 = y4_0 - 2*h*a*y4_1;
				if(abs(y4 - a*pow(e,X) > max4 ))
					max4 = abs(y4 - a*pow(e,X));
				y4_0 = y4_1;
				y4_1 = y4;

				y5 = (2*y5_1-0.5*y5_0)/(1.5+h*a);
				if(abs(y5 - a*pow(e,X) > max5))
					max5 = abs(y5 - a*pow(e,X));
				y5_0 = y5_1;
				y5_1 = y5;

				y6 = 4*y6_1+(a*h-3)*y6_0;
				if(abs(y6 - a*pow(e,X) > max6))
					max6 = abs(y6 - a*pow(e,X));
				y6_0 = y6_1;
				y6_1 = y6;
				X += h;
			}
			res1.SetMij(j,i,max1);
			res2.SetMij(j,i,max2);
			res3.SetMij(j,i,max3);
			res4.SetMij(j,i,max4);
			res5.SetMij(j,i,max5);
			res6.SetMij(j,i,max6);
		}
	}
	res1.print_mat();
	res2.print_mat();
	res3.print_mat();
	res4.print_mat();
	res5.print_mat();
	res6.print_mat();
	return 0;
}
