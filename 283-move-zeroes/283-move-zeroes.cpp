class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int len = nums.size();
      int fp = 0;
 
      if(len < 2 )
          return;
        
      while( fp < len && nums[fp] != 0 )
         fp++;
      
      cout << fp << endl;
               
      for( int i = fp; i < len; i++ )
      {
        if( nums[i] != 0 )
        {    
           nums[fp++] = nums[i];
           nums[i] = 0;
        }              
      }
    
    }
};