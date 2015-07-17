
int getMaxElement(int arr[]){

    static int i=0,max =-9999;

    if(i < size){
         if(max<arr[i])
           max=arr[i];
      i++;
      getMaxElement(arr);
    }

    return max;
}
