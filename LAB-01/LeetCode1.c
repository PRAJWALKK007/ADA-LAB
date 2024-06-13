int removeDuplicates(int nums[], int numsSize) {
    if(numsSize==0)
        return 0;
    int a=1,i;
    for (i=1;i<numsSize;i++) 
    {
        if(nums[i]!=nums[i-1]) 
        {
            nums[a]=nums[i];
            a++;
        }
    }
    return a;
}
