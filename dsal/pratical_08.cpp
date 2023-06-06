// Given sequence k = k1 <k2 < ... <kn of n sorted keys, with a search probability pi for
// each key ki . Build the Binary search tree that has the least search cost given the access probability for each
// key?
#include <iostream>
#define S 20
using namespace std;
class OBST
{
    int p[S];
    int q[S];
    int a[S];
    int w[S][S];
    int n;
    int c[S][S];
    int r[S][S];


public:
    void get_data()
    {
        int i;
        cout << "Optimal Binary Search Tree : " << endl;
        cout << "Enter the number of nodes : " << endl;
        cin >> n;
        cout << "\n Enter the data :" << endl;
        for (i = 1; i <= n; i++)
        {
            cout << "\n a[" << i << "] ";
            cin >> a[i];
        }
        for (i = 1; i <= n; i++)
        {
            cout << "\n p[" << i << "] ";
            cin >> p[i];
        }
        for (i = 1; i <= n; i++)
        {
            cout << "\n q[" << i << "] ";
            cin >> q[i];
        }
    }
    int Min(int i,int j)
    {
        int m,k;
        int minimum=10000000;
        for(m=r[i][j-1];m<=r[i+1][j];m++)
        {
            if((c[i][m-1]+c[m][j])<minimum)
            {
                minimum=c[i][m-1]+c[m][j];
                k=m;
            }
        }
        return k;
    }
    void build_OBST()
    {
        int i,j,k,l,m;
        for(i=0;i<n;i++)
        {
            w[i][i]=q[i];
            r[i][i]=c[i][i]=0;
            w[i][i+1]=q[i]+p[i+1]+q[i+1];
            r[i][i+1]=i+1;
            c[i][i+1]=q[i]+p[i+1]+q[i+1];
        }
        w[n][n]=q[n];
        r[n][n]=c[n][n]=0;
        for(m=2;m<=n;m++)
        {
            for(i=0;i<=n-m;i++)
            {
                j=i+m;
                w[i][j]=w[i][j-1]+p[j]+q[j];
                k=Min(i,j);
                c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
                r[i][j]=k;
            }
        }
    }
    void build_tree()
    {
        int i,j,k;
        int queue[20],front=-1,rear=-1;
        cout<<"The optimal binary search tree for the given node is "<<endl;
        cout<<"The root of the OBST is : "<<r[0][n];
        cout<<"The cost of the OBST is : "<<c[0][n];
        cout<<"\n\n\t NODE \t LEFT CHILD \tRIGHT CHILD ";
        cout<<endl;
        queue[++rear]=0;
        queue[++rear]=n;
        while(front!=rear)
        {
            i=queue[++front];
            j=queue[++front];
            k=r[i][j];
            cout<<"\n\t"<<k;
            if(r[i][k-1]!=0)
            {
                cout<<"\t\t "<<r[i][k-1];
                queue[++rear]=i;
                queue[++rear]=k-1;

            }
            else
                cout<<"\t\t";
            if(r[k][j]!=0)
            {
                cout<<"\t "<<r[k][j];
                queue[++rear]=k;
                queue[++rear]=j;
            }
            else
                cout<<"\t";
        }
        cout<<endl;
    }
};
int main()
{
    OBST o;
    o.get_data();
    o.build_OBST();
    o.build_tree();
    return 0;
}