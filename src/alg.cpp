// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int left = 0, right = len - 1;
  int count = 0;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      left++;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int binarySearchCount(int* arr, int left, int right, int target) {
  int count = 0;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      count++;
      int temp = mid - 1;
      while (temp >= left && arr[temp] == target) {
        count++;
        temp--;
      }
      temp = mid + 1;
      while (temp <= right && arr[temp] == target) {
        count++;
        temp++;
      }
      return count;
    }
    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    count += binarySearchCount(arr, i + 1, len - 1, target);
  }
  return count;
}
