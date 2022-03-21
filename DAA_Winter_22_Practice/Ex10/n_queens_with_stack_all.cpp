#include<iostream>
using namespace std;
#include<vector>
#include<stack>
void print_board(vector<vector<int> > board)
{
    int n,i,j;
    static int count=1;
    n = board.size();
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Completed "<<count++<<endl;
}
bool not_attacked(vector<vector<int> > &board,int row,int col)
{
 int n = board.size(),i,j;
 // check if there is a queen in the same row
 for(j=0;j<n;j++)
 {
     if((j!=col)&&(board[row][j]==1))
        return 0;
 }
 // Check if there is a queen in same column
 for(i=0;i<n;i++)
 {
     if((i!=row)&&(board[i][col]==1))
        return 0;
 }
 // both row and column increase
 for(i=row+1,j=col+1;i<n&&j<n;i++,j++)
 {
    if(board[i][j]==1)
        return 0;
}
// both row and column decrease
for(i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
{
    if(board[i][j]==1)
        return 0;
}
// row increase and column decrease
for(i=row+1,j=col-1;i<n&&j>=0;i++,j--)
{
    if(board[i][j]==1)
        return 0;
}
// row decrease and column increase
for(i=row-1,j=col+1;i>=0&&j<n;i--,j++)
{
    if(board[i][j]==1)
        return 0;
}
    return 1;
}
void n_queens(vector<vector<int> > &board, int n, int curr_row, stack<int> &pos)
{
    int i;
    // if all n-queens are placed then print board and return
    // since we only print only one solution
    if(curr_row==n)
    {
        print_board(board);
        n_queens(board,n,curr_row-1,pos);
        return;
    }
    // if stack do not have an entry for current row then start 
    // from first column
    if(pos.size()<=curr_row)
        i = 0;
    // otherwise backtrack    
    else
    {
        // try column next to previous try
        i = pos.top()+1;
        // remove queen from previous column
        board[curr_row][pos.top()] = 0;
        // remove previous entry in stack
        pos.pop();
    }
    for (;i<n;i++)
    {
        // if ith column is valid
        if (not_attacked(board,curr_row,i))
        {
            // store i in stack for current row
            pos.push(i);
            // mark in the board
            board[curr_row][i] = 1;
            // try to place queen in next row
            n_queens(board,n,curr_row+1,pos);
            //return
            return;
        }
        
    }
        // since queen cannot be placed in current row
        // backtrack to previous row
            if(curr_row>0)
                n_queens(board,n,curr_row-1,pos);
 
}
int main()
{
    int n,i,j;
    cin>>n;
    vector<int> row(n,0);
    vector<vector<int> >  board(n, row);
    stack<int> pos;
    n_queens(board,n,0,pos);

}
