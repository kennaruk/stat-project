#include <iostream>
#include <string>
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
	unsigned long long int sum = 0, sd;
	double meanValue = mean(array, size);
    for(int i = 0; i < size; ++i) {
    	double delta = array[i] - meanValue;
    	sum = delta * delta;
    	sum /= size - 1;
	}
    return sqrt(sum);
}
double percentile(int array[], int size, int percent) {
	double position = (size+1) * percent / 100;
	int lowerBound = position;
	double delta = position - lowerBound;
	
	return array[lowerBound] + array[lowerBound+1] * delta;
}
int max(int array[], int size) {
	int max = array[0];
	for(int i = 1 ; i < size ; i ++) 
		if(array[i] > max) max = array[i];
	return max;
}
int min(int array[], int size) {
	int min = array[0];
	for(int i = 1 ; i < size ; i ++) 
		if(array[i] < min) min = array[i];
	return min;
}
int range(int array[], int size) {
	return max(array, size) - min(array, size);
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
    	cout << setprecision(2) << range(incomes[i], YEAR_AMT) << endl;
    	break;
	}
	
	//GRAPH
	int widthOfCell = 12;
	cout << setw(widthOfCell) << "";
	cout << "|" << setw(widthOfCell) << "Mean";
	cout << "|" << setw(widthOfCell) << "Median";
	cout << "|" << setw(widthOfCell) << "Mode";
	cout << "|" << setw(widthOfCell) << "SD";
	cout << "|" << setw(widthOfCell) << "Percentile 95";
	cout << "|" << setw(widthOfCell) << "Percentile 90";
	cout << "|" << setw(widthOfCell) << "Variance";
	cout << "|" << setw(widthOfCell) << "Range" << endl;
	
	cout << setw(widthOfCell) << "2.a)";
	int size_for_2a = PROVINCE_AMT*YEAR_AMT;
	int data_for_2a[size_for_2a];
	for(int i = 0, index_counter = 0; i < PROVINCE_AMT; i++) {
		for(int j = 0 ; j < YEAR_AMT ; j++, index_counter++) {
			cout << incomes[i][j] << endl;
			data_for_2a[index_counter] = incomes[i][j];
		}
	}
	cout << "|" << setw(widthOfCell) << mean(data_for_2a, size_for_2a);
	cout << "|" << setw(widthOfCell) << "Median";
	cout << "|" << setw(widthOfCell) << "Mode";
	cout << "|" << setw(widthOfCell) << "SD";
	cout << "|" << setw(widthOfCell) << "Percentile 95";
	cout << "|" << setw(widthOfCell) << "Percentile 90";
	cout << "|" << setw(widthOfCell) << "Variance";
	cout << "|" << setw(widthOfCell) << "Range" << endl;
//	for(int i = 0 ; i < PROVINCE_AMT; i++)  {
//    	cout << provinces[i] << " ";
//    	for (int j = 0; j < YEAR_AMT; j++) {
//	        cout << incomes[i][j] << " ";
//	    }
//	    cout << endl;
//	}

}
