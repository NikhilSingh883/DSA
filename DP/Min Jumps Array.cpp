int Solution::jump(vector<int> &nums) {
        if(nums.size() < 2){
        return 0;
     }
      int maxi = nums[0],maxi2=0,i=0,count=0;
      while(i<nums.size()){
         count++;
          for(;i<=maxi && i<nums.size();i++){
              maxi2 = max(maxi2,i+nums[i]);
          }
         maxi = maxi2; 
         if( i>= maxi) return -1;
      }  
    return count;
}