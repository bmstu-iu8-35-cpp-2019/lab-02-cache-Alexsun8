// Copyright 2019 alexsun8

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <string>
#include <utility>
#include <vector>

#include <sstream>

class Experiment {
 private:
  int number;
  double buffer_size_kb;
  double duration_ns;

 public:
  Experiment(int num, double B_S_kb, double D_ns) {
    number = num;
    buffer_size_kb = B_S_kb;
    duration_ns = D_ns;
  }
  ~Experiment() = default;

  int num() { return number; }

  std::string memory() {
    std::string memory = "";
    double buffer_size_mb = buffer_size_kb / 1024;
    std::ostringstream ost;
    if (buffer_size_kb > 1024) {
      ost << buffer_size_mb;
      memory += ost.str();
      memory += " mb";
    } else {
      ost << buffer_size_kb;
      memory += ost.str();
      memory += " kb";
    }
    return memory;
  }

  double time() { return duration_ns; }
};

class Report {
 private:
  std::string travel_variant = "";
  std::vector<Experiment> experiments;

 public:
  Report() = default;
  Report(std::string T_V, std::vector<Experiment> ex_mass) {
    travel_variant = T_V;
    experiments = ex_mass;
  }

  ~Report() = default;

  std::string tr_var() { return travel_variant; }

  std::vector<Experiment> exps() { return experiments; }

  void clear() {
    experiments.clear();
    travel_variant.clear();
  }

  void make(std::string T_V, std::vector<Experiment> ex_mass) {
    travel_variant = T_V;
    experiments = ex_mass;
  }
};

Experiment experiment(int his_nuber, size_t n, size_t lenta,
                      std::string& order);

int* make_buffer(size_t n, int lenta, std::string order);

int* make_a_bufffer_preorder(size_t n, size_t lenta);

int* make_a_bufffer_postorder(size_t n, int lenta);

int* make_a_bufffer_randorder(size_t n, int lenta);

void write_report(Report report);

int mainF();

#endif  // INCLUDE_HEADER_HPP_
