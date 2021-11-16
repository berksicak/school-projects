#include <stdio.h>
#include <stdlib.h>
#include <math.h>//this is for abs,sqrt,ceil and floor functions
typedef struct Point{
	int x;
	int y;
}point;

typedef struct DistanceList{//this struct for saving all points and their distances
	point point1;
	point point2;
	float distance;
}dlist;
//global variables
int index=0;//i use this variable when program found a distance and saving in distances array, thanks to this we dont use loop
dlist distances[100];//this array contains pairs of points with their distances

point* getCoordinates(char fileName[20],int column){//it reads coordinates from sample.txt and returns coordinates address
	FILE *file=fopen(fileName,"r"); //opening file
	point* coordinates=(point*)malloc(sizeof(point)*column);//allocating matrix and this matrix's first row shows x coordinates, second row shows y coordinates
	if(file!=NULL){//this checks the file is open or not
	
		int i=0;
		while(!feof(file)){
			fscanf(file,"%d %d\n",&coordinates[i].x,&coordinates[i].y);
			i++;
	}
	
	}
	fclose(file);
	return coordinates;
}


void merge(point* arr, int left, int middle, int right)//this function merges two subarry of arr
{
	int i, j, k; //iteration variables
	int n1 = middle - left + 1;//left array's size
	int n2 = right - middle; //right array's size
 
	point L[n1], R[n2];//temp arrays

	// Copy data to temp arrays L[] and R[] 
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];

	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = left; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i].x <= R[j].x) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[], if there are any 
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	//Copy the remaining elements of R[], if there are any 
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// left is for left index and right is right index of the sub-array of arr to be sorted 
void mergeSort(point *arr, int left, int right)
{
	if (left < right) {
		// Same as (left+right)/2, but avoids overflow for
		int middle = left + (right - left) / 2;

		// Sort first and second halves
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);

		merge(arr, left, middle, right);
	}
}


float medianFinder(point *coordinates,int startIndex, int stopIndex){//this returns median value of coordinates.x
	float medianIndex;
	medianIndex=(stopIndex-startIndex)/2.0;
	int truncated=(int)medianIndex;//this is for checking the index, is it integer or float
	if(medianIndex=truncated){//if this is true that means medianIndex is an integer 
		return coordinates[(int)medianIndex].x;
		
	}
	else return (coordinates[startIndex+(int)medianIndex].x+coordinates[startIndex+(int)medianIndex+1].x)/2.0;
		
}



int medianIndexFinder(point *coordinates,int startIndex, int stopIndex){//this returns median index of coordinates.x
	float medianIndex;
	medianIndex=(stopIndex-startIndex)/2;
	int truncated=(int)medianIndex;//this is for checking the index, is it integer or float
	if(medianIndex=truncated){//if this is true that means medianIndex is an integer 
		return medianIndex+startIndex;
	}
	else return (int)floor(medianIndex)+startIndex;
}
//this function finds min distances between points which in coordinates
float findMinDistance(point* coordinates,int startIndex, int stopIndex){
	
	point *closeToMedian=(point*)malloc(sizeof(point)*6);//this point array helps us holding the points which close to median
	int n=stopIndex-startIndex,i,j,medianIndex;
	float tmp,min=1000,min1,min2,median;//min1 and min2 are holds min distance of left side and right side of median
	if(2<=n && n<=3){//the brute-force part 
		i=startIndex;
		for(i=startIndex;i<=stopIndex;i++){
			j=startIndex;
			if(j==i)j++;
			while(j<=stopIndex){
 				tmp=sqrt(((coordinates[i].x-coordinates[j].x)*(coordinates[i].x-coordinates[j].x))+((coordinates[i].y - coordinates[j].y)*(coordinates[i].y - coordinates[j].y)));					
				distances[index].point1=coordinates[i];
				distances[index].point2=coordinates[j];
				distances[index].distance=tmp;
				index++;
				if(min>tmp && tmp>0) {
					min=tmp;
				}
				j++;
				if(j==i)j++;
		}
				
	}
			return min;
	}
		else if(n>3) {//recursion part
			
			medianIndex=medianIndexFinder(coordinates,startIndex,stopIndex);
			min1=findMinDistance(coordinates,startIndex,medianIndex);
			min2=findMinDistance(coordinates,medianIndex+1,stopIndex);
			
			if(min1<min2)min=min1;
			else min=min2;
			
			median=medianFinder(coordinates,startIndex,stopIndex);

			j=0;
			for(i=startIndex;i<=stopIndex;i++){//this part for finding points which ones closer than min distance
				if(abs(coordinates[i].x - median)<=min){
					closeToMedian[j]=coordinates[i];
					j++;
				}
			}
			
			if(j>1){//if 2 or more point in this array recursion continious with this part
				float min3;//This variable  keeps the minimum distance of points close to the median 
			
			
				min3=findMinDistance(closeToMedian,0,j-1);
			
				if(min3<min)return min3;
				
			}
				return min;
				
			
	}
		
		
}


int main(){
	char fileName[20]="sample.txt";
	int column=10,j,median;
	point *coordinates=getCoordinates(fileName,column);
	float minDistance;
	
	printf("COORDINATES\n");
	for(j=0;j<column;j++)printf("%d %d\n",coordinates[j].x,coordinates[j].y);
	mergeSort(coordinates,0,9);
	printf("\nSORTED\n\n");
	for(j=0;j<column;j++)printf("%d %d\n",coordinates[j].x,coordinates[j].y);
	
	minDistance=findMinDistance(coordinates,0,column-1);
	for(j=0;j<=index;j++){//i use for loop because 2 distance can equal each other
		if(distances[j].distance==minDistance && distances[j].point1.x<distances[j].point2.x){
			printf("\nPoint1:(%d,%d)\tPoint2:(%d,%d)\t Distance:%f",distances[j].point1.x,distances[j].point1.y,distances[j].point2.x,distances[j].point2.y,distances[j].distance);
		}
	}
	free(coordinates);
	return 0;
}
