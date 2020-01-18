# API

### void Sleep(unsigned int second)

```c++
#include <iostream>
#include "time/time.h"

int main(int argc, char const *argv[])
{
	micky::Sleep(1);
	std::cout<< "1 second passed" << std::endl;
	return 0;
}
```

### time_t GetTimestamp()

### std::string GetTime(int types)
```c++
#include <iostream>
#include "time/time.h"
using namespace std;

int main(int argc, char const *argv[])
{
	cout<< micky::GetTime(3) <<endl;
	return 0;
}
```