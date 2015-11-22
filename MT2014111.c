#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define max 1000000
#define HASH(a2,k2,b2,m2,p) (((((a2)*(k2)) + (b2) ) % p) % (m2))
typedef struct in{
        int count1;
       long long int key;
        int id;
        }in_table;
typedef struct outer{
        int a;
        int b;
        int p5;
       long long int m;
        int count;
        in_table *next;
        }out_table;
int main()
{
    int a1,b1,l;
   long long int p1,m1,key1,oindex,iindex,i,j,k=0,w=0;
    FILE *f_i,*f_o;
    out_table *head;
    head=(out_table *)malloc(max*sizeof(out_table));
    in_table *c,*d;
    f_i=fopen("input.in","r");
    f_o=fopen("output.out","w");
    for(i=0;i<max;i++)
    head[i].next=NULL;
    m1=max;
    p1=1000171;
    srand(time(NULL));
    while(fscanf(f_i,"%lld",&key1)!=EOF)
    {oindex=HASH(1111,key1,1311,max,9876103);
     //printf("%lld\n",oindex);
     if(head[oindex].next==NULL)
     {c=(in_table *)malloc(sizeof(in_table));
      c->count1=1;
      c->key=key1;
      c->id=1;
      head[oindex].m=1;
      head[oindex].next=c;
      head[oindex].count=1;
      w++;
       head[oindex].a=rand();
        head[oindex].b=rand();
        head[oindex].p5=rand(); 
      }
      else//
      {w++;
                           iindex=HASH(head[oindex].a,key1,head[oindex].b,head[oindex].m*head[oindex].m,head[oindex].p5);
                  if(head[oindex].next[iindex].id!=1)
                  { head[oindex].next[iindex].id=1;
                    head[oindex].next[iindex].count1=1;
                    head[oindex].next[iindex].key=key1;
                    head[oindex].count=head[oindex].count+1;
                    
                    }
                    else{//oo:   
                                 l=head[oindex].m;
                               head[oindex].m=head[oindex].m+1;
                               
                                   {d=(in_table *)malloc((head[oindex].m*head[oindex].m)*sizeof(in_table));
                                oo:
                                  head[oindex].a=rand();
                           head[oindex].b=rand();   
                           head[oindex].p5=rand();
                           for(i=0;i<head[oindex].m*head[oindex].m;i++)
                                 {d[i].id=0;  
                                  d[i].key=0;
                                  d[i].count1=0;
                                  }     
                           for(i=0;i<l*l;i++)
                           { if(head[oindex].next[i].id==1)
                                {// head[oindex].next[i].id=0;
                                //  printf("isshan\n");
                                  iindex=HASH(head[oindex].a,head[oindex].next[i].key,head[oindex].b,head[oindex].m*head[oindex].m,head[oindex].p5);
                                //  printf("%lld\n",iindex);
                                  if(d[iindex].id!=1)
                                  {d[iindex].id=1;
                                   d[iindex].count1=1;
                                   d[iindex].key=head[oindex].next[i].key;
                                   }
                                   else
                                   {// printf("m=%lld , %lld \n",key1,head[oindex].m);
                                   goto oo;}
                                   }
                                   }
                                    iindex=HASH(head[oindex].a,key1,head[oindex].b,head[oindex].m*head[oindex].m,head[oindex].p5);
                       //if(key1==934618834)
                      // d[iindex].id=0;
                                    if(d[iindex].id==1)
                                    { //printf("some=%d,%lld\n",d[iindex].id,iindex);
                                                       if(d[iindex].key==key1)
                                          { d[iindex].count1=d[iindex].count1+1;
                                        //    printf("%lld , %lld \n",key1,d[iindex].key);
                                      //      getch();
                                             head[oindex].count=head[oindex].count-1;
                                            }
                                           else
                                           { //printf("%lld , %lld \n",key1,d[iindex].key);
                                            goto oo;}
                                            }
                                    else
                                    {d[iindex].key=key1;
                                     d[iindex].count1=1;
                                     d[iindex].id=1;
                                       }
                                    head[oindex].count=head[oindex].count+1;
                                    //printf("kya\n");
                                    head[oindex].next=d;
                                   
                                    }
                                  //  }
                                   // }
                                    //}
                                    }
                                    }
                                    }
                                    for(i=0;i<max;i++)
                                    {//k=k+head[i].count;
                                      for(j=0;j<head[i].m*head[i].m;j++)
                                      {if(head[i].next[j].id==1)
                                       {fprintf(f_o,"Key=%lld , OIndex=%lld, IIndex=%lld\n \n\n",head[i].next[j].key,i,j);
                                        k++;
                                       }
                                     
                                      
                                       }
                                       }
                                        for(i=0;i<max;i++)
                                       { for(j=0;j<head[i].m*head[i].m;j++)
                                       {  if(head[i].next[j].count1>1)
                                       fprintf(f_o,"Duplicate=%lld\n",head[i].next[j].key);
                                       }}
                                       
                                       fprintf(f_o,"\nTotal Keys=%lld",k);
                                       fclose(f_i);
                                       fclose(f_o);
                                       return 0;
                                    }
   
    
    
    
    
    
        
