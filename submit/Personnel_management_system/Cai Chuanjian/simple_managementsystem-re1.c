/*simple_managementsystem.c——简易人员管理系统 1.0*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
#define MAXPER 200

struct staff                      //staff结构，关于人员信息
{
	char sgroup[MAX];             //组别
	char sname[MAX];              //姓名
	char smage[MAX];              //专业年级
	char stele[MAX];              //电话
	char sqq[MAX];                //qq
	char semail[MAX];             //邮箱
	char sno[MAX];                //学号
};
struct staff per[MAXPER];         //MAXPER为可容纳人员的最大数量，暂定为200

struct admin                      //admin结构，关于用户登录、密码
{
	char user[MAX];
	char keys[MAX];
}easy;
struct admin num[MAXPER];         //MAXPER为可容纳用户的最大数量，暂定为200

int Number=0;                     //全局变量，初始化人员信息数量为0
int usernumber;                   //全局变量，初始化用户数量为0


void Menu();                      //说明提示信息，对人员信息的各种操作

void bc(struct staff*per);       //保存
void bcs(struct admin *num) ;

void Back();                     //返回主菜单

int dq(struct staff per[]);      //读取
int dqs(struct admin num[]);


void Add();                     //增加新的人员信息，并存储

void Search();                  //查找任意一个人员的信息

void Putm();                    //查找的“分支”函数，通过姓名查找

void Putn();                    //查找的“分支”函数，通过学号查找

void Delete();                  //删除人员信息

void delm();                    //删除的“分支”函数，通过姓名删除

void deln();                    //删除的“分支”函数，通过学号删除

void View();                    //浏览（无序）

void Stsrt();                   //排序

void stsrtg();                  //按组别排序

void stsrtn();                  //按学号排序

void Help();                    //帮助

void headmenu();                //开头的用户登陆界面

void reg();                     //注册

void login();                   //登录


int main(void)
{
	usernumber=dqs(num);

    headmenu();

    int choose=0;
    FILE*fpb=NULL;
    FILE*fp=NULL;

    char yesorno;

    if((fpb=fopen("staff_b.txt","rb"))==NULL)
    {
    	printf("\n提示：文件不存在，是否要创建？(y/n)\n");
    	scanf("%c",&yesorno);
    	if(yesorno=='y'||yesorno=='Y')
    	{
    		fp=fopen("staff.txt","w");
    		fprintf(fp,"%s   %s    %s  %s           %s           %s                %s\n","组别","姓名","专业年级","电话","qq","邮箱","学号");
			fpb=fopen("staff_b.txt","wb");

    		fclose(fp);
    		fclose(fpb);
		}
		else
		exit(0);
	}
	else
	{
		Number=dq(per);
	}
	system("cls");

	while(1)
	{
		Menu();
		printf("请选择：");
		scanf("%d",&choose);
		system("cls");

		switch(choose)
		{
			case 1:
				Add();
				Back();
				break;

			case 2:
				Search();
				Back();
				break;

			case 3:
				Delete();
				Back();
				break;

			case 4:
			    View();
			    Back();
				break;

			case 5:
				Stsrt();
				Back();
				break;

            case 6:
            	Help();
            	Back();
            	break;

			case 0:
				printf("谢谢使用！\n");
				printf("（请按任意键退出程序）");
				exit(0);
				break;

			default:
				printf("错误！请按Enter键返回。\n");
				break;
		}
    	fflush(stdin);
    	getchar();
    	fflush(stdin);                                //解决删除第一个字符以外的问题
    	system("cls");
    }
    Menu();
    return 0;
}




void Menu()                                //菜单函数，用来提示用户进行操作
{
/*	printf("*******************************************************************\n");
    printf("*******************************************************************\n");
	printf("**************    欢迎来到人员信息管理系统      *******************\n");
	printf("		                                                           \n");
	printf("		                                                           \n");
	printf("		----	    主菜单:			----                           \n");
	printf("		~~~~		1.  添加		~~~~                           \n");
	printf("		----		2.  查询		----                           \n");
	printf("		~~~~		3.  删除		~~~~                           \n");
	printf("		----		4.  浏览		----                           \n");
	printf("		~~~~		5.  排序		~~~~                           \n");
	printf("        ----        6.  帮助        ----                           \n");
	printf("		~~~~		0.  退出		~~~~                           \n");
	printf("*******************************************************************\n");     有问题  */

	printf("*******************************************************************\n");
    printf("*******************************************************************\n");
	printf("**************    欢迎来到人员信息管理系统      *******************\n");
	printf("		                                                           \n");
	printf("		                                                           \n");
	printf("\t\t----\t 主菜单: \t----\n");
	printf("\t\t~~~~\t 1.  添加\t~~~~\n");
	printf("\t\t----\t 2.  查询\t----\n");
	printf("\t\t~~~~\t 3.  删除\t~~~~\n");
	printf("\t\t----\t 4.  浏览\t----\n");
	printf("\t\t~~~~\t 5.  排序\t~~~~\n");
	printf("\t\t----\t 6.  帮助\t----\n");
	printf("\t\t~~~~\t 0.  退出\t~~~~\n");
	printf("*******************************************************************\n");

}

void Add()
{
    int numberTemp=0;
	int i=0,j=0,count=0;
	struct staff temp;
	printf("请输入要添加的人员信息数量：");
	scanf("%d",&numberTemp);

	for(i=0;i<numberTemp;i++)
	{
		printf("请输入第%d个人员信息:\n",i+1);
		printf("组别：");
		scanf("%s",temp.sgroup);
		printf("姓名：");
		scanf("%s",temp.sname);
		printf("专业年级：");
		scanf("%s",temp.smage);
		printf("电话：");
		scanf("%s",temp.stele);
		printf("qq：");
		scanf("%s",temp.sqq);
		printf("邮箱：");
		scanf("%s",temp.semail);
		printf("学号：");
		scanf("%s",temp.sno);

		for(j=0;j<Number;j++)
		{
			if(strcmp(temp.sno,per[j].sno)==0)
			{
				count++;
			}
		}
		if(count==0)
		{
			per[Number++]=temp;
		    bc(&temp);
			printf("添加成功\n");
		}
		else
		printf("添加失败（该学号已存在）\n");
	}

}

void bc(struct staff*per)//保存
{
	FILE*fpb=NULL;
	fpb=fopen("staff_b.txt","ab+");
	fwrite(per,sizeof(struct staff),1,fpb);
	fclose(fpb);

	FILE*fp=NULL;
	fp=fopen("staff.txt","a+");
	fprintf(fp,"%s   %s  %s  %s    %s    %s    %s\n",per->sgroup, per->sname, per->smage, per->stele, per->sqq, per->semail, per->sno);
	fclose(fp);
}

void Back()//提示返回
{
	printf("按Enter键返回主菜单\n");
}

int dq(struct staff per[])//读取
{
	FILE*fpb=NULL;
	int i=0;
	fpb=fopen("staff_b.txt","rb");
	while(fread(&per[i],sizeof(struct staff),1,fpb))
	i++;
	fclose(fpb);
	return i;
}


void Search()//主菜单功能之二——查询
{
	int n;
	printf("查询方式如下：\n");
	printf("1-姓名\n");
	printf("2-学号\n");
	printf("3-返回\n");
	printf("请输入你要查询的方式：");
	scanf("%d",&n);

	system("cls");

	switch(n)
	{
		case 1:
			Putm();
			break;
		case 2:
			Putn();
			break;
		case 3:
			break;
		default:
			system("cls");
			printf("错误！请重新输入。\n");
			Search();
	}
}

void Putm()
{
	char name[MAX];
	int i=0;
	int count=0;
	printf("请输入要查找的人员姓名:");
	scanf("%s",name);

	system("cls");

	for(i=0;i<Number;i++)
	{
		if(strcmp(name,per[i].sname)==0)
		{
			printf("%s   %s    %s  %s           %s           %s                %s\n","组别","姓名","专业年级","电话","qq","邮箱","学号");
			printf("%s   %s  %s  %s    %s    %s    %s\n",per[i].sgroup, per[i].sname, per[i].smage, per[i].stele, per[i].sqq, per[i].semail, per[i].sno);
			count++;
		}
	}
	if(count==0)
	printf("对不起，该人员不存在！\n");
}

void Putn()
{
	char no[MAX];
	int i=0;
	int count=0;
	printf("请输入要查找的人员学号:");
	scanf("%s",no);

	system("cls");

	for(i=0;i<Number;i++)
	{
		if(strcmp(no,per[i].sno)==0)
		{
			printf("%s   %s    %s  %s           %s           %s                %s\n","组别","姓名","专业年级","电话","qq","邮箱","学号");
			printf("%s   %s  %s  %s    %s    %s    %s\n",per[i].sgroup, per[i].sname, per[i].smage, per[i].stele, per[i].sqq, per[i].semail, per[i].sno);
			count++;
		}
    }
	if(count==0)
	printf("对不起，该人员不存在！\n");
}

void Delete()//主菜单的功能之三——删除
{
	int n=0;
	printf("删除方式如下：\n");
	printf("1-姓名\n");
	printf("2-学号\n");
	printf("3-返回\n");
	printf("请输入你要删除的方式：");
	scanf("%d",&n);

	switch(n)
	{
		case 1:
			delm();
			break;
		case 2:
			deln();
			break;
		case 3:
			break;
		default:
			system("cls");
			printf("错误！请重新输入。\n");
			Delete();
	}
}

void delm()//删除的“分支”函数，通过姓名删除
{
	FILE*fp=NULL;
	FILE*fpb=NULL;
	char name[MAX];
	int i=0;
	int j=0;
	int count=0;
	printf("请输入要删除的人员的姓名：");
	scanf("%s",name);

/*	for(i=0;i<Number;i++)
	{
		if(strcmp(name,per[i].sname)==0)
		{
			printf("序号：%d  ",i);
			printf("%s   %s  %s  %s    %s    %s    %s\n",per[i].sgroup, per[i].sname, per[i].smage, per[i].stele, per[i].sqq, per[i].semail, per[i].sno);
		}
	}                       对于同名同姓问题待解决。。。   */

	for(i=0;i<Number;i++)
	{
		if(strcmp(name,per[i].sname)==0)
		{
			for(j=i;j<Number-1;j++)
	    	{
	   		    per[j]=per[j+1];
		   	}
		   	Number--;
			count++;
		}
	}
	if(count>0)
	{
		fpb=fopen("staff_b.txt","wb");
	    fp=fopen("staff.txt","w");
    	for(i=0;i<Number;i++)
    	{
    		fwrite(&per[i],sizeof(struct staff),1,fpb);
    		fprintf(fp,"%s   %s  %s  %s    %s    %s    %s\n",per[i].sgroup, per[i].sname, per[i].smage, per[i].stele, per[i].sqq, per[i].semail, per[i].sno);
    	}
    	fclose(fpb);
    	fclose(fp);
    	printf("删除成功\n");
	}
	else
	printf("对不起，该人员不存在！\n");

}

void deln()//删除的“分支”函数，通过学号删除
{
	FILE*fp=NULL;
	FILE*fpb=NULL;
	char no[MAX];
	int i=0;
	int j=0;
	int count=0;
	printf("请输入要删除的人员的学号：");
	scanf("%s",no);

	for(i=0;i<Number;i++)
	{
		if(strcmp(no,per[i].sno)==0)
		{
			for(j=i;j<Number-1;j++)
			{
				per[j]=per[j+1];
			}
			Number--;
			count++;
		}
	}
	if(count>0)
	{
		fpb=fopen("staff.txt","wb");
		fp=fopen("staff.txt","w");
    	for(i=0;i<Number;i++)
    	{
    		fwrite(&per[i],sizeof(struct staff),1,fpb);
    		fprintf(fp,"%s   %s    %s  %s           %s           %s                %s\n","组别","姓名","专业年级","电话","qq","邮箱","学号");
    	}
    	fclose(fpb);
    	fclose(fp);
    	printf("删除成功\n");
	}
	else
	printf("对不起，该人员不存在！\n");
}

void View()//主菜单功能之四——浏览（无序）
{
	int i=0;

	printf("以下是全部人员信息：\n");
	printf("%s   %s    %s  %s           %s           %s                %s\n","组别","姓名","专业年级","电话","qq","邮箱","学号");
	for(i=0;i<Number;i++)
	{
		printf("%s   %s  %s  %s    %s    %s    %s\n",per[i].sgroup, per[i].sname, per[i].smage, per[i].stele, per[i].sqq, per[i].semail, per[i].sno);
	}
}
void Stsrt()//主菜单功能之五——排序
{
	int n=0;
	printf("排列方式如下：\n");
	printf("1-组别\n");
	printf("2-学号\n");
	printf("3-返回\n");
	printf("请输入你要排列的方式：");
	scanf("%d",&n);

	switch(n)
	{
		case 1:
			stsrtg();//按组别排序
			break;
		case 2:
			stsrtn();//按学号排序
			break;
		case 3:
			break;
		default:
			system("cls");
			printf("错误！请重新输入。\n");
			Stsrt();
	}
}

void stsrtg()//排序的“分支”函数，按组别排序 //目前还有问题。。。
{
	int i,k;
	int top,seek;
	char *ptstr[MAXPER];
	char *temp;
	struct staff *eptstr[MAXPER];
	struct staff *etemp;

//	char atemp[]="100";
//	char btemp[]="101";
//	char ctemp[]="102";
//	char dtemp[]="103";

	FILE*fp=NULL;
	fp=fopen("sortg.txt","w");

	for(i=0;i<Number;i++)
	{
	   /* if(strcmp((per[i].sgroup),"电路")==0)
		{
		//	printf("%d",i);
		    ptstr[i]=atemp;
		  //  printf("%d",i);
		    eptstr[i]=&per[i];
		 //   printf("%d",i);
		}
	    if(strcmp((per[i].sgroup),"机械")==0)
		{
	   	    ptstr[i]=btemp;
	        eptstr[i]=&per[i];
		}
	    if(strcmp((per[i].sgroup),"嵌软")==0)
		{
	   	    ptstr[i]=ctemp;
	        eptstr[i]=&per[i];
		}

		if(strcmp((per[i].sgroup),"视觉")==0)
		{
			ptstr[i]=dtemp;
	    	eptstr[i]=&per[i];
		} */
		ptstr[i]=per[i].sgroup;
		eptstr[i]=&per[i];

	}

	//for(i=0;i<Number;i++)
	//printf("%s",ptstr[i]);

	for(top=0;top<Number-1;top++)
	   for(seek=top+1;seek<Number;seek++)
	      if(strcmp(ptstr[top],ptstr[seek])>0)
	      {
		    temp=ptstr[top];
            ptstr[top]=ptstr[seek];
            ptstr[seek]=temp;

	      	etemp=eptstr[top];
	      	eptstr[top]=eptstr[seek];
	      	eptstr[seek]=etemp;

		  }

	fprintf(fp,"%s   %s    %s  %s           %s           %s                %s\n","组别","姓名","专业年级","电话","qq","邮箱","学号");
	printf("%s   %s    %s  %s           %s           %s                %s\n","组别","姓名","专业年级","电话","qq","邮箱","学号");

    for(k=0;k<Number;k++)
    {
    	printf("%s   %s  %s  %s    %s    %s    %s\n",eptstr[k]->sgroup,eptstr[k]->sname,eptstr[k]->smage,eptstr[k]->stele,eptstr[k]->sqq,eptstr[k]->semail,eptstr[k]->sno);
    	fprintf(fp,"%s   %s  %s  %s    %s    %s    %s\n",eptstr[k]->sgroup,eptstr[k]->sname,eptstr[k]->smage,eptstr[k]->stele,eptstr[k]->sqq,eptstr[k]->semail,eptstr[k]->sno);
	}
	fclose(fp);
}

void stsrtn()//排序的“分支”函数，按学号排序
{
	int i,k;
	int top,seek;
	char *ptstr[MAXPER];
	char *temp;
	struct staff *eptstr[MAXPER];
	struct staff *etemp;

	FILE*fp=NULL;
	fp=fopen("sortn.txt","w");

	printf("%d",Number);

	for(i=0;i<Number;i++)
	{
		ptstr[i]=per[i].sno;
		eptstr[i]=&per[i];
	}
	for(top=0;top<Number-1;top++)
	   for(seek=top+1;seek<Number;seek++)
	      if(strcmp(ptstr[top],ptstr[seek])>0)//问题
	      {
            temp=ptstr[top];
            ptstr[top]=ptstr[seek];
            ptstr[seek]=temp;

	      	etemp=eptstr[top];
	      	eptstr[top]=eptstr[seek];
	      	eptstr[seek]=etemp;
		  }

	fprintf(fp,"%s   %s    %s  %s           %s           %s                %s\n","组别","姓名","专业年级","电话","qq","邮箱","学号");
    printf("%s   %s    %s  %s           %s           %s                %s\n","组别","姓名","专业年级","电话","qq","邮箱","学号");

    for(k=0;k<Number;k++)
    {
    	printf("%s   %s  %s  %s    %s    %s    %s\n",eptstr[k]->sgroup,eptstr[k]->sname,eptstr[k]->smage,eptstr[k]->stele,eptstr[k]->sqq,eptstr[k]->semail,eptstr[k]->sno);
    	fprintf(fp,"%s   %s  %s  %s    %s    %s    %s\n",eptstr[k]->sgroup,eptstr[k]->sname,eptstr[k]->smage,eptstr[k]->stele,eptstr[k]->sqq,eptstr[k]->semail,eptstr[k]->sno);
	}
	fclose(fp);

}



void Help()//主菜单功能之六——帮助
{
	printf("注：\n");
	printf("1.选择输入序号即可；\n");
	printf("2.“添加”即添加人员，将某个新增人员信息录入；\n");
	printf("3.“查询”即检索人员信息；\n");
	printf("4.“删除”即删除某个人员信息；\n");
	printf("5.“浏览”即无序浏览全部人员信息；\n");
	printf("6.“排序”即将全部人员信息按一定顺序显示；\n");
}

void headmenu()
{
	int join;
	printf("欢迎来到人员管理系统登录页面\n\n");
	printf("1-注册；\n2-登录；\n3-退出\n");
	scanf("%d",&join);
	system("cls");


	switch(join)
	{
		case 1:
			reg();
			break;
		case 2:
			login();
			break;
		case 3:
			printf("谢谢使用！\n");
			exit(0);
		default:
			printf("错误！请重新输入。\n");
			headmenu();
	}
	fflush(stdin);

}

void reg()//注册 //缺点：存在长度限制
{
	int i=0;
	int count=0;

	printf("[Register...]\n");
	printf("（注意用户名和密码长度均不得超过20个字符）\n\n");
	printf("用户名：");
	scanf("%s",easy.user);
	printf("密码：");
	scanf("%s",easy.keys);

	for(i=0;i<usernumber;i++)
	{
		if(strcmp(easy.user,num[i].user)==0)
		count++;
	}
	if(count==0)
	{
		num[usernumber++]=easy;
	    bcs(&easy);

		system("cls");
		printf("注册成功\n\n");
		headmenu();
	}
	else
	{
		system("cls");
		printf("用户名\"%s\"已存在，请重新注册!\n\n",easy.user);
		reg();
	}
}

int dqs(struct admin num[])//读取
{
	FILE*fpb=NULL;
	int i=0;
	fpb=fopen("user_b.txt","a+b");
	while(fread(&num[i],sizeof(struct admin),1,fpb))
	i++;
	fclose(fpb);
	return i;
}

void bcs(struct admin*num)//保存
{
	FILE*fpb=NULL;
	fpb=fopen("user_b.txt","a+b");
	fwrite(num,sizeof(struct admin),1,fpb);
	fclose(fpb);

	FILE*fp=NULL;
	fp=fopen("user.txt","a+");
	fprintf(fp,"%s   %s  \n",num->user, num->keys);
	fclose(fp);
}

void login()//登录 //缺点：不能随意返回；还存在长度限制
{
	char userp[MAX];
	char keysp[MAX];
	int count=0;
	int i;
    printf("[Login...]\n\n");
	while(1)
	{
	    printf("用户名：");
	    scanf("%s",userp);
     	printf("密码：");
    	scanf("%s",keysp);

		for(i=0;i<usernumber;i++)
		{
			if(strcmp(num[i].user,userp)==0&&strcmp(num[i].keys,keysp)==0)
			count++;
		}
		if(count==1)
		break;
		else
		printf("用户名或密码错误，请重新输入：\n");
	}

}

