class Solution {
public:
    int maxArea(vector<int>& height) {
           int ar=0,mar=0;
           int a=0; 
           int b=height.size()-1;

           while (a<b){
            ar=min(height[a],height[b])*(b-a);
            if (height[a] < height[b])
               a++;
             else
               b--;
            mar=max(ar,mar);
           }
           return mar;
    }
};