class Solution {
public:
// Find's Maxium Element/Absoulte Peak Element index in Column
int maxElementInColumn(vector<vector<int>>& mat,int col,int rowNo)
{
    int maxEleIdx=0;
    for(int i=0;i<rowNo;i++)
    {
        maxEleIdx=mat[i][col] > mat[maxEleIdx][col] ? i:maxEleIdx; 
    }
    return maxEleIdx;
}
// Find's If WE have to Meve LEft Side or Not??
bool Move_LeftSide(vector<vector<int>>& mat,int midCol,int n,int rightCol)
{
    // Let's Get The Max Column Element Row
    int maxElementInCol_rowIdx=maxElementInColumn(mat,midCol,n);

    // Compare with Mid+1 -> Peak Element Logic
    // Before that check it's Column Range (leftCol<=midCol+1<=rightCol)
    // if it is in range& midcol > midCol+1 then return true as we want to move left side
    return (midCol+1<=rightCol) && (mat[maxElementInCol_rowIdx][midCol] >mat[maxElementInCol_rowIdx][midCol+1]);
    //       Range Check        &&          Peak Element Condition / Move Left Condition
}


    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // UsingBinary Search Concept Select a Random Column using Mid
        int n=mat.size();
        int m=mat[0].size();
        // leftCol= first Column
        int leftCol=0;
        // rightcol= last Column
        int rightCol=m-1;

        while(leftCol<rightCol)
        {
            // Find Middle Column/Random Column/Searching Column
            int midCol= leftCol + (rightCol-leftCol)/2;

            // Check Which Side to Move
            // Left Side?(Include Mid)
            if(Move_LeftSide(mat,midCol,n,rightCol))
            {
                rightCol=midCol;
            }
            // Move Right Side(Exclude mid)
            else
            leftCol=midCol+1;
        }
        // Our left Column Holds Our Answer
        // But Which Row?? ->Max Element Present Row
        int peakRowInLeftCol=maxElementInColumn(mat,leftCol,n);

        return vector<int> {peakRowInLeftCol,leftCol};
    }
};