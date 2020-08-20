/*
Given a  2D Array, :

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

We define an hourglass in  to be a subset of values with indices falling in this pattern in 's graphical representation:
a b c
  d
e f g

There are 16 hourglasses in 6x6, and an hourglass sum is the sum of an hourglass' values.

Task
Calculate the hourglass sum for every hourglass in , then print the maximum hourglass sum.
*/

int main()
{
    int max_sum = INT_MIN;
    int sum = 0;

    for(int R=1;R<5;R++) //skip borders
     {
         for(int C=1;C<5;C++) //skip borders
         {
             sum = 0;
             for(int r1=-1;r1<=1;r1++)
             {
                 for(int c1=-1;c1<=1;c1++)
                 {
                    if(r1 == 0 && c1 != 0) //skip adjacent elements of middle row
                    {
                        continue;
                    } 
                    sum = sum + arr[R+r1][C+c1];
                 }
             }

             if(sum > max_sum)
                max_sum = sum;
         }
     }

     std::cout << max_sum << std::endl;

    return 0;
}