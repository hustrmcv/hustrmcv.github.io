//author :ChenWellesCxy
//purpose : saddle point
#include <iostream>
#include<cstdio>
using namespace std;
#define ROWS 5
#define COLS 5

int main()
{
    int max_of_row[COLS], min_of_col[ROWS];
    int Mat[ROWS][COLS];

    cout<<"Please input the matrix in which you want to search for saddle point\n";

    for( int i = 0; i<ROWS; ++i )
    {
        for( int j = 0; j<COLS; ++j)
        {
            cin>>Mat[i][j];
        }

    }
    cout<<endl;
    for( int i = 0; i<ROWS; ++i )
    {
        max_of_row[i] = Mat[i][0];

        for( int j = 0; j<COLS-1; ++j )
        {

            if( max_of_row[i]<Mat[i][j+1] )
            {
                max_of_row[i]=Mat[i][j+1];
            }
        }
    }

    for( int i = 0; i<COLS; ++i )
    {
        min_of_col[i] = Mat[0][i];

        for( int j = 0; j<ROWS-1; ++j )
        {

            if( min_of_col[i]>Mat[j+1][i] )
            {
                min_of_col[i]=Mat[j+1][i];
            }
        }
    }
    int jug=0;
    for( int i = 0; i<ROWS; ++i )
    {
        for( int j = 0; j<COLS; ++j)
        {
            if( Mat[i][j] == max_of_row[i]&& Mat[i][j] == min_of_col[j] )
            {
                cout<<i+1<<" "<<j+1<<" "<<Mat[i][j];
                ++jug;
            }
        }
    }
    if( jug==0 )
    {
        cout<<"There is not a saddle in the matrix";
    }


    return 0;
}
