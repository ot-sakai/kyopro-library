//正方形判定
bool check(vector<int>& x, vector<int>& y) {
	vector<int> v;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++) {
			int dx = x[i] - x[j], dy = y[i] - y[j];
			v.push_back(dx * dx + dy * dy);
		}
	sort(v.begin(), v.end());
	int l = v[0];
	if (l == 0) return false; // 点が重なる
	return v[0]==l && v[1]==l && v[2]==l && v[3]==l && v[4]==l*2 && v[5]==l*2;
}

//立方体判定
bool check(vector<int>& x, vector<int>& y, vector<int>& z) {
	vector<int> v;
	for (int i = 0; i < 8; i++)
		for (int j = i + 1; j < 8; j++) {
			int dx = x[i] - x[j], dy = y[i] - y[j], dz = z[i] - z[j];
			v.push_back(dx * dx + dy * dy + dz * dz);
		}
	sort(v.begin(), v.end());
	int l = v[0];
	if (l == 0) return false; // 点が重なる
	return v[0]==l && v[11]==l && v[12]==l*2 && v[23]==l*2 && v[24]==l*3 && v[27]==l*3;
}