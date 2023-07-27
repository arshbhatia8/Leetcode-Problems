class Solution {
public:
    bool check(long long sm,long long mid,vector<int>&batteries,int n){
        long long carry=0;
        int cnt=0;
        long long vd=0;
        int i=0;
        for(i=0;i<batteries.size();i++){
            vd+=max(0ll,mid-batteries[i]);     
            cnt++;
            if(cnt==n)break;
        }
       long long pf=0;
        for(int j=i+1;j<batteries.size();j++){
            pf+=batteries[j];
        }
        if(pf>=vd){
        return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sm=0ll;
        for(int i=0;i<batteries.size();i++){
            sm+=batteries[i];
        }
        sort(batteries.rbegin(),batteries.rend());
        long long low=0,hgh=sm;
        long long ans=-1;
        while(low<=hgh){
            long long mid=(low+hgh)/2;
            if(!check(sm,mid,batteries,n)){
                hgh=mid-1;
            }
            else {
                ans=mid;
                low=mid+1;
            }

        }
        return ans;
    }
};