#ifndef _MOSHI_H_
#define _MOSHI_H_



/*          ����Ƶ��ģʽ            */
void yinyue_moshi()
{
	if(msd==1)	 //Ƶ��ģʽ
	{	
		key3=3;	
		TR0=0;	
		ET0=0;
		xsdsq=1;
		hy(number+(36+1)*8,10);	
		W_side(number+(36+1)*8,1,200);
		xsdsq=0;
		sinter();
		TR0=1;			  	//������ʱ����ʾɨ��
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
			else if(start1 == 0) //Ƶ�׶���ѡ��ģʽ			
			{
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else		 	    
				{
					 if(pingpu == 1){clear(0);Vol_watch_0(1);}      //���½���
					 else if(pingpu == 2){clear(0);Vol_watch_0(2);} //���Ͻ���
					 else if(pingpu == 3){clear(0);Vol_watch_0(3);} //ǰ�����
					 else if(pingpu == 4){clear(0);Vol_watch_0(4);} //�м�������
					 else if(pingpu == 5){clear(0);Vol_watch_0(5);} //�������������
					 else if(pingpu == 6){clear(0);Vol_watch_1(7);} //
					 else if(pingpu == 7){clear(0);Vol_watch_0(7);} //��������
					 else if(pingpu == 8){clear(0);Vol_watch_1(1);} //������������
					 else if(pingpu == 9){clear(0);Vol_watch_1(2);}  //�м�16��������
					 else if(pingpu == 10){clear(0);Vol_watch_1(3);} //�м�36��������
					 else if(pingpu == 11){clear(0);Vol_watch_1(4);} //�м�64��������
					 else if(pingpu == 12){clear(0);Vol_watch_1(5);} //����Χ���м��ĸ���������
					 else if(pingpu == 13){clear(0);Vol_watch_2();} //�м���������ȫ������					 
					 else if(pingpu == 14){clear(0);Vol_watch_3();} //�������Ϲ�
					 else if(pingpu == 15){clear(0);Vol_watch_1(6);} //�м�64��������
				}	
			}			
	   }
	}	
}								

/*          ����ģʽ            */
void donghua_moshi()
{
	if(msd==2)	 //����ģʽ
	{	
		key3=3;	
		TR0=0;	//����t0������/��ʱ��
		ET0=0;	//��T0��ʱ���ж�
		xsdsq=1;
		flash_20();
		xsdsq=0;
		sinter();
		TR0=1;			  	//������ʱ����ʾɨ��
		ET0=1;
	  while(1)
	  {
	   	if(start2 == 1)//����ģʽ
			{
				TR0=0;	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_21();	//���ֵ���ʱ1
					}
				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_21();	 //�Ӻ�����ǰ����ʾ���������9-0
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
//				    	flash_22();	 //Χ�����������LEDѭ��������ʾ����������
//					}
//				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_23();	 //�ֲ�������������ǰ���Դ˴���������
//					}
//				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_24();  //���������һ�����������һ���ƶ���
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	V_scan(20); //������ɨ���� 
//					}
//				}													
		 		donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_25();	 //������ȫ��������˸5��
					}
				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_26();  //������������������ʾ�������е�����IXU
//					}
//				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_27();	 //���߰�զ����ʾ��LED��ÿһ����չʾ�ƻ�Ч��
//					}
//				}
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_28();	 //��ʾ�������������ˮ��Ч��
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
//				    	flash_30();	 //������ʾ���������ݴ�ӡ�������Դ�ӡ4����������
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_31();	 //�����ҵ��ĸ���Χ�Ƴ�ȦȦת����4��֮���������ұ���ʾ������һ��ͼ��64��������
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_32();	 //�������ʾһ����Ȼ����ת��һ����Ŀ���Ч��ʵ��Ч��
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_33();	 //��ת���������ν�������һ����
//					}
//				}	
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_34();	 //���е�λ�����ѡ��������ת�л�ʵ�ֲ��Ƶ�Ч��
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_35();	 //��ת����Ϊ���ļӿ��ٶ�ʵ��ÿ����Ķ���Ч��
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_36();	 //�������е�������ʾ���ֽ�����ת��һ�������ε�
//					}
//				}	
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_37();	 //�����α�����СȻ����һ��ȫ����Ч��
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	W_scan(20); //ǰ���ɨ����
//					}
//				}				
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_38();	 //ǰ��������������ȫ��
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_39();	 //ʵ�ĺͿ������źͷŴ�������ȫ����ʾ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_40();	 //������ʾһ������������������� �ᶯ������
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_41();	 //��ʾһ�����ݵ�ͼ��
//					}
//				}	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_42();	 //����ʱ��ά
					} 
				}	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_15();  //��ʾ�����Ч��
					}
				}
				TR0=1;	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_1(); //������һ������ʾ4321����ʱ������
					}
				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_17();	//��ʾ��һ��VI�İ汾��־Ȼ����������������������
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//						TR0=0;
//				    	flash_16();	 //�ӱ߱ߵ������й�����ʾĬ�ϵ�Ӣ����ĸ
//					}
//				}
//				TR0=1;
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_14();//һ��һ�����ֱ������ʾ�����ص��ӹ����������޸���ʾ����
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_18();//��ʾ�������ص���8X8X8����������Ч��Ʈ�����ƶ���ȥ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_2();//ͼ��ȦȦ��ʾ����
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_3();//��ǰһ����ʾ������һ������
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_4();//��ǰһ��б�˵����һ������
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_5();//����������м䵽ǰ�浽����
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_6();//���ıߵ�ȦȦȻ������Ч��Ʈ�����ƶ���ȥ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_7();//���ı߰���ǰ�����ҹ�Ȼ��������������
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_8();//�����ƶ�һ�ŵ��ұ��м���ʾ����ͼ��
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_9();//�����ұ߹���б��Ȼ������ת����ת�����ʾ���������׿��ĺ�ʵ��
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_10();//������С�����������Ȼ�������ǰ���������¹���Ȼ��������ԭ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_11();//�����һ������Ʈ������һ��Ʈ���߶�
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_12();//���������ص��ӵ���ģ���������ƶ���ʾ����
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_13();//�����������VI1234IXU��ͼ��
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_19();//ƽ�л�����ʾ��3D CULE FFT���ָ

//					}
//				}
//				TR0=0;												 				 											 	
//			}
			}
			else if(start2 == 0) //Ƶ�׶���ѡ��ģʽ			
			{
				donghua_key2();
				if(msd != 2)
				{
					break;	
				}
				else		 	    
				{																	  
					 if(donghua1 == 1){TR0=0; flash_20();}	 //��һ������Ļ��������	  
					 else if(donghua1 == 2) {TR0=0;flash_21();}	 //�Ӻ�����ǰ����ʾ���������9-0
					 else if(donghua1 == 3) {TR0=1;clear(0);piaozhi(table_3p_zf,2500,6);} //��������ǰ��ɨ��
					 else if(donghua1 == 4) {TR0=0;flash_22();}	 //Χ�����������LEDѭ��������ʾ����������	 
					 else if(donghua1 == 5) {TR0=0;flash_23();}	 //�ֲ�������������ǰ���Դ˴���������	
					 else if(donghua1 == 6) {TR0=0;flash_24();}     //���������һ�����������һ���ƶ���
					 else if(donghua1 == 7) {TR0=0;V_scan(20);}   //������ɨ���� 
					 else if(donghua1 == 8) {TR0=0;flash_25();}	 //������ȫ��������˸5��
					 else if(donghua1 == 9) {TR0=0;flash_26();}     //������������������ʾ�������е�����IXU   
					 else if(donghua1 == 10){TR0=0;flash_27();}	 //���߰�զ����ʾ��LED��ÿһ����չʾ�ƻ�Ч��
					 else if(donghua1 == 11){TR0=0;flash_28();}	 //��ʾ�������������ˮ��Ч��
					 else if(donghua1 == 12){TR0=0;H_scan(10);V_scan(10);W_scan(10); }	 //
					 else if(donghua1 == 13){TR0=0;flash_30();}	 //������ʾ���������ݴ�ӡ�������Դ�ӡ4����������  
					 else if(donghua1 == 14){TR0=0;flash_31();}	 //�����ҵ��ĸ���Χ�Ƴ�ȦȦת����4��֮���������ұ���ʾ������һ��ͼ��64��������
					 else if(donghua1 == 15){TR0=0;flash_32();}	 //�������ʾһ����Ȼ����ת��һ����Ŀ���Ч��ʵ��Ч��  
					 else if(donghua1 == 16){TR0=0;flash_33();}	 //��ת���������ν�������һ����	 
					 else if(donghua1 == 17){TR0=0;flash_34();}	 //���е�λ�����ѡ��������ת�л�ʵ�ֲ��Ƶ�Ч��	 
					 else if(donghua1 == 18){TR0=0;flash_35();}	 //��ת����Ϊ���ļӿ��ٶ�ʵ��ÿ����Ķ���Ч��	
					 else if(donghua1 == 19){TR0=0;flash_36();}     //�������е�������ʾ���ֽ�����ת��һ�������ε�	  
					 else if(donghua1 == 20){TR0=0;flash_37();}	 //�����α�����СȻ����һ��ȫ����Ч��	
					 else if(donghua1 == 21){TR0=0;W_scan(20);}	 //ǰ���ɨ����
		 		 	 else if(donghua1 == 22){TR0=0;flash_38();}	 //ǰ��������������ȫ��    
					 else if(donghua1 == 23){TR0=0;flash_39();}	 //ʵ�ĺͿ������źͷŴ�������ȫ����ʾ	 
					 else if(donghua1 == 24){TR0=0;flash_40();}	 //������ʾһ������������������� �ᶯ������
					 else if(donghua1 == 25){TR0=0;flash_41();}     //��ʾһ�����ݵ�ͼ��
					 else if(donghua1 == 26){TR0=0;flash_42();}	 //��ʾ���������ƶ�����	
					 else if(donghua1 == 27){TR0=0;flash_15();}     //��ʾ�����Ч��			
					 
					 else if(donghua1 == 28) {TR0=1;flash_1();} //������һ������ʾ4321����ʱ������
					 else if(donghua1 == 29) {TR0=1;flash_17();}	//��ʾ��һ��VI�İ汾��־Ȼ����������������������
					 else if(donghua1 == 30) {TR0=0;flash_16();}//�ӱ߱ߵ������й�����ʾĬ�ϵ�Ӣ����ĸideasoft
					 else if(donghua1 == 31) {TR0=1;flash_14();}//һ��һ�����ֱ������ʾ�����ص��ӹ����������޸���ʾ����
					 else if(donghua1 == 32) {TR0=1;clear(0);flash_18();}//��ʾ�������ص���8X8X8����������Ч��Ʈ�����ƶ���ȥ
					 else if(donghua1 == 33) {TR0=1;clear(0);flash_2();}//ͼ��ȦȦ��ʾ����
					 else if(donghua1 == 34) {TR0=1;clear(0);flash_3();}//��ǰһ����ʾ������һ������
					 else if(donghua1 == 35) {TR0=1;clear(0);flash_4();}//��ǰһ��б�˵����һ������
					 else if(donghua1 == 36) {TR0=1;clear(0);flash_5();}//����������м䵽ǰ�浽����
					 else if(donghua1 == 37) {TR0=1;clear(0);flash_6();}//���ıߵ�ȦȦȻ������Ч��Ʈ�����ƶ���ȥ
					 else if(donghua1 == 38) {TR0=1;clear(0);flash_7();}//���ı߰���ǰ�����ҹ�Ȼ��������������
					 else if(donghua1 == 39) {TR0=1;clear(0);flash_8();}//�����ƶ�һ�ŵ��ұ��м���ʾ����ͼ��
					 else if(donghua1 == 40) {TR0=1;clear(0);flash_9();}//�����ұ߹���б��Ȼ������ת����ת�����ʾ���������׿��ĺ�ʵ��
					 else if(donghua1 == 41) {TR0=1;flash_10();}//������С�����������Ȼ�������ǰ���������¹���Ȼ��������ԭ
					 else if(donghua1 == 42) {TR0=1;flash_11();}//�����һ������Ʈ������һ��Ʈ���߶�
					 else if(donghua1 == 43) {TR0=1;flash_12();}//���������ص��ӵ���ģ���������ƶ���ʾ����
					 else if(donghua1 == 44) {TR0=1;flash_13();}//�����������VI1234IXU��ͼ��
					 else if(donghua1 == 45) {TR0=1;clear(0);flash_19();}//ƽ�л�����ʾ��3D CULE FFT���ָ
				}	
			}			
	   }
	}	
}

/*          ������λ��ģʽ            */
void shangweiji_moshi()
{
	uchar i;
	if(msd==3)	 //��λ��ģʽ 
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
/*          ����ģʽ            */
void xiugaidonghua_moshi()
{
	//
	if(msd==4)	  //����ģʽ
	{	
		key3=3;	
		TR0=0;	
		ET0=0;
		xsdsq=1;
		hy(ZM+(13*8),10);
		W_side(ZM+(13*8),1,200);
		xsdsq=0;
		sinter();
		TR0=1;			  	//������ʱ����ʾɨ��
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
						 	flash_13();//�����������VI1234IXU��ͼ��  
						}
						else
						{
							flash_43();//��ʾ���ֵ�����
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
						 	flash_19();//ƽ�л�����ʾ��3D CULE FFT���ָ

						}
						else
						{
							flash_44();//��ʾ���ֵ�����
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
							piaozhi(gaizi_san,2500,gaizi_geshu3/8);//��ʾ���ֵ�����
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
							flash_22();	 //Χ�����������LEDѭ��������ʾ����������
						}
						else
						{
								
							zimu(abc_char,jcount+5,12,1);	 //��ת��ĸ zimu(uchar *x,char n,char v,int num)//������Ļ,num��ʾѭ������,v��ʾ�����ٶ�,n�ַ�����	
						}
					}
				}
			} 		
			else if(start3 == 0) //Ƶ�׶���ѡ��ģʽ			
			{
				gaizi_key2();
				if(msd != 4)
				{
					break;	
				}
				else		 	    
				{								 
					if(gaizi == 1) {TR0=1;if(gaizi1_flag){flash_13();}else {flash_43();}}//�����������VI1234IXU��ͼ��
					else if(gaizi == 2) {TR0=1;clear(0);if(gaizi2_flag){flash_19();}else {flash_44();}}	 //ƽ�л�����ʾ��3D CULE FFT���ָ
					else if(gaizi == 3) {TR0=1;clear(0);if(gaizi3_flag){piaozhi(table_3p_zf,3000,6);}else {piaozhi(gaizi_san,3000,gaizi_geshu3/8);}}	//��ʾ�������ص���8X8X8����������Ч��Ʈ�����ƶ���ȥ
					else if(gaizi == 4)	//Χ�����������LEDѭ��������ʾ����������
					{						
						TR0=0; 
						if(gaizi4_flag)
						{
							flash_22();	 
						}
						else
						{
							
							zimu(abc_char,jcount+5,12,1);	 //��ת��ĸ zimu(uchar *x,char n,char v,int num)//������Ļ,num��ʾѭ������,v��ʾ�����ٶ�,n�ַ�����	
						}
					}
				}
			}		  
		}
	}	
}

#endif