#ifndef __FLASH_H__
#define __FLASH_H__
#include"main.h"       //主程序头文件


/*判断一个数值的第n位，是1还是0，并返回相应数值*/
uchar judgebit(uchar num,uchar b)
{
	 char n;
	 num=num&(1<<b);
	 if (num)
		n=1;
	 else
	 	n=0;
	 return n;
}
/*To figure out the round number*/
uchar abs(uchar a)
{
	 uchar b;
	 b=a/10;
	 a=a-b*10;
	 if (a>=5)
	 	b++;
	 return b;
}
/*To figure out the absolute value*/
uchar abss(char a)
{
	 if (a<0)
	 	a=-a;
	 return a;
}
/*The function can comparat the character.
And remove the big one to the back.*/
void max(uchar *a,uchar *b)
{
	uchar t;
	if ((*a)>(*b))
	{
		t=(*a);
		(*a)=(*b);
		(*b)=t;
	}
}
/*The function is to figure out the max number and return it.*/
uchar maxt(uchar a,uchar b,uchar c)
{
	if (a<b)
		a=b;
	if (a<c)
		a=c;
	return a;
}
void clear(char le)//该函数清空数组	   //填充表格
{
	uchar i,j;
	for (j=0;j<8;j++)
	{
		for (i=0;i<8;i++)
			display[j][i]=le;
	}
}
void type(uchar cha,uchar y)	//1 2 3 4 心 运算函数
{
	uchar xx;
	for (xx=0;xx<8;xx++)
	{
		display[xx][y]=table_cha[cha][xx];
	}
}
/*The first variable is the distance from the midpoint.
The second is the layer.
the third is the flash speed of the time between each two point.
The forth is the enable io,it controls weather draw or claen.*/
void cirp(char cpp,uchar dir,uchar le)
{
	uchar a,b,c,cp;
	if ((cpp<128)&(cpp>=0))
	{
		if (dir)
			cp=127-cpp;
		else
			cp=cpp;
		a=(dat[cp]>>5)&0x07;
		b=(dat[cp]>>2)&0x07;
		c=dat[cp]&0x03;

		if (cpp>63)
			c=7-c;
		point (a,b,c,le);
	}
}

void type_sj(uchar cha,uchar y)
{
	uchar xx;
	for (xx=0;xx<8;xx++)
	{
		display[xx][y]=table_cha_sj[cha][xx];
	}
}
void box(unsigned char x1,unsigned char z1,unsigned char y1,unsigned char x2,unsigned char z2,unsigned char y2,unsigned char fill,unsigned char le)
{
	 uchar i,j,t=0;
	 max(&x1,&x2);
	 max(&y1,&y2);
	 max(&z1,&z2);
	 for (i=x1;i<=x2;i++)
	  t|=1<<i;
	 if (!le)
	  t=~t;
	 if (fill)
	 {
		  if (le)
		  {
			   for (i=z1;i<=z2;i++)
			   {
			     for (j=y1;j<=y2;j++)
			     display[j][i]|=t;
			   }
		  }
		  else
		  {
			   for (i=z1;i<=z2;i++)
			   {
			     for (j=y1;j<=y2;j++)
			     display[j][i]&=t;
			   }
		  }
	 }
	 else
	 {
		  if (le)
		  {
			   display[y1][z1]|=t;
			   display[y2][z1]|=t;
			   display[y1][z2]|=t;
			   display[y2][z2]|=t;
		  }
		  else
		  {
			   display[y1][z1]&=t;
			   display[y2][z1]&=t;
			   display[y1][z2]&=t;
			   display[y2][z2]&=t;
		  }
		  t=(0x01<<x1)|(0x01<<x2);
		  if (!le)
		  t=~t;
		  if (le)
		  {
			   for (j=z1;j<=z2;j+=(z2-z1))
			   {
			     for (i=y1;i<=y2;i++)
			     display[i][j]|=t;
			   }
			   for (j=y1;j<=y2;j+=(y2-y1))
			   {
			     for (i=z1;i<=z2;i++)
			     display[j][i]|=t;
			   }
		  }
		  else
		  {
			   for (j=z1;j<=z2;j+=(z2-z1))
			   {
				    for (i=y1;i<=y2;i++)
				    {
				  	  display[i][j]&=t;
				    }
			   }
			   for (j=y1;j<=y2;j+=(y2-y1))
			   {
				    for (i=z1;i<=z2;i++)
				    {
				 	   display[j][i]&=t;
				    }
			   }
		  }
	 }
}
 
void poke(uchar n,uchar x,uchar y)
{
	 uchar i;
	 for (i=0;i<8;i++)
	 {
	 	 point(x,y,i,judgebit(n,i));
	 }
}
void boxtola(char i,uchar n)
{
	 if ((i>=0)&(i<8))
	 {
		  poke(n,0,7-i);
	 }
	 if ((i>=8)&(i<16))
	 {
	 	 poke(n,i-8,0);
	 }
	 if ((i>=16)&(i<24))
	 {
	 	 poke(n,7,i-16);
	 }
}
void rolldisplay_yd(uint speed)
{
     uchar j;
     char i,a;
     for (i=23;i>-112;i--)
     {
           for (j=0;j<112;j++)
           {
                    a=i+j;
                    if ((a>=0)&(a<24))
                    boxtola(a,table_yd[j]);
           }
           delay(speed);
		   if(dong == 1){dong = 0;return;	}
     }
}

void tranoutchar(uchar c,uint speed)
{
	 uchar i,j,k,a,i2=0;
	 for (i=0;i<8;i++)
	 {
		  if (i<7)
		  box_apeak_xy (i+1,0,0,i+1,7,7,1,1);
		  box_apeak_xy (i2,0,0,i2,7,7,1,0);
		  a=0;
		  i2=i+1;
		  for (j=0;j<=i;j++)
		  {
		 	  a=a|(1<<j);
		  }
		  for (k=0;k<8;k++)
		  {
		 	  display[k][3]|=table_cha[c][k]&a;
		   	  display[k][4]|=table_cha[c][k]&a;
		  }
		  delay(speed);
		  if(dong == 1){return;	}
	 }
}
void tranoutchar_cu(uchar c,uint speed)
{
	 uchar i,j,k,a,i2=0;
	 for (i=0;i<8;i++)
	 {
		  if (i<7)
		  box_apeak_xy (i+1,0,0,i+1,7,7,1,1);
		  box_apeak_xy (i2,0,0,i2,7,7,1,0);
		  a=0;
		  i2=i+1;
		  for (j=0;j<=i;j++)
		  {
		   a=a|(1<<j);
		  }
		  for (k=0;k<8;k++)
		  {
		  	 display[k][3]|=table_cha_cu[c][k]&a;
		  	 display[k][4]|=table_cha_cu[c][k]&a;
		  }
		  delay(speed);
		  if(dong == 1){return;	} if(gaizhiflag==1){return;}
	 }
}
void transss()
{
	 uchar i,j;
	 for (i=0;i<8;i++)
	 {
		  for (j=0;j<8;j++)
	 	  display[i][j]<<=1;
	 }
}

void hy(uchar *tab,char v)
{//tab 数据容器 每个位置是一个十六进制码
	uchar a[64]={0};
	char i,j;
	for(i=0;i<8;i++)
		a[i*8]=tab[i];//控制8 16 24 32 40 48 56位灯列变为tab内相应数据
		if(key3==1){return;}//进入对应模式 key3都为3 
		else{zhen(a,v);}//展示灯阵
	delay(50);

	for(i=1;i<8;i++)
	{
	   for(j=0;j<8;j++)
		   a[i+j*8]=a[i-1+j*8];//竖列灯阵 前竖列等于后竖列数据
		if(key3==1){break;}
		else{zhen(a,v);}//展示
		delay(50);
		if(dong == 1){return;}
	}	
	
    for(i=0;i<7;i++)
	{
	    for(j=0;j<8;j++)
		    a[i+j*8]=0;//竖列灯阵 每一竖列都亮 其实i：0~7就是从后往前亮
		if(key3==1){break;}
		else{zhen(a,v);}
		delay(50);
		if(dong == 1){return;}
	}
		if(key3==1){return;}
		else{zhen(a,23);}
		delay(50);	
}

uchar daoxu(uchar x)
{
	uchar k=0;
	char i;
	for(i=0;i<8;i++)
	{
		if((x>>(7-i))&0x01)
			k|=0x01<<i;
	}
	return k;
}

void fun1(uchar *a,uchar d,uchar b,uchar c,uchar e)//滚动字幕数据处理
{
	char i;
	for(i=0;i<8;i++)
	{
		a[i]=e&0x01;
		e>>=1;
	}
	a[7]|=(c<<1);
	a[6]|=(c&0x80);
	for(i=0;i<6;i++)
	{
		a[5-i]|=((b<<(7-i))&0x80);
	}
	d=daoxu(d);
	a[0]|=((d>>1)&0x7e);
}

void zimu(uchar *x,char n,char v,int num)//滚动字幕,num表示循环次数,v表示滚动速度,n字符个数
{
	char i,j,k;
	uchar xdata a[64]={0},temp0[8],temp1[8],temp2[8],temp3[8],temp[8];
	for(i=0;i<8;i++)
	{
		temp0[i]=0;
		temp1[i]=0;
		temp2[i]=0;
		temp3[i]=0;
	}
	while(num--)
		for(j=0;j<n;j++)//滚动
		{
			for(k=7;k>=0;k--)//读取数据
				temp[7-k]=x[j*8+k];
			for(k=0;k<8;k++)//移动8位
			{
				for(i=0;i<8;i++)
				{
					temp0[i]=(temp0[i]<<1)|(temp1[i]>>7);
					temp1[i]=(temp1[i]<<1)|(temp2[i]>>7);
					temp2[i]=(temp2[i]<<1)|(temp3[i]>>7);
					temp3[i]=(temp3[i]<<1)|(temp[i]>>7);
					temp[i]<<=1;
					fun1(a+i*8,temp0[i],temp1[i],temp2[i],temp3[i]);
					if(dong == 1){ return;}	if(gai == 1){gai = 0; return;}
					if(abcd == 1){ abcd =0; return;}
				}
			if(key3==1){break;}
			else{zhen(a,v);}
				delay(50);
			}
		}
		if(abcd == 1){ abcd =0; return;} 	if(gai == 1){gai = 0; return;}
}
void move(uchar *a,char kind,char direction,char length)//动画沿轴移动多少距离
//kind=0 x轴,1 y轴,2 z轴；direction=0,负向,1正向
{
	char i,j;
	if(kind==0)
	{
		if(direction==1)
			for(i=0;i<64;i++)
				a[i]<<=length;
		else
			for(i=0;i<64;i++)
				a[i]>>=length;	
	}
	else if(kind==1)
	{
		if(direction==1)
			for(j=0;j<8;j++)
			{
				for(i=7;i>=length;i--)
					a[i+j*8]=a[i-length+j*8];
				for(i=0;i<length;i++)
					a[i+j*8]=0;			
			}	
		else
			for(j=0;j<8;j++)
			{
				for(i=0;i<length;i++)
					a[i+j*8]=a[i+length+j*8];
				for(i=(8-length);i<8;i++)
					a[i+j*8]=0;			
			}			
	}
	else
	{
		if(direction==1)
			for(j=0;j<8;j++)
			{
				for(i=7;i>=length;i--)
					a[j+i*8]=a[j+(i-length)*8];
				for(i=0;i<length;i++)
					a[j+i*8]=0;			
			}	
		else
			for(j=0;j<8;j++)
			{
				for(i=0;i<(8-length);i++)
					a[j+i*8]=a[j+(i+length)*8];
				for(i=(8-length);i<8;i++)
					a[j+i*8]=0;			
			}	
	}
}

void leitu(uchar *b,char num,char v) 
{
	uchar a[64]={0},p;
	char i,j,k,m;
	for(m=0;m<num;m++)
	{
		for(i=0;i<8;i++)
			for(k=0;k<8;k++)
				for(j=0;j<8;j++)
				{
					p=b[m*64+i*8+k]&(0x01<<j);
					if(p)
					{
						a[i*8+k]|=p;
						if(key3==1){break;}
						else{zhen(a,v);}
						delay(50);
						if(dong == 1){ return;}
					}
				}
		if(key3==1){break;}
		else{zhen(a,60);}
		delay(50);
		for(j=0;j<64;j++)
		{
			if(!a[j])
				continue;
			a[j]=0;
		if(key3==1){break;}
		else{zhen(a,v-1);}
			delay(50);
		}
		delays(30);
	}
}




void water1(char x,char y,char v)
{
	uchar a[64]={0};
	char i,r;
	a[7*8+y]=0x01<<x;
		if(key3==1){return;}
		else{zhen(a,v);}
	delay(50);
	if(dong == 1){return;}
	for(i=6;i>=0;i--)
	{
		a[i*8+y]=a[(i+1)*8+y];
		a[(i+1)*8+y]=0;
		if(key3==1){break;}
		else{zhen(a,v);}
		delay(25);
		if(dong == 1){return;}
	}//下落
	for(r=0;r<7;r++)
	{
		for(i=0;i<8;i++)
			a[i]=tab_water[r*16+7-y+i]>>(7-x);
		if(key3==1){break;}
		else{zhen(a,v+1);}
		delay(25);
		if(dong == 1){return;}
	}//扩散
}
void water2(char x1,char y1,char x2,char y2,char v)
{
	uchar a[64]={0};
	char i,r;
	a[7*8+y1]=0x01<<x1;
		if(key3==1){return;}
		else{zhen(a,v);}
	delay(50);
	if(dong == 1){return;}
	for(i=6;i>=0;i--)
	{
		move(a,2,0,1);
		if(i==5)
		{
			a[7*8+y2]=0x01<<x2;			
		}
		if(key3==1){break;}
		else{zhen(a,v);}
		delay(25);
		if(dong == 1){return;}
	}
	for(r=0;r<9;r++)
	{
		if(r<2)
			move(a,2,0,1);
		else
			for(i=0;i<8;i++)
				a[i]=tab_water[(r-2)*16+7-y2+i]>>(7-x2);		
		if(r<7)
			for(i=0;i<8;i++)
				a[i]|=(tab_water[r*16+7-y1+i]>>(7-x1));
		if(r==1)
			a[y2]|=0x01<<x2;
		if(key3==1){break;}
		else{zhen(a,v);}
		delay(25);
		if(dong == 1){return;}
	}
}
void water3(char x1,char y1,char x2,char y2,char x3,char y3,char v)
{//3水滴
	uchar a[64]={0};
	char i,r;
	a[7*8+y1]=0x01<<x1;
		if(key3==1){return;}
		else{zhen(a,v);	}
	delay(25);
	if(dong == 1){return;}
	for(i=6;i>=0;i--)
	{
		move(a,2,0,1);
		if(i==5)//第二点
			a[7*8+y2]=0x01<<x2;	
		if(i==3)
			a[7*8+y3]=0x01<<x3;	//第三点		
		if(key3==1){break;}
		else{zhen(a,v);}
		delay(25);
		if(dong == 1){return;}
	}
	for(r=0;r<11;r++)
	{
		if(r<4)
			move(a,2,0,1);
		if(r<11&&r>=4)
			for(i=0;i<8;i++)
				a[i]=tab_water[(r-4)*16+7-y3+i]>>(7-x3);
		if(r<9&&r>=2)
			for(i=0;i<8;i++)
				a[i]|=tab_water[(r-2)*16+7-y2+i]>>(7-x2);		
		if(r<7)
			for(i=0;i<8;i++)
				a[i]|=(tab_water[r*16+7-y1+i]>>(7-x1));
		if(r==1)
			a[y2]|=0x01<<x2;
		if(r==3)
			a[y3]|=0x01<<x3;
		if(key3==1){break;}
		else{zhen(a,v);}
		delay(25);
		if(dong == 1){return;}
	}
}

void print(uchar *a,char m)//m=0中空显示,m=1实心显示
{
	uchar p;
	char i,j,k;
	uchar b[64]={0};
	for(i=0;i<8;i++)
	{
		b[7*8+i]=0xff;
	}	
	for(i=0;i<8;i++)//行切换
	{
		for(j=0;j<8;j++)//点移动
		{
			p=a[i]&(0x01<<j);
			if(p)
			{
				for(k=6;k>0;k--)
				{
					if(m==1&&k==6)
					{;}
					else
						b[(k+1)*8+7-i]&=(~p);
					b[k*8+7-i]|=(0x01<<j);
					if(dong == 1){return;}
					if(key3==1){break;}
					else{zhen(b,1);}
					delay(50);
				}
				b[1*8+7-i]=0;
				b[7-i]|=p;
				if(dong == 1){return;}
				if(key3==1){break;}
				else{zhen(b,1);	 }
				delay(50);
			}
			b[7-i]|=p;
		}
	}
		if(key3==1){return;}
		if(dong == 1){return;}
		else{zhen(b,40); }
	delay(50);
	b[0]=0;
	for(j=7;j>0;j--)
	{
		for(i=7;i>0;i--)
		{
			b[i]=b[i-1];

		}
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(b,5);	}
			delay(50);		
	}
	M_EN=0;
}

void link_jb0(char v)
{
	uchar a[64]={0};
	char i;
	for(i=0;i<64;i++)
	{
		a[i]=0x80;
		if(key3==1){break;}
		else{zhen(a,v);}
		delay(50);
		if(dong == 1){return;}
	}
}
void jb0(char num,char v)///////////////////////////////
{
	char i,k;
	uchar c[64]={0};
	for(i=0;i<64;i++)
		c[i]=0x80;
		if(key3==1){return;}
		else{zhen(c,v);}
	delay(50);
	if(dong == 1){return;}
	while(num--)
		for(i=0;i<28;i++)
		{
			if(i<7)
				for(k=0;k<8;k++)
				{
					c[k*8]|=(0x80>>(i+1));
					c[k*8+7-i]=0;
				}
			else if(i<14)
				for(k=0;k<8;k++)
				{
					c[k*8+i-6]=0x01;
					c[k*8]>>=0x01;
				}
			else if(i<21)
				for(k=0;k<8;k++)
				{
					c[k*8+i-14]=0;
					c[k*8+7]|=(0x01<<(i-13));
				}
			else if(i<28)
				for(k=0;k<8;k++)
				{
					c[k*8+27-i]=0x80;
					c[k*8+7]<<=1;
				}
				if(dong == 1){return;}
				if(key3==1){break;}
				else{zhen(c,v);}
			delay(50);
		}
	M_EN=0;
}
void yinchu(uchar *table,char n,char v)
{
/****************************
n为帧数
******************************/
	char i,j,k;
	uchar a[64]={0},p;
	for(k=0;k<n;k++)
	{
		for(i=0;i<8;i++)
		{
			p=0xff;
			for(j=0;j<64;j++)
			{
				a[j]=(table[j+k*64]|(0x80>>i))&(p<<(7-i));
			}
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);	}
			delay(50);
		}
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(table+k*64,50);}
		delay(50);
	}

}
		
void link(char v)
{
/****************************
旋转衔接
******************************/
	char i,j,k;
	uchar a[64]={0};
	for(i=0;i<64;i++)
		a[i]=0x80;
		if(key3==1){return;}
		if(dong == 1){return;}
		else{zhen(a,3);	}
	delay(50);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(i<7)
				a[j*8+7-i]&=0x7f;
			a[j*8+i]|=(0x80>>i);
		}
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
		delay(50);
	}
	for(i=0;i<6;i++)
	{
		for(j=0;j<8;j++)
			for(k=0;k<8;k++)
				a[j*8+k]=tab_xuanzhuantiao[(i+8)*8+k];
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,3);}
		delay(50);
	}
}
void xuanzhuantiao(char kind,char num,char v)//空心旋转,kind=1实心,否则空心
{
	uchar a[64]={0};
	char i,j,k;
	while(num--)
	{
		for(i=0;i<14;i++)
		{
			for(j=0;j<8;j++)
			{
				for(k=0;k<8;k++)
				{
					if(k>1&&k<6&&j>1&&j<6&&kind!=1)
						a[k+j*8]=tab_xuanzhuantiao[i*8+k]&0xc3;
					else
						a[k+j*8]=tab_xuanzhuantiao[i*8+k];
				}
			}
			if(dong == 1){return;}
		if(key3==1){break;}
		else{zhen(a,v);}
			delay(50);
		}
	}
}
void xuanzhuantiao2(char num,char v)//空心旋转,kind=1实心,否则空心
{
	uchar a[64]={0};
	char i,j,k;
	while(num--)
		for(i=0;i<56;i++)
		{
			for(j=0;j<8;j++)
				for(k=0;k<8;k++)
					a[j*8+k]=tab_xuanzhuantiao2[i*8+k];
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
			delay(50);
		}
}

void qumianxuanzhuan(char kind,char num,char v)//曲面旋转
{
	uchar a[64]={0};
	char i,j,k;
	for(j=0;j<8;j++)
		for(i=0;i<8;i++)
			a[i+j*8]=tab_xuanzhuantiao[i];
		if(key3==1){return;}
		if(dong == 1){return;}
		else{zhen(a,v);}
	delay(50);
	if(kind==1)
	{
		for(j=1;j<8;j++)//顺时针初形变换
		{
			for(i=0;i<j;i++)
				for(k=0;k<8;k++)
					a[k+i*8]=tab_xuanzhuantiao[(j-i)*8+k];
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
			delay(50);
		}
		for(i=8;i<14;i++)
		{
			move(a,2,1,1);
			for(j=0;j<8;j++)
				a[j]=tab_xuanzhuantiao[i*8+j];
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
			delay(50);
		}
	}
	else
	{
		for(j=1;j<8;j++)//逆时针初形变换
		{
			for(i=0;i<j;i++)
				for(k=0;k<8;k++)
					a[k+i*8]=tab_xuanzhuantiao[(14-j+i)*8+k];
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
			delay(50);
		}
		for(i=7;i>=0;i--)
		{
			move(a,2,1,1);
			for(j=0;j<8;j++)
				a[j]=tab_xuanzhuantiao[i*8+j];
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);	}
			delay(50);
		}
	}

	while(num--)//主循环
	{
		if(kind==1)
			for(i=0;i<14;i++)
			{
				move(a,2,1,1);
				for(j=0;j<8;j++)
					a[j]=tab_xuanzhuantiao[i*8+j];
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
				delay(50);
			}
		else
			for(i=13;i>=0;i--)
			{
				move(a,2,1,1);				
				for(j=0;j<8;j++)
					a[j]=tab_xuanzhuantiao[i*8+j];
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
				delay(50);
			}
	}
	if(kind==1)
		for(j=0;j<7;j++)
		{
			for(i=7;i>=j;i--)
			{
				if(i>j)
					for(k=0;k<8;k++)
						a[k+i*8]=tab_xuanzhuantiao[(14-i+j)*8+k];
				else
					for(k=0;k<8;k++)
						a[k+i*8]=tab_xuanzhuantiao[k];
			}
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
			delay(50);
		}
	else
		for(j=1;j<7;j++)
		{
			for(i=7;i>=j;i--)
			{
				if(i>j)
					for(k=0;k<8;k++)
						a[k+i*8]=tab_xuanzhuantiao[(i-j)*8+k];
				else
					for(k=0;k<8;k++)
						a[k+i*8]=tab_xuanzhuantiao[k];
			}
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
			delay(50);
		}
}

void qumianxuanzhuan2(char num,char v)//曲面旋转
{
	uchar a[64]={0};
	char i,j,k;
	for(j=0;j<8;j++)
		for(i=0;i<8;i++)
			a[i+j*8]=tab_xuanzhuantiao[i];
		if(key3==1){return;}
		if(dong == 1){return;}
		else{zhen(a,v);}
	delay(50);
	for(j=1;j<8;j++)
	{
		for(i=0;i<j;i++)
			for(k=0;k<8;k++)
				a[k+i*8]=tab_xuanzhuantiao[(14-j+i)*8+k];
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
		delay(50);
	}
	while(num--)
	{
		for(j=1;j<8;j++)
		{
			move(a,2,1,1);
			for(i=0;i<j;i++)
			{
				for(k=0;k<8;k++)
				{
					if(j!=7|i!=0)
						a[i*8+k]=tab_xuanzhuantiao[k+(j+7-i)*8];
					else
						a[k]=tab_xuanzhuantiao[k];
				}
			}
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
			delay(50);
		}
		for(j=1;j<8;j++)
		{
			move(a,2,1,1);
			for(i=0;i<j;i++)
			{
				for(k=0;k<8;k++)
					a[i*8+k]=tab_xuanzhuantiao[k+(14-j+i)*8];
			}
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(a,v);}
			delay(50);
		}
	}
}

void donghua(uchar *tab,uchar num,uchar n,char v)
{
	char i;
	while(n--)
	{
		for(i=0;i<num;i++)//清空
		{
		if(key3==1){break;}
		if(dong == 1){return;}
		else{zhen(tab+i*64,v);}
			delay(50);
		}
	}
}
void xzcube()
{
		char i;
		donghua(y_table,6,8,8);
		for(i=0;i<26;i++)
		{
			if(i==12||i==13||i==14)
				{		if(key3==1){break;}	 if(dong == 1){return;}
		else{zhen(yx_table+i*64,30);}
				delay(50);}
			else {
						if(key3==1){break;}if(dong == 1){return;}
		else{zhen(yx_table+i*64,14);}
				delay(50);  }
		}
		donghua(x_table,6,8,8);
		for(i=0;i<26;i++)
		{
			if(i==12||i==13||i==14)
				{		if(key3==1){break;}	if(dong == 1){return;}
		else{zhen(xz_table+i*64,30);}
				delay(50);}
			else{
						if(key3==1){break;}	if(dong == 1){return;}
		else{zhen(xz_table+i*64,14);}
				delay(50);}
		}
		donghua(z_table,6,8,8);
}

void produce_cube(uchar *a,char n) 
{
	char i,j;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		{
			if(j<n&&i<n)
				a[j+i*8]=0xff>>(8-n);
			else
				a[j+i*8]=0;
		}	
}
void link00()
{
	uchar a[64]={0};
	char i;
	for(i=10;i>7;i--)
	{
				if(key3==1){break;}	 if(dong == 1){return;}
		else{zhen(bianxing_table+i*64,70);}
		delay(50);
	}
	produce_cube(a,6);
	move(a,1,1,1);
	move(a,0,1,1);
			if(key3==1){return;}if(dong == 1){return;}
		else{zhen(a,110);}
	delay(50);
	produce_cube(a,8);
			if(key3==1){return;} if(dong == 1){return;}
		else{zhen(a,110);}
	delay(50);
}

void shensuo(uchar v)
{
	char i,j;
	uchar a[64]={0};
	for(i=0;i<64;i++)
		a[i]=0xff;
	for(i=0;i<7;i++)
	{
		move(a,0,0,1);
				if(key3==1){break;}	
		else{zhen(a,v);}
		delay(50);
	}
	for(i=0;i<7;i++)
	{
		move(a,0,1,1);
		for(j=0;j<64;j++)
			a[j]|=0x01;
				if(key3==1){break;}if(dong == 1){return;}
		else{zhen(a,v);}
		delay(50);
	}
	for(i=0;i<7;i++)
	{
		move(a,2,0,1);
				if(key3==1){break;}	
		else{zhen(a,v);}
		delay(50);
	}
	for(i=0;i<7;i++)
	{
		move(a,2,1,1);
		for(j=0;j<8;j++)
			a[j]|=0xff;
				if(key3==1){break;}if(dong == 1){return;}
		else{zhen(a,v);}
		delay(50);
	}
	for(i=7;i>0;i--)
	{
		for(j=0;j<8;j++)
			a[j*8+i]=0;
				if(key3==1){break;}	
		else{zhen(a,v);	}
		delay(50);
	}
	for(i=1;i<8;i++)
	{
		for(j=0;j<8;j++)
			a[j*8+i]|=0xff;
				if(key3==1){break;}if(dong == 1){return;}
		else{zhen(a,v);}
		delay(50);
	}
}

void produce_empty(uchar *a,char n)//0<n<=8,注意n不能为0
{
	char j;
	uchar p;
	for(j=0;j<64;j++)
		a[j]=0;
	p=0xff>>(8-n);
/************X4列*************/
	a[(n-1)*8+n-1]=p;
	a[(n-1)*8]=p;
	a[0]=p;
	a[n-1]=p;
	for(j=0;j<n;j++)
	{
		p=(0x01|(0x01<<(n-1)));
/************竖直4列*************/
		a[j*8]|=p;
		a[j*8+n-1]|=p;
/************Y4列*************/
		a[j]|=p;
		a[(n-1)*8+j]|=p;
	}
}
void cube(char empty,char kind,char v)
{
	uchar a[64]={0};
	char i;
	for(i=1;i<=8;i++)//生成
	{
		if(empty==0)
			produce_cube(a,i);
		else
			produce_empty(a,i);
		if(kind==0)
			{;}
		else if(kind==1)
			move(a,1,1,8-i);
		else if(kind==2)
		{
			move(a,1,1,8-i);
			move(a,0,1,8-i);
		}
		else
			move(a,0,1,8-i);
				if(key3==1){break;}	if(dong == 1){return;}
		else{zhen(a,v);	}
		delay(50);
	}
	for(i=7;i>0;i--)//退出
	{
		if(empty==0)
			produce_cube(a,i);
		else
			produce_empty(a,i);
		if(kind==0)
		{
			move(a,1,1,8-i);
			move(a,0,1,8-i);
		}
		else if(kind==1)
			move(a,0,1,8-i);
		else if(kind==2)
			{;}
		else
			move(a,1,1,8-i);				
				if(key3==1){break;}	if(dong == 1){return;}
		else{zhen(a,v);}
		delay(50);
	}
}
 

void shandian(char v)
{
		char i,j;
		uchar a[64];
		for(i=0;i<64;i++)
			a[i]=tab_shandian[64*21+i];
		for(i=0;i<22;i++)
					if(key3==1){break;}
		else{zhen(tab_shandian+64*i,v);}
			delay(50);
		for(i=0;i<22;i++)
		{
			for(j=0;j<64;j++)
				a[j]=a[j]&(~tab_shandian[64*i+j]);
					if(key3==1){break;}
		else{zhen(a,v);}
			delay(50);
		}
}

void szfc0(char v)//数字上浮
{
	char i,j;
	uchar a[64];
	for(i=0;i<64;i++)
	{
		a[i]=0;
	}
	for(j=0;j>=9;j++)
	{
		for(i=7;i>=0;i--)
		{
			a[i*8+3]=szfc_table[j*8+i];
			a[i*8+4]=szfc_table[j*8+i];
		}
		if(key3==1){break;}if(dong == 1){return;}
		else{zhen(a,v);}
		delay(50);
		for(i=0;i<64;i++)
		{
			a[i]=0;
		}
		zhen(a,20);
		delay(50);
	}
}

void rain(char menu,char num,char v)
{//menu=0,up;menu=1,down
	uchar a[64]={0};
	char i,j;
	if(menu==0)
	{
		for(i=0;i<8;i++)
			a[i]=tab_rain[i];
				if(key3==1){return;} if(dong == 1){return;}
		else{zhen(a,v);}
		delay(50);
		for(i=1;i<8;i++)
		{
			move(a,2,1,1);
			for(j=0;j<8;j++)
				a[j]=tab_rain[i*8+j];
					if(key3==1){break;}
		else{zhen(a,v);}
			delay(50);
		}	
		while(num--)
		{	
			for(i=0;i<8;i++)
			{
				move(a,2,1,1);
				for(j=0;j<8;j++)
					a[j]=tab_rain[i*8+j];
						if(key3==1){break;}	if(dong == 1){return;}
		else{zhen(a,v);}
				delay(50);
			}
		}
	}
	else
	{
		for(i=0;i<8;i++)
			a[7*8+i]=tab_rain[i];
				if(key3==1){return;}
		else{zhen(a,v);}
		delay(50);
		for(i=1;i<8;i++)
		{
			move(a,2,0,1);
			for(j=0;j<8;j++)
				a[7*8+j]=tab_rain[i*8+j];
					if(key3==1){break;}
		else{zhen(a,v);}
			delay(50);
		}
		while(num--)
		{	
			for(i=0;i<8;i++)
			{
				move(a,2,0,1);
				for(j=0;j<8;j++)
					a[j+7*8]=tab_rain[i*8+j];
						if(key3==1){break;}	if(dong == 1){return;}
		else{zhen(a,v);}
				delay(50);
			}				
		}
	}
}


void box_apeak_xy(uchar x1,uchar y1,uchar z1,uchar x2,uchar y2,uchar z2,uchar fill,uchar le)
{
	uchar i;
	max(&z1,&z2);
	if (fill)
	{
		for (i=z1;i<=z2;i++)
		{
			line (x1,y1,i,x2,y2,i,le);
		}
	}
	else
	{
		line (x1,y1,z1,x2,y2,z1,le);
		line (x1,y1,z2,x2,y2,z2,le);
		line (x2,y2,z1,x2,y2,z2,le);
		line (x1,y1,z1,x1,y1,z2,le);
	}
}
void roll_apeak_yz(uchar n,uint speed)
{
	uchar xdata i;
	switch(n)
	{
		case 1:
			for (i=0;i<7;i++)
			{
				display[i][7]=0;
				display[7][6-i]=255;
				delay(speed);
				if(dong == 1){return;	}
			};
			break;
		case 2:
			for (i=0;i<7;i++)
			{
				display[7][7-i]=0;
				display[6-i][0]=255;
				delay(speed);
				if(dong == 1){return;	}
			};
			break;
		case 3:
			for (i=0;i<7;i++)
			{
				display[7-i][0]=0;
				display[0][i+1]=255;
				delay(speed);
				if(dong == 1){return;	}
			};
			break;
		case 0:
			for (i=0;i<7;i++)
			{
				display[0][i]=0;
				display[i+1][7]=255;
				delay(speed);
				if(dong == 1){return;	}
			};
	}
}
void point(uchar x,uchar y,uchar z,uchar le)  
{
	uchar ch1,ch0;
	ch1=1<<x;
	ch0=~ch1;
	if (le)
		display[z][y]=display[z][y]|ch1;
	else
		display[z][y]=display[z][y]&ch0;
}
void line(uchar x1,uchar y1,uchar z1,uchar x2,uchar y2,uchar z2,uchar le)
{
	char t,a,b,c,a1,b1,c1,i;
	a1=x2-x1;
	b1=y2-y1;
	c1=z2-z1;
	t=maxt(abss(a1),abss(b1),abss(c1));
	a=x1*10;
	b=y1*10;
	c=z1*10;
	a1=a1*10/t;
	b1=b1*10/t;
	c1=c1*10/t;
	for (i=0;i<t;i++)
	{
		point(abs(a),abs(b),abs(c),le);
		a+=a1;
		b+=b1;
		c+=c1;
	}
	point(x2,y2,z2,le);
}
void trans(uchar z,uint speed)	   //	 左移动层
{
	uchar i,j;
	for (j=0;j<8;j++)
	{
		for (i=0;i<8;i++)
		{
			display[z][i]>>=1;
		}
		delay(speed);
		if(dong == 1){return;	}
	}
}
void roll_apeak_xy(uchar n,uint speed)
{
	uchar xdata i;
	switch(n)
	{
		case 1:
			for (i=0;i<7;i++)
			{
				line(0,i,0,0,i,7,0);
				line(i+1,7,0,i+1,7,7,1);
				delay(speed);
			};
			break;
		case 2:
			for (i=0;i<7;i++)
			{
				line(i,7,0,i,7,7,0);
				line(7,6-i,0,7,6-i,7,1);
				delay(speed);
			};
			break;
		case 3:
			for (i=0;i<7;i++)
			{
				line(7,7-i,0,7,7-i,7,0);
				line(6-i,0,0,6-i,0,7,1);
				delay(speed);
			};
			break;
		case 0:
			for (i=0;i<7;i++)
			{
				line(7-i,0,0,7-i,0,7,0);
				line(0,i+1,0,0,i+1,7,1);
				delay(speed);
			};
	}
}
void roll_3_xy(uchar n,uint speed)
{
	uchar xdata i;
	switch(n)
	{
		case 1:
			for (i=0;i<8;i++)
			{
				box_apeak_xy (0,i,0,7,7-i,7,1,1);
				delay(speed);
				if (i<7)
					box_apeak_xy (3,3,0,0,i,7,1,0);
			};
			break;
		case 2:
			for (i=0;i<8;i++)
			{
				box_apeak_xy (7-i,0,0,i,7,7,1,1);
				delay(speed);
				if (i<7)
					box_apeak_xy (3,4,0,i,7,7,1,0);
			};
			break;
		case 3:
			for (i=0;i<8;i++)
			{
				box_apeak_xy (0,i,0,7,7-i,7,1,1);
				delay(speed);
				if (i<7)
					box_apeak_xy (4,4,0,7,7-i,7,1,0);
			};
			break;
		case 0:
		for (i=0;i<8;i++)
		{
			box_apeak_xy (7-i,0,0,i,7,7,1,1);
			delay(speed);
			if (i<7)
				box_apeak_xy (4,3,0,7-i,0,7,1,0);
		};
	}
}
void trailler(uint speed)  //IC顺向移动函数 清除后3
{
	char i,j;
	for (i=6;i>=-3;i--)
	{
		if (i>=0)
		{
			for (j=0;j<8;j++)
			display[j][i]=display[j][i+1];
		}
		if (i<4)
		{
			for (j=0;j<8;j++)
			display[j][i+4]=0;
		}
		delay(speed);
		if(dong == 1){return;}	 if(gaizhiflag==1){return;}
	}
}


// 下雨效果飘出字移动出去
void piaozhi(uchar P_zf[11][8],uint speed,uchar a)	//a为个数
{
	uchar i,j,k,z;
	roll_apeak_yz(1,10000);
	roll_apeak_yz(2,10000);
	roll_apeak_yz(3,10000);
	delay(60000);delay(60000);
	if(dong == 1){return;}if(gai==1){gai=0;return;}	if(gaizhiflag==1){gaizhiflag=0;return;}
	for (i=0;i<a;i++)
	{
		for (j=0;j<8;j++)
		{
			for (k=0;k<8;k++)
			{
				if ((P_zf[i][j]>>k)&1)
				{
					for (z=1;z<8;z++)
					{
						point (j,7-k,z,1);
						if (z-1)
						point (j,7-k,z-1,0);
						delay(speed);
						if(dong == 1){return;} if(gai==1){gai=0;return;}  if(gaizhiflag==1){gaizhiflag=0;return;}
					}
				}
			}
		}
		delay(60000);delay(60000);delay(60000);delay(60000);delay(60000);
		trans(7,15000);
		if(dong == 1){return;}	 if(gai==1){gai=0;return;} if(gaizhiflag==1){gaizhiflag=0;return;}
	}	
}

/*From now on,the function below is to display the flash.*/
//动画1
void flash_1()
{
     uchar i;

	 clear(0);
	 for(i=4;i>0;i--)
	 {
	 	type(i,0);
	 	delay(60000);	
	 }
	 if(dong == 1){dong = 0;return;	}
}
//动画2
void flash_2()
{
    uchar i;
    clear(0);
    for (i=129;i>0;i--)
    {
        cirp(i-2,0,1);
        delay(5000);
        cirp(i-1,0,0);
    }
 	delay(4000);
	for (i=0;i<136;i++)
	{
		  cirp(i,1,1);
		  delay(5000);
		  cirp(i-8,1,0);
		  if(dong == 1){dong = 0;return;	}
	}
 	delay(5000);
  	for (i=129;i>0;i--)
 	{
 		cirp(i-2,0,1);
  		delay(5000);
 	} 
	for (i=16;i>0;i--)
 	{
		 delay(40000);
	}
 	 for (i=0;i<128;i++)
 	{
  		cirp(i-8,1,0);
  		delay(5000);
		if(dong == 1){dong = 0;return;	}
 	}
 	delay(40000);
}
//动画3
void flash_3()
{
 	char i;
	 for (i=0;i<8;i++)
	 {
		  box_apeak_xy(0,i,0,7,i,7,1,1);
		  delay(10000);
		  if (i<7)
		  box_apeak_xy(0,i,0,7,i,7,1,0);
		  if(dong == 1){dong = 0;return;	}
	 }
	 for (i=7;i>=0;i--)
	 {
		  box_apeak_xy(0,i,0,7,i,7,1,1);
		  delay(10000);
		  if (i>0)
		  box_apeak_xy(0,i,0,7,i,7,1,0);
	 }
	 for (i=0;i<8;i++)
	 {
		  box_apeak_xy(0,i,0,7,i,7,1,1);
		  delay(10000);
		  if (i<7)
		  box_apeak_xy(0,i,0,7,i,7,1,0);
		  if(dong == 1){dong = 0;return;	}
	 }
	 
}
//动画4
void flash_4()
{
	 char i,j,an[8];
	 for (j=7;j<15;j++)
	  	an[j-7]=j;
	 for (i=0;i<=16;i++)
	 {
		  for (j=0;j<8;j++)
		  {
			   if ((an[j]<8)&(an[j]>=0))
			   line(0,an[j],j,7,an[j],j,1);
		  }
		  for (j=0;j<8;j++)
		  {
			   if (((an[j]+1)<8)&(an[j]>=0))
			   line(0,an[j]+1,j,7,an[j]+1,j,0);
		  }
		  for (j=0;j<8;j++)
		  {
			   if (an[j]>0)
			   an[j]--;
		  }
		  delay(8000);
		  if(dong == 1){dong = 0;return;	}
	 }
	 for (j=0;j<8;j++)
	  	an[j]=1-j;
	 for (i=0;i<=16;i++)
	 {
		  for (j=0;j<8;j++)
		  {
			   if ((an[j]<8)&(an[j]>=0))
			   line(0,an[j],j,7,an[j],j,1);
		  }
		  for (j=0;j<8;j++)
		  {
			   if (((an[j]-1)<7)&(an[j]>0))
			   line(0,an[j]-1,j,7,an[j]-1,j,0);
		  }
		  for (j=0;j<8;j++)
		  {
			   if (an[j]<7)
			   an[j]++;
		  }
		  delay(8000);
		  if(dong == 1){dong = 0;return;	}
	 }
}
//动画5
void flash_5()
{
	 uint a=6000;
	 char i=8,j,an[4];

	 for(j=7;j<11;j++)
	 	an[j-7]=j;
	 while(i--)
	 {
		  for (j=0;j<4;j++)
		  {
			   if (an[j]<8)
			   box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
			   if (an[j]<7)
			   box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);
		  }
		  for (j=0;j<4;j++)
		  {
			   if (an[j]>3)
			   an[j]--;
		  }
		  delay(a);
	 }
	 i=3;
	 for (j=0;j<4;j++)
	 	an[j]=5-j;
	 while(i--)
	 {
		  for (j=1;j<4;j++)
		  {
			   if (an[j]<4)
			   box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
			   if (an[j]<3)
			   box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);
		  }
		  for (j=0;j<4;j++)
		  {
			   if (an[j]>0)
			   an[j]--;
		  }
		  delay(a);
		  if(dong == 1){dong = 0;return;	}
	 }
	 i=3;
	 for (j=1;j<4;j++)
		 an[j]=4-j;
	 while(i--)
	 {
		  for (j=1;j<4;j++)
		  {
			   if (an[j]>=0)
			   box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
			   if (an[j]>0)
			   box_apeak_xy(j,an[j]-1,j,7-j,an[j]-1,7-j,0,0);
		  }
		  for (j=1;j<4;j++)
		  {
			   if (an[j]<3)
			   an[j]++;
		  }
		  delay(a);
	 }
	 i=3;
	 for (j=0;j<4;j++)
	 	an[j]=j+1;
	 while(i--)
	 {
		  for (j=1;j<4;j++)
		  {
			   if (an[j]>3)
			   box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
			   if (an[j]>3)
			   box_apeak_xy(j,an[j]-1,j,7-j,an[j]-1,7-j,0,0);
		  }
		  for (j=0;j<4;j++)
		  	an[j]++;
		  delay(a);
		  if(dong == 1){dong = 0;return;}
	 }
	 i=3;
	 for (j=3;j<6;j++)
	  	an[j-2]=j;
	 while(i--)
	 {
		  for (j=1;j<4;j++)
		  {
			   box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
			   box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);
		  }
		  for (j=0;j<4;j++)
		  {
			   if (an[j]>3)
			   an[j]--;
		  }
		  delay(a);
	 }
	 i=3;
	 for (j=0;j<4;j++)
	 	an[j]=5-j;
	 while(i--)
	 {
		  for (j=1;j<4;j++)
		  {
			   if (an[j]<4)
			   box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
			   if (an[j]<3)
			   box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);
		  }
		  for (j=0;j<4;j++)
		  {
			   if (an[j]>0)
			   an[j]--;
		  }
		  delay(a);
		  if(dong == 1){dong = 0;return;	}
	 }
	 i=3;
	 for (j=0;j<4;j++)
	 	an[j]=3-j;
	 an[0]=2;
	 while(i--)
	 {
		  for (j=0;j<3;j++)
		  {
		   if (an[j]>=0)
		    box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
		   if (an[j]>=0)
		    box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);
		  }
		  for (j=0;j<4;j++)
		  {
		   if (j<5-i)
		   an[j]--;
		  }
		  delay(a);
	 }
	 i=10;
	 for (j=0;j<4;j++)
	 	 an[j]=j-2;
	 while(i--)
	 {
		  for (j=0;j<4;j++)
		  {
			   if (an[j]>=0)
			   box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
			   if (an[j]>=0)
			   box_apeak_xy(j,an[j]-1,j,7-j,an[j]-1,7-j,0,0);
		  }
		  for (j=0;j<4;j++)
		  {
			   if (an[j]<7)
			   an[j]++;
		  }
		  delay(a);
		  if(dong == 1){dong = 0;return;	}
	 }
}
//动画6
void flash_6()
{
	 piaozhi(table_3p,3000,3);
	 if(dong == 1){dong = 0;return;	}
}
//动画7
void flash_7()
{
	 uchar i;
	 uint a=3000;
	 for(i=0;i<4;i++)
	 {
	 	 roll_apeak_yz(i,6000);
		 if(dong == 1){dong = 0;return;	}
	 }
	 	 
	 for (i=0;i<8;i++)
	 {
		  box_apeak_xy (0,i,0,7-i,i,7,1,1);
		  delay(a);
	 }
	 for(i=0;i<4;i++)
	 {
	 	 delay(15000);
		 roll_3_xy(i,a);
		 if(dong == 1){dong = 0;return;	}
	 }
	 for (i=7;i>0;i--)
	 {
		  box_apeak_xy(i,0,0,i,7,7,1,0);
		  delay(a);
		  if(dong == 1){dong = 0;return;	}
	 }
}
//动画8
void flash_8()
{
	 uchar i;
	 for (i=5;i<8;i++)
	 {
		  tranoutchar(i,6000);
		  delay(50000);
		  if(dong == 1){dong = 0;return;	}
	 }
}
//动画9
void flash_9()
{
	 char i;
	 uchar j,an[8],x,y,t,x1,y1;
	 for (i=0;i<8;i++)
	 {
		  box_apeak_xy (i,0,0,i,7,7,1,1);
		  if (i)
		  box_apeak_xy (i-1,0,0,i-1,7,7,1,0);
		  delay(8000);
	 }
	 roll_apeak_xy(3,8000);
	 roll_apeak_xy(0,8000);
	 roll_apeak_xy(1,8000);
	 if(dong == 1){dong = 0;return;	}
	 for (i=0;i<7;i++)
	 {
		  line(6-i,6-i,0,6-i,6-i,7,1);
		  line(i,7,0,i,7,7,0);
		  delay(8000);
	 }
	 for (i=0;i<8;i++)
	  	an[i]=14;
	 for (i=0;i<85;i++)
	 {
		  clear(0);
		  for (j=0;j<8;j++)
		  {
			   t=an[j]%28;
			   x=dat2[t]>>5;
			   y=(dat2[t]>>2)&0x07;
			   t=(an[j]-14)%28;
			   x1=dat2[t]>>5;
			   y1=(dat2[t]>>2)&0x07;
			   line(x,y,j,x1,y1,j,1);
		  }
		  for (j=0;j<8;j++)
		  {
			  if ((i>j)&(j>i-71))
			  	an[j]++;
		  }
		  delay(5000);
		  if(dong == 1){dong = 0;return;	}
	 }
	 for (i=0;i<85;i++)
	 {
		  clear(0);
		  for (j=0;j<8;j++)
		  {
			   t=an[j]%28;
			   x=dat2[t]>>5;
			   y=(dat2[t]>>2)&0x07;
			   t=(an[j]-14)%28;
			   x1=dat2[t]>>5;
			   y1=(dat2[t]>>2)&0x07;
			   line(x,y,j,x1,y1,j,1);
		  }
		  for (j=0;j<8;j++)
		  {
			  if ((i>j)&(j>i-71))
			 	 an[j]--;
		  }
		  delay(5000);
	 }
	 for (i=0;i<29;i++)
	 {
		  clear(0);
		  t=an[0]%28;
		  x=dat2[t]>>5;
		  y=(dat2[t]>>2)&0x07;
		  t=(an[0]-14)%28;
		  x1=dat2[t]>>5;
		  y1=(dat2[t]>>2)&0x07;
		  box_apeak_xy(x,y,0,x1,y1,7,0,1);
		  box_apeak_xy(x,y,1,x1,y1,6,0,1);
		  an[0]++;
		  delay(5000);
		  if(dong == 1){dong = 0;return;	}
	 }
	 for (i=0;i<16;i++)
	 {
		  clear(0);
		  t=an[0]%28;
		  x=dat2[t]>>5;
		  y=(dat2[t]>>2)&0x07;
		  t=(an[0]-14)%28;
		  x1=dat2[t]>>5;
		  y1=(dat2[t]>>2)&0x07;
		  box_apeak_xy(x,y,0,x1,y1,7,1,1);
		  an[0]--;
		  delay(5000);
	 }
	 for (i=0;i<8;i++)
	 {
		  line(i,i,0,0,0,i,0);
		  delay(5000);
	 }
	 for (i=1;i<7;i++)
	 {
		  line(i,i,7,7,7,i,0);
		  delay(5000);
		  if(dong == 1){dong = 0;return;	}
	 }
	 for (i=1;i<8;i++)
	 {
		  clear(0);
		  box(7,7,7,7-i,7-i,7-i,0,1);
		  delay(8000);
	 }
	 for (i=1;i<7;i++)
	 {
		  clear(0);
		  box(0,0,0,7-i,7-i,7-i,0,1);
		  delay(8000);
	 }
	 for (i=1;i<8;i++)
	 {
		  clear(0);
		  box(0,0,0,i,i,i,0,1);
		  delay(8000);
	 }
	 for (i=1;i<7;i++)
	 {
		  clear(0);
		  box(7,0,0,i,7-i,7-i,0,1);
		  delay(8000);
	 }
	 for (i=1;i<8;i++)
	 {
		  box(7,0,0,7-i,i,i,1,1);
		  delay(8000);
	 }
	 for (i=1;i<7;i++)
	 {
		  clear(0);
		  box(0,7,7,7-i,i,i,1,1);
		  delay(8000);	
		  if(dong == 1){dong = 0;return;	}	  
	 }
}
//动画10
void flash_10()
{
	 uchar i,j,an[4],x,y,t;
	 for (i=1;i<7;i++)
	 {
		  clear(0);
		  box(0,6,6,1,7,7,1,1);
		  box(i,6,6-i,i+1,7,7-i,1,1);
		  box(i,6,6,i+1,7,7,1,1);
		  box(0,6,6-i,1,7,7-i,1,1);
		  box(0,6-i,6,1,7-i,7,1,1);
		  box(i,6-i,6-i,i+1,7-i,7-i,1,1);
		  box(i,6-i,6,i+1,7-i,7,1,1);
		  box(0,6-i,6-i,1,7-i,7-i,1,1);
		  delay(10000);
		  if(dong == 1){dong = 0;return;	}
	 }
	 for (i=0;i<4;i++)
	 {
		  an[i]=6*i;
	 }
	 for (i=0;i<35;i++)
	 {
		  clear(0);
		  for(j=0;j<4;j++)
		  {
			   t=an[j]%24;
			   x=dat3[t]>>4;
			   y=dat3[t]&0x0f;
			   box(x,y,0,x+1,y+1,1,1,1);
			   box(x,y,6,x+1,y+1,7,1,1);
		  }
		  for (j=0;j<4;j++)
		  	an[j]++;
		  delay(5000);
		  if(dong == 1){dong = 0;return;}
	 }
	 for (i=0;i<35;i++)
	 {
		  clear(0);
		  for(j=0;j<4;j++)
		  {
			   t=an[j]%24;
			   x=dat3[t]>>4;
			   y=dat3[t]&0x0f;
			   box(x,y,0,x+1,y+1,1,1,1);
			   box(x,y,6,x+1,y+1,7,1,1);
		  }
		  for (j=0;j<4;j++)
		 	 an[j]--;
		  delay(5000);
		  if(dong == 1){dong = 0;return;	}
	 }
	 for (i=0;i<35;i++)
	 {
		  clear(0);
		  for(j=0;j<4;j++)
		  {
			   t=an[j]%24;
			   x=dat3[t]>>4;
			   y=dat3[t]&0x0f;
			   box(x,0,y,x+1,1,y+1,1,1);
			   box(x,6,y,x+1,7,y+1,1,1);
		  }
		  for (j=0;j<4;j++)
		 	 an[j]++;
		  delay(5000);
		  if(dong == 1){dong = 0;return;	}
	 }
	 for (i=0;i<36;i++)
	 {
		  clear(0);
		  for(j=0;j<4;j++)
		  {
			   t=an[j]%24;
			   x=dat3[t]>>4;
			   y=dat3[t]&0x0f;
			   box(x,0,y,x+1,1,y+1,1,1);
			   box(x,6,y,x+1,7,y+1,1,1);
		  }
		  for (j=0;j<4;j++)
		  	an[j]--;
		  delay(5000);
		  if(dong == 1){dong = 0;return;	}
	 }
	 for (i=6;i>0;i--)
	 {
		  clear(0);
		  box(0,6,6,1,7,7,1,1);
		  box(i,6,6-i,i+1,7,7-i,1,1);
		  box(i,6,6,i+1,7,7,1,1);
		  box(0,6,6-i,1,7,7-i,1,1);
		  box(0,6-i,6,1,7-i,7,1,1);
		  box(i,6-i,6-i,i+1,7-i,7-i,1,1);
		  box(i,6-i,6,i+1,7-i,7,1,1);
		  box(0,6-i,6-i,1,7-i,7-i,1,1);
		  delay(10000);	
		  if(dong == 1){dong = 0;return;	}	  
 	 }
}
//动画11
void flash_11()
{
	 uchar i,j,t,x,y;
	 uchar code daa[13]={0,1,2,0x23,5,6,7,6,5,0x23,2,1,0};
	 clear(0);
	 for (j=0;j<5;j++)
	 {
		  for (i=0;i<13;i++)
		  {
			   if (daa[i]>>4)
			   {
				    t=daa[i]&0x0f;
				    line (0,0,t+1,0,7,t+1,1);
			   }
			   else
			        t=daa[i];
			   line (0,0,t,0,7,t,1);
			   transss();
			   delay(7000);
			   if(dong == 1){dong = 0;return;	}
		  }
	 }
	 for (j=1;j<8;j++)
	 {
		  if (j>3)
		   		t=4;
		  else
		    	t=j;
		  for (i=0;i<24;i+=j)
		  {
			   x=dat3[i]>>4;
			   y=dat3[i]&0x0f;
			   box_apeak_xy(0,x,y,0,x+1,y+1,1,1);
			   transss();
			   delay(7000);
			   if(dong == 1){dong = 0;return;	}
		  }
	 }
	 for (j=1;j<8;j++)
	 {
		  if (j>3)
		   	   t=4;
		  else
		   	   t=j;
		  for (i=0;i<24;i+=j)
		  {
			   x=dat3[i]>>4;
			   y=dat3[i]&0x0f;
			   point (0,x,y,1);
			   transss();
			   delay(7000);
			   if(dong == 1){dong = 0;return;	}			   
		  }
	 }
}
//动画12
void flash_12()
{ 
	 clear(0);
	 rolldisplay_yd(10000);
}
//动画13
void flash_13()
{     
	uchar i;
	for(i=0;i<8;i++)
	{
		clear(0);
		type(i,7);
		trailler(5000);
		delay(30000);
		if(dong == 1){dong = 0;return;}	if(gai == 1){gai = 0;return;} if(gaizhiflag==1){gaizhiflag=0;return;}	
	}   
}
//动画14
void flash_14()
{
	uchar i;
	for(i=0;i<8;i++)
	{
	 	clear(0);
     	type_sj(i,i);
     	delay(30000);
	} 
	for(i=0;i<8;i++)
	{
		clear(0);
     	type_sj(i,7-i);
     	delay(20000);
	}      
	 if(dong == 1){dong = 0;return;}
}
//动画15
void flash_15()	 
{
	rain(1,10,9);
	rain(0,10,9);
}
//动画16
void flash_16()
{
	zimu(ZM,12,12,1);
	if(dong == 1){dong = 0;  return;} 
}
//动画17
void flash_17()
{
	clear(0);
	type(0,7);
	delay(20000);
	trailler(4000);
	delay(20000);
	if(dong == 1){dong = 0;return;	}
}
//动画18
void flash_18()
{
	 piaozhi(table_3p_zf,2500,9);
	 if(dong == 1){dong = 0;return;	} if(gai==1){gai=0;return;}	
}
//动画19
void flash_19()
{
	uchar i;
	for (i=0;i<9;i++)
	{
		tranoutchar_cu(i,8000);
		delay(40000);
		delay(40000);
		if(dong == 1){dong = 0;return;	}if(gai==1){gai=0;return;}  if(gaizhiflag==1){gaizhiflag=0;return;}
	}
}
//动画20
void flash_20()
{
	uchar a[64]={0};
	char i;
	for(i=0;i<4;i++)
	{	
		a[i*8+7]=0xff;
		a[(7-i)*8+7]=0xff;
		if(key3==1)
		{
			break;
		}
		else
		{
			zhen(a,10);
		}
		delay(50);
	}
	if(key3==1)
	{
		return;
	}
	else
	{
		zhen(a,30);
	}
	for(i=3;i>=0;i--)
	{
		a[i*8+7]=0;
		a[(7-i)*8+7]=0;
		if(key3==1)
		{
			break;
		}
		else
		{
			zhen(a,10);
		}
		delay(50);
	}
	if(dong == 1){dong = 0;return;}
}
//动画21
void flash_21()
{
 	char i;
	for(i=0;i<10;i++)
	{
		hy(number+27*8+i*8,3);
		if(dong == 1){dong = 0;  return;}
	}
}
//动画22
void flash_22()
{
    zimu(number,19,12,1);
	if(dong == 1){dong = 0;  return;} if(abcd == 1){ abcd =0; return;}
}
//动画23
void flash_23()//条状升降
{
	char i,j,k,v=2;
	uchar a[64]={0};
	for(i=7;i>=0;i--)
	{
		a[i]=0x01<<i;
		if(key3==1){break;}
		else{zhen(a,v+5);}
		delay(50);
	}
	for(i=0;i<7;i++)
	{
		for(j=0;j<8;j++)
			a[j]=flash0__tab[i*8+j];
		if(key3==1){break;}
		else{zhen(a,v+5);}
		delay(50);
		if(dong == 1){dong = 0;  return;}
	}
	for(i=0;i<7;i++)
	{
		move(a,2,1,1);
		if(key3==1){break;}
		else{zhen(a,v+5);}
		delay(50);
	}
	if(dong == 1){dong = 0;  return;}
	for(i=0;i<64;i++)
	{
		if(i>55)
		a[i]=0xff;
		else
		a[i]=0;
	} 
	if(key3==1){return;}
	else{zhen(a,20);}
	delay(50);
	if(dong == 1){dong = 0;  return;}
	for(i=7;i>=0;i--)//1
		for(j=6;j>=0;j--)
		{
			a[i+j*8]=0xff;
			a[i+(j+1)*8]=0;
			if(key3==1){break;}
			else{zhen(a,v);}
			delay(50);
			if(dong == 1){dong = 0;  return;}
		}
	if(key3==1){return;}
	else{zhen(a,27);}
	for(i=7;i>=0;i--)//2
		for(j=1;j<8;j++)
		{
			a[i+j*8]=0xff;
			a[i+(j-1)*8]=0;
			if(key3==1){break;}
			else{zhen(a,v);}
			delay(50);
			if(dong == 1){dong = 0;  return;}
		}
	if(key3==1){return;}
	else{zhen(a,27);}
	delay(50);
	for(i=7;i>=0;i--)//3
		for(k=6;k>=0;k--)
		{
			for(j=0;j<8;j++)
			{
				if(k==0)
				a[j+k*8]|=(0x80>>(7-i));
				else
				a[j+k*8]=(0x80>>(7-i));
				a[j+(k+1)*8]^=(0x80>>(7-i));
			}
			if(key3==1){break;}
			else{zhen(a,v);}
			delay(50);
			if(dong == 1){dong = 0;  return;}
		}
	if(key3==1){return;}
	else{zhen(a,27);}
	delay(50);
	for(i=7;i>=0;i--)//4
		for(k=1;k<8;k++)
		{
			for(j=0;j<8;j++)
			{
				if(k==7)
				a[j+k*8]|=(0x80>>(7-i));
				else
				a[j+k*8]=(0x80>>(7-i));
				a[j+(k-1)*8]^=(0x80>>(7-i));
			}
			if(key3==1){break;}
			else{zhen(a,v);}
			delay(50);
			if(dong == 1){dong = 0;  return;}
		}
	if(key3==1){return;}
	else{zhen(a,27);}
	delay(50);
	if(dong == 1){dong = 0;  return;}
}
//动画24
void flash_24()  	
{
	uchar i,v=10,a[64]={0};
	for(i=0;i<7;i++)
		a[7*8+i]=0xff;
	for(i=0;i<8;i++)
	{
		move(a,2,0,1);
		if(key3==1){break;}
		else{zhen(a,v);}
		delay(50);
		if(dong == 1){dong = 0;  return;}
	}
}
//动画25
void flash_25()
{
	uchar a[64]={0};
	char i,j,num=20,v=10;
	while(num--)
	{
		if(dong == 1)
		{
			dong = 0;
			return;	
		}
		for(i=1;i<8;i++)
			a[i]=0xff;
		if(key3==1){break;}
		else{zhen(a,v);	}
		delay(50);
		for(i=1;i<8;i++)
		{
			move(a,2,1,1);
			for(j=0;j<8;j++)
				a[j]=0xff;
		if(key3==1){break;}
		else{zhen(a,v);}
			delay(50);
		}
		for(i=0;i<8;i++)
		{
			if(num==0&&i==7)
				continue;
			move(a,2,1,1);
		if(key3==1){break;}
		else{zhen(a,v);}
			delay(50);
		if(dong == 1){dong = 0;  return;}
		}			
	}
	for(i=0;i<7;i++)
	{
		if(dong == 1)
		{
			dong = 0;
			return;	
		}
		move(a,2,0,1);
		if(key3==1){break;}
		else{zhen(a,v+5);}
		delay(50);
	}
	if(dong == 1){dong = 0;  return;}
}
//动画26
void flash_26()
{
	leitu(yc_table,5,2);
	if(dong == 1){dong = 0;  return;}
}
//动画27 
void flash_27()
{
	uchar a[64];
	char i,j,k,v=3;
	for(k=0;k<8;k++)
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
			{
				if(dong == 1){dong = 0;  return;}
				a[tab_mian[i]*8+tab_xian[j]]|=(0x01<<tab_dian[(i+j)*8+k]);
				if(key3==1){break;}
				else{zhen(a,v);}
				delay(50);
			}
	if(key3==1){return;}
	else{zhen(a,90);}
	delay(50);
	if(dong == 1){dong = 0;  return;}
	for(k=0;k<8;k++)
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
			{
				if(dong == 1){dong = 0;  return;}
				a[tab_mian[i]*8+tab_xian[j]]^=(0x01<<tab_dian[(i+j)*8+k]);
				if(key3==1){break;}
				else{zhen(a,v);}
				delay(50);				
			}
	if(dong == 1){dong = 0;  return;}
}
//动画28
void flash_28()
{		
	water1(1,2,10);water1(2,4,10);
	water1(4,3,10);water1(7,1,10);
	water1(5,6,10);			
	water2(0,2,7,1,9);
	water2(2,4,7,7,9);
	water2(4,7,7,1,9);
	water2(3,6,7,7,9);
	water2(4,1,6,6,9);
	water2(7,3,1,2,9);
	water3(0,4,7,4,5,1,9);
	water3(7,7,0,0,0,7,9);
	water3(0,6,6,6,5,1,9);
	water3(6,7,0,0,2,2,9);
	water3(3,3,6,6,2,2,9);
	if(dong == 1){dong = 0;  return;}
}

//动画30
void flash_30()
{
	char i;
	for(i=0;i<4;i++)
	{
		print(tab_print+i*8,0);	
		if(dong == 1){dong = 0;  return;}
	}	
}
//动画31
void flash_31()
{
	link_jb0(1);
	jb0(4,3);
	yinchu(yc_table,5,9); 
	link_jb0(1);
	jb0(4,3);
	if(dong == 1){dong = 0;  return;}
}
//动画32
void flash_32()
{
	link(9);	 //从左边开始进入连接选择条的开端
	xuanzhuantiao(1,8,4);//实心旋转显示选择一个面
	xuanzhuantiao(0,8,4);//空心旋转显示选择一个面
	if(dong == 1){dong = 0;  return;}
}
//动画33
void flash_33()
{
	xuanzhuantiao2(3,3);
	if(dong == 1){dong = 0;  return;}
}
//动画34
void flash_34()
{
	qumianxuanzhuan(1,10,4);
	qumianxuanzhuan(0,10,4);
	if(dong == 1){dong = 0;  return;}
}
//动画35
void flash_35()
{
	qumianxuanzhuan2(13,4);
	if(dong == 1){dong = 0;  return;}
}
//动画36
void flash_36()
{
	donghua(bianxing_table,11,1,24);
	xzcube();
	donghua(y_table,6,5,5);
	donghua(x_table,6,5,5);
	donghua(z_table,6,5,5);
	if(dong == 1){dong = 0;  return;}
}
//动画37
void flash_37()	 
{
	link00();  
	if(dong == 1){dong = 0;  return;}
}
//动画38
void flash_38()	 
{
	shensuo(5);
	if(dong == 1){dong = 0;  return;}
}
//动画39
void flash_39()	  
{
	char i,j;
		for(i=0;i<3;i++)	 
			for(j=0;j<3;j++)
				cube(0,j,6);
		for(i=0;i<3;i++)     
			for(j=0;j<3;j++)
				cube(1,j,6);
	if(dong == 1){dong = 0;  return;}
}
//动画40
void flash_40()	 
{
	donghua(hart_table,2,10,32); 
	if(dong == 1){dong = 0;  return;}
}
//动画41
void flash_41()	 
{
	char i;
	for(i=2;i>0;i--)
		shandian(i);
	if(dong == 1){dong = 0;  return;}	
}
//动画42
void flash_42()	 
{
	szfc0(10);
	if(dong == 1){dong = 0;  return;}
}

void type1(uchar cha,uchar y)	//43
{
	uchar xx;
	for (xx=0;xx<8;xx++)
	{
		display[xx][y]=gaizi_yi[cha][xx];
	}
}
void tranoutchar_cu1(uchar c,uint speed)	//44
{
	 uchar i,j,k,a,i2=0;
	 for (i=0;i<8;i++)
	 {
		  if (i<7)
		  box_apeak_xy (i+1,0,0,i+1,7,7,1,1);
		  box_apeak_xy (i2,0,0,i2,7,7,1,0);
		  a=0;
		  i2=i+1;
		  for (j=0;j<=i;j++)
		  {
		   a=a|(1<<j);
		  }
		  for (k=0;k<8;k++)
		  {
		  	 display[k][3]|=gaizi_er[c][k]&a;
		  	 display[k][4]|=gaizi_er[c][k]&a;
		  }
		  delay(speed);
		  if(gai == 1){return;} if(abcd == 1){return;}if(gaizhiflag==1){return;}
	 }
}

//改字动画1
void flash_43()
{     
	uchar i;
	for(i=0;i<gaizi_geshu1/8;i++)
	{
		clear(0);
		type1(i,7);
		trailler(9000);
		delay(60000);
		if(gai == 1){gai = 0;return;}if(abcd == 1){ abcd =0; return;}if(gaizhiflag==1){gaizhiflag=0;return;}	
	}   
}
//改字动画2
void flash_44()
{
	uchar i;
	for (i=0;i<gaizi_geshu2/8;i++)
	{
		tranoutchar_cu1(i,10000);
		delay(60000);
		delay(60000);
		if(dong == 1){dong = 0;return;	}if(gai==1){gai=0;return;}if(abcd == 1){ abcd =0; return;}if(gaizhiflag==1){gaizhiflag=0;return;}
	}
}


#endif