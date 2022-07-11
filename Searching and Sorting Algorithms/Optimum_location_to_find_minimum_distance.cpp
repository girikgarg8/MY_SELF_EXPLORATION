#include <bits/stdc++.h>
using namespace std;
#define N 5
#define difference 1e-6
//structure defining a point
struct point{
    int x,y;
    point(int x,int y){
        this->x=x;
        this->y=y;
    }
};
//structure defining a line of ax+by+c=0 form
struct line{
    int a,b,c;
    line(int a,int b,int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
};
//function to get distance of point (x,y) from point p
double dist(double x,double y,point p){
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
}
// function to compute total sum of distances from all points from a given point on the line
double compute (point p[],int n,line l,double X){
    //here X is the x coordinate of the point chosen on line,we can calclate the Y point of the given point using the equation of line
    double res=0;
    double Y=-1*(l.c+l.a*X)/(l.b);
    for (int i=0;i<n;i++){
        res+=dist(X,Y,p[i]);
    }
    return res;
}
// Function to find the value of X on the line
double findOptimumCost(point p[],int n,line l){
    double low=1e-6;
    double high=1e6;
    //loop until the difference between high and low doesn't become as low as 1e-6
    while ((high-low)>difference){
        double mid1=low+(high-low)/3;
        double mid2=high-(high-low)/3;
        double dist1=compute(p,n,l,mid1);
        double dist2=compute(p,n,l,mid2);
        // if mid2 point gives more total distance. then skip the third part
        if (dist1<dist2){
            high=mid2;
        }
        else low=mid1;
    }
    //when we reach here, the value of low and high would differ by at least 1e-6, so we will take the average of both, and return the answer
    return compute(p,n,l,(low+high)/2);
}
int main(){
    line l(1,-1,-3); //line is x-y-3=0
    point a(-3,-2);
    point b(-1,0);
    point c(-1,2);
    point d(1,2);
    point e(3,4);
    point p[]={a,b,c,d,e};
    cout << findOptimumCost(p,5,l);
    return 0;
}