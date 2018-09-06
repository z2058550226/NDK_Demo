/* Module name is Unix. */
%module Unix
%{
/* Include the POSIX operating system APIs. */
#include<unistd.h>

int add(int a,int b);
%}

%header %{
void sayHello();
%}

