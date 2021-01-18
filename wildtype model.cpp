# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <iostream> 


# define	m_N		22           //the number of variables
# define	k_N		38           //the number of parameter 
# define    h       0.00001      //time step


double	s_ode (double m[m_N], double kk[k_N])  //Runge-kutta method solve ODE

{
	double x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20,x21;
	
	double a[m_N][4];
	
	double dm[m_N];
	int i;
	
	x0=m[0];x1=m[1];x2=m[2];x3=m[3];x4=m[4];x5=m[5];x6=m[6];x7=m[7];x8=m[8];x9=m[9];x10=m[10];x11=m[11];x12=m[12];x13=m[13];x14=m[14];x15=m[15];x16=m[16];x17=m[17];x18=m[18];x19=m[19];x20=m[20];x21=m[21];
  
for(i = 0;i < 4;i++)  
        { 
		 
        //wild-type model
        dm[0] = -kk[0]*x0*x4+kk[1]*x5+kk[9]*x10-kk[13]*x0*x3+kk[14]*x12+kk[15]*x12-kk[16]*x0*x8+kk[17]*x7+kk[27]*x17+kk[29]-kk[31]*x0; //PhoQ   
        dm[1] = kk[3]*x6-kk[7]*x1*x2+kk[8]*x10-kk[31]*x1;  //P-PhoQ
        dm[2] = -kk[4]*x6*x2+kk[5]*x9-kk[7]*x1*x2+kk[8]*x10+kk[12]*x11+kk[15]*x12+kk[26]*x17+kk[28]-kk[30]*x2;  //PhoP
        dm[3] = kk[6]*x9+kk[9]*x10-kk[10]*x7*x3+kk[11]*x11-kk[13]*x0*x3+kk[14]*x12-kk[30]*x3;  //P-PhoP
        dm[4] = -kk[0]*x0*x4+kk[1]*x5+kk[18]*x8*x13-kk[19]*x4;  //ATP
        dm[5] = kk[0]*x0*x4-kk[1]*x5-kk[2]*x5-kk[31]*x5;  //PhoQ-ATP
        dm[6] = kk[2]*x5-kk[3]*x6-kk[4]*x6*x2+kk[5]*x9-kk[31]*x6;  //P-PhoQ-ADP
        dm[7] = kk[6]*x9-kk[10]*x7*x3+kk[11]*x11+kk[12]*x11+kk[16]*x0*x8-kk[17]*x7-kk[31]*x7;  //PhoQ-ADP
        dm[8] = kk[3]*x6-kk[16]*x0*x8+kk[17]*x7-kk[18]*x8*x13+kk[19]*x4;  //ADP
        dm[9] = kk[4]*x6*x2-kk[5]*x9-kk[6]*x9-kk[31]*x9;  //P-PhoQ-ADP-PhoP
        dm[10] = kk[7]*x1*x2-kk[8]*x10-kk[9]*x10-kk[31]*x10;  //P-PhoQ-PhoP
        dm[11] = kk[10]*x7*x3-kk[11]*x11-kk[12]*x11-kk[31]*x11;  //PhoQ-ADP-P-PhoP
        dm[12] = kk[13]*x0*x3-kk[14]*x12-kk[15]*x12-kk[31]*x12;  //PhoQ-P-PhoP
		dm[13] = kk[12]*x11+kk[15]*x12-kk[18]*x8*x13+kk[19]*x4;  //Pi
        dm[15] = kk[20]*x3*x14-kk[21]*x15;  //p_1
        dm[16] = kk[22]*x2*x14-kk[23]*x16;  //p_2
		dm[17] = kk[24]*x15-kk[25]*x17;     //mRNA
		dm[19] = kk[32]*x3*x18-kk[33]*x19;  //p_1'
		dm[20] = kk[34]*x2*x18-kk[35]*x20;  //p_2'
		dm[21] = kk[36]*x19-kk[37]*x21;     //mRNA_((pmrD))
     
           
            
            a[0][i] = dm[0];  
            a[1][i] = dm[1];  
            a[2][i] = dm[2];  
            a[3][i] = dm[3];  
            a[4][i] = dm[4];  
            a[5][i] = dm[5];
			a[6][i] = dm[6];  
            a[7][i] = dm[7];  
            a[8][i] = dm[8];  
            a[9][i] = dm[9];  
            a[10][i] = dm[10];  
            a[11][i] = dm[11]; 
			a[12][i] = dm[12];  
            a[13][i] = dm[13]; 
            a[15][i] = dm[15]; 
			a[16][i] = dm[16];  
            a[17][i] = dm[17]; 
			a[19][i] = dm[19];  
			a[20][i] = dm[20];  
            a[21][i] = dm[21]; 
		
            
              
            if(i==0||i==1)  
            {  
    
				
                x0 = m[0]+h*a[0][i]/2;  
                x1 = m[1]+h*a[1][i]/2;  
                x2 = m[2]+h*a[2][i]/2;   
				x3 = m[3]+h*a[3][i]/2;  
                x4 = m[4]+h*a[4][i]/2;  
                x5 = m[5]+h*a[5][i]/2; 
                x6 = m[6]+h*a[6][i]/2;  
                x7 = m[7]+h*a[7][i]/2;  
                x8 = m[8]+h*a[8][i]/2;   
				x9 = m[9]+h*a[9][i]/2;  
                x10 = m[10]+h*a[10][i]/2;  
                x11 = m[11]+h*a[11][i]/2; 
				x12 = m[12]+h*a[12][i]/2; 
				x13 = m[13]+h*a[13][i]/2; 
                x15 = m[15]+h*a[15][i]/2; 
				x16 = m[16]+h*a[16][i]/2;  
                x17 = m[17]+h*a[17][i]/2; 
				x19 = m[19]+h*a[19][i]/2; 
            	x20 = m[20]+h*a[20][i]/2;  
                x21 = m[21]+h*a[21][i]/2; 
				
              
			
            }  
              
            if(i==2)  
            {  
     
				
				
				x0 = m[0]+h*a[0][i];  
                x1 = m[1]+h*a[1][i];  
                x2 = m[2]+h*a[2][i];   
				x3 = m[3]+h*a[3][i];  
                x4 = m[4]+h*a[4][i];  
                x5 = m[5]+h*a[5][i]; 
                x6 = m[6]+h*a[6][i];  
                x7 = m[7]+h*a[7][i];  
                x8 = m[8]+h*a[8][i];   
				x9 = m[9]+h*a[9][i];  
                x10 = m[10]+h*a[10][i];  
                x11 = m[11]+h*a[11][i]; 
				x12 = m[12]+h*a[12][i];
				x13 = m[13]+h*a[13][i];
                x15 = m[15]+h*a[15][i];
				x16 = m[16]+h*a[16][i];  
                x17 = m[17]+h*a[17][i]; 
				x19 = m[19]+h*a[19][i]; 
				x20 = m[20]+h*a[20][i];  
                x21 = m[21]+h*a[21][i]; 
			
               
              
            }  
      
        }  

m[0] = m[0]+h*(a[0][0]+2*a[0][1]+2*a[0][2]+a[0][3])/6;  
m[1] = m[1]+h*(a[1][0]+2*a[1][1]+2*a[1][2]+a[1][3])/6;  
m[2] = m[2]+h*(a[2][0]+2*a[2][1]+2*a[2][2]+a[2][3])/6;
m[3] = m[3]+h*(a[3][0]+2*a[3][1]+2*a[3][2]+a[3][3])/6;  
m[4] = m[4]+h*(a[4][0]+2*a[4][1]+2*a[4][2]+a[4][3])/6;  
m[5] = m[5]+h*(a[5][0]+2*a[5][1]+2*a[5][2]+a[5][3])/6;
m[6] = m[6]+h*(a[6][0]+2*a[6][1]+2*a[6][2]+a[6][3])/6;  
m[7] = m[7]+h*(a[7][0]+2*a[7][1]+2*a[7][2]+a[7][3])/6;  
m[8] = m[8]+h*(a[8][0]+2*a[8][1]+2*a[8][2]+a[8][3])/6;
m[9] = m[9]+h*(a[9][0]+2*a[9][1]+2*a[9][2]+a[9][3])/6;  
m[10] = m[10]+h*(a[10][0]+2*a[10][1]+2*a[10][2]+a[10][3])/6;  
m[11] = m[11]+h*(a[11][0]+2*a[11][1]+2*a[11][2]+a[11][3])/6;
m[12] = m[12]+h*(a[12][0]+2*a[12][1]+2*a[12][2]+a[12][3])/6; 
m[13] = m[13]+h*(a[13][0]+2*a[13][1]+2*a[13][2]+a[13][3])/6;
m[15] = m[15]+h*(a[15][0]+2*a[15][1]+2*a[15][2]+a[15][3])/6;  
m[16] = m[16]+h*(a[16][0]+2*a[16][1]+2*a[16][2]+a[16][3])/6;
m[14] = 1-m[15]-m[16];  //p_0
m[17] = m[17]+h*(a[17][0]+2*a[17][1]+2*a[17][2]+a[17][3])/6;
m[19] = m[19]+h*(a[19][0]+2*a[19][1]+2*a[19][2]+a[19][3])/6; 
m[20] = m[20]+h*(a[20][0]+2*a[20][1]+2*a[20][2]+a[20][3])/6;
m[18] = 1-m[19]-m[20];  //p_0'
m[21] = m[21]+h*(a[21][0]+2*a[21][1]+2*a[21][2]+a[21][3])/6;

return 0;
}



int main()
{
	
   
	FILE *fp;

    fp=fopen("wildtype .txt","w");

    //Initial values of each variables
	double m[m_N]={0.492, 0,  2.6, 0, 975,  0, 0, 0, 125, 0, 0, 0, 0, 25, 0.6, 0, 0.4, 0, 0.86, 0, 0.14, 0};  
	//parameters at 10 mM Mg2+
    double kk[k_N]={    0,   0.0093,	    67.44,	    17.52,	    1.28,	    0.015,	    1.7,	    21.62,       0.000105,	 51.39,	     0.047,	     0.0044,	2.08,	    0.037, 	     0.00155,	   0.000403,     0,         0.018,	     0.0024,	    0.00764,     0.4,	  0.7,	   0.3,  	1.2,     1.2,0.36,0.26,0.00058,0.033,0.00044,      0.0126,     0.00089,      0.162,	 0.072,	0.00006,	  0.001,	0.021,	  0.20 };
	//parameters at 50 ��M Mg2+
	double kk1[k_N]={0.057,   0.0093,	    67.44,	    17.52,	    1.28,	    0.015,	    1.7,	    21.62,       0.000105,	 51.39,	     0.047,	     0.0044,	2.08,	    0.037, 	     0.00155,	   0.000403,     0.0082,    0.018,	     0.0024,	    0.00764,     0.4,	  0.7,	   0.3,  	1.2,     1.2,0.36,0.26,0.00058,0.033,0.00044,      0.0126,     0.00089,      0.162,	 0.072,	0.00006,	  0.001,	0.021,	  0.20 };
		
	double t;
	int j;
	
	
	for(t=0;t<=5000;t+=h)  //the model reach to steady state at 10 mM Mg2+
{
		m[m_N]=s_ode(m,kk);
}


    for(t=-5;t<0;t+=0.01)  //the steady state of the model at 10 mM Mg2+
{
	fprintf(fp,"%lf %lf %lf  %lf  %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",t,m[0],m[1],m[2],m[3],m[4],m[5],m[6],m[7],m[8],m[9],m[10],m[11],m[12],m[13],m[14],m[15],m[16],m[17],m[18],m[19],m[20],m[21]);
	
	for(j=0;j<1000;j++)
{
	m[m_N]=s_ode(m,kk);
}
}
    

    
    for(t=0;t<=1000;t+=0.01)   //the change of the model at 50 ��M Mg2+
{
	fprintf(fp,"%lf %lf %lf  %lf  %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",t,m[0],m[1],m[2],m[3],m[4],m[5],m[6],m[7],m[8],m[9],m[10],m[11],m[12],m[13],m[14],m[15],m[16],m[17],m[18],m[19],m[20],m[21]);
	
	for(j=0;j<1000;j++)
{
	m[m_N]=s_ode(m,kk1);
}
}
  
	
     fclose(fp);
     return 0;
}  





