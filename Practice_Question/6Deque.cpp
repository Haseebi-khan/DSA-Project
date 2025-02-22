//                            Program to implement Deque in STL
#include <deque>
#include <iostream>

using namespace std;

void showdq(deque<int> g)
{
	deque<int>::iterator it;
	for (it = g.begin(); it != g.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}

int main()
{
	deque<int> que;

	que.push_back(10);
	que.push_front(20);
	que.push_back(30);
	que.push_front(15);
	cout << "The deque  is : ";
	showdq(que);

	cout << "\nque.size() : " << que.size();
	cout << "\n.max_size() : " << que.max_size() <<endl;

	cout << "que.at(2) : " << que.at(2) <<endl;
	cout << "que.front() : " << que.front()<<endl;
	cout << "que.back() : " << que.back()<<endl;

	cout << "\nque.pop_front() : ";
	que.pop_front();
	showdq(que);

	cout << "\nque.pop_back() : ";
	que.pop_back();
	showdq(que);

	return 0;
}


// why deque is used in c++ rather that vector ?
// 
// In C++, a deque (double-ended queue) is often preferred over a vector in certain scenarios due to its structure and performance characteristics. Here are some reasons why you might choose a deque instead of a vector:
// 
// Efficient Insertion/Deletion at Both Ends:
// 
// A deque allows for constant time insertion and deletion at both the front and the back. This is useful if you need to frequently push or pop elements from both ends.
// In contrast, a vector only provides constant time insertion/deletion at the back. Inserting at the front or middle requires shifting elements, making it less efficient.
// 
// Dynamic Allocation in Chunks:
// 
// A deque allocates memory in chunks across different parts of memory, whereas a vector allocates a single continuous block. This makes deque more flexible when frequent resizing is needed.
// A vector might require reallocating and copying all elements when its capacity is exceeded, which can be expensive.
// 
// No Invalidations for Insertions/Deletions at Front:
// 
// Since deque manages separate memory blocks, insertions or deletions at the front don’t invalidate references or iterators to elements at the back (except for global insertions that cause memory restructuring).
// In a vector, insertion or deletion at the front causes all subsequent elements to shift, invalidating references or iterators.
// 
// Access Speed:
// 
// Both deque and vector provide O(1) access time to elements via the [] operator or at() function. However, vector access might be slightly faster due to its contiguous memory allocation.
// 
// Memory Overhead:
// 
// A deque might have a slightly higher memory overhead compared to a vector because of its chunked allocation strategy. But this is a trade-off for the flexibility and efficiency it provides for front-end operations.
// 
// When to Use deque:
// 
// When you need efficient insertions and deletions from both ends of the container.
// When the total size of the container may fluctuate and you don't want the overhead of resizing or copying elements that comes with vector.
// 
// When to Use vector:
// 
// When you mostly access elements randomly or sequentially and care about memory locality.
// When you frequently append elements at the end, and don’t need to insert or delete from the front or middle often.
