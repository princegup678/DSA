#include <bits/stdc++.h>
using namespace std;
vector<bool> sieve(int n)
{
    
    //int n=100000000;
    vector<bool> v(n+1,true);
    v[0]=v[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(v[i]&&i%2==1)
        for(int j=i*i;j<=n;j+=i)
        {
            v[j]=false;
        }
    }
    return v;
}
vector<int> makelistpr(vector<bool> *v)
{
    vector<int> prime;
    prime.push_back(2);
    for(int i=3;i<=(*v).size();i+=2)
    {
        if((*v)[i])
        prime.push_back(i);
        
    }
    /*
    for(int i=0;i<15;i++)
    cout<<prime[i]<<endl;
    */
    return prime;
}

vector<int> multiples(vector<int> prime)
{
	vector<int> v;
    vector<int>::iterator ptr;
    vector<int>::iterator ptr1;
	int k=2000000;
    //v[0]=v[1]=false;
    int siz=(prime).size();
    for(ptr=prime.begin();ptr!=prime.end();ptr++)
    {
    	for(ptr1=ptr+1;ptr1!=prime.end()-1;ptr1++)
    	{
		    int l=(*ptr)*(*ptr1);
    		v.push_back(l);
		}
    	
    }
   //sort(v.begin(),v.end());
    /*
    for(ptr=v.begin();ptr!=v.begin()+10;ptr++)
    cout<<*ptr<<endl;
    */
    return v;
}

vector<int> createmulti(vector<bool> *v)
{
	//int siz=100000000+1;
    vector<int> mult;
    int k=0;
    int siz=(*v).size();
    for(int i=1;i<siz;i++)
    {
        if((*v)[i]&&k<20000005)
        {
        mult.push_back(i);
        k++;
		}
		else break;
        
    }
    return mult;
	
}

int main()
{
    int n=100000,t;
    vector<bool> v=sieve(n);
    vector<int> prime=makelistpr(&v);
    
    cout<<"h1"<<prime.size();
    vector<int> multi=multiples(prime);
    vector<int>::iterator ptr;
    //vector<bool> nums=multiples(&prime);
    //cout<<"h1";
    //vector<int> multi=makelistpr(&nums);
    cout<<"h1"<<multi.size();
    int k;
    cin>>t;
    ptr=multi.begin();
    while(t--)
    {
    	cin>>k;
    	cout<<*(ptr+k-1)<<endl;
    	
    	
    }
    

    return 0;
}

