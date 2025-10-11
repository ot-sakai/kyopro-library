//二部グラフ判定
//2彩色できるかをdfsでみていく
vector<int> color;//別途使うときに-1で初期化して、color[0]=0としてあげる必要がある
bool ok=true;
void dfs(ll now) { 
//二部グラフ判定
	for (auto next : G[now]) {
		if (color[next] == color[now]) {
			ok=false;
			return ;
		}
		else if (color[next] == !color[now])continue;
		color[next] = !color[now];
		dfs(next);
	}
}