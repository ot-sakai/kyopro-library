//三分探索 
/*
たかだか一つしか極値のない関数fにおける
極値を探索するアルゴリズム
*/

double f(double x) {

}

//最小値の場合
int cnt = 500;
double low = ;
double high = ;
while(cnt--) {
    double c1 = (low * 2 + high) / 3;
    double c2 = (low + high * 2) / 3;

    if(f(c1) > f(c2)) low = c1;
    else high = c2;
}

cout << fixed << setprecision(15) << f(low) << endl;