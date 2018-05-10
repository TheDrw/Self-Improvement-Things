// Andrew Esberto
// I've never used binary search before, so this is used to help better my 
// understanding of it. I also made up some small exercises of binary search 
// to reinforce my learnings. Maybe it will help you or something.

#include <iostream>
#include <vector>

int binary_search_ascending(const std::vector<int> &, const int);
int binary_search_descending(const std::vector<int> &, const int);
std::vector<int> binary_search_duplicates_ascending(const std::vector<int> &, const int);
std::vector<int> binary_search_duplicates_descending(const std::vector<int> &, const int);

int main()
{
	std::vector<int> arr({0,2,3,4,5,6,7,8,9});
	auto index = binary_search_ascending(arr,3);
	std::cout << "found in index " << index << " is " << arr[index] << '\n';
	
	arr = {9,8,7,6,5,4,3};
	index = binary_search_descending(arr,4);
	std::cout << "found in index " << index << " is " << arr[index] << '\n';
	
	arr = {5,6,7,7,7,9,12,12,12,12,122};
	auto indices = binary_search_duplicates_ascending(arr, 7);
	std::cout << "found 7 in indices " << indices[0] << ',' << indices[1] << '\n';
	
	arr = {122,12,12,12,9,7,7,7,5,3};
	indices = binary_search_duplicates_descending(arr, 7);
	std::cout << "found 7 in indices " << indices[0] << ',' << indices[1] << '\n';
	
	return 0;
}

// assuming array is sorted in ascending order, this will find the value and return
// the index in which the value lives in. or else it will return -1 if it doesn't.
int binary_search_ascending(const std::vector<int> &arr, const int target)
{
	if(arr.empty()) return -1;
	
	int left = 0, right = arr.size() - 1;
	while(left <= right)
	{
		int mid = left + (right - left)/2;
		if(arr[mid] == target)		return mid;
		else if(arr[mid] > target)	right = mid - 1;
		else						left = mid + 1;
	}
	
	return -1;
}

// assuming the array is sorted in descending order, this will the value and return
// the index in which the value lives in. or else it will return -1 if it doesn't.
int binary_search_descending(const std::vector<int> &arr, const int target)
{
	if(arr.empty()) return -1;
	
	int left = 0, right = arr.size() - 1;
	while(left <= right)
	{
		int mid = left + (right - left)/2;
		if(arr[mid] == target)		return mid;
		else if(arr[mid] < target)	right = mid - 1;
		else						left = mid + 1;	
	}
	
	return -1;
}

// as an exercise of binary search, i used it to find the range in which the number lies in an array.
// assuming the array has duplicates and is sorted in ascending order, this will return the 
// indices in where the values live in. if it doesn't appear, it will return an array [-1,-1].
// this is does it in O(logn) time complexity and O(1) space complexity.
std::vector<int> binary_search_duplicates_ascending(const std::vector<int> &arr, const int target)
{
	if(arr.empty()) return {-1,-1};
	
	int left = 0, right = arr.size() - 1;
	while(left <= right)
	{
		int mid = left + (right - left)/2;
		if(arr[left] == target && arr[right] == target) return {left, right};
		else if(arr[mid] > target && arr[mid] != target) right = mid - 1;
		else if(arr[mid] < target && arr[mid] != target) left = mid + 1;
		else if(arr[right] != target)					++right;
		else if(arr[left] != target)					--left;
	}
	return {-1,-1};
}

// as another exercise of binary search, it is the same as binary_search_duplicates_ascending() except 
// it is for an array sorted in descending. Time comp is Ol(logn), of course, and O(1) space comp.
std::vector<int> binary_search_duplicates_descending(const std::vector<int> &arr, const int target)
{
	if(arr.empty()) return {-1,-1};
	
	int left = 0, right = arr.size() - 1;
	while(left <= right)
	{
		int mid = left + (right - left)/2;
		if(arr[left] == target && arr[right] == target) return {left, right};
		else if(arr[mid] < target && arr[mid] != target) right = mid - 1;
		else if(arr[mid] > target && arr[mid] != target) left = mid + 1;
		else if(arr[right] != target)					++right;
		else if(arr[left] != target)					--left;
	}
	return {-1,-1};
}
