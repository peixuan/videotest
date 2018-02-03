#include "../common/common.h"
#include "../common/threading_wrapper.h"

#include <opencv2/opencv.hpp>

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

  cv::VideoCapture cap;
  cv::Mat          img;

  cap.open(0);

  while (1)
  {
    cap >> img;
    if (img.empty())
      break;

    cv::imshow("Original", img);
    cv::waitKey(50);
  }

  return 0;
}
