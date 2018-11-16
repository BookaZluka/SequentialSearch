#include <iostream>
#include <cmath>

struct Node{
    double x=0;
    double y=0;
};

double mutation(double x0,double x1){
    const int NUM = 100000000;
    double res = fabs((double)((rand() * NUM) % (int)((x1 - x0)*NUM) + 1) / NUM) + x0;
    return res;
}

double function(double x,double y){
    return -cos(x)*cos(y)*log(1+x*x+y*y)/log(2.8);
}

void sort(Node *population){
    for(int i=0;i<4;i++)
        for(int j=i+1;j<4;j++){
            if(function(population[j].x,population[j].y) > function(population[i].x,population[i].y))
                std::swap(population[i],population[j]);
        }
}

double generation(double x0,double x1){
    const int NUM = 100000000;
    double res = fabs((double)((rand() * NUM) % (int)((x1 - x0)*NUM) + 1) / NUM) + x0;
    return res;
}

int main(){
    Node population[4];
    for(int i=0;i<4;i++){
        population[i].x=generation(-1,1);
        population[i].y=generation(-1,1);
    }
    for(int i=0;i<4;i++){
        std::cout<<population[i].x<<" ";
        std::cout<<population[i].y<<" ";
        std::cout<<std::endl;
    }
    sort(population);
    Node population1[4];
    int i=0;
    while(i<1000){
        population1[0].x=population[0].x;
        population1[1].x=population[0].x;
        population1[0].y=mutation(-1,1);
        population1[1].y=mutation(-1,1);
        population1[2].x=mutation(-1,1);
        population1[3].x=mutation(-1,1);
        population1[2].y=population[0].y;
        population1[3].y=population[0].y;
        for(int i=0;i<4;i++){
            population[i].x=population1[i].x;
            population[i].y=population1[i].y;
        }
        sort(population);
        i++;
    }
    std::cout<<population[0].x<<" "<<population[0].y<<std::endl;
    std::cout<<function(population[0].x,population[0].y)<<std::endl;
    return 0;
}

