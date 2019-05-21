#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

double mean(int array[], int size) {
	double sum = 0;
	for(int i = 0; i < size; i++)
		sum += array[i];
	double result = sum / size;
	return result;
}
int median(int array[], int size) {
	if(size % 2 == 0) return (array[size/2] + array[size/2 - 1])/2;
	else return array[size/2];
}
int mode(int array[], int size) {
	 int counter = 1;
        int max = 0;
        int mode = array[0];
        for (int pass = 0; pass < size - 1; pass++)
        {
           if ( array[pass] == array[pass+1] )
           {
              counter++;
              if ( counter > max )
              {
                  max = counter;
                  mode = array[pass];
              }
           } else
              counter = 1; // reset counter.
        }
    return mode;
}
double sd(int array[], int size)
{
	long double sum = 0, sd;
	int meanValue = mean(array, size);
//	cout << "mean:" << meanValue << endl;
    for(int i = 0; i < size; ++i) {
    	cout << "array[i]:" << array[i] << endl;
    	cout << "meanValue:" << meanValue << endl;
    	cout << "diff:" << array[i] - meanValue << endl;
    	cout << "pow:" << (array[i] - meanValue)*(array[i] - meanValue) << endl;
    	cout << "/size:" << (array[i] - meanValue)*(array[i] - meanValue) / size << endl;
    	sum += pow(array[i] - meanValue, 2);
    	cout << "sum:" << sqrt((array[i] - meanValue)*(array[i] - meanValue)) << endl;
    	break;
//    	cout << (array[i] - meanValue)*(array[i] - meanValue) / size << endl;
	}
//    	sum += (array[i] - meanValue)*(array[i] - meanValue) / size;
		
//        cout << pow(array[i] - meanValue, 2) << endl;
    cout << "sum:" << sum << endl;
	sd = sum / size;
    return sd;
}

int main() {
	const int PROVINCE_AMT = 76, YEAR_AMT = 10;
	// Data preparation
    ifstream data;
    data.open("average-income-41-58-eng.csv");

    string header, provinces[PROVINCE_AMT];
    int years[YEAR_AMT];
    int incomes[PROVINCE_AMT][YEAR_AMT];
    
    data >> header;
    for (int i = 0; i < YEAR_AMT; i++) {
        data >> years[i];
    }
    
    for(int i = 0 ; i < PROVINCE_AMT; i++)  {
    	data >> provinces[i];
    	for (int j = 0; j < YEAR_AMT; j++) {
	        data >> incomes[i][j];
	    }
	    sort(incomes[i], incomes[i] + YEAR_AMT);
    	cout << setprecision(2) << sd(incomes[i], YEAR_AMT) << endl;
    	break;
	}
	
//	for(int i = 0 ; i < PROVINCE_AMT; i++)  {
//    	cout << provinces[i] << " ";
//    	for (int j = 0; j < YEAR_AMT; j++) {
//	        cout << incomes[i][j] << " ";
//	    }
//	    cout << endl;
//	}

}
