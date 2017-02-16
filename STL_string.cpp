    #include<bits/stdc++.h>
    #define lli long long int
    #define slli(a) scanf("%lld",&a)
    #define si(a) scanf("%d",&a)
    #define f(i,a,b) for(i=a;i<b;i++)
    using namespace std;
    int main()
    {
    	string str;
    	int c,i,j,k,m,n,t,l,flag,count,freq[10],score[105],m_i,Max;
    	si(t);
    	while(t--)
    	{
    		si(n);
    		f(i,0,n)
    		{
    			si(m);
    			f(j,1,7)
    			freq[j]=0;
     
    			f(j,0,m)
    			{
    				si(c);
    				freq[c]++;
    			}
     
    			count=0;
                while(1)
                {
                    count=0;
                    f(j,1,7)
                    {
                    if(freq[j]!=0)
                        count++;

                    if(freq[j]!=0)
                    freq[j]--;
                    
                    }

                    if(count == 4)
                      score[i]+=1;
                    if(count == 5)
                      score[i]+=2;
                    if(count == 6)
                      score[i]+=4;
                    if(count<4)
                      break;
                }
                
    		}
     
    		Max=-1;
    		
    		f(i,0,n)
    		{
    			if(score[i]>Max)
    			{
    				Max=score[i];
    				m_i=i;
    			}
    		}
    		
    		flag=0;
     
    		f(i,0,n)
    		{
    			if(score[i]==Max && i!=m_i)
    			{
    				flag=1;
    				break;
    			}
    		}
    		
            if(flag==1)
    			cout<<"tie"<<endl;

    		else if(m_i==0)
    			cout<<"chef"<<endl;
    		
            else 
    			cout<<m_i+1<<endl;
     
    	}
    } 