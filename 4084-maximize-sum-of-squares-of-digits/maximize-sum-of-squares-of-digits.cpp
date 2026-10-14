class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string temp="";
        int ans=0;
        int i=0;
        if (sum > 9 * num) return "";
          while(i<num)
          {
            if(sum>=9)
            {
                temp+='9';
                sum=sum-9;
            }else{
               temp += char('0' + sum);
               sum=0;
            }
            i++;
          }
          return temp;
    }
};