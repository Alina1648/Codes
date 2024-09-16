#include<iostream>
using  namespace std;
class A
{
public:
 int num1=20,num2=10;
 void fun()
 { int sum= num1+ num2;
 cout<<"addition"<<sum<<endl;
 }
 void fun( int a,int b)
 { int sub=a-b;
 cout<<"substraction"<<sub<<endl;
 }
};
int main()
{A obj;
obj.fun();
obj.fun(5,3);
return 0;
}