int N; //ツリーのサイズ

vector<int> sizeSubtree; // sizeSubtree[v] := v を根とする部分ツリーのサイズ
vector<int> centroids; // 重心列挙の答えがここに入る

/* ツリーDP */
void SubFindCentroids(int v, int parent_of_v) {
	sizeSubtree[v] = 1;
	bool isCentroid = true;
	for (auto ch : graph[v]) {
		if (ch == parent_of_v) continue;
		SubFindCentroids(ch, v);
		if (sizeSubtree[ch] > N / 2) isCentroid = false;
		sizeSubtree[v] += sizeSubtree[ch];
	}
	if (N - sizeSubtree[v] > N / 2) isCentroid = false;
	if (isCentroid) centroids.push_back(v);
}