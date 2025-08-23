
class Solution {
    public ArrayList<Integer> sumTriangles(int mat[][]) {
        // code here
        int upperSum=0,lowerSum=0,digSum=0;
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[0].length;j++){
                if(i<j){
                    upperSum+=mat[i][j];
                }
                else if(i>j){
                    lowerSum+=mat[i][j];
                }
                else{
                    digSum+=mat[i][j];
                }
            }
        }
        ArrayList ans=new ArrayList<>();
        ans.add(upperSum+digSum);
        ans.add(lowerSum+digSum);
        return ans;
    }
}