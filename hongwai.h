#ifndef __HONGWAI_H__
#define __HONGWAI_H__

#include"main.h"       //����������

sbit IRIN=P3^2;  	 //�������źŽӿ�
unsigned char IRCOM[7];

/******************************************************************************************
**********************************���⹦�ܲ���*********************************************
*******************************************************************************************/
void IRInit()
{
    EX0 = 1;                //�������ж��ж�,ʹ�� INT0 �ⲿ�ж�
    TCON |= 0x01;               //������ʽΪ���帺���ش���
    IRIN=1;                    //I/O�ڳ�ʼ��
    EA = 1;                     //�����ж�
	//IP2 = 0xff;
} 
void IRdelay(unsigned char x)         //��ʱ�ӳ���
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
/*******************����***************************************/
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
                           //ȷ��IR�źų���
     while (!IRIN)            //��IR��Ϊ�ߵ�ƽ������9ms��ǰ���͵�ƽ�źš�
     {IRdelay(1);}

     for (j=0;j<4;j++)         //�ռ���������
 	 { 
		  for (k=0;k<8;k++)        //ÿ��������8λ
		  {
			     while (IRIN)            //�� IR ��Ϊ�͵�ƽ������4.5ms��ǰ���ߵ�ƽ�źš�
			     {IRdelay(1);}
			     while (!IRIN)          //�� IR ��Ϊ�ߵ�ƽ
			     {IRdelay(1);}
			     while (IRIN)           //����IR�ߵ�ƽʱ��
			      {
			     IRdelay(1);
			     N++;           
			     if (N>=30)
				 { EX0=1;
				 return;}                  //0.14ms���������Զ��뿪��
			      }                        //�ߵ�ƽ�������                
			     IRCOM[j]=IRCOM[j] >> 1;                  //�������λ����0��
			     if (N>=8) {IRCOM[j] = IRCOM[j] | 0x80;}  //�������λ����1��
			     N=0;
		  } 
    } 
   
    if (IRCOM[2]!=~IRCOM[3])
    {
		 EX0=1;
     	return;
	}

    IRCOM[5]=IRCOM[2] & 0x0F;     //ȡ����ĵ���λ
    IRCOM[6]=IRCOM[2] >> 4;       //����4�Σ�����λ��Ϊ����λ

   if(IRCOM[5]>9)
    { IRCOM[5]=IRCOM[5]+0x37;}
   else
	  IRCOM[5]=IRCOM[5]+0x30;

   if(IRCOM[6]>9)
    { IRCOM[6]=IRCOM[6]+0x37;}
   else
	  IRCOM[6]=IRCOM[6]+0x30;


	 if(IRCOM[2]==0x45)	//����ģʽ
	 {
		kaiji_flag=0;
	 	dong = 0;
		donghua1 = 0;
		start2 = 1;		
		key2=2;	
		moshi = 1;		  	 
	 }
	  	  
	 if(IRCOM[2]==0x47)  //����ģʽ
	 {			
		ping=0;
		pingpu = 0;				
		start1=1;
    key2=1;
		moshi = 2;	
	 }
	 if(IRCOM[2]==0x44)  //������λ��ģʽ
	 {
 		moshi = 3;							
		key2=3;		 
	 }
	 
	 if(IRCOM[2]==0x40)	//�ٶȼ�
	 {
	 	shudu_jia(); //�ٶȼ�
	 }
	 
	 if(IRCOM[2]==0x43) //����ģʽ
	 {
		gai = 0;
		gaizi = 0;
		moshi = 4;	
		start3 = 1;						
		key2=4;				
	 }
	 if(IRCOM[2]==0x07) //���ȼ�
	 {
 		liangdu	= liangdu+40;
		if(liangdu>=400 && liangdu<500){liangdu = 400;}	
	 }
	 if(IRCOM[2]==0x15) //
	 {
	 ;
	 }
	 if(IRCOM[2]==0x09)//���ȼ�
	 {
 		liangdu	= liangdu-40;
		if(liangdu<=0 || liangdu>500){liangdu = 10;}	
	 }
	 //if(IRCOM[2]==0x16) ; //�ж���ʾ 
	 if(IRCOM[2]==0x19)//�ٶȼ�
	 {
	 	shudu_jian(); //�ٶȼ� 	
	 }
	 //if(IRCOM[2]==0x0d) ; //�ж���ʾ 


	 if(IRCOM[2]==0x0c) //��һ������ 
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
	 if(IRCOM[2]==0x18) //������ԭѭ��ģʽ
	 {
	 	if(msd == 2)
		{
			start2=1;dong=1;
		}	 		
	 }
	 if(IRCOM[2]==0x5e) //��һ������
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
	 if(IRCOM[2]==0x08) //��һ��Ƶ��
	 {
	 	start1 = 0;ping = 1;pingpu--;
		if(pingpu<=0 || pingpu>20)
		{
			pingpu = 15;
		}		
	 }
	 if(IRCOM[2]==0x1c)	//Ƶ�׻�ԭѭ��ģʽ
	 {
	  	start1 = 1;ping = 1;
	 }
	 if(IRCOM[2]==0x5a)	 //��һ��Ƶ��
	 {
	 	start1 = 0;ping = 1;pingpu++;
		if(pingpu >= 16)
		{
			pingpu = 1;
		}		
	 }
	 if(IRCOM[2]==0x42)   //��һ�����ֶ���
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
	 if(IRCOM[2]==0x52)  //���ֶ�����ԭѭ��ģʽ
	 {
	 	if(msd == 4)
		{
			start3 = 1;gai = 1;
		}	 	
	 }
	 if(IRCOM[2]==0x4a)   //��һ�����ֶ���
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