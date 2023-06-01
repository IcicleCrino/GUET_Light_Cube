#ifndef _PINPU_H_
#define _PINPU_H_
#include"main.h"       //主程序头文件


// 音乐频谱程序


//************************************频谱模式的延时程序************************************
void delayyp(unsigned int n1)
{
    unsigned int xdata i;
    while(n1--)
     for (i=0;i<200;i++);
}
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  读ADC程序  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
unsigned int Read_ADC0()
{
	 ADC_CONTR|=0x08;
	 _nop_();
	 _nop_();
	 _nop_();
	 _nop_();
	 while(!(ADC_CONTR&0x10));
	 ADC_CONTR&=~0x10;
	 return ((ADC_RES<<2)|(ADC_RESL));
}
unsigned int voivol(unsigned int n)
{
	 unsigned int xdata val,result,rel=0;
	 while(n)
	 {
		  val=Read_ADC0();
		  delayyp(2);
		  result=val;
		  rel=rel+result;
		  n--;
	 }
	 return rel;
}
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  频谱程序  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
void Vol_watch_0(unsigned char kxg)
{
	 unsigned int xdata result=0,l=1,n=0;
	 if(start1 == 0){ n=4294967290;}
	 else if(start1 == 1){ n=500;}
	 while(n)
	 {
		  if ((result>>5)>l)
		  l=result>>5;
		  else
		   if (l>1)
		    l--;
		  if (l>7)
		  l=7;
		
		if(kxg==1)
		{
		  box(0,0,0,l,l,l,0,1);
		  result=voivol(16);
		  box(0,0,0,7,7,7,1,0);	  
		}
		if(kxg==2)
		{
		  box(7,7,7,7-l,7-l,7-l,0,1);
		  result=voivol(16);
		  box(7,7,7,7-l,7-l,7-l,1,0); 
		}
		if(kxg==3)
		{  box(7,0,7,0,l,0,0,1);
		  result=voivol(16);
		  box(l,0,l,0,7,0,1,0);	  
		}
		if(kxg==4)
		{    
		  box(l,l,l,7-l,7-l,7-l,0,1);
		  result=voivol(16);
		  box(7-l,7-l,7-l,l,l,l,1,0);	
		}
		if(kxg==5)
		{
		  box(0,7,7,l,7-l,0,0,1);
		  result=voivol(16);
		  box(0,7,7,l,7-l,0,1,0);	 
		}
		if(kxg==7)
		{
		  box(l,0,7,0,7,0,0,1);
		  result=voivol(16);
		  box(7,0,l,0,l,0,1,0);	      
		}
		  n--;
		 yinyue_key2();
		 if(msd != 1){break;}
		if(ping == 1)
		{
			ping = 0;
			break;	
		}					
	 }
}
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  频谱程序  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
void Vol_watch_1(unsigned char kxg1)
{
	 unsigned int xdata result=0,l=0,n=0,saa,sad;
	 unsigned char code disxin[8][8]={
	0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x99, 
	0x00, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xA5, 
	0x00, 0x00, 0x81, 0x81, 0x81, 0x81, 0x81, 0xC3, 
	0x00, 0x00, 0x00, 0x81, 0x81, 0x81, 0x81, 0x81, 
	0x00, 0x00, 0x00, 0x00, 0x81, 0x81, 0x81, 0x81, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x81, 0x99, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xE7, 
	0xFF, 0xC3, 0xA5, 0x81, 0x81, 0xA5, 0xC3, 0xFF, 
	};
	if(start1 == 0){ n=4294967290;}
	 else if(start1 == 1){ n=500;}
	 while(n)
	 {
		  if ((result>>5)>l)
		  l=result>>5;
		  else
		   if (l>0)
		    l--;
		  if (l>7)
		  l=7;
		if(kxg1==1)
		{
		  box(3,3,0,4,4,l,1,1);
		  if (l<7)
		  box(3,3,7,4,4,l+1,1,0);
		  result=voivol(16);		 
		}
		if(kxg1==2)
		{
		  box(2,2,0,5,5,l,1,1);
		  if (l<7)
		  box(2,2,7,5,5,l+1,1,0);
		  result=voivol(16);		 
		}
		if(kxg1==3)
		{
		  box(1,1,0,6,6,l,1,1);
		  if (l<7)
		  box(1,1,7,6,6,l+1,1,0);
		  result=voivol(16);		  
		}
		if(kxg1==4)
		{  
		  box(0,0,0,7,7,l,1,1);
		  if (l<7)
		  box(0,0,7,7,7,l+1,1,0);
		  result=voivol(16);		
		}
		if(kxg1==6)
		{
		  box(0,0,0,1,1,l,1,1);
		  box(3,3,0,4,4,l,1,1);
		  box(7,7,0,6,6,l,1,1);
		  box(7,0,0,6,1,l,1,1);
		  box(0,7,0,1,6,l,1,1);
		  if (l<7)
		  {
		  	  box(0,0,7,1,1,l+1,1,0);	
		      box(3,3,7,4,4,l+1,1,0);
			  box(7,7,7,6,6,l+1,1,0);
			  box(7,0,7,6,1,l+1,1,0);
			  box(0,7,7,1,6,l+1,1,0);
		  }		  
		  result=voivol(16);		 
		}

		if(kxg1==5 || kxg1==7)
		{
		 	for(saa=0;saa<8;saa++)
			{
				for(sad=0;sad<8;sad++)
				{
					display[saa][sad]= disxin[saa][sad];
				}
			}
			if(kxg1 == 5)
			{
				box(3,3,0,4,4,l,1,1);
		    	if (l<7)
		    	box(3,3,7,4,4,l+1,1,0);	
			}
		    if(kxg1 == 7)
			{
				 box(2,2,0,5,5,l,1,1);
		  		 if (l<7)
		  		 box(2,2,7,5,5,l+1,1,0);
			}
		    result=voivol(16);		
		}
		n--;
		yinyue_key2();
		if(msd != 1){break;}
		if(ping == 1)
		{
			ping = 0;
			break;	
		}
	 }
}
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  频谱程序  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
void Vol_watch_2()
{
	 unsigned int xdata result=0,l=0,n=0;
	 if(start1 == 0){ n=4294967290;}
	 else if(start1 == 1){ n=500;}
	 while(n)
	 {
		  if ((result>>5)>l)
		  l=result>>5;
		  else
		   if (l>0)
		    l--;
		  if (l>7)
		  l=7;
		  clear(0);
		  switch(l)
		  {
			   case 0:point(4,4,4,1);break;
			   case 1:box(3,3,3,4,4,4,1,1);break;
			   case 2:box(2,2,2,4,4,4,1,1);break;
			   case 3:box(2,2,2,5,5,5,1,1);break;
			   case 4:box(1,1,1,5,5,5,1,1);break;
			   case 5:box(1,1,1,6,6,6,1,1);break;
			   case 6:box(0,0,0,6,6,6,1,1);break;
			   default:box(0,0,0,7,7,7,1,1);
		  }
		  result=voivol(16);
		  n--;
		  yinyue_key2();
		 if(msd != 1){break;}
		 if(ping == 1)
		 {
			ping = 0;
			break;	
		 }
 	}
}
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  频谱程序  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
void Vol_watch_3()
{
	unsigned int result,l,n=0;
	if(start1 == 0){ n=4294967290;}
	 else if(start1 == 1){ n=500;}
 	while(n)
    {
		  result=voivol(3);
		  l=result>>3;
		  if (l>7)
		  l=7;
		  transss();
		  box_apeak_xy(0,0,0,0,7,l,1,1);
		  delayyp(60);
		  n--;
		  yinyue_key2();
		 if(msd != 1){break;}
		if(ping == 1)
		{
			ping = 0;
			break;	
		}
    }
}

#endif