// Copyright 2018 Your Name <your_email>

#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <header.hpp>
#include <iostream>
#include <vector>

#define DUP(x) x x
#define MIL(x) TIS(TIS(x))
#define StoTis(x) STO(TIS(x))
#define TIS(x) STO(STO(x))
#define STO(x) DEC(DEC(x))
#define DEC(x) x x x x x x x x x x
#include <stdio.h>
//#include <intrin.h>
#include <fstream>

//#pragma intrinsic(__rdtsc)

Experiment experiment(int his_number, size_t n, size_t lenta,
                      std::string &order) {
  //шаг 1: создание буффера
  int *buffer = make_buffer(n, lenta, order);
  //шаг 2: прогрев буффера
  //    std::cout << "buf ok" << std::endl;


  size_t j = 0;
  if (order == "preorder") {
    while (j < n - lenta) {
      j = buffer[j];
    }
    j = buffer[j];
  }
  if (order == "postoreder") {
    j = n - 1;
    while (j > lenta - 1) {
      j = buffer[j];
    }
    j = buffer[j];
  }
  if (order == "randorder") {
    for (size_t l = 0; l * lenta < n; l++) j = buffer[j];
  }

  // шаг 3: замер
  std::chrono::time_point<std::chrono::system_clock> start, end;
    if (order == "preorder" || order == "randorder") {
        int k = 0;
        size_t i = 0;
        start = std::chrono::system_clock::now();
      //начать замер времни
    while(i<n/lenta) {
        DUP(TIS(k = buffer[k];))
        i++;
    }
    end = std::chrono::system_clock::now();
    } else {
        size_t i = 0;
        //начать замер времни
        int k = n - 1;
        start = std::chrono::system_clock::now();
        while(i<n/lenta) {
        DUP(TIS(k = buffer[k];))
        i++;
        }
        end = std::chrono::system_clock::now();
        }

  //закончить замерять время
  auto time = end - start;
  Experiment exp(his_number, (n * 4 / 1024), time.count()*lenta / (2000*n));
  std::cout <<  time.count()*lenta/(2000*n) << std::endl;
  delete[] buffer;
  return exp;
}

int *make_buffer(size_t n, size_t lenta, std::string order) {
  if (order == "preorder") return make_a_bufffer_preorder(n, lenta);
  if (order == "postorder") return make_a_bufffer_postorder(n, lenta);
  if (order == "randorder") return make_a_bufffer_randorder(n, lenta);
  return nullptr;
}

int *make_a_bufffer_preorder(size_t n, size_t lenta) {
  int *buffer = new int[n];
  for (size_t i = 0, j = lenta; i < n; i++) {
      int t = clock();
      buffer[i] = rand_r(reinterpret_cast<unsigned int *>(&t)) % n;
    if (i % lenta == 0) {
      buffer[i] = j;
      j += lenta;
      if (i + lenta == n) buffer[i] = 0;
    }
  }

  return buffer;
}

int *make_a_bufffer_postorder(size_t n, size_t lenta) {
  int *buffer = new int[n];
  int j = n / lenta - lenta;
  for (int i = n - 1; i >= 0; i--) {
      int t = clock();
      buffer[i] = rand_r(reinterpret_cast<unsigned int *>(&t)) % n;
      if (i % lenta == lenta - 1) {
        buffer[i] = j - 1;
      j -= lenta;
    }
    if (j < lenta) buffer[i] = n - 1;
  }
  return buffer;
}

int *make_a_bufffer_randorder(size_t n, size_t lenta) {
  std::vector<int> num(n);
  for (size_t i = 0; i * lenta < n; i++) num.push_back(i * lenta);
  int *buffer = new int[n];
  size_t r, i = 0;
  while (num.size() > 0) {
    int t = clock();
    r = rand_r(reinterpret_cast<unsigned int *>(&t)) % num.size();
    buffer[i] = num[r];
    i = num[r];
    num.erase(num.begin() + r);
  }
  return buffer;
}

void write_report(Report rep) {
  std::ofstream file;
  file.open("/home/alexsun8/CLionProjects/lab2/lab-02-cache-Alexsun8/report.md",
            std::ios::app);
  file.clear();
  file << '\n'
       << "investigation: " << '\n'
       << "travel_variant: " << rep.tr_var() << '\n'
       << "  experiments: " << '\n';
  std::vector<Experiment> exps = rep.exps();
  for (size_t i = 0; i < exps.size(); i++) {
    file << "- experiment: " << '\n';
    file << "    number: " << exps[i].num() << '\n';
    file << "    input_data: " << '\n';
    file << "      buffer_size: " << exps[i].memory() << '\n';
    file << "    results: " << '\n';
    file << "      duration: " << exps[i].time() << " ns/10" << '\n';
  }
  file.close();
}

int mainF() {
  std::ofstream file;
  file.open(
      "/home/alexsun8/CLionProjects/lab2/lab-02-cache-Alexsun8/report.md");
  file.clear();
  file.close();
  int lenta = 64;
  std::vector<Experiment> exps;
  Report rep;
  unsigned int lmin, lmax;
  lmin = 65536;    // 64kb
  lmax = 4194304;  // 4mb
  // lmax = 1048576;
  size_t x;
  size_t l;

  std::string type_order;
  for (int order = 0; order < 3; order++) {
    // int order = 0;
    if (order == 0) type_order = "preorder";
    if (order == 1) type_order = "postorder";
    if (order == 2) type_order = "randorder";
      std::cout << "buf ok" << std::endl;
    x = 0;
    while (pow(2, x) != lmin / 2) x++;
    l = 0;
    for (unsigned int memory = lmin / 2; memory <= (2 * lmax);) {
      l++;
      exps.push_back(experiment(l, memory / 4, lenta, type_order));
      x++;
      memory = static_cast<int>(pow(2, x));
    }

    rep.make(type_order, exps);
    write_report(rep);
    exps.clear();
    rep.clear();
  }
  return 0;
}
