/**
 * Cashion Penha
 * Lab 14
 * File Processing
 * 31/01/2018
 */

/**< Preprocessor directives */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

/**< Initialising array to store each value in the file */
double filevals[50];
int valuesinfile=0;

/**< Sort function to sort in Ascending order */
void sortasc(void)
{
    /**< Initialising variables */
    int a,b,mini;   /// a and mini are to denote the position pointed at
    double minv;    /// minv is to store the minimum value while sorting

    for(a=0; a<valuesinfile; a++)   ///loop to scan through each value in the .txt file
    {
        mini=a;     ///Letting mini equal to value of a
        minv=filevals[mini];    /// minv now equals the value in element indicated by mini
        for(b=a+1; b<valuesinfile; b++)     ///for loop to compare a with other elements of the array
        {
            if(minv>filevals[b])    ///comparing two elements from the array to see which is smaller
            {
                minv=filevals[b];   ///if smaller value is found then let minv be that small value
                mini=b; ///let mini indicator now equal to the value of b
            }
        }
        filevals[mini]=filevals[a]; ///letting the element indicate by mini equal to element indicated by a
        filevals[a]=minv;   ///swapping the new minimum value found
    }

}


/**< Sort function to sort in Descending order */
void sortdsc(void)
{
    /**< Initialising variables */
    int a,b,maxi;   /// a and maxi are to denote the position pointed at
    double maxv;    /// maxv is to store the maximum value while sorting
    for(a=0; a<valuesinfile; a++)   ///loop to scan through each value in the .txt file
    {
        maxi=a; ///Letting maxi equal to value of a
        maxv=filevals[maxi];    /// maxv now equals the value in element indicated by maxi
        for(b=a+1; b<valuesinfile; b++)    ///for loop to compare a with other elements of the array
        {
            if(maxv<filevals[b])    ///comparing two elements from the array to see which is greater
            {
                maxv=filevals[b];   ///if greater value is found then let maxv be that value
                maxi=b;    ///let maxi indicator now equal to the value of b
            }
        }
        filevals[maxi]=filevals[a];     ///letting the element indicate by maxi equal to element indicated by a
        filevals[a]=maxv;   ///swapping the new maximum value found
}
}
/**< Main function */
int main()
{
    /**< Initialising variables */
    int value,i;
    double sum=0,minimum=50,mean,stdev=0;
    char order;

    /**< ifstream object called inFile created */
    ifstream infile("rawValues.txt",ios::in);
    ofstream of;

    /**< To determine if the file opened successfully */
    if(!infile)
    {
        cerr <<"File could not be opened!" << endl;
        exit(1);
    }

    cout <<"Lab 14 - File Processing\n" << endl;
    cout <<"Values obtained from the .txt file" << endl;

    /**< Continue reading until end of file has been reached  */
    while (infile >> value)
    {
        filevals[valuesinfile++]=value; ///count the number of values in the file
        cout << value << endl; /// display the values from the file
        sum += value; /// add each value from the file to obtain the sum of the values
        if (value < minimum) /// condition to calculate the minimum value
        minimum = value; /// if current value is less then minimum let minimum be the current value
    }

    mean=(sum/valuesinfile);    /// sum divided by the number of values in the file

    for(i=0; i<valuesinfile; i++)   /// for loop incremented each time from 0 to end of file
    {
        stdev = stdev + pow(filevals[i]-mean,2); /// method of getting each value from the file to calculate the standard deviation
    }

    stdev= sqrt(stdev/(valuesinfile-1));    /// formula to calculate the final standard deviation value

    /**< Displaying the result */
    cout << "\nMean is: "<< mean << endl;
    cout <<"Sum of values is: "<< sum << endl;
    cout << "Maximum is: "<< value << endl;
    cout << "Minimum is: "<< minimum << endl;
    cout << "Standard deviation is: "<< stdev << endl;

    infile.close();/// closing the input file

    /**< Getting user input to decide sorting order */
    cout << "\nPlease select order for sorting: {a} for ascending or {b} for descending > ";
    cin >> order;

    /**< if user enters d, then call function to sort in descending order */
    if (order=='d')
    {
        sortdsc();
    }
    else /// if user enters anything else than d, then simply sort in ascending order by calling the function
    {
        sortasc();
    }

    of.open("sortedValues.txt");/// open the sortedValue text file

    /**< For loop to store each value onto the file */
    for(int a=0; a<valuesinfile; a++)
    {
        cout << filevals[a] << endl;
        of << filevals[a] << endl;
    }

    of.close();/// close the output file

    return 0; /// end of program
}
