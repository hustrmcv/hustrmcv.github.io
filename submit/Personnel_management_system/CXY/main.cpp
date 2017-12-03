//author :ChenWellesCxy
//purpose :personnel management system
#include <iostream>
#include <cstdio>
#include <cstring>
#define MenNum 200//人员管理系统所能存储人员的最大值
#define groupLEN 20
#define nameLEN 20
#define majorLEN 20
#define TeleLEN 15
#define mailLEN 40
#define IDLEN 11
#define qqLEN 15

using namespace std;

struct Men
{
    char group[groupLEN];
    char name[nameLEN];
    char major[majorLEN];
    char Tele[TeleLEN];
    char QQ[qqLEN];
    char Mail[mailLEN];
    char ID[IDLEN];
    int k;


};
struct Men member[MenNum];

void Memberlist();
void Add();
void Finding();
void Change();
void Sort();

int main()
{
    int option;
    cout<<"Welcome to hustrm group's personnel management system!\n";
    cout<<"Enter 1 to list all the  members' information\n";
    cout<<"Enter 2 to add members' information\n";
    cout<<"Enter 3 to find a group member\n";
    cout<<"Enter 4 to change one person's information\n";
    cout<<"Enter 5 to resort the list \n";


    cin>>option;

    FILE *Ptr;
    Ptr=fopen( "人员信息.txt", "r" );
    if( (Ptr=fopen( "人员信息.txt", "r" )) == NULL )
    {
        cout<<"Can't open the file";
    }
    else
    {
        int i=0;
        while( !feof(Ptr) )
        {

            fscanf(Ptr,"%19s%19s%19s%14s%14s%39s%10s",&member[i].group, &member[i].name, &member[i].major, &member[i].Tele, &member[i].QQ, &member[i].Mail, &member[i].ID);
            if( !feof(Ptr) )
            {
                member[i].k = 1;//对feof的使用还不是很清晰，这个读入是C语言的句法。

            }
            else
            {
                member[i].k = 0;//标记最后一个文件结尾，把标记位记为1//定义了200的结构数组但是空的先不管
            }
            ++i;
        }
        fclose( Ptr );
    }
    //读取文件中成员信息

    if( option == 1 )
    {
       Memberlist();
    }
    if( option == 2 )
    {
        Add();
    }
    if( option == 3 )
    {
        Finding();
    }
    if( option == 4 )
    {
        Change();
    }
    if( option == 5 )
    {
        Sort();
    }

    return 0;
}

void Memberlist( )
{
    FILE *Ptr;
    Ptr=fopen( "人员信息.txt", "r" );
    int i=0;
    printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
    while( i<MenNum&&!feof(Ptr) )
    {
        printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);
        if( member[i].k == 0)
        {
            break;
        }

        ++i;
    }
    fclose( Ptr );
}
void Add()
{
    FILE *Ptr;
    Ptr = fopen( "人员信息.txt ", "a+" );
    printf("You can add a member's information .\n");
    int i=0;
    while ( i<MenNum&&!feof(Ptr) )
    {
        if( member[i].k == 0)
        {
            member[i].k = 1;//把文件末尾标记传给下一个。
            ++i;
            printf("Please input member's group （电路，机械，视觉，嵌软，运营）.\n ");
            scanf("%19s", &member[i].group );
            fprintf(Ptr,"\n%-2s\t",member[i].group );

            printf("Please input member's name .\n ");
            scanf("%19s", &member[i].name );
            fprintf(Ptr,"%-6s\t",member[i].name );

            printf("Please input member's major （eg:提高1701，通信1501） .\n ");
            scanf("%19s", &member[i].major );
            fprintf(Ptr,"%-8s\t",member[i].major );

            printf("Please input member's Tele .\n ");
            scanf("%14s", &member[i].Tele );
            fprintf(Ptr,"%-11s\t",member[i].Tele );

            printf("Please input member's QQ .\n ");
            scanf("%14s", &member[i].QQ );
            fprintf(Ptr,"%-11s\t",member[i].QQ );

            printf("Please input member's Mail .\n ");
            scanf("%39s", &member[i].Mail );
            fprintf(Ptr,"%-20s\t",member[i].Mail );

            printf("Please input member's ID .\n ");
            scanf("%10s", &member[i].ID );
            fprintf(Ptr,"%-11s\t",member[i].ID );

            member[i].k = 0;

            break;
        }
        ++i;
    }
    fclose( Ptr );
    printf("The member you add is listing.\n");
    printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
    printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);
    //展示输入信息的成果

}
void Finding()
{
    int choice;
    cout<<"Enter 1 to search by name "<<endl;
    cout<<"Enter 2 to search in the groups"<<endl;
    cout<<"Enter 3 to search by ID numbers"<<endl;
    cin>>choice;

    if( choice == 1)
    {
        int i = 0,jug=0;//用这个jug变量去判断是否进入if
        char F_name[10];
        cout<<"the name that you want to search\n";
        cin>>F_name;
        while( member[i].k == 1)
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
            cout<<"Can't find the person"<<endl;
        }

    }
    if( choice == 2)
    {
        cout<<"Please enter the group name "<<endl;
        cout<<"you can choose from '视觉','电路','机械','嵌软','运营'"<<endl;
        char GN[10];
        cin>>GN;
        int i=0,jug=0;//用这个jug变量去判断是否进入if
        printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
        while( member[i].k == 1)
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
            cout<<"Can't find the person"<<endl;
        }
    }
    if( choice == 3)
    {
        cout<<"Please enter the ID numbers "<<endl;
        cout<<"Like U111111111!"<<endl;
        char IdE[12];
        cin>>IdE;
        int i=0, jug=0;//用这个jug变量去判断是否进入if
        printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n", "group","member","major","Tele","QQ", "mail","ID");
        while( member[i].k == 1)//判断是否是文件结尾
        {

            if( !strcmp( member[i].ID,IdE))
            {
                ++jug;
                printf("%-10s%-10s%-10s%-15s%-15s%-35s%-20s\n",member[i].group, member[i].name, member[i].major, member[i].Tele, member[i].QQ, member[i].Mail, member[i].ID);
            }
            ++i;

        }
        if ( jug == 0 )
        {
            cout<<"Can't find the person"<<endl;
        }

    }
}
void Change()
{
    int option;
    printf("Enter 1 to delete one's information .\n ");
    printf("Enter 2 to change one's information .\n ");
    scanf("%d" , &option );
    if( option == 1 )
    {
        FILE *Ptr;
        char Del_name[20];
        int InJug=0;
        printf("Please enter the name of the member.\n");
        scanf("%19s", Del_name );
        int i=-1;
        while(1)
        {
            ++i;
            if( strcmp( member[i].name, Del_name ) == 0 )
            {
                int j=i;
                InJug = 1;
                for ( j=i; member[j].k==1; ++j)
                {
                    strcpy( member[j].group, member[j+1].group );
                    strcpy( member[j].name, member[j+1].name );
                    strcpy( member[j].major, member[j+1].major );
                    strcpy( member[j].Tele, member[j+1].Tele );
                    strcpy( member[j].QQ, member[j+1].QQ );
                    strcpy( member[j].Mail, member[j+1].Mail );
                    strcpy( member[j].ID, member[j+1].ID );
                    member[j].k=member[j+1].k;


                }//最后一个赋给倒数第二个，标记量变为0.
                ++j;
                break;
            }

        }
        if( InJug == 0)
        {
            printf("Did't find the name matched!");
        }
        int g=0;
        Ptr = fopen("人员信息.txt", "w");
        while( g<MenNum && !feof(Ptr) )
        {
            fprintf(Ptr,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
            ++g;

            if( member[g].k == 0 )
            {
                break;
            }

        }
        fclose(Ptr);

    }
    if( option == 2)
    {
        int Change_option = 0;
        char Change_name [10];
        printf("Enter 1 to change one's group .\n ");
        printf("Enter 2 to change one's name .\n ");
        printf("Enter 3 to change one's major .\n ");
        printf("Enter 4 to change one's Telephone number.\n ");
        printf("Enter 5 to change one's QQ.\n ");
        printf("Enter 6 to change one's Mail.\n ");
        printf("Enter 7 to change one's ID number .\n ");
        scanf("%d", &Change_option);
        if( Change_option == 1 )
        {
            int j=0;
            printf("Changing group! \n Please input the name that your want to search !\n");
            scanf( "%9s", Change_name);
            while(1)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("Please input the right group!\n");
                    scanf("%19s",&member[j].group);
                }

                if( member[j].k == 0 )
                {
                    break;
                }
                ++j;
            }
        }
        else if( Change_option == 2 )
        {
            int j=0;
            printf("Changing name! \n Please input the name that your want to search !\n");
            scanf( "%9s", Change_name );
            while(1)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("Please input the new name!\n");
                    scanf( "%19s",&member[j].name );
                }

                if( member[j].k == 0 )
                {
                    break;
                }
                ++j;
            }
        }
        else if( Change_option == 3 )
        {
            int j=0;
            printf("Changing major! \n Please input the name that your want to search !\n");
            scanf( "%9s",Change_name);
            while(1)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("Please input the right major!\n");
                    scanf("%19s",&member[j].major);
                }

                if( member[j].k == 0 )
                {
                    break;
                }
                ++j;
            }
        }
        else if( Change_option == 4 )
        {
            int j=0;
            printf("Changing Tele.! \n Please input the name that your want to search !\n");
            scanf( "%9s",Change_name);
            while(1)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("Please input the new Tele.!\n");
                    scanf("%19s",&member[j].Tele);
                }

                if( member[j].k == 0 )
                {
                    break;
                }
                ++j;
            }
        }
        else if( Change_option == 5 )
        {
            int j=0;
            printf("Changing QQ! \n Please input the name that your want to search !\n");
            scanf( "%9s",Change_name);
            while(1)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("Please input the new QQ!\n");
                    scanf("%19s",&member[j].QQ);
                }

                if( member[j].k == 0 )
                {
                    break;
                }
                ++j;
            }
        }
        else if( Change_option == 6 )
        {
            int j=0;
            printf("Changing Mail! \n Please input the name that your want to search !\n");
            scanf( "%9s",Change_name);
            while(1)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("Please input the right Mail!\n");
                    scanf("%19s",&member[j].Mail);
                }

                if( member[j].k == 0 )
                {
                    break;
                }
                ++j;
            }
        }
        else if ( option == 7)
        {
            int j=0;
            printf("Changing ID! \n Please input the name that your want to search !\n");
            scanf( "%9s",Change_name);
            while(1)
            {
                if( strcmp(  member[j].name, Change_name ) == 0 )
                {
                    printf("Please input the right ID!\n");
                    scanf("%19s",&member[j].ID);
                }

                if( member[j].k == 0 )
                {
                    break;
                }
                ++j;
            }
        }
        else
        {
            printf("Please enter the number<1-7>.");
        }
        FILE *Ptr;
        int g=0;
        Ptr = fopen("人员信息.txt", "w");
        while( g<MenNum && !feof(Ptr) )
        {

            fprintf(Ptr,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
            ++g;
            if( member[g].k == 0 )
            {
                break;
            }

        }
        fclose(Ptr);

    }
}
void Sort()
{
    int Sort_option = 0;
    printf("Enter 1 to sort by ID number !\n");
    printf("Enter 2 to sort by group\n");
    scanf("%d",&Sort_option);
    if( Sort_option == 1 )
    {
        FILE *fptr ;
        if( fptr==NULL )
        {
            printf("Can not create and open the file !\n");

        }
        else
        {
            int i=0, j=0;
            while()

            /*int i=0;
            int j=0;
            int cmp;
            int ID_SortArray[MenNum]={0};
            for( i=0; i<MenNum; ++i)
            {
                ID_SortArray[i]=i;
            }
            int  memberTemp=0;
            for( i=0; member[i].k!=0; ++i)
            {
                for( j=0; member[j].k!=0; ++j )
                {
                    cmp=strcmp(member[i].ID,member[i+1].ID);
                    if( cmp == 1)//i.ID>i+1.ID
                    {
                        memberTemp=ID_SortArray[j];
                        ID_SortArray[j]=ID_SortArray[j+1];
                        ID_SortArray[j+1]=memberTemp;//排序没排出来

                    }
                }
            }
            int m=0,Last=0;
            while( 1 )
            {
                if( member[i].k==0 )
                {
                    Last = i;
                    break;
                }
            }
            int g=0;
            fptr = fopen("学号排序.txt", "w");
            while( g<Last )
            {

                fprintf(fptr,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[ID_SortArray[g]].group,
                        member[ID_SortArray[g]].name,member[ID_SortArray[g]].major,
                        member[ID_SortArray[g]].Tele,member[ID_SortArray[g]].QQ,
                        member[ID_SortArray[g]].Mail,member[ID_SortArray[g]].ID );
                printf("%d",ID_SortArray[g] );
                ++g;
            }
            fclose(fptr);*/
        }
    }
    if( Sort_option == 2 )
    {
        FILE *fptr1;
        fptr1=fopen("按视觉组排序.txt","w");
        int g= 0;
        while( !feof(fptr1)&&g<MenNum )
        {
            if( strcmp(member[g].group,"视觉")==0 )
            {
                fprintf(fptr1,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,
                        member[g].major,member[g].Tele,
                        member[g].QQ,member[g].Mail,member[g].ID );
            }
            if( member[g].k == 0 )
            {
                break;
            }
            ++g;
        }
        fclose(fptr1);


        FILE *fptr2;
        fptr2=fopen("按机械组排序.txt","w");
        g= 0;
        while( !feof(fptr2)&&g<MenNum )
        {
            if( strcmp(member[g].group,"机械")==0 )
            {
                fprintf(fptr2,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
            }
            if( member[g].k == 0 )
            {
                break;
            }
            ++g;
        }
        fclose(fptr2);

        FILE *fptr3;
        fptr3=fopen("按电路组排序.txt","w");
        g= 0;
        while( !feof(fptr3)&&g<MenNum )
        {
            if( strcmp(member[g].group,"电路")==0 )
            {
                fprintf(fptr3,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
            }
            if( member[g].k == 0 )
            {
                break;
            }
            ++g;
        }
        fclose(fptr3);

        FILE *fptr4;
        fptr4=fopen("按嵌软组排序.txt","w");
        g= 0;
        while( !feof(fptr4)&&g<MenNum )
        {
            if( strcmp(member[g].group,"嵌软")==0 )
            {
                fprintf(fptr4,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
            }
            if( member[g].k == 0 )
            {
                break;
            }
            ++g;
        }
        fclose(fptr4);

        FILE *fptr5;
        fptr5=fopen("按运营组排序.txt","w");
        g= 0;
        while( !feof(fptr5)&&g<MenNum )
        {
            if( strcmp(member[g].group,"运营")==0 )
            {
                fprintf(fptr5,"%-2s\t%-6s\t%-8s\t%-11s\t%-11s\t%-20s\t%-10s\n",member[g].group,member[g].name,member[g].major,member[g].Tele,member[g].QQ,member[g].Mail,member[g].ID );
            }
            if( member[g].k == 0 )
            {
                break;
            }
            ++g;
        }
        fclose(fptr5);
    }



}
