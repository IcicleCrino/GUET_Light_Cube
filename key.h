#ifndef _KEY_H_
#define _KEY_H_



void key_baihei_scan()
{
		if(!K1)  //�����⵽�͵�ƽ��˵����������
    {
	    delay10us(); //��ʱȥ����һ��10-20ms
      if(!K1)     //�ٴ�ȷ�ϰ����Ƿ��£�û�а������˳�
	    {
	      while(!K1)//���ȷ�ϰ��°����ȴ������ͷţ�û�����˳�
				{
					PWM_POW=1;       
					delay10us();delay10us();delay10us();delay10us();delay10us();delay10us();
					PWM_POW=0;   	
				}
				key1 = 1; //key1���°���
				moshi = moshi+1; //ÿ�ж�һ�� ģʽ�ı� ���ı�ģʽ��Ӧ�ı���
				if(moshi == 1) //����ģʽ
				{	
					dong = 0;
					donghua1 = 0;
					start2 = 1;		
					key2=2;		 		     	
				}
				if(moshi == 2)	//Ƶ��ģʽ
				{	  
					sinter(); 
					ping=0;
					dong = 2;
					pingpu = 0;
					start1=1;
					key2=1;
				}
				if(moshi == 3)  //������λ��ģʽ
				{
			    key2=3;	
					dong = 2;			     	
				}	  
				if(moshi == 4) //��ʾ���ֶ���
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

////����ģʽ�����ж�
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
////����ģʽ�����ж�
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
////����ģʽ�����ж�
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