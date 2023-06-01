#ifndef _JIANCE_H_
#define _JIANCE_H_
#include"main.h"       //主程序头文件


// 光立方开机检测模式程序
/************************************呼吸灯************************************/
void Delaypwm(unsigned int tpwm)
{
	 while(--tpwm);
}
/************************************呼吸灯************************************/
void PWM_LED()
{
	unsigned int CYCLE=100,PWM_LOW=1110,xhs=60000;
	PWM_POW=0;
	if (xhs>1)
	{
		CYCLE=1950,PWM_LOW=201;
		PWM_POW=1;
		Delaypwm(60000);
		for(PWM_LOW=1;PWM_LOW<CYCLE;PWM_LOW++)
		{
			PWM_POW=0;
			Delaypwm(PWM_LOW);
			PWM_POW=1;
			Delaypwm(CYCLE-PWM_LOW);
		}
		for(PWM_LOW=CYCLE-1;PWM_LOW>0;PWM_LOW--)
		{
			PWM_POW=0;
			Delaypwm(PWM_LOW);
			PWM_POW=1;
			Delaypwm(CYCLE-PWM_LOW);
		}
		xhs--;
	}
}
/************************************扫描一面************************************/
void turn_on(uchar v)
{
	uchar a[64]={0};
	char i,j;
	a[7]=0x80;
		if(key3==1){return;}	
		else{zhen(a,v);}
	delay(50);
	for(i=1;i<8;i++)
	{
		a[i*8+7]=0x80;
		if(key3==1){break;}		
		else{zhen(a,v);}
		delay(50);
	}
	for(i=6;i>=0;i--)
	{
		for(j=0;j<8;j++)
			a[j*8+i]=0x80;
		if(key3==1){break;}		
		else{zhen(a,v);}
		delay(50);
	}	
	for(i=0;i<64;i++)
		a[i]=0;	
	if(dong == 1){dong = 0;return;	}
}
/************************************左向右扫描检测************************************/
void H_scan(uchar v)
{	
	uchar b[64]={0};
	char i,j;
	
 	for(i=0;i<64;i++)
		b[i]=0x80;
	for(i=0;i<8;i++)
	{
		if(kaiji_flag == 0)
		{
			if(key2==1||key2==2||key2==3||key2==4||key2==5)
			{
				msd=2; 
				return;
			}	
		}
		for(j=0;j<8;j++)
		b[j*8+i]=0x80;
		if(key3==1){break;}		
		else{zhen(b,1);}
	}
	for(i=0;i<8;i++)
	{
		if(kaiji_flag == 0)
		{
			if(key2==1||key2==2||key2==3||key2==4||key2==5)
			{
				msd=2; 
				return;
			}	
		}
		for(j=0;j<64;j++)
			b[j]>>=1;
		if(key3==1){break;}		
		else{zhen(b,v);}
		delay(50);
	}
	if(dong == 1){dong = 0;return;	}
}
/************************************下向上扫描检测************************************/
void V_scan(uchar v)
{
	uchar a[64]={0};
	char i,j;
	for(i=0;i<8;i++)
		a[i]=0xff;
	if(kaiji_flag == 0)
	{
		if(key2==1||key2==2||key2==3||key2==4||key2==5)
		{
			msd=2; 
			return;
		}	
	}
	if(key3==1){return;} 
	else{zhen(a,v);}
	delay(50);
	for(i=1;i<8;i++)
	{
		if(kaiji_flag == 0)
		{
			if(key2==1||key2==2||key2==3||key2==4||key2==5)
			{
				msd=2; 
				return;
			}	
		}
		for(j=0;j<8;j++)
		{
			a[i*8+j]=0xff;
			a[(i-1)*8+j]=0;
		}
		if(key3==1){break;}		
		else{zhen(a,v);}
		delay(50);
	}
	if(dong == 1){dong = 0;return;	}
}
/************************************前向后扫描检测************************************/
void W_scan(uchar v)
{
	uchar Miku[64]={
	0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18,	//I
	0x18,0x24,0x42,0x81,0x81,0x99,0x66,0x00,	//空心爱心
	0x81,0x81,0xC3,0x42,0x5A,0x5A,0x24,0x24,	//M
	0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18,	//I
	0x63,0x66,0x6C,0x78,0x78,0x6C,0x66,0x63,	//K
	0x7E,0x7E,0x66,0x66,0x66,0x66,0x66,0x66,	//U
	};
	char i;
	for(i=0;i<6;i++)
	{
		hy(Miku+i*8,v);
		
	}
//	uchar a[64]={0};
//	char i,j;
//	for(i=0;i<8;i++) a[i*7]=apple[7-i];
	if(kaiji_flag == 0)
	{
		if(key2==2)
		{
			msd=2; 
			return;
		}	
	}
	if(key3==1){return;}
	delay(50);
//	for(i=0;i<6;i++)
//	{
//		if(kaiji_flag == 0)
//		{
//			if(key2==1||key2==2||key2==3||key2==4||key2==5)
//			{
//				msd=2; 
//				return;
//			}	
//		}
//		for(j=0;j<8;j++)
//		{
//			a[j*8+i]=apple[7-j];
//			if(j*8+i-1>=0)a[j*8+i-1]=0;
//		}
//		if(key3==1){break;}	 	
//		else{zhen(a,v);}
//		delay(50);
//	}
	M_EN=0;
	if(dong == 1){dong = 0;return;	}
}




#endif