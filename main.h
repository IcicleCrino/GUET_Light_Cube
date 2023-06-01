#ifndef _MAIN_H_
#define _MAIN_H_

#define uchar unsigned char
#define uint  unsigned int

#define uchar unsigned char	 
#define uint unsigned int	 
#define nop() _nop_();_nop_(); 
#define  NOP() _nop_()  	/* �����ָ�� */

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
sbit AD=P1^0;		 //������Ƶ����ӿ�
sbit GM=P1^1;		 //�����������ӿ�
sbit K1=P0^0;		 //���幦�ܰ����ӿ�
sbit K2=P0^1;		 //���幦�ܰ����ӿ�
sbit K3=P0^2;		 //���幦�ܰ����ӿ�
sbit K4=P0^3;		 //���幦�ܰ����ӿ�


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
sbit M_HR_DS0=P1^4;	  //ģ�����ݷ��Ͷ˿�
sbit M_LR_DS0=P1^7;	  //ģ�����ݷ��Ͷ˿�


sbit M_HG_DS0=P1^6;	  //ģ�����ݷ��Ͷ˿�
sbit M_LG_DS0=P0^7;	  //ģ�����ݷ��Ͷ˿�

sbit CLK=P3^7;    //ģ��ʱ�ӿ��ƶ˿�
sbit SUO=P3^6;	  //ģ�������źŶ˿�
/*$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$*/

sbit PWM_POW=P4^4;   //����PWM����Сҹ�ƺ������Դָʾ�ƹ��ܽӿ� �͵�ƽ


///����ȫ�ֱ���
extern uchar data msd;	
extern uchar data key2,key3; 
extern uint ld;
extern uchar xdata display[8][8];
extern uchar data xsdsq; 
extern bit M_EN = 1;
extern uchar data cd,cnt,read_flag,layerr,saom;
extern uchar data moshi; // ģʽ
bit key1;
uchar jcount; //
uchar xdata abc[45];//��ת��ĸ�����ݱ���
uchar xdata gzdh3_char[64];//���ֶ���3���յ��ֻ������ݱ���
uchar xdata  abc_char[30];//��ת��ĸ���յ����ݱ��� 
uchar xdata shuzu8X8[64];//������λ������
uchar xdata shuzu8X81[64];//
uchar data displayck[64];//
//-----------------------------------------------------
//����STC�ڲ�FLASHһ��������ַ��ÿ�������洢һ��������
//-----------------------------------------------------
uchar xdata gaizi_san[8][8];
uchar xdata gaizi_yi[8][8];
uchar xdata gaizi_er[8][8];
bit start1;
bit start2; 
uchar data ping;	//Ƶ��ѡ����
uchar data dong;	//����ѡ����
uchar data donghua1; //ѡ���ĸ��ѻ�����
uchar data pingpu;
uchar data gai;// ѡ����
uchar data gaizi;//ѡ����
int date;	 //����2����
bit abcd;//��ת��ĸ
uint liangdu;	  //����
uint donghua_shudu;   //�����ٶȵ���
bit start3; //��ת��ĸģʽ���
uchar gzdh3;
bit gaizi1_flag; //���������û�б��������
bit gaizi2_flag;
bit gaizi3_flag; 
bit gaizi4_flag; 
uchar gaizi_geshu1;
uchar gaizi_geshu2;
uchar gaizi_geshu3;
bit kaiji_flag;//
bit gaizhiflag;
uchar gzms_falg1;
uchar gzms_falg2;
uchar gzms_falg3;
uchar gzms_falg4;
uchar gzms_falg5;


			
/////////////////////��������  ///////////////////////////////////////////////////////////////// 
void delay10us(void);
void key_baihei_scan();  
void key_shangwiej_scan();   
void key_donghua_scan();	
void key_yinyue_scan();
void box(unsigned char x1,unsigned char z1,unsigned char y1,unsigned char x2,unsigned char z2,unsigned char y2,unsigned char fill,unsigned char le);
void delay(unsigned int i);  
void delayus(unsigned int yanshi);
void delays(int t);
void delay10us(void);   //��� -0.026765046296us STC 1T 22.1184Mhz   
void delay5us(void);   //��� -0.026765046296us STC 1T 22.1184Mhz
void delays(int t);
void delay1(int t);
void IRInit();     				 
void IRdelay(char x); 
unsigned int voivol(unsigned int n);
void sendbyte(unsigned int num1,unsigned int num2,unsigned int num3,unsigned int num4);
void fvb();
void sendbyteck(unsigned int num1,unsigned int num2,unsigned int num3,unsigned int num4);
void hansao(unsigned char hs);
void sendbyte1(unsigned int num1,unsigned int num2,unsigned int num3,unsigned int num4);
void W_side(uchar *tab,char num,char v);
/********************* ���ڳ�ʼ��************************/
void init_uart(void);
/************************************������************************************/
void PWM_LED();
/************************************ɨ��һ��************************************/
void turn_on(uchar v);
/************************************������ɨ����************************************/
void H_scan(uchar v);
/************************************������ɨ����************************************/
void V_scan(uchar v);
/************************************ǰ���ɨ����************************************/
void W_scan(uchar v);
void yinyue_moshi();//����Ƶ��ģʽ
void donghua_moshi();//����ģʽ
void shangweiji_moshi();	//��λ��ģʽ
void xiugaidonghua_moshi(); //��ʾ����ͨ���ֻ��޸����ݵĶ���
void pingpu_xuanze();  //����Ƶ��ѡ�񶯻�
//����ģʽ�����ж�
void yinyue_key2();
////����ģʽ�����ж�
void donghua_key2();
////����ģʽ�����ж�
void gaizi_key2();
void donghua_xuanze();  //����Ƶ��ѡ�񶯻�
/***************************************************************
*��������������2��ʼ��
*���������
*���ز�����
****************************************************************/
void xianzhuan_zm();	 //��ת��ĸ
// ����Ч��Ʈ�����ƶ���ȥ
void piaozhi(uchar P_zf[11][8],uint speed,uchar a);	//aΪ����


void clear(char le);
void type(uchar cha,uchar y);
void cirp(char cpp,uchar dir,uchar le);
void box_apeak_xy(uchar x1,uchar y1,uchar z1,uchar x2,uchar y2,uchar z2,uchar fill,uchar le);
void roll_apeak_yz(uchar n,uint speed);
void point(uchar x,uchar y,uchar z,uchar le);
void line(uchar x1,uchar y1,uchar z1,uchar x2,uchar y2,uchar z2,uchar le);
void trans(uchar z,uint speed);
void roll_apeak_xy(uchar n,uint speed);
void roll_3_xy(uchar n,uint speed);
void tranoutchar(uchar c,uint speed);
void transss();
void rolldisplay_yd(uint speed);
void trailler(uint speed);
void type_sj(uchar cha,uchar y);
void rain(char menu,char num,char v);
void rolldisplay_yd(uint speed);
void tranoutchar_cu(uchar c,uint speed);
void zhen(uchar *a,uchar v);
void hy(uchar *tab,char v);
void zimu(uchar *x,char n,char v,int num);//������Ļ,num��ʾѭ������,v��ʾ�����ٶ�,n�ַ�����
void move(uchar *a,char kind,char direction,char length);//length����Ϊ8
//kind=0 x��,1 x��,2 z�᣻direction=0,����,1����
void leitu(uchar *b,char num,char v);
void water1(char x,char y,char v);
void water2(char x1,char y1,char x2,char y2,char v);
void water3(char x1,char y1,char x2,char y2,char x3,char y3,char v);
void print(uchar *a,char m);//m=0�п���ʾ,m=1ʵ����ʾ
void link_jb0(char v);
void jb0(char num,char v);///////////////////////////////
void yinchu(uchar *table,char n,char v);
void link(char v);
void xuanzhuantiao(char kind,char num,char v);//������ת,kind=1ʵ��,�������
void xuanzhuantiao2(char num,char v);//������ת,kind=1ʵ��,�������
void qumianxuanzhuan(char kind,char num,char v);//������ת
void qumianxuanzhuan2(char num,char v);//������ת
void donghua(uchar *tab,uchar num,uchar n,char v);
void xzcube();
void link00();
void shensuo(uchar v);
void cube(char empty,char kind,char v);
void shandian(char v);
void szfc0(char v);//�����ϸ�
void sinter();
void shudu_jian(); //�ٶȼ�
void shudu_jia(); //�ٶȼ�

#endif