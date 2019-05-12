//Marrah Delmont
//Program 5 - Parallel Linear Search
//ADS - Spring 2019
//Write a linear search in Java using the Threads class to implement parallelism as discussed in class.
import java.util.Scanner;
import java.util.Random;

class MyClass extends Thread//A thread is a thread of execution in a program. The Java Virtual Machine allows an application to have multiple threads of execution running concurrently.
{
  int start;
  int end;
  int searchNum;
  int [] array;

  MyClass(int start, int end, int search, int [] arr)
  {
    this.start = start;
    this.end = end;
    searchNum = search;
    array = arr;
  }
  public void run()
  {
    for(int j = start; j <= end; j++)//searches through the array
      {
        if(array[j] == searchNum)//if the key number is found
        {
          System.out.println(searchNum + " was found at index " +j);//then it will print where the key number was found
        }
      }
  }
}
public class ParallelLinearSearch
{
  public static void main(String args[])
  {
  int searchNum;
  int arrayLength = 1000;//can be however big or small
  int[] array = new int[arrayLength];
  Scanner scan = new Scanner(System.in);
  Random rand = new Random();
  //Have your main method create a random array
  for(int i = 0; i < arrayLength; i++)
  {
    array[i] = rand.nextInt(10) + 1;//fills array with random values
    System.out.print(array[i] + " "); //Print array to screen
  }

  System.out.println("What number are you searching for between 1 and 10? "); //Ask the user for a target value
  searchNum = scan.nextInt();

//Look at different sections and take parameters
// LS Lauren = new LS(array,0,499,target);  
// LS Seth = new LS(array,500,999,target);
//Seth.start();                             
//Lauren.start();    
//Have 2 threads, each searching a different half of the array for all matches in parallel, reporting the index locations of all matches to the screen.
  MyClass a = new MyClass(0, 499, searchNum, array);
  MyClass b = new MyClass(500, 999, searchNum, array);
  a.start();
  b.start();
  }
}