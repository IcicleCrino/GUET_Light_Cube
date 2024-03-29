#ifndef _MOSHI_H_
#define _MOSHI_H_



/*          音乐频谱模式            */
void yinyue_moshi()
{
	if(msd==1)	 //频谱模式
	{	
		key3=3;	
		TR0=0;	
		ET0=0;
		xsdsq=1;
		hy(number+(36+1)*8,10);	
		W_side(number+(36+1)*8,1,200);
		xsdsq=0;
		sinter();
		TR0=1;			  	//开启定时器显示扫描
		ET0=1;
	   while(1)
	   {
	   		if(start1 == 1)
			{
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{
					if(start1 == 1)
					{
						clear(0);
				    	Vol_watch_0(1);	
					}
				} 
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{				 	
					if(start1 == 1)
					{ 
						 clear(0);
						 Vol_watch_0(2);
					}				  	
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{
					if(start1 == 1)
					{ 
						 clear(0);
				 	 	Vol_watch_0(3);
					}
				     
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{
					if(start1 == 1)
					{ 
						 clear(0); 
						 Vol_watch_0(4);
					}					 
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{
					if(start1 == 1)
					{ 
						 clear(0);
				  		 Vol_watch_0(5);	 
					}
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{ 
					if(start1 == 1)
					{ 
						 clear(0);
				 	     Vol_watch_0(6);
					}				 	 
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{  
					if(start1 == 1)
					{ 
						 clear(0);
				 	     Vol_watch_0(7);
					}					 
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{
					if(start1 == 1)
					{ 
						clear(0);	
				     	Vol_watch_1(1);	 
					}
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{ 
					if(start1 == 1)
					{
					 	  clear(0);
					      Vol_watch_1(2);
					}				    
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{ 
					if(start1 == 1)
					{ 
						clear(0); 
						Vol_watch_1(3);
					}
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{
					if(start1 == 1)
					{ 
				 		clear(0);
				 		Vol_watch_1(4);
					}
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{ 
					if(start1 == 1)
					{ 
						clear(0);
						Vol_watch_1(5);
					}
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{ 
					if(start1 == 1)
					{ 
						clear(0);
						Vol_watch_2();
					}
				}
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else
				{
					if(start1 == 1)
					{ 
				 		clear(0);
				 		Vol_watch_3();
					}
				}	
			}
			else if(start1 == 0) //频谱动画选择模式			
			{
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else		 	    
				{
					 if(pingpu == 1){clear(0);Vol_watch_0(1);}      //左下角闪
					 else if(pingpu == 2){clear(0);Vol_watch_0(2);} //右上角闪
					 else if(pingpu == 3){clear(0);Vol_watch_0(3);} //前向后闪
					 else if(pingpu == 4){clear(0);Vol_watch_0(4);} //中间向外闪
					 else if(pingpu == 5){clear(0);Vol_watch_0(5);} //后面左边向外闪
					 else if(pingpu == 6){clear(0);Vol_watch_1(7);} //
					 else if(pingpu == 7){clear(0);Vol_watch_0(7);} //左向右闪
					 else if(pingpu == 8){clear(0);Vol_watch_1(1);} //左下面向右闪
					 else if(pingpu == 9){clear(0);Vol_watch_1(2);}  //中间16个向上闪
					 else if(pingpu == 10){clear(0);Vol_watch_1(3);} //中间36个向上闪
					 else if(pingpu == 11){clear(0);Vol_watch_1(4);} //中间64个向上闪
					 else if(pingpu == 12){clear(0);Vol_watch_1(5);} //外面围着中间四个灯向上闪
					 else if(pingpu == 13){clear(0);Vol_watch_2();} //中间向外闪，全屏那样					 
					 else if(pingpu == 14){clear(0);Vol_watch_3();} //下面向上滚
					 else if(pingpu == 15){clear(0);Vol_watch_1(6);} //中间64个向上闪
				}	
			}			
	   }
	}	
}								

/*          动画模式            */
void donghua_moshi()
{
	if(msd==2)	 //动画模式
	{	
		key3=3;	
		TR0=0;	//开启t0计数器/定时器
		ET0=0;	//打开T0定时器中断
		xsdsq=1;
		flash_20();
		xsdsq=0;
		sinter();
		TR0=1;			  	//开启定时器显示扫描
		ET0=1;
	  while(1)
	  {
	   	if(start2 == 1)//动画模式
			{
				TR0=0;	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_21();	//数字倒计时1
					}
				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_21();	 //从后面往前面显示数组的数字9-0
//					}
//				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	TR0=1;clear(0);piaozhi(table_3p_zf,2000,6);
//					}
//				} 
//				TR0=0;
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_22();	 //围绕着最外面的LED循环滚动显示数组中内容
//					}
//				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_23();	 //分层升降左右上下前后以此打开升降测试
//					}
//				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_24();  //从最上面的一个面往下面的一层移动完
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	V_scan(20); //下向上扫描检测 
//					}
//				}													
		 		donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_25();	 //光立方全亮并且闪烁5次
					}
				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_26();  //从下面往上面依次显示出数组中的内容IXU
//					}
//				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_27();	 //狼七八咋的显示出LED的每一个灯展示灯火效果
//					}
//				}
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_28();	 //显示从上面往下面滴水的效果
					}
				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	TR0=0;H_scan(10);V_scan(10);W_scan(10); 
//					}
//				}	
//				donghua_key2();
//				TR0=0;
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_30();	 //空心显示将数组内容打印出来可以打印4个数组内容
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_31();	 //将左右的四个面围绕成圈圈转起来4次之后从左边往右边显示数组中一幅图像64个的数据
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_32();	 //从左边显示一个面然后旋转出一个面的空心效果实心效果
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_33();	 //旋转单个面依次交换到买一个面
//					}
//				}	
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_34();	 //以中点位轴进行选择左右旋转切换实现波纹的效果
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_35();	 //旋转左右为中心加快速度实现每个面的抖动效果
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_36();	 //将数组中的内容显示出现进行旋转是一个正方形的
//					}
//				}	
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_37();	 //将方形变形缩小然后变成一个全亮的效果
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	W_scan(20); //前向后扫描检测
//					}
//				}				
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_38();	 //前后左右上下伸缩全亮
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_39();	 //实心和空心缩放和放大正方形全亮显示
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_40();	 //动画显示一个数组里面的心形数据 会动的心形
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_41();	 //显示一个电梯的图形
//					}
//				}	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_42();	 //倒计时三维
					} 
				}	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_15();  //显示下雨的效果
					}
				}
				TR0=1;	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_1(); //包含第一个面显示4321倒计时的文字
					}
				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_17();	//显示出一个VI的版本标志然后从最里面往外面滚动出来
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//						TR0=0;
//				    	flash_16();	 //从边边的左右中滚动显示默认的英文字母
//					}
//				}
//				TR0=1;
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_14();//一个一个的字变出来显示上升沿电子光立方可以修改显示数据
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_18();//显示出上升沿电子8X8X8光立方下雨效果飘出字移动出去
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_2();//图形圈圈显示出来
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_3();//从前一排显示到后面一排两次
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_4();//从前一排斜杆到最后一排两次
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_5();//框框伸缩从中间到前面到后面
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_6();//滚四边的圈圈然后下雨效果飘出字移动出去
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_7();//滚四边包括前后左右滚然后出来半边三角形
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_8();//从左移动一排到右边中间显示文字图形
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_9();//从左到右边滚出斜杆然后螺旋转轴旋转框框显示方框伸缩孔空心和实心
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_10();//从最左小脚伸缩出框框然后变轮子前后左右上下滚动然后收缩还原
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_11();//象红旗一样被风飘动象蛇一样飘动走动
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_12();//滚动上升沿电子的字模数据文字移动显示出来
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_13();//渐变出来文字VI1234IXU的图案
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_19();//平行滑动显示出3D CULE FFT的字�

//					}
//				}
//				TR0=0;												 				 											 	
//			}
			}
			else if(start2 == 0) //频谱动画选择模式			
			{
				donghua_key2();
				if(msd != 2)
				{
					break;	
				}
				else		 	    
				{																	  
					 if(donghua1 == 1){TR0=0; flash_20();}	 //第一个面屏幕上下拉开	  
					 else if(donghua1 == 2) {TR0=0;flash_21();}	 //从后面往前面显示数组的数字9-0
					 else if(donghua1 == 3) {TR0=1;clear(0);piaozhi(table_3p_zf,2500,6);} //上下左右前后扫描
					 else if(donghua1 == 4) {TR0=0;flash_22();}	 //围绕着最外面的LED循环滚动显示数组中内容	 
					 else if(donghua1 == 5) {TR0=0;flash_23();}	 //分层升降左右上下前后以此打开升降测试	
					 else if(donghua1 == 6) {TR0=0;flash_24();}     //从最上面的一个面往下面的一层移动完
					 else if(donghua1 == 7) {TR0=0;V_scan(20);}   //下向上扫描检测 
					 else if(donghua1 == 8) {TR0=0;flash_25();}	 //光立方全亮并且闪烁5次
					 else if(donghua1 == 9) {TR0=0;flash_26();}     //从下面往上面依次显示出数组中的内容IXU   
					 else if(donghua1 == 10){TR0=0;flash_27();}	 //狼七八咋的显示出LED的每一个灯展示灯火效果
					 else if(donghua1 == 11){TR0=0;flash_28();}	 //显示从上面往下面滴水的效果
					 else if(donghua1 == 12){TR0=0;H_scan(10);V_scan(10);W_scan(10); }	 //
					 else if(donghua1 == 13){TR0=0;flash_30();}	 //空心显示将数组内容打印出来可以打印4个数组内容  
					 else if(donghua1 == 14){TR0=0;flash_31();}	 //将左右的四个面围绕成圈圈转起来4次之后从左边往右边显示数组中一幅图像64个的数据
					 else if(donghua1 == 15){TR0=0;flash_32();}	 //从左边显示一个面然后旋转出一个面的空心效果实心效果  
					 else if(donghua1 == 16){TR0=0;flash_33();}	 //旋转单个面依次交换到买一个面	 
					 else if(donghua1 == 17){TR0=0;flash_34();}	 //以中点位轴进行选择左右旋转切换实现波纹的效果	 
					 else if(donghua1 == 18){TR0=0;flash_35();}	 //旋转左右为中心加快速度实现每个面的抖动效果	
					 else if(donghua1 == 19){TR0=0;flash_36();}     //将数组中的内容显示出现进行旋转是一个正方形的	  
					 else if(donghua1 == 20){TR0=0;flash_37();}	 //将方形变形缩小然后变成一个全亮的效果	
					 else if(donghua1 == 21){TR0=0;W_scan(20);}	 //前向后扫描检测
		 		 	 else if(donghua1 == 22){TR0=0;flash_38();}	 //前后左右上下伸缩全亮    
					 else if(donghua1 == 23){TR0=0;flash_39();}	 //实心和空心缩放和放大正方形全亮显示	 
					 else if(donghua1 == 24){TR0=0;flash_40();}	 //动画显示一个数组里面的心形数据 会动的心形
					 else if(donghua1 == 25){TR0=0;flash_41();}     //显示一个电梯的图形
					 else if(donghua1 == 26){TR0=0;flash_42();}	 //显示数字往上移动出来	
					 else if(donghua1 == 27){TR0=0;flash_15();}     //显示下雨的效果			
					 
					 else if(donghua1 == 28) {TR0=1;flash_1();} //包含第一个面显示4321倒计时的文字
					 else if(donghua1 == 29) {TR0=1;flash_17();}	//显示出一个VI的版本标志然后从最里面往外面滚动出来
					 else if(donghua1 == 30) {TR0=0;flash_16();}//从边边的左右中滚动显示默认的英文字母ideasoft
					 else if(donghua1 == 31) {TR0=1;flash_14();}//一个一个的字变出来显示上升沿电子光立方可以修改显示数据
					 else if(donghua1 == 32) {TR0=1;clear(0);flash_18();}//显示出上升沿电子8X8X8光立方下雨效果飘出字移动出去
					 else if(donghua1 == 33) {TR0=1;clear(0);flash_2();}//图形圈圈显示出来
					 else if(donghua1 == 34) {TR0=1;clear(0);flash_3();}//从前一排显示到后面一排两次
					 else if(donghua1 == 35) {TR0=1;clear(0);flash_4();}//从前一排斜杆到最后一排两次
					 else if(donghua1 == 36) {TR0=1;clear(0);flash_5();}//框框伸缩从中间到前面到后面
					 else if(donghua1 == 37) {TR0=1;clear(0);flash_6();}//滚四边的圈圈然后下雨效果飘出字移动出去
					 else if(donghua1 == 38) {TR0=1;clear(0);flash_7();}//滚四边包括前后左右滚然后出来半边三角形
					 else if(donghua1 == 39) {TR0=1;clear(0);flash_8();}//从左移动一排到右边中间显示文字图形
					 else if(donghua1 == 40) {TR0=1;clear(0);flash_9();}//从左到右边滚出斜杆然后螺旋转轴旋转框框显示方框伸缩孔空心和实心
					 else if(donghua1 == 41) {TR0=1;flash_10();}//从最左小脚伸缩出框框然后变轮子前后左右上下滚动然后收缩还原
					 else if(donghua1 == 42) {TR0=1;flash_11();}//象红旗一样被风飘动象蛇一样飘动走动
					 else if(donghua1 == 43) {TR0=1;flash_12();}//滚动上升沿电子的字模数据文字移动显示出来
					 else if(donghua1 == 44) {TR0=1;flash_13();}//渐变出来文字VI1234IXU的图案
					 else if(donghua1 == 45) {TR0=1;clear(0);flash_19();}//平行滑动显示出3D CULE FFT的字�
				}	
			}			
	   }
	}	
}

/*          电脑上位机模式            */
void shangweiji_moshi()
{
	uchar i;
	if(msd==3)	 //上位机模式 
	{
		for(i=0;i<64;i++)
		{
			displayck[i]=0x00;
		}
		key3=3;				
		TR0=0;
		TR1=0;			 
		xsdsq=1;
		hy(number+(36+3)*8,10);
		W_side(number+(36+3)*8,1,200);	
		xsdsq=0;
		init_uart();
	    while(1)
	    {
			fvb();
			if(key2==1||key2==2||key2==4||key2==5)
			{
				if(key2==1)
				{
					msd=1;
					break;
				}
		     	else
				{
					if(key2==2)
					{
						msd=2;
						break;
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
				}
			}
	    }
	}	
}
/*          文字模式            */
void xiugaidonghua_moshi()
{
	//
	if(msd==4)	  //动画模式
	{	
		key3=3;	
		TR0=0;	
		ET0=0;
		xsdsq=1;
		hy(ZM+(13*8),10);
		W_side(ZM+(13*8),1,200);
		xsdsq=0;
		sinter();
		TR0=1;			  	//开启定时器显示扫描
		ET0=1;	 

	    while(1)
	    {		
			if(start3 == 1)
			{	
				gaizi_key2();
				if(msd != 4){break;}
				else
				{
					if(start3 == 1)
					{
						TR0=1;
						if(gaizi1_flag)
						{
						 	flash_13();//渐变出来文字VI1234IXU的图案  
						}
						else
						{
							flash_43();//显示文字的内容
						}
					}
				}
				gaizi_key2();
				if(msd != 4){break;}
				else
				{
					if(start3 == 1)
					{
						TR0=1;
						clear(0);
						if(gaizi2_flag)
						{
						 	flash_19();//平行滑动显示出3D CULE FFT的字�

						}
						else
						{
							flash_44();//显示文字的内容
						}				    	
					}
				}
				gaizi_key2();
				if(msd != 4){break;}
				else
				{
					if(start3 == 1)
					{
						TR0=1;
						clear(0);
						if(gaizi3_flag)
						{
						 	piaozhi(table_3p_zf,3000,6);
						}
						else
						{
							piaozhi(gaizi_san,2500,gaizi_geshu3/8);//显示文字的内容
						}				    	
					}
				}
				gaizi_key2();
				if(msd != 4){break;}
				else
				{
					if(start3 == 1)
					{
						TR0=0;
						if(gaizi4_flag)
						{
							flash_22();	 //围绕着最外面的LED循环滚动显示数组中内容
						}
						else
						{
								
							zimu(abc_char,jcount+5,12,1);	 //旋转字母 zimu(uchar *x,char n,char v,int num)//滚动字幕,num表示循环次数,v表示滚动速度,n字符个数	
						}
					}
				}
			} 		
			else if(start3 == 0) //频谱动画选择模式			
			{
				gaizi_key2();
				if(msd != 4)
				{
					break;	
				}
				else		 	    
				{								 
					if(gaizi == 1) {TR0=1;if(gaizi1_flag){flash_13();}else {flash_43();}}//渐变出来文字VI1234IXU的图案
					else if(gaizi == 2) {TR0=1;clear(0);if(gaizi2_flag){flash_19();}else {flash_44();}}	 //平行滑动显示出3D CULE FFT的字�
					else if(gaizi == 3) {TR0=1;clear(0);if(gaizi3_flag){piaozhi(table_3p_zf,3000,6);}else {piaozhi(gaizi_san,3000,gaizi_geshu3/8);}}	//显示出上升沿电子8X8X8光立方下雨效果飘出字移动出去
					else if(gaizi == 4)	//围绕着最外面的LED循环滚动显示数组中内容
					{						
						TR0=0; 
						if(gaizi4_flag)
						{
							flash_22();	 
						}
						else
						{
							
							zimu(abc_char,jcount+5,12,1);	 //旋转字母 zimu(uchar *x,char n,char v,int num)//滚动字幕,num表示循环次数,v表示滚动速度,n字符个数	
						}
					}
				}
			}		  
		}
	}	
}

#endif