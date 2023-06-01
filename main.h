#ifndef _MAIN_H_
#define _MAIN_H_

#define uchar unsigned char
#define uint  unsigned int

#define uchar unsigned char	 
#define uint unsigned int	 
#define nop() _nop_();_nop_(); 
#define  NOP() _nop_()  	/* 定义空指令 */

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
sbit AD=P1^0;		 //定义音频输入接口
sbit GM=P1^1;		 //定义光敏输入接口
sbit K1=P0^0;		 //定义功能按键接口
sbit K2=P0^1;		 //定义功能按键接口
sbit K3=P0^2;		 //定义功能按键接口
sbit K4=P0^3;		 //定义功能按键接口


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
sbit M_HR_DS0=P1^4;	  //模拟数据发送端口
sbit M_LR_DS0=P1^7;	  //模拟数据发送端口


sbit M_HG_DS0=P1^6;	  //模拟数据发送端口
sbit M_LG_DS0=P0^7;	  //模拟数据发送端口

sbit CLK=P3^7;    //模拟时钟控制端口
sbit SUO=P3^6;	  //模拟锁存信号端口
/*$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$$-_-$_-_$*/

sbit PWM_POW=P4^4;   //定义PWM呼吸小夜灯和主板电源指示灯功能接口 低电平


///定义全局变量
extern uchar data msd;	
extern uchar data key2,key3; 
extern uint ld;
extern uchar xdata display[8][8];
extern uchar data xsdsq; 
extern bit M_EN = 1;
extern uchar data cd,cnt,read_flag,layerr,saom;
extern uchar data moshi; // 模式
bit key1;
uchar jcount; //
uchar xdata abc[45];//旋转字母接数据保存
uchar xdata gzdh3_char[64];//改字动画3接收到手机的数据保存
uchar xdata  abc_char[30];//旋转字母接收到数据保存 
uchar xdata shuzu8X8[64];//电脑上位机数据
uchar xdata shuzu8X81[64];//
uchar data displayck[64];//
//-----------------------------------------------------
//定义STC内部FLASH一个扇区地址，每个扇区存储一个红外码
//-----------------------------------------------------
uchar xdata gaizi_san[8][8];
uchar xdata gaizi_yi[8][8];
uchar xdata gaizi_er[8][8];
bit start1;
bit start2; 
uchar data ping;	//频谱选择标记
uchar data dong;	//动画选择标记
uchar data donghua1; //选择哪个脱机动画
uchar data pingpu;
uchar data gai;// 选择标记
uchar data gaizi;//选择标记
int date;	 //串口2数据
bit abcd;//旋转字母
uint liangdu;	  //亮度
uint donghua_shudu;   //动画速度调节
bit start3; //旋转字母模式标记
uchar gzdh3;
bit gaizi1_flag; //开机检测有没有保存过内容
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


			
/////////////////////函数声名  ///////////////////////////////////////////////////////////////// 
void delay10us(void);
void key_baihei_scan();  
void key_shangwiej_scan();   
void key_donghua_scan();	
void key_yinyue_scan();
void box(unsigned char x1,unsigned char z1,unsigned char y1,unsigned char x2,unsigned char z2,unsigned char y2,unsigned char fill,unsigned char le);
void delay(unsigned int i);  
void delayus(unsigned int yanshi);
void delays(int t);
void delay10us(void);   //误差 -0.026765046296us STC 1T 22.1184Mhz   
void delay5us(void);   //误差 -0.026765046296us STC 1T 22.1184Mhz
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
/********************* 串口初始化************************/
void init_uart(void);
/************************************呼吸灯************************************/
void PWM_LED();
/************************************扫描一面************************************/
void turn_on(uchar v);
/************************************左向右扫描检测************************************/
void H_scan(uchar v);
/************************************下向上扫描检测************************************/
void V_scan(uchar v);
/************************************前向后扫描检测************************************/
void W_scan(uchar v);
void yinyue_moshi();//音乐频谱模式
void donghua_moshi();//动画模式
void shangweiji_moshi();	//上位机模式
void xiugaidonghua_moshi(); //显示可以通过手机修改内容的动画
void pingpu_xuanze();  //音乐频谱选择动画
//音乐模式按键判断
void yinyue_key2();
////动画模式按键判断
void donghua_key2();
////文字模式按键判断
void gaizi_key2();
void donghua_xuanze();  //音乐频谱选择动画
/***************************************************************
*函数描述：串口2初始化
*输入参数：
*返回参数：
****************************************************************/
void xianzhuan_zm();	 //旋转字母
// 下雨效果飘出字移动出去
void piaozhi(uchar P_zf[11][8],uint speed,uchar a);	//a为个数


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
void zimu(uchar *x,char n,char v,int num);//滚动字幕,num表示循环次数,v表示滚动速度,n字符个数
void move(uchar *a,char kind,char direction,char length);//length不能为8
//kind=0 x轴,1 x轴,2 z轴；direction=0,负向,1正向
void leitu(uchar *b,char num,char v);
void water1(char x,char y,char v);
void water2(char x1,char y1,char x2,char y2,char v);
void water3(char x1,char y1,char x2,char y2,char x3,char y3,char v);
void print(uchar *a,char m);//m=0中空显示,m=1实心显示
void link_jb0(char v);
void jb0(char num,char v);///////////////////////////////
void yinchu(uchar *table,char n,char v);
void link(char v);
void xuanzhuantiao(char kind,char num,char v);//空心旋转,kind=1实心,否则空心
void xuanzhuantiao2(char num,char v);//空心旋转,kind=1实心,否则空心
void qumianxuanzhuan(char kind,char num,char v);//曲面旋转
void qumianxuanzhuan2(char num,char v);//曲面旋转
void donghua(uchar *tab,uchar num,uchar n,char v);
void xzcube();
void link00();
void shensuo(uchar v);
void cube(char empty,char kind,char v);
void shandian(char v);
void szfc0(char v);//数字上浮
void sinter();
void shudu_jian(); //速度减
void shudu_jia(); //速度加

#endif