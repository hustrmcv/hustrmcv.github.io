#include <stdio.h>
#include <string.h>
#include "stddef.h"
#include <stdlib.h>

struct Friends_List
{
    char group[10];
    char name[10];
    char major[16];
    char telephone[13];
    char email[20];
    char QQ[13];
    char ID[16];
    struct Friends_List*next;
};

struct Friends_List*Create_Friends_List( struct Friends_List*p )
{
    if( p != NULL )
    {
        printf( "通讯录已经存在。\n" );
    }

    else
    {
        p = ( struct Friends_List* ) malloc( sizeof( struct Friends_List ) );

        if ( p == NULL )
        {
            printf( "创建通讯录失败，重新创建。\n" );

            return p;
        }

        p->next = NULL;
    }

    return p;
}

//添加一位新联系人的信息
void Insert_Friends_List( struct Friends_List*p )
{
    struct Friends_List*q;
    char c;

    if ( p == NULL )
    {
        printf( "通讯录不存在，请先创建！\n" );
    }

    else while(1)
    {
        q = ( struct Friends_List* ) malloc( sizeof( struct Friends_List ) );

        if(q == NULL)
        {
            continue;
        }

        printf("请输入新联系人的组别： ");
        scanf("%s", q->group);
        printf("请输入新联系人的姓名： ");
        scanf("%s", q->name);
        printf("请输入新联系人的班级名称： ");
        scanf("%s", q->major);
        printf("请输入新联系人的电话号码： ");
        scanf("%s", q->telephone);
        printf("请输入新联系人的邮箱地址： ");
        scanf("%s", q->email);
        printf("请输入新联系人的QQ号码:  ");
        scanf("%s", q->QQ);
        printf("请输入新联系人的学号： ");
        scanf("%s", q->ID);

        q->next=NULL;
        q->next=p->next;
        p->next=q;

        printf("按q退出，按其他键继续！\n");
        fflush(stdin);
        scanf("%c", &c);

        if(c == 'q')
        {
            break;
        }
    }
}

//通过名字打印出联系人信息或打印出全部联系人的信息
void Display_Friend_List( struct Friends_List*p, char name[10], int i )
{
    struct Friends_List*q;
    int j;
    q = p->next;

    if ( i == 1 )
    {
        j = 1;

        while ( q != NULL )
        {
            if ( strcmp( name, q->name )==0 )
            {
                printf( "\n************姓名为%s的第%d个联系人*************\n", q->name, j );
                printf("组别\t姓名\t专业班级\t电话号码\t邮箱地址\tQQ号码\t  学号\n");
                printf("%-8s%-8s%-16s%-16s%-16s%-12s%-12s\n", q->group, q->name, q->major, q->telephone, q->email, q->QQ, q->ID);
                j++;
            }
            q=q->next;
        }
        if( j==1 )
        {
            printf("通讯录中没有姓名为: %s的联系人。\n", name);
        }
    }

    else
    {
        j = 1;

        while( q != NULL )
        {
            printf( "\n************第%d个联系人*************\n", j );
            printf("组别\t姓名\t专业班级\t电话号码\t邮箱地址\tQQ号码\t  学号\n");
            printf("%-8s%-8s%-16s%-16s%-16s%-12s%-12s\n", q->group, q->name, q->major, q->telephone, q->email, q->QQ, q->ID);

            q = q->next;
            j++;
        }

        if( j==1 )
        {
            printf( "通讯录中没有记录。\n" );
        }
    }
}

//通过学号打印出联系人信息
void Display_Friend_List_ID( struct Friends_List*p, char ID[10], int i )
{
    struct Friends_List*q;
    int j = 1;
    q = p->next;

    while ( q != NULL )
    {
        if ( strcmp( ID, q->ID ) == 0 )
        {
            printf( "\n************学号为%s的第%d个联系人*************\n", q->ID, j );
            printf("组别\t姓名\t专业班级\t电话号码\t邮箱地址\tQQ号码\t  学号\n");
            printf("%-8s%-8s%-16s%-16s%-16s%-12s%-12s\n", q->group, q->name, q->major, q->telephone, q->email, q->QQ, q->ID);

            j++;
        }

        q=q->next;
    }

    if(j==1)
    {
        printf("通讯录中没有学号为: %s的联系人。\n", ID);
    }
}

//询问以何种方式查询
void Query_Friends_List( struct Friends_List*p )
{
    int choice;
    char name[10];
    char ID[16];

    if( p == NULL )
    {
        printf( "通讯录不存在，请先创建！\n" );

        return;
    }

    while(1)
    {
        printf( "查询选项： 1：按姓名查询联系人 2: 按学号查询联系人 3：查询所有联系人 0：退出\n" );
        printf( "请选择功能：" );  scanf( "%d", &choice );

        if ( choice == 1 )
        {
            printf( "请输入联系人的姓名：" );
            scanf( "%s", name );
            Display_Friend_List( p, name, 1 );
        }

        if ( choice == 2 )
        {
            printf( "请输入联系人的学号：" );
            scanf( "%s", ID );
            Display_Friend_List_ID( p, ID, 1 );
        }

        else if( choice == 3 )
        {
            Display_Friend_List( p, name, 2 );
        }

        else if( choice == 0 )
        {
            break;
        }
    }
}

//删除某个联系人的信息
int Delete_Friends_List( struct Friends_List*p )
{
    char name[10];
    struct Friends_List*q,*r;
    int j = 1;

    if ( p == NULL )
    {
        printf( "通讯录不存在， 请先创建！\n" );

        return 1;
    }

    printf( "请输入要删除的联系人的姓名：" );
    scanf( "%s", name );

    r = p;
    q = p->next;

    while( q != NULL )
    {
        if( strcmp( name, q->name ) == 0 )
        {
            r->next = q->next;
            free(q);
            q = r->next;
            j++;
        }

        else
        {
            r = q;
            q = q->next;
        }
    }

    if ( j == 0 )
    {
        printf("通讯录中没有姓名为：%s的联系人。\n", name);
    }

    else
    {
        printf("通讯录中共删除了姓名为：%s的%d条记录。\n", name, j);
    }

    return 0;
}

//将文件中的信息读取到单链表中
struct Friends_List *createlink()
{
    char c;
    struct Friends_List*p;
    p =(struct Friends_List*)malloc(sizeof(struct Friends_List));
    struct Friends_List *r;
    struct Friends_List *q;

    r=q=p;
    FILE * fp= fopen("information.txt","r");

    if( fp == NULL )
    {
        printf("打开文件失败!");

        return NULL;
    }

    while( (c = fgetc(fp))!=EOF )
    {
       q= (struct Friends_List*)malloc(sizeof(struct Friends_List));
       fscanf(fp,"%10s%10s%16s%13s%20s%13s%16s", \
              q->group, q->name, q->major, q->telephone, q->email, q->QQ, q->ID);
       //Display_Friend_List( p, c, 0 );

       r->next = q;
       r = q;
    }

    r->next=NULL;
    printf("读取成功！");

    return p;
}

//将单链表中的信息保存到文件中
void outlink(struct Friends_List*p)
{
   struct Friends_List *q=p->next;

   FILE *fp =fopen("information.txt","w");

   if(fp == NULL)
   {
       printf("打开文件失败!");
       return;
   }

   while(q)
   {
       //输出链表节点数据到文件information.txt
       fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s ", q->group, q->name, q->major, q->telephone, q->email, q->QQ, q->ID);
       q=q->next;
   }
   printf("\n");
   fprintf(fp,"\n");
   fclose(fp);
   printf("保存成功！");

   return;
}

//主函数
int main( void )
{
    int choice;
    struct Friends_List*p = NULL;

    do
    {
        printf( "\n通讯录管理功能选项:\n1:新建 2:插入 3:查询 4:删除 5:保存 6:载入 0:退出\n" );
        printf( "请选择功能:" );
        scanf( "%d", &choice );

        switch( choice )
        {
            case 1:
                p = Create_Friends_List(p);
                break;

            case 2:
                Insert_Friends_List(p);
                break;

            case 3:
                Query_Friends_List(p);
                break;

            case 4:
                Delete_Friends_List(p);
                break;

            case 5:
                outlink(p);
                break;

            case 6:
                p=createlink();
                break;

            case 0:
                break;

            default:
                printf( "选项错误， 重新选择。" );
        }
    }while( choice != 0 );


    printf("谢谢使用通讯录管理程序，再见！\n");

    return 0;
}
