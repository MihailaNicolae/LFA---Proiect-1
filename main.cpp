#include <iostream>
#include <cstring>
using namespace std;
struct {int val; char litera;} a[100][100];
int n,ok,nr_muchii,p,u,c[100],terminat,stare_init,nr_teste,nr_stari_fin,fin[100];
char cuvant[200];
int main()
{   cin>>n>>nr_muchii;
    for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++)
            a[i][j].val=0;
    for(int o=1;o<=nr_muchii;o++)
    {   int i,j;
        cin>>i>>j;
        a[i][j].val=1;
        cin>>a[i][j].litera;
    }
    p=u=1;
    cin>>stare_init;
    cin>>nr_stari_fin;
    int aux;
    for(int i=1;i<=nr_stari_fin;i++)
    {   cin>>aux;
        fin[aux]=1;
    }
    cin>>nr_teste;
    cin.get();
    for(int t=1;t<=nr_teste;t++)
    {   cin.getline(cuvant,200);
        p=u=1;
        c[1]=stare_init;
        terminat=0;
        while(terminat!=1)
        {   ok=0;
            if(strlen(cuvant)==0 && fin[c[p]]==1)
            {   cout<<"DA"<<'\n'<<"Traseu: ";
                for(int i=1;i<=p;i++)
                    cout<<c[i]<<' ';
                cout<<'\n';
                terminat=1;
            }
            else
                for(int i=0;i<=n;i++)
                    if(a[c[p]][i].val==1 && a[c[p]][i].litera==cuvant[0])
                    {   strcpy(cuvant,cuvant+1);
                        p++;
                        c[p]=i;
                        ok=1;
                    }
            if(ok==0 && terminat!=1)
            {   cout<<"NU"<<'\n';
                strcpy(cuvant,"");
                terminat=1;
            }
        }
    }
    return 0;
}
