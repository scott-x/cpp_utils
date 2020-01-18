### API


### void Print(color c, std::string str)

```c++
#include <iostream>
#include "cmd/cmd.h"

int main(int argc, char const *argv[])
{
	micky::Print(micky::GREEN,"hello");
	return 0;
}
```
### void PrintInfo(std::string str) 
### void PrintWarning(std::string str) 
```c++
#include <iostream>
#include "cmd/cmd.h"

int main(int argc, char const *argv[])
{
	micky::PrintWarning("hello");
	return 0;
}
```

### void AskQuestion(std::string key, const char * question)

All answers were stored in the `qs` container(map)
```c++
#include <iostream>
#include "cmd/cmd.h"

int main(int argc, char const *argv[])
{
	micky::AskQuestion("name","what's your name?");
	//all answers were stored in the qs container
	std::cout << micky::qs["name"] << std::endl;
	return 0;
}
```

### void ShowMenu(std::string tips, std::string selections[], int length)

```c++
#include <iostream>
#include "cmd/cmd.h"

int main(int argc, char const *argv[])
{
	std::string selections[] = {
		"1. sleep",
		"2. swimming",
		"3. dancing"
	};
	micky::ShowMenu("what do you want't do?",selections,3);
	return 0;
}
```