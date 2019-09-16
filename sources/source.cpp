// Copyright 2018 Your Name <your_email>

#include <header.hpp>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>

#define DUP(x) x x
#define TIS(x) STO(STO(x))
#define STO(x) DEC(DEC(x))
#define DEC(x) x x x x x x x x x x
#include <stdio.h>
//#include <intrin.h>
#include <fstream>

//#pragma intrinsic(__rdtsc)

Experiment experiment(int his_number, size_t n, size_t lenta, std::string& order){
    //шаг 1: создание буффера
    int* buffer =  make_buffer(n, lenta, order);
    //шаг 2: прогрев буффера
    for(size_t j = 0; j < n; ){
        j = buffer[j];
    }
    double time = 0;
    // шаг 3: замер
    clock_t start, end;
    start = clock();
//начать замер времни
int k=0;
       DEC(  k = buffer[k];)

        end = clock();
    //закончить замерять время
    time = end- start;
  Experiment exp(his_number, (n*4/1024/1024) , time/10);
   delete[]buffer;
    return exp;
}



int* make_buffer(size_t n,int lenta, std::string order){
    if(order=="preorder")return make_a_bufffer_preorder(n,lenta);
    if(order=="postorder")return make_a_bufffer_postorder(n,lenta);
//    if(order=="randorder")return make_a_bufffer_randorder(n,lenta);
    return nullptr;
}

int* make_a_bufffer_preorder(size_t n, size_t lenta){
    int* buffer = new int[n];
    for(size_t i = 0, j =lenta; i< n; i++) {
        buffer[i] =  rand();
        if (i%lenta == 0) {
            buffer[i] = j;
            j+= lenta;
            if (i+lenta == n) buffer[i] = 0;
        }
    }

    return buffer;
}

int* make_a_bufffer_postorder(size_t n,int  lenta){
    int* buffer = new int[n];
    int j = n/lenta - lenta;
    for(int i = n-1; i>=0; i--) {
        buffer[i] = rand();
        if (i%lenta == lenta - 1) {
            buffer[i] = j-1;
            j-=lenta;
        }
        if (j<lenta) buffer[i] =n-1;
    }
    return buffer;
}

 // char* make_a_bufffer_randorder(size_t n, int lenta);

void write_report(Report rep){
    std::ofstream file;
    file.open("/home/alexsun8/CLionProjects/lab-02-cache-Alexsun8/report.md", std::ios::app);
    file<<'\n'<<"investigation: "<<'\n'<<"travel_variant: "<< rep.tr_var()<<'\n'<<"  experiments: "<<'\n';
    std::vector<Experiment> exps = rep.exps();
    for(size_t i = 0; i <exps.size(); i++){
        file<< "- experiment: "<<'\n';
        file<<"    number: "<<exps[i].num()<<'\n';
        file<<"    input_data: "<<'\n';
        file<<"      buffer_size: "<< exps[i].memory()<< '\n';
        file<<"    results: "<< '\n';
        file<<"      duration: "<< exps[i].time()<<'\n';
    }
    file.close();
}


int mainF(){
    srand ( time(NULL) );
    int lenta = 64;
    std::vector<Experiment> exps;
    Report rep;
    unsigned long int lmin, lmax;
    lmin = 65536;//64kb
    lmax = 4194304;//4mb
    size_t x ;
    size_t l;


    std::string type_order;
   // for(int order=0;order<2;order++) {
    int order = 0;
       if(order == 0) type_order = "preorder";
       if(order == 1) type_order = "postorder";
      //  if(order == 2) type_order = "randorder";
        x = 0;
        while (pow(2,x)!=lmin/2)x++;
        l = 0;
        for (unsigned long int memory =lmin/2; memory < (3*lmax/2);) {
            l++;
            exps.push_back(experiment(l, memory/4, lenta, type_order));
            x++;
            memory = pow(2,x);
        }

        rep.make(type_order,exps);
        write_report(rep);
        exps.clear();
        rep.clear();
   // }
    return 0;
}