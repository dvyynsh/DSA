class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int MaxArea = 0;

        while(left < right){
            // Area=min(height[left],height[right])×(right−left)
            int Area = min(height[left],height[right])*(right-left);

            // we trye to eliminate the smaller height because of water you know it doesn't hold much water
            // I know width will decrease after getting closer but yeaa we are gaining Height 
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }

            MaxArea = max(MaxArea, Area);
        }

        return MaxArea;
        
    }
};