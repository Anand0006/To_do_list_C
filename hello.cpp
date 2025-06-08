#include <iostream>
using namespace std;

int main(){
 int arry[] = {10,20,30,40,50};

int n = sizeof(arry)/sizeof(arry[0]);

int largest = INT_MIN;
int secondlargest = INT_MIN;

for (int i = 0; i <n; i++)
{
    if (arry[i]>largest)
    {
        secondlargest = largest;
        largest = arry[i];
    }else if (arry[i]>secondlargest && arry[i]!= largest)
    {
            secondlargest = arry[i];
    }
    
    
}
if (secondlargest == INT_MIN)
{
    cout<<"There is no distinct second largest number"<<endl;
}else{
    cout<<"THE Second largest number is : "<< secondlargest << endl;
}

return 0;
}
