#ifndef _MOSHI_H_
#define _MOSHI_H_



/*          ÒôÀÖÆµÆ×Ä£Ê½            */
void yinyue_moshi()
{
	if(msd==1)	 //ÆµÆ×Ä£Ê½
	{	
		key3=3;	
		TR0=0;	
		ET0=0;
		xsdsq=1;
		hy(number+(36+1)*8,10);	
		W_side(number+(36+1)*8,1,200);
		xsdsq=0;
		sinter();
		TR0=1;			  	//¿ªÆô¶¨Ê±Æ÷ÏÔÊ¾É¨Ãè
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
			else if(start1 == 0) //ÆµÆ×¶¯»­Ñ¡ÔñÄ£Ê½			
			{
				yinyue_key2();
				if(msd != 1)
				{
					break;	
				}
				else		 	    
				{
					 if(pingpu == 1){clear(0);Vol_watch_0(1);}      //×óÏÂ½ÇÉÁ
					 else if(pingpu == 2){clear(0);Vol_watch_0(2);} //ÓÒÉÏ½ÇÉÁ
					 else if(pingpu == 3){clear(0);Vol_watch_0(3);} //Ç°ÏòºóÉÁ
					 else if(pingpu == 4){clear(0);Vol_watch_0(4);} //ÖĞ¼äÏòÍâÉÁ
					 else if(pingpu == 5){clear(0);Vol_watch_0(5);} //ºóÃæ×ó±ßÏòÍâÉÁ
					 else if(pingpu == 6){clear(0);Vol_watch_1(7);} //
					 else if(pingpu == 7){clear(0);Vol_watch_0(7);} //×óÏòÓÒÉÁ
					 else if(pingpu == 8){clear(0);Vol_watch_1(1);} //×óÏÂÃæÏòÓÒÉÁ
					 else if(pingpu == 9){clear(0);Vol_watch_1(2);}  //ÖĞ¼ä16¸öÏòÉÏÉÁ
					 else if(pingpu == 10){clear(0);Vol_watch_1(3);} //ÖĞ¼ä36¸öÏòÉÏÉÁ
					 else if(pingpu == 11){clear(0);Vol_watch_1(4);} //ÖĞ¼ä64¸öÏòÉÏÉÁ
					 else if(pingpu == 12){clear(0);Vol_watch_1(5);} //ÍâÃæÎ§×ÅÖĞ¼äËÄ¸öµÆÏòÉÏÉÁ
					 else if(pingpu == 13){clear(0);Vol_watch_2();} //ÖĞ¼äÏòÍâÉÁ£¬È«ÆÁÄÇÑù					 
					 else if(pingpu == 14){clear(0);Vol_watch_3();} //ÏÂÃæÏòÉÏ¹ö
					 else if(pingpu == 15){clear(0);Vol_watch_1(6);} //ÖĞ¼ä64¸öÏòÉÏÉÁ
				}	
			}			
	   }
	}	
}								

/*          ¶¯»­Ä£Ê½            */
void donghua_moshi()
{
	if(msd==2)	 //¶¯»­Ä£Ê½
	{	
		key3=3;	
		TR0=0;	//¿ªÆôt0¼ÆÊıÆ÷/¶¨Ê±Æ÷
		ET0=0;	//´ò¿ªT0¶¨Ê±Æ÷ÖĞ¶Ï
		xsdsq=1;
		flash_20();
		xsdsq=0;
		sinter();
		TR0=1;			  	//¿ªÆô¶¨Ê±Æ÷ÏÔÊ¾É¨Ãè
		ET0=1;
	  while(1)
	  {
	   	if(start2 == 1)//¶¯»­Ä£Ê½
			{
				TR0=0;	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_21();	//Êı×Öµ¹¼ÆÊ±1
					}
				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_21();	 //´ÓºóÃæÍùÇ°ÃæÏÔÊ¾Êı×éµÄÊı×Ö9-0
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
//				    	flash_22();	 //Î§ÈÆ×Å×îÍâÃæµÄLEDÑ­»·¹ö¶¯ÏÔÊ¾Êı×éÖĞÄÚÈİ
//					}
//				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_23();	 //·Ö²ãÉı½µ×óÓÒÉÏÏÂÇ°ºóÒÔ´Ë´ò¿ªÉı½µ²âÊÔ
//					}
//				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_24();  //´Ó×îÉÏÃæµÄÒ»¸öÃæÍùÏÂÃæµÄÒ»²ãÒÆ¶¯Íê
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	V_scan(20); //ÏÂÏòÉÏÉ¨Ãè¼ì²â 
//					}
//				}													
		 		donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_25();	 //¹âÁ¢·½È«ÁÁ²¢ÇÒÉÁË¸5´Î
					}
				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_26();  //´ÓÏÂÃæÍùÉÏÃæÒÀ´ÎÏÔÊ¾³öÊı×éÖĞµÄÄÚÈİIXU
//					}
//				} 
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_27();	 //ÀÇÆß°ËÕ¦µÄÏÔÊ¾³öLEDµÄÃ¿Ò»¸öµÆÕ¹Ê¾µÆ»ğĞ§¹û
//					}
//				}
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_28();	 //ÏÔÊ¾´ÓÉÏÃæÍùÏÂÃæµÎË®µÄĞ§¹û
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
//				    	flash_30();	 //¿ÕĞÄÏÔÊ¾½«Êı×éÄÚÈİ´òÓ¡³öÀ´¿ÉÒÔ´òÓ¡4¸öÊı×éÄÚÈİ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_31();	 //½«×óÓÒµÄËÄ¸öÃæÎ§ÈÆ³ÉÈ¦È¦×ªÆğÀ´4´ÎÖ®ºó´Ó×ó±ßÍùÓÒ±ßÏÔÊ¾Êı×éÖĞÒ»·ùÍ¼Ïñ64¸öµÄÊı¾İ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_32();	 //´Ó×ó±ßÏÔÊ¾Ò»¸öÃæÈ»ºóĞı×ª³öÒ»¸öÃæµÄ¿ÕĞÄĞ§¹ûÊµĞÄĞ§¹û
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_33();	 //Ğı×ªµ¥¸öÃæÒÀ´Î½»»»µ½ÂòÒ»¸öÃæ
//					}
//				}	
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_34();	 //ÒÔÖĞµãÎ»Öá½øĞĞÑ¡Ôñ×óÓÒĞı×ªÇĞ»»ÊµÏÖ²¨ÎÆµÄĞ§¹û
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_35();	 //Ğı×ª×óÓÒÎªÖĞĞÄ¼Ó¿ìËÙ¶ÈÊµÏÖÃ¿¸öÃæµÄ¶¶¶¯Ğ§¹û
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_36();	 //½«Êı×éÖĞµÄÄÚÈİÏÔÊ¾³öÏÖ½øĞĞĞı×ªÊÇÒ»¸öÕı·½ĞÎµÄ
//					}
//				}	
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_37();	 //½«·½ĞÎ±äĞÎËõĞ¡È»ºó±ä³ÉÒ»¸öÈ«ÁÁµÄĞ§¹û
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	W_scan(20); //Ç°ÏòºóÉ¨Ãè¼ì²â
//					}
//				}				
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_38();	 //Ç°ºó×óÓÒÉÏÏÂÉìËõÈ«ÁÁ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_39();	 //ÊµĞÄºÍ¿ÕĞÄËõ·ÅºÍ·Å´óÕı·½ĞÎÈ«ÁÁÏÔÊ¾
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_40();	 //¶¯»­ÏÔÊ¾Ò»¸öÊı×éÀïÃæµÄĞÄĞÎÊı¾İ »á¶¯µÄĞÄĞÎ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_41();	 //ÏÔÊ¾Ò»¸öµçÌİµÄÍ¼ĞÎ
//					}
//				}	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_42();	 //µ¹¼ÆÊ±ÈıÎ¬
					} 
				}	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_15();  //ÏÔÊ¾ÏÂÓêµÄĞ§¹û
					}
				}
				TR0=1;	
				donghua_key2();
				if(msd != 2){break;}
				else
				{
					if(start2 == 1)
					{
				    	flash_1(); //°üº¬µÚÒ»¸öÃæÏÔÊ¾4321µ¹¼ÆÊ±µÄÎÄ×Ö
					}
				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_17();	//ÏÔÊ¾³öÒ»¸öVIµÄ°æ±¾±êÖ¾È»ºó´Ó×îÀïÃæÍùÍâÃæ¹ö¶¯³öÀ´
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//						TR0=0;
//				    	flash_16();	 //´Ó±ß±ßµÄ×óÓÒÖĞ¹ö¶¯ÏÔÊ¾Ä¬ÈÏµÄÓ¢ÎÄ×ÖÄ¸
//					}
//				}
//				TR0=1;
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_14();//Ò»¸öÒ»¸öµÄ×Ö±ä³öÀ´ÏÔÊ¾ÉÏÉıÑØµç×Ó¹âÁ¢·½¿ÉÒÔĞŞ¸ÄÏÔÊ¾Êı¾İ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_18();//ÏÔÊ¾³öÉÏÉıÑØµç×Ó8X8X8¹âÁ¢·½ÏÂÓêĞ§¹ûÆ®³ö×ÖÒÆ¶¯³öÈ¥
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_2();//Í¼ĞÎÈ¦È¦ÏÔÊ¾³öÀ´
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_3();//´ÓÇ°Ò»ÅÅÏÔÊ¾µ½ºóÃæÒ»ÅÅÁ½´Î
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_4();//´ÓÇ°Ò»ÅÅĞ±¸Ëµ½×îºóÒ»ÅÅÁ½´Î
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_5();//¿ò¿òÉìËõ´ÓÖĞ¼äµ½Ç°Ãæµ½ºóÃæ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_6();//¹öËÄ±ßµÄÈ¦È¦È»ºóÏÂÓêĞ§¹ûÆ®³ö×ÖÒÆ¶¯³öÈ¥
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_7();//¹öËÄ±ß°üÀ¨Ç°ºó×óÓÒ¹öÈ»ºó³öÀ´°ë±ßÈı½ÇĞÎ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_8();//´Ó×óÒÆ¶¯Ò»ÅÅµ½ÓÒ±ßÖĞ¼äÏÔÊ¾ÎÄ×ÖÍ¼ĞÎ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_9();//´Ó×óµ½ÓÒ±ß¹ö³öĞ±¸ËÈ»ºóÂİĞı×ªÖáĞı×ª¿ò¿òÏÔÊ¾·½¿òÉìËõ¿×¿ÕĞÄºÍÊµĞÄ
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_10();//´Ó×î×óĞ¡½ÅÉìËõ³ö¿ò¿òÈ»ºó±äÂÖ×ÓÇ°ºó×óÓÒÉÏÏÂ¹ö¶¯È»ºóÊÕËõ»¹Ô­
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_11();//ÏóºìÆìÒ»Ñù±»·çÆ®¶¯ÏóÉßÒ»ÑùÆ®¶¯×ß¶¯
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_12();//¹ö¶¯ÉÏÉıÑØµç×ÓµÄ×ÖÄ£Êı¾İÎÄ×ÖÒÆ¶¯ÏÔÊ¾³öÀ´
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_13();//½¥±ä³öÀ´ÎÄ×ÖVI1234IXUµÄÍ¼°¸
//					}
//				}
//				donghua_key2();
//				if(msd != 2){break;}
//				else
//				{
//					if(start2 == 1)
//					{
//				    	flash_19();//Æ½ĞĞ»¬¶¯ÏÔÊ¾³ö3D CULE FFTµÄ×Ö¸

//					}
//				}
//				TR0=0;												 				 											 	
//			}
			}
			else if(start2 == 0) //ÆµÆ×¶¯»­Ñ¡ÔñÄ£Ê½			
			{
				donghua_key2();
				if(msd != 2)
				{
					break;	
				}
				else		 	    
				{																	  
					 if(donghua1 == 1){TR0=0; flash_20();}	 //µÚÒ»¸öÃæÆÁÄ»ÉÏÏÂÀ­¿ª	  
					 else if(donghua1 == 2) {TR0=0;flash_21();}	 //´ÓºóÃæÍùÇ°ÃæÏÔÊ¾Êı×éµÄÊı×Ö9-0
					 else if(donghua1 == 3) {TR0=1;clear(0);piaozhi(table_3p_zf,2500,6);} //ÉÏÏÂ×óÓÒÇ°ºóÉ¨Ãè
					 else if(donghua1 == 4) {TR0=0;flash_22();}	 //Î§ÈÆ×Å×îÍâÃæµÄLEDÑ­»·¹ö¶¯ÏÔÊ¾Êı×éÖĞÄÚÈİ	 
					 else if(donghua1 == 5) {TR0=0;flash_23();}	 //·Ö²ãÉı½µ×óÓÒÉÏÏÂÇ°ºóÒÔ´Ë´ò¿ªÉı½µ²âÊÔ	
					 else if(donghua1 == 6) {TR0=0;flash_24();}     //´Ó×îÉÏÃæµÄÒ»¸öÃæÍùÏÂÃæµÄÒ»²ãÒÆ¶¯Íê
					 else if(donghua1 == 7) {TR0=0;V_scan(20);}   //ÏÂÏòÉÏÉ¨Ãè¼ì²â 
					 else if(donghua1 == 8) {TR0=0;flash_25();}	 //¹âÁ¢·½È«ÁÁ²¢ÇÒÉÁË¸5´Î
					 else if(donghua1 == 9) {TR0=0;flash_26();}     //´ÓÏÂÃæÍùÉÏÃæÒÀ´ÎÏÔÊ¾³öÊı×éÖĞµÄÄÚÈİIXU   
					 else if(donghua1 == 10){TR0=0;flash_27();}	 //ÀÇÆß°ËÕ¦µÄÏÔÊ¾³öLEDµÄÃ¿Ò»¸öµÆÕ¹Ê¾µÆ»ğĞ§¹û
					 else if(donghua1 == 11){TR0=0;flash_28();}	 //ÏÔÊ¾´ÓÉÏÃæÍùÏÂÃæµÎË®µÄĞ§¹û
					 else if(donghua1 == 12){TR0=0;H_scan(10);V_scan(10);W_scan(10); }	 //
					 else if(donghua1 == 13){TR0=0;flash_30();}	 //¿ÕĞÄÏÔÊ¾½«Êı×éÄÚÈİ´òÓ¡³öÀ´¿ÉÒÔ´òÓ¡4¸öÊı×éÄÚÈİ  
					 else if(donghua1 == 14){TR0=0;flash_31();}	 //½«×óÓÒµÄËÄ¸öÃæÎ§ÈÆ³ÉÈ¦È¦×ªÆğÀ´4´ÎÖ®ºó´Ó×ó±ßÍùÓÒ±ßÏÔÊ¾Êı×éÖĞÒ»·ùÍ¼Ïñ64¸öµÄÊı¾İ
					 else if(donghua1 == 15){TR0=0;flash_32();}	 //´Ó×ó±ßÏÔÊ¾Ò»¸öÃæÈ»ºóĞı×ª³öÒ»¸öÃæµÄ¿ÕĞÄĞ§¹ûÊµĞÄĞ§¹û  
					 else if(donghua1 == 16){TR0=0;flash_33();}	 //Ğı×ªµ¥¸öÃæÒÀ´Î½»»»µ½ÂòÒ»¸öÃæ	 
					 else if(donghua1 == 17){TR0=0;flash_34();}	 //ÒÔÖĞµãÎ»Öá½øĞĞÑ¡Ôñ×óÓÒĞı×ªÇĞ»»ÊµÏÖ²¨ÎÆµÄĞ§¹û	 
					 else if(donghua1 == 18){TR0=0;flash_35();}	 //Ğı×ª×óÓÒÎªÖĞĞÄ¼Ó¿ìËÙ¶ÈÊµÏÖÃ¿¸öÃæµÄ¶¶¶¯Ğ§¹û	
					 else if(donghua1 == 19){TR0=0;flash_36();}     //½«Êı×éÖĞµÄÄÚÈİÏÔÊ¾³öÏÖ½øĞĞĞı×ªÊÇÒ»¸öÕı·½ĞÎµÄ	  
					 else if(donghua1 == 20){TR0=0;flash_37();}	 //½«·½ĞÎ±äĞÎËõĞ¡È»ºó±ä³ÉÒ»¸öÈ«ÁÁµÄĞ§¹û	
					 else if(donghua1 == 21){TR0=0;W_scan(20);}	 //Ç°ÏòºóÉ¨Ãè¼ì²â
		 		 	 else if(donghua1 == 22){TR0=0;flash_38();}	 //Ç°ºó×óÓÒÉÏÏÂÉìËõÈ«ÁÁ    
					 else if(donghua1 == 23){TR0=0;flash_39();}	 //ÊµĞÄºÍ¿ÕĞÄËõ·ÅºÍ·Å´óÕı·½ĞÎÈ«ÁÁÏÔÊ¾	 
					 else if(donghua1 == 24){TR0=0;flash_40();}	 //¶¯»­ÏÔÊ¾Ò»¸öÊı×éÀïÃæµÄĞÄĞÎÊı¾İ »á¶¯µÄĞÄĞÎ
					 else if(donghua1 == 25){TR0=0;flash_41();}     //ÏÔÊ¾Ò»¸öµçÌİµÄÍ¼ĞÎ
					 else if(donghua1 == 26){TR0=0;flash_42();}	 //ÏÔÊ¾Êı×ÖÍùÉÏÒÆ¶¯³öÀ´	
					 else if(donghua1 == 27){TR0=0;flash_15();}     //ÏÔÊ¾ÏÂÓêµÄĞ§¹û			
					 
					 else if(donghua1 == 28) {TR0=1;flash_1();} //°üº¬µÚÒ»¸öÃæÏÔÊ¾4321µ¹¼ÆÊ±µÄÎÄ×Ö
					 else if(donghua1 == 29) {TR0=1;flash_17();}	//ÏÔÊ¾³öÒ»¸öVIµÄ°æ±¾±êÖ¾È»ºó´Ó×îÀïÃæÍùÍâÃæ¹ö¶¯³öÀ´
					 else if(donghua1 == 30) {TR0=0;flash_16();}//´Ó±ß±ßµÄ×óÓÒÖĞ¹ö¶¯ÏÔÊ¾Ä¬ÈÏµÄÓ¢ÎÄ×ÖÄ¸ideasoft
					 else if(donghua1 == 31) {TR0=1;flash_14();}//Ò»¸öÒ»¸öµÄ×Ö±ä³öÀ´ÏÔÊ¾ÉÏÉıÑØµç×Ó¹âÁ¢·½¿ÉÒÔĞŞ¸ÄÏÔÊ¾Êı¾İ
					 else if(donghua1 == 32) {TR0=1;clear(0);flash_18();}//ÏÔÊ¾³öÉÏÉıÑØµç×Ó8X8X8¹âÁ¢·½ÏÂÓêĞ§¹ûÆ®³ö×ÖÒÆ¶¯³öÈ¥
					 else if(donghua1 == 33) {TR0=1;clear(0);flash_2();}//Í¼ĞÎÈ¦È¦ÏÔÊ¾³öÀ´
					 else if(donghua1 == 34) {TR0=1;clear(0);flash_3();}//´ÓÇ°Ò»ÅÅÏÔÊ¾µ½ºóÃæÒ»ÅÅÁ½´Î
					 else if(donghua1 == 35) {TR0=1;clear(0);flash_4();}//´ÓÇ°Ò»ÅÅĞ±¸Ëµ½×îºóÒ»ÅÅÁ½´Î
					 else if(donghua1 == 36) {TR0=1;clear(0);flash_5();}//¿ò¿òÉìËõ´ÓÖĞ¼äµ½Ç°Ãæµ½ºóÃæ
					 else if(donghua1 == 37) {TR0=1;clear(0);flash_6();}//¹öËÄ±ßµÄÈ¦È¦È»ºóÏÂÓêĞ§¹ûÆ®³ö×ÖÒÆ¶¯³öÈ¥
					 else if(donghua1 == 38) {TR0=1;clear(0);flash_7();}//¹öËÄ±ß°üÀ¨Ç°ºó×óÓÒ¹öÈ»ºó³öÀ´°ë±ßÈı½ÇĞÎ
					 else if(donghua1 == 39) {TR0=1;clear(0);flash_8();}//´Ó×óÒÆ¶¯Ò»ÅÅµ½ÓÒ±ßÖĞ¼äÏÔÊ¾ÎÄ×ÖÍ¼ĞÎ
					 else if(donghua1 == 40) {TR0=1;clear(0);flash_9();}//´Ó×óµ½ÓÒ±ß¹ö³öĞ±¸ËÈ»ºóÂİĞı×ªÖáĞı×ª¿ò¿òÏÔÊ¾·½¿òÉìËõ¿×¿ÕĞÄºÍÊµĞÄ
					 else if(donghua1 == 41) {TR0=1;flash_10();}//´Ó×î×óĞ¡½ÅÉìËõ³ö¿ò¿òÈ»ºó±äÂÖ×ÓÇ°ºó×óÓÒÉÏÏÂ¹ö¶¯È»ºóÊÕËõ»¹Ô­
					 else if(donghua1 == 42) {TR0=1;flash_11();}//ÏóºìÆìÒ»Ñù±»·çÆ®¶¯ÏóÉßÒ»ÑùÆ®¶¯×ß¶¯
					 else if(donghua1 == 43) {TR0=1;flash_12();}//¹ö¶¯ÉÏÉıÑØµç×ÓµÄ×ÖÄ£Êı¾İÎÄ×ÖÒÆ¶¯ÏÔÊ¾³öÀ´
					 else if(donghua1 == 44) {TR0=1;flash_13();}//½¥±ä³öÀ´ÎÄ×ÖVI1234IXUµÄÍ¼°¸
					 else if(donghua1 == 45) {TR0=1;clear(0);flash_19();}//Æ½ĞĞ»¬¶¯ÏÔÊ¾³ö3D CULE FFTµÄ×Ö¸
				}	
			}			
	   }
	}	
}

/*          µçÄÔÉÏÎ»»úÄ£Ê½            */
void shangweiji_moshi()
{
	uchar i;
	if(msd==3)	 //ÉÏÎ»»úÄ£Ê½ 
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
/*          ÎÄ×ÖÄ£Ê½            */
void xiugaidonghua_moshi()
{
	//
	if(msd==4)	  //¶¯»­Ä£Ê½
	{	
		key3=3;	
		TR0=0;	
		ET0=0;
		xsdsq=1;
		hy(ZM+(13*8),10);
		W_side(ZM+(13*8),1,200);
		xsdsq=0;
		sinter();
		TR0=1;			  	//¿ªÆô¶¨Ê±Æ÷ÏÔÊ¾É¨Ãè
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
						 	flash_13();//½¥±ä³öÀ´ÎÄ×ÖVI1234IXUµÄÍ¼°¸  
						}
						else
						{
							flash_43();//ÏÔÊ¾ÎÄ×ÖµÄÄÚÈİ
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
						 	flash_19();//Æ½ĞĞ»¬¶¯ÏÔÊ¾³ö3D CULE FFTµÄ×Ö¸

						}
						else
						{
							flash_44();//ÏÔÊ¾ÎÄ×ÖµÄÄÚÈİ
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
							piaozhi(gaizi_san,2500,gaizi_geshu3/8);//ÏÔÊ¾ÎÄ×ÖµÄÄÚÈİ
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
							flash_22();	 //Î§ÈÆ×Å×îÍâÃæµÄLEDÑ­»·¹ö¶¯ÏÔÊ¾Êı×éÖĞÄÚÈİ
						}
						else
						{
								
							zimu(abc_char,jcount+5,12,1);	 //Ğı×ª×ÖÄ¸ zimu(uchar *x,char n,char v,int num)//¹ö¶¯×ÖÄ»,num±íÊ¾Ñ­»·´ÎÊı,v±íÊ¾¹ö¶¯ËÙ¶È,n×Ö·û¸öÊı	
						}
					}
				}
			} 		
			else if(start3 == 0) //ÆµÆ×¶¯»­Ñ¡ÔñÄ£Ê½			
			{
				gaizi_key2();
				if(msd != 4)
				{
					break;	
				}
				else		 	    
				{								 
					if(gaizi == 1) {TR0=1;if(gaizi1_flag){flash_13();}else {flash_43();}}//½¥±ä³öÀ´ÎÄ×ÖVI1234IXUµÄÍ¼°¸
					else if(gaizi == 2) {TR0=1;clear(0);if(gaizi2_flag){flash_19();}else {flash_44();}}	 //Æ½ĞĞ»¬¶¯ÏÔÊ¾³ö3D CULE FFTµÄ×Ö¸
					else if(gaizi == 3) {TR0=1;clear(0);if(gaizi3_flag){piaozhi(table_3p_zf,3000,6);}else {piaozhi(gaizi_san,3000,gaizi_geshu3/8);}}	//ÏÔÊ¾³öÉÏÉıÑØµç×Ó8X8X8¹âÁ¢·½ÏÂÓêĞ§¹ûÆ®³ö×ÖÒÆ¶¯³öÈ¥
					else if(gaizi == 4)	//Î§ÈÆ×Å×îÍâÃæµÄLEDÑ­»·¹ö¶¯ÏÔÊ¾Êı×éÖĞÄÚÈİ
					{						
						TR0=0; 
						if(gaizi4_flag)
						{
							flash_22();	 
						}
						else
						{
							
							zimu(abc_char,jcount+5,12,1);	 //Ğı×ª×ÖÄ¸ zimu(uchar *x,char n,char v,int num)//¹ö¶¯×ÖÄ»,num±íÊ¾Ñ­»·´ÎÊı,v±íÊ¾¹ö¶¯ËÙ¶È,n×Ö·û¸öÊı	
						}
					}
				}
			}		  
		}
	}	
}

#endif