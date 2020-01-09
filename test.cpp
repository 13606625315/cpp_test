#include <future>
#include <iostream>
//  -lpthread

bool is_prime(int x)
{
  std::cout << "is_prime1\n";    
  for (int i=1; i<x; i++)
  {
    if (i % x == 0)
    {
      std::cout << "is_prime"<<i<<"\n";        
      return false;
    }
  }
  std::cout << "is_prime\n";
  return true;
}

int main()
{
  std::cout << "start\n";
  std::future<bool> fut = std::async(is_prime, 10);
  std::cout << "please wait";
  std::chrono::milliseconds span(10);
 // while (fut.wait_for(span) != std::future_status::ready)
    std::cout << ".";
  std::cout << std::endl;

  bool ret = fut.get();
  std::cout << "final result: " << (ret) << std::endl;
  return 0;
}