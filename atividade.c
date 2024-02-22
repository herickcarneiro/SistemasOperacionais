#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  pid_t child1,child2,neto1,neto2,neto3,neto4;
  pid_t pidPai;
  pidPai = getpid();
  child1 = fork();
  if(child1==0){
  neto1 = fork();
    if(neto1==0){
      execl("/bin/sh", "sh", "-c","echo Filho 1", NULL);
    }
    else{
      neto2 = fork();
      if(neto2==0){
        execl("/bin/ls", "ls", "-1", NULL);
      }
      else{
        sleep(3);
        wait(NULL);
        wait(NULL);
        printf("Eu sou o processo filho de pid [%4d] e o pid do pai P1 é [%4d]\n", getpid(), pidPai);
        exit(0);
     }
   }
 }
  child2 = fork();
  if(child2==0){
  neto3 = fork();
    if(neto3==0){
      //printf("Eu sou o processo neto do filho 2\n");
      execl("/bin/date", "date", NULL);
    }
    else{
      neto4 = fork();
      if(neto4==0){
        //printf("Eu sou o processo neto do filho 2\n");
        execl("/bin/hostname", "hostname", NULL);
      }
      else{
        sleep(3);
        wait(NULL);
        wait(NULL);
        printf("Eu sou o processo filho de pid [%4d] e pid do pai P1 é [%4d]\n", getpid(), pidPai); 
        exit(0);
     }
   }
 }
    else{
    sleep(3);
    wait(NULL);
    wait(NULL);
    printf("Eu sou o processo pai e meu PID é: [%4d]\n", getpid());
    printf("Programa encerrando...\n");
    }
return 0;
}
