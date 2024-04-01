// didnt understand top solution with pointers - too tred


class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),ans=0;
        n/=2;
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        nums1.erase(unique(nums1.begin(),nums1.end()),nums1.end());
        nums2.erase(unique(nums2.begin(),nums2.end()),nums2.end());

        int l=0,m=0,r=0;
        int ptr1=0,ptr2=0;
        while(ptr1<nums1.size() || ptr2<nums2.size()){
            if(ptr1>=nums1.size()){
                r++;
                ptr2++;
            }
            else if(ptr2>=nums2.size()){
                l++;
                ptr1++;
            }
            else{
                if(nums1[ptr1]==nums2[ptr2]){
                    m++;
                    ptr1++;
                    ptr2++;
                }
                else if(nums1[ptr1]<nums2[ptr2]){
                    l++;
                    ptr1++;
                }
                else{
                    r++;
                    ptr2++;
                }
            }
        }
        // cout<<l<<' '<<m<<' '<<r<<endl;
        l=min(n,l);
        r=min(n,r);
        // cout<<l<<' '<<m<<' '<<r<<endl;
        ans=l+r;
        ans+=min(m,n-l);
        m-=min(m,n-l);
        ans+=min(m,n-r);
        m-=min(m,n-r);
        return ans;
    }
};
