#ifndef _KEY_H_
#define _KEY_H_



void key_baihei_scan()
{
		if(!K1)  //如果检测到低电平，说明按键按下
    {
	    delay10us(); //延时去抖，一般10-20ms
      if(!K1)     //再次确认按键是否按下，没有按下则退出
	    {
	      while(!K1)//如果确认按下按键等待按键释放，没有则退出
				{
					PWM_POW=1;       
					delay10us();delay10us();delay10us();delay10us();delay10us();delay10us();
					PWM_POW=0;   	
				}
				key1 = 1; //key1按下按键
				moshi = moshi+1; //每判断一次 模式改变 并改变模式对应的变量
				if(moshi == 1) //动画模式
				{	
					dong = 0;
					donghua1 = 0;
					start2 = 1;		
					key2=2;		 		     	
				}
				if(moshi == 2)	//频谱模式
				{	  
					sinter(); 
					ping=0;
					dong = 2;
					pingpu = 0;
					start1=1;
					key2=1;
				}
				if(moshi == 3)  //电脑上位机模式
				{
			    key2=3;	
					dong = 2;			     	
				}	  
				if(moshi == 4) //显示文字动画
				{	
					gai = 0;
					gaizi = 0;
					dong = 2;
					start3 = 1;						
					key2=4;	
					moshi = 0;
				}	
	    }
		}
}

////音乐模式按键判断
void yinyue_key2()
{
	if(key2==3||key2==2||key2==4||key2==5)
	{
		if(key2==3)
		{
			msd=3;
			return;
		}
		else
		{
			if(key2==2)
			{
				msd=2;
				return;
			}
			if(key2==4)
			{
				msd=4;
				return;	
			}
			if(key2==5)
			{
				msd=5;
				return;
			}
		}
	}
	else
	{
		return;	
	}
}
////动画模式按键判断
void donghua_key2()
{
	if(key2==3||key2==1||key2==4||key2==5)
	{
		if(key2==3)
		{
			msd=3;return;
		}
		else
		{
			if(key2==1)
			{
				msd=1;return;
			}
			if(key2==4)
			{
				msd=4;
				return;	
			}
			if(key2==5)
			{
				msd=5;
				return;	
			}
		}
	}
	else
	{
		return;	
	}
}
////文字模式按键判断
void gaizi_key2()
{
	if(key2==3||key2==1||key2==2||key2==5)
	{
		if(key2==3)
		{
			msd=3;return;
		}
		else
		{
			if(key2==1)
			{
				msd=1;return;
			}
			if(key2==2)
			{
				msd=2;
				return;	
			}
			if(key2==5)
			{
				msd=5;
				return;	
			}
		}
	}
	else
	{
		return;	
	}
}	

#endif