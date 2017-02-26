#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
using namespace Eigen;
bool reinit(int inc[100][100],int n)
{
    int este[100];
    int da=1,i,j;
    for(i=1;i<n;i++)
            if(este[i]=inc[i][0])
    while(da)
    {
        da=0;
        for(i=1;i<n;i++)
            if(este[i]==0)
                for(j=1;j<n;j++)
                    if(inc[i][j] && este[j])
                    {
                        da=1;
                        este[i]=1;
                        break;
                    }
    }
    for(i=1;i<n;i++)
        if(este[i]==0)
            return 0;
    return 1;

}
bool cvasiviabila(int inc[100][100],int n)
{
    int este[100];
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            este[inc[i][j]]+=inc[i][j];
    for(i=1;i<=n;i++)
        if(este[i]==0)
            return 0;
    return 1;
}
bool viabila(int inc[100][100],int n, int b, int t)
{

    int iscan[100][100];
    if(b==0 ||  cvasiviabila(inc,n)==0)
        return 0;
    int este[100];
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            iscan[inc[i][j]][i]++;

    return 1;

}

void adun(int a[100],int b[100],int r[100],int n)
{
    for(int i=0;i<n;i++)
        r[i]=a[i]+b[i];
}
bool cando(int m[100], int mp[100], int s)
{
    int i;
    for(i=0;i<s;i++)
        if(m[i]+mp[i]<0)
            return 0;
    return 1;
}
bool identic(int *v1,int *v2, int s)
{

    for(int i=0;i<s;i++)
        if(v1[i]!=v2[i])
            return 0;
    return 1;
}
int omega(int *v1, int *v2, int s)
{
    int i,k=-1;
    for(i=0;i<s;i++)
    {
        if(v1[i]>v2[i])
            return 0;
        if(v2[i]>v1[i] && v2[i]!=999)
            k=i;
    }
    return k+1;
}
int addm(int m[100][100],int v[100],int &nm, int s)
{
    int i,da=1,k=nm;
    for(i=0;i<nm;i++)
        if(identic(m[i],v,s))
        {
            k=i;
            da=0;
            break;
        }
    if(da==1)
    {
        for(i=0;i<s;i++)
            m[nm][i]=v[i];
        nm++;
    }
    return k;
}
int leg[100][100];
int main()
{
    int margi=1;
    int mp[100][100]; //matricea ponderilor
    int v[100]; //marcaj initial
    int m[100][100],nm=0; //marcaje
    int s,t;
    int aux[100];
    int inc[100][100];
    int sinc;
    int sq[100][100];
    ifstream fin("date.txt");

    int i,j,k;

    fin>>s>>t>>sinc;
    for(i=0;i<t;i++)
        for(j=0;j<s;j++)
            fin>>mp[i][j];
    if(sinc)
        for(i=0;i<t;i++)
            for(j=0;j<t;j++)
                fin>>sq[i][j];

    for(i=0;i<s;i++)
        fin>>v[i];
    int blbl;
    addm(m,v,nm,s);
    int z, da;

    int k1, k2;
    for(i=0;i<nm;i++)
        for(j=0;j<t;j++)
            if(cando(m[i],mp[j],s)==1)
            {
                cout<<"m"<<i<<" - T"<<j+1;
                adun(m[i],mp[j],aux,s);
                if(sinc)
                    for(z=0;z<t;z++)
                        if(sq[j][z])
                            if(cando(m[i],mp[z],s) )
                            {
                                cout<<", T"<<z+1;
                                adun(aux,mp[z],aux,s);
                            }
                blbl=nm;
                for(z=0;z<nm;z++)
                    if(inc[z][i])
                    {
                        leg[i][z]=1;
                    }
                do
                {
                    da=0;
                    for(k1=0;k1<nm;k1++)
                        for(k2=0;k2<nm;k2++)
                        {
                            if(leg[i][k1] && !leg[i][k2] && inc[k2][k1])
                            {
                                leg[i][k2]=1;
                                da=1;
                            }
                        }
                }
                while(da);
                for(z=0;z<nm;z++)
                    if(leg[i][z])
                        while(omega(m[z],aux,s))
                        {
                            aux[omega(m[z],aux,s)-1]=999;
                            margi=0;
                        }
                k=addm(m,aux,nm,s);
                inc[i][k]=j+1;
                if(blbl==nm) cout <<" -> m"<<k<<"/";
                    else cout<<" -> m"<<blbl;
                cout<<endl;
            }

    for(i=0;i<nm;i++)
    {
        cout<<"m"<<i<<": [ ";
        for(j=0;j<s;j++)
        {
            if(m[i][j]==999)
                cout<<"w ";
            else
            cout<<m[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    /*
    for(i=0;i<nm;i++)
    {
        for(j=0;j<nm;j++)
            cout<<inc[i][j]<<" ";
        cout<<endl;
    }*/
    int bloc=0,b=1;
    if(sinc==0)
        for(i=0;i<nm;i++)
        {
            bloc=0;
            cout<<"m"<<i<<endl;
            for(j=0;j<nm;j++)
            {
                if(inc[i][j])
                {
                    cout<<"  --T"<<inc[i][j]<<"-->m"<<j<<endl;
                    bloc++;
                }
            }
            if(bloc==0)
            {
                cout<<"  BLOCAJ"<<endl;
                b=0;
            }
            //cout<<endl;
        }
    cout<<endl;
    if (margi)
        cout<<"Marginita"<<endl;
    else cout<<"Nemarginita"<<endl;
    if(reinit(inc,nm))
        cout<<"Reinitializabila";
    else cout<<"Nu este Reinitializabila";

    cout<<endl;

    if(!b)
        cout<<"Are blocaje";
    else cout<<"Nu are blocaje";
        cout<<endl;

    if(cvasiviabila(inc,nm))
        cout<<"Cvasiviabila"<<endl;
    else cout<<"Nu este Cvasiviabila";

    if(viabila(inc,nm,b,t))
        cout<<"Viabila";
    else cout<<"Neviabila";


    getch();
}
