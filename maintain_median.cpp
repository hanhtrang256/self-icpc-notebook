void ins(long long x) {
	if ((int)low.size() == 0) {
		low.insert(x);
		return;
	}
	long long med = *(low.rbegin());
	if (x >= med) {
		high.insert(x);
		if ((int)high.size() > (int)low.size()) {
			long long re = *(high.begin());
			low.insert(re);
			high.erase(high.find(re));
		}
	} else {
		low.insert(x);
		if ((int)low.size() > (int)high.size() + 1) {
			long long re = *(low.rbegin());
			high.insert(re);
			low.erase(low.find(re));
		}
	}
}

void er(long long x) {
	long long med = *(low.rbegin());
	if (x <= med) {
		low.erase(low.find(x));
		if ((int)low.size() < (int)high.size()) {
			long long re = *(high.begin());
			low.insert(re);
			high.erase(high.find(re));
		}
	} else {
		high.erase(high.find(x));
		if ((int)high.size() < (int)low.size() - 1) {
			long long re = *(low.rbegin());
			high.insert(re);
			low.erase(low.find(re));
		}
	}
}
