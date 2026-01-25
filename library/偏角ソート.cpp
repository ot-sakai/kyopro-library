const double pi = 3.14159265358979;

//偏角を求める
double getangle(double x, double y) {
    double kaku = atan2(y, x) * 180.0 / pi;  // ラジアン → 度

    if (kaku < 0.0) {
        kaku += 360.0;
    }

    return kaku;
}

// [偏角 I1] - [原点] - [偏角 I2] のなす角度を求める
// 例えば I1 = 240°、I2 = 30°のとき、求める角度は 150°
double getangle2(double I1, double I2) {
    double res = abs(I1 - I2);
    if(res >= 180.0) return 360.0 - res;
    else return res;
}

//点iを中心としたそれぞれの点の偏角を求めてソート
vector<double> vec;
for(int j = 0; j < n; j++) {
    if(i == j) continue;

    double angle = getangle(x[j] - x[i], y[j] - y[i]);
    vec.push_back(angle);
}
sort(vec.begin(), vec.end());




//偏角ソート
//外積を利用→誤差が生じない
struct point {
    int x;
    int y;
    int id;
};

ll cross(const point &a, const point &b) {
    return (ll)a.x * b.y - (ll)a.y * b.x;
}

bool compare(const point &a, const point &b) {
    int ah = (a.y < 0 or (a.y == 0 and a.x < 0));
    int bh = (b.y < 0 or (b.y == 0 and b.x < 0));
    if (ah != bh) return ah < bh;
    return cross(a, b) > 0;
}

void argument_sort(vector<point> &points) {
    sort(points.begin(), points.end(), compare);
}