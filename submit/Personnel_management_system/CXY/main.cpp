//通过这个人员管理系统学习到fscanf,fprintf,fopen,feof,EOF。完成登陆的操作
//下一次编写，改进人员计数器，采用全局变量。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MenNum 200//人员管理系统所能存储人员的最大值
#define groupLEN 20
#define nameLEN 20
#define majorLEN 20
#define TeleLEN 15
#define mailLEN 40
#define IDLEN 11
#define qqLEN 15

#define LenthUserName 20
#define LenthKeyWord  20
#define UserNum       100

//登陆机制用到的变量
struct  User
{
    char User_name[LenthUserName];
    char Keyword[LenthKeyWord];
};
struct User users[100];
int TempUserNum = 0;


//人员管理系统用到的结构变量
struct Men
{
    char group[groupLEN];
    char name[nameLEN];
    char major[majorLEN];
    char Tele[TeleLEN];
    char QQ[qqLEN];
    char Mail[mailLEN];
    char ID[IDLEN];
};
struct Men member[MenNum];
int TempMemberNum = 0;

//登陆机制
int Signin();
int Signup();
int LoadInterFace();
void LoadinUser();

//菜单管理函数
void PrtMenu();
void CleanMenu();

//菜单选项函数
void Memberlist();
void Add();
void Finding();
void Change();
void Sort();
//读入文件中的数据
void ReadMemberFile();
int main()
{
    LoadinUser();
    if( LoadInterFace()==1 )
    {
        int option = 0;
        CleanMenu();
        printf("登陆成功！\n");
        PrtMenu();
        ReadMemberFile();

        printf("请输入选项以继续:\n");
        scanf("%d", &option );

        switch( option )
        {
            case 1:
                printf("加载人员信息：\n");
                Memberlist();
                break;
            case 2:
                printf("添加新的成员：\n");
                Add();
                break;
            case 3:
                printf("查询成员信息：\n");
                Finding();
                break;
            case 4:
                printf("成员信息改动：\n");
                Change();
                break;
            case 5:
                printf("成员信息排序：\n");
                Sort();
                break;
            default:
                CleanMenu();
                printf("请输入正确的选项：\n");
                main();
            break;
        }
    }
    else
    {
        return 0;
    }



    return 0;
}
void PrtMenu()
{
    printf("******************************************************\n");
    printf("*             欢迎来到Robomaster人员管理系统         *\n");
    printf("*                 选项1：加载成员信息                *\n");
    printf("*                 选项2：添加成员信息                *\n");
    printf("*                 选项3：查询成员                    *\n");
    printf("*                 选项4：成员信息改动                *\n");
    printf("*                 选项5：排序成员                    *\n");
    printf("******************************************************\n");
}
void LoadinUser()
{
    int i = 0;
    FILE *loadptr;
    loadptr = fopen("用户数据.txt", "r");
    while( !feof(loadptr) )//
    {

        fscanf(loadptr,"%19s%19s", &users[i].User_name,&users[i].Keyword );
        ++TempUserNum;
        ++i;
    }
    TempUserNum=TempUserNum-1;
    fclose(loadptr);
}
int  LoadInterFace()
{

    int Option_load = 0;
    printf("***********************************************\n");
    printf("*           Robomaster人员管理系统            *\n");
    printf("*           选项1：登陆                       *\n");
    printf("*           选项2：注册账号                   *\n");
    printf("*           选项3：退出系统                   *\n");
    printf("***********************************************\n");

    scanf("%d",&Option_load);
    if( Option_load == 1 )
    {
        int Signinresult=Signin();
        if( Signinresult==0 )
        {
            printf("用户名或者密码错误\n");
            LoadInterFace();

        }
        else if( Signinresult==1 )
        {
            return 1;
        }
    }
    if( Option_load == 2 )
    {
        Signup();
        int Signinresult=Signin();
        if( Signinresult==0 )
        {
            printf("用户名或者密码错误\n");
            LoadInterFace();

        }
        else if( Signinresult==1 )
        {
            return 1;
        }
    }
    if( Option_load == 3 )
    {
        return 0;
    }
}
int Signup()
{
    LoadinUser();
    char UserName[LenthUserName];
    char KeyWord[LenthKeyWord];

    printf("用户注册：\n");
    printf("用户名:");
    scanf("%19s",UserName);
    printf("\n密码: ");
    scanf("%19s",KeyWord );

    int i = 0;
    while( i < TempUserNum+1 )
    {
        if( strcmp( users[i].User_name, UserName )==0 )
        {
            printf("用户名重复\n重新注册\n");
            Signup();
        }
        ++i;
    }
    printf("注册成功\n");
    FILE *loadptr;
    loadptr = fopen("用户数据.txt", "a+");
    fprintf(loadptr,"%-s\t%-s\n",UserName,KeyWord);
    LoadinUser();
    fclose(loadptr);

}
int  Signin()
{
    int i = 0;
    char UserName[LenthUserName];
    char KeyWord[LenthKeyWord];
    printf("请输入您的登陆信息:\n");
    printf("用户名:");
    scanf("%19s", &UserName);
    printf("\n密码: ");
    scanf("%19s",&KeyWord);
    while( i<TempUserNum+1 )//TempUserNum为当前注册用户数
    {
        if( strcmp( users[i].User_name, UserName )==0&& strcmp( users[i].Keyword, KeyWord )==0)
        {

            return 1;
        }
        ++i;
    }
    return 0;

}
void CleanMenu()
{
    system("cls");
}





void Memberlist()
{
    int i=0;
    printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "组别","姓名","专业年纪","电话","QQ", "邮箱","学号");
    printf("\n");
    while( i<TempMemberNum )
    {
        printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);

        ++i;
    }
}
void Add()
{
    FILE *MLptr;
    MLptr = fopen( "人员信息.txt ", "a+" );
    printf("你可以增加一个成员信息 .\n");
    int i = TempMemberNum+1;
    printf("请输入成员的组别 （电路，机械，视觉，嵌软，运营）.\n");
            scanf("%19s", &member[i].group );
            //fprintf(Ptr,"\n%-2s\t",member[i].group );

            printf("请输入成员的名字\n ");
            scanf("%19s", &member[i].name );
            //fprintf(Ptr,"%-6s\t",member[i].name );

            printf("请输入成员的专业年纪 （eg:提高1701，通信1501） .\n ");
            scanf("%19s", &member[i].major );
            //fprintf(Ptr,"%-8s\t",member[i].major );

            printf("请输入成员的电话\n ");
            scanf("%14s", &member[i].Tele );
            //fprintf(Ptr,"%-11s\t",member[i].Tele );

            printf("请输入成员的QQ .\n ");
            scanf("%14s", &member[i].QQ );
            //fprintf(Ptr,"%-11s\t",member[i].QQ );

            printf("请输入成员的邮箱\n ");
            scanf("%39s", &member[i].Mail );
            //fprintf(Ptr,"%-20s\t",member[i].Mail );

            printf("请输入成员的学号\n ");
            scanf("%10s", &member[i].ID );
            //fprintf(Ptr,"%-11s\t",member[i].ID );



                fprintf(MLptr,"\n%-2s\t",member[i].group );
                fprintf(MLptr,"%-6s\t",member[i].name );
                fprintf(MLptr,"%-8s\t",member[i].major );
                fprintf(MLptr,"%-11s\t",member[i].Tele );
                fprintf(MLptr,"%-11s\t",member[i].QQ );
                fprintf(MLptr,"%-20s\t",member[i].Mail );
                fprintf(MLptr,"%-11s\t",member[i].ID );


    fclose( MLptr );
    printf("这下面是你要添加的成员信息\n");
    printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
    printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);

    printf("添加成功!\n");
    system("pause");
    printf("你还要进行什么操作！\n");
    CleanMenu();
    main();
    //展示输入信息的成果
}
void Finding()
{
    int choice;
    printf("******************************************************\n");
    printf("*              选项1:按姓名查找                      *\n");
    printf("*              选项2:按组别查找                      *\n");
    printf("*              选项3:按学号查找                      *\n");
    printf("******************************************************\n");

    scanf("%d", &choice);

    if( choice == 1)
    {
        int i = 0,jug=0;//用这个jug变量去判断是否进入if
        char F_name[10];
        printf("请输入查找的姓名");
        scanf("%9s", &F_name);
        while( i<TempMemberNum+1 )
        {

            if( !strcmp( member[i].name, F_name))
            {
                ++jug;
                printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
                printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);
            }
            ++i;
        }
        if ( jug == 0 )
        {
            printf("没有找到匹配的名字\n");
        }

    }
    if( choice == 2)
    {
        printf("输入组别，打出组别的成员\n");
        printf("如'视觉','电路','机械','嵌软','运营'\n");
        char GN[10];
        scanf("%9s", GN);
        int i=0,jug=0;//用这个jug变量去判断是否进入if
        printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
        while( i<TempMemberNum+1 )
        {

            if( !strcmp( member[i].group,GN) )
            {
                ++jug;
                printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);
            }
            ++i;

        }
        if ( jug == 0 )
        {
            printf("没有找到这个人\n");
        }
    }
    if( choice == 3)
    {
        printf("请输入你要查找的学号\n");
        printf("例如：U201715487\n");
        char IdE[12];
        scanf("%d", IdE);
        int i=0, jug=0;//用这个jug变量去判断是否进入if
        printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
        while( i<TempMemberNum+1)//判断是否是文件结尾
        {

            if( strcmp( member[i].ID,IdE)==0 )
            {
                ++jug;
                printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);
            }
            ++i;

        }
        if ( jug == 0 )
        {
            printf("没有找到与学好匹配的成员\n");
        }

    }
}
void Change()
{
    int option;
    printf("******************************************************\n");
    printf("*              选项1:删除成员信息                    *\n");
    printf("*              选项2:成员信息改动                    *\n");
    printf("******************************************************\n");

    scanf("%d" , &option );
    if( option == 1 )
    {
        FILE *Ptr;
        char Del_name[20];
        int InJug=0;
        printf("请输入要删除的成员姓名\n");
        scanf("%19s", Del_name );
        int i=-1;
        while(1)
        {
            ++i;
            if( strcmp( member[i].name, Del_name ) == 0 )
            {
                int j=i;
                InJug = 1;
                for ( j=i; j<TempMemberNum+1; ++j)
                {
                    strcpy( member[j].group, member[j+1].group );
                    strcpy( member[j].name, member[j+1].name );
                    strcpy( member[j].major, member[j+1].major );
                    strcpy( member[j].Tele, member[j+1].Tele );
                    strcpy( member[j].QQ, member[j+1].QQ );
                    strcpy( member[j].Mail, member[j+1].Mail );
                    strcpy( member[j].ID, member[j+1].ID );
                }
                break;
            }

        }
        if( InJug == 0)
        {
            printf("没有找到你要删除的人员");
        }
        int g=0;
        Ptr = fopen("人员信息.txt", "w");
        while( g<TempMemberNum && !feof(Ptr) )
        {
            fprintf(Ptr,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
            ++g;

        }
        fclose(Ptr);

    }
    if( option == 2)
    {
        int Change_option = 0;
        char Change_name [10];
        printf("******************************************************\n");
        printf("*              选项1:更改成员组别                    *\n");
        printf("*              选项2:更改成员姓名                    *\n");
        printf("*              选项3:更改成员专业年纪                *\n");
        printf("*              选项4:更改成员电话                    *\n");
        printf("*              选项5:更改成员QQ                      *\n");
        printf("*              选项6:更改成员邮箱                    *\n");
        printf("*              选项7:更改成员学号                    *\n");
        printf("******************************************************\n");
        scanf("%d", &Change_option);
        if( Change_option == 1 )
        {
            int j=0;
            printf("更改组别! \n 请输入你要更改组别的成员的姓名!\n");
            scanf( "%9s", Change_name);
            while( j < TempMemberNum)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("请输入更改后的组别!（电路，机械，视觉，嵌软，运营）\n");
                    scanf("%19s",&member[j].group);
                }
                ++j;
            }
        }
        else if( Change_option == 2 )
        {
            int j=0;
            printf("更改姓名! \n 请输入之前的姓名 !\n");
            scanf( "%9s", Change_name );
            while( j< TempMemberNum)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("请输入更改后的姓名!\n");
                    scanf( "%19s",&member[j].name );
                }

                ++j;
            }
        }
        else if( Change_option == 3 )
        {
            int j=0;
            printf("更改专业! \n 请输入需要更改后的专业成员姓名!\n");
            scanf( "%9s",Change_name);
            while( j < TempMemberNum)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("请输入更改后的姓名!\n");
                    scanf("%19s",&member[j].major);
                }
                ++j;
            }
        }
        else if( Change_option == 4 )
        {
            int j=0;
            printf("改变电话号码! \n 请输入需要改变电话号码的成员姓名!\n");
            scanf( "%9s",Change_name);
            while( j < TempMemberNum )
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("请输入更改后的电话号码!\n");
                    scanf("%19s",&member[j].Tele);
                }
                ++j;
            }
        }
        else if( Change_option == 5 )
        {
            int j=0;
            printf("修改QQ号! \n 请输入需要修改QQ号的成员姓名!\n");
            scanf( "%9s",Change_name);
            while( j < TempMemberNum )
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("请输入新的QQ号!\n");
                    scanf("%19s",&member[j].QQ);
                }
                ++j;
            }
        }
        else if( Change_option == 6 )
        {
            int j=0;
            printf("更改邮箱! \n 请输入需要更改邮箱的成员信息 !\n");
            scanf( "%9s",Change_name);
            while( j < TempMemberNum )
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("请输入更改后的邮箱!\n");
                    scanf("%19s",&member[j].Mail);
                }
                ++j;
            }
        }
        else if ( option == 7)
        {
            int j=0;
            printf("改变学号! \n 请输入需要更改学号的成员信息!\n");
            scanf( "%9s",Change_name);
            while( j < TempMemberNum )
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("请输入更改后的学号!\n");
                    scanf("%19s",&member[j].ID);
                }
                ++j;
            }
        }
        else
        {
            printf("请输入1-7中的整数\n重新更改成员信息");
            Change();
        }
        FILE *Ptr;
        int g=0;
        Ptr = fopen("人员信息.txt", "w");
        while( g<TempMemberNum && !feof(Ptr) )
        {

            fprintf(Ptr,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
            ++g;
        }
        fclose(Ptr);
    }

}
void Sort()
{
    int Sort_option = 0;
    printf("******************************************************\n");
    printf("*              选项1:按照学号排序                    *\n");
    printf("*              选项2:按照组别分类                    *\n");
    printf("******************************************************\n");
    scanf("%d", &Sort_option );
    if( Sort_option == 1 )
    {
        int i = 0 , j = 0;
        int cmp = 0;
        struct Men TempMember;
        for( i = 0; i < TempMemberNum-1; ++i )
        {
            for( j = 0; j< TempMemberNum-i-1; ++j)
            {
                cmp = strcmp( member[j].ID, member[j+1].ID );//注意冒泡排序越界
                if( cmp>0 )
                {
                    TempMember = member[j+1];
                    member[j+1] = member[j];
                    member[j] = TempMember;
                }
            }
        }

        FILE * Sortptr;
        if( (Sortptr=fopen("按学号排序.txt","w") )== NULL )
        {
            printf("创建文件失败！\n");
        }
        else
        {
            int k = 0;
            for( k = 0; k<TempMemberNum+1; ++k )
            {
                fprintf(Sortptr,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[k].group,member[k].name,member[k].major,member[k].Tele,member[k].QQ,member[k].Mail,member[k].ID );
            }
        }
        fclose(Sortptr);
        printf("学号从小到大排序后的成员列表为：\n");
        Memberlist();

    }
    if( Sort_option == 2 )
    {
        FILE *fptr1;
        fptr1=fopen("按视觉组分类.txt","w");
        int g= 0;
        printf("视觉组的小伙伴：\n");
        printf("\n");
        while( g < TempMemberNum+1 )
        {
            if( strcmp(member[g].group,"视觉")==0 )
            {
                fprintf(fptr1,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
                printf("%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
            }
            ++g;
        }
        printf("\n\n");
        fclose(fptr1);


        FILE *fptr2;
        fptr2=fopen("按机械组分类.txt","w");
        g= 0;
        printf("机械组的小伙伴：\n");
        while( g < TempMemberNum+1 )
        {
            if( strcmp(member[g].group,"机械")==0 )
            {
                fprintf(fptr2,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
                printf("%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
            }
            ++g;
        }
        printf("\n\n");
        fclose(fptr2);

        FILE *fptr3;
        fptr3=fopen("按电路组分类.txt","w");
        printf("电路组的小伙伴：\n");
        g= 0;
        while( g < TempMemberNum+1 )
        {
            if( strcmp(member[g].group,"电路")==0 )
            {
                fprintf(fptr3,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
                printf("%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
            }
            ++g;
        }
        printf("\n\n");
        fclose(fptr3);

        FILE *fptr4;
        fptr4=fopen("按嵌软组分类.txt","w");
        printf("嵌软组的小伙伴：\n");
        g= 0;
        while( g < TempMemberNum+1 )
        {
            if( strcmp(member[g].group,"嵌软")==0 )
            {
                fprintf(fptr4,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
                printf("%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
            }
            ++g;
        }
        printf("\n\n");
        fclose(fptr4);

        FILE *fptr5;
        fptr5=fopen("按运营组分类.txt","w");
        printf("运营组的小伙伴：\n");
        g= 0;
        while( g < TempMemberNum+1 )
        {
            if( strcmp(member[g].group,"运营")==0 )
            {
                fprintf(fptr5,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
                printf("%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
            }

            ++g;
        }
        printf("\n\n");
        fclose(fptr5);
    }

}
void ReadMemberFile()
{
    FILE * MLptr ;

    if((MLptr=fopen( "人员信息.txt", "r" )) == NULL )
    {
        printf("无法打开！\n");
    }
    else
    {
        int i = 0;
        while( !feof(MLptr) )
        {
            fscanf(MLptr,"%19s%19s%19s%14s%14s%39s%10s",&member[i].group, &member[i].name, &member[i].major, &member[i].Tele, &member[i].QQ, &member[i].Mail, &member[i].ID);
            ++i;
            ++TempMemberNum;
        }
        TempMemberNum = TempMemberNum-1;//这个计算得到总成员数
        fclose( MLptr );

    }
}
