
OOP Assignment 05
Title: - Write a function template selection Sort. Write a program that inputs, sorts and outputs
an int array and a float array.
****************************************************************************/
//Program-
#include<iostream>
using namespace std;
#define size 10
int n;
template<class T>
void selection(T A[size])
{
int i,j,min;
T temp;
for(i=0;i<=n-2;i++)
{
min=i;
for(j=i+1;j<=n-1;j++)
{
if(A[j]<A[min])
min=j;
}
temp=A[i];
A[i]=A[min];
A[min]=temp;
}
cout<<"\nSorted list=\n";for(i=0;i<n;i++)
cout<<"\t"<<A[i];
}
int main()
{
int i,A[size];
float B[size];
cout<<"Selection sort\n";
cout<<"\nInteger Element\n";
cout<<"Enter how many elements you want\n";
cin>>n;
cout<<"\nEnter the Integer element\n";
for(i=0;i<n;i++)
cin>>A[i];
selection(A);
cout<<"\nFloat Element\n";
cout<<"Enter how many elements you want\n";
cin>>n;
cout<<"\nEnter float element\n";
for(i=0;i<n;i++)
cin>>B[i];
selection(B);
return 0;
}
/*Output:-
student@student-OptiPlex-3010:~$ g++ FinalPract B2.cpp
student@student-OptiPlex-3010:~$ ./a.out
Selection sort
Integer Element
Enter how many elements you want
5Enter the Integer element
7
5
8
9
3
Sorted list=
3 5 7 8 9
Float Element
Enter how many elements you want
5
Enter the float element
3.8
9.4
5.5
2.2
6.7
Sorted list=
2.2 3.8 5.5 6.7 9.4
