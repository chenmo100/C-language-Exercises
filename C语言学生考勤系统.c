#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
struct record
{   int year;
    int month;
	int day;
	int course;
	char COURSE[20];
	char name[20];
	char form[20];
}stu[300],stu1[300],stu3[300],stu4[300];
struct time
{   char name[20];
    int times;
}list[300];
struct 
{   char COURSE[20];
    int times;
}list2[300];
void start();
void input();
void change();
void search();
void statistic1();
void statistic2();
void menu();
void menu2();
void main()
{    
     printf("\n");
	 printf("\n");
	 printf("\n");
	 printf("\n");
     printf("##########################\n");
	 printf("#       学生考勤系统     #\n");
	 printf("#         欢迎您         #\n");
	 printf("##########################\n");
     printf("\n");
	 printf("\n");
	 printf("\n");
	 printf("\n");
	 start();
}
void start()
{
     int x;
	 menu();
	 scanf("%d",&x);
     fflush(stdin);
	 switch(x)
	 {
	 case 1:system("cls");input();break;
	 case 2:system("cls");search();break;
	 case 3:system("cls");change();break;
	 case 4:system("cls");statistic1();break;
     case 5:system("cls");statistic2();break;
	 case 6:break;
     default:printf("输入有误,请重输。\n");system("cls");start();
	 }
}
void input()
{  int i,c=0;
   char n;
   FILE *fp;
   printf("###########缺课记录录入##########\n");
   for(i=0;i<100;i++)
   {printf("请输入学生姓名:\n");
    gets(stu[i].name);
	printf("请输入缺课日期:\n");
	scanf("%d,%d,%d",&stu[i].year,&stu[i].month,&stu[i].day);
    fflush(stdin);
	printf("请输入课程名称:\n");
	gets(stu[i].COURSE);
	printf("请输入是第几节课\n");
	scanf("%d",&stu[i].course);
    fflush(stdin);
    printf("请输入缺课类型:\n");
	gets(stu[i].form);
    printf("请输入'Y'或'N':\n");
	scanf("%c",&n);
	c++;
	if(n=='N'||n=='n')break;
    fflush(stdin);
   }
   fp=fopen("cm.txt","ab+");//文件打开
   for(i=0;i<c;i++)//文件写入
   {
      fwrite(&stu[i],sizeof(struct record),1,fp);
   }
   fclose(fp);
   start();
}		
void search()
{  int i=0;
   char student[20]; 
   FILE *out;
   out=fopen("cm.txt","rb");
   if(out==NULL)
   printf("\n====>不能打开文件!\n");
   for(i=0;feof(out)==0;i++)
   {
	   fread(&stu1[i],sizeof(struct record),1,out);
   }
   fclose(out);
   printf("###########缺课记录查询##########\n");
   printf("请输入要查询学生的姓名:\n");
   gets(student);
   for(i=0;i<300;i++)
   {
	   if(strcmp(student,stu1[i].name)==0)
       {printf("姓名:%s\n",stu1[i].name);
	    printf("缺课日期:%d,%d,%d\n",stu1[i].year,stu1[i].month,stu1[i].day);
		printf("课程名称:%s,第几节课:%d\n",stu1[i].COURSE,stu1[i].course);
		printf("缺课类型:%s\n",stu1[i].form);
		break;
	   }
   }
   if(i==300)
   printf("无要查询学生的记录");
   start();
}
void change()
{  int i=0,num=0;
   char student[20]; 
   FILE *out;
   out=fopen("cm.txt","rb");
   if(out==NULL)
   printf("\n====>不能打开文件!\n");
   for(i=0;feof(out)==0;i++)
   {
	   fread(&stu1[i],sizeof(struct record),1,out);
	   num++;
   }
   fclose(out);
   printf("###########缺课记录修改##########\n");
   printf("请输入要修改学生的姓名:\n");
   gets(student);
   for(i=0;i<300;i++)
   {
	   if(strcmp(student,stu1[i].name)==0)
       {
		   menu2(i);break;
		}
   }
   system("cls");
   if(i==300)
   printf("无要修改学生的记录");
   else 
   {
	out=fopen("cm.txt","wb");//文件打开
    for(i=0;i<num;i++)//文件写入
   {
    fwrite(&stu1[i],sizeof(struct record),1,out);
   }
    fclose(out);//文件关闭
   }
   start();
}						
void statistic1()//统计旷课学生姓名和旷课次数,人数由多到少排序
{  
   int i=0,j=0,num=0,n=0,m=0,c=0,e=0;
   int year[2],month[2],day[2];
   FILE *out;
   out=fopen("cm.txt","rb");
   if(out==NULL)
   printf("\n====>不能打开文件!\n");
   for(i=0;feof(out)==0;i++)
   {
	   fread(&stu1[i],sizeof(struct record),1,out);
	   num++;
   }
   fclose(out);
   printf("请输入要统计的时间段:\n");
   printf("前范围:");
   scanf("%d,%d,%d",&year[0],&month[0],&day[0]);
   printf("\n后范围:");
   scanf("%d,%d,%d",&year[1],&month[1],&day[1]);
   for(i=0;i<num;i++)
   { if(stu1[i].year>year[0]&&stu1[i].year<year[1])
   {  
	   strcpy(stu3[n].name,stu1[i].name);
       strcpy(stu3[n].COURSE,stu1[i].COURSE);
	   stu3[n].course=stu1[i].course;
	   stu3[n].day=stu1[i].day;
	   strcpy(stu3[n].form,stu1[i].form);
	   stu3[n].month=stu1[i].month;
	   stu3[n].year=stu1[i].year;
	   n++;
   }
   if(stu1[i].year==year[0])
   {   if(stu[i].month>month[0]&&stu[i].month<month[1])
   {   
	   strcpy(stu3[n].name,stu1[i].name);
       strcpy(stu3[n].COURSE,stu1[i].COURSE);
	   stu3[n].course=stu1[i].course;
	   stu3[n].day=stu1[i].day;
	   strcpy(stu3[n].form,stu1[i].form);
	   stu3[n].month=stu1[i].month;
	   stu3[n].year=stu1[i].year;
	   n++;
   }
       if(stu[i].month==month[0])
	   {   if(stu[i].day>=day[0]&&stu[i].day<=day[1])
	   {       
	   strcpy(stu3[n].name,stu1[i].name);
       strcpy(stu3[n].COURSE,stu1[i].COURSE);
	   stu3[n].course=stu1[i].course;
	   stu3[n].day=stu1[i].day;
	   strcpy(stu3[n].form,stu1[i].form);
	   stu3[n].month=stu1[i].month;
	   stu3[n].year=stu1[i].year;
	   n++;
	   }
	   }
   }
   if(stu1[i].year==year[1])
   {  
	   if(stu[i].month>month[0]&&stu[i].month<month[1])
   {   
	   strcpy(stu3[n].name,stu1[i].name);
       strcpy(stu3[n].COURSE,stu1[i].COURSE);
	   stu3[n].course=stu1[i].course;
	   stu3[n].day=stu1[i].day;
	   strcpy(stu3[n].form,stu1[i].form);
	   stu3[n].month=stu1[i].month;
	   stu3[n].year=stu1[i].year;
	   n++;
   }
       if(stu[i].month==month[1])
	{   
	   if(stu[i].day>=day[0]&&stu[i].day<=day[1])
	{       
	   strcpy(stu3[n].name,stu1[i].name);
       strcpy(stu3[n].COURSE,stu1[i].COURSE);
	   stu3[n].course=stu1[i].course;
	   stu3[n].day=stu1[i].day;
	   strcpy(stu3[n].form,stu1[i].form);
	   stu3[n].month=stu1[i].month;
	   stu3[n].year=stu1[i].year;
	   n++;
	   }
	   }
   }
}

	 for(i=0;i<300;i++)
     {  
		 list[i].times=0;
	 }
	  for(i=0;i<n;i++)
	  { m=0;
	   for(j=i-1;0<=j;j--)
     {  
		  if(strcmp(stu3[i].name,stu3[j].name)==0)
		  break;
		  else m++;
	 }
           if(i==m)
		  {
			   printf("%s",stu3[i].name);
			   strcpy(list[c].name,stu3[i].name);
		       c++;
		   }
		 for(e=0;e<c;e++)
		 {  
			if(strcmp(stu3[i].name,list[e].name)==0)
			{list[e].times++;break;}
		 }
	
	}



    //  printf("\n%d\n",c);
      for(i=0;i<c;i++)
	 { 
		  printf("姓名是%s,旷课次数是%d\n",list[i].name,list[i].times);
	 }
      
}
void statistic2()//有学生旷课的课程和旷课人数，人数由多到少排序
{
   int i=0,j=0,num=0,n=0,m=0,c=0,e=0;
   int year[2],month[2],day[2];
   FILE *out;
   out=fopen("cm.txt","rb");
   if(out==NULL)
   printf("\n====>不能打开文件!\n");
   for(i=0;feof(out)==0;i++)
   {
	   fread(&stu1[i],sizeof(struct record),1,out);
	   num++;
   }
   fclose(out);
   printf("请输入要统计的时间段:\n");
   printf("前范围:");
   scanf("%d,%d,%d",&year[0],&month[0],&day[0]);
   printf("\n后范围:");
   scanf("%d,%d,%d",&year[1],&month[1],&day[1]);
   for(i=0;i<num;i++)
   { if(stu1[i].year>year[0]&&stu1[i].year<year[1])
   {  
	   strcpy(stu4[n].name,stu1[i].name);
       strcpy(stu4[n].COURSE,stu1[i].COURSE);
	   stu4[n].course=stu1[i].course;
	   stu4[n].day=stu1[i].day;
	   strcpy(stu4[n].form,stu1[i].form);
	   stu4[n].month=stu1[i].month;
	   stu4[n].year=stu1[i].year;
	   n++;
   }
   if(stu1[i].year==year[0])
   {   if(stu[i].month>month[0]&&stu[i].month<month[1])
   {   
	   strcpy(stu4[n].name,stu1[i].name);
       strcpy(stu4[n].COURSE,stu1[i].COURSE);
	   stu4[n].course=stu1[i].course;
	   stu4[n].day=stu1[i].day;
	   strcpy(stu4[n].form,stu1[i].form);
	   stu4[n].month=stu1[i].month;
	   stu4[n].year=stu1[i].year;
	   n++;
   }
       if(stu[i].month==month[0])
	   {   if(stu[i].day>=day[0]&&stu[i].day<=day[1])
	   {       
	   strcpy(stu4[n].name,stu1[i].name);
       strcpy(stu4[n].COURSE,stu1[i].COURSE);
	   stu4[n].course=stu1[i].course;
	   stu4[n].day=stu1[i].day;
	   strcpy(stu4[n].form,stu1[i].form);
	   stu4[n].month=stu1[i].month;
	   stu4[n].year=stu1[i].year;
	   n++;
	   }
	   }
   }
   if(stu1[i].year==year[1])
   {  
	   if(stu[i].month>month[0]&&stu[i].month<month[1])
   {   
	   strcpy(stu4[n].name,stu1[i].name);
       strcpy(stu4[n].COURSE,stu1[i].COURSE);
	   stu4[n].course=stu1[i].course;
	   stu4[n].day=stu1[i].day;
	   strcpy(stu4[n].form,stu1[i].form);
	   stu4[n].month=stu1[i].month;
	   stu4[n].year=stu1[i].year;
	   n++;
   }
       if(stu[i].month==month[1])
	{   
	   if(stu[i].day>=day[0]&&stu[i].day<=day[1])
	{       
	   strcpy(stu4[n].name,stu1[i].name);
       strcpy(stu4[n].COURSE,stu1[i].COURSE);
	   stu4[n].course=stu1[i].course;
	   stu4[n].day=stu1[i].day;
	   strcpy(stu4[n].form,stu1[i].form);
	   stu4[n].month=stu1[i].month;
	   stu4[n].year=stu1[i].year;
	   n++;
	   }
	   }
   }
}

	 for(i=0;i<300;i++)
     {  
		 list2[i].times=0;
	 }
	  for(i=0;i<n;i++)
	  { m=0;
	   for(j=i-1;0<=j;j--)
     {  
		  if(strcmp(stu4[i].COURSE,stu4[j].COURSE)==0)
		  break;
		  else m++;
	 }
           if(i==m)
		  {
			   printf("%s",stu4[i].COURSE);
			   strcpy(list2[c].COURSE,stu4[i].COURSE);
		       c++;
		   }
		 for(e=0;e<c;e++)
		 {  
			if(strcmp(stu4[i].COURSE,list2[e].COURSE)==0)
			{list2[e].times++;break;}
		 }
	
	}



    //  printf("\n%d\n",c);
      for(i=0;i<c;i++)
	 { 
		  printf("课程是%s,旷课人数是%d\n",list2[i].COURSE,list2[i].times);
	 }
      
}
void menu()
{    
     printf("################################\n");
	 printf("# 请选择所需功能，输入对应数字 #\n");
 	 printf("#     1.输入缺课记录           #\n");
	 printf("#     2.查找缺课记录           #\n");
	 printf("#     3.修改缺课记录           #\n");
	 printf("#     4.统计缺课记录           #\n");
	 printf("#     5.统计缺课记录           #\n");
	 printf("#     6.退出                   #\n");
 	 printf("################################\n");
}
void menu2(int i)
{       int x;
	    printf("请选择要修改的信息\n");
        printf("################################\n");
	    printf("# 请选择所需功能，输入对应数字 #\n");
 	    printf("#     1.学生姓名               #\n");
	    printf("#     2.缺课日期               #\n");
	    printf("#     3.课程名称               #\n");
	    printf("#     4.第几节课               #\n");
	    printf("#     5.缺课情况               #\n");
	    printf("#     6.退出                   #\n");
 	    printf("################################\n");
		scanf("%d",&x);
		fflush(stdin);
	    switch(x)
	{
		case 1: scanf("%s",stu1[i].name);fflush(stdin);system("cls");menu2();break;
		case 2: scanf("%d,%d,%d",&stu1[i].year,&stu1[i].month,&stu1[i].day);fflush(stdin);system("cls");menu2();break;
		case 3: scanf("%s",stu1[i].COURSE);fflush(stdin);system("cls");menu2();break;
		case 4: scanf("%d",&stu1[i].course);fflush(stdin);system("cls");menu2();break;
		case 5: scanf("%s",stu1[i].form);fflush(stdin);system("cls");menu2();break;
        case 6: break;
	}
}
