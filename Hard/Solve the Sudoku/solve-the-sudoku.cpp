//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
        bool isValid(int row,int col,int num,int grid[N][N])
    {
        // Check 3 Conditions
        // Row has Only 1 Num
        for(int i=0;i<9;i++)
        {
            // Row & Column Condition
            if(grid[row][i]==num || grid[i][col]==num)
            return false;
            // 3x3 Sub-Grid
            int m=(row/3)*3 + i/3;
            int n=(col/3)*3 + i%3;
            if(grid[m][n]==num)
            return false;
        }
        return true;
    }
    bool findEmptySpace(int grid[N][N])
    {
        // 1.Traverse Whole Matrix
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                // 2.If Empty Space Found
                if(grid[i][j]==0)
                {
                    // A.Try All Digits from 1-9
                    for(int num=1;num<=9;num++)
                    {
                        // a.Check if Valid or Not
                        if(isValid(i,j,num,grid))
                        {
                            // i.If it is Valid then Put the Number
                            grid[i][j]=num;
                            // ii.Call for Next Empty Space(if all empty Space filledProperly then Directly Return true)
                            if(findEmptySpace(grid))
                            return true;
                            // iii.Else try Next Number
                            // Backtracks
                            else
                            grid[i][j]=0;
                        }
                    }
                    // b.If no Number is Matched then Return false as the Cell cannot be filled so suduko cannot be solved
                    return false;
                }
            }
        }
        // 3.All vacent Spaces ar filled 
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return findEmptySpace(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<9;i++)
        {
        for(int j=0;j<9;j++)
        cout<<grid[i][j]<<" ";

        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends