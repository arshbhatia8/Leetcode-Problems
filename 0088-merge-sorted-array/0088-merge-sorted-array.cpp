class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        int max= m+n-1;
        int i=m-1;
        int j=n-1;
        while (i>=0 && j>=0){
            if(num2[j]>num1[i]) num1[max--]=num2[j--];
            else num1[max--]=num1[i--];
        }
        while(j>=0)num1[max--]=num2[j--];
        
    }
};