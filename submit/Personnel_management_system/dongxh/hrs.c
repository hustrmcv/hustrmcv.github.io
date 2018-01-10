
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



#define GROUP 10
#define NAME 10
#define MAJOR 10
#define GRADE 5
#define PHONENUM 15
#define QQ 15
#define EMAIL 45
#define IDNUM 11


///团队管理信息.txt
///用户信息.txt


struct student
{
    char group[GROUP];//组别
    char name[NAME];//姓名
    char major[MAJOR];//专业
    char grade[GRADE];     //年级
    char phonenum[PHONENUM];//电话
    char qq[QQ];     //QQ号
    char email[EMAIL];//电子邮件
    char IDnum[IDNUM];//学号
    struct student *next;

} ;

struct zhanghu
{
    char name[NAME];
    char username[17];//登陆用户名，不得超过16个字符
    char password[17];//登陆密码，不能超过16个字符
    struct zhanghu *next;
};
//typedef struct student member;
//typedef struct zhanghu sighininformation
struct student *headone=NULL;
struct zhanghu *headtwo=NULL;


void administrator();   ///管理员权限菜单 done
void adsighin();        ///管理员权限登录 done
void adlogin();         ///管理员权限注册 done
void admanu();          ///管理员功能菜单界面
void adcheckall();      ///done
void adgroup();         ///done
void adgrade();         ///done
void adsearch();        ///done
void adadd();           ///done
void adchange();

void loadusername_password();///将文件里保存的username和password以链表的结构形式存到内存中 done
void loadusersxinxi();   ///将文件里的数据以链表的结构形式存到内存中 done
void freelinkedlist();   ///释放链表
void clear();            ///clear screen done
int dup_check(char *filename,char *str);///duplicate check,if duplicates then return 0,if doesn't then return 1 done


void noncheckall();       ///非管理员权限查看所有成员信息 done
void non_administrator();///非管理员菜单 done
char *s_gets();          ///输入字符串辅助函数，目的是.....待定 done
void sighin();           ///签到页面=========







int main()
{
    //typedef struct student STUDENT;
    //typedef struct zhanghu ZHANGHU;
    int choiceone;
    printf("**欢迎使用董学辉的人员管理系统...\n");
    getchar();

        printf("**通过以下哪种形式进入:\n");
        printf("**1.管理员权限\n");
        printf("**2.非管理员权限\n");
        printf("**3.签到\n");
        printf("**4.退出程序\n");

    while(scanf("%d",&choiceone)==1)
    {

        switch(choiceone)
        {
        case 1:
            clear();
            administrator();
            break;
        case 2:
            clear();
            non_administrator();
            break;
        case 3:
            clear();
            sighin();
            break;
        case 4:
            printf("感谢使用\n");
            printf("any key to exit...");
            getchar();
            exit(0);

        }

        printf("**通过以下哪种形式进入:\n");
        printf("**1.管理员权限\n");
        printf("**2.非管理员权限\n");
        printf("**3.签到\n");
        printf("**4.退出程序\n");

    }

    return 0;
}



void clear()
{
    system("cls");
}



void loadusersxinxi()
{
    ///STUDENT *head=NULL;
    struct student *current;
    struct student *prev;
    FILE * fileprt=NULL;
    if((fileprt=fopen("团队管理信息.txt","r"))==NULL)
    {
        printf("载入人员信息出错...\n");
        printf("any key to exit...");
        getchar();
        exit(1);
    }
    while(!feof(fileprt))                                                ///   #define GRADE 5
        {
            current=(struct student*)malloc(sizeof(struct student));     ///   #define GROUP 10
            if(headone==NULL)                                               ///   #define NAME 10
                  headone=current;
                                                            ///   #define MAJOR 10
            else                                                         ///   #define PHONENUM 15
                prev->next=current;                                      ///   #define QQ 15
            current->next=NULL;                                          ///   #define EMAIL 45
                                                                         ///   #define IDNUM 11
            fscanf(fileprt,"%10s%10s%10s%4s%14s%14s%44s%10s",current->group,current->name,current->major,current->grade,current->phonenum,current->qq,
                   current->email,current->IDnum);
             prev=current;
        }
        fclose(fileprt);
}





void loadusername_password()
{
    struct zhanghu *current;
    struct zhanghu *prev;
    FILE *fileprt=NULL;
    if((fileprt=fopen("用户信息.txt","r"))==NULL)
    {
        printf("载入用户信息出错...\n");
        printf("any key to exit...");
        getchar();
        exit(1);
    }
    while(!feof(fileprt))
        {
            current=(struct zhanghu *)malloc(sizeof(struct zhanghu));
            if (headtwo==NULL)
                headtwo=current;
            else
                prev->next=current;
            current->next=NULL;
            fscanf(fileprt,"%10s%16s%16s",current->name,current->username,current->password);
            prev=current;


        }
    fclose(fileprt);

}





 int dup_check(char *filename,char *str)
 {
     if(filename=="团队管理信息.txt")
     {
         struct student *current;
         struct student *prev;
         int count =0;
         loadusersxinxi();
         current=headone;
         do{
                if(strcmp(str,current->IDnum)==0||strcmp(str,current->email)==0||strcmp(str,current->phonenum)==0||strcmp(str,current->qq))
                {
                    count++;
                }
                current=current->next;

           }while(current!=NULL);
          if(count!=0)
           {
                printf("你输入的信息中有部分重复，请重新输入\n");
                return 0;
           }else return 1;

     }

     else if(filename=="用户信息.txt")
     {
         struct zhanghu *current;
        // struct zhanghu *prev;
         int count =0;
         //printf("1111");
         loadusername_password();
         //
         current=headtwo;
         do{
                if(strcmp(str,current->username)==0)
                {
                    count++;
                }
                current=current->next;
           }while(current!=NULL);
          if(count!=0)
           {
                //printf("用户名重复，请重新输入\n");
                return 0;
           }else return 1;

     }
     else printf("未找到相应文件\n");
     return 0;
 }



 void non_administrator()
{
    int choicetwo;
    printf("======================================\n");
    printf("已进入非管理员权限，你可以进行如下操作\n");
    printf("1.查看团队全部人员信息\n");
    printf("2.返回上一层\n");
    printf("......\n");
    while(scanf("%d",&choicetwo)==1)
    {

        switch(choicetwo)
        {
            case 1:
                noncheckall();
                break;
            case 2:
                clear();
                return;
                break;
            default:
                printf("错误操作...\n");
                break;

        }
            getchar();
            clear();
            printf("======================================\n");
            printf("已进入非管理员权限，你可以进行如下操作\n");
            printf("1.查看团队全部人员信息\n");
            printf("2.返回上一层\n");
            printf("......\n");
            //freelinkedlist();
    }
}








void administrator()
{
    int choicetwo;
    printf("======================================\n");
    printf("1.登陆\n");
    printf("2.注册\n");
    printf("3.返回上一步\n");
    printf("......\n");
    while(scanf("%d",&choicetwo)==1)
    {

        switch(choicetwo)
        {
            case 1:
                clear();
                adsighin();
                break;
            case 2:
                clear();
                adlogin();
                break;
            case 3:
                return;
            default:
                printf("错误操作...\n");
                break;

        }
            printf("======================================\n");
            printf("1.登陆\n");
            printf("2.注册\n");
            printf("3.返回上一步\n");
            printf("......\n");
    }

}





void admanu()
{
    int choice=0;
    printf("1.查看团队全部人员信息\n");
    printf("2.按组别分类查看人员信息\n");
    printf("3.按年级分类查看人员信息\n");
    printf("4.添加人员\n");
    printf("5.查询人员\n");
    printf("6.改动人员信息\n");
    printf("7.退出系统\n");
    scanf("%d",&choice);
    while(choice)
    {
        switch(choice)
        {
        case 1:
            adcheckall();
            break;
        case 2:
            adgroup();
            break;
        case 3:
            adgrade();
            break;
        case 4:
            adadd();
            break;
        case 5:
            adsearch();
            break;
        case 6:
            adchange();
            break;
        case 7:
            printf("感谢使用...\n");
            printf("any key to exit...");
            getchar();
            exit(0);
            break;
        default:
            printf("错误操作...\n");
            break;

        }
        system("pause");

        clear();
            printf("1.查看团队全部人员信息\n");
            printf("2.按组别分类查看人员信息\n");
            printf("3.按年级分类查看人员信息\n");
            printf("4.添加人员\n");
            printf("5.查询人员\n");
            printf("6.人员信息改动\n");
            printf("7.退出系统\n");
            scanf("%d",&choice);
    }
   // freelinkedlist();
}

void adlogin()
{
    //char username[17];
   // int count=0;
    //char *prt;
    char tempusername[17];
    char temppassword[17];
    char tempname[10];
    //struct zhanghu *current=NULL;
    //struct zhanghu *prev=NULL;
    FILE *fileprt=NULL;
    printf("请输入用户名：");
    scanf("%s",tempusername);
    while(dup_check("用户信息.txt",tempusername)==0)
        {
            printf("该用户名已被使用，请输入新的用户名：");
            scanf("%s",tempusername);
        }
    //loadusername_password();///运行完这个函数后，headtwo指向了第一个动态内存块
    //while(s_gets(username,17)!=NULL && input[0]!='\0')
    //while(current!=NULL)
    //{
    //   if(current==NULL)
    //        current=headtwo;
    //    else
    //    {
    //        prev->next=current;
    //
    //    }
    //    current=current->next;
    //}
    /////这个循环体完了后，current是最后一个结点的next指针，prev->next是指向最后一个结点
    //current=(struct zhanghu*)malloc(sizeof(struct zhanghu));
    do{
    printf("请输入您的密码(不得低于6位且不得多于16位)\n");
    scanf("%s",temppassword);
    }while(strlen(temppassword)>16&&strlen(temppassword)<6);
    printf("请输出您的姓名：");
    scanf("%s",tempname);
    printf("注册成功\n");
    fileprt= fopen("用户信息.txt", "a+");
    fprintf(fileprt,"%-10s%-16s%-16s\n",tempname,tempusername,temppassword);
    fclose(fileprt);






}







void adsighin()
{
    char tempusername[17];
    char temppassword[17];
    FILE *fileprt=NULL;
    struct zhanghu *current=NULL;
    struct zhanghu *prev;
    printf("username:");
    scanf("%s",tempusername);
    ///此处添加用户名,以及查找对应的signin_information结构体
    while(dup_check("用户信息.txt",tempusername)!=0)
        {
            printf("未找到该用户名，请重新输入\n");
            printf("username:");
            scanf("%s",tempusername);
        }

    //printf("password:")；
    //此处添加密码输入，以及核对密码是否正确，
    //scanf("%s",temppassword);
    //loadusername_password();///运行完这个函数后，headtwo指向了第一个动态内存块
    //while(s_gets(username,17)!=NULL && input[0]!='\0')
   // printf("1111\n");
   do
    {
       if(current==NULL)
            current=headtwo;
        else
        {
            prev->next=current;
            current=current->next;
       }

    }while(strcmp(current->username,tempusername)!=0);
    //这个循环体完了后，current是最后一个结点的next指针，prev->next是指向最后一个结点

    printf("password:");

    scanf("%s\n",temppassword);
    while(strcmp(current->password,temppassword)!=0)
    {
        //printf("current->password=%s",current->password);
        printf("密码错误，请重新输入\n");
        printf("password:");
        scanf("%s\n",temppassword);
    }

    //system("pause");
    //clear();
    admanu();



}









void noncheckall()
{
    struct student*current;
    struct student*prev;
    loadusersxinxi();
    for(current=headone;current!=NULL;current=current->next)
    {
        printf("%-10s%-10s%-10s%-4s%\n",current->group,current->name,current->major,current->grade);
    }
    printf("\n以上就是全部成员的部分信息...any key to exit\n");
    getchar();
    getchar();

}


void adcheckall()
{
    FILE *fp;
    char ch;
    fp =fopen("团队管理信息.txt","r");
    while((ch = fgetc(fp))!=  EOF)
    {
        putchar(ch);
    }
    fclose(fp);
    printf("\n以上就是全部成员的全部信息...any key to exit\n");
    getchar();

}

//#define GROUP 10
//#define NAME 10
//#define MAJOR 10
//#define GRADE 5
//#define PHONENUM 15
//#define QQ 15
//#define EMAIL 45
//#define IDNUM 11

void adgroup()
{
        char tempgroup[10];
        struct student*current;
        loadusersxinxi();
        printf("输入您要查看的组别('视觉','电路','机械','嵌软','运营')\n");
        while(scanf("%9s", tempgroup)==1&&tempgroup[0]!='\0')
        {

            int i=0,count=0;
            printf("%-10s%-10s%-10s%-5s%-15s%-15s%-45s%-11\n", "GROUP","NAME","MAJOR","GRADE","PHONENUM", "QQ","EMAIL","IDNUM");
            for(current=headone;current!=NULL;current=current->next)
            {

                if( strcmp( current->group,tempgroup)==0 )
                {
                    ++count;
                    printf("%-10s%-10s%-10s%-5s%-15s%-15s%-45s%-11\n",current->group,current->name,current->major,current->grade,current->phonenum
                           ,current->qq,current->email,current->IDnum);
                }

            }
            if ( count == 0 )
            {
                printf("该组信息为空\n");
            }
            else  printf("这是%s组的人员信息名单\n",*tempgroup);
        }
        printf("继续输入想要查看的组别，按回车键退出...\n");
}

void adgrade()
{
        char tempgrade[10];
        struct student*current;
        loadusersxinxi();
        printf("输入您要查看的年级(eg.'2017','2016')\n");
        while(scanf("%5s", tempgrade)==1&&tempgrade[0]!='\0')
        {

            int i=0,count=0;
            printf("%-10s%-10s%-10s%-5s%-15s%-15s%-45s%-11\n", "GROUP","NAME","MAJOR","GRADE","PHONENUM", "QQ","EMAIL","IDNUM");
            for(current=headone;current!=NULL;current=current->next)
            {

                if( strcmp( current->grade,tempgrade)==0 )
                {
                    ++count;
                    printf("%-10s%-10s%-10s%-5s%-15s%-15s%-45s%-11\n",current->group,current->name,current->major,current->grade,current->phonenum
                           ,current->qq,current->email,current->IDnum);
                }

            }
            if ( count == 0 )
            {
                printf("该年级信息为空\n");
            }
            else printf("这是%s级的人员名单", *tempgrade);
            printf("继续输入想要查看的年级，按回车键退出...\n");
        }

}


void adadd()
{
    FILE *fileprt;
    struct student *current;
    char tempgroup[GROUP];
    char tempname[NAME];
    char tempmajor[MAJOR];
    char tempgrade[GRADE];
    char tempphonenum[PHONENUM];
    char tempqq[QQ];
    char tempemail[EMAIL];
    char tempIDnum[IDNUM];

    printf("你可以添加一个同学信息\n");
    fileprt = fopen( "团队管理信息.txt ", "a+" );
            printf("请输入成员的组别 （电路，机械，视觉，嵌软，运营）.\n");
            scanf("%s",tempgroup);
            fprintf(fileprt,"%10s", tempgroup );
            printf("请输入成员的名字\n ");
            scanf("%s",tempname);
            fprintf(fileprt, "%10s",tempname);
            printf("请输入成员的专业\n ");
            scanf("%s",tempmajor);
            fprintf(fileprt, "%10s", tempmajor );
            printf("请输入成员的年级\n");
            scanf("%s",tempgrade);
            fprintf(fileprt, "%5s", tempgrade);
            printf("请输入成员的电话\n ");
            scanf("%s",tempphonenum);
            fprintf(fileprt, "%15s", tempphonenum );
            printf("请输入成员的QQ .\n ");
            scanf("%s",tempqq);
            fprintf(fileprt, "%15s", tempqq );
            printf("请输入成员的邮箱\n ");
            scanf("%s",tempemail);
            fprintf(fileprt, "%45s", tempemail );
            printf("请输入成员的学号\n ");
            scanf("%s",tempIDnum);
            fprintf(fileprt, "%11s\n",tempIDnum );


            fclose( fileprt );
            printf("添加成功!\n");
            system("pause");
            clear();
}



void adsearch()
{
    char keyword[45];
    struct student*current;
    int count=0;
    //struct student*prev=NULL;
    loadusersxinxi();
    printf("请输入你要搜索的人员的部分信息(为精准搜索，仅限姓名，学号，手机号，qq，邮箱):");
    scanf("%s",keyword);
    current=headone;
    for(current=headone;current!=NULL;current=current->next)
    {
        if(strcmp(keyword,current->email)==0||strcmp(keyword,current->IDnum)==0||strcmp(keyword,current->name)==0||
           strcmp(keyword,current->phonenum)==0||strcmp(keyword,current->qq)==0)
           {
                printf("%-10s%-10s%-10s%-5s%-15s%-15s%-45s%-11\n",current->group,current->name,current->major,current->grade,current->phonenum
                           ,current->qq,current->email,current->IDnum);
                count++;
           }
    }
    if(count==0)    printf("未找到您输入的信息\n");
        else printf("以上就是你要搜素的内容\n");
        system("pause");

}


void adchange()
{
    FILE * fileprt=NULL;
    struct student*current;
    struct student*prev;
    char search[11];
    int choice=0;
    loadusersxinxi();
        printf("请输入你想进行的操作：\n");
        printf("1.修改信息\n");
        printf("2.删除人员\n");
        scanf("%d",&choice);
        while(choice!=1&&choice!=2)
            {
            printf("请重新输入你想进行的操作：\n");
            printf("1.修改信息\n");
            printf("2.删除人员\n");
            scanf("%d",&choice);
            }
       if(choice==1)
       {
           printf("请输入你想要修改的人的名字或学号");
           scanf("%s",search);
           current=headone;
           for(current=headone;current!=NULL;current=current->next)
           {
               if(strcmp(current->name,search)==0||strcmp(current->IDnum,search))
               {
                   printf("%-10s%-10s%-10s%-5s%-15s%-15s%-45s%-11\n",current->group,current->name,current->major,current->grade,current->phonenum
                           ,current->qq,current->email,current->IDnum);
                    printf("请输入成员的组别(eg.电路，机械，视觉，嵌软，运营)\n");
                    scanf("%10s", current->group );
                    printf("请输入成员的名字\n ");
                    scanf("%10s",current->name);
                    printf("请输入成员的专业\n ");
                    scanf("%10s", current->major );
                    printf("请输入成员的年级\n");
                    scanf("%5s", current->grade);
                    printf("请输入成员的电话\n ");
                    scanf("%15s", current->phonenum );
                    printf("请输入成员的QQ .\n ");
                    scanf("%15s", current->qq );
                    printf("请输入成员的邮箱\n ");
                    scanf("%45s", current->email );
                    printf("请输入成员的学号\n ");
                    scanf("%11s", current->IDnum );
                    printf("这是你修改后的信息\n");
                    printf("%-10s%-10s%-10s%-5s%-15s%-15s%-45s%-11\n",current->group,current->name,current->major,current->grade,current->phonenum
                           ,current->qq,current->email,current->IDnum);

                    break;
               }
           }
           fileprt=fopen("团队管理信息.txt ", "w");
           current=headone;
           for(current=headone;current!=NULL;current=current->next)
           {
                           fprintf(fileprt,"%10s", current->group );
            fprintf(fileprt, "%10s",current->name);
            fprintf(fileprt, "%10s", current->major );
            fprintf(fileprt, "%5s", current->grade);
            fprintf(fileprt, "%15s", current->phonenum );
            fprintf(fileprt, "%15s", current->qq );
            fprintf(fileprt, "%45s", current->email );
            fprintf(fileprt, "%11s\n", current->IDnum );

           }

            fclose( fileprt);
            printf("修改成功!\n");
            system("pause");
            clear();

       }
       else if(choice==2)
       {
           printf("请输入你想删除的人员的名字或学号\n");
           scanf("%s",search);
           current=headone;
           while(current!=NULL)
           {

              if(strcmp(current->name,search)==0||strcmp(current->IDnum,search))
               {
                   free(current);
                   prev->next=current->next;
               }
               else prev->next=current;
               current=current->next;

           }
           fileprt=fopen("团队管理信息.txt ", "w");
           current=headone;
           for(current=headone;current!=NULL;current=current->next)
           {
                fprintf(fileprt,"%10s", current->group );
                fprintf(fileprt, "%10s",current->name);
                fprintf(fileprt, "%10s", current->major );
                fprintf(fileprt, "%5s", current->grade);
                fprintf(fileprt, "%15s", current->phonenum );
                fprintf(fileprt, "%15s", current->qq );
                fprintf(fileprt, "%45s", current->email );
                fprintf(fileprt, "%11s\n", current->IDnum );

           }

            fclose( fileprt );
            printf("删除成功!\n");
            getchar();
            clear();
       }


}
/**char *s_gets(char * st,int n)
{
    char * ret_val;
    char *　find;

    ret_val=fgets(st ,n ,stdin);
    if (ret_val)
    {
        find=strchr(st, '\n');///查找换行符
        if(find)              ///如果地址不是NULL
        {
            *find='\0';
        }
        else
            while(getchar()!='\n')///按下回车键
                continue;
    }
    return ret_val;
}

**/
void freelinkedlist()
{
    struct student*currentone=NULL;
    struct zhanghu*currenttwo=NULL;
    if(headone!=NULL)
    {
        currentone=headone;
        while(currentone!=NULL)
        {
            currentone=headone;
            headone=currentone->next;
            free(currentone);
        }
    }
    if(headtwo!=NULL)
    {
        currenttwo=headtwo;
        while(currenttwo!=NULL)
        {
            currenttwo=headtwo;
            headtwo=currenttwo->next;
            free(currenttwo);
        }
    }
}




void sighin()
{
    FILE *fileprt=NULL;
    int choice=0;
    char name[5];
    struct tm *ptr;
    time_t it;
    it=time(NULL);
    ptr=localtime(&it);
    printf("您的名字是：\n");
    scanf("%s",name);
    if((fileprt=fopen("签到记录.txt","a+"))==NULL)    printf("打开文件出错...\n");
    else{
        printf("选择以下选项\n");
        printf("1.签到\n");
        printf("2.签退\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                fprintf(fileprt,"%5s%4d年%02d月%02d日 %d:%d:%d签到\n",*name,ptr->tm_year+1900,ptr->tm_mon+1,ptr->tm_mday,ptr->tm_hour,ptr->tm_min,ptr->tm_sec);
                printf("签到成功，谢谢\n");
                break;
            case 2:
                fprintf(fileprt,"%5s%4d年%02d月%02d日 %d:%d:%d签退\n",*name,ptr->tm_year+1900,ptr->tm_mon+1,ptr->tm_mday,ptr->tm_hour,ptr->tm_min,ptr->tm_sec);
                printf("签退成功，谢谢\n");
                break;
            default:
                printf("错误操作,正在退出...\n");
                break;
        }

    }
    fclose(fileprt);
}
