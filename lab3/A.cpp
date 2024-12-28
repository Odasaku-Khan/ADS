#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int b[t];
    for(int i=0;i<t;i++){
        cin>>b[i];
    }
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<t;i++){
        int l=0;
        int r=n-1;
        int mid;
        bool found=false;
        while(l<=r){
            mid = (l+r)/2;
            if(mid%2==0){
                if(b[i]<=a[mid][0] && b[i]>=a[mid][m-1]){
                    int l2=0;
                    int r2=m-1;
                    int mid2;
                    while(l2<=r2){
                        mid2=(l2+r2)/2;
                        if(b[i]==a[mid][mid2]){
                            cout<<mid<<" "<<mid2<<endl;
                            found=true;
                            break;
                        }
                        if(a[mid][mid2]<b[i]){
                            r2=mid2-1;
                        }else{
                            l2=mid2+1;
                        }
                    }
                    if(found){
                        break;
                    }
                }
                if(b[i]<a[mid][0] && b[i]<a[mid][m-1]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }else{
                if(b[i]>=a[mid][0] && b[i]<=a[mid][m-1]){
                    int l2=0;
                    int r2=m-1;
                    int mid2;
                    while(l2<=r2){
                        mid2=(l2+r2)/2;
                        if(b[i]==a[mid][mid2]){
                            cout<<mid<<" "<<mid2<<endl;
                            found=true;
                            break;
                        }
                        if(a[mid][mid2]<b[i]){
                            l2=mid2+1;
                        }else{
                            r2=mid2-1;
                        }
                    }
                    if(found){
                        break;
                    }
                }
                if(b[i]<a[mid][0] && b[i]<a[mid][m-1]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        if(!found){
            cout<<"-1"<<endl;
        }
    }
}