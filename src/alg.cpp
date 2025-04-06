int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      } else if (arr[i] + arr[j] > value) {
        break;
      }
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      left++;
      right--;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int binarySearch(int* arr, int start, int end, int target) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target) return 1;
    if (arr[mid] < target) start = mid + 1;
    else end = mid - 1;
  }
  return 0;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int needed = value - arr[i];
    if (binarySearch(arr, i + 1, len - 1, needed)) {
      count++;
    }
  }
  return count;
}
