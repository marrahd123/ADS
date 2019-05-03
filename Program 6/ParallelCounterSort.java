/*
give the computer the 2 counter arrays rather than 2 sorted arrays
    pass in singualr array tell threads which section of array to work with (0-49) then (50-99)
    give back the totals, computer merges total into grand total, then replicates the data
    subtotals are handed back by returning array, cannot be sent through the public void run though
    you can make data array data memeber of the class. you can make get method to get the data array
    add up subtotals count array inside run mehtod but have it located in the class object as a data memeber of the object.
    get method will allow the main to reach into the object and get the array
    get from both objects, add subcomponents, get grand total count array, the replicate data from that
    (This way avoids the problem of shared memory problem)
    does not print to a file 
*/
//Marrah Delmont
//Program 6
//ADS - Spring 2019
import java.util.Random;//used to fill unsorted array with random values
import java.lang.Math;//used for out of bounds
public class ParallelCounterSort
{
  public static void main(String [] args)
  {
    //make an array to be sorted
    int counter = 0;
    int min = 11;//set at 11 to go through and find smallest number in 0-10 number filled array[100]
    int max = -1;//finds largest number from 0-10
    int length;
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
      if(array[i] > max)
      {
        max = array[i];//finds largest number
      }//end if
      if(array[i] < min)
      {
        min = array[i];//finds the smallest number
      }//end if
    }
    length = max - min;
    //create threads
    MyClass a = new MyClass(0, 49, array, length, min, max, counterArray1);
    MyClass b = new MyClass(50, 99, array, length, min, max, counterArray2);
    //start 
    a.start();
    b.start();
    //join 
    try //if you do not do try/cath, an error message will display
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
      counter = counter + instances;
      for(int p = counter - instances; p < counter; p++)
      {
        newArray[p] = index + 1;
        System.out.println(newArray[p]);//prints sorted values to the new array 
      }//end inner for
    }//end outer for
  }//end main
}//end class ParallelCounterSort

class MyClass extends Thread
{
  int startIndex;
  int endIndex;
  int array[];
  int counterArray[];
  int length;
  int min;
  int max;

  MyClass(int startIndex, int endIndex, int [] array, int length, int min, int max, int [] counterArray)
  {
    this.startIndex = startIndex;
    this.endIndex = endIndex;
    this.array = array;
    this.length = length;
    this.min = min;
    this.max = max;
    this.counterArray = counterArray;
  }//constructor
  
  public void run()
  {
      int [] newArray = new int[array.length];//new array is the size of the unsorted array
      int counter = 0;
    //go through data array and counter sort the dooblie doo where index 0 represents min, 1 represents min + 1, all the way to n being max
      for(int j = startIndex; j < endIndex; j++)
      {
        int value = array[j];
        counterArray[value - min ] = counterArray[value - min] + 1;
        System.out.println("value: " + value + "   min: " + min);
      }//end for
  }//end run
}//end class MyClass