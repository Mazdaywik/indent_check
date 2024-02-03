#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>

#define MIN_INT -1000000001

void buildTree(int *tree,int size,int *arr,int n){
    
    for(int i=size;i<2*size;++i){
        if(i-size>=n){
            tree[i]=MIN_INT;
        }
        else{
            tree[i]=arr[i-size];
        }
    }
    for(int i = size-1;i>0;--i){
        tree[i]= tree[2*i]>tree[2*i+1]?tree[2*i]:tree[2*i+1];
    }
    tree[0]=0;
}
void update(int size,int*tree,int id,int value){
    id+=size;
    tree[id]=value;
    while (id/=2){
        tree[id]=tree[2*id]>tree[2*id+1]?tree[2*id]:tree[2*id+1];
    }
}

int max_value(int size,int *tree, int l,int r){
    int ans = MIN_INT;
    l+=size,r+=size;
    while(l<=r){
        if (l&1){
            ans = ans>tree[l]?ans:tree[l];
        }
        if (!(r&1)){
            ans = ans>tree[r]?ans:tree[r];
        }
        l=(l+1)/2,r=(r-1)/2;

    }
    return ans;
}

int main()
{

    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    int size = pow(2,(int)(log2(n-1))+1);
    
    int *tree = (int*)malloc(2*size*sizeof(int));
    buildTree(tree,size,arr,n);
    char query[3];
    int f,se;
    scanf("%s",query);
    while(strcmp(query,"END")!=0){
        if (strcmp(query,"MAX")==0){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",max_value(size,tree,l,r));
        }
        else{
            int id,value;
            scanf("%d%d",&id,&value);
            update(size,tree,id,value);
        }
        scanf("%s",query);
    }
    free(tree);
    return 0;
}