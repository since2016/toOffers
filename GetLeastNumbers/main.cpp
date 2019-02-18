#include <iostream>
#include <vector>
#include <set>
using namespace std;
int Partition(vector<int>& nums, int start, int end){
    int left = start;
    int right = end;
    int key = nums[start];
    while(left<right){
        while (left<right && nums[right] >= key)
            right--;
        while (left<right && nums[left] <= key)
            left++;
        if(left<right){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right]= temp;
        }
    }
    nums[start] = nums[left];
    nums[left] = key;
    return left;
}
void GetLeastKNumbers(vector<int>& nums, int k){
    if(nums.size() ==0 || k<0 || k>nums.size())
        return;
    int start = 0;
    int end = nums.size()-1;
    int index = Partition(nums,start, end);
    while (index != k){
        if(index > k){
            end = index -1;
            index = Partition(nums,start,end);
        } else{
            start = index+1;
            index = Partition(nums, start, end);
        }
    }
    for (int i = 0; i < k; ++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void GetKLeastNumbersBySet(vector<int>& nums, int k){
    multiset<int, greater<int>> int_set;
    multiset<int, greater<int>>::iterator int_set_iterator;
    if(k<1||nums.size()<k)
        return;
    vector<int>::iterator data_iter = nums.begin();
    for (; data_iter < nums.end(); ++data_iter) {
        if(int_set.size()<k)
            int_set.insert(*data_iter);
        else{
            int_set_iterator = int_set.begin();
            if(*data_iter < *(int_set_iterator)){
                int_set.erase(int_set_iterator);
                int_set.insert(*(data_iter));
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
int main() {
    vector<int> nums1 = {};
    int k1 = 0;
    int k2 = 3;
    int k3 = 5;
    vector<int> nums2 = {32,32,13,23,12,31,12,4232};
    vector<int> nums3 = {12,34,43,45,56,67,13};
    GetLeastKNumbers(nums1,k1);
    GetLeastKNumbers(nums1,k2);
    GetLeastKNumbers(nums2,k2);
    GetLeastKNumbers(nums3,k3);


    GetKLeastNumbersBySet(nums1,k1);
    GetKLeastNumbersBySet(nums1,k2);
    GetKLeastNumbersBySet(nums2,k2);
    GetKLeastNumbersBySet(nums3,k3);
    return 0;
}