# ft_printf
### _Воспроизведение оригинального printf_
- *Для компиляции и запуска*
```sh
make && gcc -Wall -Wextra -Werror main.c -o print && ./print
```
- *Пример использования в main функции*


```
#include "ft_printf.h"

int main(){
    int a = 50;
    char *lol = "Aboba";
    
    ft_print("INT IS %d, CHAR IS %s, SOME THING IS %x", a, lol, 228);
}
```

