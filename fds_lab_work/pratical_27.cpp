
#include <iostream>
#include <stack>
using namespace std;
int priority (char alpha)
{
if(alpha == '+' || alpha =='-')
return 1;
if(alpha == '*' || alpha =='/')
return 2;
return 0;
}
//--------------------------------------------------
string convert(string infix)
{
int i = 0;
string postfix ;
stack <int>s;
while(infix[i]!='\0')
{
if(infix[i]>='0' && infix[i]<= '9')
{
postfix += infix[i];
i++;
}
else if(infix[i]=='(')
{
s.push(infix[i]);
i++;
}
else if(infix[i]==')')
{
while(s.top()!='(')
{
postfix += s.top();
s.pop();
}
s.pop();
i++;
}
else
{
while (!s.empty() && priority(infix[i]) <= priority(s.top())){
postfix += s.top();
s.pop();
}
s.push(infix[i]);

i++;
}
}
while(!s.empty()){
postfix += s.top();
s.pop();
}
cout << "Postfix is : " <<postfix;
return postfix;
}
//-----------------------------------------------------------------------
int evaluate(string postfix)
{
stack<int> st;
int temp;
char c;
for (int i = 0; i < postfix.length(); i++)
{
c = postfix[i];
if (c >= '0' && c <= '9')
{
temp = (int)(c - '0');
st.push(temp);
}
else
{
int op1 = st.top();
st.pop();
int op2 = st.top();
st.pop();
switch(c)
{
case '+':
st.push(op2 + op1);
break;
case '-':
st.push(op2 - op1);
break;
case '*':
st.push(op2 * op1);
break;
case '/':
st.push(op2 / op1);
break;
}
}
}
return st.top();
}
//---------------------------------------------------------------------
int main()

{
string infix ;
string postfix;
cout<<"\n\t ENTER INFIX EXPRESSION: ";
cin>>infix;
postfix = convert(infix);
float x=evaluate(postfix);
cout<<"\n\n\tPOSTFIX EVALUATION RESULT : "<<x;
return 0;
}
