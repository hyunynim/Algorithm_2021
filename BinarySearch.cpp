int BinarySearch(vector<int>& seq, int num) {
	int l = 0, r = seq.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (seq[mid] == num)
			return mid;
		if (seq[mid] > num)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}
