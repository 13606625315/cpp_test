#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <sys/types.h>
#include <unistd.h>
std::condition_variable cv;
std::mutex cv_m;
int i = 0;
bool done = false;

const std::string getCurrentSystemTime()
{
  auto tt = std::chrono::system_clock::to_time_t
  (std::chrono::system_clock::now());
  struct tm* ptm = localtime(&tt);
  char date[60] = {0};
  sprintf(date, "%d-%02d-%02d      %02d:%02d:%02d\n",
    (int)ptm->tm_year + 1900,(int)ptm->tm_mon + 1,(int)ptm->tm_mday,
    (int)ptm->tm_hour,(int)ptm->tm_min,(int)ptm->tm_sec);
  return std::string(date);
}

bool a = false;

void waits()
{
    std::cout <<"pid = "<< getpid() <<"tid = "<<pthread_self()<<std::endl;
    std::unique_lock<std::mutex> lk(cv_m);
    std::cout <<getCurrentSystemTime()<< "Waiting... \n";
	  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Waiting...1 \n";	
    cv.wait(lk, []{return a;}); //默认为false是阻塞的; true不是阻塞的相当于没有wait //不会时时检查a的值。
    std::cout <<getCurrentSystemTime()<< "...finished waiting. i == 1\n";
    done = true;
}

void signals()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::unique_lock<std::mutex> lk(cv_m);
    std::cout << "Notifying...\n";
    //cv.notify_one();
    std::cout << "Notifying...1\n";	
    a = true; 
}

int main()
{
  std::thread t1(waits), t2(signals);
  t1.join(); t2.join();
}