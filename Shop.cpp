//
// Created by hajda2 on 2021. 09. 30..
//
#include "Shop.hpp"
#include "Queue.cpp"
#include <fstream>
#include "KPriorityQueue.cpp"
#include "Customer.hpp"

Shop::Shop(std::string filename) {
  //TODO
  int iterator;
  double prio;
  unsigned short maxsize;
  unsigned long id;
  unsigned short priority;
  unsigned short allproductnum;
  std::ifstream file;

  file.open(filename);
  file  >> iterator >> std::ws;
  for(int i = 0;i < iterator;i++){
      file >> prio >> maxsize >>std::ws;
      KPriorityQueue<Customer> vec(prio,maxsize);
      cash_registers.push_back(vec);
  }
    file  >> iterator >> std::ws;
  for (int i = 0; i < iterator; ++i) {
      file >> id >> priority >> allproductnum >> std::ws;
      Customer cus(id,priority,allproductnum);
      global_queue.in(cus);
  }
  file.close();
  //filename.max_size();
}

bool Shop::needIn() const{
    bool need = false;

    for (size_t i = 0; i < cash_registers.size(); i++) {
        if(cash_registers[i].current_size() != cash_registers[i].max_size()){
            return true;
        }
    }
    return need;
}

bool Shop::next(){
  //TODO
  // A javasolt szerkezet a következő:
  // 1. leolvassuk a pénztárgépnél lévők termékét.
  // 1.1. ha az volt az utolsó terméke, akkor növeljük a sorban állók prioritását és kivesszük a sorból
  // 2. megpróbálunk vásárlókat állítani a kasszákhoz, amíg tudunk

  while(needIn() && !global_queue.isEmpty()){
      unsigned long min  = 1000;
      int idx = 0;
      for (size_t i = 0; i < cash_registers.size(); ++i) {

          if((cash_registers[i].time_to_finish(global_queue.first()) < min) && cash_registers[i].max_size() != cash_registers[i].current_size()){
              min = cash_registers[i].time_to_finish(global_queue.first());
              idx = i;
          }
      }
      cash_registers[idx].in(global_queue.out());
      std::cout << std::endl;
  }

  for(size_t j  = 0;j < cash_registers.size(); j++){
      if(cash_registers[j].current_size() > 0) {
          //cash_registers[j].first().current_product_num--;
          cash_registers[j].Step();
      }
      if(cash_registers[j].first().current_product_num == 0){
          output.push_back(cash_registers[j].out().id);
          if(!global_queue.isEmpty()){
                cash_registers[j].in(global_queue.first());
          }
      }
  }

    for (size_t i = 0; i < cash_registers.size(); ++i) {
        if(!cash_registers[i].isEmpty()){
            return true;
        }
    }

  if(!global_queue.isEmpty()){
      return true;
  }else{
      return false;
  }
}

void Shop::result(std::string filename) const { //eremény kiírása fileba
  //TODO
  //filename.max_size();
  std::ofstream file;
  file.open(filename);
  for(int i = 0;i < (int)output.size();i++){
      file << output[i] << std::endl;
  }
  file.close();
}