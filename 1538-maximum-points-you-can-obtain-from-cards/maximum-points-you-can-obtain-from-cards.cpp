class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     int n=cardPoints.size();

     int leftSum=0;
     int rightSum=0;
     int maxSum=0;

     for(int i=0;i<k;i++){
        leftSum+=cardPoints[i];
        maxSum=max(maxSum,leftSum);
     }
     int rightIndex=n-1;
     for(int i=k;i>0;i--){
        leftSum-=cardPoints[i-1];
        rightSum+=cardPoints[rightIndex];
        rightIndex--;
        maxSum=max(maxSum,leftSum+rightSum);
     }
     return maxSum;
    }
};