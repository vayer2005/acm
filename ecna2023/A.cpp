#include <bits/stdc++.h>
using namespace std;


// T is the type of input array elements
// V is the type of required aggregate statistic
//source: https://gist.github.com/kartikkukreja/2e7685e1fc8dbca0001b
// TO use : SegmentTree<int, int> st(vector.data(), n);
// -------------------------
// Basic node for sum segment tree.
// Modify this struct to implement other statistics (min/max/gcd/etc.)
// -------------------------
struct SegmentTreeNode {
    // 1. Per-node state
    long long sum = 0;                 // example: store segment sum

    // 2. Build leaf from single array element
    template<typename T>
    void assignLeaf(const T &value) {
        sum = value;
    }

    // 3. Merge two children
    void merge(const SegmentTreeNode &left, const SegmentTreeNode &right) {
        sum = max(left.sum, right.sum);
    }

    // 4. Return the statistic represented by this node
    long long getValue() const {
        return sum;
    }
};



template<class T, class V>
class SegmentTree {
  SegmentTreeNode* nodes;
  int N;

public:
  SegmentTree(T arr[], int N) {
    this->N = N;
    nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
    buildTree(arr, 1, 0, N-1);
  }
  
  ~SegmentTree() {
    delete[] nodes;
  }
  
  V getValue(int lo, int hi) {
    SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
    return result.getValue();
  }
  
  void update(int index, T value) {
    update(1, 0, N-1, index, value);
  }
  
  private:  
  void buildTree(T arr[], int stIndex, int lo, int hi) {
    if (lo == hi) {
      nodes[stIndex].assignLeaf(arr[lo]);
      return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid);
    buildTree(arr, right, mid + 1, hi);
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
  
  SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
    if (left == lo && right == hi)
      return nodes[stIndex];
        
    int mid = (left + right) / 2;
    if (lo > mid)
      return getValue(2*stIndex+1, mid+1, right, lo, hi);
    if (hi <= mid)
      return getValue(2*stIndex, left, mid, lo, hi);
        
    SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
    SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
    SegmentTreeNode result;
    result.merge(leftResult, rightResult);
    return result;
  }
  
  int getSegmentTreeSize(int N) {
    int size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
  }
  
  void update(int stIndex, int lo, int hi, int index, T value) {
    if (lo == hi) {
    nodes[stIndex].assignLeaf(value);
    return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid)
      update(left, lo, mid, index, value);
    else
      update(right, mid+1, hi, index, value);
    
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
};




/*
struct SegmentTreeNode {
    long long sum=0;

    SegmentTreeNode(long long s = 0): sum(s) {}

    template<typename T>
    void assignLeaf(const T value) {
        sum = value;
    }

    void merge(const SegmentTreeNode &left, const SegmentTreeNode &right) {
        sum = std::max(left.sum, right.sum);
    }
    
    long long getValue() const {
        return sum;
    }
};


template<class T, class V>
class SegmentTree {
    SegmentTreeNode* nodes;
    int N;

public:
    SegmentTree(T arr[], int N) {
        this->N = N;
        nodes = new SegmentTreeNode(getSegmentTreeSize(N));
        buildTree(arr, 1, 0, N-1);
    }

    ~SegmentTree() {
        delete[] nodes;
    }

    V getValue(int lo, int hi) {
        SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
        return result.getValue();
    }

    void update(int index, T value) {
        update(1, 0, N-1, index, value);
    }

private:
    void buildTree(T arr[], int stIndex, int lo, int hi) {
        if (lo == hi) {
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }

        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        buildTree(arr, left, lo, mid);
        buildTree(arr, right, mid + 1, hi);
        nodes[stIndex].merge(nodes[left], nodes[right]);
    }

    SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
        if (left == lo && right == hi)
            return nodes[stIndex];
        int mid = (left + right) / 2;
        if (lo > mid) {
            return getValue(2*stIndex+1, mid+1, right, lo, hi);
        }
        if (hi <= mid) {
            return getValue(2*stIndex, left, mid, lo, hi);
        }
        SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
        SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
        SegmentTreeNode result;
        result.merge(leftResult, rightResult);
        return result;
    }

    int getSegmentTreeSize(int N) {
        int size = 1;
        for (; size < N; size <<= 1);
        return size << 1;
    }

    void update(int stIndex, int lo, int hi, int index, T value) {
        if (lo == hi) {
            nodes[stIndex].assignLeaf(value);
            return;
        }

        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        if (index <= mid) {
            update(left, lo, mid, index, value);
        } else {
            update(right, mid+1, hi, index, value);
        }
        nodes[stIndex].merge(nodes[left], nodes[right]);
    }
};

*/
int main() {
    int n;
    std::cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    
    SegmentTree<int, int> rMaxQ(nums.data(), n);
    
    for (int i = 0; i < n; i++) {
        nums[i] = -nums[i];
    }

    SegmentTree<int, int> rMinQ(nums.data(), n);
    for (int i = 0; i < n; i++) {
        nums[i] = -nums[i];
    }
    
    std::vector<int> sols;
    for (int i = 0; i < n; i++) {
        if ((i == 0 || rMaxQ.getValue(0, i - 1) <= nums[i]) &&
            (i == n - 1 || nums[i] <= std::abs(rMinQ.getValue(i + 1, n-1)))) {
            sols.push_back(nums[i]);
        }
    }

    std::cout << sols.size();
    for (int i = 0; i < std::min(100, (int)sols.size()); i++) {
        std::cout << " " << sols[i];
    }

    std::cout << std::endl;
}
