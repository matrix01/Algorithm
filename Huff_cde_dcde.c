#include<iostream.h>
#include<stdio.h>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<conio.h>

struct tree
{
 char a[20];
 int s;
 struct tree *left,*right;
}*root=NULL,*tt[20]={NULL},*temp,*temp2,*t2,*ri,*le;
struct pqu
 {
	int info;
       char a[20];
       struct pqu *ptr;
  }*front=NULL,*t,*par,*t1,*p1,*p2;
 struct pqu* fp(int info)
   {
    struct pqu *p=NULL;
    for(t1=front;t1->info<info&&t1!=NULL;t1=t1->ptr)
    {
      p=t1;
    }
      return (p);

  }
 void enqu(char a[20],int p)
 {
    t=(struct pqu*)malloc(sizeof(struct pqu));
    strcpy(t->a,a);
    t->info=p;
    t->ptr=NULL;
    if(front==NULL)
    {
      front=t;
    }
   else
    {
     par=fp(p);
     if(par==NULL)
     {
       t->ptr=front;
       front=t;
     }
     else
       {
	 t->ptr=par->ptr;
	 par->ptr=t;
       }
    }
  }

  struct pqu* dequ()
 {
     t1=front;
     front=front->ptr;
    return t1;
 }
 void info(char c[2])
 {
       int m=0,i;
       temp2=root;
       while(strcmp(c,temp2->a)!=0)
       {
	 t2=temp2->left;
	 for(i=0;i<strlen(t2->a);i++)
	 {
	    if(t2->a[i]==c[0])
	    {
	      temp2=temp2->left;
	      m=1;
	     cout<<"0";
	     break;
	    }
	  }
	 if(m!=1)
	  {
	    temp2=temp2->right;
	    cout<<1;
	  }
	   m=0;
	}
  }


 void insert()
 {
   char a1[20],b1[20],v1[20];
   int i,j,z=0,l;
   while(front!=NULL)
   {
     p1=dequ();
    strcpy(a1,p1->a);
    l=p1->info;
   p2=dequ();
    if(p2==NULL)
     break;
    strcpy(b1,p2->a);
   strcpy(v1,a1);
   temp=(struct tree*)malloc(sizeof(struct tree));
   strcpy(temp->a,strcat(v1,b1));
   temp->s=l+p2->info;
   temp->left=NULL;
   temp->right=NULL;
   temp2=temp;
   root=temp;
   for(i=0;i<z;)
   {
     if(strcmp(tt[i]->a,a1)==0)
     {
       temp->left=tt[i];
       for(l=i;l<z;l++)
	{
	   tt[l]=tt[l+1];
	}
	i=0;
	continue;
      }
     else if(strcmp(tt[i]->a,b1)==0)
     {
       temp->right=tt[i];
       for(l=i;l<z;l++)
	{
	   tt[l]=tt[l+1];
	}
       i=0;
       continue;
     }
    i++;
  }
  if(temp->left==NULL)
  {
    le=(struct tree*)malloc(sizeof(struct tree));
    strcpy(le->a,a1);
    le->left=NULL;
    le->right=NULL;
    temp2->left=le;
  }
  if(temp->right==NULL)
  {
    ri=(struct tree*)malloc(sizeof(struct tree));
    strcpy(ri->a,b1);
    ri->left=NULL;
    ri->right=NULL;
    temp2->right=ri;
  }
  if(front!=NULL)
  enqu(temp2->a,temp2->s);
  tt[z++]=temp2;
 }
}
 void disp(struct tree *rt)
{
  if(rt!=NULL)
  {
    disp(rt->left);
    cout<<""<<rt->a;
    disp(rt->right);
  }
}
 void main()
 {
  int i=0,g,h,p,y,n;
  char m[20],b[20][2],re;
  while(1)
  {

cout<<"===========================================================================";
cout<<"HUFFMAN CODING";

cout<<"===========================================================================";
  cout<<"Enter the total no of characters : ";
  cin>>n;
 for(i=0;i<n;i++)
 {
    cout<<"Enter the character : ";
   cin>>m;
   strcpy(b[i],m);
   cout<<"Enter frequency for "<<m<<" : ";
   cin>>g;
   enqu(m,g);
     }
 insert();
 disp(root);

cout<<"===============================================================================";
 cout<<"The corresponding codes are.....";

cout<<"===============================================================================";
 for(i=0;i<n;i++)
 {
   cout<<""<<b[i]<<" : ";
   info(b[i]);
 }
 cout<<"DO YOU WANT TO CONTINUE Y OR N: ";
 cin>>re;
 if(re=='y'||re=='Y')
   continue;
 else
   exit(0);
}
}
