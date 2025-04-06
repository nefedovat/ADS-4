// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
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

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int leftVal = arr[left];
      int rightVal = arr[right];
      int leftCount = 0, rightCount = 0;
      while (left < right && arr[left] == leftVal) {
        leftCount++;
        left++;
      }
      while (right >= left && arr[right] == rightVal) {
        rightCount++;
        right--;
      }
      if (leftVal == rightVal)
        count += (leftCount * (leftCount - 1)) / 2; // сочетания из n по 2
      else
        count += leftCount * rightCount;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int left = i + 1, right = len - 1;
    int first = -1, last = -1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] < target) {
        left = mid + 1;
      } else {
        if (arr[mid] == target) first = mid;
        right = mid - 1;
      }
    }
    left = i + 1;
    right = len - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] > target) {
        right = mid - 1;
      } else {
          if (arr[mid] == target) last = mid;
          left = mid + 1;
      }
    }
    if (first != -1 && last != -1) {
      count += last - first + 1;
    }
  }
  return count;
}
