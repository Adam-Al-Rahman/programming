// MIN HEAP CONSTRUCTION

// Implementa MinHeap class that supports:
// - Building a Min Heap from an input array of integers.
// - Inserting integers in the heap.
// - Removing the heap's minimum / root value.
// - Peeking at the heap's minimum / root value.
// - Sifting integers up and down the heap, which is to be used when inserting and removing values.

// Note that the heap should be represented in the form of an array.

// If you're unfamiliar with Min Heaps, we recommend watching the Conceptual Overview section
// of this question's video explanation before starting to code.

#include <algorithm>
#include <cassert>
#include <vector>

bool isMinHeapPropertySatisfied(std::vector<int> array) {
  for (int currentIdx = 1; currentIdx < array.size(); currentIdx++) {
    int parentIdx = (currentIdx - 1) / 2;

    if (parentIdx < 0) return true;
    if (array[parentIdx] > array[currentIdx]) return false;
  }

  return true;
}

class MinHeap {
 public:
  std::vector<int> heap;

  MinHeap(std::vector<int> vector) { heap = buildHeap(vector); }

  // TC: O(n) | SC: O(1)
  std::vector<int> buildHeap(std::vector<int>& vector) {
    int firstParentIdx = (vector.size() - 2) / 2;
    for (int currentIdx = firstParentIdx; currentIdx >= 0; currentIdx--) {
      siftDown(currentIdx, vector.size() - 1, vector);
    }

    return vector;
  }

  // TC: O(log(n)) | SC: O(1)
  void siftDown(int currentIdx, int endIdx, std::vector<int>& heap) {
    int childOneIdx = currentIdx * 2 + 1;
    while (childOneIdx <= endIdx) {
      int childTwoIdx = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
      int idxToSwap;
      if (childTwoIdx != -1 && heap[childTwoIdx] < heap[childOneIdx]) {
        idxToSwap = childTwoIdx;
      } else {
        idxToSwap = childOneIdx;
      }

      if (heap[idxToSwap] < heap[currentIdx]) {
        std::swap(heap[currentIdx], heap[idxToSwap]);
        currentIdx = idxToSwap;
        childOneIdx = currentIdx * 2 + 1;
      } else {
        return;
      }
    }
  }

  // TC: O(log(n)) | SC: O(1)
  void siftUp(int currentIdx, std::vector<int>& heap) {
    int parentIdx = (currentIdx - 1) / 2;
    while (currentIdx > 0 && heap[currentIdx] < heap[parentIdx]) {
      std::swap(heap[currentIdx], heap[parentIdx]);
      currentIdx = parentIdx;
      parentIdx = (currentIdx - 1) / 2;
    }
  }

  int peek() { return heap[0]; }

  int remove() {
    std::swap(heap[0], heap[heap.size() - 1]);
    int valueToRemove = heap.back();
    heap.pop_back();
    siftDown(0, heap.size() - 1, heap);
    return valueToRemove;
  }

  void insert(int value) {
    heap.push_back(value);
    siftUp(heap.size() - 1, heap);
  }
};

int main() {
  MinHeap minHeap({48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41});
  minHeap.insert(76);
  assert(isMinHeapPropertySatisfied(minHeap.heap));
  assert(minHeap.peek() == -5);
  assert(minHeap.remove() == -5);
  assert(isMinHeapPropertySatisfied(minHeap.heap));
  assert(minHeap.peek() == 2);
  assert(minHeap.remove() == 2);
  assert(isMinHeapPropertySatisfied(minHeap.heap));
  assert(minHeap.peek() == 6);
  minHeap.insert(87);
  assert(isMinHeapPropertySatisfied(minHeap.heap));
}
