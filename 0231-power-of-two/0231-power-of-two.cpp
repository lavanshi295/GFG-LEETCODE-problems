class Solution {
public:
    bool isPowerOfTwo(int n) {
          if(n==1)
        return true;


        if(n%2!=0)
        return false;
       

    while(n)

       {
            n=n/2;
             if(n==1)
            return true;
            if(n%2!=0)
            return false;
        }
        return false;
    }
};