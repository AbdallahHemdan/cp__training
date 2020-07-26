#include<iostream>
#include<cstdio>
#include<vector>
#define NO_NODES 100000
using namespace std;
vector<int> adj[NO_NODES+1];
//int adjlist[NO_NODES+1][NO_NODES+1];
void dfs(int at,int par,int curh,int *height,int *size,int *parent)
{
	parent[at]=par;
	height[at]=curh;
	vector<int>::iterator it;
	it=adj[at].begin();
	size[at]=1;
	while(it!=adj[at].end())
	{
	    if((*it)!=par)
	    {
            dfs((*it),at,curh+1,height,size,parent);
            size[at]+=(size[(*it)]);
	    }
		it++;
	}
	return;
}
void heavylightdecompose(int at,int par,int *size,int *heavypath,int *headheavypath)
{
    heavypath[at]=0;
    vector<int>::iterator it;
    it=adj[at].begin();
    while(it!=adj[at].end())
    {
        if((*it)!=par)
        {
            heavylightdecompose((*it),at,size,heavypath,headheavypath);
        }
        it++;
    }
    if(par==0)
        return;
    if(size[at]>size[par]/2)
    {
        if(heavypath[at]!=0)
        {
            heavypath[par]=heavypath[at];
            headheavypath[heavypath[par]]=par;
        }
        else
        {
            heavypath[at]=at;
            heavypath[par]=at;
            headheavypath[at]=par;
        }
    }
    return;
}
void printarray(int *array,int n)
{
	int i=1;
	while(i<=n)
	{
		cout<<i<<":"<<array[i]<<" ";
		i++;
	}
	cout<<endl<<endl;
}
int lca(int a,int b,int *heavypath,int *headheavypath,int *parent,int *height)
{
        while(heavypath[a]!=heavypath[b])
        {
            if(height[headheavypath[heavypath[a]]]<height[headheavypath[heavypath[b]]])
            {
                b=parent[headheavypath[heavypath[b]]];
            }
            else
            {
               a=parent[headheavypath[heavypath[a]]];
            }
        }
        if(height[a]<height[b])
            return a;
        return b;
}
int main()
{
    int t,T;
    //cin>>T;
    scanf(" %d",&T);
    t=1;
    while(t<=T)
    {
        int j,n,parent[NO_NODES+1]={0},height[NO_NODES+1],i,heavypath[NO_NODES+1],size[NO_NODES+1],headheavypath[NO_NODES+1];
        int a,b;
        //cin>>n;
        scanf(" %d",&n);
        int root,tnos,k;
        i=1;
        while(i<=n)
        {
            adj[i].clear();
            i++;
        }
        i=1;
        while(i<n)
        {
            scanf(" %d %d",&a,&b);
      //      cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            i++;
        }
        root=1;
        //----------------------HLD----------------------------------------
        dfs(root,0,0,height,size,parent);
        heavylightdecompose(root,0,size,heavypath,headheavypath);
        for(i=1;i<=n;i++)
        {
            if(heavypath[i]==0)
            {
                heavypath[i]=i;
                headheavypath[i]=i;
            }
        }
        //-----------------HLD OVER-------------------------------------------
        int q,lca_ab,dist,timereq;
       scanf(" %d",&q);
       //cin>>q;
        i=0;
        while(i<q)
        {
           scanf(" %d %d",&a,&b);
         // cin>>a>>b;
          //  printf("%d\n",lca(a,b,heavypath,headheavypath,parent,height));;
          lca_ab=lca(a,b,heavypath,headheavypath,parent,height);
          dist=height[a]+height[b]-2*height[lca_ab];
          if(lca_ab==a)
          {
                timereq=2*dist-1;
          }
          else if(lca_ab==b)
          {
                timereq=2*dist;
          }
          else
          {
                timereq=2*dist-1;
          }
          //cout<<"LCA : "<<lca_ab<<" distance "<<dist<<" time req : ";
          //cout<<timereq<<endl;
          printf("%d\n",timereq);
            i++;
        }
        t++;
    }
	return 0;
}
