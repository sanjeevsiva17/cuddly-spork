import java.io.*;
import java.lang.*;
class PrintDemo{
int i;
void print(String threadName){
try{
for(i=5;i>0;i--){
System.out.println("Counter " + i + " - Thread - " +
threadName);
}
}catch(Exception e){
System.out.println("Exception\n");
}
}
}
class simplethread extends Thread{
private Thread t;
private String name;
PrintDemo pd;
simplethread(String nm, PrintDemo p){
name = nm;
pd = p;
}
public void run(){
synchronized(pd){
pd.print(name);
System.out.println("Thread " + name + " Exiting");
}
}public void start(){
System.out.println("Starting Thread " + name);
if(t==null){
t = new Thread(this, name);
t.start();
}
}
}
class simplemultithreading{
public static void main(String args[]){
PrintDemo pd = new PrintDemo();
simplethread sth1 = new simplethread("Producer ",pd);
simplethread sth2 = new simplethread("Consumer ",pd);
sth1.start();
sth2.start();
try{
sth1.join();
sth2.join();
}catch(Exception e){
System.out.println("exception\n");
}
}
}
