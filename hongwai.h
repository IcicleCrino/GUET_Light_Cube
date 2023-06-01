#ifndef __HONGWAI_H__
#define __HONGWAI_H__

#include"main.h"       //主函数定义

sbit IRIN=P3^2;  	 //红外线信号接口
unsigned char IRCOM[7];

/******************************************************************************************
**********************************红外功能部分*********************************************
*******************************************************************************************/
void IRInit()
{
    EX0 = 1;                //允许总中断中断,使能 INT0 外部中断
    TCON |= 0x01;               //触发方式为脉冲负边沿触发
    IRIN=1;                    //I/O口初始化
    EA = 1;                     //开总中断
	//IP2 = 0xff;
} 
void IRdelay(unsigned char x)         //延时子程序
{
   unsigned char a,b;
   while(x--)
   {
     for(b=6;b>0;b--)
        for(a=127;a>0;a--);
   }
}
void IDelay(unsigned int t)
{
 	while(--t);
}
/*******************红外***************************************/
void IR_IN(void) interrupt 0 
{	   
  	 unsigned char j,k,N=0;   		
     EX0 = 0;
	 IRdelay(15);
	 if (IRIN==1) 
     {
	     EX0 =1;
	     return;
	 } 
                           //确认IR信号出现
     while (!IRIN)            //等IR变为高电平，跳过9ms的前导低电平信号。
     {IRdelay(1);}

     for (j=0;j<4;j++)         //收集四组数据
 	 { 
		  for (k=0;k<8;k++)        //每组数据有8位
		  {
			     while (IRIN)            //等 IR 变为低电平，跳过4.5ms的前导高电平信号。
			     {IRdelay(1);}
			     while (!IRIN)          //等 IR 变为高电平
			     {IRdelay(1);}
			     while (IRIN)           //计算IR高电平时长
			      {
			     IRdelay(1);
			     N++;           
			     if (N>=30)
				 { EX0=1;
				 return;}                  //0.14ms计数过长自动离开。
			      }                        //高电平计数完毕                
			     IRCOM[j]=IRCOM[j] >> 1;                  //数据最高位补“0”
			     if (N>=8) {IRCOM[j] = IRCOM[j] | 0x80;}  //数据最高位补“1”
			     N=0;
		  } 
    } 
   
    if (IRCOM[2]!=~IRCOM[3])
    {
		 EX0=1;
     	return;
	}

    IRCOM[5]=IRCOM[2] & 0x0F;     //取键码的低四位
    IRCOM[6]=IRCOM[2] >> 4;       //右移4次，高四位变为低四位

   if(IRCOM[5]>9)
    { IRCOM[5]=IRCOM[5]+0x37;}
   else
	  IRCOM[5]=IRCOM[5]+0x30;

   if(IRCOM[6]>9)
    { IRCOM[6]=IRCOM[6]+0x37;}
   else
	  IRCOM[6]=IRCOM[6]+0x30;


	 if(IRCOM[2]==0x45)	//动画模式
	 {
		kaiji_flag=0;
	 	dong = 0;
		donghua1 = 0;
		start2 = 1;		
		key2=2;	
		moshi = 1;		  	 
	 }
	  	  
	 if(IRCOM[2]==0x47)  //音乐模式
	 {			
		ping=0;
		pingpu = 0;				
		start1=1;
    key2=1;
		moshi = 2;	
	 }
	 if(IRCOM[2]==0x44)  //电脑上位机模式
	 {
 		moshi = 3;							
		key2=3;		 
	 }
	 
	 if(IRCOM[2]==0x40)	//速度加
	 {
	 	shudu_jia(); //速度加
	 }
	 
	 if(IRCOM[2]==0x43) //文字模式
	 {
		gai = 0;
		gaizi = 0;
		moshi = 4;	
		start3 = 1;						
		key2=4;				
	 }
	 if(IRCOM[2]==0x07) //亮度加
	 {
 		liangdu	= liangdu+40;
		if(liangdu>=400 && liangdu<500){liangdu = 400;}	
	 }
	 if(IRCOM[2]==0x15) //
	 {
	 ;
	 }
	 if(IRCOM[2]==0x09)//亮度减
	 {
 		liangdu	= liangdu-40;
		if(liangdu<=0 || liangdu>500){liangdu = 10;}	
	 }
	 //if(IRCOM[2]==0x16) ; //判断显示 
	 if(IRCOM[2]==0x19)//速度减
	 {
	 	shudu_jian(); //速度减 	
	 }
	 //if(IRCOM[2]==0x0d) ; //判断显示 


	 if(IRCOM[2]==0x0c) //上一个动画 
	 {
	 	if(msd == 2)
		{
			start2=0;dong=1;donghua1--;
			if(donghua1<=0 || donghua1>50)
			{
				donghua1 = 45;	
			}	
		}
	 }
	 if(IRCOM[2]==0x18) //动画还原循环模式
	 {
	 	if(msd == 2)
		{
			start2=1;dong=1;
		}	 		
	 }
	 if(IRCOM[2]==0x5e) //下一个动画
	 {
	 	if(msd == 2)
		{
			start2=0;dong=1;donghua1++;	
			if(donghua1 >= 46)
			{
				donghua1 = 1;
			}
		}
	 }
	 if(IRCOM[2]==0x08) //上一个频谱
	 {
	 	start1 = 0;ping = 1;pingpu--;
		if(pingpu<=0 || pingpu>20)
		{
			pingpu = 15;
		}		
	 }
	 if(IRCOM[2]==0x1c)	//频谱还原循环模式
	 {
	  	start1 = 1;ping = 1;
	 }
	 if(IRCOM[2]==0x5a)	 //下一个频谱
	 {
	 	start1 = 0;ping = 1;pingpu++;
		if(pingpu >= 16)
		{
			pingpu = 1;
		}		
	 }
	 if(IRCOM[2]==0x42)   //上一个文字动画
	 {
	 	if(msd == 4)
		{
			start3 = 0;gai = 1;gaizi--;
			if(gaizi<=0 || gaizi>20)
			{
				gaizi = 4;
			}
		}	
	 }
	 if(IRCOM[2]==0x52)  //改字动画还原循环模式
	 {
	 	if(msd == 4)
		{
			start3 = 1;gai = 1;
		}	 	
	 }
	 if(IRCOM[2]==0x4a)   //下一个文字动画
	 {
	 	if(msd == 4)
		{
			start3 = 0;gai = 1;gaizi++;
			if(gaizi >= 5)
			{
				gaizi = 1;
			}	 
		}	 	
	 }
     EX0 = 1; 
}


#endif