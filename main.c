#include "STC12C5A.H"  //单片机头文件
#include "intrins.h"   //包含NOP延时头文件
#include "main.h"       //主程序头文件
#include "shuju.h"     //包含字模数据数组
#include "flash.h"      //动画部分程序
#include "hongwai.h"    //红外部分程序
#include "key.h"        //按键部分程序
#include "pinpu.h"      //音乐频谱部分程序
#include "jiance.h"     //开机检测模式程序
#include "moshi.h"      //模式控制程序	  

uchar xdata display[8][8];
uchar data msd=0;
uint ld=700;
uchar data key2=0,key3=0; 
uchar data xsdsq=0; 
uchar data sj_read_flag=0;  
uchar data read_flag=0;     //电脑上位机读标记
uchar data cnt=0;
uchar data cot=0;
uchar data cd=0,layerr=0,saom=0;
uint liangdu = 400;	  //亮度
uint donghua_shudu=500;   //动画速度调节 
int date=0;	 //串口2数据
bit busy = 0; //串口判断标记
uchar data moshi=0; // 模式
bit start3 = 0; //旋转字母模式标记
bit key1=0;
uchar data abc_falg=0;       //旋转字母标记
bit start1=1;//频谱选择标记
uchar data ping=2;	//频谱选择标记
uchar data dong=2;	//动画选择标记
uchar data gai=2;// 选择标记
uchar data gaizi=2;//选择标记
bit start2=1;//	动画选择标记 
uchar data pingpu=0;	//选择哪个频谱动画 
uchar data donghua1=0; //选择哪个脱机动画 
bit start_shuju=0; //wifi接收数据开始标记
bit abcd=0;//旋转字母
bit moshi_falg=0;
uchar data dhms_falg=0;
uchar data ppms_falg=0;
uchar data sjms_falg=0;
uchar data dnms_falg=0;
uchar data gzms_falg=0;
uchar data ldjian_falg=0;
uchar data ldjia_falg=0;
uchar data sdjia_falg=0;
uchar data sdjian_falg=0;
uchar data gzdh3_falg=0;
uchar gzdh3=0;
bit gaizi1_flag=1; //开机检测有没有保存过内容
bit gaizi2_flag=1;
bit gaizi3_flag=1;
bit gaizi4_flag=1;
uchar gaizi_geshu1=0;	//改字的字数
uchar gaizi_geshu2=0;
uchar gaizi_geshu3=0;
uchar jcount=0; //收到字母的个数
bit kaiji_flag=0;//
bit gaizhiflag=0;
uchar gzms_falg1=0;
uchar gzms_falg2=0;
uchar gzms_falg3=0;
uchar gzms_falg4=0;
uchar gzms_falg5=0;

void init() //定义IO口功能
{ 
	P4SW=0xff;                //定义P4口为I/O口 
	P0M1=0x00; 				  
	P0M0=0xff;                //定义P0为强上拉输出. 
 	P1M1=0x01; 
	P1M0=0xfe;                //定义P1为强上拉输出.   P1.0作为AD此时不能作为强上拉
	P2M1=0x00; 
	P2M0=0xff;                //定义P2为强上拉输出. 
	P3M1=0x00; 
	P3M0=0xf8;                //定义P3为强上拉输出. 
	P4M1=0x00; 
	P4M0=0xff;                //定义P4为强上拉输出. 	
}

void ADC0_Init (void) //AD初始化
{
	uchar i;
  P1ASF = 0x01;                   //Open 8 channels ADC function
  ADC_RES = 0;                    //Clear previous result	清零ADC的8位数据
	AUXR1 &=0xFB;                   //1111,1011, 令 ADRJ=0 (10位A/D转换结果的高8位放在ADC_RES寄存器, 低2位放在ADC_RESL寄存器)
  ADC_CONTR = ADC_POWER | ADC_SPEEDLL;//配置ADC寄存器  
	for(i=0;i<24;i++)_nop_();	
}

void sinter() //中断初始化
{
	TCON=0x01;
	TH0=0x10;
	TL0=0x00;
	IPH = 0xfc;	  	 
	ET0 = 1;
	TR0 = 1;	
}

void init_uart(void) //串口初始化
{
	 PCON |= 0x80;
	 SCON = 0x50;
	 AUXR |= 0x40;
	 AUXR &= 0xFE;
	 TMOD &= 0x0F;
	 TMOD |= 0x20;					  
	 TL1 = 0xE8;
	 TH1 = 0xE8;
	 ET1 = 0;
	 TR1 = 1;
	 ES=1;
	 EA=1;
}

void delayus(unsigned int yanshi)//根据yanshi值的大小进行延时等待操作，1默认为2uS
{
	unsigned int wmys; 		//定义延时循环控制变量
	for(wmys=0;wmys<=yanshi;wmys++);	//根据延时参数进行空循环操作，达到延时功能
}
void delay10us(void)   //误差 -0.026765046296us STC 1T 22.1184Mhz
{
    unsigned char a,b;
    for(b=1;b>0;b--)
			for(a=2;a>0;a--);	   //默认的速度为5，变速1-5-25-125
}
void delay5us(void)   //误差 -0.026765046296us STC 1T 22.1184Mhz
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=5;a>0;a--);	   //默认的速度为5，变速1-5-25-125
}
void delay(uint ihk)
{    
	if(key3==2){return;}
	else
    {                                                                                              
	    while(ihk--)
		{
		 	delay5us();   //12t的mcu 注释这个延时即可
			if(dong == 1){return;} if(gai == 1){return;}if(gaizhiflag==1){return;}
		}
	}
}
void delays(int t)
{
	int i;
	while(t--)
		for(i=0;i<700;i++);
}

void hansao(unsigned char hs) //根据hs的值 判断选择哪一行 操纵P2的值选通1-8行
{
	if(hs<8)			  //判断hs的值是否在行扫描的值范围内，不在范围内不执行任何操作
	{
		if(M_EN == 0)
		{
			if(hs==7)		  //选通第1行
			{
			  P2=0Xfe;
				delayus(liangdu);
				P2 = 0xff;	  //消影
				return;
			}
			if(hs==6)		  //选通第2行
			{
			     P2=0Xfd;
				 delayus(liangdu);
			     P2 = 0xff;		
				 return;
			}
			if(hs==5)		  //选通第3行
			{
				P2=0Xfb;
				delayus(liangdu);
				P2 = 0xff;	
				return;
			}
			if(hs==4)		  //选通第4行
			{
		    	P2=0Xf7;
				delayus(liangdu);
				P2 = 0xff;	
			  	return;
			}
			if(hs==3)		  //选通第5行
			{
				P2=0Xef;
				delayus(liangdu);
				P2 = 0xff;							
				return;
			}
			if(hs==2)		  //选通第6行
			{
				P2=0Xdf;
				delayus(liangdu);
				P2 = 0xff;	
				return;
			}
			if(hs==1)		  //选通第7行
			{
				P2=0Xbf;
				delayus(liangdu);
				P2 = 0xff;	
				return;
			}
			if(hs==0)		  //选通第8行
			{
				P2=0X7f;
				delayus(liangdu);
				P2 = 0xff;	
				return;
			}
		}
	}
}
//动画驱动程序 发送字节入寄存器
void sendbyte(unsigned int num1,unsigned int num2,unsigned int num3,unsigned int num4)
{    
    unsigned char c; 	
    for(c=0;c<8;c++)			
   {
      CLK=0; 				 
      M_LR_DS0=num1&0x80;			 
	  M_LG_DS0=num2&0x80;			
	  M_HR_DS0=num3&0x80;			
	  M_HG_DS0=num4&0x80;			
      CLK=1; 				
	  num1<<=1;        	
      num2<<=1;        	
      num3<<=1;        	
      num4<<=1;        		
    }
}

void sendbyte1(unsigned int num1,unsigned int num2,unsigned int num3,unsigned int num4)
{
    unsigned char c;
    for(c=0;c<8;c++)
    {
		CLK=0;	 //模拟时钟控制端口
		M_LR_DS0=num1&0x01;	   //模拟数据发送端口
		M_LG_DS0=num2&0x01;
		M_HR_DS0=num3&0x01;
		M_HG_DS0=num4&0x01;
		CLK=1;
		num1>>=1;
		num2>>=1;
		num3>>=1;
		num4>>=1;
    }
}
//************************************595芯片驱动程序3 上位机控制部分***********************************
//void sendbyteck(unsigned int num1,unsigned int num2,unsigned int num3,unsigned int num4)
//{
//    unsigned char c;
//    for(c=0;c<8;c++)
//   	{
//		CLK=0;
//		M_LR_DS0=num1&0x01;
//		M_LG_DS0=num2&0x01;
//		M_HR_DS0=num3&0x01;	    
//		M_HG_DS0=num4&0x01;
//		CLK=1;
//		num1>>=1;
//		num2>>=1;
//		num3>>=1;
//		num4>>=1;
//    }
//}
//void fvb()		//电脑上位机数据处理
//{
//	if(read_flag)
//	{
//		read_flag=0;
//		for(saom=0;saom<8;saom++)
//		{
//			displayck[saom+0]=((shuzu8X8[saom*8]>>7)&0x01)+(((shuzu8X8[saom*8+1]>>7)&0x01)<<1)+(((shuzu8X8[saom*8+2]>>7)&0x01)<<2)+(((shuzu8X8[saom*8+3]>>7)&0x01)<<3)+(((shuzu8X8[saom*8+4]>>7)&0x01)<<4)+(((shuzu8X8[saom*8+5]>>7)&0x01)<<5)+(((shuzu8X8[saom*8+6]>>7)&0x01)<<6)+(((shuzu8X8[saom*8+7]>>7)&0x01)<<7);	
//			displayck[saom+8]=((shuzu8X8[saom*8]>>6)&0x01)+(((shuzu8X8[saom*8+1]>>6)&0x01)<<1)+(((shuzu8X8[saom*8+2]>>6)&0x01)<<2)+(((shuzu8X8[saom*8+3]>>6)&0x01)<<3)+(((shuzu8X8[saom*8+4]>>6)&0x01)<<4)+(((shuzu8X8[saom*8+5]>>6)&0x01)<<5)+(((shuzu8X8[saom*8+6]>>6)&0x01)<<6)+(((shuzu8X8[saom*8+7]>>6)&0x01)<<7);	
//			displayck[saom+16]=((shuzu8X8[saom*8]>>5)&0x01)+(((shuzu8X8[saom*8+1]>>5)&0x01)<<1)+(((shuzu8X8[saom*8+2]>>5)&0x01)<<2)+(((shuzu8X8[saom*8+3]>>5)&0x01)<<3)+(((shuzu8X8[saom*8+4]>>5)&0x01)<<4)+(((shuzu8X8[saom*8+5]>>5)&0x01)<<5)+(((shuzu8X8[saom*8+6]>>5)&0x01)<<6)+(((shuzu8X8[saom*8+7]>>5)&0x01)<<7);	
//			displayck[saom+24]=((shuzu8X8[saom*8]>>4)&0x01)+(((shuzu8X8[saom*8+1]>>4)&0x01)<<1)+(((shuzu8X8[saom*8+2]>>4)&0x01)<<2)+(((shuzu8X8[saom*8+3]>>4)&0x01)<<3)+(((shuzu8X8[saom*8+4]>>4)&0x01)<<4)+(((shuzu8X8[saom*8+5]>>4)&0x01)<<5)+(((shuzu8X8[saom*8+6]>>4)&0x01)<<6)+(((shuzu8X8[saom*8+7]>>4)&0x01)<<7);	
//			displayck[saom+32]=((shuzu8X8[saom*8]>>3)&0x01)+(((shuzu8X8[saom*8+1]>>3)&0x01)<<1)+(((shuzu8X8[saom*8+2]>>3)&0x01)<<2)+(((shuzu8X8[saom*8+3]>>3)&0x01)<<3)+(((shuzu8X8[saom*8+4]>>3)&0x01)<<4)+(((shuzu8X8[saom*8+5]>>3)&0x01)<<5)+(((shuzu8X8[saom*8+6]>>3)&0x01)<<6)+(((shuzu8X8[saom*8+7]>>3)&0x01)<<7);	
//			displayck[saom+40]=((shuzu8X8[saom*8]>>2)&0x01)+(((shuzu8X8[saom*8+1]>>2)&0x01)<<1)+(((shuzu8X8[saom*8+2]>>2)&0x01)<<2)+(((shuzu8X8[saom*8+3]>>2)&0x01)<<3)+(((shuzu8X8[saom*8+4]>>2)&0x01)<<4)+(((shuzu8X8[saom*8+5]>>2)&0x01)<<5)+(((shuzu8X8[saom*8+6]>>2)&0x01)<<6)+(((shuzu8X8[saom*8+7]>>2)&0x01)<<7);	
//			displayck[saom+48]=((shuzu8X8[saom*8]>>1)&0x01)+(((shuzu8X8[saom*8+1]>>1)&0x01)<<1)+(((shuzu8X8[saom*8+2]>>1)&0x01)<<2)+(((shuzu8X8[saom*8+3]>>1)&0x01)<<3)+(((shuzu8X8[saom*8+4]>>1)&0x01)<<4)+(((shuzu8X8[saom*8+5]>>1)&0x01)<<5)+(((shuzu8X8[saom*8+6]>>1)&0x01)<<6)+(((shuzu8X8[saom*8+7]>>1)&0x01)<<7);	
//			displayck[saom+56]=((shuzu8X8[saom*8]>>0)&0x01)+(((shuzu8X8[saom*8+1]>>0)&0x01)<<1)+(((shuzu8X8[saom*8+2]>>0)&0x01)<<2)+(((shuzu8X8[saom*8+3]>>0)&0x01)<<3)+(((shuzu8X8[saom*8+4]>>0)&0x01)<<4)+(((shuzu8X8[saom*8+5]>>0)&0x01)<<5)+(((shuzu8X8[saom*8+6]>>0)&0x01)<<6)+(((shuzu8X8[saom*8+7]>>0)&0x01)<<7);	
//		}
//	}
//	for(layerr=0;layerr<8;layerr++)
//	{		
//		key_baihei_scan();  
//		hansao(layerr);
//		sendbyteck(~displayck[layerr*8+0],~displayck[layerr*8+2],~displayck[layerr*8+4],~displayck[layerr*8+5]);
//		sendbyteck(~displayck[layerr*8+3],~displayck[layerr*8+1],~displayck[layerr*8+6],~displayck[layerr*8+7]);
//		SUO=0;		//模拟锁存信号端口	      
//		_nop_();
//		SUO=1;	 
//	  	M_EN=0;	
//		hansao(layerr); 	 		     
//		delayus(ld);	    
//		M_EN=1;				
//		if(key2==1||key2==2||key2==4||key2==5) 
//		{
//			break; 
//		} 	   
//	}
//}
void zhen(uchar *a,uchar v)	 //前面动画数据处理
{
	 char layer;
	 while(v--)
	 {	
		  for(layer=0;layer<8;layer++)
		  {
			 	if(xsdsq==1){;}
				else
				{
					key_baihei_scan(); 
					if(msd==2||msd==6)
					{
						if(key2==1||key2==3||key2==5||key2==4)  
						{
							key3=1;	
							M_EN=1;				  
							break;
						}
					}
					if(msd==4)
					{
						if(key2==1||key2==3||key2==5||key2==2)  
						{
							key3=1;	
							M_EN=1;		  
							break;
						}
					}
				}	
				sendbyte1(~a[layer*8+7],~a[layer*8+5],~a[layer*8+3],~a[layer*8+2]);
				sendbyte1(~a[layer*8+4],~a[layer*8+6],~a[layer*8+1],~a[layer*8+0]);
				SUO=0;			      
				_nop_();
				SUO=1;
				M_EN=0;	
				hansao(7-layer);		      
				delayus(donghua_shudu);		    
				M_EN=1;			
				if(dong == 1){break;}	 
				if(abcd == 1){break;}
				if(gai == 1){break;} 
		  }
		  delays(2);		   
	 }
}

void W_side(uchar *tab,char num,char v)
{
	uchar a[64]={0};
	int i,j;
	for(j=0;j<num;j++)
	{
		for(i=0;i<8;i++)
			a[i*8+7]=tab[j*8+i];	
		if(key3==1){break;}
		else{zhen(a,v);}
		delay(50);
	}
}

void main()
{
	unsigned char p=0,k=0,l=0;	  //定义
	init();	
	start_shuju = 1;
	IDelay(100);
	IRInit();
	ADC0_Init();
	clear(0);
	PWM_LED();//开启PWM呼吸灯功能
  moshi = 0;
	key2 = 0;
	ping=2;	
	dong=2;
	gai=2;
	gaizi=0;
	pingpu = 0;
	donghua1 = 0;
	start1 = 1;
	start2 = 1;
//	turn_on(10);
//	H_scan(10); // 左向右扫描检测
//	V_scan(10); //下向上扫描检测
//	W_scan(10); //前向后扫描检测
//	PWM_POW=0;  //打开电源指示灯
	sinter();
	TR0=0;	   //关闭定时器显示扫描	 相当于关闭频谱模式显示和后面部分动画显示	
	while(1)	//开机检测模式
	{
//		H_scan(40); // 左向右扫描检测   
//		V_scan(40); //下向上扫描检测 
		W_scan(10); //后向前扫描检测
		if(key1 == 1)
		{
			msd=2; 
			break;	
		}
		if(key2==3||key2==1||key2==4||key2==5||key2==2)
		{
			if(key2==3)
			{
				msd=3;break;
			}
			else
			{
				if(key2==1)
				{
					msd=1;break;
				}
				if(key2==4)
				{
					msd=4;
					break;	
				}
				if(key2==5)
				{
					msd=5;
					break;	
				}
				if(key2==2)
				{
					msd=2;
					break;	
				}
			}
		}
	}
	delay(10); //如果是前面动画和上机模式需要延时下
	while(1)  /*play list*/
	{      
		kaiji_flag = 1; //开机后  
		yinyue_moshi();//音乐频谱模式
		donghua_moshi();//动画模式
		shangweiji_moshi();	//上位机模式
		xiugaidonghua_moshi(); //显示文字动画   		
	}
}

void serial (void) interrupt 4 using 1//串口中断
{
	uchar tempbuff;ES=0;
	if(RI)
	{
		RI=0;tempbuff=SBUF;
		switch(cnt)
		{
			case 0:if(tempbuff==0xf2)cnt=1;else {cnt=0;}break;
			case 1:shuzu8X8[cd++]=tempbuff;
			if(cd==64)
			{
				cnt=0;
				cd=0;
				read_flag=1;
			}
			else
			{
				break;
			}
			default:break;
		}
	}
	ES=1;
}

void print1() interrupt 1//定时中断
{
	static uchar layert=0;
	TR0 = 0;
	ET0= 0;

	if(msd==1)	  //频谱模式
	{		
			 sendbyte(~display[layert][0],~display[layert][2],~display[layert][4],~display[layert][5]);
			 sendbyte(~display[layert][3],~display[layert][1],~display[layert][6],~display[layert][7]);
			 SUO=0;
			 _nop_();
			 SUO=1;
			 M_EN=0;
			 hansao(7-layert); 	 
			 delayus(ld);
			 M_EN=1;				 
	          if (layert<7) 
	               layert++;
	          else 
	               layert=0;
		    key_baihei_scan(); 	
			if(msd==1)
			{
				if(key2==2||key2==3||key2==4||key2==5)
				{
					key3=2;	
					return;			
				}	
			}   			
			 TH0=0xef;
	         TL0=0x00;
	}
	if(msd==2)	 //后部分动画 
	{	     	  
			 sendbyte(~display[layert][0],~display[layert][2],~display[layert][4],~display[layert][5]);
			 sendbyte(~display[layert][3],~display[layert][1],~display[layert][6],~display[layert][7]);
	
			 SUO=0;
			 _nop_();
			 SUO=1;
			 M_EN=0;
			 hansao(layert); 
			 delayus(donghua_shudu);
			 M_EN=1;				 
	          if (layert<7) 
	               layert++;
	          else 
	               layert=0;	
		     key_baihei_scan(); 
			if(msd==2) 
			{
				if(key2==1||key2==3||key2==4||key2==5)
				{
					key3=2;
					return;			
				}	
			}  
			 TH0=0xef;
	         TL0=0x00;
	}
	if(msd==4)	 //文字动画部分 
	{	     	  
			 sendbyte(~display[layert][0],~display[layert][2],~display[layert][4],~display[layert][5]);
			 sendbyte(~display[layert][3],~display[layert][1],~display[layert][6],~display[layert][7]);
	
			 SUO=0;
			 _nop_();
			 SUO=1;
			 M_EN=0;
			 hansao(layert); 
			 delayus(donghua_shudu);
			 M_EN=1;				 
	          if (layert<7) 
	               layert++;
	          else 
	               layert=0;	
		     key_baihei_scan(); 
			if(msd==4) 
			{
				if(key2==1||key2==3||key2==2||key2==5)
				{
					key3=2;
					return;			
				}	
			}  
			
			 TH0=0xef;
	         TL0=0x00;
	}
	TR0 = 1;
	ET0 = 1;	  
}

void shudu_jia() //速度加
{
	if(key2==2 || key2==4)
	{
		if(donghua_shudu>500 && donghua_shudu<=1500)
		{
			donghua_shudu = donghua_shudu-200;
		}
		else if(donghua_shudu>100 && donghua_shudu<=500)
		{
			donghua_shudu = donghua_shudu-100;
		}
		else if(donghua_shudu>30 && donghua_shudu<=100)
		{
			donghua_shudu = donghua_shudu-40;
		}
		else if(donghua_shudu>0 && donghua_shudu<=30)
		{
			donghua_shudu = donghua_shudu-10;		
		}
		if(donghua_shudu<=0 || donghua_shudu> 2000)
		{
			donghua_shudu=1;
		}			
	}		
}
void shudu_jian() //速度减
{
	if(key2==2 || key2==4)
	{
		if(donghua_shudu>0 && donghua_shudu<=30)
		{
		  donghua_shudu = donghua_shudu+10;
		}
		else if(donghua_shudu>30 && donghua_shudu<=100)
		{
		  donghua_shudu = donghua_shudu+40;
		}
		else if(donghua_shudu>100 && donghua_shudu<=500)
		{
		  donghua_shudu = donghua_shudu+100;
		}
		else if(donghua_shudu>500 && donghua_shudu<1500)
		{
		  donghua_shudu = donghua_shudu+200;
		}
		
		if(donghua_shudu >= 1500)
		{
			donghua_shudu = 1500;	 	
		}	
	}			 
}

