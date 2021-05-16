// binary search example in C/C++
/* here Arr is an of integer type, n is size of array 
   and target is element to be found */

int binarySearch(vector<int> Arr,int target) 
{
	//set stating and ending index
	int low = 0, high = A.size()-1;

	while(low <= high) 
	{
		// take mid of the list
		int mid = (low + high) / 2;
		cout <<"low = "<<low<<" , high = "<< high<<" , mid = "<< mid << endl;

		// we found a match
		if(A[mid] == target) 
			return mid; 
		
		// go on right side
		else if(A[mid] < target) 
			low = mid + 1;
		
		// go on left side
		else 
			high = mid - 1;
	
	}
	// element is not present in list
	return -1;
}
