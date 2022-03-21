#include<iostream>
using namespace std;
#include<vector>
#include<stack>
// https://liujoycec.github.io/2015/09/20/n_queens_symmetry/
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
void print_stack(stack<int> pos)
{
    while(!pos.empty())
    {
        cout<<pos.top()<<" ";
        pos.pop();
    }
    cout<<endl;
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
bool stack_equal(stack<int> soln,stack<int> curr)
{
    stack<int> reverse;
 
    while(!soln.empty())
    {
        reverse.push(soln.top());
        soln.pop();
    }
    while(!reverse.empty())
    {
 
        if(reverse.top()!=curr.top())
            return false;
        reverse.pop();
        curr.pop();
    }

    return true;
}
bool stack_mirror(stack<int> soln, stack<int> curr)
{
    int n = soln.size();
    while(!soln.empty())
    {
        if((soln.top()!=(n-curr.top()-1))&&((n-soln.top()-1)!=curr.top()))
            return false;
        soln.pop();
        curr.pop();
    }
    return true;
}
bool solution_already_seen(vector<stack<int> >& solutions,stack<int> pos)
{
    int i,j;
    bool equal=true;

    for(i=0;i<solutions.size();i++)
    {
       if(stack_equal(solutions[i],pos))
        return true;
       if (stack_mirror(solutions[i],pos))
        return true;
    }
    return false;
}
void n_queens(vector<vector<int> > &board, int n, int curr_row, stack<int> &pos,vector<stack<int> >&solutions)
{
    int i;
    bool backtrack=true;
    if(curr_row<0)
        return ;
    if(curr_row==n)
    {
        
        if(solutions.size()==0)
        {
            print_board(board);
            print_stack(pos);
            solutions.push_back(pos);
        }
        else if(!solution_already_seen(solutions,pos))
        {
            print_board(board);
            print_stack(pos);
            solutions.push_back(pos);
        }
        n_queens(board,n,curr_row-1,pos,solutions);
        return;
    }
    if(pos.size()<=curr_row)
        i = 0;
    else
    {

        i = pos.top()+1;
        board[curr_row][pos.top()] = 0;
        pos.pop();
    }
    for (;i<n;i++)
    {
        if (not_attacked(board,curr_row,i))
        {
            backtrack = false;
            pos.push(i);
            board[curr_row][i] = 1;
            n_queens(board,n,curr_row+1,pos,solutions);
            return;
        }
        
    }
    if(backtrack)
    {
   //         cout<<"Backtrack"<<endl;
            n_queens(board,n,curr_row-1,pos,solutions);
    }
}
int main()
{
    int n,i,j;
    cin>>n;
    vector<int> row(n,0);
    vector<vector<int> >  board(n, row);
    vector<stack<int> > solutions;
    stack<int> pos;
    n_queens(board,n,0,pos,solutions);
   // print_board(board);
}
