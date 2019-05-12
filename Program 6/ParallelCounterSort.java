//Marrah Delmont
//Program 6 - Parallel Counter Sort
//ADS - Spring 2019
/* Write Program 6 in Java using the Threads class to implement parallelism as discussed in class.
    Write a Counter Sort method that will Counter Sort any array of integers.*/
import java.util.Random;//used to fill unsorted array with random values
public class ParallelCounterSort
{
  public static void main(String [] args)
  {
    //make an array to be sorted
    int [] array = new int[100];//holds the unsorted values
    int [] newArray = new int[100];//holds the sorted values
    int [] counterArray1 = new int[50];//will sort the first half - half the size of the array
    int [] counterArray2 = new int[50];//will sort the second half - half the size of the array
    Random rand = new Random();
    System.out.println("The unsorted array");
    for(int i = 0; i < 100; i++)//loop to print unsorted array
    {
      array[i] = rand.nextInt(10) + 1;
      System.out.print(array[i] + " ");//prints unsorted array
    }
    //create threads
    MyClass a = new MyClass(0, 49, array, counterArray1);
    MyClass b = new MyClass(50, 99, array, counterArray2);
    //start 
    a.start();
    b.start();
    System.out.println("\nThe sorted array: ");
    //join 
    try //if you do not do try/catch, an error message will display
    {
      a.join();
      b.join();
    } catch(Exception e)
    {
      System.out.println("ERROR: Failed to join");
    }//catch
    //get number of values for each index from the two counter arrays
    for(int index = 0; index < counterArray1.length; index++)
    {
      int instances = counterArray1[index] + counterArray2[index];
      for(int p = 0; p < instances; p++)
      {
        newArray[p] = index;
        System.out.print(newArray[p]+ " ");//prints sorted values to the new array 
      }//end inner for
    }//end outer for
  }//end main
}//end class ParallelCounterSort

class MyClass extends Thread //A thread is a thread of execution in a program. The Java Virtual Machine allows an application to have multiple threads of execution running concurrently.
{
  int start;
  int end;
  int array[];
  int counterArray[];

  MyClass(int start, int end, int [] array, int [] counterArray)
  {
    this.start = start;
    this.end = end;
    this.array = array;
    this.counterArray = counterArray;
  }
  public void run()
  {
      for(int j = start; j < end; j++)
      {
        int value = array[j];
        counterArray[value] = counterArray[value] + 1;
      }//end for
  }//end run
}//end class MyClass