#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student
{
   char name[20];
   char sex[10];
   int num;
   float CN;       //语文
   float MT;       //数学
   float EN;       //英语
   float SC;       //科学

}stu[40];
int NUM=0;
/*******************************************查找*****************************************/  
 int F3_seek()
 {
 	void exitSy();
 	char a[10]; 
	 int i,j=-2,d,num; 
	 	int h=0,k;
	float s;
	float sum[40],ave[40],sum2[3][40];
  	system("cls");
    printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
         if (NUM==0)
            {
            	printf("当前共有0个学生数据，无法进行查找操作！\n");
            	printf("请按任意键返回主菜单...\n");
            	getchar();
            	return;
			}
			printf("1.我想按姓名查询学生的数据\n"); 
		    printf("2.我想按学号查询学生的数据\n");
		    printf("3.返回主菜单\n");
            printf("0.退出系统\n");
             printf("Tips:请输入对应数字进入对应功能\n\n");		
loop18:    num=getNum();
          if (num>3)
            {
      	      printf("请输入正确的指令！\n"); 
      	      goto loop18;
	        }
         switch (num)
           {
            	case 0:exitSy();break;
      	        case 1:  system("cls");
                         printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                         	printf("请输入学生姓名：\n");
                           printf("Tips：输入\"exit\"退出系统，输入\"back\"回到主菜单...\n");
 loop3:                for(i=0;i<10;i++)
		                 a[i]='\0';      
                         gets(a);
                      if (strcmp(a,"exit")==0) 
                        	exitSy();
                        if (strcmp(a,"back")==0) 
                        	return -1; 
                       for (i=0;i<NUM;i++)
                          {
                       	      if (strcmp(a,stu[i].name)==0)
             	                  {
							          j=i; 
							          break;
								  } 
             	           }
			            if (j==-2) 
			                  { 
			   	               printf("查无此人，请重新输入：\n");
			   	               goto loop3;
			                  }
		                 
				        break;
		        case 2:  system("cls");
                         printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                         	printf("请输入学生学号：\n");
                           printf("Tips：输入\"exit\"退出系统，输入\"back\"回到主菜单...\n");
 loop19:                for(i=0;i<10;i++)
		                 a[i]='\0';      
                         gets(a);
                      if (strcmp(a,"exit")==0) 
                        	exitSy();
                        if (strcmp(a,"back")==0) 
                        	return -1; 
                       for (i=0;i<NUM;i++)
                          { 
                       	      if ((strlen(a)==1&&atoi(a)==stu[i].num)||(strlen(a)==2&&atoi(a)==stu[i].num))
             	                  {
							          j=i; 
							          break;
								  } 
             	           }
			            if (j==-2) 
			                  { 
			   	                printf("查无此人，请重新输入：\n");
			   	                goto loop19;
			                  }
		                 
				
				         break;
	        	case 3:return -1; 
	        }

		    
			system("cls");
           printf("\n*******************************************欢迎使用成绩管理系统！*******************************************\n");
    printf("\n   姓名    性别   学号   语文成绩(CN)   数学成绩(MT)  英语成绩(EN)   科学成绩(SC)   总分      平均分    排名\n");
        for (h=0;h<NUM;h++)
        {
           sum[h]=stu[h].CN+stu[h].MT+stu[h].EN+stu[h].SC; 
		   ave[h]=sum[h]/4.0;
		   sum2[0][h]=stu[h].CN+stu[h].MT+stu[h].EN+stu[h].SC; 
		}
	for(h=0;h<NUM;h++)
	 sum2[1][h]=h+1;
    for(h=0;h<NUM-1;h++)
    for(k=0;k<NUM-h-1;k++)
     {
     	if (sum2[0][k]<sum2[0][k+1])
     	  {
     	  	
		   	 s=sum2[0][k];
			 sum2[0][k]=sum2[0][k+1];
			 sum2[0][k+1]=s;
			 s=sum2[1][k];
			 sum2[1][k]=sum2[1][k+1];
			 sum2[1][k+1]=s;	 	
		  	 	
		  }
	 } 

	for(h=0;h<NUM;h++)
	  sum2[2][h]=h+1;   
	
	for(h=0;h<NUM-1;h++)
	for(k=0;k<NUM-h-1;k++)
     {
     	if (sum2[1][k]>sum2[1][k+1])
     	  {
     	  	
		   	 s=sum2[1][k];
			 sum2[1][k]=sum2[1][k+1];
			 sum2[1][k+1]=s;
			 s=sum2[2][k];
			 sum2[2][k]=sum2[2][k+1];
			 sum2[2][k+1]=s;	 	
		  	 	
		  }
	 }  

  	
	     printf(" %-8s|  %-2s  |  %-2d  |   %-6.2f    |     %-6.2f   |    %-6.2f    |    %-6.2f  |  %-6.2f  |  %-6.2f  |  %.0f \n",stu[j].name,stu[j].sex,stu[j].num,stu[j].CN,stu[j].MT,stu[j].EN,stu[j].SC,sum[j],ave[j],sum2[2][j]);
    	getchar(); 
		return j;    
		    
		

} 	
/***************************************退出系统***************************************************/ 
void exitSy()
{
	 printf("系统将于  3  秒后关闭..."); 
	 	Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  秒后关闭...",2); 
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  秒后关闭...",1); 
		Sleep(1000);
	exit(0);
	
 } 

/***************************************保存完毕-说话***************************************************/ 
void saveAll()
{
	system("cls");
	printf("\n*****************************欢迎进入成绩管理系统！*****************************\n");
  
	 printf("系统将于  3  秒后保存完毕..."); 
	 	Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  秒后保存完毕...",2); 
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  秒后保存完毕...\n",1); 
		Sleep(1000); 
		printf("\n数据保存完毕，请按任意键回到主菜单！\n");
		getchar(); 
 } 
 /*******************************************密码*****************************************/  
 int key()
 {
 	
 	char a[10];
    int i;
    for (i=0;i<10;i++)
    {
    	a[i]=getch();
    	if (a[i]=='\b'&&i==0)
    {
		 	 a[i]='\0';
			  i--;
		    continue;
	}
	else if (a[i]=='\b'&&i>0)
	  {
	  	 printf("\b \b");
	  	 a[i]='\0';
	     i-=2;	 
	  }
	else if(a[i]==13)
	  {
	  	 a[i]='\0';
		 break;        
	  }
	else 		
	  	printf("*");   
    }
	if(strcmp(a,"0000")==0)
		    return 1;
	else return  0;
	
}
/*****************************************登录*****************************************************/ 
void login()
{
	void menu();
	char a[10];  
	int  b=0;
	int i;
    printf("\n*****************************欢迎进入成绩管理系统！*****************************\n");
    printf("请输入密码");
	printf("（Tips：密码为四个数字，总共3次机会）:\n\n");
    for (i=4;i>0;i--)
	   {
	   	  b=key();
	   	  if (b==1)
	   	    break;
	   	  else if (i==2)
			   {
				 printf("\n对不起，密码输入错误\n\n");
				 exitSy();
			   }
		  else
			 printf("\n对不起，输入错误，您还有%d次机会：\n\n",i-2);
	   	  	   
		
	   }
     
	 menu();  
	// if (b==2) exit(0);	
	
	
} 

/*****************************************显示菜单*****************************************************/ 
 void menu()
{
	void F1_get();
	void F8_save();
	void getData();
   void F2_change();
	void A_txtPrint();
	void F4_deletAll();
	 void F7_show();
	char a[50];
	char b[10];
	int  num,q;
	system("CLS");
	getData();                       //获得数据 
    printf("\n*****************************欢迎进入成绩管理系统！*****************************\n");
	printf("录入(1)\\修改(2)\\查找(3)\\删除(4)\\排序(5)\\显示(6)\\统计(7)\\打印(8)\\退出系统(0)\n");
    printf("(Tips:请输入菜单旁边的数字进入对应功能！)\n\n");
	num=getNum();                   //得到一个正确的指令 
  switch (num)
	{
	    case 1:F1_get();break;
	    case 2:F2_change();break;
		case 3:q=F3_seek();
		       break;
		case 4:F4_deletAll();break;
		case 5:F5_sort();break;
    	case 6:F7_show();break;
		case 7:F7_statistics();break;
    	case 8:A_txtPrint();break;
	    case 0:exitSy();break;
	}
}
/*******************************录入每个同学的学号、姓名、性别和各科的考试成绩**************************/
  void F1_get()
  {
    void F8_save();
    int i,j,num;
    char a[10];
    char sub[][4]={"CN:","MT:","EN:","SC:"}; 
    float grades[4];
	system("CLS");
  	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
  	printf("当前有%d个学生的资料，",NUM);
  	printf("您想输入几个学生的信息？\n");
  
  	scanf("%d",&num);
  	getchar();
  
  	for(i=0;i<num;i++)
  	{
loop1: system("CLS");  	  
       printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
  	   printf("请输入第%d位学生的姓名+性别(男/女)+学号：\n",i+1);             
       printf("Tips：中间请以回车分开\n"); 
       scanf("%s%*c%s%*c%d%*c",stu[NUM+i].name,stu[NUM+i].sex,&stu[i+NUM].num);
       printf("请输入第%d位学生的成绩：\n",i+1);
       printf("Tips：语文（CN），数学（MT），英语（EN），科学（SC）\n"); 
       for (j=0;j<4;j++)
       {
       	  printf("%s",sub[j]);
       	  scanf("%f",&grades[j]);
	   }
	   getchar();
	  if (num==1||i==num-1)
	     printf("您确定输入正确吗？（Y/N/B/E）\n");
	  else
	    printf("您确定正确并进入下一名吗？（Y/N/B/E）\n");
loop2:	   scanf("%s%*c",a);
	   if (a[0]=='Y')
	    {
	   	 stu[i+NUM].CN=grades[0];
	     stu[i+NUM].MT=grades[1];
	     stu[i+NUM].EN=grades[2];
	     stu[i+NUM].SC=grades[3];
	    
	     continue;
	    }
	   else if(a[0]=='N')
	    {
	      	system("CLS");
			goto loop1;	
		}
		 else if(a[0]=='B')
	    {
	        printf("\n请按任意键返回主菜单（数据未保存）...\n\n") ;
			getchar();
			return; 
		}
		else if(a[0]=='E')
	    {
	       
			exitSy();
		}
	  else
	    {
	   	   printf("请输入正确指令（Y/N）\n");
	   	   goto loop2; 
	    }
	   }
    NUM+=num;
   if (num!=0) F8_save();
    	// printf("%s  %s  %s   yuwen:%f    shuxue:%f    yingyu:%f   kexue:%f\n",stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC); 
}
/*******************************************获得一个正确的指令*****************************************/ 
int getNum()
{
	int num;
	char b[50];
	scanf("%s",b);
	getchar();
	if ((strlen(b)==1)&&b[0]>='0'&&b[0]<='9')
		num=b[0]-48;
		else 
		 {
		 	printf("请输入正确的指令！\n"); 
            num=getNum();
         }
     return num;
}

/*******************************************获得数据*****************************************/
void getData()
{
	FILE *p;
	int i=0,size;
	p=fopen("Student Grades.dat","rb");
	if (!p)
	{
		printf("File is wrong!");
		exit(0);
	}
	
   fseek(p,0L,2);
   size=ftell(p);
   if (size==0) NUM=0;
    else
	  {
	  	rewind(p);
	  	fread(&NUM,sizeof(int),1,p);
	   } 
  for(i=0;i<NUM;i++)
	 {
	 	rewind(p);
	 	fseek(p,sizeof(int)+i*sizeof(struct Student),0);
	 	fread(&stu[i],sizeof(struct Student),1,p);
       
	 }
   fclose(p);		

} 
/*******************************************保存修改---二进制文件(有话)*****************************************/ 
void F8_save()
{
	
	int i=0;
	FILE *p;
	p=fopen("Student Grades.dat","wb");
	if (!p)
	{
		printf("File is wrong!");
		exit(0);
	}
  	fwrite(&NUM,sizeof(int),1,p);
	for (i=0;i<NUM;i++)
	  fwrite(&stu[i],sizeof(struct Student),1,p);
	fclose(p);
	saveAll(); 
}
/*******************************************保存修改---二进制文件(没话)*****************************************/ 
void F8_save1()
{
	
	int i=0;
	FILE *p;
	p=fopen("Student Grades.dat","wb");
	if (!p)
	{
		printf("File is wrong!");
		exit(0);
	}
  	fwrite(&NUM,sizeof(int),1,p);
	for (i=0;i<NUM;i++)
	  fwrite(&stu[i],sizeof(struct Student),1,p);
	fclose(p);
//	saveAll(); 
}
/*******************************************打印---文本文档*****************************************/ 
void A_txtPrint()
{
	int i=0;
	char head1[100]="*****************************欢迎使用成绩管理系统！******************************\n"; 
	char head2[100]="\n   姓名    性别   学号   语文成绩(CN)   数学成绩(MT)   英语成绩(EN)   科学成绩(SC)\n\n";
	FILE *p;
	p=fopen("学生成绩.txt","w");
	if (!p)
	{
		printf("File is wrong!");
		exit(0);
	}
	fputs(head1,p);
    fputs(head1,p);
    fputs(head1,p);
    fputs(head2,p);
    if (NUM!=0)
  	  for(i=0;i<NUM;i++)
	     fprintf(p," %-8s|  %-2s  |  %-2d  |   %-6.2f    |     %-6.2f   |    %-6.2f    |    %-6.2f\n",stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC);
        
			fclose(p);
}
/*******************************************成绩修改*****************************************/ 
void F2_change()
{
	int num,i,k,h,j=-2;
	char a[10];
	 char sub[][4]={"CN:","MT:","EN:","SC:"}; 
   
	 struct Student example;
	system("cls");
	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
   if (NUM==0)
     {
	  	printf("当前共有0位学生,无法进行修改 \n");
	  	printf("请按任意键回到主菜单... \n");
	  	getchar();
		return;
	 }
	 system("cls");
	      j=F3_seek();
       if (j==-1) return; 
loop4:	      printf("\n1.我想修改姓名\n");	
          printf("2.我想修改性别\n");
          printf("3.我想修改学号\n");
          printf("4.我想修改语文成绩（CN）\n");
          printf("5.我想修改数学成绩（MT）\n");
		  printf("6.我想修改英语成绩（EN）\n");
          printf("7.我想修改科学成绩（SC）\n");
          printf("8.我想修改全部\n"); 
		  printf("9.返回主菜单\n");
		  printf("0.退出系统\n");	   	
          printf("Tips:请输入指定数字进行修改\n");	   	
       num=getNum();
    switch (num)
	{
	    case 1:  system("cls");
              	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                 printf("请输入姓名：");
	             gets(example.name);
	        
	             printf("您确定将  %s  修改为  %s  吗？（Y\\N）",stu[j].name,example.name);
loop5:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     strcpy(stu[j].name,example.name);
				  	 break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("请输入正确指令！\n");
				  	 goto loop5;
				   }	 
	    case 2: system("cls");
              	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                printf("请输入性别：");
	             gets(example.sex);
	             printf("您确定将  %s  修改为  %s  吗？（Y\\N）",stu[j].sex,example.sex);
loop6:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     strcpy(stu[j].sex,example.sex);
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("请输入正确指令！\n");
				  	 goto loop6;
				   }	 
	    case 3: system("cls");
              	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                printf("请输入学号：");
	             scanf("%d",&example.num);
	             printf("您确定将  %d  修改为  %d  吗？（Y\\N）",stu[j].num,example.num);
loop7:	             for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j].num=example.num;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("请输入正确指令！\n");
				  	 goto loop7;
				   }	 
		case 4: system("cls");
              	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                printf("请输入语文成绩（CN）：");
	             scanf("%f",&example.CN);
	             getchar();
	             printf("您确定将  %.2f  修改为  %.2f  吗？（Y\\N）",stu[j].CN,example.CN);
loop8:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j].CN=example.CN;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("请输入正确指令！\n");
				  	 goto loop8;
				   }
			
		case 5:system("cls");
              	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                printf("请输入数学成绩（MT）：");
	             scanf("%f",&example.MT);
	             getchar();
	             printf("您确定将  %.2f  修改为  %.2f  吗？（Y\\N）",stu[j].MT,example.MT);
loop9:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j].MT=example.MT;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("请输入正确指令！\n");
				  	 goto loop9;
				   }
		case 6:system("cls");
              	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                printf("请输入英语成绩（EN）：");
	             scanf("%f",&example.EN);
	             getchar();
	             printf("您确定将  %.2f  修改为  %.2f  吗？（Y\\N）",stu[j].EN,example.EN);
loop10:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j].EN=example.EN;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("请输入正确指令！\n");
				  	 goto loop10;
				   }
		case 7:system("cls");
              	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                printf("请输入科学成绩（SC）：");
	             scanf("%f",&example.SC);
	             getchar();
	             printf("您确定将  %.2f  修改为  %.2f  吗？（Y\\N）",stu[j].SC,example.SC);
loop11:	            for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j].SC=example.SC;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("请输入正确指令！\n");
				  	 goto loop11;
				   }
	    case 8: system("cls");
              	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                printf("请输入学生的姓名+性别(男/女)+学号：\n");
                printf("Tips：中间请以回车分开\n");
 				scanf("%s%*c%s%*c%d%*c",example.name,example.sex,&example.num);
 				printf("请输入学生的成绩：\n");
 				printf("Tips：语文（CN），数学（MT），英语（EN），科学（SC）\n"); 
      		    printf("%s",sub[0]);
       	 		scanf("%f",&example.CN);
	            printf("%s",sub[1]);
       	        scanf("%f",&example.MT);  
                printf("%s",sub[2]);
       	       scanf("%f",&example.EN); 
               printf("%s",sub[3]);
       	       scanf("%f",&example.SC);
               printf("您确定输入正确并修改吗？（Y\\N）");
loop12:	         for(h=0;h<10;h++)
		               a[h]='\0';   
				 gets(a);
	             if (a[0]=='Y'&&strlen(a)==1)
	               {
				     stu[j]=example;
				     break;
					} 
				 else if (a[0]=='N'&&strlen(a)==1)
				   {
				   	  system("cls");
				   	  	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
                       goto loop4;
					 }	
				else 
				  {
				  	 printf("请输入正确指令！\n");
				  	 goto loop12;
				   }
	    case 9:return;
	    case 0:exitSy();
}
           printf("\n修改后的学生数据为 ：\n");
		   printf("%s  %s  %d   CN:%.2f    MT:%.2f    EN:%.2f   SC:%.2f\n",stu[j].name,stu[j].sex,stu[j].num,stu[j].CN,stu[j].MT,stu[j].EN,stu[j].SC); 
           printf("请再次确认，确定保存修改吗？(Y\\N)\n");
           printf("（Warning：数据一旦修改，则无法恢复！）\n");
loop13:		   for(h=0;h<10;h++)
		      a[h]='\0';   
			gets(a);
			 if (a[0]=='Y'&&strlen(a)==1)
	          F8_save();
               else if (a[0]=='N'&&strlen(a)==1)
                {
                	printf("数据保存失败！请按任意键回到主菜单！\n");
				    getchar();
				    return;
			    }
			    else 
				  {
				  	 printf("请输入正确指令！\n");
				  	 goto loop13;
				   }
}
/*******************************************成绩删除*****************************************/  
void F4_delet()
{
	int i,h,j=-2;
	char a[10];
	struct Student example;
	system("cls");
	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
   if (NUM==0)
     {
	  	printf("当前共有0位学生,无法进行删除操作 \n");
	  	printf("请按任意键回到主菜单... \n");
	  	getchar();
		return;
	 }
	
	      j=F3_seek();
          if (j==-1) return; 
          printf("确认删除该学生的信息吗？(Y\\N)\n");
	      printf("(Warning：数据一旦修改，则无法恢复！）\n");
loop14:   for(h=0;h<10;h++)
		      a[h]='\0';   
		  gets(a);
		  if (a[0]=='Y'&&strlen(a)==1)
	        {
	    	   if (j==NUM)  goto loop15;
	    	   else 
			     {
			           for(i=j+1;i<=NUM;i++)
					     {
					        stu[i-1]=stu[i];	 
						 }   	 	
				 }  
loop15:	       NUM-=1;
	    	   F8_save();
	    	}
         else if (a[0]=='N'&&strlen(a)==1)
            {
                printf("数据删除失败！请按任意键回到主菜单！\n");
				getchar();
				return;
			}
		 else 
			{
				printf("请输入正确指令！\n");
				goto loop14;
			}
}
/*******************************************按每个学生的总分进行排序*****************************************/  
void sort1()
{
	struct Student example1;
	int i,j;
	float sum[40];
	float a;
     for (i=0;i<NUM;i++)
        sum[i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC;
   
    for(i=0;i<NUM-1;i++)
    for(j=0;j<NUM-i-1;j++)
     {
     	if (sum[j]<sum[j+1])
     	  {
     	  	 example1=stu[j];
     	  	 stu[j]=stu[j+1];
			 stu[j+1]=example1;	 
			 a=sum[j];
			 sum[j]=sum[j+1];
			 sum[j+1]=a;	 	
		  }
	 }
}	
/*******************************************按学号排出成绩表*****************************************/  
void sort2()
{
	struct Student example;
	int i,j;

    for(i=0;i<NUM-1;i++)
    for(j=0;j<NUM-i-1;j++)
     {
     	if (stu[j].num>stu[j+1].num)
     	  {
     	  	 example=stu[j];
     	  	 stu[j]=stu[j+1];
			 stu[j+1]=example;	 	
		  }
	 }
	
}	
/*******************************************按姓名的字典顺序排出成绩表*****************************************/  
void sort3()
{
	struct Student example;
	int i,j;
    for(i=0;i<NUM-1;i++)
    for(j=0;j<NUM-i-1;j++)
     {
     	if (strcmp(stu[j].name,stu[j+1].name)==1)
     	  {
     	  	 example=stu[j];
     	  	 stu[j]=stu[j+1];
			 stu[j+1]=example;	 	
		  }
	 }
}	
/*****************************************排序*****************************************************/ 
F5_sort()
{
	int num,j;
	system("cls");
	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
     if (NUM==0)
            {
            	printf("当前共有0个学生数据，无法进行排序操作！\n");
            	printf("请按任意键返回主菜单...\n");
            	getchar();
            	return;
			}
	printf("\n1.按每个学生的总分进行排序\n");
  	printf("2.按学号排出成绩表；\n");
  	printf("3.按姓名的字典顺序排出成绩表");
    printf("\n4.返回主菜单\n");
    printf("0.退出系统\n");
    printf("Tips:请输入对应数字进入对应功能\n\n");		
loop17:    num=getNum();
    if (num>4)
      {
      	 printf("请输入正确的指令！\n"); 
      	 goto loop17;
	  }
    switch (num)
      {
      	case 0:exitSy();break;
      	case 1:sort1();break;
		case 2:sort2();break;
		case 3:sort3();break;
	    case 4:return;break;
	  }

	system("cls");
	printf("\n*****************************欢迎进入成绩管理系统！*****************************\n");
  
	 printf("系统将于  3  秒后保存完毕..."); 
	 	Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  秒后保存完毕...",2); 
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  秒后保存完毕...\n",1); 
		Sleep(1000); 
	
	 printf("\n数据排序完毕,请输入任意键回到主菜单！\n");
	 printf("Tips:可进入【显示】功能查看排序后的数据！\n\n");
	 F8_save1();
	 getchar(); 
} 		
/*******************************************统计计算*****************************************/  
F7_statistics()
{
	int num,i,j; 
	void statistics1();
	void statistics2();
	void statistics3() ;
	void statistics4() ;
	system("cls");
	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
    if (NUM==0)
            {
            	printf("当前共有0个学生数据，无法进行计算操作！\n");
            	printf("请按任意键返回主菜单...\n");
            	getchar();
            	return;
			}
  	printf("\n1.计算每门课程的总分和平均分\n");
  	printf("2.计算每个学生所有课程的总分和平均分\n");
  	printf("3.对每门课程按优（90~100）、良（80~89）、中（70~79）、\n  及格（60~69）、不及格（0~59）统计人数，及所占的百分比\n");
   	printf("4.输出班级每门课程的统计数据");
    printf("\n5.返回主菜单\n");
    printf("0.退出系统\n");
    printf("Tips:请输入对应数字进入对应功能\n");
loop15:    num=getNum();
    if (num>5)
      {
      	 printf("请输入正确的指令！\n"); 
      	 goto loop15;
	  }
    switch (num)
      {
      	case 0:exitSy();
      	
      	case 1:statistics1();break;
		case 2:statistics2();break;
		case 3:statistics3() ;break;
		case 4:statistics4() ;break;
		case 5:return;
	  }

	printf("\n\n请按任意键返回主菜单...\n");
	getchar();	
}
/*******************************************计算每门课程的总分和平均分*****************************************/  
void statistics1()
{
  	system("cls");
  	float ave[4],sum[4];
  	int i,j;
  	for (i=0;i<NUM;i++)
  	{
  		sum[0]+=stu[i].CN;
  		sum[1]+=stu[i].MT;
  		sum[2]+=stu[i].EN;
  		sum[3]+=stu[i].SC;
    }
    for (i=0;i<4;i++)
      ave[i]=sum[i]/NUM;
	printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
    printf("每门课程的总分和平均分为：\n\n");
    printf("              |  语文(CN)  |  数学(MT)  | 英语(EN)  | 科学(SC)             \n") ;
    printf("       总分： |  %7.2f   |  %7.2f   |  %7.2f  | %7.2f\n",sum[0],sum[1],sum[2],sum[3]) ;
    printf("      平均分: |  %7.2f   |  %7.2f   |  %7.2f  | %7.2f\n",ave[0],ave[1],ave[2],ave[3]) ;
  
}	
/*******************************************计算每个学生所有课程的总分和平均分*****************************************/  
void statistics2()
{
  	float ave[40],sum[40];
    system("cls");
	int i,j;
	for (i=0;i<NUM;i++)
  	{
  		sum[i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC;
  	    ave[i]=sum[i]/4;
    }
    printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
    printf("每个学生所有课程的总分和平均分为：\n\n");
    printf("             |           总分           |              平均分\n");
    for (j=0;j<NUM;j++)
       printf("     %-8s|          %6.2f          |              %6.2f\n",stu[j].name,sum[j],ave[j]);	
}
/********对每门课程按优（90~100）、良（80~89）、中（70~79）、\n  及格（60~69）、不及格（0~59）统计人数，及所占的百分比******/  
void statistics3() 
{
	 system("cls");
	 int i,j;
	int sum[4][5]={0};

	for (i=0;i<NUM;i++)
    	{
    		if (stu[i].CN>=90&&stu[i].CN<=100) sum[0][0]++;
			if (stu[i].CN>=80&&stu[i].CN<=89)  sum[0][1]++;
			if (stu[i].CN>=70&&stu[i].CN<=79) sum[0][2]++;
			if (stu[i].CN>=60&&stu[i].CN<=69) sum[0][3]++;
			if (stu[i].CN >=0&&stu[i].CN<=59) sum[0][4]++;
			
			if (stu[i].MT>=90&&stu[i].MT<=100) sum[1][0]++;
			if (stu[i].MT>=80&&stu[i].MT<=89)  sum[1][1]++;
			if (stu[i].MT>=70&&stu[i].MT<=79)  sum[1][2]++;
			if (stu[i].MT>=60&&stu[i].MT<=69)  sum[1][3]++;
			if (stu[i].MT >=0&&stu[i].MT<=59)  sum[1][4]++;
			
			if (stu[i].EN>=90&&stu[i].EN<=100) sum[2][0]++;
			if (stu[i].EN>=80&&stu[i].EN<=89)  sum[2][1]++;
			if (stu[i].EN>=70&&stu[i].EN<=79)  sum[2][2]++;
			if (stu[i].EN>=60&&stu[i].EN<=69)  sum[2][3]++;
			if (stu[i].EN >=0&&stu[i].EN<=59)  sum[2][4]++;
			
			if (stu[i].SC>=90&&stu[i].SC<=100) sum[3][0]++;
			if (stu[i].SC>=80&&stu[i].SC<=89)  sum[3][1]++;
			if (stu[i].SC>=70&&stu[i].SC<=79)  sum[3][2]++;
			if (stu[i].SC>=60&&stu[i].SC<=69)  sum[3][3]++;
			if (stu[i].SC >=0&&stu[i].SC<=59)  sum[3][4]++;
		}
    printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
    printf("每门课程分等级统计人数，及所占的百分比：\n");
    printf("Tips:优（90~100）、良（80~89）、中（70~79）、及格（60~69）、不及格（0~59）\n");
    printf("Tips:当前共有%d人\n\n",NUM); 
    printf("1.人数：\n\n") ;
   printf(" \t| 语文(CN)  |  数学(MT)  |   英语(EN)  |   科学(SC)   \n");
    printf("   优   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][0],sum[1][0],sum[2][0],sum[3][0]);	
    printf("   良   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][1],sum[1][1],sum[2][1],sum[3][1]);    
    printf("   中   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][2],sum[1][2],sum[2][2],sum[3][2]);	
    printf("  及格  |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][3],sum[1][3],sum[2][3],sum[3][3]);	
    printf(" 不及格 |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][4],sum[1][4],sum[2][4],sum[3][4]);
    printf("\n\n2.百分比：\n\n");
    printf(" \t|  语文(CN)  |   数学(MT)  |   英语(EN)  |   科学(SC)   \n");
    printf("   优   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][0]*100.0/NUM,sum[1][0]*100.0/NUM,sum[2][0]*100.0/NUM,sum[3][0]*100.0/NUM);	
    printf("   良   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][1]*100.0/NUM,sum[1][1]*100.0/NUM,sum[2][1]*100.0/NUM,sum[3][1]*100.0/NUM);    
    printf("   中   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][2]*100.0/NUM,sum[1][2]*100.0/NUM,sum[2][2]*100.0/NUM,sum[3][2]*100.0/NUM);	
    printf("  及格  |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][3]*100.0/NUM,sum[1][3]*100.0/NUM,sum[2][3]*100.0/NUM,sum[3][3]*100.0/NUM);	
    printf(" 不及格 |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][4]*100.0/NUM,sum[1][4]*100.0/NUM,sum[2][4]*100.0/NUM,sum[3][4]*100.0/NUM);
  
}
/********输出班级每门课程的统计数据：包括每门课程的平均分、每门课程优、良、中、及格、不及格的人数及所占百分比********/  
void statistics4() 
{
    system("cls");
	 int i,j;
	int sum[4][5]={0};

	for (i=0;i<NUM;i++)
    	{
    		if (stu[i].CN>=90&&stu[i].CN<=100) sum[0][0]++;
			if (stu[i].CN>=80&&stu[i].CN<=89)  sum[0][1]++;
			if (stu[i].CN>=70&&stu[i].CN<=79) sum[0][2]++;
			if (stu[i].CN>=60&&stu[i].CN<=69) sum[0][3]++;
			if (stu[i].CN >=0&&stu[i].CN<=59) sum[0][4]++;
			
			if (stu[i].MT>=90&&stu[i].MT<=100) sum[1][0]++;
			if (stu[i].MT>=80&&stu[i].MT<=89)  sum[1][1]++;
			if (stu[i].MT>=70&&stu[i].MT<=79)  sum[1][2]++;
			if (stu[i].MT>=60&&stu[i].MT<=69)  sum[1][3]++;
			if (stu[i].MT >=0&&stu[i].MT<=59)  sum[1][4]++;
			
			if (stu[i].EN>=90&&stu[i].EN<=100) sum[2][0]++;
			if (stu[i].EN>=80&&stu[i].EN<=89)  sum[2][1]++;
			if (stu[i].EN>=70&&stu[i].EN<=79)  sum[2][2]++;
			if (stu[i].EN>=60&&stu[i].EN<=69)  sum[2][3]++;
			if (stu[i].EN >=0&&stu[i].EN<=59)  sum[2][4]++;
			
			if (stu[i].SC>=90&&stu[i].SC<=100) sum[3][0]++;
			if (stu[i].SC>=80&&stu[i].SC<=89)  sum[3][1]++;
			if (stu[i].SC>=70&&stu[i].SC<=79)  sum[3][2]++;
			if (stu[i].SC>=60&&stu[i].SC<=69)  sum[3][3]++;
			if (stu[i].SC >=0&&stu[i].SC<=59)  sum[3][4]++;
		}
    printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
    printf("每门课程分等级统计人数，及所占的百分比：\n");
    printf("Tips:优（90~100）、良（80~89）、中（70~79）、及格（60~69）、不及格（0~59）\n");
    printf("Tips:当前共有%d人\n\n",NUM); 
    printf("1.人数：\n\n") ;
   printf(" \t| 语文(CN)  |  数学(MT)  |   英语(EN)  |   科学(SC)   \n");
    printf("   优   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][0],sum[1][0],sum[2][0],sum[3][0]);	
    printf("   良   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][1],sum[1][1],sum[2][1],sum[3][1]);    
    printf("   中   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][2],sum[1][2],sum[2][2],sum[3][2]);	
    printf("  及格  |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][3],sum[1][3],sum[2][3],sum[3][3]);	
    printf(" 不及格 |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][4],sum[1][4],sum[2][4],sum[3][4]);
    printf("\n\n2.百分比：\n\n");
    printf(" \t|  语文(CN)  |   数学(MT)  |   英语(EN)  |   科学(SC)   \n");
    printf("   优   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][0]*100.0/NUM,sum[1][0]*100.0/NUM,sum[2][0]*100.0/NUM,sum[3][0]*100.0/NUM);	
    printf("   良   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][1]*100.0/NUM,sum[1][1]*100.0/NUM,sum[2][1]*100.0/NUM,sum[3][1]*100.0/NUM);    
    printf("   中   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][2]*100.0/NUM,sum[1][2]*100.0/NUM,sum[2][2]*100.0/NUM,sum[3][2]*100.0/NUM);	
    printf("  及格  |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][3]*100.0/NUM,sum[1][3]*100.0/NUM,sum[2][3]*100.0/NUM,sum[3][3]*100.0/NUM);	
    printf(" 不及格 |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][4]*100.0/NUM,sum[1][4]*100.0/NUM,sum[2][4]*100.0/NUM,sum[3][4]*100.0/NUM);
   float ave[4],sum1[4];
  	
  	for (i=0;i<NUM;i++)
  	{
  		sum1[0]+=stu[i].CN;
  		sum1[1]+=stu[i].MT;
  		sum1[2]+=stu[i].EN;
  		sum1[3]+=stu[i].SC;
    }
    for (i=0;i<4;i++)
      ave[i]=sum1[i]/NUM;
 printf("\n\n3.平均分&总分：\n\n");
   
    printf("              |  语文(CN)  |  数学(MT)  | 英语(EN)  | 科学(SC)             \n") ;
    printf("       总分： |  %7.2f   |  %7.2f   |  %7.2f  | %7.2f\n",sum1[0],sum1[1],sum1[2],sum1[3]) ;
    printf("      平均分: |  %7.2f   |  %7.2f   |  %7.2f  | %7.2f\n",ave[0],ave[1],ave[2],ave[3]) ;
} 
 /*******************************************成绩删除-所有*****************************************/  
void F4_deletAll()
{ 
     char a[10];
     FILE *p;
     
	 int i,j,num,h; 
     system("cls");
	 printf("\n*****************************欢迎使用成绩管理系统！*****************************\n\n");
	 
	 printf("1.我想删除个别数据\n2.我想删除所有数据\n");
	 printf("3.返回主菜单\n0.退出系统\n"); 
	 printf("(Tips:请输入菜单旁边的数字进入对应功能！)\n\n");
loop17:	 num=getNum();
	 if(num==1) F4_delet();
	  else if (num==0)
	    exitSy();
	   else if (num==3)
	     return;
	  else if (num==2)
	   {
	   	  system("cls");
	      printf("\n****************************欢迎使用成绩管理系统！*****************************\n\n");
	      if (NUM==0)
		     {
			   printf("当前共有0个学生数据，无法进行删除操作！\n请按任意键返回主菜单...\n");
			   getchar();
			   return;
		     }

		  printf("当前共有%d位学生，确认全部删除吗？(Y\\N)\n",NUM);
		   printf("(Warning：数据一旦修改，则无法恢复！）\n");
loop16:   for(h=0;h<10;h++)
		      a[h]='\0';   
		  gets(a);
		  if (a[0]=='Y'&&strlen(a)==1)
	        {
	                p=fopen("Student Grades.dat","wb");
	                if (!p)
	                   {
		                    printf("File is wrong!");
                    		exit(0);
	                   }
  	              
  	               NUM=0;
  	               fwrite(&NUM,sizeof(int),1,p);
  	                fclose(p);
                   saveAll();    	   
			}
         else if (a[0]=='N'&&strlen(a)==1)
            {
                printf("数据删除失败！请按任意键回到主菜单！\n");
				getchar();
				return;
			}
		 else 
			{
				printf("请输入正确指令！\n");
				goto loop16;
			}
	   }
	   else 
	     {
	     	printf("请输入正确的指令！\n");
	        goto loop17;
		 }

} 
/*******************************************显示*****************************************/  
void F7_show()
{
	system("cls"); 
	int i=0,j;
	float a;
	float sum[40],ave[40],sum2[3][40];
    printf("\n*******************************************欢迎使用成绩管理系统！*******************************************\n");
    printf("\n   姓名    性别   学号   语文成绩(CN)   数学成绩(MT)  英语成绩(EN)   科学成绩(SC)   总分      平均分    排名\n");
    for (i=0;i<NUM;i++)
        {
           sum[i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC; 
		   ave[i]=sum[i]/4.0;
		   sum2[0][i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC; 
		}
	for(i=0;i<NUM;i++)
	 sum2[1][i]=i+1;
    for(i=0;i<NUM-1;i++)
    for(j=0;j<NUM-i-1;j++)
     {
     	if (sum2[0][j]<sum2[0][j+1])
     	  {
     	  	
		   	 a=sum2[0][j];
			 sum2[0][j]=sum2[0][j+1];
			 sum2[0][j+1]=a;
			 a=sum2[1][j];
			 sum2[1][j]=sum2[1][j+1];
			 sum2[1][j+1]=a;	 	
		  	 	
		  }
	 } 

	for(i=0;i<NUM;i++)
	  sum2[2][i]=i+1;   
	
	for(i=0;i<NUM-1;i++)
	for(j=0;j<NUM-i-1;j++)
     {
     	if (sum2[1][j]>sum2[1][j+1])
     	  {
     	  	
		   	 a=sum2[1][j];
			 sum2[1][j]=sum2[1][j+1];
			 sum2[1][j+1]=a;
			 a=sum2[2][j];
			 sum2[2][j]=sum2[2][j+1];
			 sum2[2][j+1]=a;	 	
		  	 	
		  }
	 }  
	if (NUM!=0)
  	  for(i=0;i<NUM;i++)
	     printf(" %-8s|  %-2s  |  %-2d  |   %-6.2f    |     %-6.2f   |    %-6.2f    |    %-6.2f  |  %-6.2f  |  %-6.2f  |  %.0f \n",stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC,sum[i],ave[i],sum2[2][i]);
    
		printf("\n\n请输入任意键返回主菜单...\n");
		getchar();


}
 
