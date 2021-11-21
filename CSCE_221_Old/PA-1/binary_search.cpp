#include <vector>

using std::vector;

template <typename F1, typename F2>
int Binary_Search(vector<F1> &v, F2 x) {
int mid, low = 0; int high = (int) v.size()-1; while (low < high) { mid = (low+high)/2; if (num_comp++, v[mid] < x) low = mid+1; else high = mid;
} if (num_comp++, x == v[low]) return low; //OK: found throw Unsuccessful_Search(); //exception: not found
}
void sort_items() {
		
}
