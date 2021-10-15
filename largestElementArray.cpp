/*Program to find largest element in an array

 Example : 
 Size : 4
 Array Elements :  2 4 5 10
 Output :   10
 10 largest element in array .

*/
#include<iostream>
using namespace std;


int largestElement(int Array[], int Size){

    int Max =Array[0];  // temporary variable Max to store first element inside index 0

    for(int i=0;i<Size;i++){

        if(Max<Array[i]){         // checking for elements larger than Max varibale

            Max=Array[i];         // Then assign the largest element in Max;
        }
    }
    return Max; // return the value of largest element back to main

}

int main(){
     int  Size;
    cout<<"Enter the size the array: ";
    cin>>Size;
    int Array[Size];               // array of default size 100
    cout<<"Enter array element ";

    for(int i=0;i<Size;i++){
                                // Enter the array elements
        cin>>Array[i];
    }

 cout<<largestElement(Array,Size);

 return 0;
}
