#include "../common/common.h"
#include "../common/threading_wrapper.h"

class TestThread : public BaseFramework::ThreadingWrapper
{
public:
  virtual void ThreadMain();
};

void TestThread::ThreadMain()
{
  printf("Hello World!\n\tfrom sub thread\n");
}

int main(int argc, char *argv[])
{
  BaseFramework::ThreadingWrapper *test_thread = new TestThread();
  test_thread->Start();
  test_thread->Stop();

  return 0;
}
