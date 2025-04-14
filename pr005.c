//Программа, порождающая дочерний процесс (часть 2)
//Процесс-родитель и процесс-ребёнок должны выполнять разные действия
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main () {
       	 pid_t procid, pprocid;
         int a=0, b;
         procid = getpid();
         pprocid = getppid();
         printf("До вызова fork()\n");
         printf("Ид. текущ. процесса: %d\nИд. род. процесса: %d\n", procid, pprocid);
         printf("Начальное значение a: %d\n", a);
         b = fork();
	 if (b<0) {
		 //Во время выполнения fork() произошла ошибка. Выходим из программы с возвратом кода -1
		 printf("Ошибка при выполнениии fork() \n");
	         exit(-1); //выход из программы
	}
	 else if (b==0) {
		 printf("\n\nПоявился дочерний процесс, получил значение %d\n", b);
                 a = a+1; //Проверяем изменение значения переменой a
                 procid = getpid();
        	 pprocid = getppid();
         	 printf("После вызова fork() в процессе-ребёнке\n");
        	 printf("Ид. текущ. процесса: %d\nИд. род. процесса: %d\nНовое значение a: %d\n", procid, pprocid, a);
	 }
	 else {
		 printf("\n\nРодительский процесс после вызова fork() получил ид. ребёнка: %d\n", b); 
		 a = a+1111; //Проверяем изменение значения переменой a
		 procid = getpid();
		 pprocid = getppid();
                 printf("Идентификаторы процессе-родителя\n");
	   	 printf("Ид. текущ. процесса: %d\nИд. род. процесса: %d\nНовое значение a: %d\n", procid, pprocid, a);
	 }
         return 0; 
}
