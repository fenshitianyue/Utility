#pragma once

///////////////////////////////////////////////////////
// 这是一个Linux下测试代码块运行时间的类
///////////////////////////////////////////////////////
#include <iostream>
#include <sys/time.h>

#define TIME_INTERVAL TimeInterval t

class TimeInterval{
public:
  TimeInterval(){
    gettimeofday(&start, NULL);
  }
  ~TimeInterval(){
    gettimeofday(&end, NULL);
    std::cout << 1000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000 << "ms"
              << std::endl;
  }
private:
  timeval start; 
  timeval end;
};


