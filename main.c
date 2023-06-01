#include "STC12C5A.H"  //��Ƭ��ͷ�ļ�
#include "intrins.h"   //����NOP��ʱͷ�ļ�
#include "main.h"       //������ͷ�ļ�
#include "shuju.h"     //������ģ��������
#include "flash.h"      //�������ֳ���
#include "hongwai.h"    //���ⲿ�ֳ���
#include "key.h"        //�������ֳ���
#include "pinpu.h"      //����Ƶ�ײ��ֳ���
#include "jiance.h"     //�������ģʽ����
#include "moshi.h"      //ģʽ���Ƴ���	  

uchar xdata display[8][8];
uchar data msd=0;
uint ld=700;
uchar data key2=0,key3=0; 
uchar data xsdsq=0; 
uchar data sj_read_flag=0;  
uchar data read_flag=0;     //������λ�������
uchar data cnt=0;
uchar data cot=0;
uchar data cd=0,layerr=0,saom=0;
uint liangdu = 400;	  //����
uint donghua_shudu=500;   //�����ٶȵ��� 
int date=0;	 //����2����
bit busy = 0; //�����жϱ��
uchar data moshi=0; // ģʽ
bit start3 = 0; //��ת��ĸģʽ���
bit key1=0;
uchar data abc_falg=0;       //��ת��ĸ���
bit start1=1;//Ƶ��ѡ����
uchar data ping=2;	//Ƶ��ѡ����
uchar data dong=2;	//����ѡ����
uchar data gai=2;// ѡ����
uchar data gaizi=2;//ѡ����
bit start2=1;//	����ѡ���� 
uchar data pingpu=0;	//ѡ���ĸ�Ƶ�׶��� 
uchar data donghua1=0; //ѡ���ĸ��ѻ����� 
bit start_shuju=0; //wifi�������ݿ�ʼ���
bit abcd=0;//��ת��ĸ
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
bit gaizi1_flag=1; //���������û�б��������
bit gaizi2_flag=1;
bit gaizi3_flag=1;
bit gaizi4_flag=1;
uchar gaizi_geshu1=0;	//���ֵ�����
uchar gaizi_geshu2=0;
uchar gaizi_geshu3=0;
uchar jcount=0; //�յ���ĸ�ĸ���
bit kaiji_flag=0;//
bit gaizhiflag=0;
uchar gzms_falg1=0;
uchar gzms_falg2=0;
uchar gzms_falg3=0;
uchar gzms_falg4=0;
uchar gzms_falg5=0;

void init() //����IO�ڹ���
{ 
	P4SW=0xff;                //����P4��ΪI/O�� 
	P0M1=0x00; 				  
	P0M0=0xff;                //����P0Ϊǿ�������. 
 	P1M1=0x01; 
	P1M0=0xfe;                //����P1Ϊǿ�������.   P1.0��ΪAD��ʱ������Ϊǿ����
	P2M1=0x00; 
	P2M0=0xff;                //����P2Ϊǿ�������. 
	P3M1=0x00; 
	P3M0=0xf8;                //����P3Ϊǿ�������. 
	P4M1=0x00; 
	P4M0=0xff;                //����P4Ϊǿ�������. 	
}

void ADC0_Init (void) //AD��ʼ��
{
	uchar i;
  P1ASF = 0x01;                   //Open 8 channels ADC function
  ADC_RES = 0;                    //Clear previous result	����ADC��8λ����
	AUXR1 &=0xFB;                   //1111,1011, �� ADRJ=0 (10λA/Dת������ĸ�8λ����ADC_RES�Ĵ���, ��2λ����ADC_RESL�Ĵ���)
  ADC_CONTR = ADC_POWER | ADC_SPEEDLL;//����ADC�Ĵ���  
	for(i=0;i<24;i++)_nop_();	
}

void sinter() //�жϳ�ʼ��
{
	TCON=0x01;
	TH0=0x10;
	TL0=0x00;
	IPH = 0xfc;	  	 
	ET0 = 1;
	TR0 = 1;	
}

void init_uart(void) //���ڳ�ʼ��
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

void delayus(unsigned int yanshi)//����yanshiֵ�Ĵ�С������ʱ�ȴ�������1Ĭ��Ϊ2uS
{
	unsigned int wmys; 		//������ʱѭ�����Ʊ���
	for(wmys=0;wmys<=yanshi;wmys++);	//������ʱ�������п�ѭ���������ﵽ��ʱ����
}
void delay10us(void)   //��� -0.026765046296us STC 1T 22.1184Mhz
{
    unsigned char a,b;
    for(b=1;b>0;b--)
			for(a=2;a>0;a--);	   //Ĭ�ϵ��ٶ�Ϊ5������1-5-25-125
}
void delay5us(void)   //��� -0.026765046296us STC 1T 22.1184Mhz
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=5;a>0;a--);	   //Ĭ�ϵ��ٶ�Ϊ5������1-5-25-125
}
void delay(uint ihk)
{    
	if(key3==2){return;}
	else
    {                                                                                              
	    while(ihk--)
		{
		 	delay5us();   //12t��mcu ע�������ʱ����
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

void hansao(unsigned char hs) //����hs��ֵ �ж�ѡ����һ�� ����P2��ֵѡͨ1-8��
{
	if(hs<8)			  //�ж�hs��ֵ�Ƿ�����ɨ���ֵ��Χ�ڣ����ڷ�Χ�ڲ�ִ���κβ���
	{
		if(M_EN == 0)
		{
			if(hs==7)		  //ѡͨ��1��
			{
			  P2=0Xfe;
				delayus(liangdu);
				P2 = 0xff;	  //��Ӱ
				return;
			}
			if(hs==6)		  //ѡͨ��2��
			{
			     P2=0Xfd;
				 delayus(liangdu);
			     P2 = 0xff;		
				 return;
			}
			if(hs==5)		  //ѡͨ��3��
			{
				P2=0Xfb;
				delayus(liangdu);
				P2 = 0xff;	
				return;
			}
			if(hs==4)		  //ѡͨ��4��
			{
		    	P2=0Xf7;
				delayus(liangdu);
				P2 = 0xff;	
			  	return;
			}
			if(hs==3)		  //ѡͨ��5��
			{
				P2=0Xef;
				delayus(liangdu);
				P2 = 0xff;							
				return;
			}
			if(hs==2)		  //ѡͨ��6��
			{
				P2=0Xdf;
				delayus(liangdu);
				P2 = 0xff;	
				return;
			}
			if(hs==1)		  //ѡͨ��7��
			{
				P2=0Xbf;
				delayus(liangdu);
				P2 = 0xff;	
				return;
			}
			if(hs==0)		  //ѡͨ��8��
			{
				P2=0X7f;
				delayus(liangdu);
				P2 = 0xff;	
				return;
			}
		}
	}
}
//������������ �����ֽ���Ĵ���
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
		CLK=0;	 //ģ��ʱ�ӿ��ƶ˿�
		M_LR_DS0=num1&0x01;	   //ģ�����ݷ��Ͷ˿�
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
//************************************595оƬ��������3 ��λ�����Ʋ���***********************************
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
//void fvb()		//������λ�����ݴ���
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
//		SUO=0;		//ģ�������źŶ˿�	      
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
void zhen(uchar *a,uchar v)	 //ǰ�涯�����ݴ���
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
	unsigned char p=0,k=0,l=0;	  //����
	init();	
	start_shuju = 1;
	IDelay(100);
	IRInit();
	ADC0_Init();
	clear(0);
	PWM_LED();//����PWM�����ƹ���
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
//	H_scan(10); // ������ɨ����
//	V_scan(10); //������ɨ����
//	W_scan(10); //ǰ���ɨ����
//	PWM_POW=0;  //�򿪵�Դָʾ��
	sinter();
	TR0=0;	   //�رն�ʱ����ʾɨ��	 �൱�ڹر�Ƶ��ģʽ��ʾ�ͺ��沿�ֶ�����ʾ	
	while(1)	//�������ģʽ
	{
//		H_scan(40); // ������ɨ����   
//		V_scan(40); //������ɨ���� 
		W_scan(10); //����ǰɨ����
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
	delay(10); //�����ǰ�涯�����ϻ�ģʽ��Ҫ��ʱ��
	while(1)  /*play list*/
	{      
		kaiji_flag = 1; //������  
		yinyue_moshi();//����Ƶ��ģʽ
		donghua_moshi();//����ģʽ
		shangweiji_moshi();	//��λ��ģʽ
		xiugaidonghua_moshi(); //��ʾ���ֶ���   		
	}
}

void serial (void) interrupt 4 using 1//�����ж�
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

void print1() interrupt 1//��ʱ�ж�
{
	static uchar layert=0;
	TR0 = 0;
	ET0= 0;

	if(msd==1)	  //Ƶ��ģʽ
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
	if(msd==2)	 //�󲿷ֶ��� 
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
	if(msd==4)	 //���ֶ������� 
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

void shudu_jia() //�ٶȼ�
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
void shudu_jian() //�ٶȼ�
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

