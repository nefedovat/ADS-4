// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
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
      int l = 1, r = 1;
      while (left + l < right && arr[left + l] == arr[left]) l++;
      while (right - r > left && arr[right - r] == arr[right]) r++;
      if (arr[left] != arr[right]) {
        count += l * r;
        left += l;
        right -= r;
      } else {
        int n = right - left + 1;
        count += (n * (n - 1)) / 2;
        break;
      }
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
      left = i + 1, right = len - 1;
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
